#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        if(maxHeap.size() == minHeap.size()) {
            maxHeap.push(tmp);
        }
        else {
            minHeap.push(tmp);
        }

        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int x = minHeap.top(), y = maxHeap.top();
            minHeap.pop(); maxHeap.pop();
            minHeap.push(y); maxHeap.push(x);
        }

        cout << maxHeap.top() << '\n';
    }
    
    return 0;
}
