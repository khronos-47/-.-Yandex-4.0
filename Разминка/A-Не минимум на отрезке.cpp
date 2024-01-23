#include <iostream>

using namespace std;

int main()
{
   int n = 0, m = 0;
   cin >> n >> m;
   int *a = new int[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];

   }
   int l = 0, r = 0;
   for (int i = 0; i < m; i++) {
      cin >> l >> r;
      int ma = a[l], j = l + 1;
      for (; j < r + 1; j++) {
         if (a[j] != ma) {
            cout << max(a[j], ma) << endl;
            break;
         }
      }
      if (j == r + 1) {
         cout << "NOT FOUND" << endl;
      }
   }
}