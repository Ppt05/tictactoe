/* Địa chỉ tham biến, tham trị. Viết chương trình thử nghiệm truyền tham số kiểu
Point vào hàm theo hai kiểu truyền tham trị và truyền tham biến. Hãy dùng phương pháp in địa chỉ của biến kiểu Point
để chứng tỏ rằng khi truyền tham trị ta có tham số là một bản sao của đối số (khác địa chỉ), còn khi truyền tham chiếu,
 ta có tham số và đối số chính là một biến (trùng địa chỉ). */

#include <bits/stdc++.h>
 using namespace std;
  struct Point {
  int x,y;
  };
  /*pass by value*/
void diachi( Point p){
cout << &p<< endl;
}
/* pass by reference */
void Diachi(Point& p){
    cout << &p<< endl;
}
int main(){
Point p;
cout << &p<< endl;
diachi(p);
Diachi(p);
return 0;
}
