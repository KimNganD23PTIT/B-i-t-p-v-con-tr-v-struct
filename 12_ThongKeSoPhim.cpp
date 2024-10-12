#include <iostream>
#include <algorithm>

using namespace std;

float trungBinh(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=*(arr+i);
    }
    return sum/n;
}

float Median(int *arr,int n)
{
    sort(arr,arr+n);

        if(n%2==0)
        {
            int mid_index_1=n/2;
            int mid_index_2=n/2-1;
            return (*(arr+mid_index_1)+*(arr+mid_index_2))/2;
        }
        else
        {
            int mid_index = n/2;
            return *(arr+mid_index);
        }

}

int Mode(int *arr,int n)
{
    int c=0,mode=-1;
    int maxCount=0;
    for(int i=0;i<n;i++)
    {
        c=0;
        for(int j=i;j<n;j++)
        {
            if(*(arr+i)==*(arr+j))
            {
                c++;
            }
        }
        if(maxCount<c)
        {
            maxCount=c;
            mode=*(arr+i);
        }
    }
    if(maxCount==1)
    {
        return -1;
    }
    return mode;

}

int main()
{
    system("chcp 65001");
    int n;
    int *arr = new int[n];
    do
    {
    std::cout<<"Nhập số sinh viên được khảo sát: ";
    cin>>n;
     if(n<=0)
    {
        std::cout<<"vui lòng nhập lại!\n";
    }
    }while(n<=0);
    
    std::cout<<"Số phim sinh viên đã xem: ";
    for(int i=0;i<n;i++)
    {
        do
        {
            cin>>arr[i];
            if(arr[i]<0)
            {
                std::cout<<"Số phim không được âm.Vui lòng nhập lại!";
            }
        } while (arr[i]<0);
        
        
    }
    std::cout<<"Trung bình số phim sinh viên xem: "<<trungBinh(arr,n)<<endl;
    std::cout<<"giá trị median: "<<Median(arr,n)<<endl;
    if(Mode(arr,n)>1)
    {
    std::cout<<"giá trị số phim mà sinh viên xem nhiều nhất: "<<Mode(arr,n);
    }
    else if(Mode(arr,n)==-1)
    {
        std::cout<<"không có giá trị nào xuất hiện nhiều hơn 1 lần";
    }

}