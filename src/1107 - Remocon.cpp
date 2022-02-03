#include <bits/stdc++.h> 
using namespace std;
 
int n, m;
int arr[15];
int ans;

void find(string num) {
	for(int i=0; i<10; i++) {
		if(arr[i]) {
			string tmp = num + to_string(i);
			ans = min(ans, int(abs(n-stoi(tmp))+tmp.length()));
			
			if(tmp.length()<6) {
				find(tmp);
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    ans = abs(n-100);
    
    fill_n(arr, 13, 1);
    int tmp;
    for(int i=0; i<m; i++) {
    	cin>>tmp;
    	arr[tmp]=0;
	}
	
	if(m<10) {
		find("");
	}
	cout<<ans;
	
    return 0;
}
