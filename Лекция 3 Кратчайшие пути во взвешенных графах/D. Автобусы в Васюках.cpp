#include <iostream>
#include <queue>
using namespace std;


struct comparator
{
   bool  operator()  (vector<int64_t> &a, vector <int64_t> &b)
   {
      if ( a[0] != b[0] )
         return (a[0] > b[0]);
      else
         return (a[1] > b[1]);
   }
   bool  operator()  (int &a, int &b)
   {
      return a > b;
   }

};

vector<vector<int64_t>> deik(vector<vector<vector<int>>> &a, int s, int f,int n) {
   priority_queue <vector<int64_t>, vector< vector<int64_t> >, comparator>  q;
   
   bool *qw = new bool[n] {false};
   vector<int64_t> t = { 0,s };
   q.push(t);
   int64_t v = 0, w = 0;

   vector<vector<int64_t>> z(n, vector<int64_t>(2, -1));
   z[s][0] = 0;
   z[s][1] = -1;
   while (!q.empty() ) {
      w = q.top()[0];
      v = q.top()[1];
      q.pop();
      /*if ( qw[v] == true ) {
         continue;
      }
      else {
         qw[v] = true;
      }*/
      for ( int i = 0; i < a[v].size(); i++ ) {
         int64_t b = a[v][i][0];
         int64_t l = a[v][i][1];
         int64_t c = a[v][i][2];
         if ( w > b ) {
            continue;
         }
         if ( z[l][0] > c  or z[l][0] == -1 ) {
            z[l][0] = c;
            z[l][1] = v;
            vector<int64_t> kl = { c, l };
            q.push(kl);
         }
      }
   }
   /*for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < 2; j++ ) {
         cout << z[i][j] << " ";
      }
      cout << endl;
   }*/
   return z;
}

int main() {

   //priority_queue <vector<int>, vector< vector<int> >, comparator>  q;

   int n, s, f,k;
   cin >> n;
   cin >> s >> f;
   cin >> k;
   int d, b, l,c;
   vector<vector<vector<int>>> a(n, vector <vector<int>>() ) ;
   for(int i =0 ; i< k ;i++ ){
      cin >> d >> b >> l>>c;
      vector<int> gg{ b , l - 1, c };
      a[d - 1].push_back(gg);
      
   }
   /*for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < a[i].size(); j++ ) {
         cout << "( " << a[i][j].first << " , " << a[i][j].second << ") ";
      }
      cout << endl;
   }*/
   const vector<vector<int64_t>> as = deik(a, s - 1, f - 1, n);
   cout << as[f-1][0];

   return 0;
}