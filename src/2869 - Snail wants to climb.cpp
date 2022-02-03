#include <bits/stdc++.h> 
using namespace std;

int a, b, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> v;
	cout << (v-b-1)/(a-b)+1 << '\n';
	
    return 0;
}
