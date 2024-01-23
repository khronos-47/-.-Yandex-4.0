#include <iostream>

using namespace std;



int *merge(int l,int r, int *s) {
   if ( r - l <=0 ) {
      int *f = new int[1];
      f[0] = s[l];
      return f;
   }
   int middle = (l + r) / 2;
   int *b = merge(l,middle, s);
   int *a = merge( middle + 1,r, s);
   int *f = new int[r - l + 1];
   int i = 0, j = 0;
   int n = r - middle;
   int m = middle - l + 1;
   int k = 0;
   while ( j < m and i < n ) {
      if ( a[i] < b[j] ) {
         f[k] = a[i];
         i++;
         k++;
      }
      else {
         f[k] = b[j];
         j++;
         k++;
      }
   }
   while ( j < m ) {
      f[k] = b[j];
      j++;
      k++;
   }
   while ( i < n ) {
      f[k] = a[i];
      i++;
      k++;
   }
   delete[] a;
   delete[] b;
   return f;
}





int main()
{
   int n = 0;
   cin >> n;
   int *a = new int[n];
   for ( int i = 0; i< n; i++ ) {
      cin >> a[i];
   }
   a = merge(0, n - 1, a);
   for ( int i = 0; i < n; i++ ) {
      cout << a[i] << " ";
   }
   return 0;
}