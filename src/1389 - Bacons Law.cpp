#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m, a, b;
bool arr[101][101];
int visited[101];

int search(int a) {
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(a);
    visited[a] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=1; i<=n; i++) {
            if(arr[x][i] == 1 && visited[i] == -1) {
                q.push(i);
                visited[i] = visited[x] + 1;
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans += visited[i];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    int mn = 5010;
    int ans, tmp;
    for(int i=1; i<=n; i++) {
        tmp = search(i);
        if(tmp < mn) {
            mn = tmp;
            ans = i;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
