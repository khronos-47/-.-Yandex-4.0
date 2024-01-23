#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int a, b, c;
   cin >> a >> b >> c;
   if ( a > (b / c + (b % c > 0)) ) {
      cout << "YES";

   }
   else {
      cout << "NO";
   }
   return 0;
}