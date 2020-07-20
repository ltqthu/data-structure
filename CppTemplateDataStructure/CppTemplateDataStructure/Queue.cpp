#include "Queue.h"
#include<string>
#include<iostream>
using namespace std;
int TestQueue()
{
    Queue<string> test_queue;
    test_queue.push("one");
    test_queue.push("two");
    test_queue.push("three");
    test_queue.push("four");
    test_queue.push("five");
    cout << "队列的大小" << test_queue.size() << endl;
    while (!test_queue.is_empty())
    {
        cout << test_queue.front() << endl;
        test_queue.pop();
    }
    getchar();
    return 0;
}