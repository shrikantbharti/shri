
#include<iostream>
using namespace std;


class graph
{
    int vcount;
    int ecount;
    int cost[20][20];
    public:
    graph()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                cost[i][j]=9999;
            }
        }
    }
    void create_adjmat();
    void display_adjmat();
    void prims();
};




void graph::create_adjmat()
{
    int i=0,a,b;
    cout<<"\nEnter No of vertices : ";
    cin>>vcount;
    cout<<"\nEnter No of edges : ";
    cin>>ecount;
   
    while(i<ecount)
    {
        cout<<"\nEnter src index : ";
        cin>>a;
        cout<<"\nEnter destination index : ";
        cin>>b;
        cout<<"\nEnter cost : ";
        cin>>cost[a][b];
        cost[b][a]=cost[a][b];
        i++;
    }

    
}




void graph::display_adjmat()
{
    int i,j;
    cout<<"\nAdjacency Matrix : \n";
    for(i=0;i<vcount;i++)
    {
        for(j=0;j<vcount;j++)
        {
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }
}





void graph::prims()
{
    int a,b,i,j,k,r,min,t[ecount][2],flag=0;
    int mincost=0;
    int nearest[vcount];


    cout<<"\nEnter the starting vertex : ";
    cin>>a;
    nearest[a]=-1;


    for(i=0;i<vcount;i++)
    {
        if(i!=a)
        {
            nearest[i]=a;
        }
    }
    r=0;


    for(i=0;i<vcount;i++)
    {
        min=9999;

        for(k=0;k<vcount;k++)
        {
            if(nearest[k]!=-1 && cost[k][nearest[k]]<min)
            {
                j=k;
                min=cost[k][nearest[k]];
		flag=1;
            }
        }

	if(flag==1)
	{
		t[r][0]=j;
		t[r][1]=nearest[j];
		r=r+1;
	
		mincost=mincost+cost[j][nearest[j]];
		nearest[j]=-1;
		cout<<"\nVertice Selected : "<<j<<endl;

		for(k=0;k<vcount;k++)
		{
		    if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
		    {
		        nearest[k]=j;
		    }
		}
	}
        flag=0;
    }





    cout<<"\nVertex\tNearest\n\n";
    for(i=0;i<r;i++)
    {
	cout<<t[i][0]<<"\t"<<t[i][1]<<endl;
    }
    cout<<"\n\nSpanning Distance : "<<mincost<<endl;
   
    



}
int main()
{
    graph g1;
    g1.create_adjmat();
    g1.display_adjmat();
    g1.prims();
    return 0;
}
