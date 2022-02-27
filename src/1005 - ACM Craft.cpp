#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int t, n, k, w;
vector<vector<int>> p;
vector<int> times, dist, inDegree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        p.clear();
        times.clear();
        dist.clear();
        inDegree.clear();

        cin >> n >> k;
        p.resize(n+1);
        times.resize(n+1);
        dist.resize(n+1);
        inDegree.resize(n+1);

        for(int i=1; i<=n; i++) {
            cin >> times[i];
        }
        int x, y;
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            p[x].push_back(y);
            inDegree[y]++;
        }
        cin >> w;

        queue<int> q;
        for(int i=1; i<=n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                dist[i] = times[i];
            }
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(x == w) break;

            for(int i=0; i<p[x].size(); i++) {
                int nx = p[x][i];
                inDegree[nx]--;
                if(inDegree[nx] == 0) {
                    q.push(nx);
                }
                if(dist[nx] < dist[x] + times[nx]) {
                    dist[nx] = dist[x] + times[nx];
                }
            }
        }
        
        cout << dist[w] << '\n';
    }
    
    return 0;
}
