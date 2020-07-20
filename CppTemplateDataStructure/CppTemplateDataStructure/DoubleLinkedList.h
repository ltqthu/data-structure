# ifndef DOUBLE_LINK_H
# define DOUBLE_LINK_H
#include <fstream>
using namespace std;
//双向链表的节点结构
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

//双向链表类
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

//构造函数
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_pHead = new Node<T>(0, nullptr, nullptr);
    m_pHead->next = m_pHead;
    m_pHead->prev = m_pHead;
    m_nCount = 0;
};

//获取双向链表头节点
template<typename T>
Node<T>* DoubleLinkedList<T>::get_head() const
{
    return m_pHead;
}

//返回双向链表长度
template <typename T>
int DoubleLinkedList<T>::size() const
{
    return m_nCount;
}

//获取指定下标的元素
template <typename T>
Node<T>* DoubleLinkedList<T>::get_node(int index)
{
    if (index >= m_nCount || index < 0)
        return nullptr;
    // 前半部分
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
    // 后半部分
    index = m_nCount - index - 1;
    Node<T>* pnode = m_pHead->prev;
    while (index)
    {
        pnode = pnode->prev;
        index--;
    }
    return pnode;
};

//将新节点插到第一个位置
template <typename T>
Node<T>* DoubleLinkedList<T>::insert_front(T value)
{
    Node<T>* newNode = new Node<int>(value, m_pHead, m_pHead->next);
    m_pHead->next->prev = newNode;
    m_pHead->next = newNode;
    m_nCount++;
    return newNode;
};

//将新节点插到链表尾部
template <typename T>
Node<T>* DoubleLinkedList<T>::insert_last(T value)
{
    Node<T>* newNode = new Node<int>(value, m_pHead->prev, m_pHead);
    m_pHead->prev->next = newNode;
    m_pHead->prev = newNode;
    m_nCount++;
    return newNode;
};

//将节点位置插到index位置之前
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

//删除链表第一个节点, 返回删除后链表第一个节点
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

//删除链表的末尾节点, 返回删除后链表尾部元素
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

//删除指定位置的元素
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

//判断链表是否为空
template <typename T>
bool DoubleLinkedList<T>::is_empty() const
{
    return m_nCount == 0;
};

//获取第一个节点的值
template<typename T>
T DoubleLinkedList<T>::get_front_value()
{
    return m_pHead->next->value;
};

//获取最后一个节点的值
template <typename T>
T DoubleLinkedList<T>::get_last_value()
{
    return m_pHead->prev->value;
};

//获取指定位置节点的值
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