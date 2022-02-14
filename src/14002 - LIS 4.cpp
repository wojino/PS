#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int arr[1001];
int dp[1001];
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        
        for(int j=0; j<n; j++) {
            if(arr[j] < arr[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if(dp[i] > ans) {
            ans = dp[i];
        }
    }
    
    cout << ans << '\n';

    for(int i=n-1; i>=0; i--) {
        if(dp[i] == ans) {
            s.push(arr[i]);
            ans--;
        }
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
