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

// Hàm nhập thông tin diễn giả với ràng buộc đầu vào
void inputSpeaker(Speaker &speaker) {
    // Nhập tên
    do {
        cout << "Nhập tên diễn giả: ";
        getline(cin, speaker.name);
        if (speaker.name.empty()) {
            cout << "Tên không được để trống, vui lòng nhập lại." << endl;
        }
    } while (speaker.name.empty());

    // Nhập số điện thoại
    do {
        cout << "Nhập số điện thoại: ";
        getline(cin, speaker.phone);
        if (speaker.phone.empty()) {
            cout << "Số điện thoại không được để trống, vui lòng nhập lại." << endl;
        }
    } while (speaker.phone.empty());

    // Nhập chủ đề bài phát biểu
    do {
        cout << "Nhập chủ đề bài phát biểu: ";
        getline(cin, speaker.topic);
        if (speaker.topic.empty()) {
            cout << "Chủ đề không được để trống, vui lòng nhập lại." << endl;
        }
    } while (speaker.topic.empty());

    // Nhập phí diễn thuyết với kiểm tra số âm
    do {
        cout << "Nhập phí diễn thuyết: ";
        cin >> speaker.fee;
        if (speaker.fee < 0) {
            cout << "Phí diễn thuyết không được là số âm, vui lòng nhập lại." << endl;
        }
    } while (speaker.fee < 0);
    
    cin.ignore();  // Xóa ký tự newline còn lại trong bộ đệm
}

// Hàm hiển thị thông tin một diễn giả
void displaySpeaker(const Speaker &speaker) {
    cout << "Tên: " << speaker.name << endl;
    cout << "Số điện thoại: " << speaker.phone << endl;
    cout << "Chủ đề: " << speaker.topic << endl;
    cout << "Phí diễn thuyết: " << speaker.fee << endl;
}

// Hàm hiển thị tất cả các diễn giả
void displayAllSpeakers(const Speaker speakers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nDiễn giả số " << i + 1 << ":" << endl;
        displaySpeaker(speakers[i]);
        cout << "------------------------------" << endl;
    }
}

// Hàm tìm kiếm diễn giả theo chủ đề
void searchSpeakerByTopic(const Speaker speakers[], int size, const string &keyword) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (speakers[i].topic.find(keyword) != string::npos) {
            // Nếu tìm thấy từ khóa trong chủ đề, hiển thị thông tin diễn giả
            cout << "\nDiễn giả số " << i + 1 << " có chủ đề khớp với từ khóa '" << keyword << "':" << endl;
            displaySpeaker(speakers[i]);
            found = true;
            cout << "------------------------------" << endl;
        }
    }

    if (!found) {
        cout << "\nKhông tìm thấy diễn giả nào với chủ đề chứa từ khóa '" << keyword << "'." << endl;
    }
}

int main() {
    const int NUM_SPEAKERS = 10;  // Số lượng diễn giả tối thiểu là 10
    Speaker speakers[NUM_SPEAKERS];  // Mảng lưu trữ danh sách các diễn giả
    
    // Khởi tạo mặc định cho mỗi diễn giả
    for (int i = 0; i < NUM_SPEAKERS; i++) {
        speakers[i].name = "Chưa có dữ liệu";
        speakers[i].phone = "Chưa có dữ liệu";
        speakers[i].topic = "Chưa có dữ liệu";
        speakers[i].fee = 0.0;
    }

    int choice;
    do {
        cout << "\nMENU QUẢN LÝ DIỄN GIẢ" << endl;
        cout << "1. Nhập thông tin diễn giả" << endl;
        cout << "2. Thay đổi thông tin diễn giả" << endl;
        cout << "3. Hiển thị tất cả thông tin diễn giả" << endl;
        cout << "4. Tìm kiếm diễn giả theo chủ đề" << endl;
        cout << "5. Thoát" << endl;
        cout << "Lựa chọn: ";
        cin >> choice;
        cin.ignore();  // Xóa ký tự newline trong bộ đệm

        switch (choice) {
            case 1: {
                for (int i = 0; i < NUM_SPEAKERS; i++) {
                    cout << "\nNhập thông tin cho diễn giả số " << i + 1 << ":" << endl;
                    inputSpeaker(speakers[i]);
                }
                break;
            }
            case 2: {
                int index;
                cout << "Nhập số thứ tự diễn giả muốn thay đổi (1 - " << NUM_SPEAKERS << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 1 && index <= NUM_SPEAKERS) {
                    cout << "\nThay đổi thông tin cho diễn giả số " << index << ":" << endl;
                    inputSpeaker(speakers[index - 1]);  // Chỉnh sửa thông tin
                } else {
                    cout << "Chỉ số không hợp lệ!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\nHiển thị thông tin tất cả các diễn giả:" << endl;
                displayAllSpeakers(speakers, NUM_SPEAKERS);
                break;
            }
            case 4: {
                string keyword;
                cout << "Nhập từ khóa để tìm kiếm theo chủ đề: ";
                getline(cin, keyword);
                searchSpeakerByTopic(speakers, NUM_SPEAKERS, keyword);
                break;
            }
            case 5:
                cout << "Thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng chọn lại!" << endl;
        }
    } while (choice != 5);

    return 0;
}
