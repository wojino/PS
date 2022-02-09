#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int visited[1000100];
queue<int> q;

int search() {
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == 1) {
            return visited[x] - 1;
        }

        int nx;
        if(x % 3 == 0) {
            nx = x / 3;
            if(!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
        if(x % 2 == 0) {
            nx = x / 2;
            if(!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
        if(x - 1 >= 1) {
            nx = x - 1;
            if(!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    cout << search() << '\n';
    
    return 0;
}
