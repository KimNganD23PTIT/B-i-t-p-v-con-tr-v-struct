#include <iostream>
#include <string>

using namespace std;

struct MovieData
{
    string phim;
    string daoDien;
    int namPhatHanh;
    int thoiLuong;
    float chiPhisx;
    float doanhThu;
};

void display(const MovieData &movie)
{
    cout<<"Tên phim: "<<movie.phim<<endl;
    cout<<"Đạo diễn: "<<movie.daoDien<<endl;
    cout<<"Năm phát hành: "<<movie.namPhatHanh<<endl;
    cout<<"Thời lượng: "<<movie.thoiLuong<<endl;
    if(movie.doanhThu>=movie.chiPhisx)
    {
        cout<<"Lợi nhuận: $" <<movie.doanhThu-movie.chiPhisx<<endl;
    }
    else
    {
        cout<<"Thua lỗ: $" <<movie.chiPhisx-movie.doanhThu<<endl;
    }
    cout << "---------------------------" << endl;
}

int main()
{
    system("chcp 65001");
   MovieData movie1={"The Godfather", "Francis Ford Coppola", 1972, 175,6.0,137};
   MovieData movie2={"Inception", "Christopher Nolan", 2010, 148,160.0,830};
   display(movie1);
   display(movie2);
}