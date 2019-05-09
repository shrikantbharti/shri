#include<iostream>
#define max 100
using namespace std;
class Graph
{
	int a[10][10],v,i,j;
public:
	Graph()
{
		cout<<"\nEnter number of vertices:";
		cin>>v;
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				a[i][j]=999;
			}
		}
}
	void accept();
	void display();
	void prims();
};

void Graph::accept()
{
	int ch;
	cout<<"\nEnter the weight of edges:";
	for(i=0;i<v;i++)
	{
		for(j=i;j<v;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
			}
			else
			{
				cout<<"\nIs there any edge between "<<i<<" to "<<j<<" (Y=1 or N=0)?";
				cin>>ch;
				if(ch==1)
				{
				cout<<"\nFor edge"<<i<<"-"<<j<<":";
				cin>>a[i][j];
				a[j][i]=a[i][j];
				}
			}
		}
	}

}

void Graph::display()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}

}

void Graph::prims()
{
	int stv,i,nearest[max],min,k,j,r,mincost,t[max][max];
	cout<<"\nEnter the starting vertex:";
	cin>>stv;
	nearest[stv]=-1;
	for(i=0;i<v;i++)
	{
		if(i!=stv)
		{
			nearest[i]=stv;
		}
	}
	r=0;
	for(i=1;i<v;i++)
	{
		min=999;
		for(k=0;k<v;k++)
		{
			if(nearest[k]!=-1 && (a[k][nearest[k]])<min)
			{
				j=k;
				min=a[k][nearest[k]];
			}
		}
		t[r][1]=j;
		t[r][2]=nearest[j];
		r=r+1;
		mincost=mincost+a[j][nearest[j]];
		nearest[j]=-1;
		for(k=0;k<v;k++)
		{
			if(nearest[k]!=-1 && (a[k][nearest[k]])>a[k][j])
			{
				nearest[k]=j;
			}
		}

	}

	cout<<"\nMinimum cost:"<<mincost;
}
int main()
{
	Graph g;
	g.accept();
	g.display();
	g.prims();
	return 0;
}
/*OUTPUT
 *
Enter number of vertices:6

Enter the weight of edges:
Is there any edge between 0 to 1 (Y=1 or N=0)?1

For edge0-1:10

Is there any edge between 0 to 2 (Y=1 or N=0)?0

Is there any edge between 0 to 3 (Y=1 or N=0)?1

For edge0-3:30

Is there any edge between 0 to 4 (Y=1 or N=0)?1

For edge0-4:45

Is there any edge between 0 to 5 (Y=1 or N=0)?0

Is there any edge between 1 to 2 (Y=1 or N=0)?1

For edge1-2:50

Is there any edge between 1 to 3 (Y=1 or N=0)?0

Is there any edge between 1 to 4 (Y=1 or N=0)?1

For edge1-4:40

Is there any edge between 1 to 5 (Y=1 or N=0)?1

For edge1-5:25

Is there any edge between 2 to 3 (Y=1 or N=0)?0

Is there any edge between 2 to 4 (Y=1 or N=0)?1

For edge2-4:35

Is there any edge between 2 to 5 (Y=1 or N=0)?1

For edge2-5:15

Is there any edge between 3 to 4 (Y=1 or N=0)?0

Is there any edge between 3 to 5 (Y=1 or N=0)?1

For edge3-5:20

Is there any edge between 4 to 5 (Y=1 or N=0)?1

For edge4-5:55
0	10	999	30	45	999
10	0	50	999	40	25
999	50	0	999	35	15
30	999	999	0	999	20
45	40	35	999	0	55
999	25	15	20	55	0

Enter the starting vertex:0

Minimum cost:105
 */
