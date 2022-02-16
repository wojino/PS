#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, ans, endNode;
vector<pi> t[10010];
bool chk[10010];

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
    cin >> n;
    int parent, child, w;
    for(int i=0; i<n-1; i++) {
        cin >> parent >> child >> w;
        t[parent].push_back({child, w});
        t[child].push_back({parent, w});
    }
    
    search(1, 0);
    memset(chk, false, sizeof(chk));
    search(endNode, 0);

    cout << ans << '\n';
    
    return 0;
}
