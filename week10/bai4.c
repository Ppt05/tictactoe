
#include <bit/stdc++.h>
using namespace std;
int check(){
    int n=10;
    int*p;
    p=&n;
    return p;
}
int main(){
    int* ptr = check();/*lỗi con trỏ ptr trỏ tới một vùng nhớ không còn hợp lệ,
                        vì biến n đã bị hủy khi kết thúc phạm vi của hàm check()*/
    cout << ptr << endl;
    delete ptr ;// Loi vi ptr ko tror vào vùng nhớ đc cấp phát đôngj  nên ko dùng lệnh delete
    cout << ptr <<endl;
    return 0;
}
