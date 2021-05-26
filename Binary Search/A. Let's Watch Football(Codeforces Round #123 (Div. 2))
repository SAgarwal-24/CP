// Awesome Binary search application with time and data speed flavour in story .. xd
// We have to find out minimum waiting time 

#include <bits/stdc++.h>
using namespace std;


int32_t main(){

   int a,b,c; cin>>a>>b>>c;
   
   // watch_tim= (tot_time-wt);
   //waiting_tim = wt;

   // waiting_tim_data + watch_tim_data >= tot_data
   //  wt.b  + (tot_time-wt).b >= (tot_time-wt).a
   //  tot_time.b >= (tot_time-wt).a
   // or wt.a >= tot_time.(a-b)


   int tot_time=(a*c+b-1)/b; // tot_time= ceil(a*c)/b time download full video

   int lo=0, hi=tot_time;

   int wait=hi;
   while(lo<=hi){
       int mid= lo+ (hi-lo)/2; // mid is waiting time instant

       if(mid*a>=tot_time*(a-b)){
           wait=mid;
           hi=mid-1;
       }
       else{
           lo=mid+1;
       }

   }
   
   cout<<wait;

  
  return 0;
}

