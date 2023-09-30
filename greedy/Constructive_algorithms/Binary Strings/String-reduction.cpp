// https://www.hackerrank.com/challenges/string-reduction/problem
// https://www.geeksforgeeks.org/smallest-length-string-with-repeated-replacement-of-two-distinct-adjacent/

// Can be done also using - dp
// This is mathematical approach (explained of gfg in detail- worth seeing it - awesome insights on strings containing 3 characters )

int stringReduction(string s) {
    
    int i, n=s.size(), ans=0;
    
    int cnt[3]={0};
    
    for(i=0;i<n;i++){
       
       cnt[s[i]-'a']+=1;
       
    }
    
    if(cnt[0]==n || cnt[1]==n || cnt[2]==n)
        return n;
    
    
    if(cnt[0]%2==cnt[1]%2 and cnt[1]%2==cnt[2]%2)
        return 2;
    
    return 1;
    
}
