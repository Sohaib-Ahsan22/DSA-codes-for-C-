#include <iostream>
using namespace std;
#include <algorithm>

struct Records
{
    int Rno;
    float GPA;
    Records* next;
    Records* prev;
};
 
 // Records* head=NULL;

 void insert (Records**head)
 {
    Records* ptr = (Records*) malloc (sizeof(Records));
        cout<<"enter roll number"<< "\n";
        cin >> ptr-> Rno;
        cout << "enter GPA" << "\n";
        cin>> ptr-> GPA;
        ptr -> next=NULL;
        ptr -> prev=NULL;
    if (*head == NULL)
    {
        *head = ptr;
        (*head)->prev= NULL;
    }
    else
    {
        Records* curr = *head;
            while (curr->next != NULL)
            {
                curr= curr->next;
            }
        curr -> next= ptr;
        ptr->prev=curr;
    }
 }

 void search(Records** head)
 {
    if (*head == NULL)
    {
        cout<<"list is ALL empty"<<"\n";
    }
    else
    {
        int tosearch;
        cout<<"enter roll number to be searched:"<< "\n";
        cin>>tosearch;
        Records* curr = *head;
        bool found;
        while (curr!=NULL)
        {
            if (curr-> Rno == tosearch)
            {
                cout<<"detail of entered roll number is:      "<<"\n"<<"roll number  :    "<<curr->Rno << "\n" <<"GPA is  :     "<< curr ->GPA<<"\n";
                found = true;
                break;
            }
            else
            {
                curr = curr->next;
            } 
        }
        if (found == false)
        {
            cout << "data not found"<< "\n" ;   
        } 
    } 
 }

 void print(Records** head)
 {
    if (*head == NULL)
    {
        cout<<"list is ALL empty"<<"\n";
    }
    else
    {
        Records* curr = *head;
        while (curr!=NULL)
        {
                    
                cout<<"roll number is  :  "<<curr->Rno << "\n" <<"GPA is    :    "<< curr ->GPA<< "\n";
                curr = curr->next;
            
        } 
    }
 }

 void Delete(Records** head)
 {
    if (*head == NULL)
    {
        cout<<"list is ALL empty"<<"\n";
    }
    else
    {
        int todel;
        cout<<"enter roll number to be deleted:"<< "\n";
        cin>>todel;
        Records* curr = *head;
        if (todel == (*head)->Rno)
        {
        *head = (*head)->next;
        free(curr);
        cout<<"successfully deleted"<<"\n";  
        }
        else
        {
            Records* previous = *head;
            curr = (*head)->next;
            while (curr!= NULL)
            {
                if (curr-> Rno == todel)
                {
                    previous->next = curr->next;
                    free(curr);
                    cout<<"successfully deleted"<<"\n";
                    break;
                }
                //prev = curr;
                curr=curr->next;
                previous=previous->next;
            }
            if (curr == NULL)
            {
                cout<<"record not found"<<"\n";
            }    
        }
    }
 }
 void DeleteAll(Records** head)
 {
    if (*head == NULL)
    {
        cout<<"list is already empty"<<"\n";
    }
    else
    {
        Records* curr = *head;
        while(curr!=NULL)
        {
            *head = (*head)->next;
            free(curr);
            curr= (*head);
        }
        cout<<"All DATA DELETED"<<"\n";
    }
 
 }

 int main()
    {
        Records* head=NULL;
        int a=1;
        while (a==1 || a==2 || a==3 || a==4 || a== 5 || a==6)
        {
            if (a==1)
            {
                insert (&head);
            }
        
            else if (a==2)
            {
                search(&head);
            }
            else if (a==3)
            {
                print(&head);
            }
            else if (a==4)
            {
                Delete(&head);
            }
            else if (a==5)
            {
                DeleteAll(&head);   
            }
            
            
            else if (a==6)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "if you want to enter data press 1" << "\n";
            cout << "if you want to search data press 2" << "\n";
            cout << "if you want to print data press 3" << "\n";
            cout << "if you want to delete some data press 4" << "\n";
            cout << "if you want to delete all data press 5" << "\n";
            cout << "if you want to end process press 6" << "\n";
            cin>>a;
            while (a<1 || a>6)
            {
                cout<<"invalid key entered"<<"\n";
            cout << "if you want to enter data press 1" << "\n";
            cout << "if you want to search data press 2" << "\n";
            cout << "if you want to print data press 3" << "\n";
            cout << "if you want to delete some data press 4" << "\n";
            cout << "if you want to delete all data press 5" << "\n";
            cout << "if you want to end process press 6" << "\n";
            cin>>a;
            }    
        }
           
        return 0;
    }
