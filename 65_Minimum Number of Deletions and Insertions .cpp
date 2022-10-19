// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

/*
    IDEA->Minimum Insertions/Deletions to Convert String A to String B 

    We want to make strings equal with minimum operations --> So we need to do minimal change as possible

    # Find LCS of s1 and s2  -> # ans = l1-lcs+l2-lcs
*/
int canYouMake(string &str, string &ptr){
    int l1=str.size(),l2=ptr.size();
    vector<int>prv(l2+1),curr(l2+1);

    for(int i=1;i<=l1;++i){
        for(int j=1;j<=l2;++j){
            if(str[i-1]==ptr[j-1]){
                curr[j]=1+prv[j-1];
            }else{
                curr[j]=max(prv[j],curr[j-1]);
            }
        }
        prv=curr;
    }
    int lcs_len=prv[l2];
//     cout<<"lcs_len->"<<lcs_len<<"\n";
    return l1+l2-2*lcs_len;
}