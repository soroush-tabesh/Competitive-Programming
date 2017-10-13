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

int ns,ne;
vector<int> input,result;
vector<pair<int,char> > ans;

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
	cin >> ns;
	forar(i,ns){
		int a;
		cin >> a;
		input.pb(a);
	}
	cin >> ne;
	forar(i,ne){
		int a;
		cin >> a;
		result.pb(a);
	}
	int lastind = 0;
	for(int i = 0;i < ne;i++){
		int sum = 0;
		int cnt = lastind;
		int m_max = 0;
		while(sum < result[i] && cnt < ns){
			sum += input[cnt];
			m_max = (m_max < input[cnt] ? input[cnt] : m_max);
			cnt++;
		}
		if(sum == 0 || sum != result[i]){
			cout << "NO";
			return;
		}
		if(cnt - lastind == 1){
			lastind = cnt;
			continue;
		}
		bool is = false;
		int bigmons;
		for(int j = lastind; j < cnt; j++){
			if(input[j] == m_max && ( (input[(j-1 >= lastind ? j - 1 : lastind)] < input[j]) ||  (input[(j + 1 < cnt ? j + 1 : cnt-1)] < input[j]) )){
				is = true;
				bigmons = j;
				break;
			}
		}
		if(!is){
			cout << "NO";
			return;
		}
		while(1 < cnt-lastind){
			if(input[(bigmons-1 >= lastind ? bigmons - 1 : lastind)] < input[bigmons] ){
				input[bigmons] += input[bigmons - 1];
				ans.pb(make_pair(bigmons + 1,'L'));
				input.erase(input.begin()+(bigmons - 1));
				cnt--;
				bigmons--;
			}else{
				input[bigmons] += input[bigmons + 1];
				ans.pb(make_pair(bigmons + 1,'R'));
				input.erase(input.begin()+(bigmons + 1));
				cnt--;
			}
		}
		lastind = cnt;
	}
	bool is = result.size() == input.size();
	forar(i,min(result.size(),input.size())){
		is = is && result[i] == input[i];
	}
	if(!is){
		cout << "NO";
		return;
	}
	cout << "YES" << endl;
	forar(i,ans.size()){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
}