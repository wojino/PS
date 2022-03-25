#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
vector<ll> v;
ll arr[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    ll tmp;
    ll min = 3000000000;
    for(int i=0; i<n-2; i++) {
        int ptr1 = i+1, ptr2 = n-1;

        while(ptr1 < ptr2) {
            tmp = v[i] + v[ptr1] + v[ptr2];
            if(abs(tmp) < min) {
                min = abs(tmp);
                arr[0] = v[i];
                arr[1] = v[ptr1];
                arr[2] = v[ptr2];
            }
            if(tmp == 0) {
                break;
            }
            else if(tmp > 0) {
                ptr2--;
            }
            else {
                ptr1++;
            }
        }
    }

    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
    
    return 0;
}
