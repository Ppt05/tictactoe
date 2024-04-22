#include <iostream>


using namespace std;
int strlen(const char *a){
int length = 0;
while (*a != '\0'){
    length++;
    a++;
}
return length;
}
void strcpy(const char *source, char *destination){
    while(*source!='\0'){
            *destination = *source;
             source++;
             destination++;


    }
    *destination ='\0';
 }



char* reverse(const char*a){
    int l = strlen(a);
    char *result= new char[l+1];
    for(int i=0;i<l; i++ ){
        result[i]=a[l-i-1];
    }
    result[l]='\0';
    return result;
}

char* delete_char(const char *a, char c) {
    int l= strlen(a);
    int count =0;
    for(int i=0; i<l; i++){
        if(a[i]==c){
            count++;
        }
    }
    char *result= new char[l- count +1];
    int j=0;
    for (int i = 0; i < l; i++) {
        if (a[i] != c) {
            result[j++] = a[i];
        }
    }
    result[j] = '\0';
    return result;
}


 char* pad_right(const char* a, int n) {
    int len = strlen(a);
    char* result = new char[n + 1];
    for (int i = 0; i < len; i++) {
        result[i] = a[i];
    }
    for (int i = len; i < n; i++) {
        result[i] = ' ';
    }
    result[n] = '\0';
    return result;
}



char* pad_left(const char* a, int n) {
    int len = strlen(a);
    char* result = new char[n + 1];
    int pad_length = n - len;
    for (int i = 0; i < pad_length; i++) {
        result[i] = ' ';
    }
    for (int i = pad_length; i < n; i++) {
        result[i] = a[i - pad_length];
    }
    result[n] = '\0';
    return result;
}


char* truncate(const char* a, int n) {
    int len = strlen(a);
    char* result = new char[n + 1];
    for (int i = 0; i < n && i < len; i++) {
        result[i] = a[i];
    }
    result[n] = '\0';
    return result;
}


char* trim_left(const char* a) {
    int len = strlen(a);
    int i = 0;
    while (a[i] == ' ') {
        i++;
    }
    char* result = new char[len - i + 1];
    int j=0;
    while (a[i] != '\0') {
        result[j++] = a[i++];
    }
    result[j] = '\0';
    return result;
}



char* trim_right(const char* a) {
    int len = strlen(a);
    int i = len - 1;
    while (i >= 0 && a[i] == ' ') {
        i--;
    }
    char* result = new char[i + 2];
    for (int j = 0; j <= i; j++) {
        result[j] = a[j];
    }
    result[i + 1] = '\0';
    return result;
}
int main(){
     const char str[] = "   hallo Welt   ";
    cout << str << endl;

    char* reverse1 = reverse(str);
    cout << reverse1<< endl;
    delete[] reverse1;

    char* deleted_char = delete_char(str, ' ');
    cout << deleted_char << endl;
    delete[] deleted_char;

    char* padded_right = pad_right(str, 20);
    cout << padded_right << std::endl;
    delete[] padded_right;

    char* padded_left = pad_left(str, 20);
    cout << padded_left << endl;
    delete[] padded_left;





    return 0;
}
