#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int t, a, b;
bool visited[10010];

string search(int a, int b) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;
    q.push({a, ""});

    while(!q.empty()) {
        int x = q.front().f;
        string str = q.front().s;
        q.pop();

        if(x == b) {
            return str;
        }

        int nx;
        // D
        nx = (x * 2) % 10000;
        if(!visited[nx]) {
            visited[nx] = 1;
            q.push({nx, str + "D"});
        }
        // S
        if(x == 0) nx = 9999;
        else nx = x - 1;
        if(!visited[nx]) {
            visited[nx] = 1;
            q.push({nx, str + "S"});
        }
        // L
        nx = (x % 1000) * 10 + (x / 1000);
        if(!visited[nx]) {
            visited[nx] = 1;
            q.push({nx, str + "L"});
        }
        // R
        nx = (x / 10) + (x % 10) * 1000;
        if(!visited[nx]) {
            visited[nx] = 1;
            q.push({nx, str + "R"});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << search(a, b) << '\n';
    }
    
    return 0;
}
