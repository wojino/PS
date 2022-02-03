#include <bits/stdc++.h>
using namespace std;
 
int t;
int m, n, k;
int x, y;
int arr[55][55];

int adj(int x, int y) {
	if(x<0 || y<0) {
		return 0;
	}
	
	if(arr[x][y]) {
		arr[x][y]=0;
		adj(x-1, y);
		adj(x+1, y);
		adj(x, y-1);
		adj(x, y+1);
	}
	
	return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    
    while(t--) {
    	cin >> m >> n >> k;
    	for(int i=0; i<k; i++) {
    		cin >> x >> y;
    		arr[x][y] = 1;
		}
		
		int cnt=0;
		
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				if(arr[i][j]) {
					adj(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << "\n";
	}
    
    return 0;
}
