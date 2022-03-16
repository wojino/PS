#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, d, k, c;
int arr[3000010];
int chk[3010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d >> k >> c;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    chk[c] = 1;

    int tmp = 1;
    for(int i=0; i<k; i++) {
        if(chk[arr[i]] == 0) {
            tmp++;
        }
        chk[arr[i]]++;
    }

    int ans = tmp;
    for(int i=0; i<n; i++) {
        chk[arr[i]]--;
        if(chk[arr[i]] == 0) {
            tmp--;    
        }

        chk[arr[(i+k)%n]]++;
        if(chk[arr[(i+k)%n]] == 1) {
            tmp++;
        }

        ans = max(ans, tmp);
    }

    cout << ans << '\n';
    
    return 0;
}
