#include <iostream>
using namespace std;
#include <algorithm>

 void searchvalue(int arr[],int l)
 {
    int value;
    cout<<"enter a value to be searched "<<"\n";
    cin>> value;
    int index=value % l;
    int hold=index;
     while (arr[index]!=value)
        {   
            int i=1;
            index=index+i;
             if (index==l)
            {
                index=0;
            }
            if (index==hold)
            {
                cout<<"no record found"<<"\n";
                break;
            }
        }
if (arr[index]==value)
{
      cout<<"value entered is "<< value<< "\n"<<"it is found at index number :  "<< index<<"\n";
 } 

 }  
 
 void insertvalue(int arr[],int l)
 {
    int value;
    cout<<"enter a value to be enter"<<"\n";
    cin>> value;
    int index=value % l;
     int hold=index;
    while (arr[index]!=-1)
        {   int i=1;
            index=index+i;
             if (index==l)
            {
                index=0;
            }
            if (index==hold)
            {
                cout<<"no empty space left"<<"\n";
                break;
            }
       }
if (arr[index]==-1)
{
     arr[index]=value;
      cout<<"value entered at "<< index<< "\n"<<"value is  :  "<< arr[index]<<"\n";
 } 
}
void printlist(int list[],int lengthoflist)
{
    
    for (int i = 0; i < lengthoflist; i++)
    {
        cout<<i<<"    "<<list[i]<<"\n";
    }
}

   
 int main()
    {
        int l;
        cout<<"enter length of array "<<"\n";
        cin>>l;
        int arr[l];
        for (int i = 0; i < l; i++)
        {
            arr[i]={-1};
            // cout<<i<<"    "<<arr[i]<<"\n";
        }
        cout<<"array created of length:"<<l<<"\n";
         int a;
        cout << "press 1 to insert a value" << "\n";
        cout << "press 2 to search a value" << "\n";
        cout << "press 3 to print the list" << "\n";
        cout << "press 4 to end" << "\n";
        cin>>a;
        while (a==1 || a==2 || a==3 || a==4)
        {
             if (a==1)
            {
                insertvalue(arr,l);
            }
            else if (a==2)
            {
                searchvalue(arr, l);
            } 
            else if (a==3)
            {
                printlist(arr,l);
            }
                    
            else if (a==4)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;

                break;
            }
              
            cout << "press 1 to insert a value" << "\n";
            cout << "press 2 to search a value" << "\n";
            cout << "press 3 to print list" << "\n";
            cout << "press 4 to end program" << "\n";
            cin>>a;
            while (a<1 || a>4)
            {
                cout<<"invalid key entered"<<"\n";
                break;
            }    
        }
           
        return 0;
    }