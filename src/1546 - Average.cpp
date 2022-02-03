#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	int m=0;
	float res=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		res += arr[i];
		if(arr[i]>m) {
			m = arr[i];
		}
	}
	
	res = 1.0f * res/m*100/ n;
	
	cout << res << '\n';
	
	return 0;
}
