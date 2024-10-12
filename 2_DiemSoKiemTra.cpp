#include <iostream>

using namespace std;


void sapXepDiem(float* diem, int soLuong) {
    float temp=0.0;
    for(int i=0;i<soLuong-1;++i)
    {
        for(int j=i+1;j<soLuong;++j)
        {
            if(*(diem+i)>*(diem+j))
            {
               temp = *(diem + i);
                *(diem + i) = *(diem + j);
                *(diem + j) = temp;
            }
        }
    }
}

float tinhDiemTrungBinh(float* diem, int soLuong) {
    float tong = 0.0;
    for (int i = 0; i < soLuong; ++i) {
        tong += *(diem + i);
    }
    return tong / soLuong;
}

int main() {
    int soLuong;

    do {
        cout << "Nhap so luong diem kiem tra: ";
        cin >> soLuong;
        if (soLuong <= 0) {
            cout << "So luong diem phai la so duong. Vui long nhap lai.\n";
        }
    } while (soLuong <= 0);
    float* diem = new float[soLuong];
    for (int i = 0; i < soLuong; ++i) {
        do {
            cout << "Nhap diem thu " << i + 1 << ": ";
            cin >> *(diem + i);
            if (*(diem + i) < 0) {
                cout << "Diem khong duoc am. Vui long nhap lai.\n";
            }
        } while (*(diem + i) < 0);
    }
    sapXepDiem(diem, soLuong);

    float diemTrungBinh = tinhDiemTrungBinh(diem, soLuong);
    cout << "\nDanh sach diem sau khi sap xep tang dan:\n";
    for (int i = 0; i < soLuong; ++i) {
        cout << *(diem + i) << " ";
    }
    cout << "\nDiem trung binh: " << diemTrungBinh <<endl;
    delete[] diem;

    return 0;
}
