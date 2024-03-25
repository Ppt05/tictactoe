#include <iostream>


using namespace std;

int main()
{
    char daytab[2][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};
char daytab2[2][12] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
};

for(int i=0;i<2;i++){
    for(int j=0;j<12;j++){
        cout<<  static_cast<int>(daytab[i][j])<<" ";}
        cout << endl;
    }



for(int i=0;i<2;i++){
    for(int j=0;j<12;j++){
        cout<<  static_cast<int>(daytab2[i][j])<<" ";}
        cout << endl;
    }


/*b*/
char daytab3[2][12] = {
  {31,28,31,30},{31,29,31,30}
  };
char daytab4[2][12] = {31,28,31,30,31,29,31,30};

for(int i=0;i<2;i++){
    for(int j=0;j<12;j++){
        cout<<  static_cast<int>(daytab3[i][j])<<" ";}
        cout << endl;
    }

for(int i=0;i<2;i++){
    for(int j=0;j<12;j++){
        cout<<  static_cast<int>(daytab4[i][j])<<" ";}
        cout << endl;
    }


    char daytab5[][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};
 int rows5 = sizeof(daytab5) / sizeof(daytab5[0]);
 for(int i=0;i<rows5;i++){
    for(int j=0;j<12;j++){
        cout<<  static_cast<int>(daytab5[i][j])<<" ";}
        cout << endl;
    }

  char daytab6[][] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};
int rows6 =sizeof(daytab6) / sizeof(daytab6[0]);
int cols6 = sizeof(daytab6[0]) / sizeof(daytab6[0][0]) ;
for(int i=0;i<rows6;i++){
    for(int j=0;j<cols6;j++){
        cout<<  static_cast<int>(daytab6[i][j])<<" ";}
        cout << endl;
    }


 char daytab7[2][] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};

int cols7 = sizeof(daytab7[0]) / sizeof(daytab7[0][0]) ;
for(int i=0;i<2;i++){
    for(int j=0;j<cols7;j++){
        cout<<  static_cast<int>(daytab7[i][j])<<" ";}
        cout << endl;

}
  }
