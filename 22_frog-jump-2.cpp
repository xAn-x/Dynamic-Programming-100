//problem link-->https://atcoder.jp/contests/dp/tasks/dp_b

//HEADER FILES-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <math.h>
#include <string>
#include <climits>

using namespace std;

//MACROS--------------------------------------------------------------------------------------------------------------

#define INF INT_MAX
#define neg_INF INT_MIN

#define loop(i,st,end,jump) for(auto i = st; i<=end; i+=jump)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

typedef long long ll;
#define mod (1000000007);

void runTime();
//-------------------------------------------------------------------------------------------------------------------

//Method-1=>Memoization->O(n) time and space
/*
unordered_map<int,int>m;
int frog_jump(int n,int k,vi&costs){
	if(n==1) return m[n]=0;

	if(m.count(n)) return m[n];
	int minCost=INF;
	loop(jmp,1,k,1){
		if(n-1-jmp<0) break;
		int jump_cost=abs(costs[n-1]-costs[n-1-jmp]);
		minCost=min(jump_cost+frog_jump(n-jmp,k,costs),minCost);
	}

	return m[n]=minCost;
}
*/


//Method-2=>Tabulation->O(n) time and space
/*
int frog_jump(int n,int k,vi &costs){
	vector<int>dp(n);
	dp[0]=0;

	loop(i,1,n-1,1){
		int minCost=INT_MAX;
		loop(jmp,1,k,1){
			if(i-jmp<0) break;
			minCost=min(abs(costs[i]-costs[i-jmp])+dp[i-jmp],minCost);
		}
		dp[i]=minCost;
	}

	return dp[n-1];
}
*/

//Method-3=>Tabulation+Space-Optimisation->O(n)time & O(k) space
int frog_jump(int n,int k,vi &costs){
	if(n==1) return 0;

	vector<int>dp(k+1,1e5);
	dp[0]=0;

	loop(i,1,n-1,1){
		int minCost=INT_MAX;
		loop(jmp,1,k,1){
			if(i-jmp<0) break;
			minCost=min(abs(costs[i]-costs[i-jmp])+dp[i-jmp],minCost);
		}
		loop(i,0,k-1,1){
			dp[i]=dp[i+1];
		}
		dp[k]=minCost;
	}

	return dp[k];
}

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n,k;
    cin>>n>>k;

    vector<int> costs(n);
    for(int  &cost:costs) cin>>cost;

    cout<<frog_jump(n,k,costs)<<'\n';
    
    runTime();
    return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}