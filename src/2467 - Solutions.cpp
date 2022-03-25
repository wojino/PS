#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
vector<int> v;

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

    int ptr1 = 0, ptr2 = n-1;
    int ans1, ans2, tmp;
    int min = 2000000000;
    while(ptr1 < ptr2) {
        tmp = v[ptr1] + v[ptr2];
        if(abs(tmp) < min) {
            min = abs(tmp);
            ans1 = v[ptr1];
            ans2 = v[ptr2];
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
    
    cout << ans1 << ' ' << ans2 << '\n';
    
    return 0;
}
