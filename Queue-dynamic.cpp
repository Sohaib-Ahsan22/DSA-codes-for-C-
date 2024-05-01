#include <iostream>
using namespace std;
#include <algorithm>

struct QNode
{
    float value;
    QNode* next;
};
 
 QNode* front=NULL;
 QNode* rear=NULL;

 void EnQueue ()
 {
    QNode* temp = (QNode*) malloc (sizeof(QNode));
        cout<<"enter value"<< "\n";
        cin >> temp-> value;
        temp -> next=NULL;
        

    if (front == NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    //    QNode* curr = front;
    //         while (curr->next != NULL)
    //         {
    //             curr= curr->next;
    //         }
    //     rear=temp;
    //     curr -> next= rear;
    }
 }

 void DeQueue ()
 {
    if (front==NULL && rear==NULL)
    {
        cout<< "ALL EMPTY"<<"\n";
    }
    else
    {
        if (front==rear)
        {
            QNode* curr = front;
            cout << front->value<< "\n";
            front=front->next;
            rear=rear->next;
            free(curr); 
        }
        else
        {
            QNode* curr = front;
            cout << front->value<< "\n";
            front=front->next;
            free(curr);
        }
    }

 }

 
 int main()
    {
        int a=1;
        while (a==1 || a==2 || a==3 )
        {
            if (a==1)
            {
                EnQueue ();
            }
        
            else if (a==2)
            {
                DeQueue();
            }
            
            else if (a==3)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "if you want to EnQueue a value press 1" << "\n";
            cout << "if you want to DeQueue a value press 2" << "\n";
            cout << "if you want to  end program press 3" << "\n";
            cin>>a;
            while (a<1 || a>3)
            {
                cout<<"invalid key entered"<<"\n";
            cout << "if you want to EnQueue a value press 1" << "\n";
            cout << "if you want to DeQueue a value press 2" << "\n";
            cout << "if you want to  end program press 3" << "\n";
            cin>>a;            
            }    
        }
           
        return 0;
    }