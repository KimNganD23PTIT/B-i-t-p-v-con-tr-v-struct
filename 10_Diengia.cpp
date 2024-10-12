#include <iostream>
#include <string>
using namespace std;

// Định nghĩa cấu trúc Speaker để lưu trữ thông tin của mỗi diễn giả
struct Speaker {
    string name;       // Tên diễn giả
    string phone;      // Số điện thoại
    string topic;      // Chủ đề bài phát biểu
    double fee;        // Phí diễn thuyết
};

// Hàm nhập thông tin diễn giả
void inputSpeaker(Speaker &speaker) {
    cout << "Nhập tên diễn giả: ";
    getline(cin, speaker.name);
    
    cout << "Nhập số điện thoại: ";
    getline(cin, speaker.phone);
    
    cout << "Nhập chủ đề bài phát biểu: ";
    getline(cin, speaker.topic);
    
    cout << "Nhập phí diễn thuyết: ";
    cin >> speaker.fee;
    cin.ignore();  // Xóa ký tự newline còn lại trong bộ đệm
}

// Hàm hiển thị thông tin diễn giả
void displaySpeaker(const Speaker &speaker) {
    cout << "Tên: " << speaker.name << endl;
    cout << "Số điện thoại: " << speaker.phone << endl;
    cout << "Chủ đề: " << speaker.topic << endl;
    cout << "Phí diễn thuyết: " << speaker.fee << endl;
}

int main() {
    const int NUM_SPEAKERS = 5;  // Số lượng diễn giả có thể quản lý
    Speaker speakers[NUM_SPEAKERS];  // Mảng lưu trữ danh sách các diễn giả

    int choice;
    do {
        cout << "\nMENU QUẢN LÝ DIỄN GIẢ" << endl;
        cout << "1. Nhập thông tin diễn giả" << endl;
        cout << "2. Hiển thị thông tin diễn giả" << endl;
        cout << "3. Thoát" << endl;
        cout << "Lựa chọn: ";
        cin >> choice;
        cin.ignore();  // Xóa ký tự newline trong bộ đệm

        switch (choice) {
            case 1: {
                int index;
                cout << "Nhập số thứ tự diễn giả (0 - " << NUM_SPEAKERS - 1 << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 0 && index < NUM_SPEAKERS) {
                    inputSpeaker(speakers[index]);
                } else {
                    cout << "Chỉ số không hợp lệ!" << endl;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Nhập số thứ tự diễn giả (0 - " << NUM_SPEAKERS - 1 << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 0 && index < NUM_SPEAKERS) {
                    displaySpeaker(speakers[index]);
                } else {
                    cout << "Chỉ số không hợp lệ!" << endl;
                }
                break;
            }
            case 3:
                cout << "Thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
    } while (choice != 3);

    return 0;
}
