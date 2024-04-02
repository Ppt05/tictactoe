#include <iostream>
using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   // In địa chỉ của biến x
   cout << "Địa chỉ của biến x trong hàm f(): " << &x << endl;
}

void g(int yval)
{
   int y;
   // In địa chỉ của biến y
   cout << "Địa chỉ của biến y trong hàm g(): " << &y << endl;
}

int main()
{
   f(7);
   g(11);
   return 0;
}
