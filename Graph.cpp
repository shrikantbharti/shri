//Name:manas yeole
//Roll no:203364
//Aim:graphs Understanding and applications

#include <iostream>
#include <string>
#define MAX 20

using namespace std;

class gnode
{
	int useid;
	string data;
	gnode *next;

	friend class graph;
};

class stack
{
	int top, datas[MAX * 2];

public:
	stack()
	{
		top = -1;
	}
	void push(int temp)
	{
		top++;
		datas[top] = temp;
	}

	int isempty()
	{
		if(top == -1)
			return 1;
		else
			return 0;
	}

	int pop()
	{
		if(isempty() != 1)
		{
			int temp = datas[top];
			top--;
			return temp;
		}

		else
			return 0;
	}
	friend class graph;
};

class queue
{
	int front, rear, dataq[MAX];

public:
	queue()
	{
		front = rear = -1;
	}
	void insert(int temp)
	{
		rear++;
		dataq[rear] = temp;
	}

	int empty()
	{
		if(rear == front)
			return 1;
		else
			return 0;
	}

	int deleteQ()
	{
		if(empty() != 1)
		{
			front++;
			int temp = dataq[front];
			return temp;
		}
		else
			return 0;
	}
	friend class graph;
};

class graph
{
	gnode *head[MAX];
	int visited[MAX], n;

public:

	graph()
	{
		n = 0;

		cout<<"\nHow many users? ";
		cin>>n;

		for(int i = 0; i < n; i++)
		{
			head[i] = new gnode();
			head[i]->useid = i;

			cout<<"\nEnter name of user #"<<head[i]->useid<<" ";
			cin>>head[i]->data;
			//head[i]->next = NULL;	//Breakpoint 1
		}
	}

	void create()
	{
		gnode *curr;
		gnode *temp;
		int v;
		char ans;

		for(int i = 0; i < n; i++)	//Breakpoint 2
		{
			temp = head[i];
			cout<<"\nenter user no. "<<head[i]->useid<<"'s friends: ";

			do
			{
				cout<<"\nenter id ";
				cin>>v;

				if(head[i]->useid == v)
					cout<<"\nNot permitted!";

				else
				{
					curr = new gnode();
					curr->data = head[v]->data;
					curr->useid = v;
					temp->next = curr;
					temp = temp->next;
				}

				cout<<"\nAdd any more friends?";
				cin>>ans;
			}while(ans == 'y' || ans == 'Y');
		}
	}

	void gdisplay()
	{
		gnode *temp;

		cout<<"\nSocial network: "<<endl;

		for(int i = 0; i < n; i++)
		{
			temp = head[i];

			while(temp != NULL)
			{
				cout<<temp->data<<"\t";
				temp = temp->next;
			}
			cout<<"\n";
		}
	}

	void dfsr()
	{
		for(int i = 0; i < n; i++)
			visited[i] = 0;

		int star;
		cout<<"\nWhere to start DFS(recursive)?";
		cin>>star;

		dfsr(star);
	}

	void dfsr(int star)
	{
		gnode *temp;

		cout<<head[star]->data;

		visited[star] = 1;
		temp = head[star]->next;

		while(temp != NULL)
		{
			if(!visited[temp->useid])
				dfsr(temp->useid);

			else
			{
				temp = temp->next;

				if(temp != NULL && visited[temp->useid] == 0)
					dfsr(temp->useid);
			}
		}
	}

	void dfsi(int star)
	{
		gnode *temp;
		cout<<"\n";

		for(int i = 0; i < n; i++)
			visited[i] = 0;

		stack s1;

		s1.push(star);

		visited[star] = 1;

		do
		{
			star = s1.pop();
			cout<<head[star]->data;

			temp = head[star]->next;
			while(temp != NULL)
			{
				if(!visited[temp->useid])
				{
					s1.push(temp->useid);
					visited[temp->useid] = 1;
				}

				temp = temp->next;
			}
		}while(!s1.isempty());
		//cout<<"\n";
	}

	void bfsr(int star)
	{
		gnode *temp;
		cout<<"\n";

		for(int i = 0; i < n; i++)
			visited[i] = 0;

		queue q1;

		q1.insert(star);
		visited[star] = 1;

		while(!q1.empty())
		{
			star = q1.deleteQ();

			cout<<head[star]->data;

			temp = head[star]->next;
			while(temp != NULL)
			{
				if(!visited[temp->useid])
				{
					q1.insert(temp->useid);
					visited[temp->useid] = 1;
				}
				temp = temp->next;
			}
		}
		cout<<"\n";
	}
};

int main()
{
	int stard, starb, cho;
	char con;

	graph g1;

	do
	{
		cout<<"\nChoose";
		cout<<"\n1 to Create network";
		cout<<"\n2 to display the network";
		cout<<"\n3 to show its Dfs(recursive)";
		cout<<"\n4 to show its Dfs(non-recursive)";
		cout<<"\n5 to show its Bfs";

		cin>>cho;
		switch(cho)
		{
			case 1: g1.create();
					break;

			case 2: g1.gdisplay();
					break;

			case 3: g1.dfsr();
					break;

			case 4: cout<<"\n\nWhere to start DFS(non-recursive)?";
					cin>>stard;

					g1.dfsi(stard);
					break;

			case 5: cout<<"\n\nWhere to start BFS?";
					cin>>starb;

					g1.bfsr(starb);
					break;

			default: cout<<"\nWrong input";
		}
		cout<<"\n\ndo you want to continue?";
		cin>>con;
	}while(con == 'y' || con == 'Y');

	return 0;
}


/*
 *

How many users? 3

Enter name of user #0 0

Enter name of user #1 1

Enter name of user #2 2

Choose
1 to Create network
2 to display the network
3 to show its Dfs(recursive)
4 to show its Dfs(non-recursive)
5 to show its Bfs1

enter user no. 0's friends:
enter id 1

Add any more friends?n

enter user no. 1's friends:
enter id 0

Add any more friends?y

enter id 2

Add any more friends?n

enter user no. 2's friends:
enter id 1

Add any more friends?n


do you want to continue?y

Choose
1 to Create network
2 to display the network
3 to show its Dfs(recursive)
4 to show its Dfs(non-recursive)
5 to show its Bfs2

Social network:
0	1
1	0	2
2	1


do you want to continue?y

Choose
1 to Create network
2 to display the network
3 to show its Dfs(recursive)
4 to show its Dfs(non-recursive)
5 to show its Bfs3

Where to start DFS(recursive)?0
012

do you want to continue?y

Choose
1 to Create network
2 to display the network
3 to show its Dfs(recursive)
4 to show its Dfs(non-recursive)
5 to show its Bfs4


Where to start DFS(non-recursive)?1

120

do you want to continue?y

Choose
1 to Create network
2 to display the network
3 to show its Dfs(recursive)
4 to show its Dfs(non-recursive)
5 to show its Bfs5


Where to start BFS?2

210


do you want to continue?
 */
