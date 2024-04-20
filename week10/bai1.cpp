/*Trả về mảng động. Viết một hàm concat(const char*, const* char) nhận tham số là hai hằng xâu kí tự,
trả về một xâu kí tự là kết quả của việc nối hai xâu đó.
 Chẳng hạn nếu tham số lần lượt có nội dung là “Hello“
 và “World” thì xâu trả về có nội dung “HelloWorld”.*/

#include <iostream>
#include <cstring>
using namespace std;

char* concat(const char* str1, const char* str2) {
   size_t a = strlen(str1); // Độ dài của chuỗi str1
   size_t b = strlen(str2); // Độ dài của chuỗi str2
   size_t c = a + b + 1;    // Độ dài của chuỗi kết quả
   char* result = new char[c];

   strncpy(result, str1,a);// Sao chép chuỗi str1 vào chuỗi kết quả
   strcat(result, str2);    // Nối chuỗi str2 vào chuỗi kết quả

   return result;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "World";
    char* print = concat(str1, str2);
    cout << print << endl;
    delete[] print;
    return 0;
}

