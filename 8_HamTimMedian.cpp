#include <iostream>
#include <algorithm> 

using namespace std;

double findMedian(int arr[], int size) 
{
    sort(arr, arr + size);

    if (size % 2 == 0) 
    {
        int midIndex1 = size / 2 - 1;  
        int midIndex2 = size / 2;     
        return (arr[midIndex1] + arr[midIndex2]) / 2.0;
    }
     else 
    {
        int midIndex = size / 2;
        return arr[midIndex];
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    double median = findMedian(arr, size);
    cout << "Median là: " << median << endl;

    return 0;
}
