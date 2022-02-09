#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, k;
int visited[200010];
queue<int> q;

int search() {
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == k) {
            return visited[x] - 1;
        }

        int nx;
        nx = x + 1;
        if(nx < 200010 && visited[nx] == 0) {
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
        nx = x - 1;
        if(nx >= 0 && visited[nx] == 0) {
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
        nx = 2 * x;
        if(nx < 200010 && visited[nx] == 0) {
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    memset(visited, 0, sizeof(visited));
    q.push(n);
    visited[n] = 1;
    cout << search() << '\n';

    return 0;
}
