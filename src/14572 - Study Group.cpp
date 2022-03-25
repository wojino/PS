#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int n, k, d, m;

struct Student {
    int skill;
    int arr[31] = {};
    bool operator < (const Student &s) const {
        return skill < s.skill;
    }
};

vector<Student> v;
int chk[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> d;
    for(int i=0; i<n; i++) {
        Student s;
        int m, tmp;
        cin >> m >> s.skill;
        for(int j=0; j<m; j++) {
            cin >> tmp;
            s.arr[tmp] = 1;
        }
        v.push_back(s);
    }
    
    sort(v.begin(), v.end());
    
    int ptr1 = 0, ptr2 = -1;
    int ans = 0;
    
    while(ptr2+1 < n) {
        if(v[ptr2+1].skill - v[ptr1].skill <= d) {
            ptr2++;
            for(int i=1; i<=30; i++) {
                if(v[ptr2].arr[i] == 1) {
                    chk[i]++;
                }
            }
            
            int a = 0, b = 0;
            for(int i=1; i<=30; i++) {
                if(chk[i] > 0) {
                    a++;
                }
                if(chk[i] == ptr2 - ptr1 + 1) {
                    b++;
                }
            }
            int e = (a - b) * (ptr2 - ptr1 + 1);
            ans = max(ans, e);
        }
        else {
            for(int i=1; i<=30; i++) {
                if(v[ptr1].arr[i] == 1) {
                    chk[i]--;
                }
            }
            ptr1++;
        }

    }    
    
    cout << ans << '\n';

    return 0;
}
