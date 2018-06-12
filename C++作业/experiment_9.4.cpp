/*
 *根据数据结构和类模板知识，定义一个通用栈（后进先出）类并加以实现，编写主函数进行测试
 */
 
#include<iostream>
using namespace std;

template<class T>
class SqStack
{
private:
enum{MaxSize=100};
T data[MaxSize];
T top;
public:
SqStack();
~SqStack();
bool isEmpty();
void pushInt(T x);
T popInt();
T getTop();
void display();
};

template<class T>
SqStack<T>::SqStack()
{
top=-1;
}

template<class T>
SqStack<T>::~SqStack(){}

template<class T>
bool SqStack<T>::isEmpty()//判断栈为空
{
return(top==-1);
}

template<class T>
void SqStack<T>::pushInt(T x)//元素进栈
{
if(top==MaxSize-1)
{
std::cout<<"栈上溢出！"<<std::endl;
}
else
{
++top;
data[top]=x;
}
}

template<class T>
T SqStack<T>::popInt()//退栈
{
T tmp=0;
if(top==-1)
{
std::cout<<"栈已空！"<<std::endl;
}
else
{
tmp=data[top--];
}
return tmp;
}

template<class T>
T SqStack<T>::getTop()//获得栈顶元素
{
T tmp=0;
if(top==-1)
{
std::cout<<"栈空！"<<std::endl;
}
else
{
tmp=data[top];
}
return tmp;
}

template<class T>
void SqStack<T>::display()//打印栈里元素
{
std::cout<<"栈中元素："<<std::endl;
for(int index=top;index>=0;--index)
{
std::cout<<data[index]<<std::endl;
}

}
int main()
{
SqStack<int>st;
std::cout<<"栈空："<<st.isEmpty()<<std::endl;
for(int i=1;i<10;i++)
{
st.pushInt(i);
}
st.display();
std::cout<<"退一次栈"<<std::endl;
st.popInt();
std::cout<<"栈顶元素:"<<st.getTop()<<std::endl;
st.popInt();
st.display();
return 0;
}

