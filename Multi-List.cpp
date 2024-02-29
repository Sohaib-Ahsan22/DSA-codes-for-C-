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
 stud* top=NULL;
void insertStudent ()
 {
    stud* ptr = (stud*) malloc (sizeof(stud));
        cout<<"enter Student ID"<< "\n";
        cin >> ptr->SID;
        ptr -> next=NULL;
        cout<<"enter Course ID you want to be enrolled"<< "\n";
        cin >> ptr->COID;

        course* check = head;
        while (ptr->COID!=check->CID)
        {
            check=check->next;
        }
        if (check->start==NULL)
        {
            check->start=ptr; 
            cout<<"Enrolled"<<"\n";  
        }
        else
        {
            while (check->start->next!=NULL)
            {
                check->start=check->start->next;
            }
            check->start->next=ptr;
            
        }
 }        
//     if (top == NULL)
//     {
//         top = ptr;
//     }
//     else
//     {
//         stud* curr = top;
//             while (curr->next != NULL)
//             {
//                 curr= curr->next;
//             }
//         curr -> next= ptr;
//     }
//  }

//  void search(Records** head)
//  {
//     if (*head == NULL)
//     {
//         cout<<"list is ALL empty"<<"\n";
//     }
//     else
//     {
//         int tosearch;
//         cout<<"enter roll number to be searched:"<< "\n";
//         cin>>tosearch;
//         Records* curr = *head;
//         bool found;
//         while (curr!=NULL)
//         {
//             if (curr-> Rno == tosearch)
//             {
//                 cout<<"detail of entered roll number is:      "<<"\n"<<"roll number  :    "<<curr->Rno << "\n" <<"GPA is  :     "<< curr ->GPA<<"\n";
//                 found = true;
//                 break;
//             }
//             else
//             {
//                 curr = curr->next;
//             } 
//         } 
//         if (found == false)
//         {
//             cout << "data not found"<< "\n" ;   
//         }
//     }
//  }

//  void print(Records** head)
//  {
//     if (*head == NULL)
//     {
//         cout<<"list is ALL empty"<<"\n";
//     }
//     else
//     {
//         Records* curr = *head;
//         while (curr!=NULL)
//         {
                    
//                 cout<<"roll number is  :  "<<curr->Rno << "\n" <<"GPA is    :    "<< curr ->GPA<< "\n";
//                 curr = curr->next;
            
//         } 
//     }
//  }
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
                cout<<curr->start->SID<<"\n";
                curr = curr->next;
            
        } 
    }
 }
 void printStudent()
 {
    if (top== NULL)
    {
        cout<<"list is ALL empty"<<"\n";
    }
    else
    {
        stud* curr = top;
        while (curr!=NULL)
        {
                    
                cout<<"Student ID is  :  "<<curr->SID << "\n" ;
                curr = curr->next;
            
        } 
    }
 }
//  void Delete(Records** head)
//  {
//     if (*head == NULL)
//     {
//         cout<<"list is ALL empty"<<"\n";
//     }
//     else
//     {
//         int todel;
//         cout<<"enter roll number to be deleted:"<< "\n";
//         cin>>todel;
//         Records* curr = *head;
//         if (todel == (*head)->Rno)
//         {
//         *head = (*head)->next;
//         free(curr);
//         cout<<"successfully deleted"<<"\n";  
//         }
//         else
//         {
//             Records* prev = *head;
//             curr = (*head)->next;
//             while (curr!= NULL)
//             {
//                 if (curr-> Rno == todel)
//                 {
//                     prev->next = curr->next;
//                     free(curr);
//                     cout<<"successfully deleted"<<"\n";
//                     break;
//                 }
//                 //prev = curr;
//                 curr=curr->next;
//                 prev=prev->next;
//             }
//             if (curr == NULL)
//             {
//                 cout<<"record not found"<<"\n";
//             }    
//         }
//     }
//  }
//  void DeleteAll(Records** head)
//  {
//     if (*head == NULL)
//     {
//         cout<<"list is already empty"<<"\n";
//     }
//     else{
//         Records* curr = *head;
//         while(curr!=NULL)
//         {
//             *head = (*head)->next;
//             free(curr);
//             curr= (*head);
//         }
//         cout<<"All DATA DELETED"<<"\n";
//     }
//  }

 int main()
    {
        int a;
        cout << "if you want to enter Course ID press 1" << "\n";
        cout << "if you want to enter Student ID press 2" << "\n";
        cout << "if you want to print Courses press 3" << "\n";
        cout << "if you want to print Students press 4" << "\n";
        cin>>a;
        while (a==1 || a==2 || a==3 || a==4 || a== 5 || a==6)
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
                printStudent();
            }
            // else if (a==5)
            // {
            //     DeleteAll(&head);   
            // }
            
            
            else if (a==6)
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