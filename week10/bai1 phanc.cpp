#include <iostream>
#include <cstring>

using namespace std;
struct string1 {
    int n;
    char* str;


//construct
string1(const char* s){
    n= strlen(s);
    str = new char[n+1];
    strcpy(str,s);
}

//destruct
 ~string1() {
    delete[] str;
}
 void print()const{
 cout << str<< endl;
 }
  void append(const char*s){
      int a= strlen(s);
      char *temp= new char[n+a+1];
      strcpy(temp,str);
      strcat(temp,s);

      delete[] str;
      str=temp;
      n+=a;
  }
};

int main()
{
    string1 greeting("hi");
    greeting.append("there");
    greeting.print();

    return 0;
}
