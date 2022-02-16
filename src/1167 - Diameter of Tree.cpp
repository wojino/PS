#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int v, ans, endNode;
vector<pi> t[100010];
bool chk[100010];

void search(int node, int len) {
    if(chk[node]) {
        return;
    }
    chk[node] = true;

    if(len > ans) {
        ans = len;
        endNode = node;
    }
    
    for(int i=0; i<t[node].size(); i++) {
        search(t[node][i].f, len + t[node][i].s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v;
    int v1, v2, w;
    for(int i=0; i<v; i++) {
        cin >> v1;
        while(1) {
            cin >> v2;
            if(v2 == -1) break;
            cin >> w;
            t[v1].push_back({v2, w});
            t[v2].push_back({v1, w});
        }
    }

    search(1, 0);
    memset(chk, false, sizeof(chk));
    search(endNode, 0);

    cout << ans << '\n';
    
    return 0;
}
