//thread-safe queue

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace  t_task{
template <class T>
class queue;
}

template <class T>
class t_task::queue {
private: public:
    std::queue<T> q;
    std::condition_variable cv;
    std::mutex mutex;
    bool on;
public:

    queue(): on(true) {
        ;
    }

    void put(T const &value) {
        std::unique_lock<std::mutex> lock(mutex);
        q.push(value);
        cv.notify_one();
    }

    bool get(T &result) {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [this]()->bool {
            return !q.empty() || !on;
        });
        if (q.empty())
            return false;
        result = q.front();
        q.pop();
        return true;
    }

    void finish() {
        std::unique_lock<std::mutex> lock(mutex);
        on = false;
        cv.notify_all();
    }

    bool is_finished() {
        std::lock_guard<std::mutex> lock(mutex);
        return !on && q.empty();
    }

    bool empty() {
        std::lock_guard<std::mutex> lock (mutex);
        return q.empty();
    }
};


#endif // QUEUE_H
