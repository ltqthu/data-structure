# ifndef QUEUE_H
# define QUEUE_H
//链表队列的结构体
template<typename T>
struct Node
{
    Node() {};
    Node(T t) :value(t), next(nullptr) {}

    T value;
    Node<T>* next;
};

//链表队列的模板类
template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    bool is_empty();
    int size();
    bool pop();
    void push(T t);
    T front();

private:
    Node<T>* m_pHead;
    Node<T>* m_pEnd;
    int m_nCount;
};

//构造函数
template<typename T>
Queue<T>::Queue() :m_pHead(nullptr), m_pEnd(nullptr), m_nCount(0)
{
    m_pHead = new Node<T>();
    m_pEnd = m_pHead;
    m_nCount = 0;
};

//析构函数
template <typename T>
Queue<T>::~Queue()
{
    while (m_pHead->next != nullptr)
    {
        Node<T>* pNode = m_pHead;
        m_pHead = m_pHead->next;
        delete pNode;
    }
};

//判断队列是否为空
template <typename T>
bool Queue<T>::is_empty()
{
    return m_nCount == 0;
};

//获取队列大小
template <typename T>
int Queue<T>::size()
{
    return m_nCount;
};

//在队尾插入
template <typename T>
void Queue<T>::push(T t)
{
    Node<T>* pMove = new Node<T>(t);
    m_pEnd->next = pMove;
    m_pEnd = pMove;
    m_nCount++;
};

//在队首弹出
template <typename T>
bool Queue<T>::pop()
{
    if (m_nCount == 0)
        return false;
    Node<T>* pHead = m_pHead->next;
    m_pHead->next = m_pHead->next->next;
    delete pHead;
    m_nCount--;
    return true;
};

//获取队首元素
template<typename T>
T Queue<T>::front()
{
    return m_pHead->next->value;
};

#endif //QUEUE_H