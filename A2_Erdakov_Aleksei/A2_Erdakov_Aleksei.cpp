// A2_Erdakov_Aleksei.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PriorityQueue.h"
#include "string"

using std::cout;
using std::string;
using std::endl;

int main() {
    PriorityQueue<string> queue;

    cout << "Pushing elements" << endl;
    queue.push(3, "C");
    queue.push(1, "A");
    queue.push(2, "B");
    queue.push(4, "D");

    while (!queue.isEmpty()) {
        cout << "  " << queue.front() << endl;
        queue.pop();
    }

    return 0;
}