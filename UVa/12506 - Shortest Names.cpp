#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

vs v;
unordered_map<string,int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        m.clear();
        v.clear();
        int n;
        cin >> n;
        string str;
        rep(i,n){
            cin >> str;
            v.push_back(str);
            string b;
            rep(j,sz(str)){
                b += str[j];
                m[b]++;
            }
        }
        int res=0;
        rep(i,sz(v)){
            string b;
            rep(j,sz(v[i])){
                b += v[i][j];
                if(m[b]==1){
                    res += sz(b);
                    break;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}

