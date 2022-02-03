#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=0;
    int ptr = 0;
    
    string str;
    getline(cin, str);
    if(str == " ") {
        printf("0");
        return 0;
    }
    
    while(true) {
        if(ptr >= str.length()) {
            break;
        }
        else if(str.find(' ', ptr) == 0) {
            ptr++;
        }
        else if(str.find(' ', ptr) != string::npos) {
            n++;
            ptr = str.find(' ', ptr)+1;
        }
        else if(str.find(' ', ptr) == string::npos) {
            break;
        }
        
    }
    if(str[str.length()-1] == ' ') {
        cout << n << "\n";
        return 0;
    }
    
    cout << n+1 << "\n";
    
    return 0;
}
