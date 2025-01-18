#include <bits/stdc++.h>
using namespace std;

void arr_rev_recur(int arr[],int ft,int lst)
{
    int x;
    if(ft<lst)
    {
        x=arr[ft];
        arr[ft]=arr[lst];
        arr[lst]=x;
        arr_rev_recur(arr,ft+1,lst-1);
    }
    
}


int main()
{
    int n;
    cout<<"Enter the size of the array = ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter = ";
        cin>>arr[i];
    }

    cout<<"Original array is :"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    arr_rev_recur(arr,0,n-1);

    cout<<"Reverse of the array is :"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}