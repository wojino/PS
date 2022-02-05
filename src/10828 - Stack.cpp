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
    
    stack<int> s;
    while(n--) {
        getline(cin, str);

        if(str.length() >= 6) { // push X
            s.push(stoi(str.substr(5)));
        }
        else if(str == "pop") { // pop
            if(s.empty()) {
                cout << "-1\n";
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(str == "size") { // size
            cout << s.size() << '\n';
        }
        else if(str == "empty") { // empty
            cout << s.empty() << '\n';
        }
        else { // top
            if(s.empty()) {
                cout << "-1\n";
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }
    
    return 0;
}
