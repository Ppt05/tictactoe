/*struct được sao chép có trường dữ liệu là mảng, là một struct khác.
Xử lý xâu. Tương tự định nghĩa cấu trúc Array trong bài giảng, hãy xây dựng cấu trúc String để lưu trữ một xâu kí tự.Mô tả như sau:
Cấu trúc này cần có hai biến thành viên, một biến n lưu độ dài xâu, một con trỏ str chiếu tới mảng char được cấp phát động.
Một constructor với tham số kiểu const char* để có thể khởi tạo một biến kiểu String bằng lệnh như:
String s(“Hello”);
Constructor có nhiệm vụ cấp phát mảng động với kích thước thích hợp và chép nội dung xâu kí tự được cho vào mảng đó.
Destructor có nhiệm vụ giải phóng mảng động str.
Hàm thành viên void print() với nhiệm vụ in nội dung xâu str ra màn hình
Hàm thành viên void append(const char* ) với tham số là một hằng xâu kí tự và có nhiệm vụ nối thêm xâu kí tự đó vào cuối xâu. Ví dụ, sau đoạn lệnh sau thì greeting chứa nội dung “Hi there”:
	String greeting(“Hi”);
	greeting.append(“ there”);
	// đến đây nếu chạy greeting.print() ta sẽ được output “Hi there”.
Gợi ý: Để làm việc này, bạn cần làm các bước sau: (1) dùng một con trỏ tạm temp để cấp phát một mảng động mới có kích thước đủ lớn, (2) copy xâu str hiện hành vào phần đầu mảng mà temp đang trỏ tới, (3) copy xâu tham số vào phần sau. Đến giờ mảng động temp đã chứa nội dung đầy đủ của xâu kết quả. Việc còn lại là trỏ str tới mảng đó.Bạn hãy tự làm tiếp.
Chú ý tránh thất thoát bộ nhớ, cần giải phóng vùng bộ nhớ đã từng cấp phát nhưng không còn cần dùng đến nữa.
	Với mỗi hàm, cần demo tại hàm main của chương trình.
	Chú ý: dùng const ở bất cứ chỗ nào có thể.*/

	#include <bits/stdc++.h>
	using namespace std;

	struct String{
	int n;
	char* str;


	//Construct
	String (const char* s){
	    n= strlen (s);
	    str = new char[n+1];
	    strcpy(str,s);
	}
	~String (){
	delete [] str;
	}
void print() const{
    cout << str << endl;
}
void append(const char* s ){
int len=strlen(s);
        char*temp= new char[n+1+len];
        strcpy(temp, str); // Sao chép nội dung xâu hiện tại vào temp
        strcat(temp, s); // Nối xâu s vào cuối xâu temp
        delete[] str; // Giải phóng bộ nhớ của xâu hiện tại
        str = temp; // Trỏ str tới mảng mới
        n += len; // Cập nhật độ dài mới
    }
};

int main() {
    String greeting("Hi");
    greeting.append(" there");
    greeting.print();



    return 0;
}

