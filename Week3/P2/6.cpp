/* Ship. Viết một struct Ship là kiểu dữ liệu đại diện cho một con tầu (ship). Mỗi ship có một biến thành viên là một
Rect để ghi tọa độ và kích thước của tầu, một biến thành viên id kiểu string là số hiệu của tầu.
Ngoài ra còn có thêm dx và dy là vận tốc hiện hành của tầu theo trục x và trục y.
Viết hàm move() của Ship với nhiệm vụ thay đổi vị trí của tầu theo vận tốc hiện hành (x += dx, y+= dy).
Viết hàm display(const Ship& ship) là hàm độc lập bên ngoài với nhiệm vụ hiển thị số hiệu và tọa độ của tầu.*/


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
   struct Ship{
       Rect rect;
       string id;
       int dx,dy;





   void move(){
       rect.x += dx;
       rect.y += dy;

   }
   };
   void display(const Ship& ship) {
    cout <<  ship.id ;
    cout << ship.rect.x << ship.rect.y  << endl;
}



