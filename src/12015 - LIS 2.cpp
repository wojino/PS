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

    v.push_back(0);
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        if(tmp > v.back()) {
            v.push_back(tmp);
        }
        else {
            int ptr = lower_bound(v.begin(), v.end(), tmp) - v.begin();
            v[ptr] = tmp;
        }
    }

    cout << v.size() - 1 << '\n';
    
    return 0;
}
