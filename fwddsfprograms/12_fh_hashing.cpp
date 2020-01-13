#include"12_fh_hashing.h"

int main()
{
	char name[20];
	file_h object;
	int id,ch,recno;
	emp rec1;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"Enter File name: ";
	cin>>name;
	object.init(name);					

	do
	{
		cout<<"\n\n1.Insert \n2.Display \n3.Delete \n4.Search \n5.Modify \n6.Exit";
		cout<<"\nEnter Your Choice:  ";
		cin>>ch;
	
		switch(ch)
		{
			case 1:		
			cout<<"\nEnter Record (Employee id, Name, salary)\n"; 	
			cin>>rec1.id>>rec1.name>>rec1.salary;
			object.insert(rec1);
			break;
		
			case 2:
			object.displayall();
			break;

			case 3:
			cout<<"\nEnter employee id To Delete:  ";
			cin>>id;
			object.delet(id);
			break;
		
			case 4:
			cout<<"\nEnter employee id To Search:  ";	
			cin>>id;
			recno=object.search(id);
			if(recno>=0)
			{
				cout<<"\nRecord No. :\t"<<recno;
				cout<<"\nIndex \tId \tName \tsalary \tLink";
				object.display(recno);
			}
			else
			cout<<"\nRecord Not Found:  ";	
			break;
			
			case 5:
			cout<<"\nEnter employee id To Modify:  ";
			cin>>id;
			object.modify(id);
			break;
		}	
	}while(ch<6);
}

/*				
				**OUTPUT**

	Enter File name: file1

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  1

	Enter Record (Employee id, Name, salary)
	9 aaa 5000


	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  1

	Enter Record (Employee id, Name, salary)
	20 bbb 3000


	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  1

	Enter Record (Employee id, Name, salary)
	31 ccc 8000


	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  2

		    ----Data File----
	Index   Id      Name    Salary  Link
	0.      31      ccc     8000    -1
	1       ------------------------------
	2       ------------------------------
	3       ------------------------------
	4       ------------------------------
	5       ------------------------------
	6       ------------------------------
	7       ------------------------------
	8       ------------------------------
	9.      9       aaa     5000    10
	10.     20      bbb     3000    0

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  4

	Enter employee id To Search:  20

	Record No. :    10
	Index   Id      Name    salary  Link
	10.     20      bbb     3000    0

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  3

	Enter employee id To Delete:  20

	Entry deleted...

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  2

		    ----Data File----
	Index   Id      Name    Salary  Link
	0.      31      ccc     8000    -1
	1       ------------------------------
	2       ------------------------------
	3       ------------------------------
	4       ------------------------------
	5       ------------------------------
	6       ------------------------------
	7       ------------------------------
	8       ------------------------------
	9.      9       aaa     5000    0
	10      ------------------------------

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  3

	Enter employee id To Delete:  25

	Record Not Found,..

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  5

	Enter employee id To Modify:  9

	Enter new name ,salary
	zzz 5555

	Entry modified...

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice:  2

		    ----Data File----
	Index   Id      Name    Salary  Link
	0.      31      ccc     8000    -1
	1       ------------------------------
	2       ------------------------------
	3       ------------------------------
	4       ------------------------------
	5       ------------------------------
	6       ------------------------------
	7       ------------------------------
	8       ------------------------------
	9.      9       zzz     5555    0
	10      ------------------------------

	1.Insert
	2.Display
	3.Delete
	4.Search
	5.Modify
	6.Exit
	Enter Your Choice: 6 
*/



