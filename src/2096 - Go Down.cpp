#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int tmp[3];
int dp[2][3][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tmp[0] >> tmp[1] >> tmp[2];

        dp[(i+1)%2][0][0] = tmp[0] + max(dp[i%2][0][0], dp[i%2][1][0]);
        dp[(i+1)%2][1][0] = tmp[1] + max(max(dp[i%2][0][0], dp[i%2][1][0]), dp[i%2][2][0]);
        dp[(i+1)%2][2][0] = tmp[2] + max(dp[i%2][1][0], dp[i%2][2][0]);

        dp[(i+1)%2][0][1] = tmp[0] + min(dp[i%2][0][1], dp[i%2][1][1]);
        dp[(i+1)%2][1][1] = tmp[1] + min(min(dp[i%2][0][1], dp[i%2][1][1]), dp[i%2][2][1]);
        dp[(i+1)%2][2][1] = tmp[2] + min(dp[i%2][1][1], dp[i%2][2][1]);
    }

    int mx = max(max(dp[n%2][0][0], dp[n%2][1][0]), dp[n%2][2][0]);
    int mn = min(min(dp[n%2][0][1], dp[n%2][1][1]), dp[n%2][2][1]);

    cout << mx << ' ' << mn << '\n';
    
    return 0;
}
