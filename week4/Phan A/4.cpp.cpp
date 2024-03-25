#include <iostream>
using namespace std;

int main() {
    // Khai báo mảng và các biến
    const int N = 5;
    char arr[N];
    char var1, var2, var3;

    // Truy cập ra ngoài mảng (đọc tràn)
    cout << "Đọc tràn mảng:" << endl;
    for (int i = -1; i <= N + 1; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;
    cout << "var3 = " << var3 << endl;

    // Ghi tràn mảng
    cout << "\nGhi tràn mảng:" << endl;
    for (int i = -1; i <= N + 1; ++i) {
        arr[i] = 'X';
    }

    // In giá trị của các biến được khai báo xung quanh mảng
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;
    cout << "var3 = " << var3 << endl;

    // Tràn mảng nhiều chiều
    cout << "\nTràn mảng nhiều chiều:" << endl;
    const int rows = 3, cols = 4;
    char arr2D[rows][cols];

    // Ghi tràn dòng đầu tiên của mảng hai chiều
    for (int j = 0; j <= cols + 1; ++j) {
        arr2D[0][j] = 'Y';
    }

    // In đầy đủ mảng ra màn hình
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
