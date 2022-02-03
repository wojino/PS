#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> a >> b) {
		if (a==0) {
			return 0;
		}
	
		cout << a+b << '\n';
	}

	return 0;
}
