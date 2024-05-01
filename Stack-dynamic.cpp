#include <iostream>
using namespace std;
#include <algorithm>

struct StNode
{
    float value;
    StNode* next;
};
 
 StNode* top=NULL;

 void push ()
 {
    StNode* temp = (StNode*) malloc (sizeof(StNode));
        cout<<"enter value"<< "\n";
        cin >> temp-> value;
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

 void pop ()
 {
    if (top==NULL)
    {
        cout<< "Stack underflow"<<"\n";
    }
    else
    {
    StNode* curr = top;
    cout << top->value<< "\n";
    top=top->next;
    free(curr);
    }

 }

 
 int main()
    {
        int a=1;
        while (a==1 || a==2 || a==3 )
        {
            if (a==1)
            {
                push ();
            }
        
            else if (a==2)
            {
                pop();
            }
            
            else if (a==3)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "if you want to push value press 1" << "\n";
            cout << "if you want to pop value press 2" << "\n";
            cout << "if you want to  end program press 3" << "\n";
            cin>>a;
            while (a<1 || a>3)
            {
                cout<<"invalid key entered"<<"\n";
            cout << "if you want to push value press 1" << "\n";
            cout << "if you want to pop value press 2" << "\n";
            cout << "if you want to  end program press 3" << "\n";
            cin>>a;            
            }    
        }
           
        return 0;
    }
