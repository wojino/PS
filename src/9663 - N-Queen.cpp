#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, res;
bool arr[15][15];

bool isPossible(int y, int x) {
    for(int i=0; i<y; i++) {
        if(arr[i][x]) return false;
        if(x+y-i >= 0 && x+y-i < n && arr[i][x+y-i]) return false;
        if(x-y+i >= 0 && x-y+i < n && arr[i][x-y+i]) return false;
    }

    return true;
}

void search(int y) {
    if(y == n) {
        res++;
    }
    else {
        for(int i=0; i<n; i++) {
            if(!arr[y][i] && isPossible(y, i)) {
                arr[y][i] = true;
                search(y + 1);
                arr[y][i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    search(0);
    cout << res << '\n';
    
    return 0;
}
