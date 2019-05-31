/***˳��ջ��ʵ��***/
#include<iostream>
#include<stdlib.h>
using namespace std;

//˳��ջ����
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//˳��ջ�洢�ռ�ĳ�ʼ������
typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType *base;//ջ��ָ��
	SElemType *top;//ջ��ָ��
	int stacksize;//ջ���õ��������
} SqStack;

//�㷨3.1��	
Status InitStack(SqStack &S) {
	//����һ����ջS
	S.base = new SElemType[MAXSIZE];//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	if (!S.base)
		exit(OVERFLOW); //�洢����ʧ��
	S.top = S.base; //top��ʼΪbase����ջ
	S.stacksize = MAXSIZE; //stacksize��Ϊջ���������MAXSIZE
	return OK;
}
//�㷨3.2��˳��ջ����ջ
Status Push(SqStack &S, SElemType e) {
	// ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base == S.stacksize)
		return ERROR; //ջ��
	*(S.top++) = e; //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//�㷨3.3��˳��ջ�ĳ�ջ
Status Pop(SqStack &S, SElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ	
	if (S.base == S.top)
		return ERROR;//ջ��
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
SElemType GetTop(SqStack S) {//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S.top != S.base) //ջ�ǿ�
		return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}

int StackEmpty(SqStack S)
{//�ж�ջ�Ƿ�ǿգ��շ���1���ǿշ���0
     	if (S.top == S.base) //ջ��
     	  return 1;
     	else
     	  return 0;
}

void conversion(int N,int m)//����ת�� 
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

Status Matching()//����ƥ�� 
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
	cout << "1. ��ʼ��ջ\n";
	cout << "2. Ԫ�ؽ�ջ\n";
	cout << "3. Ԫ�س�ջ\n";
	cout << "4. ���Ƶ�ת��\n";
	cout << "5. ����ƥ��ļ���\n";
	cout << "0. �˳�\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��:";
		cin>>choose;
		switch(choose)
		{
			case 1://��ʼ��ջ 
			if (InitStack(s))
				{
					cout << "�ɹ�����ջ\n\n";
			    	if(StackEmpty(s))
					cout<<"��ջΪ��ջ\n\n";
				} 
			else
				cout << "ջ����ʧ��\n\n";
			
			break;
			case 2://Ԫ�ؽ�ջ
			cout<<"�����ջԪ�ظ�����";
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
			  		{ //����ջ�쳣ʱ�����"POP ERROR",��������
			     	cout<<"POP ERROR"<<endl;
			     	break;			    				
			  		}	 
				else
			  		cout<<temp<<endl;
				}			 
			}
			if(StackEmpty(s))
	  				cout<<"ջ�գ�"<<endl;	  
			else
	  				cout<<"ջ��Ԫ��Ϊ�� "<<GetTop(s)<<endl;
	  				cout<<"\n";
	  				cout<<"\n";
			break;
			case 3://Ԫ�س�ջ
			cout<<"�����ջԪ�ظ�����";
			cin>>n;
			while(n--)
			{
			if(e!=-1)
			Pop(s,e);	
			else
				{
					t=Pop(s,temp);
				if(t==0)
			  		{ //����ջ�쳣ʱ�����"POP ERROR",��������
			     	cout<<"POP ERROR"<<endl;
			     	break;			    				
			  		}	 
				else
			  		cout<<temp<<endl;
				}			 
			}
			if(StackEmpty(s))
	  				cout<<"ջ�գ�"<<endl;	  
			else
	  				cout<<"ջ��Ԫ��Ϊ�� "<<GetTop(s)<<endl;
	  				cout<<"\n";
			break;
			case 4://���Ƶ�ת��
				InitStack(s);
			int n,m;
			cout<<"�����ʮ���Ƶ����ֺ�ҪתΪ�����ƣ�";
			cout<<"\n"; 
			while((cin>>n)&&(cin>>m)!=0)
			{
				cout<<"��ʮ���Ƶ�"<<n<<"ת��Ϊ"<<m<<"���ƣ�"<<endl;
				conversion(n,m);
				cout<<"\n\n";
				break;
			}
			break;
			case 5://����ƥ��
			Status Matching();
			 
			 
		}
	
	} 
	return 0;
}
