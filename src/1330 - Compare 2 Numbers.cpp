#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	
	string str = "";
	
	if(a>b) {
		str = ">";
	}
	else if (a==b) {
		str = "==";
	}
	else {
		str = "<";
	}
	
	cout << str << '\n';
	
	return 0;
}
