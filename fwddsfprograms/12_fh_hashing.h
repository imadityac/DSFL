
#include<iostream>
#include<fstream>
#include<string.h>
#define size 11	//macro  for table sixe
#define h(x) x%size		//to find remainder(%)			
using namespace std;

struct emp
{
	int id;
	char name[20];
	float salary;
	int status;	 //if 0	record present if 1 deleted		
	int link;	//store address of next locn.	
};

class file_h
{
	char table[30];
	fstream file;
	emp rec;	//struct object
	public:
	void init(char a[20]);				
	void displayall();				
	void insert(emp rec1);
	void modify(int id);
	void delet(int id);
	int search(int id);
	
	void display(int recno)			//to display single record
	{
		int i=recno;
		file.open(table,ios::binary | ios::in );
		file.seekg(recno*sizeof(emp),ios::beg);	//go to position
		file.read((char*)&rec,sizeof(emp));

		if(rec.status==0)	//if record present		
		{
			cout<<"\n"<<i<<".\t"<<rec.id<<"\t"<<rec.name<<"\t"<<rec.salary;
			cout<<"\t"<<rec.link;
		}
	
		else	//record not present
		cout<<"\n"<<i<<"\t------------------------------";	
		file.close();
	}
	
	void read(int recno)
	{
		file.open(table,ios::binary|ios::in);
		file.seekg(recno*sizeof(emp),ios::beg);	//goto particular recno
		file.read((char*)&rec,sizeof(emp));	//  read record belongs to reco
		file.close();
	}
	
	void write(int recno)
	{
		file.open(table,ios::binary|ios::out|ios::in);
		file.seekp(recno*sizeof(emp),ios::beg);	//goto position & write
		file.write((char*)&rec,sizeof(emp));	//to write a record
		file.close();
	}
};

void file_h :: init(char a[20])				
{
	int i;
	strcpy(table,a);
	rec.status=1; //initialization
	rec.link=-1;
	file.open(table,ios::binary | ios::out);
	file.close();
	for(i=0;i<size;i++)	//index
		write(i);
	
}

void file_h :: insert(emp rec1)		
{
	int n,i,j,start,k;
	rec1.status=0;						
	rec1.link=-1;
	start=h(rec1.id);	//store remainder 					
	
	for(i=0;i<size;i++)	//go to required indexno(starting of chain)
	{
		j=(start+i)%size;	//calculate position(if 12%11 goto 1)
		read(j);
		if(rec.status==0 && h(rec.id)==start)	//if chain found
		  break;
	}
	if(i<11)
	{
		while(rec.link!=-1)	//if chain is present goto 	end of cain
		{
			j=rec.link;
			read(j);
		}
		
		for(i=0;i<size;i++) //find empty locn.
		{
			k=(start+i)%size;	//calculate index
			read(k);
			if(rec.status==1)	//empty locn
			{
				rec=rec1;
				write(k);
				read(j);
				rec.link=k;
				write(j);
				return;
			}
		}	
	cout<<"\nTable is full:  ";
	}
	
	else	//if 1st element
	{
		for(i=0;i<size;i++)		//find empty locn.		
		{
			k=(start+i)%size;
			read(k);
			if(rec.status==1)
			{
				rec=rec1;
				write(k);				
				return;
			}
		}cout<<"\nTable Is Full... ";

	}
}


void file_h :: displayall()
{
	int i=0,n;
	cout<<"\n\t----Data File----";
	cout<<"\nIndex\tId\tName\tSalary\tLink";
	for(i=0;i<size;i++)
		display(i);
}

void file_h :: delet(int id)
{
	emp rec1;
	int recno;
	int i,j,start,k;
	start=h(id);	//store position				
	
	for(i=0;i<size;i++)	//locate start of chain
	{
		j=(start+i)%size;
		read(j);
		if(rec.status==0 && h(rec.id)==start)  //record found
			break;
	}

	if(i<11)	//chain exists					
	{	
		if(rec.id==id && rec.link==-1)	//record found			
		{
			rec.status=1;
			write(j);	
			cout<<"\nEntry deleted...";		
		}
		else
		{
			while(rec.id != id && rec.link!=-1)//chain
			{
				k=j;
				j=rec.link;
				read(j);			
			}
		
			if(rec.id==id)
			{
				rec.status=1;
				write(j);
				int nextlink=rec.link;	//to change link
				read(k);
				
				rec.link=nextlink;
				write(k);
				cout<<"\nEntry deleted...";	
			}
		
			else
			cout<<"\nElement Not Found... ";
		}
	}
	else
	cout<<"\nRecord Not Found,..  ";	
}	

void file_h :: modify(int id)
{
	emp rec1;
	int recno;
	int i,j,start,k;
	start=h(id);	//store position				
	
	for(i=0;i<size;i++)	//locate start of chain
	{
		j=(start+i)%size;
		read(j);
		if(rec.status==0 && h(rec.id)==start)  //record found
			break;
	}

	if(i<11)	//chain exists					
	{	
		if(rec.id==id)	//record found			
		{
			cout<<"\nEnter new name ,salary\n";
			cin>>rec.name>>rec.salary;
			write(j);	
			cout<<"\nEntry modified...";	
		}
		else
		{
			while(rec.id != id && rec.link!=-1)//chain
			{
				k=j;
				j=rec.link;
				read(j);			
			}
		
			if(rec.id==id)
			{
				cout<<"\nEnter new name ,salary\n";
				cin>>rec.name>>rec.salary;
				write(j);
				cout<<"\nEntry modified...";	
			}
		
			else
			cout<<"\nElement Not Found.. ";
		}
	}
	else
	cout<<"\nRecord Not Found..  ";	
}	

int file_h :: search(int id)
{
	int start,i,j;
	start=h(id);
	for(i=0;i<size;i++)
	{
		j=(start+i)%size;
		read(j);
	
		if(rec.status==0 && h(rec.id)==start)	//record found
		break;
	}

	if(i<11)	//chain exists
	{
		while(rec.id!=id && rec.link!=-1)//chaining
		{
			j=rec.link;
			read(j);
		}
		if(rec.id==id)
		return(j);

		else
		return(-1);

	}
	else
	return -1;//record not found
}
