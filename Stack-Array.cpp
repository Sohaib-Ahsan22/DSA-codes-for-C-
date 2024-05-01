#include <iostream>
using namespace std;
void push(int array[],int &i,int l)
{
    cout<<"enter the value to be stored"<<"\n";
    int input;
    cin>>input;
    if (i>=l)
    {
        cout<<"stack overflow"<<"\n";
        
    }
    else
    {
        
    array[i++]=input;
    
    }
}
void pop(int array[],int &i, int l)
{
    if (i<=0)
    {
        cout<<"stack under flow"<<"\n";
        
    }
    else
    {
        cout<<array[--i]<<"\n";
    }
    

}
 int main()
    {
        int l;
        cout<<"enter length of stack "<<"\n";
        cin>>l;
        int arr[l];
        int a=0;
        int i=0;
        while (a >= 0 && a <= 3)
        {
            switch (a)
            {
            case 1:
                push (arr,i,l);
                break;
            case 2:
                pop(arr,i,l);
                break;
            }
            cout << "if you want to push value press 1" << "\n";
            cout << "if you want to pop value press 2" << "\n";
            cout << "if you want to  end program press 3" << "\n";
            cin>>a;
            if (a==3)
            {
                cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
                int c =0;
                cin>> c;
                cout << "Ratings  :  "<<c;
                break;
            }
            
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