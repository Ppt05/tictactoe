#include <bits/stdc++.h>
using namespace std;

void printMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0)); // Tạo ma trận kích thước n*n, tất cả các giá trị ban đầu là 0
    int num = 1;
    int r = 0, c = n / 2; // Bắt đầu từ hàng giữa cột phía trên cùng

    while (num <= n * n) {
        magicSquare[r][c] = num; // Gán giá trị vào ô hiện tại
        num++;

        int next_r = (r - 1 + n) % n; // Dịch chuyển đến ô tiếp theo theo chiều ngược chiều kim đồng hồ
        int next_c= (c + 1) % n;

        if (magicSquare[next_r][next_c] != 0) { // Nếu ô tiếp theo đã được điền giá trị, dịch chuyển xuống dòng
            r = (r + 1) % n;
        } else { // Nếu ô tiếp theo chưa được điền giá trị, dịch chuyển đến ô tiếp theo
            r = next_r;
            c = next_c;
        }
    }

    // In ma trận kì ảo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1 && n > 0)
        printMagicSquare(n);

}
