#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m, u, v;
int cnt = 0;
bool arr[1010][1010];
int visited[1010];
queue<int> q;

void search() {
    for(int i=1; i<=n; i++) {
        if(visited[i] == 0) {
            cnt++;
            q.push(i);
            visited[i] = cnt;
            
            while(!q.empty()) {
                int x = q.front();
                q.pop();

                for(int j=1; j<=n; j++) {
                    if(arr[x][j] == 1 && visited[j] == 0) {
                        visited[j] = cnt;
                        q.push(j);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        arr[u][v] = arr[v][u] = 1;
    }
    
    search();
    cout << cnt << '\n';
    
    return 0;
}
