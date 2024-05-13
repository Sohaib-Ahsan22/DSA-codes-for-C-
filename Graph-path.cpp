#include <iostream>
using namespace std;
#include <algorithm>
struct vertex;
struct Edge
{
    vertex* ver;
    Edge* next;
    
};
struct vertex
{
    int rep;
    vertex* next;
    Edge* Edgelist;
};

 
 vertex* head=NULL;

 void insertVertex ()
 {
    vertex* ptr = (vertex*) malloc (sizeof(vertex));
        cout<<"enter value of vertex"<< "\n";
        cin >> ptr-> rep;
        ptr -> next=NULL;
        ptr->Edgelist=NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        vertex* curr = head;
            while (curr->next != NULL)
            {
                curr= curr->next;
            }
        curr -> next= ptr;
    }
 }

void insertEdge ()
 {
    Edge* ptr = (Edge*) malloc (sizeof(Edge));
        cout<<"enter edge"<< "\n";
        int edgename;
        cin >> edgename ;
        ptr ->next=NULL;
        cout<<"enter vertex you want to connect with"<< "\n";
        int connection;
        cin >> connection;

        vertex* check = head;
        while (check!=NULL)
        {
            if (edgename==check->rep)
            {
                break;
            }
            else
            {
                check=check->next;
            }
        }
        if (check==NULL)
        {
            cout<<"vertex does not exists"<<"\n";
            delete ptr;
        }
        vertex* connectTo=head;
         while (connectTo!=NULL)
        {
            if (connection==connectTo->rep)
            {
                break;
            }
            else
            {
                connectTo=connectTo->next;
            }
        }
        if (connectTo->rep >= edgename)
        {
            cout<<"invalid connection"<<"\n";
            delete ptr;
        }
        
        else if (connectTo->Edgelist==NULL)
        {   
            ptr->ver=check;  
            connectTo->Edgelist=ptr; 
            cout<<"Added"<<"\n";
              
        }
        else
        {
            ptr->ver=check;
            Edge* temp = connectTo->Edgelist;
            while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        cout << "connection added" << endl;
        }
 }        
  
void printvertex()
 {
    if (head == NULL)
    {
        cout<<"Graph is ALL empty"<<"\n";
    }
    else
    {
        vertex* curr = head;
        while (curr!=NULL)
        {         
            cout<<"vertex is  :  "<<curr->rep << "\n" ;
            curr = curr->next;   
        } 
    }
 }   
struct StNode
{
    int value;
    StNode* next;
};
 
 StNode* top=NULL;

 void push (int update)
 {
    StNode* temp = (StNode*) malloc (sizeof(StNode));
        
        temp-> value=update;
        temp -> next=top;
        top=temp;
 }

 int pop ()
 {
    if (top==NULL)
    {
        cout<< "Stack underflow"<<"\n";
    }
    else
    {
    StNode* curr = top;
    return  top->value;
    top=top->next;
    free(curr);
    }
 }
 
 void FindPath(int initial, int final) 
 {
    vertex* curr = head; 
    bool t = false; 
    while (curr != NULL && curr->rep != initial) 
    {
        curr = curr->next;
    }

    
    if (curr == NULL || curr->rep == final) 
    {
        cout << "No path exists between " << initial << " and " << final << endl;
        return;
    }
    while (curr->Edgelist != NULL) 
    {
        if (curr->Edgelist->ver->rep == final) 
        {
            cout << curr->rep << " <- " << curr->Edgelist->ver->rep << endl;
            t = true; 
            break;
        } else
         {
            push(curr->rep);
            FindPath(curr->Edgelist->ver->rep, final); 
            if (t) 
            {
                cout << pop() << " <- "; 
            } 
            else 
            {
                curr->Edgelist = curr->Edgelist->next;
        
            }
        }


    }

    if (!t) {
        pop(); 
}
}

 int main()
    {
        int a;
        cout << "if you want to enter vertex , press 1" << "\n";
        cout << "if you want to enter connection, press 2" << "\n";
        cout << "if you want to print vertecies ,press 3" << "\n";
        cout << "if you want to find path ,press 4" << "\n";
        cout << "if you want to end press 5" << "\n";
        cin>>a;
        while (a==1 || a==2 || a==3 || a==4 )
        {
            if (a==1)
            {
                insertVertex ();
            }
        
            else if (a==2)
            {
                insertEdge();
            }
            else if (a==3)
            {
                printvertex();
            } 
            else if (a==4)
            {
                int to,from;
                cout <<"find path from"<<endl;
                cin>> from;
                cout <<"find path to"<<endl;
                cin>> to;
                FindPath(from,to);
            }
             
            else if (a==5)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "if you want to enter vertex , press 1" << "\n";
            cout << "if you want to enter connection, press 2" << "\n";
            cout << "if you want to print vertecies ,press 3" << "\n";
            cout << "if you want to find path ,press 4" << "\n";
            cout << "if you want to end press 5" << "\n";
            cin>>a;
            while (a<1 || a>6)
            {
                cout<<"invalid key entered"<<"\n";
            cout << "if you want to enter vertex , press 1" << "\n";
            cout << "if you want to enter connection, press 2" << "\n";
            cout << "if you want to print vertecies ,press 3" << "\n";
            cout << "if you want to find path ,press 4" << "\n";
            cout << "if you want to end press 5" << "\n";
            cin>>a;
            }    
        }
           
        return 0;
    }