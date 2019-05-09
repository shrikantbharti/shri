#include <iostream>
using namespace std;

class Heap
{

    int arr[20];

public:
    void accept(int n);
    void display(int n,int flag);
    void heapSort(int n);
    void heapify(int n,int i);
    void adjust(int n,int i);
};

void Heap:: accept(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter"<<i<<" Students marks:";
        cin>>arr[i];
    }
}
void Heap::display(int n,int flag)
{
    cout<<"\nMarks:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

    if(flag==0)
    {
        cout<<"\nMax:"<<arr[n-1];
        cout<<"\nMin:"<<arr[0];
    }
}

void Heap::heapSort(int n)
{
    int i,t;
    for(i=((n-1)/2);i>=0;i--)
    {
        adjust(n-1,i);
    }
    display(n,1);

    while(n>0)
    {
        t=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=t;
        n--;
        adjust(n,0);
    }
 }

void Heap::adjust(int n,int i)
{
    int j,temp;
    while((2*i+1)<n)
    {
        j=(2*i+1);
        if((j+1<n) && (arr[j+1]>arr[j]))
        {
            j=j+1;
        }
        if(arr[i]>arr[j])
        {
            break;
        }
        else
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        i=j;
    }
}

int main()
{
    Heap h1;
    int f;
    int n;

    cout<<"Enter Total Number Of Students:";
    cin>>n;
    do
    {
        cout<<"\nEnter Your Choice:\n";
        cout<<"\n1.Accept Data\n2.Sort Data\n3.Display Data\n4.Exit";
        cin>>f;

        switch(f)
        {
            case 1:
                    h1.accept(n);
            break;

            case 2:
                    h1.heapSort(n);
            break;

            case 3:
                    h1.display(n,0);
            break;

            default:
            break;
        }
    }
    while(f<4);
    return 0;
}

/*output
 * Enter no of students appearing for exam:5

MENU

1.Accept
2.Sort
3.Display
4.Exit

Enter your choice :
1

Enter0 Students marks:10

Enter1 Students marks:20

Enter2 Students marks:30

Enter3 Students marks:40

Enter4 Students marks:50

MENU

1.Accept
2.Sort
3.Display
4.Exit

Enter your choice :
3

The marks are as follows:
10    20    30    40    50
The maximum marks scored are:50
The minimum marks scored are:10
MENU

1.Accept
2.Sort
3.Display
4.Exit

Enter your choice :
2

The marks are as follows:
40    20    30    10    50
MENU

1.Accept
2.Sort
3.Display
4.Exit

Enter your choice :
4































-----------------------------








Enter Total Number Of Students:9

Enter Your Choice:

1.Accept Data
2.Sort Data
3.Display Data
4.Exit
1

Enter0 Students marks:5

Enter1 Students marks:25

Enter2 Students marks:10

Enter3 Students marks:15

Enter4 Students marks:75

Enter5 Students marks:20

Enter6 Students marks:30

Enter7 Students marks:45

Enter8 Students marks:35

Enter Your Choice:

1.Accept Data
2.Sort Data
3.Display Data
4.Exit
2

Marks:
75    45    30    15    25    20    10    5    35
Enter Your Choice:

1.Accept Data
2.Sort Data
3.Display Data
4.Exit
3

Marks:
5    10    15    20    25    30    35    45    75
Max:75
Min:5
Enter Your Choice:

1.Accept Data
2.Sort Data
3.Display Data
4.Exit4

 */