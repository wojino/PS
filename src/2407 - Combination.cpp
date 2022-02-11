#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, m;
string dp[101][101];

string bigNumAdd(string a, string b) {
    int sum = 0;
    string res;

    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        res.push_back(sum % 10 + '0');
        sum /= 10;
    }

    reverse(res.begin(), res.end());
    
    return res;
}

string c(int n, int r) {
    if(r == 0 || r == n) {
        return "1";
    }
    
    string &res = dp[n][r];
    if(res != "") {
        return res;
    }
    
    res = bigNumAdd(c(n-1, r-1), c(n-1, r));
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    cout << c(n, m) << '\n';
    
    return 0;
}
