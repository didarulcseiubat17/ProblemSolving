#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)
#define all(arr) arr.begin(),arr.end()

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

class PrintScheduler {
public:
string getOutput(vector <string> threads, vector <string> slices)
{

	vi arr(threads.size(),0);	//holds the cur position the ith thread wait on
	string res;
	fo(i,slices.size()){
		int fir,sec;
		sscanf(slices[i].c_str(),"%d %d", &fir,&sec);

		while(sec--){
			res += threads[fir][arr[fir] % threads[fir].size()];
			arr[fir]++;
		}
	}

	return res;



}



// BEGIN CUT HERE
void __test()
{
// END CUT HERE

// BEGIN CUT HERE
		static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
// END CUT HERE

// BEGIN CUT HERE
}
// END CUT HERE

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB","CD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1","1 1","0 1","1 2"} ; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ACBDC"; verify_case(0, Arg2, getOutput(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 20","0 21"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEA"; verify_case(1, Arg2, getOutput(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A","B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 10","0 1","1 10","0 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BBBBBBBBBBABBBBBBBBBBAA"; verify_case(2, Arg2, getOutput(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A"; verify_case(3, Arg2, getOutput(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
PrintScheduler c;
c.__test();
return 0;
}
// END CUT HERE