/*Xâu đối xứng. Viết chương trình nhập từ bàn phím một xâu kí tự độ
dài tối đa 100, sau đó kiểm tra xem xâu kí tự đó có đối xứng hay kh
ông. Chẳng hạn “abcba", “abba" là đối xứng, còn “abcda” không đối xứng. Nếu có thì in ra “Yes”,
nếu không thì in ra “No”.*/
#include <iostream>


using namespace std;

int main()

{
      int check=1;
      string n;
      cin >> n;
    for(int i=0; i<(n.length()/2); i++){
        for (int j=n.length()-i-1; j>=(n.length()/2);j--){
            if(n[i]!=n[j]) check=0;
            break;
        }
    }

if(check==1) cout <<"yes";
        else cout << "no";
}
