#include <iostream>
#include <vector>
using namespace std;
// A == 65
// a == 97
int64_t *po = new int64_t[200000]{1};
int x = 30;
int p = 1000000000;

int equal(string h, int l, int from1, int from2,int64_t *a ) {
   int64_t k1 = (a[from1 + l] + a[from2 ] * po[l]) % p;
   int64_t k2 = (a[from2 + l] + a[from1 ] * po[l]) % p;
   if ( k1 == k2 ) {
      for ( int i = 0; i < l; i++ ) {
         if ( h[from1 + i] != h[from2 + i] )
            return 0;
      }
      return 1;
   }
   return 0;
}

void hashing(int64_t *a, string h) {
   for ( int i = 1; i < h.size() + 1; i++ )
      a[i] = (a[i - 1] * x + (h[i - 1] - 'a' + 1)) % p;
}

int main()
{
   for ( int i = 1; i < 20; i++ ) {
      po[i] = (po[i - 1] * x) %p ;
   }
   string h;
   cin >> h;
   int64_t *a = new int64_t[h.size() + 1] {};
   hashing(a, h);
   int n = 0;
   cin >> n;
   for ( int i = 0; i < n; i++ ) {
      int d, b, c;
      cin >> d >> b >> c;

      if ( equal(h, d, b, c, a) ) {
         cout << "yes" << endl;
      }
      else {
         cout << "no" << endl;
      }
   }
   return 0;
}