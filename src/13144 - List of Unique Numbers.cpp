#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int arr[100100];
bool chk[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    int ptr1 = 0, ptr2 = -1;
    while(ptr2+1 < n) {
        if(chk[arr[ptr2+1]] == 0) {
            ptr2++;
            ans += (ptr2 - ptr1 + 1);
            chk[arr[ptr2]] = 1;
        }
        else {
            chk[arr[ptr1]] = 0;
            ptr1++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
