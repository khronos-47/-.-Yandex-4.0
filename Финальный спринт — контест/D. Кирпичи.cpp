#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> mai;

int rec(vector<int> &s, vector<int> &a, int *l, int k, int sm, int n, int ii) {
	if ( s.size() >= mai.size() and mai.size() > 0 ) {
		return 0;
	}
	if ( sm == n ) {
		if ( mai.size() > s.size() or mai.size() == 0 ) {
			mai = s;

		}
		return 0;
	}
	for ( int i = ii; i < k; i++ ) {
		if ( l[i] < 2 and sm + a[i] <= n ) {
			l[i]++;
			s.push_back(a[i]);
			rec(s, a, l, k, sm + a[i], n,i);
			s.pop_back();
			l[i]--;
		}
	}
	return 0;
}


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k, 0);

	int64_t sum = 0;
	for ( int i = 0; i < k; i++ ) {
		cin >> a[i];
		sum += a[i];
	}
	if ( 2 * sum < n ) {
		cout << -1;
		return 0;
	}


	vector<int>s;
	int *l = new int[k] {};
	rec(s, a, l, k, 0, n,0);
	cout << mai.size() << endl;
	for ( int i = 0; i < mai.size(); i++ ) {
		cout << mai[i] << " ";
	}
	return 0;
}