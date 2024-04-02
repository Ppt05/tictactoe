#include <iostream>
using namespace std;

// Hàm sử dụng tham trị (pass-by-value)
void passByValue(int x) {
    cout << &x << endl;
}

// Hàm sử dụng tham chiếu (pass-by-reference)
void passByReference(int &y) {
    cout << &y << endl;
}

int main() {
    int a = 5;

    // In địa chỉ của biến a
    cout << "Địa chỉ của biến a trong hàm main: " << &a << endl;
    passByValue(a);
    passByReference(a);


    return 0;
}
 // Nhận xét:
    // Khi truyền đối số bằng giá trị (pass-by-value), một bản sao của giá trị của biến a được tạo ra và truyền vào hàm.
    // Do đó, địa chỉ của biến trong hàm sẽ khác với địa chỉ của biến trong hàm gọi (main).
    // Khi truyền đối số bằng tham chiếu (pass-by-reference), đối số và tham biến sẽ trỏ đến cùng một vị trí trong bộ nhớ, do đó có cùng địa chỉ.

