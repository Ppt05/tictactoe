#include <iostream>
using namespace std;
int a1[5];
int a5[]={1,2,3,4};
int main()
{
    int a2[6];
    int a3[5]={1,2,5,6,7};
    int a4[2]={7,8};
    int a6[]={1,2,3,4};
  for(int i=0;i<5;i++){
    cout << a1[i];
  }
  cout <<endl;
  for (int i=0; i<6; i++){
    cout<< a2[i];
  }
  cout << endl;
  for (int i=0; i<5; i++){
    cout<< a3[i];
  }
  cout << endl;
  for (int i=0; i<2; i++){
    cout<< a4[i];
  }
  cout << endl;
  for (int i=0; i<sizeof(a5); i++){
    cout<< a5[i];
  }
  cout << endl;
  for (int i=0; i<sizeof(a6); i++){
    cout<< a6[i];
  }
    return 0;
}
/*Khởi tạo mảng một chiều. Hãy viết một chương trình thử dùng các cách khai báo và khởi tạo mảng dưới đây. Với mỗi cách, nếu không có lỗi thì dùng vòng lặp in toàn bộ nội dung của mảng ra màn hình để xem kết quả khởi tạo, nếu có lỗi thì chuyển khai báo đó thành dạng comment
Khai báo mảng trong và ngoài hàm main() và không khởi tạo giá trị cho mảng
Khai báo và khởi tạo trong và ngoài hàm main() dạng int a[N] = {1, 2, 3, 4} với N lớn hơn và nhỏ hơn 4.
Khai báo và khởi tạo trong và ngoài hàm main() dạng int a[ ] = {1, 2, 3, 4}.
Hãy chạy đi chạy lại trường hợp khai báo bên trong hàm main() và không khởi tạo để quan sát hiện tượng mỗi lần chạy lại in ra một kết quả khác cho nội dung mảng. Rút kinh nghiệm tránh lỗi không khởi tạo giá trị cho biến.
*/
