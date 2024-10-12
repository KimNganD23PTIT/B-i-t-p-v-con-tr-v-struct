#include <iostream>

using namespace std;

int findMode(int* arr, int size) 
{
    int maxCount = 0;
    int mode = -1;

    for (int* ptr1 = arr; ptr1 < arr + size; ptr1++) 
    {
        int count = 0;

        for (int* ptr2 = arr; ptr2 < arr + size; ptr2++) 
        {
            if (*ptr1 == *ptr2) 
            {
                count++;
            }
        }

        if (count > maxCount) 
        {
            maxCount = count;
            mode = *ptr1;
        }
    }
    if (maxCount == 1) 
    {
        return -1;
    }

    return mode;
}

int main() 
{
    int arr[] = {1, 2, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int mode = findMode(arr, size);
    
    if (mode == -1) 
    {
        cout << "Không có mode trong mảng." << endl;
    } else {
        cout << "Mode của mảng là: " << mode << endl;
    }

    return 0;
}
