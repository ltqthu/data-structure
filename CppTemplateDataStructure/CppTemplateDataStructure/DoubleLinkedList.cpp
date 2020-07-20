#include<iostream>
#include"DoubleLinkedList.h"
using namespace std;

int TestDoubleLinkedList()
{
    DoubleLinkedList<int> test_list;
    for (int i = 0; i < 10; i++)
    {
        test_list.insert(0, i + 10);
    }
    cout << test_list;

    test_list.insert(0, 100);
    cout << test_list;

    test_list.insert_last(1000);
    cout << test_list;

    //É¾³ý²âÊÔ
    test_list.remove_front();
    cout << test_list;

    test_list.remove_last();
    cout << test_list;

    test_list.remove(3);
    cout << test_list;

    getchar();
    return 0;
}
