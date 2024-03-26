#include <bits/stdc++.h>
using namespace std;


    bool check(int n){
    string str = to_string(n);
    string str2= str;
    reverse(str2.begin(),str2.end());
    if(str==str2) return true;
    else return false;
}
int count(int A,int B){
   int count=0;
for (int i = A; i <= B; i++) {
        if (check(i)) {
            count++;
        }
    }
    return count;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << count(A, B) << endl;
    }
    return 0;
}

