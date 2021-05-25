//C. To Add or Not to Add  Codeforces Round #143 (Div. 2)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define mod 1000000007

#define all(c) c.begin(), c.end()

#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << endl
#define hh cout << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define show(A) for (auto i: A) cout << i << " "; cout << '\n';
#define show_(A, n) F(i, n) { show(A[i]) }


struct tupple{
    int fre,no;
};

int32_t main(){
fast
 
  int  k,n,i; cin>>n>>k;
  

  int a[n+1]={0};
  for(i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);



  int pre[n+1]={0};
  for(i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];

  tupple ans={-1,-1};
  int lo=1,hi=n;
  while (lo<=hi)
  {
      int mid=lo+(hi-lo)/2; // window size

        int sum=0,f=0;
        for(i=mid;i<=n;i++){
            sum=pre[i]-pre[i-mid];

            if((a[i]*mid)-sum<=k){
               
                ans.fre=mid;
                ans.no=a[i];
                f=1;
                break;
            }
        }

     

        if(f&1){ 
            lo=mid+1;  // got something now check for more window size
        }
        else{
            hi=mid-1; // starve for smaller window
        }
  }
  

  cout<<ans.fre<<" "<<ans.no;
 
  return 0;
}

