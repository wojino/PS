#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int n, e, v1, v2;
int dist[801];
vector<pi> arr[801];

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
    cin >> n >> e;
    int a, b, c;
    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }

    int w, w1, w2, w3, w4;
    dijkstra(v1);
    w = dist[v2];
    dijkstra(1);
    w1 = dist[v1];
    w2 = dist[v2];
    dijkstra(n);
    w3 = dist[v1];
    w4 = dist[v2];

    ll ans;
    if (w == INF) {
        ans = -1;
    }
    else {
        ans = w;
        if(w1 + w4 < w2 + w3) {
            if(w1 == INF || w4 == INF) {
                ans = -1;
            }
            else {
                ans += w1 + w4;
            }
        }
        else if(w1 + w4 == w2 + w3){
            if((w1 == INF || w4 == INF) && (w2 == INF || w3 == INF)) {
                ans = -1;
            }
            else {
                ans += w1 + w4;
            }
        }
        else {
            if(w2 == INF || w3 == INF) {
                ans = -1;
            }
            else {
                ans += w2 + w3;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
