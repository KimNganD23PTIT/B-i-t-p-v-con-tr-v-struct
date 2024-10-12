#include <iostream>
#include <vector>

using namespace std;

void NoiMang(int *arr1,int size1, int *arr2, int size2)
{
    vector<int> S;

    for(int i=0;i<size1;i++)
    {
        S.push_back(*(arr1+i));
    }
    for(int i=0;i<size2;i++)
    {
        S.push_back(*(arr2+i));
    }
    for(int i=0;i<S.size();i++)
    {
        cout<<S[i]<<" ";
    }
}

int main()
{
    int arr1[]={1,2,3,4};
    int arr2[]={5,6,7,8,9};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Mang thu nhat: ";
    for(int i=0;i<size1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Mang thu hai: ";
    for(int i=0;i<size2;i++)
    {
        cout<<arr2[i]<<" ";
    }

    cout<<endl;
    cout<<"Mang sau khi noi: ";
    NoiMang(arr1,size1,arr2,size2);
    
    return 0;
}