#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.ignore();
    
    queue<int> q;
    while(n--) {
        getline(cin, str);

        if(str.length() >= 6) { // push X
            q.push(stoi(str.substr(5)));
        }
        else if(str == "pop") { // pop
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size") { // size
            cout << q.size() << '\n';
        }
        else if(str == "empty") { // empty
            cout << q.empty() << '\n';
        }
        else if(str == "front") { // front
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else { // back
            if(q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
    
    return 0;
}
