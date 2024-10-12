#include <iostream>
#include <vector>

using namespace std;

void locMang(int *arr,int n,int k)
{
    vector<int> L;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)%k==0)
        {
            L.push_back(*(arr+i));
        }
    }
    cout<<"mảng mới chứa các giá trị trong mảng gốc là bội số của tham số thứ ba: ";
    for(int i=0;i<L.size();i++)
    {
        cout<<L[i]<<" ";
    }
}


int main()
{
    system("chcp 65001");
    int n,k;
    cout<<"Nhập kích thước mảng: ";
    cin>>n;
    int *arr= new int[n];
    cout<<endl;
    cout<<"Nhập mảng số nguyên: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Nhập một số nguyên: ";
    cin>>k;
    locMang(arr,n,k);
}