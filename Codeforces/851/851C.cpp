//In The Name of Allah
//Mon 13/6/96
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

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int n;
ld points[1000+5][5];
vector<int> goods;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		forar(j,5){
			cin >> points[i][j];
		}
	}
	if(n > 32){
		cout << 0;
		return;
	}
	forar(i,n){
		bool is = true;
		forar(j,n){
			fori(k,j+1,n){
				if(i == j || i == k)
					continue;
				ld dot = 0;
				forar(w,5){
					dot += (points[j][w] - points[i][w])*(points[k][w] - points[i][w]);
				}
				ld szeA = 0,szeB = 0;
				forar(w,5){
					szeA += pow(points[j][w] - points[i][w],2);
				}
				forar(w,5){
					szeB += pow(points[k][w] - points[i][w],2);
				}
				szeA = sqrt(szeA);
				szeB = sqrt(szeB);
				ld angle = dot/(szeA*szeB);
				if(angle>0)
					is = false;
			}
		}
		if(is)
			goods.pb(i);
	}
	cout << goods.size() << endl;
	for(int i : goods){
		cout << i+1 << endl;
	}
}