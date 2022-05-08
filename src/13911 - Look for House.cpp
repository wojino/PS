#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int v, e;
int dist[10010][2];
vector<pi> arr[10010];
int mc, st;
int mx, sx;
bool notHouse[10010];

void dijkstra(int start, int state) {
    for(int i=1; i<=v+2; i++) {
        dist[i][state] = INF;
    }

    priority_queue<pi> pq;
    pq.push({0, start});
    dist[start][state] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().f;
        int cur = pq.top().s;
        pq.pop();

        for(int i=0; i<arr[cur].size(); i++) {
            int next = arr[cur][i].f;
            int ncost = arr[cur][i].s;

            if(dist[next][state] > cost + ncost) {
                dist[next][state] = cost + ncost;
                pq.push({-dist[next][state], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;
    
    int x, y, w;
    for(int i=0; i<e; i++) {
        cin >> x >> y >> w;
        arr[x].push_back({y, w});
        arr[y].push_back({x, w});
    }

    int tmp;
    cin >> mc >> mx;
    for(int i=0; i<mc; i++) {
        cin >> tmp;
        arr[v+1].push_back({tmp, 0});
        notHouse[tmp] = 1;
    }
    cin >> st >> sx;
    for(int i=0; i<st; i++) {
        cin >> tmp;
        arr[v+2].push_back({tmp, 0});
        notHouse[tmp] = 1;
    }

    dijkstra(v+1, 0);
    dijkstra(v+2, 1);

    int ans = 2*INF;
    int my, sy;
    for(int i=1; i<=v; i++) {
        if(notHouse[i]){
            continue;
        }

        my = dist[i][0];
        sy = dist[i][1];
        
        if(my == INF || my == 0 || sy == INF || sy == 0) {
            continue;
        }
        
        if(my <= mx && sy <= sx) {
            ans = min(ans, my + sy);
        }
    }
    
    if(ans == 2*INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}
