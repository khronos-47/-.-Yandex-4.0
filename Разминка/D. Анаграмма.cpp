#include <iostream>


using namespace std;

int main()
{
   string a, s;
   cin >> a >> s;
   if ( a.size() != s.size() ) {
      cout << "NO";
      return 0;
   }
   int  d[130] = {};
   for ( int i = 0; i < a.size(); i++ ) {
      d[(int)a[i]]++;
      d[(int)s[i]]--;

   }
   for ( int i = 60; i < 130; i++ ) {
      if ( d[i] != 0 ) {
         cout << "NO";
         return 0;
      }
   }
   cout << "YES";
   return 0;
}