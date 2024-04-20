#include <bits/stdc++.h>
using namespace std;

int main( )
{
  /* char a[4] = "abc";
   for (char *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}*/
/*int array[4] = {1,2,3,4};
   for (int *cp = array; cp < array +4; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
   }
*/

/*double b[4]={1.1,2.2,3.3,4.4};
for (double *cp = b; cp < b +4; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
   }*/

double b[4]={1.1,2.2,3.3,4.4};
for (double *cp = b; cp < b +4; cp+=2) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}
