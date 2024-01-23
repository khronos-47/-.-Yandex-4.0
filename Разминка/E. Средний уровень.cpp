#include <iostream>


using namespace std;

int main()
{
   int n;
   cin >> n;
   int *s = new int[n];
   long int d = 0;
   for ( int i = 0; i < n; i++ ) {
      cin >> s[i];
      d += s[i];
   }
   long int f = 0;
   for ( int i = 0; i < n; i++ ) {
      cout << d - s[i] * (n - 2 * i) - f << endl;
      d -= s[i];
      f += s[i];
   }
   return 0;
}