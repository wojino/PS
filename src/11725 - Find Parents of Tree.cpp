#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, tmp1, tmp2;
vector<vector<int>> v;
int parent[100001];

void search(int x) {
    for(int i=0; i<v[x].size(); i++) {
        if(parent[v[x][i]] == 0) {
            parent[v[x][i]] = x;
            search(v[x][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    v.resize(n + 1);
    for(int i=0; i<n-1; i++) {
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    
    parent[1] = 1;
    search(1);
    for(int i=2; i<=n; i++) {
        cout << parent[i] << '\n';
    }
    
    return 0;
}
