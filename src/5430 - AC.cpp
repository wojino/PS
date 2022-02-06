#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int t, n;
string p;
string arr;
string tmp;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        ans = "";
        tmp = "";
        bool flag = false;
        deque<int> dq;
        cin >> p >> n >> arr;
        for(int i=1; i<arr.length(); i++) {
            if((arr[i] == ',' || arr[i] == ']') && tmp.length()) {
                dq.push_back(stoi(tmp));
                tmp = "";
            }
            else {
                tmp += arr[i];
            }
        }
        
        for(int i=0; i<p.length(); i++) {
            if(p[i] == 'R') {
                flag = !flag;
            }
            else if(p[i] == 'D' && !dq.empty()) {
                if(flag) dq.pop_back();
                else dq.pop_front();
            }
            else {
                ans = "error";
                break;
            }
        }

        if(ans != "error" && dq.empty()) {
            ans = "[]";
        }
        else if(ans != "error") {
            ans += '[';
            while(!dq.empty()) {
                if(flag) {
                    ans += to_string(dq.back());
                    ans += ',';
                    dq.pop_back();
                }
                else { // not flag
                    ans += to_string(dq.front());
                    ans += ',';
                    dq.pop_front();
                }
            }
            ans[ans.length()-1] = ']';
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
