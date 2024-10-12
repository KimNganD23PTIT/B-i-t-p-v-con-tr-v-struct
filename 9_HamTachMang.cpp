#include <iostream>
#include <vector>

using namespace std;

void TachMang(int *arr,int size)
{  
   vector<int> A; 
    for(int i=0;i<size;i+=2)
    {

            A.push_back(*(arr+i));
            
    }
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }

}

int main()
{  

    int arr[]={1,2,10,9,8,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Mang truoc khi tach: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Mang sau khi tach: ";
    TachMang(arr,size);
  
}