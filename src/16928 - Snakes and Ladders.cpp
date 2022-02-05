#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m, x, y, u, v;
int mv[101];
int arr[101];
queue<int> q;

void search() {
    memset(arr, -1, sizeof(arr));

    q.push(1);
    arr[1] = 0;
    while(!q.empty()) {
        int start = q.front();
        q.pop();

        for(int i=1; i<=6; i++) {
            int end = start + i;
            if(end > 100) {
                continue;
            }
            if(mv[end]) {
                end = mv[end];
            }
            if(arr[end] == -1) {
                arr[end] = arr[start]+1;
                q.push(end);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        mv[x] = y;
    }
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        mv[u] = v;
    }
    
    search();

    cout << arr[100] << '\n';
    
    return 0;
}
