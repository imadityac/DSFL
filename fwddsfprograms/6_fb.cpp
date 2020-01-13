#include"6_fb.h"

int main()
{
    FB *user[MAX];
    int n=0,choice;
    
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
    cout<<"\n\t\t\u1368 FACEBOOK \u1368\n";
    do
    {
    cout<<"\n--------------------MENU--------------------";
    cout<<"\n\t1:Add New User\n\t2:MaxFriends\n\t3:Max & Min Comments\n\t4:Birthday's in current Month\n\t5:Display_Users\n\t  0:EXIT >>";
    cin>>choice;
    
    if(n==0)
    	choice=1;
    
    switch(choice)
    {
    	case 1:
    		adduser(user,&n);
    		break;
    	case 2:
    		MaxFriends(user,&n);
    		break;
    	case 3:
    		CommentCount(user,&n);
    		break;
    	case 4:
    		Birthdays(user,&n);
    		break;
    	case 5:
    		cout<<"\n\t1:byTime\n\t2:DFT\n\t3:BFT >>";
    		cin>>choice;
    		
    		cout<<"\n\tNAME\t\tDOB\t\tcomments";
    		switch(choice)
    		{
    			case 1:
    				for(choice=0 ; choice<n ; choice++)
    					user[choice]->display(1);
					break;
    			case 2:
    				DFT(user,&n);
					break;
    			case 3:
    				BFT(user,&n);
					break;
    		}
    		break;
    }
    }while(choice!=0);
    
    cout<<"\n";
    return 0;
}

/*
		 ++OUTPUT++

		፨ FACEBOOK ፨

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>1

	Enter the name >> sahil 
	Enter the DOB(date month year) >> 31 4 2013

	INVALID
	Enter the DOB(date month year) >> 19 12 1998
	Enter the No.of comments >> 07

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>1

	Enter the name >> aakash
	Enter the DOB(date month year) >> 31 -4 2013

	INVALID
	Enter the DOB(date month year) >> 30 4 2015
	
	INVALID
	Enter the DOB(date month year) >> 3 4 1998
	Enter the No.of comments >> 19

	"sahil"  <-->  "aakash"
	1:Friend's	0:Ignore >> 1

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>1

	Enter the name >> aditya
	Enter the DOB(date month year) >> 2 3 1998
	Enter the No.of comments >> 20

	"sahil"  <-->  "aditya"
	1:Friend's	0:Ignore >> 1

	"aakash"  <-->  "aditya"
	1:Friend's	0:Ignore >> 1

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>1

	Enter the name >> pooja
	Enter the DOB(date month year) >> 12 3 1798
	
	INVALID
	Enter the DOB(date month year) >> 30 4 2015
	Enter the No.of comments >> 12

	"sahil"  <-->  "pooja"
	1:Friend's	0:Ignore >> 0

	"aakash"  <-->  "pooja"
	1:Friend's	0:Ignore >> 0

	"aditya"  <-->  "pooja"
	1:Friend's	0:Ignore >> 1

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>1

	Enter the name >> gaurav
	Enter the DOB(date month year) >> 16 7 1998
	Enter the No.of comments >> 234

	"sahil"  <-->  "gaurav"
	1:Friend's	0:Ignore >> 1

	"aakash"  <-->  "gaurav"
	1:Friend's	0:Ignore >> 0

	"aditya"  <-->  "gaurav"
	1:Friend's	0:Ignore >> 0

	"pooja"  <-->  "gaurav"
	1:Friend's	0:Ignore >> 1

--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>2

	"sahil" has max-friends (3)
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>3

	Max Comments:
	"gaurav" - 234
	Min Comments:
	"sahil" - 7
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>4

	Find birthdays in month-12

	
	sahil		19/12/1998		7
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>4

	Find birthdays in month-3

	
	aditya		2/3/1998		20
	
	pooja		12/3/1998		12
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>5

	1:byTime
	2:DFT
	3:BFT >>1

	NAME		DOB		comments
	sahil		19/12/1998		7
	aakash		3/4/1998		19
	aditya		2/3/1998		20
	pooja		12/3/1998		12
	gaurav		16/7/1998		234
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>5

	1:byTime
	2:DFT
	3:BFT >>2

	NAME		DOB		comments
	sahil		19/12/1998		7
	gaurav		16/7/1998		234
	pooja		12/3/1998		12
	aditya		2/3/1998		20
	aakash		3/4/1998		19
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>5

	1:byTime
	2:DFT
	3:BFT >>3

	NAME		DOB		comments
	sahil		19/12/1998		7
	aakash		3/4/1998		19
	aditya		2/3/1998		20
	gaurav		16/7/1998		234
	pooja		12/3/1998		12
--------------------MENU--------------------
	1:Add New User
	2:MaxFriends
	3:Max & Min Comments
	4:Birthday's in current Month
	5:Display_Users
	  0:EXIT >>0


*/
