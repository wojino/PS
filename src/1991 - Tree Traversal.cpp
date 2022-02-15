#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
vector<pi> t(27);

void preOrder(int root) {
    int l = t[root].f;
    int r = t[root].s;
    cout << (char)(root+'A');
    if(l > 0)
        preOrder(l);
    if(r > 0)
        preOrder(r);
}

void inOrder(int root) {
    int l = t[root].f;
    int r = t[root].s;
    if(l > 0)
        inOrder(l);
    cout << (char)(root+'A');
    if(r > 0)
        inOrder(r);
}

void postOrder(int root) {
    int l = t[root].f;
    int r = t[root].s;
    if(l > 0)
        postOrder(l);
    if(r > 0)
        postOrder(r);
    cout << (char)(root+'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    char root, l, r;
    for(int i=0; i<n; i++) {
        cin >> root >> l >> r;
        t[root - 'A'] = {l - 'A', r - 'A'};
    }

    preOrder(0);
    cout << '\n';

    inOrder(0);
    cout << '\n';

    postOrder(0);
    cout << '\n';
    
    return 0;
}
