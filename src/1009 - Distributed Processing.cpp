#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int res;
	cin >> t;
	while(t--) {
		res = 1;
		cin >> a >> b;
		for(int i=0; i<b; i++) {
			res = res * a % 10;
		}
		
		if (res == 0) {
			res = 10;
		}
		cout << res << '\n';
	}
	
	return 0;
}
