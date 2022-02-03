#include <bits/stdc++.h> 
using namespace std;

int arr[1000010];
int m, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	arr[1] = 1;
	cin >> m >> n;
	for(int i=2; i*i<=n; i++) {
	
		if(arr[i] == 0) {
			for(int j=2; j*i<=n; j++) {
				arr[j*i] = 1;
			}
		}
		
	}
	
	for(int i=m; i<=n; i++) {
		if(arr[i]==0) {
			cout << i << '\n';
		}
	}
	
	return 0;
}
