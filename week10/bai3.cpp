#include <iostream>

using namespace std;

int main()
{
    char* a = new char[10];
char* c = a + 3;
for (int i = 0; i < 9; i++) a[i] = 'a';
a[9] = '\0';
cerr <<"a: " << "-" << a << "-" << endl;
cerr <<"c: " << "-" << c << "-" << endl;
delete c;// sai vì c không phải là con trỏ được câp phát động
cerr << "a after deleting c:" << "-" << a << "-" << endl;


    return 0;
}
