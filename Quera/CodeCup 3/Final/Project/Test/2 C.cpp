// IN THE be name khoda :)
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

const int MN=2e5+100 , inf=1e9+100 , mod=1000*1000*1000+7 ;

int n,ans;
int arrA[MN],arrB[MN];
map<int,int> cntA,cntB;
set<pair<int,int> ,greater<pair<int,int> > > pA,pB;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arrA[i];
        cntA[arrA[i]]++;
    }
    for(int i = 0;i<n;i++){
        cin >> arrB[i];
        cntB[arrB[i]]++;
    }
    for(auto x : cntA){
        pA.insert(make_pair(x.second,x.first));
    }
    for(auto x : cntB){
        pB.insert(make_pair(x.second,x.first));
    }
    for(auto x : pA){
        int temp=0;
        int xp = x.first;
        set<pair<int,int> > ttp;
        for(auto it = pB.begin();it != pB.end() && xp;){
            temp++;
            xp--;
            auto bc = *it;
            auto itp = it;
            it++;
            pB.erase(itp);
            if(bc.first > 1)
                ttp.insert(make_pair(bc.first-1,bc.second));
        }
        for(auto k : ttp){
            pB.insert(k);
        }
        ans += temp;
    }
    cout << ans << endl;
}
