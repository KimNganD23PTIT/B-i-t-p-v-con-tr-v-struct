#include <iostream>
using namespace std;

// Cấu trúc dateTime để lưu trữ ngày và giờ
struct dateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Hàm nhập thông tin ngày và giờ
void inputDateTime(dateTime &dt) {
    cout << "Nhập năm: ";
    cin >> dt.year;
    
    cout << "Nhập tháng (1-12): ";
    cin >> dt.month;
    while (dt.month < 1 || dt.month > 12) {
        cout << "Tháng không hợp lệ, vui lòng nhập lại (1-12): ";
        cin >> dt.month;
    }
    
    cout << "Nhập ngày (1-31): ";
    cin >> dt.day;
    while (dt.day < 1 || dt.day > 31) { // Có thể cải tiến để kiểm tra số ngày hợp lệ theo từng tháng
        cout << "Ngày không hợp lệ, vui lòng nhập lại (1-31): ";
        cin >> dt.day;
    }
    
    cout << "Nhập giờ (0-23): ";
    cin >> dt.hour;
    while (dt.hour < 0 || dt.hour > 23) {
        cout << "Giờ không hợp lệ, vui lòng nhập lại (0-23): ";
        cin >> dt.hour;
    }

    cout << "Nhập phút (0-59): ";
    cin >> dt.minute;
    while (dt.minute < 0 || dt.minute > 59) {
        cout << "Phút không hợp lệ, vui lòng nhập lại (0-59): ";
        cin >> dt.minute;
    }

    cout << "Nhập giây (0-59): ";
    cin >> dt.second;
    while (dt.second < 0 || dt.second > 59) {
        cout << "Giây không hợp lệ, vui lòng nhập lại (0-59): ";
        cin >> dt.second;
    }
}

// Hàm hiển thị thông tin ngày và giờ
void displayDateTime(const dateTime &dt) {
    cout << dt.year << "/" 
         << (dt.month < 10 ? "0" : "") << dt.month << "/" 
         << (dt.day < 10 ? "0" : "") << dt.day << " "
         << (dt.hour < 10 ? "0" : "") << dt.hour << ":"
         << (dt.minute < 10 ? "0" : "") << dt.minute << ":"
         << (dt.second < 10 ? "0" : "") << dt.second << endl;
}

// Hàm so sánh hai đối tượng dateTime
int compareDateTime(const dateTime &dt1, const dateTime &dt2) {
    // So sánh năm
    if (dt1.year < dt2.year) return -1;
    if (dt1.year > dt2.year) return 1;

    // So sánh tháng
    if (dt1.month < dt2.month) return -1;
    if (dt1.month > dt2.month) return 1;

    // So sánh ngày
    if (dt1.day < dt2.day) return -1;
    if (dt1.day > dt2.day) return 1;

    // So sánh giờ
    if (dt1.hour < dt2.hour) return -1;
    if (dt1.hour > dt2.hour) return 1;

    // So sánh phút
    if (dt1.minute < dt2.minute) return -1;
    if (dt1.minute > dt2.minute) return 1;

    // So sánh giây
    if (dt1.second < dt2.second) return -1;
    if (dt1.second > dt2.second) return 1;

    // Nếu tất cả các trường đều bằng nhau
    return 0;
}

int main() {
    dateTime dt1, dt2;

    cout << "Nhập ngày giờ thứ nhất:\n";
    inputDateTime(dt1);

    cout << "\nNhập ngày giờ thứ hai:\n";
    inputDateTime(dt2);

    // Hiển thị hai ngày giờ đã nhập
    cout << "\nNgày giờ thứ nhất: ";
    displayDateTime(dt1);

    cout << "Ngày giờ thứ hai: ";
    displayDateTime(dt2);

    // So sánh hai ngày giờ
    int result = compareDateTime(dt1, dt2);
    if (result == 0) {
        cout << "\nCả hai ngày giờ đều bằng nhau." << endl;
    } else if (result < 0) {
        cout << "\nNgày giờ thứ nhất nhỏ hơn ngày giờ thứ hai." << endl;
    } else {
        cout << "\nNgày giờ thứ nhất lớn hơn ngày giờ thứ hai." << endl;
    }

    return 0;
}
