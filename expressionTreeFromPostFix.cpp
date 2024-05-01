#include <iostream>
using namespace std;
struct Node
{
    char node;
    Node* Lchild;
    Node* Rchild;
};
struct StackNode
{
    Node* value;
    StackNode* next;
};
 StackNode* top1=NULL;
 void push1 (Node* val)
 {
    StackNode* temp = (StackNode*) malloc (sizeof(StackNode));       
        temp-> value= val;
        temp -> next=NULL;
        

    if (top1 == NULL)
    {
        top1=temp;
    }
    else
    {
        StackNode* curr = top1;
        top1=temp;
        temp->next=curr;
    }
 }

Node* pop1 ()
 {
    if (top1==NULL)
    {
        cout<< "Stack underflow"<<"\n";
        return 0;
    }
    else
    {
    StackNode* curr = top1;
    Node* val = top1->value;
    top1 = top1->next;
    delete curr;
    return val;
    }
 }
struct StNode
{
    char value;
    StNode* next;
};
 
 StNode* top=NULL;

 void push (char val)
 {
    StNode* temp = (StNode*) malloc (sizeof(StNode));       
        temp-> value= val;
        temp -> next=NULL;
        

    if (top == NULL)
    {
        top=temp;
    }
    else
    {
        StNode* curr = top;
        top=temp;
        temp->next=curr;
    }
 }
 struct StNode1
{
    string value;
    StNode1* next;
};
StNode1* top2=NULL;
 void push2 (string val)
 {
    StNode1* temp = (StNode1*) malloc (sizeof(StNode1));       
        temp-> value= val;
        temp -> next=NULL;
        

    if (top2 == NULL)
    {
        top2=temp;
    }
    else
    {
        StNode1* curr = top2;
        top2=temp;
        temp->next=curr;
    }
 }
char head ()
 {
    if (top==NULL)
    {
        cout<< "Stack underflow"<<"\n";
        return 0;
    }
    else
    {
    char val = top->value;
    return val;
    }
 }
 char pop ()
 {
    if (top==NULL)
    {
        cout<< "Stack underflow"<<"\n";
        return 0;
    }
    else
    {
    StNode* curr = top;
    char val = top->value;
    top = top->next;
    delete curr;
    return val;
    }
 }
 string pop2 ()
 {
    if (top2==NULL)
    {
        cout<< "Stack underflow"<<"\n";
        return 0;
    }
    else
    {
    StNode1* curr = top2;
    string val = top2->value;
    top2 = top2->next;
    delete curr;
    return val;
    }
 }
int precedence(char op) 
{
    
    if (op == '*' || op == '/' || op=='%')
    {
        return 4;
    }
    if (op == '+' || op == '-')
    {
        return 3;
    }
    if (op=='<' || op== '>' )
    {
        return 2;
    }
    if (op=='&' || op=='|')
    {
        return 1;
    }  
    return 0;
}
string PostFix(string &input)
{
    string postfix;
    for (char i : input)
    {
        if (isalnum(i))
        {
            postfix += i;
        }
        else if (i=='(')
        {
           push(i); 
        }
        else if (i==')')
        {
           while (top!= NULL && head() != '(') {
                postfix += head();
                pop();
            } 
            pop();
        }
        else
        {
            while (top!= NULL && precedence(head()) >= precedence(i)) {
                postfix += head();
                pop();
            }
            push(i);
        }
    }
    while (top!=NULL)
    {
        postfix += head();
        pop();
    }
    return postfix;
}
void ExpressionTree(char val)
{
    if (val == '*' || val == '/' || val == '-' || val == '+' ||val == '%' || val == '|' || val == '&' || val == '<' || val == '>') 
    {
        Node* temp = (Node*) malloc (sizeof(Node));       
        temp-> node= val;
        temp -> Rchild=pop1();
        temp -> Lchild=pop1();
        push1(temp);
    }
    else{
         Node* temp = (Node*) malloc (sizeof(Node));
         temp->node=val;
         temp -> Lchild=NULL;
         temp -> Rchild=NULL;
         push1(temp);
    }
}
void InOrderTraversal(Node* root) {
if (root == nullptr) {
    return;
}
InOrderTraversal(root->Lchild); 
cout << root->node << " "; 
InOrderTraversal(root->Rchild); 
}


    
int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = PostFix(infix);
    for (char i : postfix)
    {
        ExpressionTree(i);    
    }
    
    cout << "Postfix expression: " << postfix << endl;
    cout << "In-order traversal of the expression tree: ";
    InOrderTraversal(top1->value);

    return 0;
}


