#pragma once
#include <queue>

template<typename T>
class Queue {
    std::queue<T> queue_;

public:
    Queue() = default;
    Queue(const Queue<T>&) = delete;
    Queue& operator=(const Queue<T>&) = delete;

    Queue(Queue<T>&& other) {
        queue_ = std::move(other.queue_);
    }

    virtual ~Queue() {  }

    bool empty() const { return queue_.empty(); }
    unsigned long size() const { return queue_.size(); }

    std::<T> pop() {
        if (queue_.empty()) {
            return {};
        }
        T tmp = queue_.front();
        queue_.pop();
        return tmp;
    }

    void push(const T& item) {
        queue_.push(item);
    }

    std::optional<T> peek() {
        if (queue_.empty()) {
            return {};
        }
        return queue_.front();
    }
};