#include <bits/stdc++.h>
using namespace std;
 
int t;
int arr[50][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    
    arr[0][0]=0;
    arr[0][1]=1;
    arr[1][0]=1;
	arr[1][1]=0;
	
	for(int i=2;i<43;i++) {
		arr[i][0] = arr[i-2][0] + arr[i-1][0];
		arr[i][1] = arr[i-2][1] + arr[i-1][1];
	}
    
    int n;
    
    for(int i=0;i<t;i++) {
    	cin>>n;
    	cout<<arr[n][1]<<" "<<arr[n][0]<<"\n";
	}
    
    return 0;
}
