#include"3_binary_tree.h"

int main()
{
	TREE *root=NULL,*ptr,*temp,*copyroot;
	int choice,key=0,ht=0,maxht=0;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"\n\t\t** Binary Tree **\n";
	do
	{
		cout<<"\n--------------------MENU--------------------\n";
		cout<<"\n\t1:Insert\n\t2:Display\n\t3:Depth of Tree\n\t4:Display Leaf-Nodes\n\t5:Create copy of tree\n\t0:EXIT : ";
		cin>>choice;
	
		if(key++==0 && choice!=1)
			choice=1;
	
		switch(choice)
		{
			case 1:
				ptr=new TREE;		
				ptr->insert(NULL);
			
				if(root==NULL)
				{
					root=ptr;
					cout<<"\n\tRoot NODE created";
				}
				else
				{
					temp=root;
					while(temp!=NULL)
					{
						cout<<"\n\tAdd to 1:Left or 2:Right of (  ";
						temp->display();
						cout<<") >>";
						cin>>key;
						if(key==1)
							temp=temp->setleft(ptr);
						else if(key==2)
							temp=temp->setright(ptr);
					}
				}
				break;
			case 2:
				cout<<"\n\t\b\b\u1368 Recursion:\n\t1:InOrder\n\t2:PreOrder\n\t3:PostOrder";
				cout<<"\n\t\b\b\u1368 Without-Recursion  :\n\t4:InOrder\n\t5:PreOrder\n\t6:PostOrder :";
				cin>>choice;
				cout<<"\n\t>>";
			
				ptr=root;
				switch(choice)
				{
					case 1:
						ptr->in_display();
						break;
					case 2:
						ptr->pre_display();
						break;
					case 3:
						ptr->post_display();
						break;
					case 4:
						display_in(root);
						break;
					case 5:
						display_pre(root);
						break;
					case 6:
						display_post(root);
						break;
				}
				break;
			case 3:
				root->depth(&ht,&maxht);
				cout<<"\n\tDepth of Tree = "<<maxht;
				break;
			case 4:
				cout<<"\n\tLeaf-nodes is/are :\n\t";
				root->leafnodes();
				break;
			case 5:
				copyroot=new TREE;
				root->copy(copyroot);
				cout<<"\n\tCopy of TREE is created :)";
				cout<<"\n\t>>InOrder : ";
				copyroot->in_display();
				cout<<"\n\t>>PreOrder : ";
				copyroot->pre_display();
				cout<<"\n\t>>PostOrder : ";
				copyroot->post_display();
				break;
		}
	}while(choice!=0);
	
	cout<<"\n";
	return 0;
}

/*
			** OUTPUT **

		** Binary Tree **

--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 1

	Enter the data of node : 5

	Root NODE created
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 1

	Enter the data of node : 4

	Add to 1:Left or 2:Right of (  5  ) >>1

--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 1

	Enter the data of node : 0

	Add to 1:Left or 2:Right of (  5  ) >>1

	Add to 1:Left or 2:Right of (  4  ) >>1

--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 1

	Enter the data of node : 6

	Add to 1:Left or 2:Right of (  5  ) >>2

--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 1

	Enter the data of node : 4

	Add to 1:Left or 2:Right of (  5  ) >>2

	Add to 1:Left or 2:Right of (  6  ) >>1

--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :1

	>>0  4  5  4  6  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :2

	>>5  4  0  6  4  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :3

	>>0  4  4  6  5  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :4

	>>0  4  5  4  6  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :5

	>>5  4  0  6  4  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 2

      ፨ Recursion:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Without-Recursion  :
	4:InOrder
	5:PreOrder
	6:PostOrder :6

	>>0  4  4  6  5  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 3

	Depth of Tree = 2
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 4

	Leaf-nodes is/are :
	0  4  
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 5
  
	Copy of TREE is created :)
	>>InOrder : 0  4  5  4  6  
	>>PreOrder : 5  4  0  6  4  
	>>PostOrder : 0  4  4  6  5
--------------------MENU--------------------

	1:Insert
	2:Display
	3:Depth of Tree
	4:Display Leaf-Nodes
	5:Create copy of tree
	0:EXIT : 0
*/
