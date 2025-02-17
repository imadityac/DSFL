
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>

class TREE
{
	char *data;
	TREE **left;
	TREE **right;
	public:
	TREE()
	{
		data=new char[10];
		left=new TREE*;
		right=new TREE*;
	}
	void insert(char *flag);
	TREE * setleft(TREE *ptr);
	TREE * setright(TREE *ptr);
	
	void display();
	TREE * checkleft();
	TREE * checkright();
	
	void in_display();
	void pre_display();
	void post_display();
	
	void depth(int *,int *);
	void leafnodes();
	void copy(TREE *);
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

void display_in(TREE *root);
void display_pre(TREE *root);
void display_post(TREE *root);

//	//	//	//	//	//	//	//	//	//	TREE

void TREE::insert(char *flag)
{
	if(flag==NULL)
	{
		cout<<"\n\tEnter the data of node : ";
		cin>>data;
	}
	else
		strcpy(data,flag);
	
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
	cout<<data<<"  ";
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

void TREE::in_display()			//Recursive Inorder Traversal
{
	TREE *temp;
	
	if(*left!=NULL)
	{
		temp=*left;
		temp->in_display();
	}
	cout<<data<<"  ";
	if(*right!=NULL)
	{
		temp=*right;
		temp->in_display();
	}
}
void TREE::pre_display()		//Recursive Preorder Traversal
{
	TREE *temp;
	
	cout<<data<<"  ";
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
void TREE::post_display()		//Recursive Postorder Traversal
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
	cout<<data<<"  ";
}

void TREE::depth(int *ht,int *maxht)//Depth of TREE
{
	TREE *temp;

	if(*left!=NULL)
	{
		temp=*left;
		(*ht)++;
		if(*ht > *maxht)
			*maxht=*ht;
		temp->depth(ht,maxht);
		(*ht)--;
	}
	if(*right!=NULL)
	{
		temp=*right;
		(*ht)++;
		if(*ht > *maxht)
			*maxht=*ht;
		temp->depth(ht,maxht);
		(*ht)--;
	}
}
void TREE::leafnodes()			//Display Leaf-Nodes
{
	TREE *temp;
	int flag=0;
	
	if(*left!=NULL)
	{
		flag++;
		temp=*left;
		temp->leafnodes();
	}
	if(*right!=NULL)
	{
		flag++;
		temp=*right;
		temp->leafnodes();
	}
	if(flag==0)
		cout<<data<<"  ";
		
}
void TREE::copy(TREE *root)		//copy of TREE
{
	TREE *temp;
	
	root->insert(data);
	if(*left!=NULL)
	{
		temp=new TREE;
		root->setleft(temp);
		(*left)->copy(temp);		
	}
	if(*right!=NULL)
	{
		temp=new TREE;
		root->setright(temp);
		(*right)->copy(temp);
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

//	//	//	//	//	//	//	//	//	//	Functions:

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
