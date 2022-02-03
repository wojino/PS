#include <bits/stdc++.h>
using namespace std;

int arr[30] = {0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	
	for(int i=0; i<str.length(); i++) {
		arr[str[i] - 'A']++;
	}
	
	int mx = 0;
	int tmp;
	int flag = 0;
	char ans;
	for(int i=0; i<26; i++) {
		tmp = arr[i];
		if (tmp > mx) {
			mx = tmp;
			flag = 0;
			ans = 'A' + i;
		}
		else if (tmp == mx) {
			flag = 1;
		}
	}
	
	if (flag == 1) {
		cout << "?\n";
	}
	else {
		cout << ans << "\n";
	}
	
	return 0;
}
