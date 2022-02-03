#include <bits/stdc++.h> 
using namespace std;

int n, m;
int arr[55][55];
int board[8][8];

int find(int x, int y) {
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			board[i][j] = arr[i+x][j+y];
		}
	}
	
	int res1=0, res2=0;
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(board[i][j] == (i+j)%2) {
				res1++;
			}
			else {
				res2++;
			}
		}
	}
	
	if(res1<res2) {
		return res1;
	}
	else {
		return res2;
	}
	
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	char c;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> c;
			if(c=='W') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
	
	int tmp=1;
	int mn = 64;
	
	for(int i=0; i<n-7; i++) {
		for(int j=0; j<m-7; j++) {
			tmp = find(i, j);
			
			if(tmp<mn) {
				mn = tmp;
			}
		}
	}
	
	cout << mn << '\n';
	
	return 0;
}
