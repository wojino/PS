#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> y >> w >> h;
	
	cout << min(min(x, w-x), min(y, h-y)) << '\n';
	
	return 0;
}
