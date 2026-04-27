#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

template<typename T>
class Heap {
public:
    void push(const T& value) {
        data_.push_back(value);
        std::push_heap(data_.begin(), data_.end());
    }

    T pop() {
        if (data_.empty()) {
            throw std::underflow_error("heap is empty");
        }
        std::pop_heap(data_.begin(), data_.end());
        T value = data_.back();
        data_.pop_back();
        return value;
    }

    T top() const {
        if (data_.empty()) {
            throw std::underflow_error("heap is empty");
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
    std::vector<T> data_;
};
