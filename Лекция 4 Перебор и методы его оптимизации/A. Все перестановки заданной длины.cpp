#include <iostream>
#include <vector>
using namespace std;

int rec(bool *t,vector<vector<int>> &s, vector<int> a, int n) {
	
	for ( int i = 1; i < n + 1; i++ ) {
		if ( t[i] == false ) {
				a.push_back(i);
				t[i] = true;
				if ( a.size() == n ) {
					s.push_back(a);
				}
				else {
					rec(t, s, a, n);
				}
				t[i] = false;
				a.pop_back();

		}
	}
	return 0;
}



int main() {
	int n;
	cin >> n;
	vector<vector<int>> s;
	int k = 1;
	bool *t = new bool[n + 1] {};
	vector<int>a;
	rec(t, s, a, n);
	for ( int i = 0; i < s.size(); i++ ) {
		for ( int j = 0; j < s[i].size(); j++ ) {
			cout << s[i][j];
		}
		cout << endl;
	}

	return 0;
}