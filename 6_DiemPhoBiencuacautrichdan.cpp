#include <iostream>
#include <string>

using namespace std;

struct Quote 
{
    string author;
    string content;
    int likes;
};


double calculateLikes(const Quote quotes[], int size, int &totalLikes) {
    totalLikes = 0;
    for (int i = 0; i < size; ++i) {

        if (quotes[i].likes < 0) {
            cout << "Lỗi: Số lượt thích không thể là số âm!\n";
            return -1;
        }
        totalLikes += quotes[i].likes;
    }
    return static_cast<double>(totalLikes) / size;
}

void displayPopularQuotes(const Quote quotes[], int size, double averageLikes, int totalLikes) {
    cout << "\nCác câu trích dẫn phổ biến hơn mức trung bình (" << averageLikes << " lượt thích):\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        if (quotes[i].likes > averageLikes) {
            double likePercentage = (static_cast<double>(quotes[i].likes) / totalLikes) * 100;
            cout << "Người sáng tác: " << quotes[i].author << "\n";
            cout << "Nội dung: \"" << quotes[i].content << "\"\n";
            cout << "Lượt thích: " << quotes[i].likes << "\n";
            cout << "Phần trăm lượt thích: " << likePercentage << "%\n";
            cout << "--------------------------------------------------\n";
        }
    }
}

int main() 
{

    const int numQuotes = 3;
    Quote quotes[numQuotes];

    for (int i = 0; i < numQuotes; ++i) {
        cout << "Nhập thông tin về câu trích dẫn thứ " << i + 1 << ":\n";
        cout << "Người sáng tác: ";
        getline(cin, quotes[i].author);
        cout << "Nội dung của câu trích dẫn: ";
        getline(cin, quotes[i].content);
        do {
            cout << "Số lượt thích: ";
            cin >> quotes[i].likes;
            if (quotes[i].likes < 0) {
                cout << "Lỗi: Số lượt thích không thể là số âm. Vui lòng nhập lại.\n";
            }
        } while (quotes[i].likes < 0);
        cin.ignore();
    }

    int totalLikes;
    double averageLikes = calculateLikes(quotes, numQuotes, totalLikes);

    if (averageLikes >= 0) 
    {
        displayPopularQuotes(quotes, numQuotes, averageLikes, totalLikes);
    }

    return 0;
}
