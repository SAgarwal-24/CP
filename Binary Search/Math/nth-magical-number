//link: https://leetcode.com/problems/nth-magical-number/
//Inclusion-exclusion based 


class Solution {
public:
    int m = 1e9+7;
    #define ll long long 
    
    ll gcd(ll a, ll b){
        
        while(b>0){
        ll c = b;
            b = a%b;
            a = c;
        }
        
        return a;
    }
    
    ll lcm(ll a, ll b){
        
        return (a*1LL*b)/gcd(a,b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        
        ll ans=0;
        
        ll l=min(a,b), r=n*1LL*(min(a,b));
        
        ll hcf = lcm(a,b);
       
 
        while(l<=r){
            
            ll mi = l + (r-l)/2;
            
            ll cnt = (mi/a) + (mi/ b) - (mi/hcf);
            
            if(cnt>=n){
                ans = mi;
                r = mi-1;
            }
            else{
                l = mi+1;
            }
            
        }
        
        return ans%m;
    }
};


