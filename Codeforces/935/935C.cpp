//In The Name of Allah
//Mon 30/11/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	ld r,x1,y1,x2,y2;
	cout << fixed << setprecision(15);
	cin >> r >> x1 >> y1 >> x2 >> y2;
	if(r*r > (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)){
		if(x1 == x2 && y1 == y2){
			cout << (2*x1+r)/2 << " " << y1 << " " << r/2 << endl;
			return;
		}
		ld rat = r/sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		ld x3 = rat*(x1-x2)+x1;
		ld y3 = rat*(y1-y2)+y1;
		ld x = (x3+x2)/2;
		ld y = (y3+y2)/2;
		ld rr = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
		cout << x << " " << y << " " << rr << endl;
	}else{
		cout << x1 << " " << y1 << " " << r << endl;
	}
}
