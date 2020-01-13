#include"5_bst.h"

int main()
{
	TREE *root=NULL,*ptr,*temp,*mroot;
	int choice,key,flag;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	do
	{
	cout<<"\n--------------------MENU--------------------\n";
	cout<<"\n\t1:Insert\n\t2:Delete\n\t3:Search\n\t4:MirrorImage\n\t5:Display\n\t6:Display Level Wise\n\t0:EXIT  >>";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			ptr=new TREE;
			ptr->insert(0);
			
			if(root==NULL)
				root=ptr;
			else 
			{
				temp=root;
				while(temp!=NULL)
				{
				if(ptr->retdata() < temp->retdata())
					temp=temp->setleft(ptr);
				else
					temp=temp->setright(ptr);
				}
			}
			break;
		case 2:
		    cout<<"\n\tEnter the key to delete >>";
		    cin>>key;
		    if(root->search(key)==1)
			{
		    	flag=root->delet(key);
		    
		    	if(flag==1)
				{
					cout<<"\n\tTREE has only-one Node(ROOT).So deletion of it will result into Segmentation-Fault.";
					cout<<"\n\tEnter 1:continue 0:Terminate >>";
					cin>>flag;
					if(flag==1)
						delete(root);
				}
				else if(flag==2)
				{
					temp=root;
					root=root->checkright();
		    		delete(temp);	
		    	}
		    	else if(flag==3)
		    	{
					temp=root;
					root=root->checkleft();
		    		delete(temp);
		    	}
		    	else if(flag==4)
		    	{
					temp=root;
					temp=temp->checkright();
					while(temp->checkleft()!=NULL)
						temp=temp->checkleft();
					
					flag=temp->retdata();
					
					root->delet(flag);
					temp=root->checkleft();
					ptr =root->checkright();
					root->insert(flag);
					root->setleft(temp);
					root->setright(ptr);
				}
				cout<<"\n\tKey Deleted Successfully";
			}
		   	else
		        cout<<"\n\tKey Not Present";
				
			break;
		case 3:
		    cout<<"\n\tEnter search key >> ";
		    cin>>key;
		    if(root->search(key)!=1)
		        cout<<"\n\tKey Not Present";
		    break;
		case 4:
			mroot=new TREE;
			root->mirror(mroot);
			cout<<"\n\t>>InOrder\t:";
			mroot->in_display();
			cout<<"\n\t>>PreOrder\t:";
			mroot->pre_display();
			cout<<"\n\t>>PostOrder\t:";
			mroot->post_display();
			cout<<"\n\tMirror of TREE is created :)";
		    break;
		case 5:
			cout<<"\n\t\b\b\u1368 RECURSIVE:\n\t1:InOrder\n\t2:PreOrder\n\t3:PostOrder";
			cout<<"\n\t\b\b\u1368 Non-REC  :\n\t4:InOrder\n\t5:PreOrder\n\t6:PostOrder";
			cout<<"\n\t\b\b\u1368 7:Breadth-First >>";

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
				case 7:
	    			BFS(root);
					break;
			}
			break;
	    case 6:
	    	flag=0,choice=1,key=0;
	    	cout<<"\n\tDisplay level wise \n\t>>\t";
	    	for(key=0 ; key<=choice ; key++)
	    	{
	    		for(int i=0 ; i<key ; i++)
	    			cout<<"\b";
	    		root->level_display(&flag,&choice,key);
	    		cout<<"\n\t\t";
	    	}
	        break;
	}
	}while(choice!=0);
	
	cout<<"\n";
	return 0;
}

/*				++OUTPUT++


--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>15

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>9

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>4

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>18

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>19

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>17

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>12

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>1

	>>4  9  12  15  17  18  19  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>2

	>>15  9  4  12  18  17  19  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>3

	>>4  12  9  17  19  18  15  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>4

	>>4  9  12  15  17  18  19  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>5

	>>15  9  4  12  18  17  19  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>6

	>>4  12  9  17  19  18  15  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>7

	>>15  9  18  4  12  17  19  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>6

	Display level wise 
	>>		15  
	       9  18  
	      4  12  17  19 
		
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>3

	Enter search key >> 17

	Key Present 17  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>3

	Enter search key >> 18

	Key Present 18  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>2

	Enter the key to delete >>19

	Key Present 19  
	Key Deleted Successfully
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>1

	>>4  9  12  15  17  18  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>2

	Enter the key to delete >>18

	Key Present 18  
	Key Deleted Successfully
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>1

	>>4  9  12  15  17
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>1

	Enter the data >>20

--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>1

	>>4  9  12  15  17  20
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>6

	Display level wise 
	>>		15  
	       9  17  
	      4  12  20  
		
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>2

	Enter the key to delete >>9

	Key Present 9  
	Key Deleted Successfully
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>6

	Display level wise 
	>>		15  
	       12  17  
	      4     20  
		
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>4

	>>InOrder	:20  17  15  12  4  
	>>PreOrder	:15  17  20  12  4  
	>>PostOrder	:20  17  4  12  15  
	Mirror of TREE is created :)
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>5

      ፨ RECURSIVE:
	1:InOrder
	2:PreOrder
	3:PostOrder
      ፨ Non-REC  :
	4:InOrder
	5:PreOrder
	6:PostOrder
      ፨ 7:Breadth-First >>1

	>>4  12  15  17  20  
--------------------MENU--------------------

	1:Insert
	2:Delete
	3:Search
	4:MirrorImage
	5:Display
	6:Display Level Wise
	0:EXIT  >>0

*/
