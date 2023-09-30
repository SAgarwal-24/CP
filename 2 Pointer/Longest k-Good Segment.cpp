// https://codeforces.com/problemset/problem/616/D
// D. Longest k-Good Segment
// Educational Codeforces Round 5

// Standard 2-pointer problem to find longest segment with distinct elements<=k
// revise it

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl
#define hh cout << endl
#define bor cout<<"\n---\n";
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


struct par{
    int l,r;
};

int32_t main(){

    fast

     int i,n,k; cin>>n>>k;
    
     int a[n+1]={0};
     for(i=1;i<=n;i++)cin>>a[i];

     //for(i=1;i<=n;i++)cout<<a[i]<<" ";

    
    par ans={1,1};

    unordered_map<int,int>fre;

    int st=1,dis=0,len=0;
    i=1;
    while(i<=n){
        fre[a[i]]++;

        dis+=(fre[a[i]]==1);

        while(dis>k){
            fre[a[st]]--;
            dis-=(fre[a[st]]==0);
            st++;
        }

        if(len<i-st+1){
            len=i-st+1;
            ans.l=st, ans.r=i;
        }

        i++;
    }
   
    
    cout<<ans.l<<" "<<ans.r;


//return 0;
}
