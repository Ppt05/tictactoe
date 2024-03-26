#include <bits/stdc++.h>

using namespace std;

void printSpiralMatrix(int x, int y) {
    vector<vector<int>> matrix(x, vector<int>(y)); // Tạo ma trận x hàng, y cột
    int value = 1;
    int top = 0, bottom = x - 1, left = 0, right = y - 1;

    while (top <= bottom && left <= right) {
        // In hàng đầu tiên từ cột left đến cột right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        // In cột cuối cùng từ hàng top đến hàng bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        // In hàng cuối cùng từ cột right đến cột left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        // In cột đầu tiên từ hàng bottom đến hàng top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }

    // In ra ma trận xoắn ốc
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int x, y;
    cin >> x>>y;
        printSpiralMatrix(x, y);
    return 0;
}
