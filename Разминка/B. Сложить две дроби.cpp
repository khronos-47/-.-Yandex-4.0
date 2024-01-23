#include <iostream>

using namespace std;

int main()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   int r = a * d + b * c;
   int l = b * d;
   for ( int i = 2; i <= l; i++ ) {
      if ( l % i == 0 and r % i == 0 ) {
         l = l / i;
         r = r / i;
         i = 1;
      }
   }
   cout << r << " " << l;
}