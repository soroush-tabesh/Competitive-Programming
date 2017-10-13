#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long int li;

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();

int main()
{
    // question1();
	// question2();
	// question3();
	question4();
	// question5();
	// question6();
	// question7();
    return 0;
}

void question1(){
	int a,b,l,ans=0;
	cin >> a >> b >> l;
	ans = (l/2)*(a+b);
	ans += (l%2==1 ? a : 0);

	cout << ans;
}

string findpair(string a,vector<pair<string,string> > data){
	string ans = "";
	for(int i = 0;i < data.size();i++){
		if(data[i].first == a){
			ans = data[i].second + " 3";
			break;
		}
	}
	return ans;
}

void question2(){
	int n,m;
	cin >> n >> m;
	vector< pair<string,string> > data;

	for(int i = 0;i < n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		data.push_back(make_pair(s1,s2));
	}
	data.push_back(make_pair("",""));

	for(int i = 0;i < m;i++){
		string temp;
		cin >> temp;
		string ans = findpair(temp,data);
		cout << ans << "kachal! ";
	}
}

void question3(){
	int t,x,y,ans=0;
	cin >> t;
	vector<pair<int,int> > data;

	for(int i = 0;i < t;i++){
		cin >> x >> y;
		data.push_back(make_pair(x,y));
	}

	for(int i = 0;i < t;i++){
		x = data[i].first;
		y = data[i].second;
		if(x-y == 0){
			if(x%2 == 0){
				ans = 2*x;
				cout << ans;
			}else{
				ans = 2*(x+1)-3;
				cout << ans;
			}
		}else if(x-y==2){
			if(x%2 == 0){
				ans = 2*x-2;
				cout << ans;
			}else{
				ans = 2*(x-1)-1;
				cout << ans;
			}
		}else{
			cout << -1;
		}
		cout << endl;
	}

}

void question4(){
	int n,k;
	cin >> n >> k;

	if(k <= n/2){
		if(n%2==0){
			k = n/2;
			for(int i = k;i >= 1;i--){
				cout << i << " " << i + k << " ";
			}
		}else{
			k = n/2+1;
			for(int i = 1;i <= n-k;i ++){
				cout<< i << " " << i + k << " ";
			}
			cout << n-k+1;
		}
	}else{
		cout << "Impossible";
	}

}

void question5(){

}

void question6(){

}

void question7(){

}


