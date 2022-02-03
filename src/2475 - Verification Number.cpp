#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n, m;
int ans = 0;
int arr[1000010];

int search(int lo, int hi) {
	if (lo>hi) {
		return 0;
	}

	int mid = (lo + hi) / 2;
	ll sum = 0;
	for(int i=0; i<n; i++) {
		if(arr[i]-mid>0) {
			sum += arr[i] - mid;
		}
	}
	
	if(sum>=m) {
		if(mid>ans) {
			ans = mid;
		}
		return search(mid+1, hi);
	}
	else {
		return search(lo, mid-1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	int lo = 0, hi = 0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i]>hi) {
			hi = arr[i];
		}
	}
	
	search(lo, hi);
	cout << ans << '\n';
	
	return 0;
}
