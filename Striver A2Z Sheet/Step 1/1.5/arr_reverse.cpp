#include <bits/stdc++.h>
using namespace std;

void reversearr(int arr[],int  n)

{
    int  i,j;
    for(i=0;i<n/2;i++)
    {
        j=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=j;
    }
}


int main()
{
    int N;
    cout<<"Enter N = ";
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cout<<" Enter = ";
        cin>>arr[i];
    }
    reversearr(arr,N);
    cout<<endl;
    cout<<"Reverse Array is = ";
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}