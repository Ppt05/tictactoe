#include <iostream>
using namespace std;


void printLine(int M, int N) {
    for (int i = 0; i < M; ++i) {
        cout << " ";
    }
    for (int i = 0; i < N; ++i) {
        cout << "*";
    }
    cout << endl;
}


void printHollowTriangle(int numLines) {

    for (int i = 0; i < numLines; ++i) {

        printLine(numLines - i - 1, 2 * i + 1);
    }
}

int main() {
    int numLines;
    cin >> numLines;

    printHollowTriangle(numLines);

    return 0;
}
