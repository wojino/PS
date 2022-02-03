#include <bits/stdc++.h> 
#include <string>
using namespace std;

int n, m, b;
int arr[510][510];

int cal(int h, int b) {
	int t = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if (arr[i][j] > h) {
				t += (arr[i][j] - h)*2;
				b += arr[i][j] - h;
			}
			else if (arr[i][j] < h) {
				t += (h - arr[i][j]);
				b -= h - arr[i][j];
			}
		}
	}
	if (b<0) {
		return 256*500*500*2+10;
	}
	
	return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> b;
	
	int mn = 256;
	int mx = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] < mn) {
				mn = arr[i][j];
			}
			if(arr[i][j] > mx) {
				mx = arr[i][j];
			}
		}
	}
	
	int t=256*500*500*2+1;
	int h=0;
	int tmp;
	for(int i=mn; i<=mx; i++) {
		tmp = cal(i, b);
		if(tmp<=t) {
			t = tmp;
			h = i;
		}
	}
	
	cout << t << ' ' << h << '\n';
	
    return 0;
}
