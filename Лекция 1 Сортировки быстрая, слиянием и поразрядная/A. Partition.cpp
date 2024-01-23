#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int n;
   cin >> n;
   int *a = new int[n];
   for ( int i = 0; i < n; i++ ) {
      cin >> a[i];

   }
   int p = 0;
   cin >> p;
   int e = 0, g = 0, t =0;
   for ( int i = 0; i < n; i++ ) {
      t = a[i];
      if ( t < p ) {
         a[i] = a[g];
         a[g] = a[e];
         a[e] = t;
         g++;
         e++;
         continue;
      }
      if ( t == p ) {
         a[i] = a[g];
         a[g] = t;
         g++;
         continue;
      }

   }
   cout << e << endl << n - e;

   return 0;
}