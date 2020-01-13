
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
#define MAX 10

class FB
{
    char *name;
    struct DOB
    {
    	int date;
    	int month;
    	int year;
    }*DOB;
    int *comments;
    int *index;
    FB **next;
    public:
    FB()
    {
        name=new char[10];
        DOB=new struct DOB;
        comments=new int;
       	index=new int;
        next=new FB*;
    }
    void copy(FB *ptr);
    void insert(int flag);
    void display(int flag);
    int info(int flag);
    FB * fnext(FB *ptr);
};

class STACK
{
	FB **address;
	STACK **next;
	public:
	STACK()
	{
		address=new FB*;
		next=new STACK*;
	}
	STACK * push(STACK *top,FB *ptr);
	FB * pop();
	STACK * fnext();
};

class QUE
{
	FB **address;
	QUE **next;
	public:
	QUE()
	{
		address=new FB*;
		next=new QUE*;
	}
	void enque(FB *ptr);
	FB * deque();
	QUE * fnext(QUE *rear);
};


void adduser(FB *user[MAX],int *n);
void DFT(FB *user[MAX],int *n);
void BFT(FB *user[MAX],int *n);
void MaxFriends(FB *user[MAX],int *n);
void CommentCount(FB *user[MAX],int *n);
void Birthdays(FB *user[MAX],int *n);


//  //  //  //  //  //  //  //  //  //  FB

void FB::copy(FB *ptr)
{
    strcpy(name,ptr->name);
    DOB=ptr->DOB;
    *comments=*ptr->comments;
    *index=*ptr->index;
    *next=NULL;
}
void FB::insert(int flag)
{
    cout<<"\n\tEnter the name >> ";
    cin>>name;
    
    while(1)
    {
		cout<<"\tEnter the DOB(date month year) >> ";
		cin>>DOB->date;
		cin>>DOB->month;
		cin>>DOB->year;
		
		if(DOB->year>0 && DOB->month>0 && DOB->date>0)
		{
			if(DOB->year<2015 && DOB->year>1900 && DOB->year%4==0 && DOB->month==2 && DOB->date<30)
				break;
			else if(DOB->year<2015 && DOB->year>1900 && DOB->year%4!=0 && DOB->month==2 && DOB->date<29)
				break;
			else if(DOB->year<2015 && DOB->year>1900 && DOB->month%2!=0 && DOB->date<32)
				break;
			else if(DOB->year<2015 && DOB->year>1900 && DOB->month%2==0 && DOB->month!=2 && DOB->date<31)
				break;
			else
				cout<<"\n\tINVALID\n";	
    	}
    	else
			cout<<"\n\tINVALID\n";
    }
    cout<<"\tEnter the No.of comments >> ";
    cin>>*comments;
    *index=flag;
    *next=NULL;
}
void FB::display(int flag)
{
    if(flag==1)
        cout<<"\n\t"<<name<<"\t\t"<<DOB->date<<"/"<<DOB->month<<"/"<<DOB->year<<"\t\t"<<*comments;
    else
    	cout<<name;
}
int FB::info(int flag)
{
	if(flag==10)
		return *index;
	else if(flag==20)
		return *comments;
	else
		return DOB->month;
}
FB * FB::fnext(FB *ptr)
{
	if(ptr==NULL)
		return *next;
	
	*next=ptr;
	return NULL;
}

//	//	//	//	//	//	//	//	//	//	STACK

STACK * STACK::push(STACK *top,FB *ptr)
{
	*address=ptr;
	*next=top;
	return this;
}
FB * STACK::pop()
{
	return *address;
}
STACK * STACK::fnext()
{
	return *next;
}

//	//	//	//	//	//	//	//	//	//	QUE

void QUE::enque(FB *ptr)
{
	*address=ptr;
	*next=NULL;
}
FB * QUE::deque()
{
	return *address;
}
QUE * QUE::fnext(QUE *temp)
{
	if(temp==NULL)
		return *next;
	*next=temp;
	return NULL;
}

//	//	//	//	//	//	//	//	//	//	Functions

void adduser(FB *user[MAX],int *n)
{
	FB *temp,*ptr;
	int i,flag;
	
    if(*(n)+1<MAX)
	{
		user[*n]=new FB;
       	user[*n]->insert(*n);
       	(*n)++;
           	
        for(i=0;i<*(n)-1;i++)
        {
        	cout<<"\n\t\"";
           	user[i]->display(0);
            cout<<"\"  <-->  \"";
            user[*(n)-1]->display(0);
               	
            cout<<"\"\n\t1:Friend's	0:Ignore >> ";
            cin>>flag;
            if(flag==1)
            {
                ptr=new FB;
                ptr->copy(user[*(n)-1]);
                temp=user[i];
                while(temp->fnext(NULL)!=NULL)
                   	temp=temp->fnext(NULL);
                temp->fnext(ptr);
                        
                ptr=new FB;
                ptr->copy(user[i]);
                temp=user[*(n)-1];
                while(temp->fnext(NULL)!=NULL)
                   	temp=temp->fnext(NULL);
                temp->fnext(ptr);
            }
        }
    }
}

void DFT(FB *user[MAX],int *n)
{
	FB *ptr;
	STACK *top=NULL,*sptr;
	int visit[MAX]={0},flag;
    		
   	visit[0]=1;
   	sptr=new STACK;
	top=sptr->push(top,user[0]);
    
    while(top!=NULL)
    {    	
	    ptr=top->pop();
     	ptr->display(1);
     	
	    sptr=top;
     	top=top->fnext();
     	delete(sptr);
     	
     	while(ptr!=NULL)
     	{
     	  	flag=ptr->info(10);
     	  	if(visit[flag]!=1)
	     	{
	     		visit[flag]=1;
	   			sptr=new STACK;
	     	 	top=sptr->push(top,user[flag]);
     	  	}
     	ptr=ptr->fnext(NULL);
     	}
    }
}

void BFT(FB *user[MAX],int *n)
{
	FB *ptr;
	QUE *front=NULL,*rear=NULL,*temp;
	int visit[MAX]={0},flag;
    		
	visit[0]=1;
   	temp=new QUE;
	temp->enque(user[0]);
   	if(front==NULL)
    	front=temp;
   	else
   		rear->fnext(temp);
   	rear=temp;
   	
    while(front!=NULL)
    {    	
	    ptr=front->deque();
     	ptr->display(1);
     	
	    temp=front;
     	front=front->fnext(NULL);
     	delete(temp);
     	
     	while(ptr!=NULL)
     	{
     	  	flag=ptr->info(10);
     	  	if(visit[flag]!=1)
	     	{
	     		visit[flag]=1;
	   			temp=new QUE;
	     	 	temp->enque(user[flag]);
     	  		if(front==NULL)
    				front=temp;
   				else
   					rear->fnext(temp);
   				rear=temp;
     	  	}
     	ptr=ptr->fnext(NULL);
     	}
    }
}

void MaxFriends(FB *user[MAX],int *n)
{
	FB *ptr;
	QUE *front=NULL,*rear=NULL,*temp;
	int visit[MAX]={0},max[MAX]={0},flag,count,fmax;

	visit[0]=1;
   	temp=new QUE;
	temp->enque(user[0]);
   	if(front==NULL)
    	front=temp;
   	else
   		rear->fnext(temp);
   	rear=temp;
   	
    while(front!=NULL)
    {    	
	    ptr=front->deque();
     	count=ptr->info(10);
     	
	    temp=front;
     	front=front->fnext(NULL);
     	delete(temp);
     	
     	while(ptr!=NULL)
     	{
     	  	flag=ptr->info(10);
     	  	max[count]++;
     	  	if(visit[flag]!=1)
	     	{
	     		visit[flag]=1;
	   			temp=new QUE;
	     	 	temp->enque(user[flag]);
     	  		if(front==NULL)
    				front=temp;
   				else
   					rear->fnext(temp);
   				rear=temp;
     	  	}
     	ptr=ptr->fnext(NULL);
     	}
    }
    for(count=fmax=0 ; count<*n ; count++)
    	if(max[fmax]<max[count])
    		fmax=count;
    		
	cout<<"\n\t\"";
    user[fmax]->display(0);
    cout<<"\" has max-friends ("<<max[fmax]-1<<")";
    
}

void CommentCount(FB *user[MAX],int *n)
{
	FB *ptr;
	STACK *top=NULL,*sptr;
	int visit[MAX]={0},flag,max,min;
    		
   	visit[0]=1;
   	sptr=new STACK;
	top=sptr->push(top,user[0]);
    
    max=min=0;
    while(top!=NULL)
    {    	
	    ptr=top->pop();
     	
	    sptr=top;
     	top=top->fnext();
     	delete(sptr);
     	
     	while(ptr!=NULL)
     	{
     	  	flag=ptr->info(10);
     	  	if(visit[flag]!=1)
	     	{
	     		visit[flag]=1;
     	  		if(user[max]->info(20)<ptr->info(20))
     	  			max=ptr->info(10);
     	  		if(user[min]->info(20)>ptr->info(20))
     	  			min=ptr->info(10);
     	  		
	   			sptr=new STACK;
	     	 	top=sptr->push(top,user[flag]);
     	  	}
     	ptr=ptr->fnext(NULL);
     	}
    }
    cout<<"\n\tMax Comments:\n\t\"";
    user[max]->display(0);
    cout<<"\" - "<<user[max]->info(20);
    
    cout<<"\n\tMin Comments:\n\t\"";
    user[min]->display(0);
    cout<<"\" - "<<user[min]->info(20);
}

void Birthdays(FB *user[MAX],int *n)
{
	FB *ptr;
	QUE *front=NULL,*rear=NULL,*temp;
	int visit[MAX]={0},flag,count=0,bmon1,bmon2;

	cout<<"\n\tFind birthdays in month-";
	cin>>bmon1;

	visit[0]=1;
   	temp=new QUE;
	temp->enque(user[0]);
   	if(front==NULL)
    	front=temp;
   	else
   		rear->fnext(temp);
   	rear=temp;
     	  	
    bmon2=user[0]->info(30);
    if(bmon1==bmon2)
    {
    	cout<<"\n\t";
    	user[0]->display(1);
    	count++;
    }
   	
    while(front!=NULL)
    {    	
	    ptr=front->deque();
     	
	    temp=front;
     	front=front->fnext(NULL);
     	delete(temp);
     	
     	while(ptr!=NULL)
     	{
     	  	flag=ptr->info(10);
     	  	if(visit[flag]!=1)
	     	{
	     		visit[flag]=1;
     	  		bmon2=ptr->info(30);
     	  		if(bmon1==bmon2)
     	  		{
     	  			cout<<"\n\t";
     	  			ptr->display(1);
     	  			count++;
     	  		}
     	  	
	   			temp=new QUE;
	     	 	temp->enque(user[flag]);
     	  		if(front==NULL)
    				front=temp;
   				else
   					rear->fnext(temp);
   				rear=temp;
     	  	}
     	ptr=ptr->fnext(NULL);
     	}
    }
    if(count==0)
    	cout<<"\n\tNo birthdays Found in month-"<<bmon1;
    
}
