#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

ll INF = (ll) 1000000000 * 2000;
int n, m, a, b, k;
int uarr[2010];
int varr[2010];

ll dist[105000];
vector<pi> arr[105000];

void dijkstra(int start) {
    for(int i=1; i<=n*(k+1); i++) {
        dist[i] = INF;
    }

    priority_queue<pi> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        ll cost = -pq.top().f;
        int cur = pq.top().s;
        pq.pop();

        if(dist[cur] < cost) continue;
        for(int i=0; i<arr[cur].size(); i++) {
            int next = arr[cur][i].f;
            ll ncost = arr[cur][i].s;

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
    cin >> n >> m >> a >> b;
    int u, v, t;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> t;
        uarr[i] = u;
        varr[i] = v;
        arr[u].push_back({v, t});
        arr[v].push_back({u, t});
    }
    
    cin >> k;
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=m; j++) {
            cin >> t;
            arr[uarr[j] + i*n].push_back({varr[j] + i*n, t});
            arr[varr[j] + i*n].push_back({uarr[j] + i*n, t});
        }
        
    }

    for(int i=0; i<k; i++) {
        for(int j=1; j<=n; j++) {
            arr[j + i*n].push_back({j + (i+1)*n, 0});
            arr[j + i*n].push_back({j + (i+1)*n, 0});
        }
    }

    dijkstra(a);

    ll ans = dist[b];
    for(int i=1; i<=k; i++) {
        ans = min(ans, dist[b + i*n]);
    }
    cout << ans << '\n';

    return 0;
}
