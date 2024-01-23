#include <iostream>

using namespace std;



int *partition(int l, int n, int *a) {
   int p = a[l + (n - l) / 4];
   int e = l, g = l, t = l;
   for ( int i = l; i <= n; i++ ) {
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
      }

   }
   int *d = new int[2];
   d[0] = e - 1;
   d[1] = g;
   return d;
}
int quick_sort(int l, int r, int *a) {

   int *p = partition(l, r, a);
   if ( r - l < 2 )
      return 0;

   quick_sort(l, p[0], a);
   quick_sort(p[1], r, a);
   return 0;
}

int main()
{
   int n;
   cin >> n;
   int *a = new int[n];
   for ( int i = 0; i < n; i++ ) {
      cin >> a[i];

   }
   quick_sort(0, n - 1, a);
   for ( int i = 0; i < n; i++ ) {
      cout << a[i] << " ";
   }

   return 0;
}