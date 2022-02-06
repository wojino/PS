#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int t, k, tmp;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        multiset<int> ms;
        cin >> k;
        cin.ignore();
        for(int i=0; i<k; i++) {
            getline(cin, str);
            tmp = stoi(str.substr(2));

            if(str[0] == 'I') {
                ms.insert(tmp);
            }
            else if(str[0] == 'D') {
                if(!ms.empty()) {
                    if(tmp == 1) { // D 1
                        ms.erase(--ms.end());
                    }
                    else { // D -1
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
    
    return 0;
}
