# ifndef SINGLE_LINKED_LIST_H
# define SINGLE_LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

//单链表节点结构
template <typename T>
class Node
{
public :
	T value;
	Node* next;
public:
	Node() {};
	Node(T value, Node * next) : value(value), next(next){}
};

//单链表模板类
template <typename T>
class SingleLinkedList
{
public:
	typedef Node<T>* pointer;
	SingleLinkedList();
	~SingleLinkedList();

	int size() const;						 //获取长度
	bool is_empty() const;			     //判空

	Node<T>* insert(int index, T t); //在指定位置进行插入
	Node<T>* insert_head(T t);		 //在链表头进行插入
	Node<T>* insert_last(T t);		 //在链表尾进行插入

	Node<T>* remove(int index);		 //在指定位置进行删除
	Node<T>* remove_head();			 //删除链表头
	Node<T>* remove_last();			 //删除链表尾

	T get_value(int index);			     //获取指定位置的元素
	T get_head_value();					 //获取链表头元素
	T get_last_value();					 //获取链表尾元素

	Node<T>* get_head() const;				 //获取链表头节点

	template<typename T>
	friend ostream& operator<<(ostream& out, const SingleLinkedList<T>& single_linked_list);
private :
	int m_nCount;
	Node<T>* m_pHead;				 

private :
	Node<T>* get_node(int index);	  //获取指定位置的节点
};

//构造函数
template <typename T>
SingleLinkedList<T>::SingleLinkedList():m_nCount(0), m_pHead(nullptr)
{
	m_pHead = new Node<T>();
	m_pHead->next = nullptr;
};

//析构函数
template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    Node<T>* pNode = m_pHead->next;
    while (nullptr != pNode)
    {
        Node<T>* temp = pNode;
        pNode = pNode->next;
        delete temp;
    }
};

//返回指定索引的前一个位置节点，若链表为空，则返回头节点
template <typename T>
Node<T>* SingleLinkedList<T>::get_node(int index)
{
	if (index > m_nCount || index < 0 )
		return nullptr;
	Node<T>* pMove = m_pHead;
	while (index != 0)
	{
		index--;
		pMove = pMove->next;
	}
	return pMove;
}

//返回链表的大小
template <typename T>
int SingleLinkedList<T>::size() const
{
	return m_nCount;
};

//链表判空
template <typename T>
bool SingleLinkedList<T>::is_empty() const
{
	return m_nCount==0;
};

template<typename T>
Node<T>* SingleLinkedList<T>::get_head() const
{
	return m_pHead->next;
}

//在指定位置插入新节点
template <typename T>
Node<T>* SingleLinkedList<T>::insert(int index, T t)
{
	Node<T>* preNode = get_node(index);
	if (preNode)
	{
		Node<T> *newNode = new Node<T>(t, preNode->next); //构建新节点，构建时指明节点的next节点
		preNode->next = newNode;
		m_nCount++;
		return newNode;
	}
	return nullptr;
};

//从头部插入
template <typename T>
Node<T>* SingleLinkedList<T>::insert_head(T t)
{
	return insert(0, t);
};

//从尾部进行插入
template <typename T>
Node<T>* SingleLinkedList<T>::insert_last(T t)
{
	return insert(m_nCount, t);
};

//删除链表指定位置元素
template <typename T>
Node<T>* SingleLinkedList<T>::remove(int index)
{
	if (is_empty())
		return nullptr;

	Node<T>* pNode = get_node(index);

	if (pNode == nullptr) 
		return nullptr;

	//if (index == m_nCount-1)
	//{

	//}

	Node<T>* delNode = pNode->next;
	pNode->next = delNode->next;
	m_nCount--;
	delete delNode;
	return pNode->next;
};

//删除头节点
template<typename T>
Node<T>* SingleLinkedList<T>::remove_head()
{
	return remove(0);
};

//删除尾节点
template<typename T>
Node<T>*SingleLinkedList<T>::remove_last()
{
	return remove(m_nCount-1);
};

// 打印
template<typename T>
ostream& operator<<(ostream& out, const SingleLinkedList<T>& single_linked_list)
{
	SingleLinkedList<T>::pointer pMove = single_linked_list.get_head();
	while (pMove != nullptr)
	{
		out << pMove->value << " ";
		pMove = pMove->next;
	}
	out << endl;
	return out;
}
#endif //SINGLE_LINKED_LIST_H