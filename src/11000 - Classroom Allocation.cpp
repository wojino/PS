#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
pi arr[200100];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].f >> arr[i].s;
    }

    sort(arr, arr+n);

    pq.push(arr[0].s);
    for(int i=1; i<n; i++) {
        if(pq.top() <= arr[i].f) {
            pq.pop();
            pq.push(arr[i].s);
        }
        else {
            pq.push(arr[i].s);
        }
    }
    
    cout << pq.size() << '\n';
    
    return 0;
}
