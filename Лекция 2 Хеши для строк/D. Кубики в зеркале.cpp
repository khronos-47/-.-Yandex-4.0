#include <iostream>
#include <vector>
using namespace std;
// A == 65
// a == 97
int64_t *po = new int64_t[1000001]{ 1 };
int x = 1000001;
int p = 1000000000;

int equal(int l, int from1, int from2, int64_t *a,int64_t *ra , int *b,int n) {
   int64_t k1 = (a[from1 + l] + ra[from2] * po[l]) % p;
   int64_t k2 = (ra[from2 + l] + a[from1] * po[l]) % p;
   if ( k1 == k2 ) {
      for ( int i = 0; i < l ; i++ ) {
         if ( b[ l  + i] != b[l - i -1 ] ) {
            return 0;
         }
      }
      return 1;
   }
   return 0;
}

void hashing(int64_t *a, int *b,int n) {
   for ( int i = 1; i < n + 1; i++ )
      a[i] = (a[i - 1] * x + b[i - 1]) % p;
}

void rhash(int64_t *ra, int *b, int n) {
   for ( int i = 1; i < n + 1; i++ )
      ra[i] = (ra[i - 1] * x + b[n - i]) % p;
}


int main()
{
   int n,t;
   cin >> n >> t;
   x = t + 1;
   for ( int i = 1; i < n + 1; i++ ) {
      po[i] = (po[i - 1] * x) % p;
   }
   int *b = new int[n];
   for ( int i = 0; i < n; i++ ) {
      cin >> b[i];
   }
   int64_t *a = new int64_t[n + 1]{};
   int64_t *ra = new int64_t[n + 1]{};
   hashing(a, b, n);
   rhash(ra, b, n);
   int ad = 1;
   for ( int i = n/2; i >=0  ; i-- ) {
      if ( equal(i ,0, n - i * 2,  a, ra, b, n) ) {
         cout <<n - i <<" ";
      }
   }
   //cout << n ;


   return 0;
}