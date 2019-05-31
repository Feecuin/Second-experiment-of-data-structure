/***顺序栈的实现***/
#include<iostream>
#include<stdlib.h>
using namespace std;

//顺序栈定义
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//顺序栈存储空间的初始分配量
typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType *base;//栈底指针
	SElemType *top;//栈顶指针
	int stacksize;//栈可用的最大容量
} SqStack;

//算法3.1　	
Status InitStack(SqStack &S) {
	//构造一个空栈S
	S.base = new SElemType[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base)
		exit(OVERFLOW); //存储分配失败
	S.top = S.base; //top初始为base，空栈
	S.stacksize = MAXSIZE; //stacksize置为栈的最大容量MAXSIZE
	return OK;
}
//算法3.2　顺序栈的入栈
Status Push(SqStack &S, SElemType e) {
	// 插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize)
		return ERROR; //栈满
	*(S.top++) = e; //元素e压入栈顶，栈顶指针加1
	return OK;
}
//算法3.3　顺序栈的出栈
Status Pop(SqStack &S, SElemType &e) {
	//删除S的栈顶元素，用e返回其值	
	if (S.base == S.top)
		return ERROR;//栈空
	e = *(--S.top); //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//算法3.4　取顺序栈的栈顶元素
SElemType GetTop(SqStack S) {//返回S的栈顶元素，不修改栈顶指针
	if (S.top != S.base) //栈非空
		return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
}

int StackEmpty(SqStack S)
{//判定栈是否非空，空返回1，非空返回0
     	if (S.top == S.base) //栈空
     	  return 1;
     	else
     	  return 0;
}

void conversion(int N,int m)//数制转换 
{
	SqStack S;
	SElemType e;
	InitStack(S);
	while(N)
	{
		Push(S,N%m);
		N/=m;
	} 
	while(!StackEmpty(S)) 
	{
		Pop(S,e);
		cout<<e;
	}	 
}

Status Matching()//括号匹配 
{
	SqStack S;
	SElemType e;
	InitStack(S);
	int flag=1;
	char ch;
	cin>>ch;
	while(ch!='#'&&flag)
	{
		switch(ch)
		{
			case '[':
			case '(':
				Push (S,ch);
				break;
			case ')':
				if(!StackEmpty(S)&&GetTop(S)=='(')
					Pop(S,e);
				else flag=0;
				break;
			case ']':
				if(!StackEmpty(S)&&GetTop(S)=='[')	
					Pop(S,e);
				else flag=0;
				break;	
		}
		cin>>ch;
	}
	if(StackEmpty(S)&&flag)
		return true;
	else return false;
}

int main()
{	
	SqStack s;
	int n,t;
	SElemType e,temp,choose;
	cout << "1. 初始化栈\n";
	cout << "2. 元素进栈\n";
	cout << "3. 元素出栈\n";
	cout << "4. 数制的转换\n";
	cout << "5. 括号匹配的检验\n";
	cout << "0. 退出\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
			case 1://初始化栈 
			if (InitStack(s))
				{
					cout << "成功建立栈\n\n";
			    	if(StackEmpty(s))
					cout<<"此栈为空栈\n\n";
				} 
			else
				cout << "栈建立失败\n\n";
			
			break;
			case 2://元素进栈
			cout<<"输入进栈元素个数：";
			cin>>n;
			while(n--)
			{			
				cin>>e; 
				if(e!=-1)
		   		Push(s,e);
				else
				{
					t=Pop(s,temp);
				if(t==0)
			  		{ //当出栈异常时，输出"POP ERROR",并结束。
			     	cout<<"POP ERROR"<<endl;
			     	break;			    				
			  		}	 
				else
			  		cout<<temp<<endl;
				}			 
			}
			if(StackEmpty(s))
	  				cout<<"栈空！"<<endl;	  
			else
	  				cout<<"栈顶元素为： "<<GetTop(s)<<endl;
	  				cout<<"\n";
	  				cout<<"\n";
			break;
			case 3://元素出栈
			cout<<"输出出栈元素个数：";
			cin>>n;
			while(n--)
			{
			if(e!=-1)
			Pop(s,e);	
			else
				{
					t=Pop(s,temp);
				if(t==0)
			  		{ //当出栈异常时，输出"POP ERROR",并结束。
			     	cout<<"POP ERROR"<<endl;
			     	break;			    				
			  		}	 
				else
			  		cout<<temp<<endl;
				}			 
			}
			if(StackEmpty(s))
	  				cout<<"栈空！"<<endl;	  
			else
	  				cout<<"栈顶元素为： "<<GetTop(s)<<endl;
	  				cout<<"\n";
			break;
			case 4://数制的转换
				InitStack(s);
			int n,m;
			cout<<"请输出十进制的数字和要转为几进制：";
			cout<<"\n"; 
			while((cin>>n)&&(cin>>m)!=0)
			{
				cout<<"将十进制的"<<n<<"转换为"<<m<<"进制："<<endl;
				conversion(n,m);
				cout<<"\n\n";
				break;
			}
			break;
			case 5://括号匹配
			Status Matching();
			 
			 
		}
	
	} 
	return 0;
}
