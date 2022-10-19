//problem link-->

#include <bits/stdc++.h>
using namespace std;

void runTime();

/*Method-1=>Find All binary String of n length and find which has no consecutive 1->

long long no_of_string_with_no_consecutive_1(int n){
	if(n==0 n==1 or n==2) return n+1;

	long long start=0,end=pow(2,n)-1 ;

	long long count=0;
	for(long long i=start;i<=end;i++){
		long long num=i;

		bool prv_1=false,have_consecutive_1=false;
		while(num>0){

			if((num & 1)==0){
				prv_1=false;
				num=num>>1;
			}
			else if((num & 1)==1 and prv_1==false){
				prv_1=true;
				num=num>>1;
			}else{
				have_consecutive_1=true;
				break;
			}

		}

		if(have_consecutive_1==false) count++;
	}

	return count; }

*/

//Tabulation + Space Optimisation=>

long long no_of_string_with_no_consecutive_1(int n){
	if(n==0) return 1;

	/*Intution=>

		if n=0->1{""};
		if n=1->2{"1","0"};
		if n=2->3{"10","00"};
		if n=3-> 5{"100","101","100","010","001","000"};

		From Above We can see that this is Pattern of fibonacci :)

	*/
    
	if(n==1 or n==2) return n+1;

	int prv=3,prv_prv=2;

	for(int idx=3;idx<=n;idx++){
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

  	long long no_of_string=no_of_string_with_no_consecutive_1(n);
  	printf("no_of_string: %lld\n",no_of_string);
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

