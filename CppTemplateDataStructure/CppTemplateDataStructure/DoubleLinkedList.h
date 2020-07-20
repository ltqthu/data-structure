# ifndef DOUBLE_LINK_H
# define DOUBLE_LINK_H
#include <fstream>
using namespace std;
//˫������Ľڵ�ṹ
template <typename T>
struct Node
{
public:
    Node() {};
    Node(T value, Node<T>* prev, Node<T>* next) :value(value), prev(prev), next(next) {}
public:
    T value;
    Node<T>* prev;
    Node<T>* next;
};

//˫��������
template<typename T>
class DoubleLinkedList
{
public:
    typedef Node<T>* pointer;
public:
    DoubleLinkedList();
    ~DoubleLinkedList() {};
public:
    Node<T>* insert(int index, T value);
    Node<T>* insert_front(T value);
    Node<T>* insert_last(T value);

    Node<T>* remove(int index);
    Node<T>* remove_front();
    Node<T>* remove_last();

    bool is_empty() const;
    int size() const;

    T get_value(int index);
    T get_front_value();
    T get_last_value();
    Node<T>* get_head() const;

    template <typename T>
    friend ostream& operator<<(ostream& out, const DoubleLinkedList<T>& double_linked_list);

private:
    Node<T>* m_pHead;
    int m_nCount;
private:
    Node<T>* get_node(int index);
};

//���캯��
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_pHead = new Node<T>(0, nullptr, nullptr);
    m_pHead->next = m_pHead;
    m_pHead->prev = m_pHead;
    m_nCount = 0;
};

//��ȡ˫������ͷ�ڵ�
template<typename T>
Node<T>* DoubleLinkedList<T>::get_head() const
{
    return m_pHead;
}

//����˫��������
template <typename T>
int DoubleLinkedList<T>::size() const
{
    return m_nCount;
}

//��ȡָ���±��Ԫ��
template <typename T>
Node<T>* DoubleLinkedList<T>::get_node(int index)
{
    if (index >= m_nCount || index < 0)
        return nullptr;
    // ǰ�벿��
    if (index <= m_nCount / 2)
    {
        Node<T>* pNode = m_pHead->next;
        while (index)
        {
            pNode = pNode->next;
            index--;
        }
        return pNode;
    }
    // ��벿��
    index = m_nCount - index - 1;
    Node<T>* pnode = m_pHead->prev;
    while (index)
    {
        pnode = pnode->prev;
        index--;
    }
    return pnode;
};

//���½ڵ�嵽��һ��λ��
template <typename T>
Node<T>* DoubleLinkedList<T>::insert_front(T value)
{
    Node<T>* newNode = new Node<int>(value, m_pHead, m_pHead->next);
    m_pHead->next->prev = newNode;
    m_pHead->next = newNode;
    m_nCount++;
    return newNode;
};

//���½ڵ�嵽����β��
template <typename T>
Node<T>* DoubleLinkedList<T>::insert_last(T value)
{
    Node<T>* newNode = new Node<int>(value, m_pHead->prev, m_pHead);
    m_pHead->prev->next = newNode;
    m_pHead->prev = newNode;
    m_nCount++;
    return newNode;
};

//���ڵ�λ�ò嵽indexλ��֮ǰ
template <typename T>
Node<T>* DoubleLinkedList<T>::insert(int index, T value)
{
    if (index == 0)
        return insert_front(value);

    Node<T>* pNode = get_node(index);
    if (pNode == nullptr)
        return nullptr;
    Node<T>* newNode = new Node<T>(value, pNode->prev, pNode);
    pNode->prev->next = newNode;
    pNode->prev = newNode;
    m_nCount++;

    return newNode;
};

//ɾ�������һ���ڵ�, ����ɾ���������һ���ڵ�
template<typename T>
Node<T>* DoubleLinkedList<T>::remove_front()
{
    if (m_nCount == 0)
    {
        return nullptr;
    }
    Node<T>* pnode = m_pHead->next;
    m_pHead->next = pnode->next;
    pnode->next->prev = m_pHead;
    delete pnode;
    m_nCount--;
    return m_pHead->next;
};

//ɾ�������ĩβ�ڵ�, ����ɾ��������β��Ԫ��
template<typename T>
Node<T>* DoubleLinkedList<T>::remove_last()
{
    if (m_nCount == 0)
    {
        return nullptr;
    }
    Node<T>* pnode = m_pHead->prev;
    pnode->prev->next = m_pHead;
    m_pHead->prev = pnode->prev;
    delete pnode;
    m_nCount--;
    return m_pHead->prev;
}

//ɾ��ָ��λ�õ�Ԫ��
template <typename T>
Node<T>* DoubleLinkedList<T>::remove(int index)
{
    if (index == 0)
        return remove_front();
    if (index == m_nCount - 1)
        return remove_last();
    if (index >= m_nCount)
        return nullptr;
    Node<T>* pnode = get_node(index);
    pnode->prev->next = pnode->next;
    pnode->next->prev = pnode->prev;

    Node<T>* ptemp = pnode->prev;
    delete pnode;
    m_nCount--;
    return ptemp;
};

//�ж������Ƿ�Ϊ��
template <typename T>
bool DoubleLinkedList<T>::is_empty() const
{
    return m_nCount == 0;
};

//��ȡ��һ���ڵ��ֵ
template<typename T>
T DoubleLinkedList<T>::get_front_value()
{
    return m_pHead->next->value;
};

//��ȡ���һ���ڵ��ֵ
template <typename T>
T DoubleLinkedList<T>::get_last_value()
{
    return m_pHead->prev->value;
};

//��ȡָ��λ�ýڵ��ֵ
template <typename T>
T DoubleLinkedList<T>::get_value(int index)
{
    Node<T>* pnode = get_node(index);
    return pnode->value;
};

template <typename T>
ostream& operator<<(ostream& out, const DoubleLinkedList<T>& double_linked_list)
{
    Node<T>* pMove = double_linked_list.get_head()->next;
    for (int i = 0; i < double_linked_list.size(); i++)
    {
        out << pMove->value << " ";
        pMove = pMove->next;
    }
    out << endl;
    return out;
}
#endif //DOUBLE_LINK_H