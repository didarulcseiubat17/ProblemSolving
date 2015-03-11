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
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
typedef long long ll;
using namespace std;

vs v;
class TheTriangleBothDivs {
public:
    void build(string& time, int idx, string res){
        if(idx == 11){
            v.push_back(res);
            return;
        }
        if(time[idx] != '?'){
            string nxt = res;
            nxt += time[idx];
            build(time,idx+1,nxt);
            return;
        }
        if(idx == 0){
            build(time,idx+1, res+"0");
            build(time,idx+1,res+"1");
            if(time[idx+1] == '?' || time[idx+1] <='3')
                build(time,idx+1,res+"2");
        }
        else if(idx == 1){
            rep(i,10){
                if(i < 4 || res[0] <'2'){
                    char c = i+'0';
                    build(time,idx+1, res + c);
                }
            }
        }
        else if(idx == 3){
            rep(i,6){
                char c = i+'0';
                build(time,idx+1, res+c);
            }

        }
        else if(idx == 4){
            rep(i,10){
                char c = i+'0';
                build(time,idx+1, res+c);
            }

        }
        else if(idx == 9){
            build(time,idx+1, res+"+");
            build(time,idx+1, res+"-");
        }
        else if(idx == 10){
            repe(i,'0','9'){
                char c = i;
                if(res[idx-1] =='-' && c=='0') continue;
                build(time,idx+1,res + char(i));
            }
        }
    }

    string covert(string str){
        int h,m,p;
        char s;
        sscanf(str.c_str(),"%d:%d GMT%c%d",&h,&m,&s,&p);
        if(s == '-')
            h = (h+p)%24;
        else
            h = (h-p+24)%24;
        char res[100];
        sprintf(res,"%02d:%02d",h,m);
        return res;
    }

    string fix(string time){
        v.clear();
        build(time,0,"");
        string res = covert(v[0]);
        reps(i,1,sz(v)){

            res = min(res, covert(v[i]));
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
    cout << "]" << endl;
    TheTriangleBothDivs *obj;
    string answer;
    obj = new TheTriangleBothDivs();
    clock_t startTime = clock();
    answer = obj->fix(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
    if (hasAnswer) {
        res = answer == p1;
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
int main() {
    bool all_right;
    all_right = true;

    string p0;
    string p1;

    {
        // ----- test 0 -----
        p0 = "??:11 GMT-9";
        p1 = "00:11";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 0 -----
        p0 = "17:45 GMT-4";
        p1 = "21:45";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        p0 = "16:?" "? GMT?" "?";
        p1 = "00:00";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = "?1:34 GMT-9";
        p1 = "06:34";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = "?" "?:?" "? GMT?" "?";
        p1 = "00:00";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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