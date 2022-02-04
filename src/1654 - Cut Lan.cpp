#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int k, n;
ll ans = 0;
int arr[10010];

int search(ll lo, ll hi) {
    if(lo > hi) {
        return 0;
    }

    ll mid = (lo + hi) / 2;
    ll sum = 0;
    for(int i=0; i<k; i++) {
        sum += (arr[i] / mid);
    }

    if(sum>=n) {
        ans = mid;
        return search(mid+1, hi);
    }
    else {
        return search(lo, mid-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> k >> n;
    ll lo = 1, hi = 0;
    for(int i=0; i<k; i++) {
        cin >> arr[i];
        if(arr[i]>hi) {
            hi = arr[i];
        }
    }
    
    search(lo, hi);
    cout << ans << '\n';
    
    return 0;
}
