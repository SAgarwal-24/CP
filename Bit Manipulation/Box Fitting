/*
https://codeforces.com/problemset/problem/1498/B
Box Fitting

Trick : since all width is of form 2^x so use bitmasking and frequency map and keep putting largest block first

Their are multiple ways to solve this problem like binary search
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << endl
#define hh cout << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define bor cout << "\n---\n";



template<typename C,
typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container){
bool first = true;
std::stringstream ss; 
ss << '[';
   for(const auto &x : container){
       if (!first){
           ss << ", ";
       }
       first = false;
       ss << x;
   }
   ss << ']';
   return os << ss.str();
}
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> &p){
   os << '{' << p.first << ", " << p.second << '}';
   return os;
}

void print(int x)
{
    string s = "";
    while (x)
    {
        if (x & 1)
            s += "1";
        else
            s += "0";
        x = x / 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int32_t main()
{

    fast int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n, m, i, W;
        cin >> n >> W;

       

        int ans = 0;
        int w = 0;
        map<int, int> fre;

        for (i = 0; i < n; i++)
        {
           
            int x;
            cin >> x;
            w = w | x;
         
            fre[x]++;
        }

       

            while (w)
        {
            int slab=W;
            i=19;
            

            while(i>=0 and w)
            {
                int bit = w & (1 << i);
               
                if (bit)
                {
                    
                    if(bit<=slab){
                        slab-=bit;

                        fre[bit]--;
                        
                         // cout<<bit<<endl; print(bit);
                 
                        if(fre[bit]==0){
                            w = w xor bit;
          
                        }
                        continue;
                    }
        
                }

             
                i--;
            }
            
            ans++;

        }

        cout << ans << endl;
    }
    return 0;
}


                  
