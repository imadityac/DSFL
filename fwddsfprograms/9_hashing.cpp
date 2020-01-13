#include"9_hashing.h"

int main()
{
	int choice;
	
	cout<<"\n\t\t ** Dev By Aditya Choudhari (25008) **\n";
	do
	{
	cout<<"\n********************HASHING********************\n";
	cout<<"\n\t1:chaining without replacement\n\t2:chaining with replacement";
	cout<<"\n\t0:EXIT  >>";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			noreplace();
			break;
		case 2:
			replace();
			break;
	}
	}while(choice!=0);
	
	cout<<"\n";
	return 0;
}

/*
				  ++OUTPUT++
		
********************HASHING********************

	1:chaining without replacement
	2:chaining with replacement
	0:EXIT  >>2

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>55
	Enter the mob_no >>55

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>85
	Enter the mob_no >>85

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>46
	Enter the mob_no >>46

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		-1		-1		-1
	1		-1		-1		-1
	2		-1		-1		-1
	3		-1		-1		-1
	4		-1		-1		-1
	5		55		55		7
	6		46		46		-1
	7		85		85		-1
	8		-1		-1		-1
	9		-1		-1		-1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>66
	Enter the mob_no >>66

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		-1		-1		-1
	1		-1		-1		-1
	2		-1		-1		-1
	3		-1		-1		-1
	4		-1		-1		-1
	5		55		55		7
	6		46		46		8
	7		85		85		-1
	8		66		66		-1
	9		-1		-1		-1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>77
	Enter the mob_no >>77

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		-1		-1		-1
	1		-1		-1		-1
	2		-1		-1		-1
	3		-1		-1		-1
	4		-1		-1		-1
	5		55		55		9
	6		46		46		8
	7		77		77		-1
	8		66		66		-1
	9		85		85		-1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>22
	Enter the mob_no >>22

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>63
	Enter the mob_no >>63

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>94
	Enter the mob_no >>94

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>35
	Enter the mob_no >>35

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		35		35		-1
	1		-1		-1		-1
	2		22		22		-1
	3		63		63		-1
	4		94		94		-1
	5		55		55		9
	6		46		46		8
	7		77		77		-1
	8		66		66		-1
	9		85		85		0
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>37
	Enter the mob_no >>37

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		35		35		-1
	1		37		37		-1
	2		22		22		-1
	3		63		63		-1
	4		94		94		-1
	5		55		55		9
	6		46		46		8
	7		77		77		1
	8		66		66		-1
	9		85		85		0
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	No more space to ADD New Entry
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>2

	Enter the mob_no to search >>98

	Record Not Found
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>2

	Enter the mob_no to search >>37

	NAME 	mob_no
	37	37
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>0

********************HASHING********************

	1:chaining without replacement
	2:chaining with replacement
	0:EXIT  >>1
	
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name1
	Enter the mob_no >>55

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name2
	Enter the mob_no >>63

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name3
	Enter the mob_no >>99

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name4
	Enter the mob_no >>120

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name5
	Enter the mob_no >>85

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		name4	120		-1
	1		-1		-1		-1
	2		-1		-1		-1
	3		name2	63		-1
	4		-1		-1		-1
	5		name1	55		6
	6		name5	85		-1
	7		-1		-1		-1
	8		-1		-1		-1
	9		name3	99		-1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name6
	Enter the mob_no >>19

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name7
	Enter the mob_no >>46

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		name4	120		-1
	1		name6	19		-1
	2		-1		-1		-1
	3		name2	63		-1
	4		-1		-1		-1
	5		name1	55		6
	6		name5	85		-1
	7		name7	46		-1
	8		-1		-1		-1
	9		name3	99		1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name8
	Enter the mob_no >>35

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name9
	Enter the mob_no >>26

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>1

	Enter the NAME >>name10
	Enter the mob_no >>77

--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>3

	index	NAME	Mob_no	chain
	0		name4	120		-1
	1		name6	19		-1
	2		name9	26		-1
	3		name2	63		-1
	4		name10	77		-1
	5		name1	55		6
	6		name5	85		8
	7		name7	46		2
	8		name8	35		-1
	9		name3	99		1
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>2

	Enter the mob_no to search >>98

	Record Not Found
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>2

	Enter the mob_no to search >>35

	NAME 	mob_no
	name8	35
--------------------MENU--------------------

	1:Add
	2:Search
	3:#Table
	0:EXIT >>0

********************HASHING********************

	1:chaining without replacement
	2:chaining with replacement
	0:EXIT  >>0


*/
