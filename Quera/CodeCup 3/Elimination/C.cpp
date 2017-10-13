//In The Name of Allah
//Fri 14/7/96
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+100 , inf=1e9+100 ;
#define int long long
#define pb push_back
#define F first
#define S second

set<char>s1,s2;
string st,t;
int n;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    for(char c:t){
        s1.insert(c);
    }
    for(int i=0;i<n;i++){
        s2.clear();
        cin>>st;
        for(char c:st){
            s2.insert(c);
        }
        if(s1==s2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
