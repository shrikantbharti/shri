/*Name:Shrikant Bharti
Roll no. : 203702
class:SYCSE-G1
*/

//Binary Tree

#include <iostream>
using namespace std;
class treenode
{
    char data[10];
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree{
    treenode *root;
public:
    tree();
    void create_r();
    void create_r(treenode *);
    void create_nr();
    void inorder_r();
    void inorder_r(treenode *);
    void preorder_r();
    void preorder_r(treenode *);
    void postorder_r();
    void postorder_r(treenode *);
    void inorder_nr();
    void preorder_nr();
    void postorder_nr();
};



tree::tree(){
    root=NULL;
}

void tree:: create_r(){
    if(root==NULL){
        root = new treenode;
        cout<<"Enter data:";
        cin>>root->data;
    }
    create_r(root);
}

void tree:: create_r(treenode *temp){
    char ch;
    treenode *curr;
    cout<<"\nDo you want to add to the left of the node  "<<temp->data <<"  ?(n/y)";
    cin>>ch;
    if(ch=='y'){
        curr=new treenode;
        cout<<"\nEnter data:";
        cin>>curr->data;
        temp->left=curr;
        create_r(curr);
    }
    cout<<"\nDo you want to add to the right of the node  "<<temp->data <<"  ?(n/y)";
    cin>>ch;
    if(ch=='y'){
        curr=new treenode;
        cout<<"\nEnter data:";
        cin>>curr->data;
        temp->right=curr;
        create_r(curr);
    }
}

void tree:: create_nr(){
    char ch,choice;
    int flag;
    treenode *temp,*curr;
    if(root==NULL){
        root=new treenode;
        cout<<"\nENter data:";
        cin>>root->data;
    }
    do{
        temp=root;
        flag=0;
        curr=new treenode;
        cout<<"Enter data:";
        cin>>curr->data;
        while(flag==0){
            cout<<"\nDo you want to add to the left or right of the node  "<<temp->data<<"  ? (l or r)";
            cin>>ch;
            if(ch=='l')
                {
                    if(temp->left==NULL){
                        temp->left=curr;
                        flag=1;
                    }
                    temp=temp->left;
                }
            else {
                if(ch=='r'){
                    if(temp->right==NULL)
                    {
                    temp->right=curr;
                    flag=1;
                    }
                temp=temp->right;
            }
            }
            }
        cout<<"Do you want to continue?(y or n)";
        cin>>choice;
        }
    while(choice=='y');
    }


void tree:: inorder_r(){
    if (root == NULL){
        cout<<"\nBinary tree empty!";
    }
    else{
        inorder_r(root);
    }
}
void tree :: inorder_r(treenode *temp){
    if (temp!=NULL){
        inorder_r(temp->left);                            //traversal LDR
        cout<<temp->data<<"\t";
        inorder_r(temp->right);
    }
}
void tree :: preorder_r(){
    if (root == NULL){
            cout<<"\nBinary tree empty!";
        }
        else{
            preorder_r(root);
        }
}
void tree :: preorder_r(treenode *temp){
    if (temp!=NULL){
        cout<<temp->data<<"\t";                            //traversal DLR
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}
void tree :: postorder_r(){
    if (root == NULL){
            cout<<"\nBinary tree empty!";
        }
        else{
            postorder_r(root);
        }
}
void tree :: postorder_r(treenode *temp){
    if (temp!=NULL){
        postorder_r(temp->left);                        //Traversal LRD
        postorder_r(temp->right);
        cout<<temp->data<<"\t";
    }
}


class stack{
    int top;
    treenode *data[30];                                    //creating array for stack of data type treenode*
public:
    stack(){                                            //constructor
        top=-1;
    }
    void push(treenode *temp);                            //member functions
    treenode *pop();
    int empty();
    friend class tree;
};
void stack::push(treenode *temp){
    top++;
    data[top]=temp;
}
treenode* stack::pop(){
    treenode* temp;
    temp=data[top];
    top--;
    return(temp);
}


int stack ::empty(){
    if(top==-1){
        return (1);
    }
    else{
        return (0);
    }
}

void tree :: inorder_nr(){
    stack s;//object of class stack
    treenode *temp;
    if (root == NULL){
                cout<<"\nBinary tree empty!";
            }
else{
    temp=root;
    while(1){
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()==1){                            //terminating condition
            break;
        }
            temp=s.pop();
            cout<<"\t"<<temp->data;
            temp=temp->right;
    }
}
}
void tree :: preorder_nr(){
    stack s;
    treenode *temp;
    if (root == NULL){
                cout<<"\nBinary tree empty!";
            }
            else{
    temp=root;
    while(1){
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<temp->data<<"\t";
            temp=temp->left;
        }
        if(s.empty()==1){
            break;
        }
            temp=s.pop();
            temp=temp->right;
    }
}
}

void tree :: postorder_nr(){
    stack s;
    treenode *temp;
    if (root == NULL){
                    cout<<"\nBinary tree empty!";
                }
else{
    temp=root;
    while(1){
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }

        if(s.data[s.top]->right==NULL){
            temp=s.pop();
            cout<<temp->data<<"\t";
        }
        while( s.top!=-1 && s.data[s.top]->right==temp ){
            temp=s.pop();
            cout<<temp->data<<"\t";
        }
        if(s.empty()==1){
                    break;
                }
            temp=s.data[s.top]->right;
    }
}
}
int main() {
    tree bt;                                        //object of class tree
    int ch;
    do{
    cout<<"\n___MENU_____";                            //menu driven interface
    cout<<"\n1.Create(r)          2.Create(nr)";
    cout<<"\n3.In order(r)        4.In order(nr)";
    cout<<"\n5.Preorder(r)        6.Preorder(nr)";
    cout<<"\n7.Postorder(r)       8.Postorder(nr)";
    cout<<"\n9.Exit";
    cin>>ch;
    switch(ch){
    case 1:
        bt.create_r();
        break;
    case 2:
        bt.create_nr();
        break;
    case 3:
        cout<<"\nThe tree in inorder(r) is :\n";
        bt.inorder_r();
        break;
    case 4:
        cout<<"\nThe tree in inorder(nr) is :\n";
        bt.inorder_nr();
        break;
    case 5:
        cout<<"\nThe tree in preorder(r) :\n";
        bt.preorder_r();
        break;
    case 6:
        cout<<"\nThe tree in preorder(nr) :\n";
        bt.preorder_nr();
        break;
    case 7:
        cout<<"\nThe tree in postorder(r) :\n";
        bt.postorder_r();
        break;
    case 8:
        cout<<"\nThe tree in postorder(r) :\n";
        bt.postorder_nr();
        break;
    case 9:
        return 0;
    default:
        return 0;
    }
    }
    while(ch<10);
    return 0;
}
