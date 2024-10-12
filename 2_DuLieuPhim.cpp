#include <iostream>
#include <string>

using namespace std;

struct MovieData
{
    string phim;
    string daoDien;
    int namPhatHanh;
    int thoiLuong;
};

void display(const MovieData &movie)
{
    cout<<"Tên phim: "<<movie.phim<<endl;
    cout<<"Đạo diễn: "<<movie.daoDien<<endl;
    cout<<"Năm phát hành: "<<movie.namPhatHanh<<endl;
    cout<<"Thời lượng: "<<movie.thoiLuong<<endl;
    cout << "---------------------------" << endl;
}

int main()
{
    system("chcp 65001");
   MovieData movie1={"The Godfather", "Francis Ford Coppola", 1972, 175};
   MovieData movie2={"Inception", "Christopher Nolan", 2010, 148};
   display(movie1);
   display(movie2);
}