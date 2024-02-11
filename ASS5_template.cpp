#include<iostream>
using namespace std;
template<typename T>

void sort(T a[],int n)
{
    int min;
    T temp;

    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }

    cout<<"\nSorted array: ";
    for(int i=0;i<n;i++)
    {
    cout<<" "<<a[i];
    }
}
int main()
{
    int choice,n;
    int a[10];
    float b[10];
    do
    {
    cout<<"\n\n 1. Sort Integer : ";
    cout<<"\n 2. Sort Float : ";
    cout<<"\n 3. Exit : "<<endl;
    cout<<"\n Enter Choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            {
            cout<<"\nEnter Total Number Of Integer Elements:";
            cin>>n;
            cout<<"\nEnter Integer Elements:";
            for(int i=0;i<n;i++)
            {
            cin>>a[i];
            }
            sort<int>(a,n);
            break;
            }
        case 2:
            {
            cout<<"\nEnter Total Number Of Integer Elements:";
            cin>>n;
            cout<<"\nEnter Integer Elements:";
            for(int i=0;i<n;i++)
            {
            cin>>b[i];
            }
            sort<float>(b,n);
            break;
            }
        case 3:
            {
            cout<<"**********Program Exited Successfully**********"<<endl;
            exit(0);
            }


        default:
            {
            cout<<"\n Invalid";
            }
    }
    }
    while(choice!=4);
    return 0;
}
