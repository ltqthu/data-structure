#include<iostream>
#include"SingleLinkedList.h"
using namespace std;

int TestSingleLinkedList()
{
	SingleLinkedList<int> test_list;
	for (int i = 0; i < 10; i++)
	{
		test_list.insert(i, i);
	}
	cout << test_list.size() << endl;
	cout << test_list;

	test_list.insert_head(1111);
    cout << test_list;

	test_list.insert_last(2222);
    cout << test_list;

	test_list.remove_head();
	cout << test_list;

	test_list.remove_last();
	cout << test_list;

	getchar();
	return 0;
}
