#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

struct idx {
    int y, x, z;
};

int n, m;
string str;
int a[1003][1003];
int chk[1003][1003][2];
queue<idx> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve() {
    memset(chk, -1, sizeof(chk));

    q.push({1, 1, 0});
    chk[1][1][0] = 1;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        q.pop();
        if(y == n && x == m) {
            return chk[y][x][z];
        }

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(a[ny][nx] == 0 && chk[ny][nx][z] == -1) {
                chk[ny][nx][z] = chk[y][x][z] + 1;
                q.push({ny, nx, z});
            }
            if(a[ny][nx] == 1 && z == 0 && chk[ny][nx][z] == -1) {
                chk[ny][nx][1] = chk[y][x][0] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin.ignore();
    memset(a, -1, sizeof(a));
    for(int i=1; i<=n; i++) {
        getline(cin, str);
        for(int j=1; j<=m; j++) {
            a[i][j] = str[j-1] - '0';
        }
    }

    cout << solve() << '\n';
    
    return 0;
}
