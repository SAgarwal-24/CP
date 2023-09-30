// A. You Are Given Two Binary Strings (GREEDY TYPE ON BINARY STRINGS)
// trick: do bitwise or of 2 strings such that to make there sum(bitwise or) lexi. minimal
// https://codeforces.com/problemset/problem/1202/A

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


// sk=f(x)+f(y)⋅2^k   or sk= f(x) | f(y) ie bitwise sum
// Multiplying by 2^k is equivalent to appending zeros
// since we have to minimize rev(sk) lexicographically

// ie make more zeros as much as possible in sk
// x=10000 , y=1
// then append 4 zeros in y  to make it look like as
// x=10000 y=10000  so that sk=x|y (bitwise or) ie sk=100000
// actually we tried to make rightmost 1 of x to zero

// below we can't make rightmost 1 of x as zero bcz we can only append not remove zeros
// so we make next rightmost 1 of x as zero by appending zero in x
// x=10001 , y=10
// x=10001
// y=   10
// so append 3 zeros to make next rightmost bit of x as zero greedily to get lexi minimal rev(sk)



int32_t main(){
fast
int tc=1;
cin>>tc;
while(tc--){
   int n,m,i,j;
   
   string s1,s2; cin>>s1>>s2;

   int n1=s1.size(), n2=s2.size(), p=0;

   i=n2-1;
   while(i>=0){
       if(s2[i]=='1')break;
       i--;
   }

   j=n1-1-(n2-1-i);
   int ans=0;


   while(j>=0){
       if(s1[j]=='1')break;
       ans++;
       j--;
   }

   cout<<ans<<endl;
   
 
}
return 0;
}
