//https://codeforces.com/problemset/problem/1514/B
// bitmask observation based

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


// say n=4 k=4
// one of the config in which we must need BITWISE AND of all elemetns 0
// and we must need maximum sum

// so one of the possible config to satisfy both must condition is
//    14->  1110
//    13->  1101
//    11->  1011
//    7->   0111
// sum=45

// it is kind of (n X k) rectangular matrix ie n rows and k columns
// so their are n rows or n places or n options to make only one cell of a column zero
// for each column we can't make more than 1 cell 0 bcz we don't want to compromise on sum
//  so for each column their are n-choices
//  so for k column their are n*n*n...*n ktimes ie n^k choices to achieve this config

// one more eg n=4 k=4
//      1010 - 10
//      1101 - 13
//      0111 - 7
//      1111 - 15
//  here also  sum=45 and each col has atmost one zero
// so 4*4*4*4 = 4^4 choices to get this config

int32_t main(){
fast
int tc=1;
cin>>tc;
while(tc--){
   int n,i,k;
   cin>>n>>k;

   int mod=1e9+7, ans=1;
   for(i=1;i<=k;i++){
       ans=((ans%mod) * (n%mod))%mod;
   }

    cout<<ans<<endl;
   
}
return 0;
}
