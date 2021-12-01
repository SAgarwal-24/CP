link: https://codeforces.com/problemset/problem/459/A

#include <bits/stdc++.h>
using namespace std;
 
int dis(int x1,int y1, int x2, int y2){

    return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);

}
void solve() {
     int i, n; 
     
     //remember sides of square are parallel to standard coor-axes graph
     int x1, y1, x2, y2;
     cin>>x1>>y1>>x2>>y2;

     int x3, y3, x4, y4;

    //case-1 : (x1,y1) and (x2,y2) are not adjacent ie on diagonal 
     if(x1!=x2 and y1!=y2){ //we can't consider sides as diagonal as sides of square are parallel to standard coor-axes graph
        y4 = y1;
        x4 = x2;

        y3 = y2;
        x3 = x1;

        if(dis(x1,y1,x3,y3) != dis(x2,y2,x3,y3)){
            cout<<-1<<endl;
          //  return;
        }
     }
    //case-2 : (x1,y1) and (x2,y2) are  adjacent 
     else if(y1==y2){
        x3=x1, x4=x2;
        int s = abs(x2-x1);
        y3=y4=y1+s;
     }
     else if(x1==x2){
        y3=y1, y4=y2;
        int s = abs(y2-y1);
        x3=x4=x1+s;
     }
     
    
     cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}

 
int32_t main()
{
    fast_cin();
    ll tc=1;
    // cin >> tc;
    while (tc--) 
     {
        solve();
     }
    return 0;
}
