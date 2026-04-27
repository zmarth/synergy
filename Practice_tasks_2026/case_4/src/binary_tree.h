#pragma once

#include <cstddef>
#include <memory>

template<typename T>
class BinaryTree {
public:
    void push(const T& value) {
        insert(root_, value);
    }

    void pop(const T& value) {
        remove(root_, value);
    }

    bool search(const T& value) const {
        Node* current = root_.get();
        while (current != nullptr) {
            if (value < current->value) {
                current = current->left.get();
            } else if (value > current->value) {
                current = current->right.get();
            } else {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

private:
    struct Node {
        explicit Node(const T& value) : value(value) {}

        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    void insert(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            node = std::make_unique<Node>(value);
            ++size_;
            return;
        }
        if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        }
    }

    void remove(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            return;
        }
        if (value < node->value) {
            remove(node->left, value);
            return;
        }
        if (value > node->value) {
            remove(node->right, value);
            return;
        }

        if (!node->left) {
            node = std::move(node->right);
            --size_;
            return;
        }
        if (!node->right) {
            node = std::move(node->left);
            --size_;
            return;
        }

        std::unique_ptr<Node>* successor = &node->right;
        while ((*successor)->left) {
            successor = &(*successor)->left;
        }
        node->value = (*successor)->value;
        remove(node->right, node->value);
    }

    std::unique_ptr<Node> root_;
    size_t size_ = 0;
};
