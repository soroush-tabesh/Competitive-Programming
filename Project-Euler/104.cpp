//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("104.in","r",stdin),freopen("104.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool check(ll l ,ll r){
	while(l > 1000*1000*1000)
		l/=10;
	bool mark[10];
	int cnt = 0;
	memset(mark,0,sizeof mark);
	while(l > 0){
		if(!mark[l%10] && l%10 != 0){
			mark[l%10] = 1;
			cnt ++;
		}
		l/=10;
	}
	int cnt2 = 0;
	memset(mark,0,sizeof mark);
	while(r > 0){
		if(!mark[r%10] && r%10 != 0){
			mark[r%10] = 1;
			cnt2 ++;
		}
		r/=10;
	}
	if(cnt2 >= 9 && cnt >= 9 ){
		return true;
	}
	return false;
}

void Solution(){
	
	cout.precision(2);
	cout << fixed;
	
	ll p = 1;
	ll pp = 1;

	ld lim = pow(10,10);

	ld phi = sqrt(double(5));
	phi += double(1);
	phi /= double(2);
	
	ld phip = sqrt(double(5));
	phip *= double(-1);
	phip += double(1);
	phip /= double(2);
	
	ld t1 = phi*phi;
	ld t2 = phip*phip;

	fori(i,3,1000*1000){
		
		t1*=phi;
		while(t1 > lim)
			t1 /= 10;
		t2*=phip;
		while(t2 > lim)
			t2 /= 10;
		ld ans = t1 - t2;
		ans /= sqrt(double(5));
		ll rd = p + pp;
		rd %= 1000*1000*1000;
		pp = p;
		p = rd;
	
		if(check(llround(trunc(ans)) , rd)){
			cout << i << endl;
			return;
		}
	}
	
}
