#include"2_prio_q.h"

int main()
{
	int choice,prio,n[3]={0,0,0};
	QUE *front[3]={NULL,NULL,NULL},*rear[3],*ptr;

	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	cout<<"\n\t\t\t** Prority Queue **";
	
	do
	{
	cout<<"\n--------------------MENU--------------------\n";
	cout<<"\n\t1:Add_Patient\n\t2:Display_Patients\n\t3:Service\n\t  0:EXIT : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			while(1)
			{
				cout<<"\n\tEnter Priority (0-High|1-Medium|2-Low) : ";
				cin>>prio;
				if(prio>=0&&prio<3)
					break;
			}
			if(n[prio]<MAX)
			{
				n[prio]++;
				ptr=new QUE;
				ptr->insert(front);
				
				if(front[prio]==NULL)
					front[prio]=ptr;
				else
					rear[prio]->setnext(ptr);	
				
				rear[prio]=ptr;
			}
			else 
				cout<<"\n\tPatient Limit Exceeded";
				
			break;
		case 2:
			cout<<"\n\tID_\tNAME_\t\tDisease_";
			for(prio=0;prio<3;prio++)
			{
				if(prio==0)
					cout<<"\n\n\tHighPriority:";
				else if(prio==1)
					cout<<"\n\n\tMediumPriority:";			
				else
					cout<<"\n\n\tLowPriority:";
				
			ptr=front[prio];
			if(front[prio]==NULL)
				cout<<"\n\tNo patients";
			while(ptr!=NULL)
				ptr=ptr->display(1);
				
			}
			break;
		case 3:
			cout<<"\n\tID_\tNAME_\t\tDisease_";
			
			if(front[0]==NULL && front[1]==NULL && front[2]==NULL)
				cout<<"\n\tNo patients";
			else
				for(prio=0;prio<3;prio++)
				{
					if(front[prio]!=NULL)
					{
						ptr=front[prio];
						front[prio]=front[prio]->display(1);
						delete ptr;
						n[prio]--;
						break;
					}
				}
			break;
	}
	}while(choice!=0);

	cout<<"\n";
	return 0;
}

/*              ++OUTPUT++

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>1

	Enter Priority (0-High|1-Medium|2-Low) >> 0

	Enter the id >> 101
	Enter NAME >> ritesh
	Enter Disease >> cancer

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>1

	Enter Priority (0-High|1-Medium|2-Low) >> 0

	Enter the id >> 101

	Entered ID already assigned :(
	Enter the id >> 102
	Enter NAME >> virat
	Enter Disease >> diabetes

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>1

	Enter Priority (0-High|1-Medium|2-Low) >> 1

	Enter the id >> 102

	Entered ID already assigned :(
	Enter the id >> 103
	Enter NAME >> slaman
	Enter Disease >> accident

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>1

	Enter Priority (0-High|1-Medium|2-Low) >> 2

	Enter the id >> 102

	Entered ID already assigned :(
	Enter the id >> 104
	Enter NAME >> gaurav
	Enter Disease >> cough

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>2

	ID_	NAME_		Disease_

	HighPriority:
	101	ritesh		cancer
	102	virat		diabetes

	MediumPriority:
	103	slaman		accident

	LowPriority:
	104	gaurav		cough
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	101	ritesh		cancer
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	102	virat		diabetes
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>1

	Enter Priority (0-High|1-Medium|2-Low) >> 0

	Enter the id >> 106
	Enter NAME >> swappnil
	Enter Disease >> high_fever

--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>2

	ID_	NAME_		Disease_

	HighPriority:
	106	swappnil		high_fever

	MediumPriority:
	103	slaman		accident

	LowPriority:
	104	gaurav		cough
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	106	swappnil		high_fever
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>2

	ID_	NAME_		Disease_

	HighPriority:
	No patients

	MediumPriority:
	103	slaman		accident

	LowPriority:
	104	gaurav		cough
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	103	slaman		accident
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	104	gaurav		cough
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>3

	ID_	NAME_		Disease_
	No patients
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>2

	ID_	NAME_		Disease_

	HighPriority:
	No patients

	MediumPriority:
	No patients

	LowPriority:
	No patients
--------------------MENU--------------------

	1:Add_Patient
	2:Display_Patients
	3:Service
	  0:EXIT  >>0

*/
