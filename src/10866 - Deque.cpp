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
    
    deque<int> d;
    while(n--) {
        getline(cin, str);

        if(str.length() >= 11) {
            if(str[5] == 'f') { // push_front
                d.push_front(stoi(str.substr(11)));
            }
            else { // push_back
                d.push_back(stoi(str.substr(10)));
            }
        }
        else if(str == "pop_front") { // pop_front
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(str == "pop_back") { // pop_back
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if(str == "size") { // size
            cout << d.size() << '\n';
        }
        else if(str == "empty") { // empty
            cout << d.empty() << '\n';
        }
        else if(str == "front") { // front
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
            }
        }
        else { // back
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
            }
        }
    }
    
    return 0;
}
