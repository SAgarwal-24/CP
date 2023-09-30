// https://www.codechef.com/COOK64/problems/SEAARASU
// editorial - https://discuss.codechef.com/t/seaarasu-editorial/11896
// 

#include <bits/stdc++.h>
#define int long long int 
using namespace std;

int gcd(int a, int b){

    if(b==0)
        return a;

    return gcd(b,a%b);
}

void solve(){

    int i,n,x;
    cin>>n;

    int g;
    cin>>g;

    for(i=1;i<n;i++){
        cin>>x;
        g=gcd(g,x);
    }

    cout<<n*g<<endl;

}

int32_t main()
{
    int tc = 1;
    cin >> tc;

 
    while (tc--)
    {
        solve();
    }

    return 0;
}
