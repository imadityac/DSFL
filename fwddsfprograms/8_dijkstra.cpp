#include"8_dijkstra.h"

int main()
{
    int *a,n,flag,choice;
    
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
    cout<<"\n\t\t**Shortest path using Dijkstra's alorithm**\n";
    cout<<"\n\tEnter the No.of Vertices : ";
    cin>>n;
    a=new int[n*n];
    accept(a,n);
    
    do
    {
		cout<<"\n--------------------MENU--------------------";
		cout<<"\n\t1:Display Adjacency matrix\n\t2:Display Shortest paths\n\t0:Exit : ";
		cin>>choice;
		
		switch(choice)
		{
		    case 1:
		        display(a,n);
		        break;
		    case 2:
		    dijkstra(a,n);
		        break;
		}
    }while(choice!=0);
    
    cout<<"\n";
    return 0;    
}

/*
						**OUTPUT**
	
			**Shortest path using Dijkstra's alorithm**

	Enter the No.of Vertices : 5

	Weight of edge [0][1]>>10

	Weight of edge [0][2]>>0

	Weight of edge [0][3]>>30

	Weight of edge [0][4]>>100

	Weight of edge [1][2]>>50

	Weight of edge [1][3]>>0

	Weight of edge [1][4]>>0

	Weight of edge [2][3]>>20

	Weight of edge [2][4]>>10

	Weight of edge [3][4]>>60

--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Display Shortest paths
	0:Exit : 1

	0]	0	10	0	30	100
	1]	10	0	50	0	0
	2]	0	50	0	20	10
	3]	30	0	20	0	60
	4]	100	0	10	60	0
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Display Shortest paths
	0:Exit : 2

	Enter the STARTING VERTEX of Graph : 0


	Distance of node 1 from node 0 is : 10
	Its path is : 1<-0

	Distance of node 2 from node 0 is : 50
	Its path is : 2<-3<-0

	Distance of node 3 from node 0 is : 30
	Its path is : 3<-0

	Distance of node 4 from node 0 is : 60
	Its path is : 4<-2<-3<-0
--------------------MENU--------------------
	1:Display Adjacency matrix
	2:Display Shortest paths
	0:Exit : 0

*/
