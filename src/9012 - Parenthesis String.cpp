#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int t;
string str;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    int a;
    bool flag;
    while(t--) {
        cin >> str;

        a = 0;
        flag = 1;
        for(int i=0; i<str.length(); i++) {
            if(str[i] == '(') {
                a++;
            }
            else {
                a--;
            }
            
            if(a<0) {
                flag = 0;
            }
        }
        if(a!=0) {
            flag = 0;
        }
        if(flag) {
            ans = "YES";
        }
        else {
            ans = "NO";
        }
        cout << ans << '\n';
    }
    
    return 0;
}
