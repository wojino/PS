#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int n, m, startCity, endCity;
int dist[20010];
vector<pi> arr[20010];

void dijkstra(int start) {
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
    cin >> n >> m;
    int x, y, w;
    for(int i=0; i<m; i++) {
        cin >> x >> y >> w;
        arr[x].push_back({y, w});
    }
    cin >> startCity >> endCity;
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }

    dijkstra(startCity);
    cout << dist[endCity] << '\n';
    
    return 0;
}
