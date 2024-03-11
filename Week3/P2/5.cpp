/*Rect. Viết một struct Rect là kiểu dữ liệu đại diện cho hình chữ nhật.
 Rect có bốn thành viên dữ liệu x, y là tọa độ góc trên trái, w và h là chiều rộng, chiều cao của hình.
  Rect có hàm contains() nhận 01 tham số kiểu Point và trả về giá trị kiểu bool là true nếu point được
  cho nằm bên trong hình (tính cả viền), false nếu ngược lại. Hãy sử dụng const để đảm bảo hàm contains
   không sửa giá trị của điểm được truyền vào, và để các hàm này dùng được cho các hằng kiểu Rect.*/

   #include <bits/stdc++.h>
   using namespace std;
   struct Point{
   int x;
   int y;
   };
   struct Rect{
       int x,y;
       int w,h;
    bool constains(const Point& p){
    if( p.x >= x && p.x<= x+w &&p.y <=y && p.y >= y+h)
    {
        return true;
    }
    return false;

    }

   };


