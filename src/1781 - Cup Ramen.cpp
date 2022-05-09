#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
pi arr[200200];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].f >> arr[i].s;
    }
    
    sort(arr, arr+n);

    int ans = 0, j = n-1;
    for(int i=n; i>0; i--) {
        while(j>=0 && arr[j].f >= i) {
            pq.push(arr[j].s);
            j--;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
    
    return 0;
}
