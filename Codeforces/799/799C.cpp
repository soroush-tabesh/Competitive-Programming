//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

pii fd[M];
pii fc[M];
pii dpd[M][2];
pii dpc[M][2];
int n,c,d,nd,nc,ansd,ansc,ansboth;
pii t1,t2;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool comp(pii a,pii b){
	return a.F > b.F;
}

void Solution(){
	cin >> n >> c >> d;
	forar(i,n){
		int b,p;
		char c;
		cin >> b >> p >> c;
		if(c=='C'){
			fc[nc] = make_pair(b,p);
			nc++;
			if(b > dpc[p][0].F){
				dpc[p][1] = dpc[p][0];
				dpc[p][0] = fc[nc-1];
			}else if(b>dpc[p][1].F){
				dpc[p][1] = fc[n-1];
			}
		}else{
			fd[nd] = make_pair(b,p);
			nd++;
			if(b>dpd[p][0].F){
				dpd[p][1] = dpd[p][0];
				dpd[p][0] = fd[nd-1];
			}else if(b>dpc[p][1].F){
				dpd[p][1] = fd[nd-1];
			}
		}
	}
	sort(fc,fc+nc,comp);
	sort(fd,fd+nd,comp);
	fori(i,1,M){
		pii k[4];
		k[0] = dpc[i][0];
		k[1] = dpc[i][1];
		k[2] = dpc[i-1][0];
		k[3] = dpc[i-1][1];
		sort(k,k+4,comp);
		unique(k,k+4);
		dpc[i][0] = k[0];
		dpc[i][1] = k[1];
		
		k[0] = dpd[i][0];
		k[1] = dpd[i][1];
		k[2] = dpd[i-1][0];
		k[3] = dpd[i-1][1];
		sort(k,k+4,comp);
		unique(k,k+4);
		dpd[i][0] = k[0];
		dpd[i][1] = k[1];
	}
	if(nc > 1){
		forar(i,nc){
			if(i && fc[i-1] == fc[i] && fc[i-1].S + fc[i].S <= c){
				ansc = max(ansc ,fc[i-1].F + fc[i].F);
			}
			if(fc[i].S <= c){
				int temp = 0;
				temp += fc[i].F;
				if(dpc[c-fc[i].S][0] != fc[i] && dpc[c-fc[i].S][0].F){
					temp += dpc[c-fc[i].S][0].F;
				}else if(dpc[c-fc[i].S][1] != fc[i] && dpc[c-fc[i].S][1].F){
					temp += dpc[c-fc[i].S][1].F;
				}else{
					continue;
				}
				ansc = max(ansc,temp);
			}
		}
	}
	if(nd > 1){
		forar(i,nd){
			if(i && fd[i-1] == fd[i] && fd[i-1].S + fd[i].S <= d){
				ansd = max(ansd ,fd[i-1].F + fd[i].F);
			}
			if(fd[i].S <= d){
				int temp = 0;
				temp += fd[i].F;
				if(dpd[d-fd[i].S][0] != fd[i] && dpd[d-fd[i].S][0].F){
					temp += dpd[d-fd[i].S][0].F;
				}else if(dpd[d-fd[i].S][1] != fd[i] && dpd[d-fd[i].S][1].F){
					temp += dpd[d-fd[i].S][1].F;
				}else{
					continue;
				}
				ansd = max(ansd,temp);
			}
		}
	}
	if(dpd[d][0].F * dpc[c][0].F)
		ansboth = dpd[d][0].F + dpc[c][0].F;
	cout << max(max(ansc,ansd),ansboth);
	
}
