#include <bits/stdc++.h>
using namespace std;
struct Point{
int x;
int y;
};
void input_point(Point& p) {
  cin >> p.x;
  cin >> p.y;
}
Point mid_point(const Point& p1, const Point& p2){
Point mid;
mid.x=(p1.x+p2.x)/2;
mid.y=(p1.y+p2.y)/2;
return mid;
}
void print(Point& v) {
cout  << v.x << v.y ;
}

int main() {
    Point p1, p2;
    input_point(p1);
    input_point(p2);

    Point mid = mid_point(p1, p2);
    print(mid);


    return 0;
}
