#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm trả về một số ngẫu nhiên nhỏ hơn N
int randomLessThanN(int N) {
    // Đảm bảo sinh số ngẫu nhiên khác nhau mỗi lần chạy chương trình
    srand(time(NULL));
    // Sinh số ngẫu nhiên và trả về kết quả
    return rand() % N;
}

int main() {
    int N;
    cout << "Enter the maximum value (N): ";
    cin >> N;

    int randomNum = randomLessThanN(N);
    cout << "Random number less than " << N << ": " << randomNum << endl;

    return 0;
}
