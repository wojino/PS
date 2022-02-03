#include <bits/stdc++.h> 

#define f first
#define s second
using namespace std;

typedef pair<int,int> pi;

int t, n, m, tmp, mdoc;
pi tmppair;
int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	int res;
	while(t--) {
		for(int i=0; i<10; i++) {
			arr[i] = 0;
		}
		
		res = 0;
		queue<pi> q;
	
		cin >> n >> m;
		for(int i=0; i<n; i++) {
			cin >> tmp;
			arr[tmp]++;
			if(i==m) {
				q.push(pi(tmp, 1));
				mdoc = tmp;
			}
			else {
				q.push(pi(tmp, 0));
			}
		}
		
		int mx=10;
		while(true) {
			mx = 0;
		
			for(int i=0; i<10; i++) {
				if(arr[i]>0 && i>mx) {
					mx = i;
				}
			}
			
			if(mdoc>=mx) {
				break;
			}
			
			tmppair = q.front();
			if(tmppair.f == mx) {
				q.pop();
				res++;
				arr[tmppair.f]--;
			}
			else {
				q.pop();
				q.push(tmppair);	
			}
		}
		
		while(true) {
			tmppair = q.front();
			q.pop();
			if(tmppair.f<mdoc) {
				
			}
			else if(tmppair.s==0) {
				res++;
			}
			else {
				res++;
				break;
			}
		}
		
		cout << res << '\n';
		
	}

	return 0;
}
