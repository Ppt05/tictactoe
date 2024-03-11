 /*Viết một chương trình nhỏ để thử nghiệm struct Ship, tạo ra một số con tầu với tọa độ và tốc độ khác nhau. Dùng vòng lặp cho các con tầu di chuyển và hiển thị tọa độ của tầu. Ví dụ
while (loop < 10) {
    ship1.move(); ship2.move();
    display(ship1); display(ship2);
} */

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
    cout <<  ship.id<< endl ;
    cout << ship.rect.x << ship.rect.y  << endl;
}

int main() {
    Ship ship1;
    ship1.id = "Ship1";
    ship1.rect.x = 0;
    ship1.rect.y = 0;
    ship1.rect.w = 5;
    ship1.rect.h = 3;
    ship1.dx = 1;
    ship1.dy = 1;

    Ship ship2;
    ship2.id = "Ship2";
    ship2.rect.x = 10;
    ship2.rect.y = 5;
    ship2.rect.w = 4;
    ship2.rect.h = 2;
    ship2.dx = -1;
    ship2.dy = 2;

    int loop = 0;
    while (loop < 10) {
        ship1.move();
        ship2.move();
        display(ship1);
        display(ship2);
        loop++;
    }

    return 0;
}
