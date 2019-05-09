/*
Name : Shrikant Bharti
R_no : 203702
Div. : 7 G1 SYBtech CSE
*/
#include<iostream>
#include<string.h>
using namespace std;
#define max 100
int r=-1;
int f=-1;
class node
{
	char word[20],mean[20];
	node *lc;
	node *rc;
	friend class bst;
};
node *q[max];
class bst
{
	node *root;
	public:
	bst()
	{
		root=NULL;
	}
	void create();
	void search();
	int search(node *temp,char str[20]);
	void bfs();
	int isempty();
	int isfull();
	node* deleq();
	void add(node* item);
	void delt();
	void mirror_r();
	void mirror_r(node *root);
	void copy();
	node* copy(node *root);
	void del();
	void postorder();
	void postorder(node *temp);
};
void bst::create()
{
	node *temp,*curr;
	int flag,c;
	do {
	if(root==NULL)
	{
		root=new node();
		cout<<"Enter word and its meaning for root:";
		cin>>root->word;
		cin>>root->mean;
		root->lc=NULL;
		root->rc=NULL;
	}
	else
	{
		temp=root;
		flag=0;
		curr=new node();
		curr->lc=NULL;
		curr->rc=NULL;
		cout<<"Enter word and its meaning:";
		cin>>curr->word;
		cin>>curr->mean;
		while(flag==0)
		{
			if((strcmp(curr->word,temp->word)) < 0)
			{
				if(temp->lc==NULL)
				{
					temp->lc=curr;
					flag=1;
				}
				temp=temp->lc;
			}
			else
			{
				if(temp->rc==NULL)
				{
					temp->rc=curr;
					flag=1;
				}
				temp=temp->rc;
			}
		}
	}
	cout<<"Do you want to add more?(y=1/n=0):";
	cin>>c;
	}while(c==1);
}
void bst::search()
{
	int flag=0;
	char str[20];
	cout<<"Enter word to be search:";
	cin>>str;
	flag=search(root,str);
	if(flag==1)
		cout<<"Found!!";
	else
		cout<<"Not found!!";
}
int bst::search(node *temp,char str[20])
{
	int f=0;
	if(temp!=NULL)
	{
		if((strcmp(str,temp->word)) == 0)
			return 1;
		if((strcmp(str,temp->word)) < 0)
			f=search(temp->lc,str);
		if((strcmp(str,temp->word)) > 0)
			f=search(temp->rc,str);
	}
	return f;
}
int bst:: isempty()
{
	if(f==r)
		return 0;
	else
		return 1;
}
int bst::isfull()
{
	if(r==(max-1))
		return 0;
	else
		return 1;
}
void bst::add(node* item)
{
	if(isfull())
	{
		r++;
		q[r]=item;
	}
	else
	{
		cout<<"\nQueue is full:";
	}
}
node* bst::deleq()
{
	node *temp;
	if(isempty())
	{
		f++;
		temp=q[f];
		return temp;
	}
	else
		return NULL;
}
void bst::bfs()
{
	node *temp;
	temp=root;
	add(temp);
	while(isempty())
	{
		temp=deleq();
		cout<<temp->word<<"-"<<temp->mean<<"\t";
		if(temp->lc!=NULL)
		{
			add(temp->lc);
			cout<<"\n";
		}
		if(temp->rc!=NULL)
		{
			add(temp->rc);
		}
	}
}
void bst::mirror_r()
{
	mirror_r(root);
	bfs();
}
void bst::mirror_r(node *root)
{
	node *temp;
	temp=root->lc;
	root->lc=root->rc;
	root->rc=temp;
	if(root->lc!=NULL)
		mirror_r(root->lc);
	if(root->rc!=NULL)
		mirror_r(root->rc);
}
void bst:: copy()
{
	node *temp,*tmp;
	tmp=copy(root);
	cout<<"Copied tree:\n";
	//bfs();
	temp=tmp;
	add(temp);
	while(isempty())
	{
		temp=deleq();
		cout<<temp->word<<"\t"<<temp->mean<<"\n";
		if(temp->lc!=NULL)
			add(temp->lc);
		if(temp->rc!=NULL)
			add(temp->rc);
	}
}
node* bst:: copy(node *root)
{
	node *temp;
	temp=NULL;
	if(root!=NULL)
	{
		temp=new node();
		strcpy(temp->word,root->word);
		strcpy(temp->mean,root->mean);
		temp->lc=copy(root->lc);
		temp->rc=copy(root->rc);
	}
	return temp;
}
void bst:: del()
{
node *temp,*parent,*curr,*s;
int flag=0;
string key;
cout<<"Enter key to delete:";
cin>>key;
curr=root;
while(curr!=NULL)
{
    if(curr->word == key)
    {
        flag=1;
        break;
    }
    else if(curr->word <key)
    {
        parent=curr;
        curr=curr->rc;
    }
    else
    {
        parent=curr;
        curr=curr->lc;
    }
}
if(flag==1)
{
	if(curr==root)
	{
		if(curr->rc==NULL)
		{
			root=root->lc;
		}
		else if(curr->lc==NULL)
		{
			root=root->rc;
		}
		else if(curr->rc!=NULL && curr->lc!=NULL)
		{
			temp=curr->lc;
			root=curr->rc;
			s=curr->rc;
			while(s->lc!=NULL)
			{
				s=s->lc;
			}
        s->lc=temp;
        }
    }
    else if( curr!=root)
    {
        if(curr->lc==NULL && curr->rc==NULL)
        {
            if(parent->lc==curr)
            {
                parent->lc=NULL;
            }
            else
            {
                parent->rc=NULL;
            }
        }
        else if(curr->lc==NULL)
        {
            if(parent->lc==curr)
            {
                parent->lc=curr->rc;
            }
            else
            {
            	parent->rc=curr->rc;
            }
        }
        else if(curr->rc==NULL)
        {
        	if(parent->lc==curr)
        	{
        		parent->lc=curr->lc;
        	}
        	else
        	{
        		parent->rc=curr->lc;
        	}
        }
        else
        {
        	s=curr->rc;
        	temp=curr->lc;
        	while(s->lc!=NULL)
        	{
        		s=s->lc;
        	}
        	s->lc=temp;
        	if(parent->lc==curr)
        	{
        		parent->lc=curr->rc;
        	}
        	else
        	{
        		parent->rc=curr->rc;
        	}
        }
    }
	curr->lc=NULL;
	curr->rc=NULL;
	delete(curr);
}
else
{
	cout<<"Keyword doesn't exist";
}
}
void bst::postorder()
{
    postorder(root);
}

void bst::postorder(node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->lc);
        postorder(temp->rc);
    }
    delete(temp);
}
int main()
{
	bst b1;
	int ch;
	do {
	cout<<"\nEnter your choice:\n1.create\n2.search\n3.Display(BFS)\n4.delete\n5.mirror\n6.copy(recursive)\n7.Exit\n";
	cin>>ch;
	switch(ch)
	{
	case 1:
		b1.create();
		break;
	case 2:
		b1.search();
		break;
	case 3:
		cout<<"\nBFS is:\n";
		b1.bfs();
		break;
	case 4:
		b1.del();
		break;
	case 5:
		cout<<"\nMirror:\n";
		b1.mirror_r();
		break;
	case 6:
		b1.copy();
		break;
	case 7:
		b1.postorder();
		b1.bfs();
		break;
	}
	}while(ch!=7);
	return 0;
}



/*output:student@student:~$ g++ tbt2.cpp
student@student:~$ ./a.out

Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

1

Enter word and its meaning for root:Apple
Fruit
Do you want to add more?(y=1/n=0):1
Enter word and its meaning:Banana
Fruit
Do you want to add more?(y=1/n=0):1
Enter word and its meaning:Cat
Animal
Do you want to add more?(y=1/n=0):1
Enter word and its meaning:Dog
animal
Do you want to add more?(y=1/n=0):1
Enter word and its meaning:Grapes
Fruit
Do you want to add more?(y=1/n=0):0

Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

2

Enter word to be search:Apple
Found!!
Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

2   

Enter word to be search:water
Not found!!
Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit


3

BFS is:
Apple-Fruit	Banana-Fruit	Cat-Animal	Dog-animal	Grapes-Fruit	
Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

4

Enter key to delete:Cat

Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

3

BFS is:
Apple-Fruit	Banana-Fruit	Dog-animal	Grapes-Fruit	
Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

5

Mirror:
Apple-Fruit	
Banana-Fruit	
Dog-animal	
Grapes-Fruit	
Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

6

Copied tree:
Apple	Fruit
Banana	Fruit
Dog	animal
Grapes	Fruit

Enter your choice:
1.create
2.search
3.Display(BFS)
4.delete
5.mirror
6.copy(recursive)
7.Exit

7

