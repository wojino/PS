#include <bits/stdc++.h>
#define f first
#define s second
#define INF 987654321;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

string s;
int n;
int dp[2501];
int pal[2501][2501];

bool isPal(int i, int j) {
    if(i == j) return true;
    if(i + 1 == j) return s[i] == s[j];

    int &ret = pal[i][j];
    if(ret != -1) return ret;

    return ret = (s[i] == s[j] && isPal(i + 1, j - 1));
}

int solve(int x) {
    if (x == n) return 0;

    int &ret = dp[x];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=x; i<n; i++) {
        if(isPal(x, i)) {
            ret = min(ret, 1 + solve(i + 1));
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    memset(pal, -1, sizeof(pal));
    cin >> s;
    n = s.length();

    cout << solve(0);
    
    return 0;
}
