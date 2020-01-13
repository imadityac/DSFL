
#include<iostream>
using namespace std;
#include<stdlib.h>

class TREE
{
	int *data;
	TREE **left;
	TREE **right;
	public:
	TREE()
	{
		data=new int;
		left=new TREE*;
		right=new TREE*;
	}
	void insert(int flag);
	TREE * setleft(TREE *ptr);
	TREE * setright(TREE *ptr);
	int retdata();
	
	void display();
	TREE * checkleft();
	TREE * checkright();
	
	int delet(int key);
	int search(int key);
	void mirror(TREE * mroot);
	void in_display();
	void pre_display();
	void post_display();
	void level_display(int *height,int *maxht,int level);
};

class STACK
{
	TREE **address;
	STACK **next;
	public:
	STACK()
	{
		address=new TREE*;
		next=new STACK*;
	}
	void setnext(STACK *ptr);
	STACK * push(TREE *root,STACK *top);
	TREE * pop();
	STACK * retnext();
	
};

class QUE
{
	TREE **address;
	QUE **next;
	public:
	QUE()
	{
		address=new TREE*;
		next=new QUE*;
	}
	void enque(TREE *ptr);
	void setnext(QUE *qptr);
	TREE * deque();
	QUE * retnext();
};

void display_in(TREE *root);
void display_pre(TREE *root);
void display_post(TREE *root);
void BFS(TREE *root);

//	//	//	//	//	//	//	//	//	//	TREE

int TREE::retdata()
{
	return *data;
}
void TREE::insert(int flag)
{
	if(flag==0)
	{
		cout<<"\n\tEnter the data >>";
		cin>>*data;
	}
	else 
		*data=flag;	

	*left=NULL;
	*right=NULL;
}
TREE * TREE::setleft(TREE *ptr)
{
	if(*left==NULL)
	{
		*left=ptr;
		return NULL;
	}
	else 
		return *left;
}
TREE * TREE::setright(TREE *ptr)
{
	if(*right==NULL)
	{
		*right=ptr;
		return NULL;
	}
	else 
		return *right;
}

void TREE::display()
{
	cout<<*data<<"  ";
}
TREE * TREE::checkleft()
{		
	if(*left==NULL)
		return NULL;
	return *left;
}
TREE * TREE::checkright()
{
	if(*right==NULL)
		return NULL;
	return *right;
}

int TREE::delet(int key)	//Delete
{
    TREE *temp,*tleft,*tright;
    int flag=0;
    
	if(*data==key)
    {
	    if(*left==NULL && *right==NULL)
	    	return 1;
	    else if(*left==NULL)
	    	return 2;
	    else  if(*right==NULL)
	    	return 3;
	    else 
	    	return 4;
	}
	else if(key<*data && *left!=NULL)
	{
		temp=*left;
		flag=temp->delet(key);
		
		if(flag==1)
		{
			temp=*left;
			*left=NULL;
			delete(temp);
		}
		else if(flag==2)
		{
			temp=*left;
			*left=temp->checkright();
			delete(temp);
		}
		else if(flag==3)
		{	
			temp=*left;
			*left=temp->checkleft();
			delete(temp);
		}
		else if(flag==4)
		{
			temp=*left;
			temp=temp->checkright();
			while(temp->checkleft()!=NULL)
				temp=temp->checkleft();
			
			flag=temp->retdata();
			
			temp=*left;
			temp->delet(flag);
			tleft=temp->checkleft();
			tright=temp->checkright();
			temp->insert(flag);
			temp->setleft(tleft);
			temp->setright(tright);
		}
		return 0;
	}
	else if(key>*data && *right!=NULL)
	{
		temp=*right;
		flag=temp->delet(key);
		
		if(flag==1)
		{
			temp=*right;
			*right=NULL;
			delete(temp);
		}
		else if(flag==2)
		{
			temp=*right;
			*right=temp->checkright();
			delete(temp);
		}
		else if(flag==3)
		{	
			temp=*right;
			*right=temp->checkleft();
			delete(temp);
		}
		else if(flag==4)
		{
			temp=*right;
			temp=temp->checkright();
			while(temp->checkleft()!=NULL)
				temp=temp->checkleft();
			
			flag=temp->retdata();
			
			temp=*right;
			temp->delet(flag);
			tleft=temp->checkleft();
			tright=temp->checkright();
			temp->insert(flag);
			temp->setleft(tleft);
			temp->setright(tright);
		}
		return 0;
	}
}
int TREE::search(int key)	//Search
{
 	TREE *temp; int flag=0;
	
	if(*data==key)
    {
        cout<<"\n\tKey Present ";
	    cout<<*data<<"  ";
	    return 1;
	}
	else if(key<*data && *left!=NULL)
	{
		temp=*left;
		flag=temp->search(key);
	}
	else if(key>*data && *right!=NULL)
	{
		temp=*right;
		flag=temp->search(key);
	}
	return flag;
}
void TREE::mirror(TREE *mroot)	//mirror of TREE
{
	TREE *temp;
	mroot->insert(*data);
	
	if(*left!=NULL)
	{
		temp=new TREE;
		(*left)->mirror(temp);
		mroot->setright(temp);
	}
	if(*right!=NULL)
	{
		temp=new TREE;
		(*right)->mirror(temp);
		mroot->setleft(temp);	
	}
}
void TREE::in_display()		//InOrder traversal
{
	TREE *temp;
	
	if(*left!=NULL)
	{
		temp=*left;
		temp->in_display();
	}
	cout<<*data<<"  ";
	if(*right!=NULL)
	{
		temp=*right;
		temp->in_display();
	}
}
void TREE::pre_display()	//PreOrder traversal
{
	TREE *temp;
	
	cout<<*data<<"  ";
	if(*left!=NULL)
	{
		temp=*left;
		temp->pre_display();
	}
	if(*right!=NULL)
	{
		temp=*right;
		temp->pre_display();
	}
}
void TREE::post_display()	//PostOrder traversal
{
	TREE *temp;
	
	if(*left!=NULL)
	{
		temp=*left;
		temp->post_display();
	}
	if(*right!=NULL)
	{
		temp=*right;
		temp->post_display();
	}
	cout<<*data<<"  ";
}
void TREE::level_display(int *height,int *maxht,int level)	//level wise display
{
	if( (*height)==level )
		cout<<*data<<"  ";
		
	if(*left!=NULL)
	{
		(*height)++;
		if(*maxht < *height)
			*maxht=*height;
		
		(*left)->level_display(height,maxht,level);
		(*height)--;
	}
	if(*right!=NULL)
	{
		(*height)++;
		if(*maxht < *height)
			*maxht=*height;

		(*right)->level_display(height,maxht,level);
		(*height)--;
	}
}

//	//	//	//	//	//	//	//	//	//	STACK

void STACK::setnext(STACK *ptr)
{
	*next=ptr;
}
STACK * STACK::push(TREE *root,STACK *top)
{
	*address=root;
	*next=top;
	return this;
}
TREE * STACK::pop()
{
	return *address;
}
STACK * STACK::retnext()
{
	return *next;
}


//	//	//	//	//	//	//	//	//	//	QUE

void QUE::enque(TREE *ptr)
{
	*address=ptr;
	*next=NULL;
}
void QUE::setnext(QUE *qptr)
{
	*next=qptr;
}
TREE * QUE::deque()
{
	return *address;
}
QUE * QUE::retnext()
{
	return *next;
}

//	//	//	//	//	//	//	//	//	//	Function

void display_in(TREE *root)		//NonRecursive Inorder Traversal
{
	STACK *top=NULL,*stackptr;
	int flag=0;
	
	while(1)
	{
	if(flag==0)
	{
		if(root->checkleft()!=NULL)
		{
			stackptr=new STACK;
			top=stackptr->push(root,top);
			
			root=root->checkleft();
		}
		else
			flag=1;
	}
	else if(flag==1)
	{	
		root->display();

		if(root->checkright()!=NULL)
		{
			flag=0;
			root=root->checkright();
		}
		else
		{
			flag=1;
			if(top!=NULL)
			{
				root=top->pop();
				top=top->retnext();
			}
			else 
				break;
		}
	}
	}
}
void display_pre(TREE *root)	//NonRecursive Preorder Traversal
{
	STACK *top=NULL,*stackptr;
	int flag=0;
	
	while(1)
	{
	if(flag==0)
	{
		root->display();
		if(root->checkleft()!=NULL)
		{
			stackptr=new STACK;
			top=stackptr->push(root,top);
			
			root=root->checkleft();
		}
		else
			flag=1;
	}
	else if(flag==1)
	{
		if(root->checkright()!=NULL)
		{
			flag=0;
			root=root->checkright();
		}
		else
		{
			flag=1;
			if(top!=NULL)
			{
				root=top->pop();
				top=top->retnext();
			}
			else 
				break;
		}
	}
	}
}
void display_post(TREE *root)	//NonRecursive Postorder Traversal
{
    TREE *temp;
	STACK *top=NULL,*stackptr;
	int flag=0;
	
	while(1)
	{
	if(flag==0)
	{
		if(root->checkleft()!=NULL)
		{
			stackptr=new STACK;
			top=stackptr->push(root,top);
			
			root=root->checkleft();
			flag=0;
		}
		else
			flag=1;
	}
	else if(flag==1)
	{
		if(root->checkright()!=NULL)
		{
			stackptr=new STACK;
			top=stackptr->push(root,top);
			
			root=root->checkright();
			flag=0;
		}
		else
			flag=2;
	}
	else if(flag==2)
	{
	    root->display();
	    temp=root;
	    if(top!=NULL)
		{
			root=top->pop();
			top=top->retnext();
			
	        if(root->checkleft()==temp)
	            flag=1;
	        else if(root->checkright()==temp)
	            flag=2;
		}
		else 
			break;
	}
	}
}
void BFS(TREE *root)	//Level Wise Display
{
	TREE *ptr;
	QUE *front=NULL,*rear=NULL,*qptr;
	
	while(1)
	{
		root->display();
		if(root->checkleft()!=NULL)
		{
			ptr=root->checkleft();
			qptr=new QUE;
			qptr->enque(ptr);
			
			if(front==NULL)
				front=rear=qptr;
			else
			{
				rear->setnext(qptr);
				rear=qptr;
			}
		}
		if(root->checkright()!=NULL)
		{
			ptr=root->checkright();
			qptr=new QUE;
			qptr->enque(ptr);
			
			if(front==NULL)
				front=rear=qptr;
			else
			{
				rear->setnext(qptr);
				rear=qptr;
			}
		}
		if(front==NULL)
			break;
		root=front->deque();
		qptr=front;
		front=front->retnext();
		delete(qptr);
	}
}
