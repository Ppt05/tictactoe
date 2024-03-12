#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p;
 cout << "Dia chi cua bien p: " << &p << endl;
    cout << "Dia chi cua truong x: " << &(p.x) << endl;
    cout << "Dia chi cua truong y: " << &(p.y) << endl;

    return 0;
}
/*Nhận xét:
        - Địa chỉ của p.x và p.y là khác nhau => mỗi trường trong struct đều được lưu ở một vị trí riêng biệt
        - Địa chỉ của p.x sẽ có địa chỉ thấp hơn p.y => phản ánh thứ tự khai báo trong struct
        - Ngoài ra, cũng sẽ thấy rằng địa chỉ của biến p (địa chỉ của cấu trúc) sẽ giống với địa chỉ của trường x.
        Điều này là do x là trường đầu tiên trong cấu trúc, do đó địa chỉ của p sẽ trỏ đến vị trí bắt đầu của cấu trúc, tức là vị trí của trường x.
    */

