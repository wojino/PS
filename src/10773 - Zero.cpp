#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int k, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    
    stack<int> s;
    while(k--) {
        cin >> tmp;
        if(tmp == 0) {
            s.pop();
        }
        else {
            s.push(tmp);
        }
    }

    int sum=0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}
