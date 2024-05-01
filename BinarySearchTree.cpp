#include <iostream>
using namespace std;
struct BSTnode
{
    int data;
    BSTnode* right;
    BSTnode* left;
};
BSTnode* insert (BSTnode* node, int value)
{
    if (node==NULL)
    {
        BSTnode* node=(BSTnode*)malloc(sizeof(BSTnode));
        node->data=value;
        node->right=NULL;
        node->left=NULL;
        return node;
    }
    if (value<node->data)
    {
        node->left=insert(node->left,value);
    }
    else
    {
        node->right=insert(node->right,value);
    }
}
void SearchTree (BSTnode* node, int value)
{
    if (node==NULL)
    {
        cout<<"no record found"<<"\n";
        
    }
    else if (node->data==value)
    {
        cout<<"record found"<<"\n";
    }
    
    
    else if (value<node->data)
    {
        SearchTree(node->left,value);
    }
     
    else
    {
        SearchTree(node->right,value);
    }   
}
BSTnode* minvalue(BSTnode* node)
{
    while (node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}
BSTnode* todel(BSTnode* node,int value)
{
     if (node==NULL)
    {
        cout<<"no record found"<<"\n";  
    }
    if (value<node->data)
    {
        node->left =todel(node->left,value);
    }
    else if (value>node->data)
    {
        node->right =todel(node->right,value);
    }
   else
   {
    if (node->left==NULL)
    {
        BSTnode* temp = node->right;
        free(node);
        return temp;
    }
    else if (node->right==NULL)
    {
        BSTnode* temp = node->left;
        free(node); 
        return temp;
    }
    BSTnode* temp = minvalue(node->right);
    node->data=temp->data;
    node->right=todel(node->right,temp->data);
    return node;
   }
}

void InOrderTrav(BSTnode* node)
{
    if (node!=NULL)
    {
        InOrderTrav(node->left);
        cout<<node->data<<endl;
        InOrderTrav(node->right);
    }
}
void PreOrderTrav(BSTnode* node)
{
    if (node!=NULL)
    {
        cout<<node->data<<endl;
        PreOrderTrav(node->left);
        PreOrderTrav(node->right);
    }
}
void PostOrderTrav(BSTnode* node)
{
    if (node!=NULL)
    {
        PostOrderTrav(node->left);
        PostOrderTrav(node->right);
        cout<<node->data<<endl;
    }
}

BSTnode* maxvalue(BSTnode* node)
{
    while (node->right!=NULL)
    {
        node=node->right;
    }
    return node;
}
int main()
{
    BSTnode* Root= NULL;
    int a=0;
    int input=0;
    while (a>=0 && a<=9)
    {
    if (a==1)
    {
        cout<<"enter value to be stored"<<"\n";
        cin>>input;
        Root=insert(Root,input);
        
    }
    else if (a==2)
    {
        cout<<"enter value to be searched"<<"\n";
        cin>>input;
        SearchTree(Root,input);
       
    }
    else if (a==3)
    {
        cout<<"enter value to be deleted"<<"\n";
        cin>>input;
        minvalue(Root->right);
        todel(Root,input);
    }
    else if(a==4)
    {
        cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
            int c =0;
            cin>> c;
            cout << "Ratings  :  "<<c;
            break;   
    } 
    else if (a==5)
    {
        InOrderTrav(Root);
    }
    else if (a==6)
    {
        PreOrderTrav(Root);
    }
    else if (a==7)
    {
        PostOrderTrav(Root);
    }
    else if (a==8)
    {
       BSTnode* MinimumValue= minvalue(Root->right);
       //cout<<MinimumValue->data<<endl;
    }
     else if (a==9)
    {
       BSTnode* MaximumValue= maxvalue(Root->left);
       //cout<<MaximumValue->data<<endl;
    }
    
    
     
    cout<<"      select one      "<<endl;
    cout<<"press 1 to enter data"<<endl;
    cout<<"press 2 to search data "<<"\n";
    cout<<"press 3 to delete a value"<<"\n";
    cout<<"press 4 to end program "<<"\n";
    cout<<"press 5 to print the data using InOrder Traversal "<<"\n";
    cout<<"press 6 to print the data using PreOrder Traversal "<<"\n";
    cout<<"press 7 to print the data using PostOrder Traversal "<<"\n";
    cout<<"press 8 to print the minimum value "<<"\n";
    cout<<"press 9 to print the Maximum value "<<"\n";
    cin>>a;  
    }
    return 0;
}
