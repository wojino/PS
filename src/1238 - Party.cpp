#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int n, m, x;
int dist[1010];
int timearr[1010];
vector<pi> arr[1010];

void dijkstra(int start) {
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }

    priority_queue<pi> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().f;
        int cur = pq.top().s;
        pq.pop();

        if(dist[cur] < cost) continue;
        for(int i=0; i<arr[cur].size(); i++) {
            int next = arr[cur][i].f;
            int ncost = arr[cur][i].s;

            if(dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x;
    int a, b, t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        arr[a].push_back({b, t});
    }

    for(int i=1; i<=n; i++) {
        dijkstra(i);
        timearr[i] = dist[x];
    }
    dijkstra(x);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        timearr[i] += dist[i];
        if(timearr[i] > ans) {
            ans = timearr[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
