#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int n = 0, m = 0;
   cin >> n >> m;
   vector<vector<int>> s(n, vector<int>(m,0));
   vector<vector<int>> d(n, vector<int>(m,0));
   for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < m;j++ ) {
         cin >> s[i][j];
         if ( i == 0 and j == 0 ) {
            d[i][j] = s[i][j];
         }
         else if ( i == 0 ) {
            d[i][j] = d[i][j - 1] + s[i][j];
         }
         else if ( j == 0 ) {
            d[i][j] = d[i - 1][j] + s[i][j];
         }
         else {
            d[i][j] = d[i - 1][j] + d[i][j - 1] + s[i][j] - d[i - 1][j - 1];
         }
      }
   }

   int side = min(n, m);
   bool  is = true;
   while ( side > 0 ) {
      for ( int i = 0; i < n - side + 1; i++ ) {
         for ( int j = 0; j < m - side + 1; j++ ) {
            is = true;
            int sq = d[i + side - 1][j + side - 1];
            if ( i == 0 and j == 0 ) {
               sq = sq;
            }
            else if ( i == 0 ) {
               sq = sq - d[i + side - 1][j - 1];
            }
            else if ( j == 0 ) {
               sq = sq - d[i - 1][j + side -1];
            }
            else {
               sq =sq -  d[i + side - 1 ][j - 1] - d[i-1][j + side - 1] + d[i-1][j-1];
            }
            if ( sq == side * side ) {
               cout << side;
               return 0;
            }
         }
      }
      side--;  
   }
   cout << 0;
   return 0;
}