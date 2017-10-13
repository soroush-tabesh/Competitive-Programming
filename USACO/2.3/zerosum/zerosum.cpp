/*
ID: soroosh4
LANG: C++11
TASK: zerosum
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("zerosum.in","r",stdin),freopen("zerosum.out","w",stdout)
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

string nums = "0123456789";
string ops = " +-";
set<string> ans;
int n;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int ppow(int base,int exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	int v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v;
}

void Solution(){
	cin >> n;
	forar(mask,ppow(3,n-1)){ // 0 : ' '    1 : '+'    2: '-'
		int r = 0,t = 1,state=1;
		string s = "1";
		// evaluate the mask
		forar(i,n-1){
			if((mask/ppow(3,i))%3 == 0){
				t *= 10;
				t += i+2;
			}else{
				if(state == 1){
					r+=t;
					t=i+2;
				}else{
					r-=t;
					t=i+2;
				}
				state = (mask/ppow(3,i))%3;
			}
			s += ops[(mask/ppow(3,i))%3];
			s += nums[i+2];
		}
		if(state == 1){
			r+=t;
		}else{
			r-=t;
		}
		if(r==0){
			ans.insert(s);
		}
	}
	for(string s : ans){
		cout << s << endl;
	}
}
