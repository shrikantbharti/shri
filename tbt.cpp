/*
Name : Shrikant Bharti
R_no. : 203702
Div : G1
*/


#include <iostream>
using namespace std;

class tbtnode
{
	char data;
	bool rbit;
	bool lbit;
	tbtnode *right;
	tbtnode *left;
	friend class tbt;
public:
	tbtnode();
};

tbtnode :: tbtnode()
{
		lbit=1;
		rbit=1;
}

class tbt
{
	tbtnode *head;
	tbtnode *root;
public:
	void create();
	void inorder();
	void preorder();
	tbtnode *presuccr(tbtnode *temp);
	tbtnode *inordersuccr(tbtnode *temp);
	tbt();
};

tbt :: tbt()
{
	head=new tbtnode;
	head->rbit=0;
	head->left=head;
	head->right=head;
}

void tbt :: create()
{
	root=new tbtnode;
	char ch, choice;
	tbtnode *temp, *curr;
	cout<<"\n Enter data for root: ";
	cin>>root->data;
	head->lbit=0;
	root->left=head;
	root->right=head;
	head->left=root;
	do
	{
		int flag=0;
		temp=root;
		curr=new tbtnode;
		cout<<"\n Enter data for the node: ";
		cin>>curr->data;
		while(flag==0)
		{
			cout<<"\n Where do you want this node (right/left)? ";
			cin>>ch;
			if(ch=='l' || ch=='L')
			{
				if(temp->lbit==1)
				{
					curr->right=temp;
					curr->left=temp->left;
					temp->left=curr;
					temp->lbit=0;
					flag=1;
				}
				else
					temp=temp->left;
			}
			if(ch=='r' || ch=='R')
			{
				if(temp->rbit==1)
				{
					curr->left=temp;
					curr->right=temp->right;
					temp->right=curr;
					temp->rbit=0;
					flag=1;
				}
				else
					temp=temp->right;
			}
		}
		cout<<"\n Do you want to add more nodes (y/n)? ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
}

void tbt :: inorder()
{
	tbtnode *temp;
	temp=head;
	cout<<"\n In-order Traversal: ";
	while(1)
	{
		temp=inordersuccr(temp);
		if(temp==head)
			break;
		cout<<temp->data<<"  ";
	}
	cout<<"\n ";
}
tbtnode *tbt :: inordersuccr(tbtnode *temp)
{
	tbtnode *x;
	x=temp->right;
	if(temp->rbit==0)
	{
		while(x->lbit==0)
			x=x->left;
	}
	return x;
}

void tbt :: preorder()
{
	tbtnode *temp;
	temp=head->left;
	cout<<"\n Pre-order Traversal: ";
	while(temp!=head)
	{
		cout<<temp->data<<"  ";
		while(temp->lbit!=1)
		{
			temp=temp->left;
			cout<<temp->data<<"  ";
		}
		while(temp->rbit==1)
			temp=temp->right;
		temp=temp->right;
	}
	cout<<"\n ";
}

int main()
{
	tbt t1;
	t1.create();
	t1.inorder();
	t1.preorder();
	return 0;
}

/*
     OUTPUT:

 Enter data for root: A

 Enter data for the node: B

 Where do you want this node (right/left)? L

 Do you want to add more nodes (y/n)? Y

 Enter data for the node: C

 Where do you want this node (right/left)? R

 Do you want to add more nodes (y/n)? Y

 Enter data for the node: D

 Where do you want this node (right/left)? L

 Where do you want this node (right/left)? L

 Do you want to add more nodes (y/n)? Y

 Enter data for the node: E

 Where do you want this node (right/left)? L

 Where do you want this node (right/left)? R

 Do you want to add more nodes (y/n)? Y

 Enter data for the node: F

 Where do you want this node (right/left)? R

 Where do you want this node (right/left)? L

 Do you want to add more nodes (y/n)? Y

 Enter data for the node: G

 Where do you want this node (right/left)? R

 Where do you want this node (right/left)? R

 Do you want to add more nodes (y/n)? N

 In-order Traversal: D  B  E  A  F  C  G  
 
 Pre-order Traversal: A  B  D  E  C  F  G 

*/
