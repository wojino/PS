#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
int idx[100010];
int inOrder[100010];
int postOrder[100010];

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart > inEnd || postStart > postEnd) {
        return;
    }

    int root = idx[postOrder[postEnd]];
    int leftSize = root - inStart;
    int rightSize = inEnd - root;
    cout << inOrder[root] << ' ';

    getPreOrder(inStart, root - 1, postStart, postStart + leftSize - 1);
    getPreOrder(root + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> inOrder[i];
        idx[inOrder[i]] = i;
    }
    for(int i=0; i<n; i++) {
        cin >> postOrder[i];
    }

    getPreOrder(0, n-1, 0, n-1);
    
    return 0;
}
