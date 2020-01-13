#include"11_fh.h"

int main()
{
	ALGO a;
	int i,n,rollno,choice;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"\n\t\t\t**File Handling**\n";
	cout<<"\n\tEnter the number of records (n) >>";
	cin>>n;

    for(i=0;i<n;i++)
        a.add(i);

	do
	{
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1.Add\n\t2.Display\n\t3.Delete\n\t4.Modify\n\t0.Exit  >>";
		cin>>choice;
		switch(choice)
		{
		
			case 1:	a.add(1);
					break;
			case 2:	cout<<"\n\tRoll_No\t\tName\t\tAddress\t\tDivision";
					a.display();
					break;
			case 3:	cout<<"\n\tEnter the roll_no to delete >>";
					cin>>rollno;
					a.delet(rollno);
					break;
			case 4:	cout<<"\n\tEnter the roll_no to modify >>";
					cin>>rollno;
					a.modify(rollno);
					break;

		}
	}while(choice!=0);
	cout<<"\nTHANK YOU\n";
	return 0;
}

/*
                 ++OUTPUT++
            
			**File Handling**

	Enter the number of records (n) >>3

	Roll No.>>7
	Enter Name >>aditya
	Enter Address >>nalstop
	Enter Division >>a

	Roll No.>>22
	Enter Name >>aakash
	Enter Address >>warje
	Enter Division >>a

	Roll No.>>27
	Enter Name >>sahil
	Enter Address >>bharti
	Enter Division >>a

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>2

	Roll_No		Name		Address		Division
	7		aditya		nalstop		a
	22		aakash		warje		a
	27		sahil		bharti		a
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>1

	Roll No.>>38
	Enter Name >>gaurav
	Enter Address >>wadgaon
	Enter Division >>a

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>2

	Roll_No		Name		Address		Division
	7		aditya		nalstop		a
	22		aakash		warje		a
	27		sahil		bharti		a
	38		gaurav		wadgaon		a
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>3

	Enter the roll_no to delete >>28

	Record Not Found!
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>3

	Enter the roll_no to delete >>27

	Roll_No		Name		Address		Division
	27		sahil		bharti		a
	The Record is Deleted!

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>2

	Roll_No		Name		Address		Division
	7		aditya		nalstop		a
	22		aakash		warje		a
	38		gaurav		wadgaon		a
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>4

	Enter the roll_no to modify >>22

	Roll_No		Name		Address		Division
	22		aakash		warje		a
	Enter the New data:
	Roll No.>>23
	Enter Name >>aakash
	Enter Address >>kothrud
	Enter Division >>A

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>2

	Roll_No		Name		Address		Division
	7		aditya		nalstop		a
	23		aakash		kothrud		A
	38		gaurav		wadgaon		a
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>1

	Roll No.>>27
	Enter Name >>ashil
	Enter Address >>model
	Enter Division >>A

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>2

	Roll_No		Name		Address		Division
	7		aditya		nalstop		a
	23		aakash		kothrud		A
	38		gaurav		wadgaon		a
	27		ashil		model		A
--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>4

	Enter the roll_no to modify >>27

	Roll_No		Name		Address		Division
	27		ashil		model		A
	Enter the New data:
	Roll No.>>27
	Enter Name >>shantanu
	Enter Address >>
        		model
	Enter Division >>A

--------------------MENU--------------------
	1.Add
	2.Display
	3.Delete
	4.Modify
	0.Exit  >>0

THANK YOU


*/
