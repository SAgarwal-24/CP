//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int  long long
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


struct burger{

    int unit_b=0;    // unit burger
    int unit_s=0;    // unit sausage
    int unit_c=0;    // unit cheese
};

void solve(){

   string s;   
   cin>>s;

   int i,n=s.size();

   int nb,ns,nc;
   cin>>nb>>ns>>nc;

   int pb,ps,pc;
   cin>>pb>>ps>>pc;

   int rubles;
   cin>>rubles;

   burger b;

   for(i=0;i<n;i++){

        b.unit_b += s[i]=='B';
        b.unit_c += s[i]=='C';
        b.unit_s += s[i]=='S';
   }

   int lo=0, hi=1e13; //[0,1e13] burgers can be made 

   int ans=0;

   //if 'mid' no of burgers can be made then definitely 'mid-1' burgers can be make - with given money and material

   while(lo<=hi){
       int mid = lo+(hi-lo)/2;

     // need_burger = burger_required - already_available_burger_in_kitchen
     // need_burger =  mid*b.unit_b   - nb                                  (similarly for cheese and sausage)

        int need_b=0, need_s=0, need_c=0;

        need_b = max( (mid * b.unit_b) - nb , (int)0);
        need_s = max( (mid * b.unit_s) - ns , (int)0);
        need_c = max( (mid * b.unit_c) - nc , (int)0);

        int expense = pb*need_b + ps*need_s + pc*need_c;

        if(expense<=rubles){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
   } 

   cout<<ans<<endl;
  
}


// Fuck rating 
// enjoy process and improvement(by red coders like colin)

int32_t main()
{
    fast int tc = 1;
    // cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}
