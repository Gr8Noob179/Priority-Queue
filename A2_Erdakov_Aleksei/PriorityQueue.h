#pragma once
#include "LinkedList.h"

using std::pair;

template <typename T>
class PriorityQueue {
public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;

    void push(int priority, T data) {
        if (list.isEmpty()) {
            list.insertFront({ priority, data });  // Insert at the front if the list is empty.
        }
        else {
            Node<pair<int, T>>* current = list.getHead();
            Node<pair<int, T>>* prev = nullptr;

            while (current != nullptr && current->data.first <= priority) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                list.insertFront({ priority, data });
            }
            else {
                list.insertAfter(prev, { priority, data });
            }
        }
    }

    void pop() {
        list.removeFront();
    }

    T& front() {
        return list.getFront().second;
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    int getSize() const {
        return list.getSize();
    }

private:
    LinkedList<pair<int, T>> list;
};