#include <iostream>
#include <string>

using namespace std;

struct Quote 
{
    string author;      
    string content;
    int likes;
};


void displayQuote(const Quote &quote) {
    cout << "Thông tin về câu trích dẫn:\n";
    cout << "Người sáng tác: " << quote.author << endl;
    cout << "Nội dung: \"" << quote.content << "\"" << endl;
    cout << "Số lượt thích: " << quote.likes << endl;
}

int main()
{

    Quote myQuote;

    cout << "Nhập thông tin về câu trích dẫn:\n";
    cout << "Người sáng tác: ";
    getline(cin, myQuote.author);
    cout << "Nội dung của câu trích dẫn: ";
    getline(cin, myQuote.content);
    cout << "Số lượt thích: ";
    cin >> myQuote.likes;
    cout << endl;
    displayQuote(myQuote);
}
