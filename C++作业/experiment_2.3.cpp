/*
 *参考stack，设计一个类，能够实现对环形队列的读写。
 *其中包括对队列类型、队列总长度的定义、初始化、为空判断、为满判断、读取、写入、获取队列有效内容长度等。编写相应的测试主函数并成功运行。
 */
 
#include<iostream>
using namespace std;
class CirQueue
{
public:
    CirQueue(int queueCapacity);  
    ~CirQueue();                  
    int QueueLenth();          
    bool EnQueue(int element);    
    bool DeQueue(int &element);   
    bool QueueEmpty();            
    bool QueueFull();             
    void ClearQueue();            
    void QueueTravel();           
private:
    int *m_pQueue;                
    int m_iHead;                       
    int m_iTail;                  
    int m_iQueueLenth;            
    int m_iQueueCapacity;         
};
//元素入队
bool CirQueue::EnQueue(int element)
{
    if (QueueFull())
    {
        return false;
    }
    else
    {
        m_pQueue[m_iTail] = element;
        m_iTail++;
        m_iTail = m_iTail % m_iQueueCapacity;
        m_iQueueLenth++;
        return true;
    }
}
//元素出队
bool CirQueue::DeQueue(int &element)
{
    if (QueueEmpty())
    {
        return false;
    }
    else
    {
        element = m_pQueue[m_iHead];
        m_iHead++;
        m_iHead = m_iHead % m_iQueueCapacity;
        m_iQueueLenth--;    
        return true;
    }
}
//队列遍历
void CirQueue::QueueTravel()
{
    for (int i = m_iHead; i < m_iQueueLenth + m_iHead; i++) 
	{ cout << m_pQueue[i%m_iQueueCapacity] << endl;
    }
    cout << endl;
}
CirQueue::CirQueue(int queueCapacity)
{
    m_iQueueCapacity = queueCapacity;
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLenth = 0;
    m_pQueue = new int[queueCapacity];
}
//队列构销
CirQueue::~CirQueue()
{
    delete[]m_pQueue;
    m_pQueue = NULL;
}
//得到队列长度
int CirQueue::QueueLenth()
{
    return m_iQueueLenth;
}
//清空队列
void CirQueue::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLenth = 0;
}
//队列判空
bool CirQueue::QueueEmpty()
{
    if (m_iQueueLenth == 0)
    {
        return true;
    }
    return false;
}
//队列判满
bool CirQueue::QueueFull()
{
    if (m_iQueueLenth == m_iQueueCapacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
	int sum,j;
	cout <<"请输入队列的长度：";
	cin  >> sum,j;
    CirQueue *s = new CirQueue(sum);
	cout <<"请输入元素：";
	for(int i=0;i<sum;i++)
	{
		cin >>j;
        s->EnQueue(j);
	}
    cout <<"queue lenth is: "<< s->QueueLenth() << endl;
    s->QueueTravel();
	cout <<"退出队列中多少元素：";
    int e = 0;
	int max;
	cin  >>max;
	for(;e<max;){
    s->DeQueue(e);
    cout<< "out"<<max << ":"<< e << endl;
	}
    cout <<" after queue lenth is: " << s->QueueLenth() << endl;
    s->ClearQueue();
    s->QueueTravel();
    delete s;
    s = NULL;
    system("pause");
}

