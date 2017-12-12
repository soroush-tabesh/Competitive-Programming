//In The Name of Allah
//Tue 21/9/96
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

ll n;
map<int,int> rmap;
vector<ll> data;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		ll a;
		cin >> a;
		rmap[a]++;
		data.pb(a);
	}
	ll sum1 = 0,sum2=0,pref=0,bnd=1LL*100000*100000*100000;
	forar(i,n){
		sum1 += (i*data[i])-pref;
		if(sum1 >= bnd){
			sum2+=sum1/bnd;
			sum1%=bnd;
		}
		if(sum1 < 0){
			sum2+=sum1/bnd-1;
			sum1-=(sum1/bnd-1)*bnd;
			if(sum1 >= bnd){
				sum2+=sum1/bnd;
				sum1%=bnd;
			}
		}
		pref+=data[i];
	}
	for(ll x : data){
		rmap[x]--;
		sum1 -= rmap[x+1]-rmap[x-1];
	}
	if(sum1 >= bnd){
		sum2+=sum1/bnd;
		sum1%=bnd;
	}
	if(sum1 < 0){
		sum2+=sum1/bnd-1;
		sum1-=(sum1/bnd-1)*bnd;
		if(sum1 >= bnd){
			sum2+=sum1/bnd;
			sum1%=bnd;
		}
	}
	if(sum2!=0){
		if(sum2 > 0){
			cout << sum2;
			stringstream ss;
			forar(i,15){
				ss << sum1%10;
				sum1/=10;
			}
			string s = ss.str();
			reverse(s.begin(),s.end());
			cout << s << endl;
		}else{
			if(sum1){
				cout << "-";
				sum2++;
				if(sum2)
					cout << abs(sum2);
				sum1 = bnd-sum1;
				stringstream ss;
				forar(i,15){
					ss << sum1%10;
					sum1/=10;
				}
				string s = ss.str();
				reverse(s.begin(),s.end());
				if(!sum2){
					while(s[0] == '0'){
						s.erase(s.begin());
					}
				}
				cout << s << endl;
			}else{
				cout << sum2 << "000000000000000" << endl;
			}
		}
	}else{
		cout << sum1 << endl;
	}
}
