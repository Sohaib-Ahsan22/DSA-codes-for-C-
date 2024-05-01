#include <iostream>
using namespace std;
#include <algorithm>
struct stud
{
    int SID;
    stud* next;
    int COID;
};
struct course
{
    int CID;
    course* next;
    stud* start;
};


 
 course* head=NULL;

 void insertCourse ()
 {
    course* ptr = (course*) malloc (sizeof(course));
        cout<<"enter course ID"<< "\n";
        cin >> ptr-> CID;
        ptr -> next=NULL;
        ptr-> start=NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        course* curr = head;
            while (curr->next != NULL)
            {
                curr= curr->next;
            }
        curr -> next= ptr;
    }
 }

void insertStudent ()
 {
    stud* ptr = (stud*) malloc (sizeof(stud));
        cout<<"enter Student ID"<< "\n";
        cin >> ptr->SID;
        ptr -> next=NULL;
        cout<<"enter Course ID you want to be enrolled"<< "\n";
        cin >> ptr->COID;

        course* check = head;
        while (check!=NULL)
        {
            if (ptr->COID==check->CID)
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
            cout<<"enter valid course ID"<<"\n";
            delete ptr;
        }
        
        else if (check->start==NULL)
        {
            check->start=ptr; 
            cout<<"Enrolled"<<"\n";
              
        }
        else
        {
            stud* temp = check->start;
            while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        cout << "Enrolled and added\n";
        }
 }        
  
void printCourse()
 {
    if (head == NULL)
    {
        cout<<"list is ALL empty"<<"\n";
    }
    else
    {
        course* curr = head;
        while (curr!=NULL)
        {         
            cout<<"Course ID is  :  "<<curr->CID << "\n" ;
               stud* temp = curr->start;
            while (temp != NULL) {
                cout << "Enrolled Student IDs: " << temp->SID << "\n";
                temp = temp->next;
            }
            curr = curr->next;   
        } 
    }
 }
 void Delete()
 {
    if (head == NULL)
    {
        cout<<"No Course Entered"<<"\n";
    }
    else
    {
        int todel;
        cout<<"enter course ID number to be deleted:"<< "\n";
        cin>>todel;
        course* curr = head;
        if (todel == head->CID)
        {
        head = head->next;
        while (curr->start!= NULL)
        {
            stud* temp=curr->start;
            curr->start=curr->start->next;
            free(temp);
        }
        free(curr);
        cout<<"successfully deleted"<<"\n";  
        }
        else
        {
            course* prev = head;
            curr = head->next;
            while (curr!= NULL)
            {
                if (curr->CID== todel)
                {
                    prev->next = curr->next;
                     while (curr->start!= NULL)
                {
                    stud* temp=curr->start;
                    curr->start=curr->start->next;
                    free(temp);
                }
                    free(curr);
                    cout<<"successfully deleted"<<"\n";
                    break;
                }
                //prev = curr;
                curr=curr->next;
                prev=prev->next;
            }
            if (curr == NULL)
            {
                cout<<"record not found"<<"\n";
            }    
        }
    }
 }


 int main()
    {
        int a;
        cout << "if you want to enter Course ID press 1" << "\n";
        cout << "if you want to enter Student ID press 2" << "\n";
        cout << "if you want to print Courses press 3" << "\n";
        cout << "if you want to delete a course press 4" << "\n";
        cout << "if you want to end press 5" << "\n";
        cin>>a;
        while (a==1 || a==2 || a==3 || a==4 )
        {
            if (a==1)
            {
                insertCourse ();
            }
        
            else if (a==2)
            {
                insertStudent();
            }
            else if (a==3)
            {
                printCourse();
            }
            else if (a==4)
            {
                Delete();
            }
            
            // else if (a==4)
            // {
            //     printStudent();
            // }
            // else if (a==5)
            // {
            //     DeleteAll(&head);   
            // }
            
            
            else if (a==5)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "if you want to enter Course ID press 1" << "\n";
            cout << "if you want to enter Student ID press 2" << "\n";
            cout << "if you want to print Courses press 3" << "\n";
            cout << "if you want to delete a course press 4" << "\n";
            cout << "if you want to end press 5" << "\n";
            cin>>a;
            while (a<1 || a>6)
            {
                cout<<"invalid key entered"<<"\n";
            cout << "if you want to enter Course ID press 1" << "\n";
            cout << "if you want to enter Student ID press 2" << "\n";
            cout << "if you want to print Courses press 3" << "\n";
            cout << "if you want to delete a course press 4" << "\n";
            cout << "if you want to end press 5import-mod" << "\n";
            cin>>a;
            }    
        }
           
        return 0;
    }