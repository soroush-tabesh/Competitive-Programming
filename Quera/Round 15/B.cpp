#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define pf push_front
#define fr first
#define sc second

using namespace std;

typedef long long int ll;
typedef long double ld;

void solution();

int main(){
	Init;
	solution();
	return 0;
}

void solution(){
	ld a,b,c;
	cin >> a >> b >> c;
	if(a==b&&b==c)
		cout << 0;
	else if( ((a+b) / 2) == c || ((a+c) / 2) == b || ((b+c) / 2) == a )
		cout << 1;
	else
		cout << 2;
}
