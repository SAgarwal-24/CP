// https://codeforces.com/contest/1555/problem/D


#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


template<typename C,
typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container){
bool first = true;
std::stringstream ss; 
ss << '[';
   for(const auto &x : container){
       if (!first){
           ss << ", ";
       }
       first = false;
       ss << x;
   }
   ss << ']';
   return os << ss.str();
}
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> &p){
   os << '{' << p.first << ", " << p.second << '}';
   return os;
}


int32_t main(){
fast
int tc=1;
//cin>>tc;
while(tc--){
   int n,m,i,j,q;
   cin>>n>>q;

   string a; cin>>a;

   vector<string>permut={"abc","acb","bac","bca","cab","cba"};

   vector<vector<int>> prefix(6,vector<int>(n,0));


   for(i=0;i<6;i++){
       //cout<<permut[i]<<endl;
       for(j=0;j<n;j++){

           prefix[i][j] = (j>0)?prefix[i][j-1]:0;
           prefix[i][j] +=  permut[i][j%3]!=a[j];

       }
       
       //cout<<prefix[i]<<endl;
   }

   while (q--)
   {
      int l,r; 
      cin>>l>>r;
      l--,r--;

      int cost = 1e6;

      for(i=0;i<6;i++){

          int hi  = prefix[i][r];

          int low = l>0 ? prefix[i][l-1] : 0;

          cost = min(cost, hi-low);
      }

      cout<<cost<<endl;

   }
   

   
   
}
return 0;
}
