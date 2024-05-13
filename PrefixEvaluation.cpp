#include <iostream>
using namespace std;
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
string PostFix(string input)
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

string ReverseString(string input)
{
    string reverse="";
    int i = 0;
    while (i < input.length())
    {
        push(input[i]);
        i++;
    }
     while(top!=NULL)
    {
        char popped = pop(); 
        
        if (popped == '(')
        {
            reverse += string(1, ')');
        }
        else if (popped == ')')
        {
            reverse += string(1, '(');
        }
        else
        {
            reverse += string(1, popped);
        }
    }
    
    return reverse;
}
int PrefixEvaluation(string input)
{
  string postfixEq = ReverseString(input);
  cout<<postfixEq<<endl;
  int result;
  for (int i = 0; i < postfixEq.length(); i++)
  {
    char currChar = postfixEq[i];
    if (currChar > 47 && currChar < 58)
      push(currChar - 48);
    else
    {
      int tmp;
      int rop = pop();
      int lop = pop();
      switch (currChar)
      {
      case '*':
        tmp = lop * rop;
        break;
      case '/':
        tmp = lop / rop;
        break;
      case '%':
        tmp = lop % rop;
        break;
      case '+':
        tmp = lop + rop;
        break;
      case '-':
        tmp = lop - rop;
        break;
      case '<':
        tmp = lop < rop;
        break;
      case '>':
        tmp = lop > rop;
        break;
      case '=':
        tmp = lop == rop;
        break;
      case '!':
        tmp = lop != rop;
        break;
      case '&':
        tmp = lop && rop;
        break;
      case '|':
        tmp = lop || rop;
        break;
      default:
        break;
      }
      push(tmp);
    }
  }
  result = pop();
  return result;
}
    
int main()
{
    string infix;
    cout << "Enter an infix expression: ";   //test case used was a+(b*c) and here a =5 , b=3 and c=1
    getline(cin, infix);
    string reverseinfix=ReverseString(infix);
    cout<< "the reversed infix is  " <<reverseinfix<< endl;
    string postfix = PostFix(reverseinfix);
    cout << "Postfix expression: " << postfix << endl;
    string prefix=ReverseString(postfix);
    cout<<"the prefix is   "<<prefix << endl;
    int result = PrefixEvaluation(prefix);
    cout<<result<<endl;

    return 0;
}


