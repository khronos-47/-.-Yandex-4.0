#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int n;
   cin >> n;
   for ( int i = 0; i < n; i++ ) {
      int t, a, b;
      cin >> t >> a >> b;
      if ( b - a > 1 ) {
         if ( t > b and t < 2 * a ) {
            cout << "NO"<<endl;
         }
         else {
            cout << "YES"<<endl;
         }
         continue;
      }
      t = t % (a * b);
      if ( t == 0 ) {
         cout << "YES" << endl;

      }
      while ( t > 0 ) {
         if ( t % b > 0 ) {
            t = t - a;
         }
          if(t%b == 0 ){
            cout << "YES" << endl;
            break;
         }
         if ( t % a > 0 ) {
            t -= b;
         }
         if(t % a == 0){
            cout << "YES"<<endl;
            break;
         }
         if ( t < 0 ) {
            cout << "NO"<<endl;
            break;
         }
      }
   }
   return 0;
}