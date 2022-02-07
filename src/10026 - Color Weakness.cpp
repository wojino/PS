#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int cnt = 0;
char tmp;
int arr1[105][105];
int arr2[105][105];
int visit1[105][105];
int visit2[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pi> q;

int search(int arr[105][105], int visit[105][105]) {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(visit[i][j] == 0) {
                cnt++;
                q.push({i, j});
                visit[i][j] = cnt;
                while(!q.empty()) {
                    int y = q.front().f;
                    int x = q.front().s;
                    q.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(arr[ny][nx] != 0 && arr[ny][nx] == arr[y][x] && visit[ny][nx] == 0) {
                            visit[ny][nx] = cnt;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> tmp;
            if(tmp == 'R') {
                arr1[i][j] = 1;
                arr2[i][j] = 1;
            }
            else if(tmp == 'G') {
                arr1[i][j] = 2;
                arr2[i][j] = 1;
            }
            else {// tmp == 'B'
                arr1[i][j] = 3;
                arr2[i][j] = 3;
            }
        }
    }

    cout << search(arr1, visit1) << ' ' << search(arr2, visit2) << '\n';
    
    return 0;
}
