#### Print permutations of a given string using backtracking:
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


#### Permutation when repetition is allowed

```
We can easily calculate the permutation with repetition. The permutation with repetition of objects can be written using the exponent form.

When the number of object is “n,” and we have “r” to be the selection of object, then;

Choosing an object can be in n different ways (each time).

Thus, the permutation of objects when repetition is allowed will be equal to,

n × n × n × ……(r times) = nr

This is the permutation formula to compute the number of permutations feasible for the choice of “r” items from the “n” objects when repetition is allowed.
```

### Important Leetcode Posts
1. [Number Theory (Prime nos. etc) - TOPICS WHICH YOU CAN'T SKIP | INTERVIEW PREPARATION | Part 1](https://leetcode.com/discuss/study-guide/3735417/topics-which-you-cant-skip-interview-preparation-part-1)
2. Important and Useful links from all over the LeetCode - https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-LeetCode


