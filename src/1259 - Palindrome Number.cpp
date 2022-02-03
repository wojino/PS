#include <bits/stdc++.h> 
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	bool flag=0;
	while(cin >> str) {
		if(str == "0") {
			break;
		}
		
		flag=1;
		for(int i=0; i<str.length()/2; i++) {
			if(str[i] != str[str.length()-1-i]) {
				flag=0;
				break;
			}
		}
		
		if(flag) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
		
	}
	
    return 0;
}
