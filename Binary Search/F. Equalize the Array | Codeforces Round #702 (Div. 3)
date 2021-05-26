// F. Equalize the Array | Codeforces Round #702 (Div. 3)
// Awesome question on BS ... deserves a revision

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define mod 1000000007
#define all(c) c.begin(), c.end()

#define watch(x) cout << (#x) << " is " << (x) << endl
#define border  cout<<"----\n";

#define hh cout << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



int32_t main(){
fast
  
  int tc; cin>>tc;
  while(tc--){
      int n,i;
      cin>>n;

      map<int,int>fre_mp;
      for(i=0;i<n;i++){  //O(nlogn)
          int ele; cin>>ele;
          fre_mp[ele]++;
      }


    // Make a frequency array
      vector<int>fre_arr;
      for(auto par:fre_mp){  //O(n)
         // fre_arr.insert(fre_arr.end(),par.second,par.first);
         fre_arr.push_back(par.second);
      }

      sort(all(fre_arr));
     
    //   for(auto x:fre_arr)
    //   cout<<x<<" ";

    //   cout<<endl;
     
     // make suffix sum of whole frequency array
      int siz=fre_arr.size();
      int suf[siz+1]={0};
      int pre[siz+1]={0};

      suf[siz-1]=fre_arr.back();
      pre[0]=fre_arr[0];
      
      for(i=siz-2;i>=0;i--){  //O(n)
          suf[i]=suf[i+1]+fre_arr[i];
      }
      for(i=1;i<siz;i++){
          pre[i]=pre[i-1]+fre_arr[i];
      }


    //   for(i=0;i<siz;i++){
    //       cout<<suf[i]<<" ";
    //   }
    //   cout<<endl;

    //   for(i=0;i<siz;i++){
    //       cout<<pre[i]<<" ";
    //   }
    //   cout<<endl;
     

      int ans=INT_MAX;
      //Now generate (L,R) for all frequencies
      // ie check is it suitable to convert to all elements to that frequency
      // so finding (L,R) for all frequencies from vector..,its double work
      for(auto ele:fre_arr){
          int big=upper_bound(all(fre_arr),ele)-fre_arr.begin();
          int smal=lower_bound(all(fre_arr),ele)-fre_arr.begin();

          //cout<<ele<<": b,s "<<big<<","<<smal<<endl;

          int right=suf[big]-((siz-big)*ele);
          int left=0;
          if(smal>0)left=pre[smal-1];

          //cout<<right+left<<endl;
          //border

          ans=min(ans,right+left);
      }

      cout<<ans<<endl;

  }
 
  return 0;
}

