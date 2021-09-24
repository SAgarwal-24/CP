#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int a,b,c,m;
        cin>>a>>b>>c>>m;

        int ar[3]={a,b,c};
        sort(ar,ar+3);

        int low=0, hi =0;

        low = ar[2] - 1 - (ar[1]  + ar[0]);
        hi = (a-1) + (b-1) + (c-1);

        if(low<=m and m<=hi){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

        
    }
}

/*
link - https://codeforces.com/contest/1574/problem/B#
- Awesome question on  Permutation and Combinations knowledge 
- and needs kind intuition of -> "Division of Objects into Groups" (P&C standard topic)
- editorial is awesome  specially last paragraph explaining reasoning for "Exactly m pairs"


-  ie "Now for the proof of the fact that every value in-between is also achievable.
     Since we have a construction for m=0, let's try modifying it. 
     Let's reduce the test to m=0 the following way. 
    While m>0, decrease the count of the letter that appears the most by 1 and decrease m by 1.
    Now build the string for m=0 with the reduced values. 
    After that put the letters back, placing them next to the last occurrence of the 
    same letter (there is at least one occurrence of each letter, the proof is trivial). 
      That increases m by 1 and the count of this letter by 1. 
      Thus, we'll return to the initial test."

*/
