#pragma once
#include "Node.h"
#include <cassert>

template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList() { clear(); }

    void push(int priority, T data) {
        Node<T>* newNode = new Node<T>(priority, data);

        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next && current->next->priority <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void pop() {
        assert(head != nullptr && "Cannot pop from an empty list.");
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T& front() {
        assert(head != nullptr && "Cannot access front of an empty list.");
        return head->data;
    }

    bool isEmpty() const { return head == nullptr; }

    int getSize() const { return size; }

    void clear() {
        while (head) {
            pop();
        }
    }

private:
    Node<T>* head;
    int size;
};