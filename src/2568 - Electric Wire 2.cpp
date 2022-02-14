#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, x, y;
priority_queue<pi> pq;
vector<pi> arr;
vector<int> v;
vector<pi> dp;
stack<int> s;

int solve() {
    v.push_back(0);
    int tmp;
    for(int i=0; i<n; i++) {
        tmp = arr[i].s;
        if(tmp > v.back()) {
            v.push_back(tmp);
            dp.push_back({v.size() - 1, tmp});
        }
        else {
            int ptr = lower_bound(v.begin(), v.end(), tmp) - v.begin();
            v[ptr] = tmp;
            dp.push_back({ptr, tmp});
        }
    }

    int ans = v.size() - 1;
    cout << n - ans << '\n';

    for(int i=n-1; i>=0; i--) {
        if(dp[i].f == ans) {
            ans--;
        }
        else {
            s.push(arr[i].f);
        }
    }

    while(!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        pq.push({x, y});
    }
    
    while(!pq.empty()) {
        arr.push_back(pq.top());
        pq.pop();
    }
    reverse(arr.begin(), arr.end());

    solve();

    return 0;
}
