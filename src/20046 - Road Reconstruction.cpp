#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int m, n;
int arr[1010][1010];
int dist[1010][1010];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dijkstra() {
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = INF;
        }
    }

    if(arr[1][1] == -1) {
        return INF;
    }

    priority_queue<pair<int, pi>> pq;
    pq.push({-arr[1][1], {1, 1}});
    dist[1][1] = arr[1][1];

    while(!pq.empty()) {
        int y = pq.top().s.f;
        int x = pq.top().s.s;
        int cost = -pq.top().f;
        pq.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ncost = arr[ny][nx];

            if(ncost == -1) {
                continue;
            }
            if(ny < 1 || ny > m || nx < 1 || nx > n) {
                continue;
            }

            if(dist[ny][nx] > cost + ncost) {
                dist[ny][nx] = cost + ncost;
                pq.push({-dist[ny][nx], {ny, nx}});
            }
        }
    }

    return dist[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = dijkstra();
    if(ans == INF) {
        cout << "-1" << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}
