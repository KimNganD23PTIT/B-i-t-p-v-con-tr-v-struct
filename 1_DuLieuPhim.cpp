#include <iostream>
#include <string>

using namespace std;

struct MovieData
{
    string title;
    string director;
    int releaseYear;
    int duration;
};

void displayMovieData(const MovieData &movie) 
{
    cout << "Thông tin về bộ phim:\n";
    cout << "Tên phim: " << movie.title << endl;
    cout << "Đạo diễn: " << movie.director << endl;
    cout << "Năm phát hành: " << movie.releaseYear << endl;
    cout << "Thời lượng: " << movie.duration << " phút" << endl;
}

int main() 
{
    system("chcp 65001");
    MovieData movie;

    cout << "Nhập thông tin về bộ phim:\n";
    cout << "Tên phim: ";
    getline(cin, movie.title);
    cout << "Đạo diễn: ";
    getline(cin, movie.director);
    cout << "Năm phát hành: ";
    cin >> movie.releaseYear;
    cout << "Thời lượng (tính bằng phút): ";
    cin >> movie.duration;

    cout << endl;
    displayMovieData(movie);

    return 0;
}
