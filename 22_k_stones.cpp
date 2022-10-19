/*problem link-->There is set A={a1,a2,a3...an}consisting +ve integer.Taro and Jiro will play the following game agains each other.

Initially we have a pile consisting of k stones .Two players perform the following oprn alternatively,starting from taro.
	*Choose an element x in A and removem exactly x stones from pile
Player loses if he is unable to play.Determine the winner

INPUT:
	N k
	a1,a2,a3...an

OUTPU:
	If taro win->Print first
	else ->Print second

*/

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

void print_winner(vi &nums,int n,int k){
	
}

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting errors in error.txt
	freopen("error.txt", "w", stderr);
	//For getting output in output.txt
	freopen("output.txt", "w", stdout);
#endif
      
    int n,k;
    cin>>n>>k;

    vi nums(n);
    for(int &ele:nums) cin>>ele;

    print_winner(nums,n,k);
    
    runTime();
    return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}