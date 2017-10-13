//In The Name of Allah
//Fri 10/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e3+5;

void Solution();

int n;
pii data[M];
int res[M];
map<pair<pii,pii> ,set<int> > lines;// slope and deltaY to count

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool cmp(pair<pair<pii,pii> ,set<int> > a,pair<pair<pii,pii> ,set<int> > b){
	return a.S.size() > b.S.size();
}

void Solution(){
	cin >> n;
	forar(i,n){
		int y;
		cin >> y;
		data[i] = {i+1,y};
	}

	forar(i,n){
		fori(j,i+1,n){
			pii slope;
			slope.F = (data[i].F-data[j].F);
			slope.S = (data[i].S-data[j].S);
			int gcd = __gcd(slope.F,slope.S);
			slope.F /= gcd;
			slope.S /= gcd;
			pii deltaY;
			deltaY.F = data[i].S*slope.F - data[i].F*slope.S;
			deltaY.S = slope.F;
			gcd = __gcd(deltaY.F,deltaY.S);
			deltaY.F /= gcd;
			deltaY.S /= gcd;
			pair<pii,pii> toadd;
			toadd.F = slope;
			toadd.S = deltaY;
			lines[toadd].insert(i);
			lines[toadd].insert(j);
			//cout << slope.F << " " << slope.S << " " << deltaY.F << " " << deltaY.S << endl;
		}
	}
	vector<pair<pair<pii,pii> ,set<int> > > linesvect;
	for(pair<pair<pii,pii> ,set<int> > cur : lines){
		linesvect.pb(cur);
		if(cur.S.size()==n){
			cout << "No" << endl;
			return;
		}
	}
	sort(linesvect.begin(),linesvect.end(),cmp);
	forar(i,linesvect.size()){
		pair<pair<pii,pii> ,set<int> > cur = linesvect[i];
		if(cur.S.size() == n-1){
			cout << "Yes" << endl;
			return;
		}
		fori(j,i+1,linesvect.size()){
			pair<pair<pii,pii> ,set<int> > cur2 = linesvect[j];
			if(cur2.F.F != cur.F.F)
				continue;
			int t = set_union(cur.S.begin(),cur.S.end(),cur2.S.begin(),cur2.S.end(),res) - res;
			if(cur.S.size() != 0 && cur2.S.size() != 0 && t == n){
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
}


