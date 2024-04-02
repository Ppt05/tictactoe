#include <iostream>
#include <cmath>
using namespace std;

int roundToNearest1(double num) {
    // Sử dụng ceil và floor để làm tròn
    int roundedNum = (num - floor(num) < 0.5) ? floor(num) : ceil(num);
    return roundedNum;
}

int main() {
    double num;
    cout << "Enter a real number: ";
    cin >> num;
    int roundedNum = roundToNearest1(num);
    cout << "Rounded number: " << roundedNum << endl;
    return 0;
}
// ko dung ceilvà floor
#include <iostream>
using namespace std;

int roundToNearest2(double num) {

    int roundedNum = (num >= 0) ? int(num + 0.5) : int(num - 0.5);
    return roundedNum;
}

int main() {
    double num;
    cout << "Enter a real number: ";
    cin >> num;
    int roundedNum = roundToNearest2(num);
    cout << "Rounded number: " << roundedNum << endl;
    return 0;
}
