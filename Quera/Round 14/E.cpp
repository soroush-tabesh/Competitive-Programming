#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define first frs
#define second scnd
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int ai[100];
int bi[100];
bool dpA[100*1000+1];
bool dpB[100*1000+1];

int main()
{
	//Init;
	#ifndef ONLINE_JUDGE
    //WFile;
	#endif
	Solution();
    return 0;
}

inline bool getinA(int index,int num){
	if(index-num <= 0)
		return 1;
	return dpA[index-num];
}

inline bool getinB(int index,int num){
	if(index-num <= 0)
		return 0;
	return dpB[index-num];
}

inline void Log(string s){
	cout << "Log: " << s << endl;
}

inline void Log(int s){
	cout << "Log: " << s << endl;
}

void Solution(){
	int n,a,b;
	cin >> n;

	cin >> a;
	ForI(i,0,a){
		cin >> ai[i];
	}
	cin >> b;
	ForI(i,0,b){
		cin >> bi[i];
	}
	sort(ai,ai+a);
	sort(bi,bi+b);

	// init
	ForI(i,1,ai[0]){
		dpA[i] = 1;
	}

	// solve dp
	ForI(i,1,n+1){
		//dpA
		if(i>=ai[0]){
			bool tempA = 0;
			ForI(j,0,a){
				tempA = tempA || getinB(i,ai[j]);
			}
			dpA[i] = tempA;
		}
		//dpB
		if(i >= bi[0]){
			bool tempB = 1;
			ForI(j,0,b){
				tempB = tempB && getinA(i,bi[j]);
			}
			dpB[i] = tempB;
		}
	}
	if(dpA[n])
		cout << "Pashmak";
	else
		cout << "Charze";


}
