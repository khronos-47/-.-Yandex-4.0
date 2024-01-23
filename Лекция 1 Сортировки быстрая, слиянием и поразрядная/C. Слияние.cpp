#include <iostream>

using namespace std;




int main()
{
   int n = 0;
   cin >> n;
   int *a = new int[n];
   for ( int i = 0; i< n; i++ ) {
      cin >> a[i];
   }
   int m = 0;
   cin >> m;
   int *b = new  int[m];
   for ( int i = 0; i < m; i++ ) {
      cin >> b[i];
      
   }

   int i = 0, j = 0;
   while ( j < m and i < n ) {
      if ( a[i] < b[j] ) {
         cout << a[i]<< " ";
         i++;
      }
      else {
         cout << b[j] << " ";
         j++;
      }
   }
   while ( j < m ) {
      cout << b[j] << " ";
      j ++ ;
   }
   while ( i < n ) {
      cout << a[i] << " ";
      i++;
   }
   return 0;
}