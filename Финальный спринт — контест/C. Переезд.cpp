#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mx = 0;
int deik(vector<vector<vector<int>>> &a, int v, int t, int w,int n,bool *l) {
   if ( t > 24 * 60 or (w/100 <= mx and w>-1)  ) {
      return 0;
   }
   if ( v == n - 1 ) {
      if ( t <= 24 * 60 ) {
         if ( mx < w / 100 ) {
            mx = w / 100;
            
         }
     }
      return 0;
   }
   
   for ( int i = 0; i < a[v].size(); i++ ) {
      int av = a[v][i][0];
      int at = a[v][i][1];
      int aw = a[v][i][2];
      if ( l[av] == true ) {
         continue;
      }
      l[av] = true;
      int y = aw;
      if ( w > -1 ) {
         y = min(w, aw);
      }
      deik(a, av, t + at, y, n, l);
      l[av] = false;
   }
   return 0;
}

int main() {
   int n,k;
   cin >> n>>k;
   if ( n == 1 ) {
      cout << 10000000;
      return 0;
   }
   int t = 3000000;
   vector<vector<vector<int>>> a(n, vector<vector<int>>());
   int f, b, c,d;
   for ( int i = 0; i < k; i++ ) {
      cin >>f  >> b >> c >> d;
      if ( (d - t) < 100 ) {
         continue;
      }
      vector<int> q = { b-1, c, d -t };
      a[f - 1].push_back(q);
      q = { f - 1,c,d - t };
      a[b - 1].push_back(q);
   }
   bool *l = new bool[n] {};
   l[0] = true;
   deik(a, 0, 0, -1, n, l);
   if ( mx > 10000000 ) {
      cout << 10000000;
   }
   else {
      cout << mx;
   }
   return 0;
}
