#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, s;
int arr[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ptr1 = 0, ptr2 = 1;
    int sum = arr[0];
    int res = 100000;

    while(ptr2 <= n) {
        if(sum >= s && ptr2 - ptr1 > 1) {
            res = min(res, ptr2-ptr1);
            sum -= arr[ptr1];
            ptr1++;
        }
        else {
            if(sum >= s && ptr2 - ptr1 == 1) {
                res = min(res, ptr2-ptr1);
            }
            sum += arr[ptr2];
            ptr2++;
        }
    }
    if(res == 100000) {
        cout << 0 << '\n';
    }
    else {
        cout << res << '\n';
    }

    return 0;
}
