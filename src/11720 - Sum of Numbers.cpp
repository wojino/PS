#include <bits/stdc++.h>
using namespace std;

int n;
char tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	int res = 0;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		res += tmp - '0';
	}
	
	cout << res;
	
	return 0;
}
