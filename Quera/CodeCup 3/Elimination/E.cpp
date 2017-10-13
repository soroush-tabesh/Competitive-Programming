//In The Name of Allah
//Sat 15/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int n;
struct Frac{
	ll num=1,den=1;
	Frac(){
		num=0;
		den=1;
	}
	Frac(ll mnum,ll mden){
		ll s = mnum*mden;
		if(s)
			s/=abs(s);
		num = abs(mnum);
		den = abs(mden);
		ll g = __gcd(num,den);
		num /= g;
		den /= g;
		num *= s;
	}
	Frac operator+(Frac b){
		Frac r(num * (b.den) + den * (b.num),den * (b.den));
		return r;
	}
	Frac operator-(Frac b){
		Frac r((num * b.den) - den * (b.num),den * (b.den));
		return r;
	}
	Frac operator*(Frac b){
		Frac r(num * (b.num),den * (b.den));
		return r;
	}
	Frac operator/(Frac b){
		Frac r(num * (b.den),den * (b.num));
		return r;
	}
	Frac& operator=(Frac b){
		num = b.num;
		den = b.den;
		return (*this);
	}
	bool operator<(Frac b){
		return num*(b.den) < den*(b.num);
	}
	bool operator==(Frac b){
		return num*(b.den) == den*(b.num);
	}
};typedef struct Frac Frac;
Frac fine(1200,1);
struct Team{
	ll id,cnt,wr,tsum,rank,nrank;
	bool operator<(Team b){
		return ((cnt > b.cnt)||(cnt == b.cnt && (Frac(tsum,1) + Frac(wr,1)*fine)<(Frac(b.tsum,1) + Frac(b.wr,1)*fine)));
	}
	bool operator==(Team b){
		return (cnt == b.cnt && (Frac(tsum,1) + Frac(wr,1)*fine)==(Frac(b.tsum,1) + Frac(b.wr,1)*fine));
	}
};typedef struct Team Team;
Team team[200];
vector<Frac> crits;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> team[i].cnt >> team[i].tsum >> team[i].wr;
		team[i].id = i;
	}
	sort(team,team+n);
	team[0].rank = 1;
	fori(i,1,n){
		if(team[i] == team[i-1]){
			team[i].rank = team[i-1].rank;
		}else{
			team[i].rank = i+1;
		}
	}
	forar(i,n){
		fori(j,i+1,n){
			if(team[i].cnt != team[j].cnt || team[i].wr == team[j].wr)
				continue;
			Frac r(team[j].tsum - team[i].tsum,team[i].wr-team[j].wr);
			crits.pb(r);
		}
	}
	ll ans = 0;
	for(Frac fr : crits){
		fine.num = fr.num;
		fine.den = fr.den;
		sort(team,team+n);
		team[0].nrank = 1;
		ll res = 0;
		fori(i,1,n){
			if(team[i] == team[i-1]){
				team[i].nrank = team[i-1].nrank;
			}else{
				team[i].nrank = i+1;
			}
		}
		forar(i,n){
			ll t = (team[i].rank - team[i].nrank)*(team[i].rank - team[i].nrank);
			if(team[i].nrank > team[i].rank){
				t*=-1;
			}
			res += t;
		}
		ans = max(ans,res);
	}
	cout << ans << endl;
}
