#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, k;
vector<pi> item;
int dp[100001][101];

int knapsack(int w, int idx) {
    if(idx == n) {
        return 0;
    }

    int nw = item[idx].f;
    int nv = item[idx].s;
    int &res = dp[w][idx];
    if(res != 0) {
        return res;
    }

    if(w + nw <= k) {
        res = knapsack(w + nw, idx + 1) + nv;
    }
    res = max(res, knapsack(w, idx + 1));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int w, v;
    for(int i=0; i<n; i++) {
        cin >> w >> v;
        item.push_back({w, v});
    }

    cout << knapsack(0, 0) << '\n';
    
    return 0;
}
