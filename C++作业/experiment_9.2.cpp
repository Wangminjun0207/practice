/*
 *设计一个通用链表类，要求如下：
 *a．数据成员包含头指针、尾指针、链表中节点个数、顺序访问中当前节点指针和当前节点前一个节点的指针；
 *b．主要的成员函数包含：生成节点（在链表头、尾以及任意位置）、插入节点、删除节点、访问/修改节点、遍历链表，以及一些辅助函数等；
 *c．能实现两个链表的复制；
 *d．能实现两个链表对象的赋值；
 *e．在测试程序中定义两个整型链表A和B，分别插入5个元素，然后把B中的元素加入A的尾部。
 */
#include<iostream>
#include<string>
using namespace std;

template <class T>
struct Node
{
	int Data;
	Node<T> *Next;
};

template<class T>
class Tlist
{
private:
	Node<T> *head,*tail,*now,*before;
	int node_num;
public:
	Tlist():head(NULL),tail(NULL),now(NULL),before(NULL),node_num(0){}
	Tlist(Tlist &s){s.head=head;}
	~Tlist(){}
	  void creat();//生成节点
	  void Traverse();//遍历链表
	  void insertlist();//在节点前插入节点b 
	  void deletelist();
	  void connect(Node<T> *pnode)
	  {
		  tail=head;
		  while(tail->Next!=NULL)
		  {
			  tail=tail->Next;
		  }
		  tail->Next=pnode;
	  }
	  Node<T> *gethead(){return head;}
};

template<class T>
void Tlist<T>::creat()
{
	
	cout<<"输入0时停止创建"<<endl;
	now=before=new Node<T>;
	cout<<"Data:";
	cin>>now->Data;
	while(now->Data!=0)
	{
		node_num++;
		if(node_num==1)
			head=now;
		else 
			before->Next=now;
		before=now;
		now=new Node<T>;
		cout<<"Data:";
		cin>>now->Data;

	}
	before->Next=NULL;
	tail=now;
	delete now;
}
template<class T>
void Tlist<T>::Traverse()
{
	
	Node<T>  *p;
	p=head;
	int count=1;                                                                                 
	while(p!=NULL)
	{
		cout<<"这是第"<<count<<"个节点Data为:"<<p->Data<<endl;
		p=p->Next;count++;
	}
}


template<class T>
void  Tlist<T>::insertlist()
{
	Node<T>  *newn= new Node<T> ;
	cout<<"请输入你要插入的数组信息Data：";
	cin>>newn->Data;
	Node<T>  *p0,*p1,*p2;
	p1=head;
	p0=newn;
	if(head==NULL)
	{head=p0;p0->Next=NULL;
	tail=p0;}
	else
	{
		while((p0->Data>p1->Data)&&(p1->Next!=NULL))
		{p2=p1;	p1=p1->Next;}//找到要插入的节点
		if(p0->Data<=p1->Data)
		{
			if(head==p1)  head=p0;
			else  p2->Next=p0;
			p0->Next=p1;
		}
		
		else
		{p1->Next=p0;p0->Next=NULL;tail=p0;}
	}
	node_num+=1;

}

template<class T>
void Tlist<T>::deletelist()
{
	int num;
	Node<T>  *p1,*p2;
	cout<<"请输入你要删除的节点数据:";
	cin>>num;
	p1=head;
	while(p1->Data!=num&&p1->Next!=NULL)
	{
		p2=p1;
		p1=p1->Next;
	}
	if(p1->Data==num)
	{
		if(p1==head)   head=head->Next;
		else     p2->Next=p1->Next;
		delete p1;
		cout<<"成功删除"<<num<<endl;
		node_num=node_num-1;
	}
}

int main()
{
	Tlist<int > node1 , node2,A,B;
	node1.creat();
	node1.Traverse();
	Node<int> b;
	b.Data=0;
	node1.deletelist();
	cout<<"\n删除后节点数据为："<<endl;
	node1.Traverse();
	node1.insertlist();
	cout<<"\n插入后的节点"<<endl;
	node1.Traverse();
	node2=node1;//链对象的赋值
	cout<<"\nnoe1赋值给node2的链表："<<endl;
	node2.Traverse();
	cout<<"\nA链表创建"<<endl;
	A.creat();
	cout<<"B链表创建"<<endl;
	B.creat();
	A.connect(B.gethead());
	cout<<"A链表与B链表链接后：\n";
	A.Traverse();
	return 0;
}

