#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m;
string tmp;
int arr[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pi> q;

void search() {
    q.push({1, 1});
    while(!q.empty()) {
        int x = q.front().f;
        int y = q.front().s;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(arr[ny][nx] == 1) {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(arr, -1, sizeof(arr));
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        for(int j=1; j<=m; j++) {
            arr[i][j] = (int)tmp[j-1] - '0';
        }
    }
    
    search();
    cout << arr[n][m] << '\n';
    
    return 0;
}
