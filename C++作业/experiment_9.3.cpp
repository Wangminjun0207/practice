/*
 *根据数据结构和类模板知识，定义一个通用队列（先进先出）类并加以实现，编写主函数进行测试；
 */
 
#include <iostream>
using namespace std;
const int MaxQSize = 100;
template<class T>
class Queue
{
private:
	int front, rear, count;//对头指针、队尾指针、元素个数
	T qlist[MaxQSize];
public:
	Queue(void);//构造函数，进行数据成员的初始化
	void Insert(const &item);//新元素入队
	T Delete(void);//元素出队
	T getFront() const;//访问对首元素
	int getLength(void) const;//求元素个数
	int isEmpty(void) const;//判断队列空
	int isFull(void) const;//判断队列满
};

template<class T>
Queue<T>::Queue():front(0),rear(0),count(0) {}

template<class T>
void Queue<T>::Insert(const &item)
{
	if(count==MaxQSize)
	{
		cout<<"Queue overflow"<<endl;
		exit(1);//如果队列为满，终止程序
	}
	count++;
	qlist[rear] = item;
	rear = (rear+1)%MaxQSize;//队尾指针+1，用取余运算实现循环队列
}

template<class T>
T Queue<T>::Delete()
{
	T temp;
	if(count==0)
	{
		cout<<"Deleting from an empty queue!"<<endl;
		exit(1);//如果队列为空，终止程序
	}
	temp = qlist[front];
	count--;
	front = (front+1)%MaxQSize;
	return temp;
}

template<class T>
T Queue<T>::getFront() const
{
	return qlist[front];
}

template<class T>
int Queue<T>::getLength() const
{
	return count;
}

template<class T>
int Queue<T>::isEmpty() const 
{
	return count == 0;//返回逻辑值count == 0
}

template<class T>
int Queue<T>::isFull() const
{
	return count == MaxQSize;//返回逻辑值count == MaxQSize
}

int main()
{
	Queue<int>q;
	q.Insert(1);
	q.Insert(2);
	q.Insert(3);
	q.Insert(4);
	q.Insert(5);
	q.Insert(6);
	cout<<"The front is "<<q.getFront()<<endl;
	while(!q.isEmpty())
	{
		cout<<"The length is "<<q.getLength()<<endl;
		cout<<"The front is "<<q.getFront()<<endl;
		q.Delete();
	}
	int i = 1;
	while(!q.isFull())
	{
		q.Insert(i);
		i++;
	}
	cout<<"The length is "<<q.getLength()<<endl;
	return 0;
}

