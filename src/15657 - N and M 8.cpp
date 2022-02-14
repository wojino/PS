#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m, tmp;
priority_queue<int> pq;
vector<int> v;
vector<int> ans;

int solve(int idx, int length) {
    if(length == m) {
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return 0;
    }

    for(int i=idx; i<n; i++) {
        ans.push_back(v[i]);
        solve(i, length + 1);
        ans.pop_back();
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        v.push_back(tmp);
    }
    reverse(v.begin(), v.end());

    solve(0, 0);
    
    return 0;
}
