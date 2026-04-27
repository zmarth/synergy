#pragma once

#include <deque>
#include <stdexcept>

template<typename T>
class Queue {
public:
    void push(const T& value) {
        data_.push_back(value);
    }

    T pop() {
        if (data_.empty()) {
            throw std::underflow_error("queue is empty");
        }
        T value = data_.front();
        data_.pop_front();
        return value;
    }

    T front() const {
        if (data_.empty()) {
            throw std::underflow_error("queue is empty");
        }
        return data_.front();
    }

    size_t size() const {
        return data_.size();
    }

    bool empty() const {
        return data_.empty();
    }

private:
    std::deque<T> data_;
};
