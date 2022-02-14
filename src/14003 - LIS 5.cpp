#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
vector<int> v;
vector<pi> dp;
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    v.push_back(-1000000001);
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
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
    cout << ans << '\n';

    for(int i=n-1; i>=0; i--) {
        if(dp[i].f == ans) {
            s.push(dp[i].s);
            ans--;
        }
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    
    return 0;
}
