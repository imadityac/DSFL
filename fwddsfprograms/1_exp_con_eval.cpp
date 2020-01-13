#include"1_exp_con_eval.h"

int main()
{
	int choice;
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"\n\t\t** Expression Convertion & Evaluation **";
	
	do
	{
	cout<<"\n--------------------MENU--------------------\n";
	cout<<"\n\t1:InFix-PostFix \n\t2:Infix-PreFix \n\t3:Postfix_Evaluation \n\t4:PreFix_Evaluation \n\t  0:EXIT :";
	cin>>choice;
	
	switch(choice)
	{
	case 1:
		in_post();
		break;
	case 2:
		in_pre();
		break;
	case 3:
		epost();
		break;
	case 4:
		epre();
		break;
	}
	}while(choice!=0);

	cout<<"\n";
	return 0;
}

/*                ++OUTPUT++

--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>1

	Enter the Infix-Expression : (a+b)*(c

	Incorrect Expression. Try Again :(

	Enter the Infix-Expression : a+b+

	Incorrect Expression. Try Again :(

	Enter the Infix-Expression : a+b*c

	Postfix-Expression : abc*+

--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>2

	Enter the Infix-Expression : +a+b

	Incorrect Expression. Try Again :(

	Enter the Infix-Expression : a+b*c-d

	prefix-Expression : -+a*bcd
--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>3

	Enter the PostFix-Expression : +ab

	Incorrect Expression
--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>3

	Enter the PostFix-Expression : ab+cd-*

	Enter the value of 'a' = 2

	Enter the value of 'b' = 3

	Enter the value of 'c' = 4

	Enter the value of 'd' = 5

	Result = -5
--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>4

	Enter the preFix-Expression : ab+

	Incorrect Expression
--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>4

	Enter the preFix-Expression : +-ab*43

	Enter the value of 'b' = 3

	Enter the value of 'a' = 4

	Result = 13
--------------------MENU--------------------

	1:InFix-PostFix 
	2:Infix-PreFix 
	3:Postfix_Evaluation 
	4:PreFix_Evaluation 
	  0:EXIT  >>0

*/
