#include <iostream>
#include <string>
using namespace std;


void sapXepDiem(float* diem, int soLuong, string* names)
{
    float temp=0.0;
    string s;
    for(int i=0;i<soLuong-1;++i)
    {
        for(int j=i+1;j<soLuong;++j)
        {
            if(*(diem+i)>*(diem+j))
            {
               temp = *(diem + i);
               s=*(names+i);
                *(diem + i) = *(diem + j);
                *(names+i)=*(names+j);
                *(diem + j) = temp;
                *(names+j)=s;
            }
        }
    }
}

int main() 
{
    int soLuong;

    do 
    {
        cout << "Nhap so luong hoc sinh: ";
        cin >> soLuong;
        if (soLuong <= 0) 
        {
            cout << "So luong diem phai la so duong. Vui long nhap lai.\n";
        }
    } while (soLuong <= 0);
    string* names = new string[soLuong];
    float* diem = new float[soLuong];
    for (int i = 0; i < soLuong; ++i) 
    {
        do {
            cout<<"Nhap ten hoc sinh: ";
            cin>>*(names+i);
            cout << "Nhap diem cua " << *(names+i) << ": ";
            cin >> *(diem + i);
            if (*(diem + i) < 0) {
                cout << "Diem khong duoc am. Vui long nhap lai.\n";
            }
        } while (*(diem + i) < 0);
    }
    sapXepDiem(diem, soLuong, names);
    cout << "\nDanh sach hoc sinh sau khi sap xep theo diem:\n";
    for (int i = 0; i < soLuong; ++i)
    {
        cout<<*(names+i)<<": ";
        cout << *(diem + i) <<endl;
    }
    delete[] diem;
    delete[] names;

    return 0;
}
