/*
https://codeforces.com/problemset/problem/1407/C
----------
Editorial
Observation: (a mod b > b mod a)⇔(a<b).

Proof: if a>b, then (amodb)<b=(bmoda). If a=b, then (amodb)=(bmoda)=0.
----------
each time we will make two queries and whichever no is small we can guess it 100% correctly as
(small_no % big_no = small_no ) 
and we can't make guess for big_no so we keep updating 'mx' pointer 
--------
helpful : https://www.youtube.com/watch?v=iLqCGiqVn1k

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cout<<(#x)<<" is: "<<x<<endl;

int32_t main(){

    int n,i,r1,r2,mx=1; cin>>n;

    int ans[n+4]={0};
    fill(ans,ans+n+1,n);

    for(i=2;i<=n;i++){

        cout<<"? "<<mx<<" "<<i<<endl;
        cin>>r1;

        cout<<"? "<<i<<" "<<mx<<endl;
        cin>>r2;

        if(r1>r2){ // a[mx]<a[i] so a[mx] is correct guess
            ans[mx]=r1;
            mx=i; //update mx to max.
        }
        else{ // a[i]<a[mx] so a[i] is correct guess
            ans[i]=r2;
        }


    }

    cout<<"! ";
    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }


   return 0;  
}
