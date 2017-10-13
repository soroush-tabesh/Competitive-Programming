#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

vector<int> nums;
int k;
string str;
vector<char> buffer;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool cond(int w){
	int r = 1,cnt = 0;
	forar(i,nums.size()){
		if(nums[i] > w)
			return 0;
		cnt += nums[i];
		if(cnt > w){
			r++;
			cnt = nums[i];
		}
	}
	if(r > k)
		return 0;
	return 1;
	
}

void Solution(){
	cin >> k;
	getline(cin,str);
	getline(cin,str);
	forar(i,str.length()){
		buffer.pb(str[i]);
		if(str[i] == ' ' || str[i] == '-'){
			nums.pb(buffer.size());
			buffer.clear();
		}
	}
	nums.pb(buffer.size());
	
	// backward
	int l=0,h=str.length();
	while(h - l > 1){
		if(cond((h+l)/2))
			h = (h+l)/2;
		else
			l = (h+l)/2;
	}
	cout << h;
	
}