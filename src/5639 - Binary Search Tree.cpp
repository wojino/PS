#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

vector<int> t;

void preToPost(int l, int r) {
    int parent = l;
    int pos = l;

    while(t[++pos] < t[parent] && pos < t.size());

    if(l + 1 <= pos - 1) {
        preToPost(l + 1, pos - 1);
    }
    if(pos <= r) {
        preToPost(pos, r);
    }

    cout << t[parent] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    while(cin >> tmp) {
        t.push_back(tmp);
    }
    
    preToPost(0, t.size() - 1);
    
    return 0;
}
