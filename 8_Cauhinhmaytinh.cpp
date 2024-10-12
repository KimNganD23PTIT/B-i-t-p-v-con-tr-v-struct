#include <iostream>
#include <vector>
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
    
    // Kiểm tra điểm đánh giá hiệu suất phải >= 0
    do {
        cout << "Nhập điểm đánh giá hiệu suất (không âm): ";
        cin >> comp.performanceScore;
        if (comp.performanceScore < 0) {
            cout << "Điểm đánh giá không được âm. Vui lòng nhập lại.\n";
        }
    } while (comp.performanceScore < 0);
    
    // Kiểm tra giá phải >= 0
    do {
        cout << "Nhập giá của máy tính (USD, không âm): ";
        cin >> comp.price;
        if (comp.price < 0) {
            cout << "Giá không được âm. Vui lòng nhập lại.\n";
        }
    } while (comp.price < 0);
}

// Hàm hiển thị thông tin cấu hình máy tính
void displayComputer(const Computer &comp, int index) {
    cout << "\n--- Cấu hình máy tính #" << index + 1 << " ---" << endl;
    cout << "Tốc độ xung nhịp: " << comp.clockSpeed << " GHz" << endl;
    cout << "Số lõi CPU: " << comp.cores << endl;
    cout << "Dung lượng RAM: " << comp.ram << " GB" << endl;
    cout << "Dung lượng ổ cứng: " << comp.hardDrive << " GB" << endl;
    cout << "Điểm đánh giá hiệu suất: " << comp.performanceScore << endl;
    cout << "Giá máy tính: " << comp.price << " USD" << endl;
}

// Hàm hiển thị toàn bộ danh sách các cấu hình máy tính
void displayAllComputers(const vector<Computer> &computers) {
    if (computers.empty()) {
        cout << "\nChưa có cấu hình máy tính nào trong hệ thống.\n";
        return;
    }
    for (size_t i = 0; i < computers.size(); ++i) {
        displayComputer(computers[i], i);
    }
}

// Hàm thay đổi giá của một cấu hình máy tính
void changePrice(vector<Computer> &computers, int index) {
    if (index < 0 || index >= computers.size()) {
        cout << "Số thứ tự không hợp lệ!\n";
        return;
    }
    float newPrice;
    do {
        cout << "Nhập giá mới cho máy tính #" << index + 1 << " (không âm): ";
        cin >> newPrice;
        if (newPrice < 0) {
            cout << "Giá không được âm. Vui lòng nhập lại.\n";
        }
    } while (newPrice < 0);
    
    computers[index].price = newPrice;
    cout << "Giá của máy tính #" << index + 1 << " đã được cập nhật thành " << newPrice << " USD.\n";
}

int main() {
    vector<Computer> computers; // Danh sách các máy tính
    int choice;

    do {
        // Hiển thị menu cho người dùng
        cout << "\n--- Quản lý cấu hình máy tính ---\n";
        cout << "1. Thêm cấu hình máy mới\n";
        cout << "2. Thay đổi giá của cấu hình máy\n";
        cout << "3. Hiển thị tất cả cấu hình máy\n";
        cout << "0. Thoát\n";
        cout << "Chọn một tùy chọn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Thêm cấu hình máy mới
                Computer newComputer;
                inputComputer(newComputer);
                computers.push_back(newComputer);
                cout << "Cấu hình máy mới đã được thêm vào.\n";
                break;
            }
            case 2: {
                // Thay đổi giá của một cấu hình máy
                if (computers.empty()) {
                    cout << "Không có cấu hình máy nào để thay đổi giá.\n";
                    break;
                }
                
                int index;
                do {
                    cout << "Nhập số thứ tự của cấu hình máy muốn thay đổi giá (từ 1 đến " << computers.size() << "): ";
                    cin >> index;
                    if (index < 1 || index > computers.size()) {
                        cout << "Số thứ tự không hợp lệ. Vui lòng nhập lại.\n";
                    }
                } while (index < 1 || index > computers.size());
                
                changePrice(computers, index - 1);  // Giảm 1 để chuyển từ số thứ tự sang chỉ số mảng
                break;
            }
            case 3: {
                // Hiển thị tất cả cấu hình máy
                displayAllComputers(computers);
                break;
            }
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Tùy chọn không hợp lệ, vui lòng thử lại.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
