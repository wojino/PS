#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m;
vector<int> v;

int solve(int idx, int length) {
    if(length == m) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return 0;
    }

    for(int i=idx; i<=n; i++) {
        v.push_back(i);
        solve(i, length + 1);
        v.pop_back();
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    solve(1, 0);

    
    return 0;
}
