/*Lỗi sử dụng con trỏ. Hãy chạy chương trình thử nghiệm các đoạn code sau. Chú thích vào code đâu là các dòng gây lỗi và đó là lỗi gì.
 int* p = new int;
 int* p2 = p;
 *p = 10;
 delete p;
*p2 = 100;
 cout << *p2;
 delete p2; */


#include <iostream>

using namespace std;

int main()
{
    int* p = new int; // cấp phát bộ nhớ động cho 1 số nguyên và gán địa chỉ của bộ nhớ cho biến con trỏ p
 int* p2 = p; //con trỏ p2 gán vào p tức là con troe p2 trỏ đến địa chỉ  mà p trỏ
 *p = 10;// gán giá trị 10 cho bộ nhớ mà p trỏ tới
 delete p;// giải phóng bộ nhớ mà p trỏ tới
*p2 = 100;/*Lỗi ở đây khi bộ nhớ mà p trỏ tới đã được giải phóng nhưng p2 vẫn giữ địa chỉ tẠI BỘ NHỚ đó và thay đổi giá trị tại địa chỉ
             mà p2 trỏ tới thành 100
            vấn đề ở đây là bộ nhớ đã được giải phóng nên không thể gán giá trị vaof địa chỉ*/


 cout << *p2;// không thể in ra
 delete p2;// không thể giải phóng 2 lần cùng 1 địa chỉ

}
