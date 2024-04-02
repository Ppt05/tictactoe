
/*Địa chỉ các biến. Hãy viết một chương trình có khai báo một mảng a kiểu int, mảng b kiểu char, in ra màn hình địa chỉ của 03 phần tử liên tiếp của mảng a, 03 phần tử liên tiếp của mảng b. Bạn có nhận xét gì về các kết quả đó? Viết câu trả lời vào chương trình ở dạng comment.
Khai báo thêm một vài biến trước và sau các mảng trên. Hãy thử nghiệm để trả lời câu hỏi: các biến đó có vị trí tương đối với nhau như thế nào. Viết câu trả lời vào chương trình ở dạng comment.
Để in địa chỉ của một phần từ mảng char, bạn dùng lệnh sau, chẳng hạn cho b[i]:
		cout << (void *)&b[i];
Nếu chỉ dùng &b[i] thì cout sẽ nghĩ rằng bạn in ra một xâu kí tự nên bạn sẽ không thấy được địa chỉ của phần từ mảng b[i].
Ta sẽ nói thêm về việc này khi học con trỏ.*/

#include <iostream>
using namespace std;

int main() {
    int a[5];
    char b[5];

    int x, y;

    for (int i = 0; i < 3; ++i) {
        cout << "Địa chỉ của a[" << i << "]: " << &a[i] << endl;
    }
    for (int i = 0; i < 3; ++i) {
        cout << "Địa chỉ của b[" << i << "]: " << (void *)&b[i] << endl;
    }

    /* Nhận xét về các kết quả
    Các địa chỉ của các phần tử liên tiếp của mảng a và b thường không liên tục về mặt vị trí bộ nhớ.
    Điều này phụ thuộc vào cách mà trình biên dịch cấp phát bộ nhớ cho các mảng và các biến khác trong chương trình.
    Trong một số trường hợp, có thể thấy rằng các địa chỉ của các phần tử liên tiếp của mảng a và b không khác biệt nhiều,
    nhưng điều này không đảm bảo xảy ra trong tất cả các trường hợp.*/


    cout << "Địa chỉ của biến x: " << &x << endl;
    cout << "Địa chỉ của mảng a: " << &a << endl;
    cout << "Địa chỉ của mảng b: " << &b << endl;
    cout << "Địa chỉ của biến y: " << &y << endl;

    /* Nhận xét về vị trí tương đối của các biến
    // Vị trí tương đối của các biến và mảng trong bộ nhớ phụ thuộc vào trình biên dịch và cơ chế cấp phát bộ nhớ của hệ thống.
    // Trong trường hợp này, địa chỉ của biến x sẽ gần với địa chỉ của mảng a, địa chỉ của mảng a sẽ gần với địa chỉ của mảng b, và cuối cùng là địa chỉ của biến y.
    // Tuy nhiên, không có quy tắc cụ thể nào đảm bảo về vị trí tương đối của các biến và mảng trong bộ nhớ.*/

    return 0;
}
