#include <iostream>
#include <vector>

using namespace std;

const int p = 31;  // Простое число для вычисления хеша
const int mod = 1e9 + 9;  // Модуль для вычисления хеша

vector<int> compute_z_function_with_hash(const string &S) {
   int N = S.size();
   vector<int> z(N, 0);
   vector<int> h(N, 0);

   // Вычисление хешей для префиксов строки
   h[0] = 1;
   for ( int i = 1; i < N; ++i ) {
      h[i] = (1LL * h[i - 1] * p) % mod;
   }

   // Вычисление хеша для подстроки S[l:r]
   auto hash_substring = [&](int l, int r) -> int {
      if ( l == 0 ) {
         return h[r];
      }
      return (h[r] - 1LL * h[l - 1] * h[r - l + 1] % mod + mod) % mod;
   };

   int l = 0, r = 0;  // Границы самого правого отрезка совпадения

   for ( int i = 1; i < N; ++i ) {
      if ( i <= r ) {
         z[i] = min(r - i + 1, z[i - l]);
      }

      while ( i + z[i] < N && S[z[i]] == S[i + z[i]] ) {
         ++z[i];
      }

      if ( i + z[i] - 1 > r ) {
         l = i;
         r = i + z[i] - 1;
      }
   }

   return z;
}

int main() {
   string S;
   cin >> S;
   vector<int> z_function_result = compute_z_function_with_hash(S);

   for ( int value : z_function_result ) {
      cout << value << " ";
   }

   return 0;
}