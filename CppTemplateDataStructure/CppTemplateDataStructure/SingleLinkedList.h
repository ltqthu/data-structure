# ifndef SINGLE_LINKED_LIST_H
# define SINGLE_LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

//������ڵ�ṹ
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

//������ģ����
template <typename T>
class SingleLinkedList
{
public:
	typedef Node<T>* pointer;
	SingleLinkedList();
	~SingleLinkedList();

	int size() const;						 //��ȡ����
	bool is_empty() const;			     //�п�

	Node<T>* insert(int index, T t); //��ָ��λ�ý��в���
	Node<T>* insert_head(T t);		 //������ͷ���в���
	Node<T>* insert_last(T t);		 //������β���в���

	Node<T>* remove(int index);		 //��ָ��λ�ý���ɾ��
	Node<T>* remove_head();			 //ɾ������ͷ
	Node<T>* remove_last();			 //ɾ������β

	T get_value(int index);			     //��ȡָ��λ�õ�Ԫ��
	T get_head_value();					 //��ȡ����ͷԪ��
	T get_last_value();					 //��ȡ����βԪ��

	Node<T>* get_head() const;				 //��ȡ����ͷ�ڵ�

	template<typename T>
	friend ostream& operator<<(ostream& out, const SingleLinkedList<T>& single_linked_list);
private :
	int m_nCount;
	Node<T>* m_pHead;				 

private :
	Node<T>* get_node(int index);	  //��ȡָ��λ�õĽڵ�
};

//���캯��
template <typename T>
SingleLinkedList<T>::SingleLinkedList():m_nCount(0), m_pHead(nullptr)
{
	m_pHead = new Node<T>();
	m_pHead->next = nullptr;
};

//��������
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

//����ָ��������ǰһ��λ�ýڵ㣬������Ϊ�գ��򷵻�ͷ�ڵ�
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

//��������Ĵ�С
template <typename T>
int SingleLinkedList<T>::size() const
{
	return m_nCount;
};

//�����п�
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

//��ָ��λ�ò����½ڵ�
template <typename T>
Node<T>* SingleLinkedList<T>::insert(int index, T t)
{
	Node<T>* preNode = get_node(index);
	if (preNode)
	{
		Node<T> *newNode = new Node<T>(t, preNode->next); //�����½ڵ㣬����ʱָ���ڵ��next�ڵ�
		preNode->next = newNode;
		m_nCount++;
		return newNode;
	}
	return nullptr;
};

//��ͷ������
template <typename T>
Node<T>* SingleLinkedList<T>::insert_head(T t)
{
	return insert(0, t);
};

//��β�����в���
template <typename T>
Node<T>* SingleLinkedList<T>::insert_last(T t)
{
	return insert(m_nCount, t);
};

//ɾ������ָ��λ��Ԫ��
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

//ɾ��ͷ�ڵ�
template<typename T>
Node<T>* SingleLinkedList<T>::remove_head()
{
	return remove(0);
};

//ɾ��β�ڵ�
template<typename T>
Node<T>*SingleLinkedList<T>::remove_last()
{
	return remove(m_nCount-1);
};

// ��ӡ
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