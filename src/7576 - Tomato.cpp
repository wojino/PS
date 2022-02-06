#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int m, n;
int arr[1010][1010];
int dx[6] = {-1, 1, 0, 0};
int dy[6] = {0, 0, -1, 1};

queue<pi> q;

void search() {
    while(!q.empty()) {
        int x = q.front().f;
        int y = q.front().s;
        q.pop();

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny] == 0) {
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;

    memset(arr, -1, sizeof(arr));
    for(int j=1; j<=n; j++) {
        for(int k=1; k<=m; k++) {
            cin >> arr[j][k];
            if(arr[j][k] == 1) {
                q.push({j, k});
            }
        }
    }

    search();

    int ans = 0;
    for(int j=1; j<=n; j++) {
        for(int k=1; k<=m; k++) {
            if(arr[j][k] == 0) {
                cout << "-1\n";
                return 0;
            }
            if(arr[j][k] > ans) {
                ans = arr[j][k];
            }
        }
    }
    
    cout << ans - 1 << '\n';

    return 0;
}
