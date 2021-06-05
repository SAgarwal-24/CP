// https://codeforces.com/problemset/problem/1362/B
// B. Johnny and His Hobbies
// XOR based brute force


#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// here we require a sequence such that
// seq-> a1, a2, a3, .. am, a1^k, a2^k, a3^k, ... am^k
// ie if their is a element a1 in sequence 
// then their must be a1^k too for any k and we need to find minimum such k

// case-1: when k not exists
// their are cases when such k doesn't exist  like
// when nos are 10, 100, 1000 (binary format) ans=-1

//case-2: when k exists
// case-2.1
// say we have 6 elements in array
// ie: seq->  a,b,c,a^k,b^k,c^k  (all are distinct)
// then taking xor of whole sequence gives-> k^k^k=k (other terms cancel)

// case-2.2
// seq -> a,b,a^k,b^k (all are distinct)
// now taking xor of whole sequence gives-> k^k=0 so we can't find k in this case
// since constraints are small do brute force (n<1024)
// so find all possible k by doing n^2 iteration and find all k by pairwise xor and store them
// ie for(i,n)
//    for(j,n)set.insert(k=a[i]^a[j])
// and then verify eack k


// all a[i] are distinct but are solution will pass even for non distinct
// if we don't store 0 in the set which contains all possible k 

int32_t main(){
fast
int tc=1;
cin>>tc;
while(tc--){
   int n,m,i,j;

   cin>>n;
   set<int>st;
   int a[n], has[1045]={0};

   int k=0;
   bool ok=true, flg=false;

   for(i=0;i<n;i++){
       int x; cin>>x;
       a[i]=x;
       has[x]=1;
   }

   for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
           if((a[i]^a[j])>0)
          {
             // watch(a[i]^a[j]);
              st.insert(a[i]^a[j]);
          } 
       }
   }

  // watch(k);

   for(auto x:st){
       ok=true;

      // cout<<x<<endl;

       for(i=0;i<n;i++){
           if(has[a[i]^x]==0){
                ok=false; break;
          } 
       }
      
      if(ok){
          flg=true; k=x; break;
      }
   }
   
   
   if(flg)cout<<k;
   else cout<<-1;

   cout<<endl;
}
return 0;
}
