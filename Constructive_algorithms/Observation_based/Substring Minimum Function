/*
link:https://www.codechef.com/FZBZ21B/problems/SUBMIMX
best clean code: https://www.codechef.com/viewsolution/54360610

-but below is more understandale and shows struggle...xd...showing some cases , corner cases and gives better picture of thinking pattern
-main idea strike
  since -> F(n) = no_of_substring = n*(n+1)/2   (say length of substring = n)
                                  = (n^2 + n)/2   (we can se n^2 factor ....giving massive high value to F(n))
                                  
  Therefore to minimise F(n) -> definitely try to minimise n ->  specially bcz of n^2 factor 
  hence our goal is to keep length_of_maximum_segment_of_zeros as minimum as possible  

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



void solve(){

  
   int n,m;
   cin>>n>>m;

   int ones = m;
   int zeros=n-m;

   if(ones==0){

       cout<< (zeros*(zeros+1))/2<<endl;
       return;
   }

   if(zeros<=ones){
       cout<<zeros<<endl;
   }
   else{

       int len = (zeros/(ones+1));

       int rem = zeros %(ones+1);

  

        int p1 =  rem;
        int p2 =  ones+1 - p1;
         
        

        int ans2 = (p2*len*(len+1))/2;
        int ans1 = (p1*(len+1)*(len+2))/2;

        cout<< ans1 + ans2 <<endl;
   }


return;
  
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
