#include <bits/stdc++.h>
using namespace std;
 
int n, m, v;
int a, b;
int arr[1010][1010];
bool visited[1010];
queue<int> q;

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";
	
	for(int i=1; i<=n; i++) {
		if(arr[v][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	q.push(v);
	visited[v] = 1;
	cout << v << " ";
	
	while(!q.empty()) {
		v = q.front();
		q.pop();
		
		for(int i=1; i<=n; i++) {
			if(arr[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>v;
    
    for(int i=0; i<m; i++) {
    	cin >> a >> b;
    	arr[a][b] = 1;
    	arr[b][a] = 1;
	}
	
	dfs(v);	
	cout << "\n";
	
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	
	bfs(v);
    
    return 0;
}
