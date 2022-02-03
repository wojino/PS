#include <bits/stdc++.h> 
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> a >> b >> c) {
		if(a==0) {
			break;
		}
		if(a>c) {
			swap(a, c);
		}
		if(b>c) {
			swap(b, c);
		}
		
		if(a*a+b*b==c*c) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}
