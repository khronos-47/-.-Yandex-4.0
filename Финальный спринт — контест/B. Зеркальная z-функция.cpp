#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for ( int i = 1, l = 0, r = 0; i < n; ++i ) {
		if ( i <= r )
			z[i] = min(r - i + 1, z[i - l]);
		while ( i + z[i] < n && s[z[i]] == s[i + z[i]] )
			++z[i];
		if ( i + z[i] - 1 > r )
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	string s1 = s + s;
	for ( int i = n - 1	; i >= 0; i-- ) {
		s1[n + n - i - 1] = s[i];
	}
	auto z = z_function(s1);

	for ( int i = z.size() - 1; i >= n; i-- ) {
		cout << z[i] << " ";
	}

	cout << endl;
	return 0;
}

