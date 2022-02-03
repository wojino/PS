#include <bits/stdc++.h> 
using namespace std;

int n, tmp;
int mn = 1000000;
int mx = -1000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp>mx) {
			mx = tmp;
		}
		if(tmp<mn) {
			mn = tmp;
		}
	}
	cout << mn << ' ' << mx << '\n';
	
	return 0;
}
