#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int ans = 0;
    int a, b;
    if(pq.size() == 1) {
        ans = 0;
    }
    else {
        while(!pq.empty()) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            ans += a + b;
            if(pq.empty()) {
                break;
            }
            pq.push(a + b);
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
