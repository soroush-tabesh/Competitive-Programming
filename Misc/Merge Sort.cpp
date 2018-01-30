//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("bigtest.in","r",stdin),freopen("bigtest.out","w",stdout)
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

void Solution();

ll n,sum;
ll data[100*1000];
ll temp[100*1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void merge(ll abeg,ll aend,ll bbeg,ll bend){
	ll mbegin = abeg;
	ll tind = 0;
	while(abeg < aend || bbeg < bend){
		if(abeg == aend){
			temp[tind++] = data[bbeg++];
		}else if(bbeg == bend){
			temp[tind++] = data[abeg++];
		}else{
			if(data[abeg] < data[bbeg]){
				temp[tind++] = data[abeg++];
			}else if(data[abeg] == data[bbeg]){
				temp[tind++] = data[abeg++];
			}else{
				temp[tind++] = data[bbeg++];
				sum += aend-abeg;
			}
		}
	}
	forar(i,tind){
		data[mbegin+i] = temp[i];
	}
}

void mergeSort(ll mbegin, ll mend){
	if(mend - mbegin == 1)
		return;
	ll mid = (mbegin + mend)/2;
	mergeSort(mbegin,mid);
	mergeSort(mid,mend);
	merge(mbegin,mid,mid,mend);
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	mergeSort(0,n);
	/*cout << endl;
	forar(i,n){
		cout << data[i] << " ";
	}
	cout << endl;*/
	cout << sum << endl;
}