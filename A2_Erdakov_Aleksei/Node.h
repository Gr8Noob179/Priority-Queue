#pragma once

template <typename T>
class Node {
public:
    int priority;
    T data;
    Node* next;

    Node(int priority, T data) : priority(priority), data(data), next(nullptr) {}
};