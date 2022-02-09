#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
string tmp;
int arr[70][70];

bool isvalid(int n, int x, int y);
string quadtree(int n, int x, int y);

bool isValid(int n, int x, int y) {
    return ((quadtree(n/2, x, y) == quadtree(n/2, x+n/2, y))
         && (quadtree(n/2, x+n/2, y) == quadtree(n/2, x, y+n/2))
         && (quadtree(n/2, x, y+n/2) == quadtree(n/2, x+n/2, y+n/2))
         && ((quadtree(n/2, x, y) == "1") || (quadtree(n/2, x, y) == "0")));
}

string quadtree(int n, int x, int y) {
    if(n == 1)
        return to_string(arr[y][x]);
    else if(isValid(n, x, y)) {
        return quadtree(n/2, x, y);
    }
    else {
        return ("(" + quadtree(n/2, x, y) + quadtree(n/2, x+n/2, y)
              + quadtree(n/2, x, y+n/2) + quadtree(n/2, x+n/2, y+n/2) + ")");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        for(int j=0; j<n; j++) {
            arr[i][j] = (int)tmp[j] - '0';
        }
    }

    string ans = quadtree(n, 0, 0);
    cout << ans << '\n';
    
    return 0;
}
