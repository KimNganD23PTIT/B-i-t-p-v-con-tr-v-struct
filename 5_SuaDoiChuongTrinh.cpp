#include <iostream>

using namespace std;

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
      system("chcp 65001");
    int numDonations;
    cout << "Nhập số lượng đóng góp: ";
    cin >> numDonations;

    int *donations = new int[numDonations];
    cout << "Nhập các giá trị đóng góp:\n";
    for (int i = 0; i < numDonations; i++) {
        cout << "Giá trị đóng góp " << i + 1 << ": ";
        cin >> donations[i];
    }
    int **arrPtr = new int*[numDonations];

    for (int count = 0; count < numDonations; count++) {
        arrPtr[count] = &donations[count];
    }

    arrSelectSort(arrPtr, numDonations);

    cout << "Các giá trị đóng góp theo thứ tự tăng dần:\n";
    showArrPtr(arrPtr, numDonations);

    cout << "Các giá trị đóng góp theo thứ tự ban đầu:\n";
    showArray(donations, numDonations);

    delete[] donations;  
    delete[] arrPtr;

    return 0;
}

// Hàm sắp xếp mảng các con trỏ theo thứ tự tăng dần
void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minElem = arr[startScan];
        minIndex = startScan;
        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr[index]) < *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

// Hàm hiển thị mảng ban đầu
void showArray(const int arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

// Hàm hiển thị mảng theo thứ tự sắp xếp (qua các con trỏ)
void showArrPtr(int *arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}
