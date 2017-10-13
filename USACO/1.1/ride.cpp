/*
ID: soroosh4
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("ride.in","r",stdin),freopen("ride.out","w",stdout)
#define frs first
#define scn second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int main()
{
	Init;
	WFile;
	Solution();
    return 0;
}

void Solution(){
	string a,b;
	cin >> a >> b;
	int sa=1,sb=1;
	for(int i = 0;i < a.length();i++){
		sa *= a[i]-64;
		sa %= 47;
	}
	for(int i = 0;i < b.length();i++){
		sb *= b[i]-64;
		sb %= 47;
	}
	if(sb == sa)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
}
