#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

ll a, b;
queue<pi> q;

int search() {
    q.push({a, 1});

    while(!q.empty()) {
        ll x = q.front().f;
        int cnt = q.front().s;
        q.pop();

        if(x == b) {
            return cnt;
        }

        int nx;
        if(x * 2 <= b) {
            nx = x * 2;
            q.push({nx, cnt + 1});
        }
        if(x * 10 + 1 <= b) {
            nx = x * 10 + 1;
            q.push({nx, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    
    cout << search() << '\n';

    return 0;
}
