//link: https://codeforces.com/contest/1611/problem/B


#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



void solve(){

   
   int a,b;
   cin>>a>>b;

   if(a>b)
    swap(a,b);

    /*

   -----------------------
    a<=b
    now start removing (1,3) ie

   (a,b)-> (a-x,b-3x) [after removing 'x' teams of (1,3) from (a,b) ] 

    Since we are removing 'more from b' and 'less from a'
    So there will be a inversion point in the inequality-> when  we get ->  (a>=b) 

    ie in other words : 
    (old_a <= old_b)   (initially)
    (new_a >= new_b)   (finally)   where new_a = a-x,  new_b = b-3x
    
  Finding 'x'

     a-x >= b-3x 
     2x  >= b-a
      x  >= (b-a)/2  (taking ceil value)
      x  >= (b-a+1)/2  .....(1)

    [
      Note : but also we want -> a-x>=0 and b-3x>=0
      ie a>=x and b>=3x 
         a>=x and (b/3)>=x 
         min(a,b/3)>=x   .......(2)

    ]

    
        from (1) and (2)
           L      <=  x <=      R         (L<=R)
        (b-a+1)/2 <=  x <= min(a,b/3)

        But for some testcase  (eg a=2,b=100) 
        we get L>R  ie  'x is so big' 
        we have       '(a-x<0) or (b-3x<0)'  which we don't want 
        so in this case we have to compromise with x = min(a,b/3) 


     So finally 'x teams' will be
      x =  min(  {a, b/3,  (b-a+1)/2} )

    */

    

    int x =  min( { a,  b/3,  (b-a+1)/2 });

    a = a - x;
    b = b - 3*x;

    //finding no of (2,2) from remaining teams 
    
    // cout<<a<<","<<b<<endl;

    int rem = max( (int) 0, min(a/2, b/2));

    // watch(x);
    // watch(rem);

    cout<<(x+rem)<<endl;
 


}


// Fuck rating 
// enjoy process and improvement(by red coders like colin)

int32_t main()
{
    fast
    int tc = 1;
    cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}
