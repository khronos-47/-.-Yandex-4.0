#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int n = 0;
   cin >> n;
   vector<vector<string>> a(10, vector <string>());
   vector<string> s(n,"");
   string h = "";
   for ( int i = 0; i < n; i++ ) {
      cin >> s[i];
      h = s[i];
      char x =0;
      x = h[h.size() - 1];
      a[x - '0'].push_back(h);
   }
   cout << "Initial array:" << endl;
   for ( int i = 0; i < n; i++ ) {
      cout << s[i];
      if ( i < n - 1 ) {
         cout << ", ";
      }
   }
   cout << endl;
   cout << "**********" << endl;
   int k = 1;
   for ( int i = (int)(h.size() - 2); i >= -1; i-- ) {
      cout << "Phase "<< k<<endl;
      k++;
      s.clear();
      for ( int j = 0; j < 10; j++ ) {
         int l = 0;
         cout << "Bucket "<<j<<": ";
         if ( a[j].size() == 0 ) {
            cout << "empty" << endl;
            continue;
         }
         for (l = 0 ; l < a[j].size() - 1; l++ ) {
            cout << a[j][l] << ", ";
            s.push_back(a[j][l]);
         }
         cout << a[j][l] << endl;
         s.push_back(a[j][l]);
      }
      cout << "**********" << endl;
      if ( i == -1 ) {
         cout << "Sorted array:" << endl;
         for ( int j = 0; j < n - 1; j++ ) {
            cout << s[j] << ", ";
         }
         cout << s[s.size() - 1];
         break;
      }
      char x=0 ;
      a.clear();
      a.resize(10);
      for ( int j = 0; j < n; j++ ) {
         x = s[j][i];
         a[x - '0'].push_back(s[j]);
      }
   }
   return 0;
}