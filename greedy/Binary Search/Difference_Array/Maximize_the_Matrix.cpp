//link: https://www.interviewbit.com/problems/maximize-the-matrix/  (awesome question deserves revision)
// helpful link: https://pastebin.com/UGbH69wJ
// my_code_link: https://ideone.com/7HdyDs


//Binary Seach + difference_array_logic for check function

#define vi vector<int>

bool check(vector<vector<int> > &a, int b, int c, int mi){

    int row=a.size(), col=a[0].size();
    int i,j;

    int cnt=0; //cnt of operations reqd. so that new_min_of_matrix = mi

     for(i=0;i<row;i++){

         vi op(col+1, 0); //operations required for each element 

        for(j=0;j<col;j++){
            
            // if(mi+1 > a[i][j])  //elements already greater 
            op[j] =  (mi - a[i][j] + 1)/2;
            
        }

    
        vi remove_inv_op(col+1, 0); // to remove invalid operations for any jth element ie operations which not belong to window of jth element
        int pref=0; //containing no of operation done till now on op[j] bcz of elements already in any of the window 

        

        for(j=0;j<col;j++){
            
            pref += remove_inv_op[j]; // operations to removed from pref which are not in window of op[j]  
            op[j] -= pref;  //operation on a[i][j] done bcz of elements in window of 1Xc operation

            if(op[j]>0){ // if still we need some operations in op[j] 
                cnt += op[j];
                pref += op[j];  //now these operations are done on window of [j, j+c] , so we store them in variable 'pref'  

                if(j+c<col){
                    remove_inv_op[j+c] -= op[j];
                }
            }

            if(cnt>b)
              return false;
        }
     }

     return true;
}

int Solution::solve(vector<vector<int> > &a, int b, int c) {

    int lo = -1e8, hi = 1e9, ans=0;

    while(lo<=hi){
        int mi = lo + (hi-lo)/2;

        if(check(a, b, c, mi)){
          
            ans = mi;
            lo = mi+1;
        }
        else{
            hi = mi-1;
        }
    }

    // cout<<ans<<endl;
    return ans;
}
