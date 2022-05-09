#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m;
priority_queue<int> pq1;
priority_queue<int> pq2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        pq1.push(-x);
    }
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        pq2.push(-x);
    }

    while(!(pq1.empty() && pq2.empty())) {
        if(pq1.empty()) {
            int x = pq2.top();
            pq2.pop();
            cout << -x << ' ';
            continue;
        }
        else if(pq2.empty()){
            int x = pq1.top();
            pq1.pop();
            cout << -x << ' ';
            continue;
        }
        int x1 = pq1.top();
        int x2 = pq2.top();
        
        if(x1 >= x2) {
            pq1.pop();
            cout << -x1 << ' ';
        }
        else {
            pq2.pop();
            cout << -x2 << ' ';
        }
    }
    
    return 0;
}
