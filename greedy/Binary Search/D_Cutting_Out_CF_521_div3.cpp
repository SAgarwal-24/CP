//https://codeforces.com/contest/1077/problem/D
// D. Cutting Out
// Codeforces Round #521 (Div. 3)

// Binary search on  no of copies of smaller string can be present in larger string
// and to check no of copies present "Matrix filling column wise with same character technique" is used 
// this trick deserves a bookmark and revision

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl
#define hh cout << endl
#define bor cout<<"\n---\n";
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


struct num{
    int val,abundance;
};

int32_t main(){

    fast
    int n,k,i; cin>>n>>k;
    
    int s[n];
    map<int,int>freq;
    for(i=0;i<n;i++){
        cin>>s[i];
        freq[s[i]]++;
    }
    
    int copy=n/k;
    int lo=1, hi=copy; // lo=1 bcz their always exist a string with k character to make one copy 
    // eg s="12345678" k=4 even if all are different then also we have say t="1234" 
    // we know "1234" is not present multiple times but it is present at least once so 
    // lower_bound of no of copies = 1 ie lo=1 .. otherwise runtime error
    
    vector<num>ans;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2; //no of copies to be removed
                            // ie matrix of mid*k total elements
                            // and we have to fill the matrix column wise
                            // such that each column is filled with same number or letter

        // in order to check whether a character has enough frequency to fill 
        // whole column of the matrix
        // so distribute its frequency in all rows of matrix
        // ie (frequency/no of copies) or (frequency/mid) as mid=no of copies
                        
        int spaces=0;
        vector<num>v;
        for(auto ele:freq){
            int x=ele.first, f=ele.second;
            if((f/mid)>0){
                v.push_back({x,f/mid});
                spaces+=(f/mid);
            }

            if(spaces>=k)break;
        }

        if(spaces>=k){
            ans=v;
            lo=mid+1;  // check if more copies can be removed
        }
        else{
            hi=mid-1; 
        }
    }

    for(auto par:ans){
        int x=par.val;
        int f=par.abundance;

        while(f-- and k--){ // print k elements at most representing string t 
            cout<<x<<" ";
        }
    }

//return 0;
}
