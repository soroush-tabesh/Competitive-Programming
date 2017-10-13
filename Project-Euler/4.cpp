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
	//WFile;
	Solution();
	return 0;
}

string num = "0123456789";

bool check(int k){
	string s;
	while(k>0){
		s+=num[k%10];
		k/=10;
	}
	forar(i,s.length()/2){
		if(s[i] != s[s.length()-1-i])
			return false;
	}
	return true;
}

void Solution(){
	int m = 0;
	fori(i,100,1000){
		fori(j,100,1000){
			if(check(i*j)){
				m = max(m,int(i*j));
			}
		}
	}
	cout << m;
}
