#include"7_kruskal.h"

int main()
{
    int *a,n,flag,choice;
    
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
    cout<<"\n\t\t**Minimum Spanning Tree using Kruskal's alorithm**\n";
    cout<<"\n\tEnter the No.of Vertices : ";
    cin>>n;
    a=new int[n*n];
    accept(a,n);
    
    do
    {
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1:Display Adjacency matrix\n\t2:Min. Spanning Tree\n\t0:Exit : ";
		cin>>choice;
		
		switch(choice)
		{
		    case 1:
		        display(a,n);
		        break;
		    case 2:
		        spantree(a,n);
		        break;
		}
    }while(choice!=0);
    
    cout<<"\n";
    return 0;    
}

/*
					**OUTPUT**

		**Minimum Spanning Tree using Kruskal's alorithm**

	Enter the No.of Vertices : 4

	Weight of edge [0][1]>>3

	Weight of edge [0][2]>>4

	Weight of edge [0][3]>>2

	Weight of edge [1][2]>>1

	Weight of edge [1][3]>>4

	Weight of edge [2][3]>>0

--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 1

	0]	0	3	4	2
	1]	3	0	1	4
	2]	4	1	0	0
	3]	2	4	0	0
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 2

	Start pt.   End pt.   Weight
	1		2	1
	0		3	2
	0		1	3

	Weight of Min-Spanning Tree is : 6
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 0

administrator@IT-PL1-PC02:~$ g++ dsf7.cpp
administrator@IT-PL1-PC02:~$ ./a.out

		**Minimum Spanning Tree using Kruskal's alorithm**

	Enter the No.of Vertices : 8

	Weight of edge [0][1]>>2

	Weight of edge [0][2]>>0

	Weight of edge [0][3]>>3 

	Weight of edge [0][4]>>0

	Weight of edge [0][5]>>1

	Weight of edge [0][6]>>0

	Weight of edge [0][7]>>0

	Weight of edge [1][2]>>2

	Weight of edge [1][3]>>2

	Weight of edge [1][4]>>4

	Weight of edge [1][5]>>0

	Weight of edge [1][6]>>0

	Weight of edge [1][7]>>0

	Weight of edge [2][3]>>0

	Weight of edge [2][4]>>5

	Weight of edge [2][5]>>0

	Weight of edge [2][6]>>0

	Weight of edge [2][7]>>1

	Weight of edge [3][4]>>4

	Weight of edge [3][5]>>3

	Weight of edge [3][6]>>0

	Weight of edge [3][7]>>0

	Weight of edge [4][5]>>3

	Weight of edge [4][6]>>7

	Weight of edge [4][7]>>6

	Weight of edge [5][6]>>5

	Weight of edge [5][7]>>0

	Weight of edge [6][7]>>0

--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 1

	0]	0	2	0	3	0	1	0	0
	1]	2	0	2	2	4	0	0	0
	2]	0	2	0	0	5	0	0	1
	3]	3	2	0	0	4	3	0	0
	4]	0	4	5	4	0	3	7	6
	5]	1	0	0	3	3	0	5	0
	6]	0	0	0	0	7	5	0	0
	7]	0	0	1	0	6	0	0	0
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 2

	Start pt.   End pt.   Weight
	0		5	1
	2		7	1
	0		1	2
	1		2	2
	1		3	2
	4		5	3
	5		6	5

	Weight of Min-Spanning Tree is : 16
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Min. Spanning Tree
	0:Exit : 0

*/

