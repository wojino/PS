#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m=0;
	int k;
	for(int i=0; i<9; i++) {
		cin >> arr[i];
		if(arr[i]>m) {
			k = i+1;
			m = arr[i];
		}
	}
	cout << m << '\n' << k << '\n';
    
	return 0;
}
