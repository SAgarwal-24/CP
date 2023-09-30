// Simple implementation based
// https://codeforces.com/problemset/problem/1042/B

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int bitmask(string s){
    sort(s.begin(),s.end());

    string abc="ABC";
    int num=0,j=s.size()-1;

    int wt=1;
    for(int i=2;i>=0;i--){
        if(abc[i]==s[j]){
            num+=wt;
            j--;
        }
        wt=wt*2;
        if(j==-1)break;
    }

    return num;
}

int32_t main(){
fast

   int n,i,k,j;
   string s;

   cin>>n;
   int cost[8];
   memset(cost,-1,sizeof(cost));

   for(i=0;i<n;i++){
       int c;
       cin>>c>>s;
       int num=bitmask(s);

       cost[num]=(cost[num]==-1)?c:min(c,cost[num]);
       
   }


    for(i=1;i<8;i++){
        if(cost[i]==-1)continue;

       for(j=i+1;j<8;j++){
           if(cost[j]==-1)continue;
           
           if(cost[i|j]==-1)
           cost[i|j]=cost[i]+cost[j];
           else
           cost[i|j]=min(cost[i|j],cost[i]+cost[j]);
       }
     
   }

//    for(i=1;i<8;i++){
//        cout<<cost[i]<<" ";
//    }
//    cout<<endl;

    int  ans=cost[7];
    cout<<ans<<endl;
   

return 0;
}
