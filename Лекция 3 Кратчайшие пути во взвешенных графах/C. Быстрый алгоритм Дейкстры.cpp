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

vector<vector<int64_t>> deik(vector<vector<pair<int, int>>> &a, int s, int f,int n) {
   priority_queue <vector<int64_t>, vector< vector<int64_t> >, comparator>  q;
   bool *qw = new bool[n] {false};
   vector<int64_t> t = { 0,s };
   q.push(t);
   int64_t v = 0, w = 0;

   vector<vector<int64_t>> z(n, vector<int64_t>(2, -1));
   while (!q.empty() ) {
      w = q.top()[0];
      v = q.top()[1];
      q.pop();
      if ( qw[v] == true ) {
         continue;
      }
      else {
         qw[v] = true;
      }
      for ( int i = 0; i < a[v].size(); i++ ) {
         int64_t aw = a[v][i].first;
         int64_t av = a[v][i].second;
         if ( z[av][0] > w + aw or z[av][0] == -1 ) {
            z[av][0] = w + aw;
            z[av][1] = v;
            vector<int64_t> l = { w + aw , av };
            q.push(l);
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
   cin >> n >> k;
   int d, b, l;
   vector<vector<pair<int,int>>> a(n, vector <pair<int,int>>() ) ;
   for(int i =0 ; i< k ;i++ ){
      cin >> d >> b >> l;
      a[d - 1].push_back(pair<int, int>(l, b - 1));
      a[b - 1].push_back(pair<int, int>(l, d - 1));
      
   }
   /*for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < a[i].size(); j++ ) {
         cout << "( " << a[i][j].first << " , " << a[i][j].second << ") ";
      }
      cout << endl;
   }*/
   cin >> s >> f;
   const vector<vector<int64_t>> as = deik(a, s - 1, f - 1, n);
   cout << as[f-1][0];

   return 0;
}