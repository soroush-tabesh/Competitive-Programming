//In The Name of Allah
//Tue 21/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

int n;
struct comp {
	bool operator() (pii a,pii b){
		return ((a.F - a.S + n)%n) < ((b.F - b.S + n)%n);
	}
};
int adjcur[1005];
int adjgoal[1005];
set<pii,comp> adjtemp[1005];
vector<pii> ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int getl(int cur,set<pii,comp>::iterator neib){
	int res;
	if(neib != adjtemp[cur].begin()){
		res = (prev(neib))->F;
	}else{
		res = (cur+1)%n;
	}
	return res;
}

int getr(int cur,set<pii,comp>::iterator neib){
	int res;
	if(next(neib) != adjtemp[cur].end()){
		res = (next(neib))->F;
	}else{
		res = (cur-1+n)%n;
	}
	return res;
}

void setadjtemp(){
	forar(i,n){
		adjtemp[i].clear();
	}
	fori(i,2,n-1){
		adjtemp[0].insert(adjtemp[0].end(),{i,0});
		adjtemp[i].insert({0,i});
	}
}

void solveA(){ // temp to cur
	vector<pii> res;
	setadjtemp();
	int g = 0;
	int i = 0;
	while(g < n){
		if(adjtemp[i].size() == adjcur[i]){
			g++;
		}else{
			g=0;
			int er = -1;
			//cout << "new : " << g << endl;
			//cout << i+1 << " " << adjtemp[i].size() << " " << adjcur[i] << endl;
			if(adjtemp[i].size() > adjcur[i]){
				for(auto neib = adjtemp[i].begin();neib != adjtemp[i].end();neib++){
					if(adjtemp[neib->F].size() > adjcur[neib->F]){
						int c,d;
						c = getl(i,neib);
						d = getr(i,neib);
						adjtemp[c].insert({d,c});
						adjtemp[d].insert({c,d});
						adjtemp[neib->F].erase({i,neib->F});
						er = neib->F;
						res.pb({d,c});
						//cout << er+1 << " : " << i+1 << endl;
						//cout << c+1 << " " << d+1 << endl;
						break;
					}
				}
			}
			g++;
			if(er != -1)
				adjtemp[i].erase({er,i});
		}
		i=(i+1)%n;
	}
	reverse(res.begin(),res.end());
	ans.insert(ans.end(),res.begin(),res.end());
}

void solveB(){ // temp to tar
	setadjtemp();
	int g = 0;
	int i = 0;
	while(g < n){
		if(adjtemp[i].size() == adjgoal[i]){
			g++;
		}else{
			g=0;
			int er = -1;
			//cout << "new : " << g << endl;
			//cout << i+1 << " " << adjtemp[i].size() << " " << adjgoal[i] << endl;
			if(adjtemp[i].size() > adjgoal[i]){
				for(auto neib = adjtemp[i].begin();neib != adjtemp[i].end();neib++){
					if(adjtemp[neib->F].size() > adjgoal[neib->F]){
						int c,d;
						c = getl(i,neib);
						d = getr(i,neib);
						adjtemp[c].insert({d,c});
						adjtemp[d].insert({c,d});
						adjtemp[neib->F].erase({i,neib->F});
						er = neib->F;
						ans.pb({er,i});
						//cout << er+1 << " : " << i+1 << endl;
						//cout << c+1 << " " << d+1 << endl;
						break;
					}
				}
			}
			g++;
			if(er != -1)
				adjtemp[i].erase({er,i});
		}
		i=(i+1)%n;
	}
}

void Solution(){
	cin >> n;
	forar(i,n-3){
		int a,b;
		cin >> a >> b;
		adjcur[--a]++;
		adjcur[--b]++;
	}
	forar(i,n-3){
		int a,b;
		cin >> a >> b;
		adjgoal[--a]++;
		adjgoal[--b]++;
	}
	solveA();
	solveB();
	cout << ans.size() << endl;
	for(pii x : ans){
		cout << x.F+1 << " " << x.S+1 << endl;
	}
}
