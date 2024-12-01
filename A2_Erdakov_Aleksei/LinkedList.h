#pragma once
#include "Node.h"
#include <cassert>

template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList() { clear(); }

    void insertAfter(Node<T>* prevNode, T data) {
        assert(prevNode != nullptr && "Previous node cannot be null.");
        Node<T>* newNode = new Node<T>(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        size++;
    }

    void insertFront(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void removeFront() {
        assert(head != nullptr && "Cannot remove from an empty list.");
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T& getFront() {
        assert(head != nullptr && "Cannot access front of an empty list.");
        return head->data;
    }

    bool isEmpty() const { return head == nullptr; }

    int getSize() const { return size; }

    Node<T>* getHead() const { return head; }

    void clear() {
        while (head) {
            removeFront();
        }
    }

private:
    Node<T>* head;
    int size;
};