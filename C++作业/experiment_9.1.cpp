/*
 *理解下面的动态数组类模板，它由一系列位置连续、任意数量相同类型的元素组成，
 *元素个数可在程序运行时改变，并完成该类中没有完成的成员函数（不允许改变已有，
 *代码）并设计主函数，实现对该模板类的功能测试。
 */ 
#include <iostream>
using namespace std;
enum ErrorType{ invalidArraySize, memoryAllocatetionError, indexOutOfRang};
char *errorMsg[] = {"Invalid array size","Memory allocatetion error","Invalid index"};
template <class T>
class Array
{
private:
	T *alist;
	int size;
	void Error(ErrorType error)const{cout<<errorMsg[error]; exit(0);}//输出错误信息
public:
	Array(int sz=50);//构造函数
	Array(const Array<T>& X);//析构函数
	~Array(void);
	Array<T>& Equal(const Array<T>& rhs);
	T& GetItem(int i);
	int Getsize(void)const;//获取数组大小
	void Resize(int sz);//重新设置数组大小	
};

template <class T>
Array<T>::Array(int sz)
{
	if(sz <= 0)
		Error(invalidArraySize);
	size = sz;
	alist = new T[size];
	if(alist == 0)
		Error(memoryAllocatetionError);
	for(int i=0;i<size; i++)
		alist[i] = i;
}

template <class T>
Array<T>::Array(const Array<T> & x)
{
	int n = x.size;
	size = n;
	alist = new T[n];
	if(alist == 0)
		Error(memoryAllocatetionError);
	T * srcptr = x.alist;
	T * destptr = alist;
	while(n--)
		*destptr++=*srcptr++;
}

template <class T>
Array<T>::~Array()
{
	delete[] alist;
}
template <class T>

Array<T>& Array<T>::Equal(const Array<T> &rhs)
{
	int  n = rhs.size;
	if(size != n)
	{
		delete[] alist;
		alist = new T[n];
		if(alist == 0)
			Error(memoryAllocatetionError);
		size = n;
	}
	T * destptr = alist;
	T * srcptr = rhs.alist;
	while(n--)
		*destptr++ = *srcptr++;
	return *this;
}

template <class T>
T &Array<T>::GetItem(int n)
{
	if(n<0 || n>size-1)
		Error(indexOutOfRang);
	return alist[n];
} 

template <class T>
int Array<T>::Getsize() const
{
	return size;
}

template <class T>
void Array<T>::Resize(int sz)
{
	size = sz;
}

int main()
{
	Array<int>array(10);
    array.Getsize();
    cout<<"没有重新设置之前 size = "<<array.Getsize()<<endl;
    array.Resize(20);
	cout<<"重新设置数组之后 size = "<<array.Getsize()<<endl;
	return 0;
}

