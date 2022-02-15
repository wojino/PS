#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

string a, b;
int n, m;
int dp[1001][1001];

int solve(int pos1, int pos2) {
    if(pos1 == n || pos2 == m) {
        return 0;
    }
    if(a[pos1] == b[pos2]) {
        return 1 + solve(pos1 + 1, pos2 + 1);
    }
    
    int &res = dp[pos1][pos2];
    if(res != -1) {
        return res;
    }

    res = max(solve(pos1 + 1, pos2), solve(pos1, pos2 + 1));
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    n = a.length();
    m = b.length();
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0);
        
    return 0;
}
