#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int arr[301];
int dp[301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp[i] = max(dp[i-2], dp[i-3] + arr[i-1]) + arr[i];
    }

    cout << dp[n] << '\n';
    
    return 0;
}
