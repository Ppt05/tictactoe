/* Tham số hàm. Viết chương trình thử nghiệm truyền tham số kiểu Point vào hàm theo hai kiểu truyền tham trị và truyền tham biến. Hãy dùng hàm main() để thử nghiệm sự khác nhau giữa hiệu ứng truyền tham trị và tham biến là struct và tham trị tham biến là thành viên của struct.
*/
#include <iostream>
using namespace std;


struct Point {
    int x;
    int y;
};
void modify_point_by_value(Point p) {
    p.x = 3;
    p.y = 2;
   cout << "Gia tri sau khi thay doi trong ham modify_point_by_value: (" << p.x << ", " << p.y << ")" << endl;
}

void modify_point_by_reference(Point& p) {
    p.x = 3;
    p.y = 2;
  cout << "Gia tri sau khi thay đoi trong hàm modify_point_by_reference: (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point p = {5, 7};

    cout << p.x << ", " << p.y << endl;


    modify_point_by_value(p);
    cout << "Gia tri sau khi goi ham modify_point_by_value: (" << p.x << ", " << p.y << ")" << endl;


    modify_point_by_reference(p);
    cout << "Gia tri sau khi goi ham modify_point_by_reference: (" << p.x << ", " << p.y << ")" << endl;

    return 0;
}
