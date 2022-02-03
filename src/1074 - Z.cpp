#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int quad(int n, int r, int c) {
	if(n==0) {
		return 0;
	}
	int cnt, y, x, newr, newc;
	y = r / int(pow(2, n-1));
	x = c / int(pow(2, n-1));
	newr = r % int(pow(2, n-1));
	newc = c % int(pow(2, n-1));
	
	cnt = (y*2+x)*int(pow(2, 2*n-2));

	return cnt + quad(n-1, newr, newc);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r >> c;
    
    cout << quad(n, r, c) << '\n';
    
    return 0;
}
