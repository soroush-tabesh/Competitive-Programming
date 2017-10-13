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

const ll delta = 10883;

void Solution();

int main()
{
	Init;
	//WFile;
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
	v%=delta;
	if(exp%2)
		v*=base;
	return v%delta;
}

void Solution(){
	int sec = 0;
	pii p[3];
	pii np[3] = {{1024,2010},{-1381,138},{1,2010}};
	pii ways[8]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
	bool sp[3] = {0,0,0};
	
	while(!sp[0] || !sp[1] || !sp[2]){
		sec++;
		forar(turt,3){
			p[turt] = np[turt];
		}
		forar(turt,3){
			int dx = abs(p[turt].F-p[(turt+1)%3].F);
			int dy = abs(p[turt].S-p[(turt+1)%3].S);
			sp[turt] = ((dx == 1 && dy == 1) || (dx == 0 && dy == 1) || (dx == 1 && dy == 0) || (dx == 0 && dy == 0));
			if(!sp[turt]){
				pii next = p[turt];
				forar(i,8){
					if(abs(ways[i].F + p[turt].F - p[(turt+1)%3].F) + abs(ways[i].S + p[turt].S - p[(turt+1)%3].S) < abs(next.F - p[(turt+1)%3].F) + abs(next.S - p[(turt+1)%3].S)){
						next = p[turt];
						next.F += ways[i].F;
						next.S += ways[i].S;
					}
				}
				np[turt] = next;
			}
		}
	}
	cout << ppow(sec-1,6);
}