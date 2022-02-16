#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int INF = 987654321;
int v, e, start;
int dist[20010];
vector<pi> arr[20010];

void dijkstra() {
    priority_queue<pi> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().f;
        int cur = pq.top().s;
        pq.pop();

        for(int i=0; i<arr[cur].size(); i++) {
            int next = arr[cur][i].f;
            int ncost = arr[cur][i].s;

            if(dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
    
    for(int i=1; i<=v; i++) {
        if(dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e >> start;
    int x, y, w;
    for(int i=0; i<e; i++) {
        cin >> x >> y >> w;
        arr[x].push_back({y, w});
    }
    for(int i=1; i<=v; i++) {
        dist[i] = INF;
    }

    dijkstra();
    
    return 0;
}
