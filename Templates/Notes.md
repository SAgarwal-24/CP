Print permutations of a given string using backtracking:
![file](https://github.com/SAgarwal-24/CP/assets/44989343/684b8b42-6b70-49d5-a289-8b8eba613b8d)

```
void permute(string& a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l + 1, r);
 
            // backtrack
            swap(a[l], a[i]);
        }
    }
}
```
