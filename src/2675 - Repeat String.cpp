#include <bits/stdc++.h> 
using namespace std;

string str;
int t, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {
		cin >> r >> str;
		for(int i=0; i<str.length(); i++) {
			for(int j=0; j<r; j++) {
				cout << str[i];
			}
		}
		cout << '\n';
	}
	
	return 0;
}
