#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Method-1=>Plain Recursive=>Time Complexity=>O(2^n),Space Complexity=>O(n)

long long fibonacci(int n){
	if(n==0 or n==1) return n;
	else return fibonacci(n-1)+fibonacci(n-2);}

*/


/*Method-2+>Memoization->Time Complexity=>O(n),Space Complexity=>O(n+n)

long long fibonacci(int n,vector<long long>&storage){
	if(n==0 or n==1) return n;

	if(storage[n]!=0){
		return storage[n];
	}

	storage[n]=fibonacci(n-1,storage)+fibonacci(n-2,storage);

	return storage[n];}

*/


/*Method 3->Tabulation->Time Complexity=>O(n),Space Complexity=>O(n)

long long fibonacci(int n){
	vector<long long>storage(n+1);
	if(n==0 or n==1) return n;

	//Base Case->
	storage[0]=0;storage[1]=1;

	for(int idx=2;idx<=n;idx++){
		storage[idx]=storage[idx-1]+storage[idx-2];
	}

	return storage[n];}

*/


//Method 4->Tabulation+Space Optimisation=>Time Complexity=>O(n),Space Complexity=>O(1) 
long long fibonacci(int n){
	if(n==0 or n==1) return n;

	long prv=1,prv_prv=0;
	
	for(int idx=2;idx<=n;idx++){
		int temp=prv;
		prv+=prv_prv;
		prv_prv=temp;
	}

	return prv;
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
	freopen("error.txt","w",stderr);
	//For getting output in output.txt
	freopen("output.txt", "w", stdout);
#endif
    
  	int n;
  	scanf("%d",&n);

//Plain Recursion->
  	// long long fib_n=fibonacci(n);

//Memoization->
  	// vector<long long>storage(n+1);long long fib_n=fibonacci(n,storage);

//Tabulation->  	
  	long long fib_n=fibonacci(n);
  	printf("%lld",fib_n);
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

