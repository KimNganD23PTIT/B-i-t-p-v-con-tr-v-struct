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

// Hàm nhập thông tin ngày và giờ với các ràng buộc đầu vào
void inputDateTime(dateTime &dt) {
    // Nhập năm với ràng buộc không âm
    do {
        cout << "Nhập năm (>= 0): ";
        cin >> dt.year;
        if (dt.year < 0) {
            cout << "Năm không được là số âm. Vui lòng nhập lại." << endl;
        }
    } while (dt.year < 0);

    // Nhập tháng với ràng buộc từ 1 đến 12
    do {
        cout << "Nhập tháng (1-12): ";
        cin >> dt.month;
        if (dt.month < 1 || dt.month > 12) {
            cout << "Tháng không hợp lệ. Vui lòng nhập từ 1 đến 12." << endl;
        }
    } while (dt.month < 1 || dt.month > 12);

    // Nhập ngày với ràng buộc từ 1 đến 31 (có thể thêm điều kiện theo từng tháng)
    do {
        cout << "Nhập ngày (1-31): ";
        cin >> dt.day;
        if (dt.day < 1 || dt.day > 31) {
            cout << "Ngày không hợp lệ. Vui lòng nhập từ 1 đến 31." << endl;
        }
    } while (dt.day < 1 || dt.day > 31);

    // Nhập giờ với ràng buộc từ 0 đến 23
    do {
        cout << "Nhập giờ (0-23): ";
        cin >> dt.hour;
        if (dt.hour < 0 || dt.hour > 23) {
            cout << "Giờ không hợp lệ. Vui lòng nhập từ 0 đến 23." << endl;
        }
    } while (dt.hour < 0 || dt.hour > 23);

    // Nhập phút với ràng buộc từ 0 đến 59
    do {
        cout << "Nhập phút (0-59): ";
        cin >> dt.minute;
        if (dt.minute < 0 || dt.minute > 59) {
            cout << "Phút không hợp lệ. Vui lòng nhập từ 0 đến 59." << endl;
        }
    } while (dt.minute < 0 || dt.minute > 59);

    // Nhập giây với ràng buộc từ 0 đến 59
    do {
        cout << "Nhập giây (0-59): ";
        cin >> dt.second;
        if (dt.second < 0 || dt.second > 59) {
            cout << "Giây không hợp lệ. Vui lòng nhập từ 0 đến 59." << endl;
        }
    } while (dt.second < 0 || dt.second > 59);
}

// Hàm hiển thị thông tin ngày và giờ
void displayDateTime(const dateTime &dt) {
    cout << dt.year << "/" 
         << (dt.month < 10 ? "0" : "") << dt.month << "/" 
         << (dt.day < 10 ? "0" : "") << dt.day << " "
         << (dt.hour < 10 ? "0" : "") << dt.hour << ":"
         << (dt.minute < 10 ? "0" : "") << dt.minute << ":"
         << (dt.second < 10 ? "0" : "") << dt.second;
}

// Hàm so sánh hai đối tượng dateTime
// Trả về:
//   -1 nếu dt1 đến trước dt2
//    0 nếu hai thời điểm giống nhau
//    1 nếu dt2 đến trước dt1
int compareDateTime(const dateTime &dt1, const dateTime &dt2) {
    // So sánh từng trường: năm, tháng, ngày, giờ, phút, giây
    if (dt1.year != dt2.year) return dt1.year < dt2.year ? -1 : 1;
    if (dt1.month != dt2.month) return dt1.month < dt2.month ? -1 : 1;
    if (dt1.day != dt2.day) return dt1.day < dt2.day ? -1 : 1;
    if (dt1.hour != dt2.hour) return dt1.hour < dt2.hour ? -1 : 1;
    if (dt1.minute != dt2.minute) return dt1.minute < dt2.minute ? -1 : 1;
    if (dt1.second != dt2.second) return dt1.second < dt2.second ? -1 : 1;
    
    return 0; // Hai thời điểm giống nhau
}

// Hàm tìm thời điểm sớm hơn hoặc trả về thông báo "Ngày giờ giống nhau"
dateTime findEarlierDateTime(const dateTime &dt1, const dateTime &dt2) {
    int result = compareDateTime(dt1, dt2);
    if (result == 0) {
        cout << "Ngày giờ giống nhau." << endl;
        return dt1; // Trả về bất kỳ thời điểm nào
    } else if (result < 0) {
        return dt1; // Thời điểm thứ nhất đến trước
    } else {
        return dt2; // Thời điểm thứ hai đến trước
    }
}

int main() {
    dateTime dt1, dt2;

    cout << "Nhập ngày giờ thứ nhất:\n";
    inputDateTime(dt1);

    cout << "\nNhập ngày giờ thứ hai:\n";
    inputDateTime(dt2);

    // So sánh và tìm thời điểm sớm hơn
    dateTime earlier = findEarlierDateTime(dt1, dt2);

    // Hiển thị thời điểm sớm hơn hoặc thông báo
    cout << "\nThời điểm sớm hơn là: ";
    displayDateTime(earlier);
    cout << endl;

    return 0;
}
