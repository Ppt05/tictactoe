#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Hàm chuyển đổi số từ hệ cơ số 10 sang hệ cơ số 2
string decimalToBinary(int decimalNum) {
    string binaryNum = "";
    while (decimalNum > 0) {
        int remainder = decimalNum % 2;
        binaryNum = to_string(remainder) + binaryNum;
        decimalNum /= 2;
    }
    return binaryNum;
}

// Hàm chuyển đổi số từ hệ cơ số 2 sang hệ cơ số 10
int binaryToDecimal(string binaryNum) {
    int decimalNum = 0;
    for (int i = 0; i < binaryNum.length(); ++i) {
        decimalNum += (binaryNum[i] - '0') * pow(2, binaryNum.length() - i - 1);
    }
    return decimalNum;
}

