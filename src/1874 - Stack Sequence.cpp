#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    stack<int> s;

    int ptr = 0;
    for(int i=1; i<=n; i++) {
        s.push(i);
        str += "+\n";

        while(!s.empty() && s.top() == arr[ptr]) {
            ptr++;
            s.pop();
            str += "-\n";
        }
    }

    if(!s.empty()) {
        cout << "NO\n";
    }
    else {
        cout << str;
    }

    return 0;
}
