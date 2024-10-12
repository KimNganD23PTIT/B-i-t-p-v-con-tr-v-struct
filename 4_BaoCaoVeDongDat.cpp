#include <iostream>
#include <string>

using namespace std;


struct Earthquake 
{
    string name;        
    string location;
    int year;
    double magnitude;
    int deaths;
};

int main() {
    const int NUM_EARTHQUAKES = 3;
    Earthquake earthquakes[NUM_EARTHQUAKES];

    for (int i = 0; i < NUM_EARTHQUAKES; ++i) {
        cout << "Nhập thông tin cho trận động đất thứ " << i + 1 << ":\n";
        cout << "Tên trận động đất: ";
        getline(cin, earthquakes[i].name);
        cout << "Vị trí xảy ra: ";
        getline(cin, earthquakes[i].location);
        cout << "Năm xảy ra: ";
        cin >> earthquakes[i].year;
        cout << "Độ lớn theo thang Richter: ";
        cin >> earthquakes[i].magnitude;
        cout << "Số người thiệt mạng: ";
        cin >> earthquakes[i].deaths;
        cin.ignore();
        cout << endl;
    }

    cout << "Thông tin về các trận động đất:\n";
    for (int i = 0; i < NUM_EARTHQUAKES; ++i) {
        cout << "Trận động đất " << i + 1 << ":\n";
        cout << "Tên: " << earthquakes[i].name << endl;
        cout << "Vị trí: " << earthquakes[i].location << endl;
        cout << "Năm xảy ra: " << earthquakes[i].year << endl;
        cout << "Độ lớn: " << earthquakes[i].magnitude << endl;
        cout << "Số người thiệt mạng: " << earthquakes[i].deaths << endl;
        cout << endl;
    }

    return 0;
}
