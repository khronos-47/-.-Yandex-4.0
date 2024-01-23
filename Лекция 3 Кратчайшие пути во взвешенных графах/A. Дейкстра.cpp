#include <iostream>
#include <queue>
using namespace std;


struct comparator
{
   bool  operator()  (vector<int> &a, vector <int> &b)
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

vector<vector<int>>  deik(int **a, int s, int f,int n) {
   priority_queue <vector<int>, vector< vector<int> >, comparator>  q;
   bool *qw = new bool[n] {false};
   vector<int> t = { 0,s };
   q.push(t);
   int v = 0, w = 0;

   vector<vector<int>> z(n, vector<int>(2, -1));
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
      for ( int i = 0; i < n; i++ ) {
         if ( a[v][i] > -1 ) {
            if ( z[i][0] > w + a[v][i] or z[i][0] == -1 ) {
               z[i][0] = w + a[v][i];
               z[i][1] = v;
               vector<int> l = { w + a[v][i] , i };
               q.push(l);
            }
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

   int n, s, f;
   cin >> n >> s >> f;
   int **a = new int *[n];
   for ( int i = 0; i < n; i++ ) {
      a[i] = new int[n];
      for ( int j = 0; j < n; j++ ) {
         cin >> a[i][j];
      }
   }
   vector<vector<int>> as = deik(a, s - 1, f - 1, n);
   cout << as[f - 1][0];
	return 0;
}