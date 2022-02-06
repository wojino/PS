#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int m, n, h;
int arr[110][110][110];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

typedef struct _Index {
    int x, y, z;
} Index;
queue<Index> q;

void search() {
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(arr[nx][ny][nz] == 0) {
                arr[nx][ny][nz] = arr[x][y][z] + 1;
                q.push({nx, ny, nz});
            } 
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> h;

    memset(arr, -1, sizeof(arr));
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                cin >> arr[j][k][i];
                if(arr[j][k][i] == 1) {
                    q.push({j, k, i});
                }
            }
        }
    }

    search();

    int ans = 0;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                if(arr[j][k][i] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                if(arr[j][k][i] > ans) {
                    ans = arr[j][k][i];
                }
            }
        }
    }
    
    cout << ans - 1 << '\n';

    return 0;
}
