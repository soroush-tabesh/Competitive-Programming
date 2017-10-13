//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: range
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("range.in","r",stdin),freopen("range.out","w",stdout)
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

int n;
bool data[255][255];
int mark[255][255];
int chksize[255][255];
int ans[251];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void appsol(int s,int from = 2){
	from = max(from,2);
	while(s >= from){
		ans[s]++;
		s--;
	}
}

void Solution(){
	cin >> n;
	forar(i,n){
		forar(j,n){
			char c;
			cin >> c;
			if(c == '1')
				data[i][j] = 1;
		}
	}
	
	//algorithm
	forar(i,n){
		forar(j,n){
			if(data[i][j]){
				int size = n;
				if(i+max(2,chksize[i][j]) > n || j+max(2,chksize[i][j]) > n)
					continue;
				fori(s,max(2,chksize[i][j]),n+1){
					bool is = true;
					forar(mi,s){
						if(!data[i+mi][j+s-1]){
							is = false;
							break;
						}
					}
					if(is){
						forar(mj,s){
							if(!data[i+s-1][j+mj]){
								is = false;
								break;
							}
						}
					}
					if(!is){
						size = s-1;
						break;
					}else{
						forar(mi,s){
							appsol(mi+1,mark[i+mi][j+s-1]+1);
							mark[i+mi][j+s-1] = max(mi+1,mark[i+mi][j+s-1]);
						}
						forar(mj,s){
							appsol(mj+1,mark[i+s-1][j+mj]+1);
							mark[i+s-1][j+mj] = max(mj+1,mark[i+s-1][j+mj]);
						}
					}
				}
				fori(mi,i,i+size){
					fori(mj,j,j+size){
						chksize[mi][mj] = max(chksize[mi][mj],int(min(i+size-mi,j+size-mj)+1));
					}
				}
			}
		}
	}
	
	forar(i,251){
		if(ans[i])
			cout << i << " " << ans[i] << endl;
	}
}
