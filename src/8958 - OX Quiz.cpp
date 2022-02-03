#include <bits/stdc++.h> 
using namespace std;

int t, tmp, sum;
string str;
int arr[90];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {
		for(int i=0; i<90; i++) {
			arr[i] = 0;
		}
		
		tmp = 0;
		cin >> str;
		for(int i=0; i<str.length(); i++) {
			if(str[i]=='O') {
				tmp++;
				if(i==str.length()-1) {
					arr[i] = tmp;
				}
			}
			else {
				arr[i] = tmp;
				tmp = 0;
			}
		}
		sum = 0;
		for(int i=0; i<str.length(); i++) {
			sum += arr[i]*(arr[i]+1)/2;
		}
		
		cout << sum << '\n';
	}
	
	return 0;
}
