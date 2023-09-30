// https://codeforces.com/problemset/problem/192/A
//A. Funky Numbers (Codeforces Round #121 (Div. 2)
// simple problem fun problem - s=a+b and we have both 'a' and 'b' in vector in sorted form

#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main(){
  

  int n; cin>>n;
  vector<int>a;

  int num=1,diff=2;
  while(num<=n){
      a.push_back(num);
      num=num+diff;
      diff++;
  }

  for(int i=0;i<a.size();i++){          // a-> 1,3,6,10,15,21 (monotonic increasing)

      int lo=i, hi=a.size()-1;
      while(lo<=hi){
          int mid=lo+(hi-lo)/2;

          if(a[mid]+a[i]==n){
              cout<<"YES\n"; return 0;
          }
          else if(a[mid]+a[i]>n){
              hi=mid-1;
          }
          else{
              lo=mid+1;
          }
      }
  }
  
  /* -------------- alternative stl code ------
  int s=a.size();
  for(int i=0;i<s;i++){

      if(binary_search(a.begin()+i,a.end(),n-a[i])){
           cout<<"YES\n"; return 0;
      }
      
  }
  
  */



  cout<<"NO\n"; 
  return 0;
}
 
