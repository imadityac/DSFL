
#include<iostream>
using namespace std;
#include<stdlib.h>
#define MAX 10

class QUE
{
	int *id;
	char *name,*disease;
	QUE **next;
	public:
	QUE()
	{
		id=new int;
		name=new char[20];
		disease=new char[20];
		next=new QUE*;
	}
	void insert(QUE * []);
	QUE * display(int flag);
	void setnext(QUE *);
	int ret_id()
	{
		return *id;
	}
};

//	//	//	//	//	//	//	//	//	//

void QUE::insert(QUE *front[3])
{
	int flag,i;
	QUE *temp;
	while(1)
	{
	flag=0;
	cout<<"\n\tEnter the id >> ";
	cin>>*id;
		for(i=0 ; i<3 ; i++)
		{
			temp=front[i];
			while(temp!=NULL)
			{
				if(*id==temp->ret_id())
				flag=1;
				temp=temp->display(0);
			}
		}
		if(flag==0)
			break;
		cout<<"\n\tEntered ID already assigned :(";
	}
	cout<<"\tEnter NAME >> ";
	cin>>name;
	cout<<"\tEnter Disease >> ";
	cin>>disease;
	*next=NULL;
}
QUE * QUE::display(int flag)
{
	if(flag==1)
		cout<<"\n\t"<<*id<<"\t"<<name<<"\t\t"<<disease;
	return *next;
}
void QUE::setnext(QUE *ptr)
{
	*next=ptr;
}
