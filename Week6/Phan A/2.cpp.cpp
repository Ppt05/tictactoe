#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của số nguyên N
int factorial(int x) {
    // In giá trị và địa chỉ của tham số x
    cout << "x = " << x << " at " << &x << endl;

    if (x == 0 || x == 1)
        return 1;
    else
        return x * factorial(x - 1);
}

int main() {

    int N = 10;

    int result = factorial(N);


    cout << result << endl;

    /* Nhận xét về chuỗi giá trị được in ra màn hình:
     Khi chạy chương trình, các giá trị của tham số và địa chỉ của tham số đều được in ra màn hình.
     Các giá trị của tham số xuất hiện theo thứ tự giảm dần, đồng thời các địa chỉ của tham số tăng dần.
     Điều này phản ánh cách mà các biến địa phương được lưu trữ trong bộ nhớ theo ngăn xếp (stack frame)
    Tính kích thước của một stack frame cho hàm factorial:
     Kích thước của một stack frame cho hàm factorial bao gồm kích thước của các biến địa phương và kích thước của return address.
     Trong trường hợp này, mỗi stack frame bao gồm:
    - Kích thước của biến địa phương int (x)
     - Kích thước của return address (địa chỉ trở về sau khi gọi hàm factorial)
     Vậy kích thước của một stack frame cho hàm factorial sẽ phụ thuộc vào kích thước của biến int và kích thước của con trỏ trên hệ thống cụ thể.
    */
    return 0;
}
