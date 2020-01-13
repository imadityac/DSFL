#include"4_exp_tree.h"

int main()
{
	int choice;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"\n\t\t\t** Expression tree **";
	
	do
	{
	cout<<"\n--------------------MENU--------------------\n";
	cout<<"\n\t1:PostFix\n\t2:PreFix\n\t0:EXIT : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			postfix();
			break;
		case 2:
			prefix();
			break;
	}
	}while(choice!=0);
	
	cout<<"\n";
	return 0;
}

/*

--------------------MENU--------------------

	1:PostFix
	2:PreFix
	0:EXIT  >>1

	Enter the postfix Expression : ab++

	Invalid Expression :(
	Enter the postfix Expression : +ab

	Invalid Expression
--------------------MENU--------------------

	1:PostFix
	2:PreFix
	0:EXIT  >>1

	Enter the postfix Expression : ab+cd-*

      ፨ Resursive
	InOrder:
	a  +  b  *  c  -  d  
	PreOrder:
	*  +  a  b  -  c  d  
	PostOrder:
	a  b  +  c  d  -  *  
      ፨ Non-Resursive
	InOrder:
	a  +  b  *  c  -  d  
	PreOrder:
	*  +  a  b  -  c  d  
	PostOrder:
	a  b  +  c  d  -  *  
--------------------MENU--------------------

	1:PostFix
	2:PreFix
	0:EXIT  >>2

	Enter the prefix Expression : ab+

	Invalid Expression
--------------------MENU--------------------

	1:PostFix
	2:PreFix
	0:EXIT  >>2

	Enter the prefix Expression : *-ab+cd

      ፨ Resursive
	InOrder:
	a  -  b  *  c  +  d  
	PreOrder:
	*  -  a  b  +  c  d  
	PostOrder:
	a  b  -  c  d  +  *  
      ፨ Non-Resursive
	InOrder:
	a  -  b  *  c  +  d  
	PreOrder:
	*  -  a  b  +  c  d  
	PostOrder:
	a  b  -  c  d  +  *  
--------------------MENU--------------------

	1:PostFix
	2:PreFix
	0:EXIT  >>0

*/
