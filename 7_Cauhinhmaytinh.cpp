#include <iostream>
#include <string>
using namespace std;

// Khai báo cấu trúc lưu trữ thông tin về cấu hình máy tính
struct Computer {
    float clockSpeed;       // Tốc độ xung nhịp (GHz)
    int cores;              // Số lõi CPU
    int ram;                // Dung lượng RAM (GB)
    int hardDrive;          // Dung lượng ổ cứng (GB)
    float performanceScore; // Điểm đánh giá hiệu suất
    float price;            // Giá của máy tính (USD)
};

// Hàm nhập thông tin cấu hình máy tính
void inputComputer(Computer &comp) {
    cout << "Nhập tốc độ xung nhịp của bộ xử lý (GHz): ";
    cin >> comp.clockSpeed;
    cout << "Nhập số lõi của CPU: ";
    cin >> comp.cores;
    cout << "Nhập dung lượng RAM (GB): ";
    cin >> comp.ram;
    cout << "Nhập dung lượng ổ cứng (GB): ";
    cin >> comp.hardDrive;
    cout << "Nhập điểm đánh giá hiệu suất: ";
    cin >> comp.performanceScore;
    cout << "Nhập giá của máy tính (USD): ";
    cin >> comp.price;
}

// Hàm hiển thị thông tin cấu hình máy tính
void displayComputer(const Computer &comp) {
    cout << "\n--- Thông tin cấu hình máy tính ---" << endl;
    cout << "Tốc độ xung nhịp: " << comp.clockSpeed << " GHz" << endl;
    cout << "Số lõi CPU: " << comp.cores << endl;
    cout << "Dung lượng RAM: " << comp.ram << " GB" << endl;
    cout << "Dung lượng ổ cứng: " << comp.hardDrive << " GB" << endl;
    cout << "Điểm đánh giá hiệu suất: " << comp.performanceScore << endl;
    cout << "Giá máy tính: " << comp.price << " USD" << endl;
}

int main() {
    system("chcp 65001");
    Computer myComputer;

    // Nhập thông tin máy tính
    inputComputer(myComputer);

    // Hiển thị thông tin cấu hình máy tính
    displayComputer(myComputer);

    return 0;
}
