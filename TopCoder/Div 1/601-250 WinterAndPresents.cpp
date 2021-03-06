#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

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
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

class WinterAndPresents {
public:
     long long getNumber(vector <int> apple, vector <int> orange) {
          int x = 1<<27, n = sz(apple);
          rep(i,n) {
               x = min(x, apple[i] + orange[i]);
          }
          ll res = 0;
          repa(i,1,x,1) {
               int minapple =0, maxapple=0, maxorange=0;
               rep(j,n) {
                    maxapple += min(apple[j],i);
                    maxorange += min(orange[j],i);
               }
               minapple = n*i - maxorange;
               res += maxapple-minapple+1;
          }
          return res;
     }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, long long p2)
{
     cout << "Test " << testNum << ": [" << "{";
     for (int i = 0; int(p0.size()) > i; ++i) {
          if (i > 0) {
               cout << ",";
          }
          cout << p0[i];
     }
     cout << "}" << "," << "{";
     for (int i = 0; int(p1.size()) > i; ++i) {
          if (i > 0) {
               cout << ",";
          }
          cout << p1[i];
     }
     cout << "}";
     cout << "]" << endl;
     WinterAndPresents *obj;
     long long answer;
     obj = new WinterAndPresents();
     clock_t startTime = clock();
     answer = obj->getNumber(p0, p1);
     clock_t endTime = clock();
     delete obj;
     bool res;
     res = true;
     cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
     if (hasAnswer) {
          cout << "Desired answer:" << endl;
          cout << "\t" << p2 << endl;
     }
     cout << "Your answer:" << endl;
     cout << "\t" << answer << endl;
     if (hasAnswer) {
          res = answer == p2;
     }
     if (!res) {
          cout << "DOESN'T MATCH!!!!" << endl;
     } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
          cout << "FAIL the timeout" << endl;
          res = false;
     } else if (hasAnswer) {
          cout << "Match :-)" << endl;
     } else {
          cout << "OK, but is it right?" << endl;
     }
     cout << "" << endl;
     return res;
}
int main()
{
     bool all_right;
     all_right = true;

     vector <int> p0;
     vector <int> p1;
     long long p2;

     {
          // ----- test 0 -----
          int t0[] = {1};
          p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
          int t1[] = {1};
          p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
          p2 = 3ll;
          all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
          // ------------------
     }

     {
          // ----- test 1 -----
          int t0[] = {1,2,0,3};
          p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
          int t1[] = {4,5,0,6};
          p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
          p2 = 0ll;
          all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
          // ------------------
     }

     {
          // ----- test 2 -----
          int t0[] = {2,2,2};
          p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
          int t1[] = {2,2,2};
          p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
          p2 = 16ll;
          all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
          // ------------------
     }

     {
          // ----- test 3 -----
          int t0[] = {7,4,5};
          p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
          int t1[] = {1,10,2};
          p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
          p2 = 46ll;
          all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
          // ------------------
     }

     {
          // ----- test 4 -----
          int t0[] = {1000000};
          p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
          int t1[] = {1000000};
          p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
          p2 = 1000002000000ll;
          all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
          // ------------------
     }

     if (all_right) {
          cout << "You're a stud (at least on the example cases)!" << endl;
     } else {
          cout << "Some of the test cases had errors." << endl;
     }
     return 0;
}
// END KAWIGIEDIT TESTING







//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
