//============================================================================
// Name        : hashf.cpp
// Author      : Shrikant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 10

    class student
    {
        int rollno;
        string name;
        char grade;
        public:
            student();
            friend class hash;
    };

    student::student()
    {
        rollno=-1;
        name=" ";
        grade=' ';
    }

    class hash
    {
        student hashtable[max];
        public:
            hash();
            void linear_without();
            void display();
            void linear_with();
    };

    hash::hash()
{
    for(int i=0;i<max;i++)
    {
        hashtable[i].rollno=-1;
    }
}

    void hash::linear_without()
    {
        student s;
        char ch='y';
        int index,i,flag=0;
        while(ch=='y')
        {
            cout<<"\nEnter Student Details:";
            cout<<"\nRoll No:";
            cin>>s.rollno;
            cout<<"\nName:";
            cin>>s.name;
            cout<<"\nGrade:";
            cin>>s.grade;
            index=s.rollno%max;
            if(hashtable[index].rollno==-1)
            {
                hashtable[index]=s;
            }
            else
            {
                i=1;
                i=(index+1)%max;
                while(i!=index)
                {
                    if(hashtable[i].rollno==-1)
                    {
                        hashtable[i]=s;
                        flag=1;
                        break;
                    }
                    i=(i+1)%max;
                }
                if(flag==0)
                {
                    cout<<"\nHash table is full! cannot accept any more entries!"<<endl;
                    break;
                }

            }
            cout<<"\nDo you want to add more records?(y or n)";
            cin>>ch;
        }
    }

    void hash::linear_with()
    {
        student s,temp;
        char ch='y';
        int index,i,flag=0;
        while(ch=='y')
        {
        cout<<"\nEnter Student Details";
        cout<<"\nRoll No:";
        cin>>s.rollno;
        cout<<"Name:";
        cin>>s.name;
        cout<<"Grade:";
        cin>>s.grade;
        index=s.rollno%max;
        if(hashtable[index].rollno==-1)
        {
            hashtable[index]=s;
        }
        else
        {
            temp=s;
            if(hashtable[index].rollno%max!=index)
            {
                temp=hashtable[index];
                hashtable[index]=s;
            }
                i=1;
                i=(index+1)%max;
                while(i!=index)
                {
                    if(hashtable[i].rollno==-1)
                    {
                        hashtable[i]=temp;
                        flag=1;
                        break;
                    }
                    i=(i+1)%max;
                }
                if(flag==0)
                        {
                            cout<<"\nHash table is full! cannot accept any more entries!";
                            break;
                        }
            }
        cout<<"\nDo you want to add more records?(y or n)";
        cin>>ch;
        }
    }

    void hash::display()
    {
        cout<<"\nThe student records are as follows:";
        cout<<"\n\tROllNO\tNAME\tGRADE\n";
        for(int i=0;i<max;i++)
        {

cout<<i<<"\t"<<hashtable[i].rollno<<"\t"<<hashtable[i].name<<"\t"<<hashtable[i].grade<<"\n";
        }
    }

    int main() {
        hash h;
        int f;
        do
        {
            cout<<"\nMENU";
            cout<<"\n1.Linear without    2.Linear With    3.Display 4.Exit";
            cout<<"\nEnter your choice: ";
            cin>>f;
            switch(f)
            {
            case 1:
                    h.linear_without();
                    break;
            case 2:
                    h.linear_with();
                    break;
            case 3:
                    h.display();
                    break;
            default:
                    return 0;
            }
        }
        while(f<4);
        return 0;
    }
/*
 * Output:
 *
MENU
1.Linear without    2.Linear With    3.Display 4.Exit
Enter your choice: 1

Enter Student Details:
Roll No:2

Name:shri

Grade:A

Do you want to add more records?(y or n)y

Enter Student Details:
Roll No:1

Name:Aniket

Grade:A

Do you want to add more records?(y or n)y

Enter Student Details:
Roll No:4

Name:Sagar

Grade:A

Do you want to add more records?(y or n)y

Enter Student Details:
Roll No:5

Name:Varad

Grade:A

Do you want to add more records?(y or n)n

MENU
1.Linear without    2.Linear With    3.Display 4.Exit
Enter your choice: 3

The student records are as follows:
	ROllNO	NAME	GRADE
0	-1
1	1	Aniket	A
2	2	shri	A
3	-1
4	4	Sagar	A
5	5	Varad	A
6	-1
7	-1
8	-1
9	-1

MENU
1.Linear without    2.Linear With    3.Display 4.Exit
Enter your choice: 2

Enter Student Details
Roll No:2
Name:Shri
Grade:B

Do you want to add more records?(y or n)y

Enter Student Details
Roll No:1
Name:Aniket
Grade:B

Do you want to add more records?(y or n)y

Enter Student Details
Roll No:4
Name:Sagar
Grade:B

Do you want to add more records?(y or n)y

Enter Student Details
Roll No:5
Name:Varad
Grade:B

Do you want to add more records?(y or n)n

MENU
1.Linear without    2.Linear With    3.Display 4.Exit
Enter your choice: 3

The student records are as follows:
	ROllNO	NAME	GRADE
0	-1
1	1	Aniket	A
2	2	shri	A
3	2	Shri	B
4	4	Sagar	A
5	5	Varad	A
6	1	Aniket	B
7	4	Sagar	B
8	5	Varad	B
9	-1

MENU
1.Linear without    2.Linear With    3.Display 4.Exit
Enter your choice: 4
 *
 */
