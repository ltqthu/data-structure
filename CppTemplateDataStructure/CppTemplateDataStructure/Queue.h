# ifndef QUEUE_H
# define QUEUE_H
//������еĽṹ��
template<typename T>
struct Node
{
    Node() {};
    Node(T t) :value(t), next(nullptr) {}

    T value;
    Node<T>* next;
};

//������е�ģ����
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

//���캯��
template<typename T>
Queue<T>::Queue() :m_pHead(nullptr), m_pEnd(nullptr), m_nCount(0)
{
    m_pHead = new Node<T>();
    m_pEnd = m_pHead;
    m_nCount = 0;
};

//��������
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

//�ж϶����Ƿ�Ϊ��
template <typename T>
bool Queue<T>::is_empty()
{
    return m_nCount == 0;
};

//��ȡ���д�С
template <typename T>
int Queue<T>::size()
{
    return m_nCount;
};

//�ڶ�β����
template <typename T>
void Queue<T>::push(T t)
{
    Node<T>* pMove = new Node<T>(t);
    m_pEnd->next = pMove;
    m_pEnd = pMove;
    m_nCount++;
};

//�ڶ��׵���
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

//��ȡ����Ԫ��
template<typename T>
T Queue<T>::front()
{
    return m_pHead->next->value;
};

#endif //QUEUE_H