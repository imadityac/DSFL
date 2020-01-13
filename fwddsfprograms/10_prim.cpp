#include"10_prim.h"

int main()
{
    int *a,n,flag,choice,i;
    
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
    cout<<"\n\t\t**Prim's alorithm**\n";
    cout<<"\n\tEnter the No.of Cities : ";
    cin>>n;
    a=new int[n*n];
    struct city c[n];
        
    for(i=0;i<n;i++)
    {
    	cout<<"\n\tEnter the name of "<<i<<"th city : ";
    	cin>>c[i].name;
    }
    accept(a,c,n);
    
    do
    {
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1:Display Adjacency matrix\n\t2:Min. Spanning Tree\n\t0:Exit : ";
		cin>>choice;
		
		switch(choice)
		{
		    case 1:
		        display(a,c,n);
		        break;
		    case 2:
		        spantree(a,c,n);
		        break;
		}
    }while(choice!=0);
    
    cout<<"\n";
    return 0;
}

/*
				**OUTPUT**
		
			**Prim's alorithm**

	Enter the No.of Cities : 5

	Enter the name of 0th city : Pune

	Enter the name of 1th city : Mum 

	Enter the name of 2th city : Chen

	Enter the name of 3th city : Delhi

	Enter the name of 4th city : Nagpur

	Rent between cities [Pune][Mum] : ₹ 10

	Rent between cities [Pune][Chen] : ₹ 50

	Rent between cities [Pune][Delhi] : ₹ 60

	Rent between cities [Pune][Nagpur] : ₹ 30

	Rent between cities [Mum][Chen] : ₹ 90

	Rent between cities [Mum][Delhi] : ₹ 40

	Rent between cities [Mum][Nagpur] : ₹ 40

	Rent between cities [Chen][Delhi] : ₹ 100

	Rent between cities [Chen][Nagpur] : ₹ 70

	Rent between cities [Delhi][Nagpur] : ₹ 50

--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 1

	Pune]	0	10	50	60	30
	Mum]	10	0	90	40	40
	Chen]	50	90	0	100	70
	Delhi]	60	40	100	0	50
	Nagpur]	30	40	70	50	0
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 2

	Start Pt.	End Pt.		Weight
	Pune		Mum			10
	Pune		Nagpur		30
	Mum			Delhi		40
	Pune		Chen		50
	
	Minimum total cost betweeen all cities is : ₹ 130
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 0
*/

