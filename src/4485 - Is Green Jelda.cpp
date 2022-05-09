#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int n;
int arr[130][130];
int dist[130][130];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dijkstra() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue<pair<int, pi>> pq;
    pq.push({-arr[1][1], {1, 1}});
    dist[1][1] = arr[1][1];

    while(!pq.empty()) {
        int x = pq.top().s.f;
        int y = pq.top().s.s;
        int cost = -pq.top().f;
        pq.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = arr[nx][ny];
            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }
            if(dist[nx][ny] > cost + ncost) {
                dist[nx][ny] = cost + ncost;
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 0;
    while(true) {
        t++;
        cin >> n;
        if(n == 0) {
            break;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cin >> arr[i][j];
            }
        }

        dijkstra();
        cout << "Problem " << t << ": " << dist[n][n] << '\n';
    }
    
    return 0;
}
