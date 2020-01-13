
#include<iostream>
#include<fstream>
using namespace std;

class student
{    
 	int roll;
 	char name[20];
 	char address[50];
 	char division;
 	public:
 	void getdata()
 	{
 		cout<<"\n\tRoll No.>>";
 		cin>>roll;
 		cout<<"\tEnter Name >>";
 		cin>>name;
 		cout<<"\tEnter Address >>";
 		cin>>address;
 		cout<<"\tEnter Division >>";
 		cin>>division;
 	}
 	void putdata()
 	{
 		cout<<"\n\t"<<roll<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<division;
 	}
 	int rollno()
 	{
 	    return roll;
 	}
};

class ALGO
{
	public:
	void add(int i)  //add function
	{
	    fstream fp("Student.txt",ios::out|ios::app);

		student s;
		s.getdata();
		fp.write((char *) &s,sizeof(s));
		fp.close();
	}
	void display()      		  //display function
	{
		fstream fp("Student.txt",ios::in);
		student s;
		fp.read((char *)&s,sizeof(s));
		while(!fp.eof())
		{
			s.putdata();
			fp.read((char *)&s,sizeof(s));
		}
		fp.close();
	}
	void delet(int rollno)    //delete function
	{
		fstream fp1("Student.txt",ios::in);
		fstream temp("Temp.txt",ios::out | ios::app);
		student s;
		int flag=0;
		fp1.read((char *)&s,sizeof(s));
		while(!fp1.eof())
		{
			if(rollno==s.rollno())
			{
			    cout<<"\n\tRoll_No\t\tName\t\tAddress\t\tDivision";
			    s.putdata();
				cout<<"\n\tThe Record is Deleted!\n";
				flag=1;
			}
			else
			{
				temp.write((char *)&s,sizeof(s));
			}
			fp1.read((char *)&s,sizeof(s));
		}
		if(flag==0)
			cout<<"\n\tRecord Not Found!";
		fp1.close();
		temp.close();
		remove("Student.txt");
		rename("Temp.txt","Student.txt");
	}
	void modify(int rollno)  //modify function
	{
		fstream fp1("Student.txt",ios::in);
		fstream temp("Temp.txt",ios::out | ios::app);
		student s;
		int flag=0;
		fp1.read((char *)&s,sizeof(s));
		while(!fp1.eof())
		{
			if(rollno==s.rollno())
			{
			    cout<<"\n\tRoll_No\t\tName\t\tAddress\t\tDivision";
			    s.putdata();
				cout<<"\n\tEnter the New data:";
				s.getdata();
				flag=1;
			}
			temp.write((char *)&s,sizeof(s));
			fp1.read((char *)&s,sizeof(s));
		}
		if(flag==0)
			cout<<"\n\tRecord Not Found!";
		fp1.close();
		temp.close();
		remove("Student.txt");
		rename("Temp.txt","Student.txt");
	}
};
