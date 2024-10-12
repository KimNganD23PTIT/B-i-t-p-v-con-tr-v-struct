#include <iostream>

using namespace std;

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    cout<<"Byte ma mang chiem dung: "<<sizeof(A)<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"phan tu A["<<i<<"]: "<<A[i]<<" tai dia chi: "<<&A[i]<<endl;
    }

}