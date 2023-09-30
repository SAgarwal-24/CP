// link: https://www.codechef.com/FOUR21B/problems/S03E02
//sol link: https://www.codechef.com/viewsolution/54543251

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define all(c) c.begin(), c.end()
#define int long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container)
{
    bool first = true;
    std::stringstream ss;
    ss << '[';
    for (const auto &x : container)
    {
        if (!first)
        {
            ss << ", ";
        }
        first = false;
        ss << x;
    }
    ss << ']';
    return os << ss.str();
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << '{' << p.first << ", " << p.second << '}';
    return os;
}



void solve(){

 
	
   int i,n,k,j;
   cin>>n>>k;

   string s;
   cin>>s;

    
   if(n==1){
       cout<<n<<endl;
       return;
   }

  
    int pc=0, sc=0, ans=0, l=0, r=n-1;

    //prefix of equal colors 
    i=0;
    while(i<n-1 and s[i]==s[i+1])
        i++;
    l=i+1;
    pc=l; // prefix cnt of equal colors

   

    if(pc==n){  //all color are equal
        cout<<n<<endl;
        return;
    }

    if(k==0){  //atleast one color different and we can't make move
        cout<<-1<<endl;
        return;
    }


    //suffix of equal colors 
    j=n-1;
    while(l<j-1 and s[j-1]==s[j])
        j--;
    r=j-1;
    sc=(n-1)-r; //suffix cnt of equal colors

   

    //best answer for k=1 ie 1 deletion 
    if(s[0]==s[n-1]){
        ans = pc + sc;  
    }
    else{
        ans = max(pc, sc);
    }

    if(k==1){ //only 1 deletion
        cout<<ans<<endl;
        return;
    }

   

    assert(k>=2);

    map<char,vi>fre;

    i=l;
    while(i<=r){

        j=i+1;

        while(j<=r and s[i]==s[j])
            j++;
        
        fre[s[i]].pb(j-i);

        i=j;
    }


    // watch(fre);

    for(auto it:fre){

        char ch = it.first;

        sort(all(fre[ch]), greater<int>());

        int c=k-1, f=0;
        
        for(auto x:fre[ch]){

            if(c==0)break;

            f+=x;
            c--;
            
        }

        if(ch==s[0]) f=f+pc;
        if(ch==s[n-1])f=f+sc;

        ans = max(ans, f);
    }

    cout<<ans<<endl;

    
   
}


// Fuck rating 
// enjoy process and improvement(by red coders like colin)

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


