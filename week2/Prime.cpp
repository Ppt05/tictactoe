
#include <bits/stdc++.h>
using namespace std;
bool primeCheck(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i*i < n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    if(primeCheck(n)){
        cout <<"yes" << endl;
    }else
    cout << "no"<<endl;

    return 0;
}
