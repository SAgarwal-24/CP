/*
link - https://codeforces.com/contest/1855/problem/B
solution - https://codeforces.com/contest/1855/submission/216352222
*/

void solve(){

    long long n;
	cin>>n;

    if(n&1){ 
        cout<<1<<endl;
        return;

        /*
            n-> is odd -> therefore none of the even no is multiple of x 
            so interval [l,r] length can be max. 1 
        */
    }	

    /*
      say  n = 720  = 8x9x10 -> so it seems [8, 9, 10] is one of the valid interval
      which is actually [2x2x2, 3x3, 5x2] ie we can break any valid set into smaller number which have more probablity of getting converge/continous interval
      we can observe - [1,2,3,4,5,6] is probable set 
    */

   int factor = 1, cnt = 0;
   while(n % factor == 0){
    factor ++;
    cnt ++;
   }

   cout<<cnt<<endl;

}
