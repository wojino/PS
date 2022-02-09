#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, ans = 0;
int lvl = 2, eat = 0;
int arr[25][25];
bool visited[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Shark {
    int x, y, d;
    // d > y > x
    bool operator < (const Shark &s) const {
        if(d == s.d) {
            if(y == s.y)
                return x > s.x;
            else
                return y > s.y;
        }
        else
            return d > s.d;
    }
};

priority_queue<Shark> q;

void search() {
    while(!q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        int d = q.top().d;
        q.pop();

        if(arr[y][x] > 0  && arr[y][x] < lvl) {
            arr[y][x] = 0;
            eat++;
            if(eat == lvl) {
                lvl++;
                eat = 0;
            }
            ans += d;
            d = 0;
            memset(visited, false, sizeof(visited));
            while(!q.empty()) q.pop();
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(arr[ny][nx] != -1 && !visited[ny][nx] && (arr[ny][nx] >= 0 && arr[ny][nx] <= lvl)) {
                q.push({nx, ny, d+1});
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(arr, -1, sizeof(arr));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                q.push({j, i, 0});
                arr[i][j] = 0;
            }
        }
    }
    
    search();
    cout << ans << '\n';
    
    return 0;
}
