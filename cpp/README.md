# Must read things for leetcode specially

Leetcode Editor

imap kj <Esc>
or
imap kj <C-c>

Clion

shift + f9 for build and execute
shift + f10 for debug build and execute

The file readme.cpp will have code for how to accomplish this.

1. integer maximum, minimum, syntax, integer to string, string to integer
2. use of std::distance
2. max element of vector, accumlate of vector, iota
3. max function of 1, 2, 3, 4, .. items
2. vector initializations
3. custom comparator, with auto function and old school method, for sort and lower_bound
   https://leetcode.com/problems/find-right-interval/description/?envType=problem-list-v2&envId=sorting
see submissions
   1. auto lambda, std::function lambda
   2. plain bool function, using std::bind()
   3. functor: struct with operator() overloading
   4. Custom Node struct with operator < overloading
4. priority queue with custom comparator, with greater<>
5. sort and remove duplicates in two lines: coordinate compression
5. min heap implementation
5. bit manip tricks, bitset<N>
6. https://codeforces.com/blog/entry/72437
6. sorting
7. hashmap
8. random number init 
9. lower bound, upper bound, for sorted vector, map, set
10. set, map, hashset, hashmap, insert, lookup, erase operations
for example, map insert does not replace value if already exists.
11. 

binary search
case 1: find the last true
```c++
for [0....n-1] = [tttttfffffffffff]
lo  = 0, hi = n; // [0, n)
while(hi-lo > 1) {
    ll mid = (lo+hi)/2;
    if(fun(mid)) lo = mid; // [mid, n)
    else right = mid; // [lo, mid);
}
ans = left;
```
```c++
//https://leetcode.com/problems/first-bad-version
case 2: find the first true
for [1...n] = [fffffffffttttt]
lo = 0, hi = n; // (0, n]
while(hi-lo > 1) {
    ll mid = (1+lo+hi)/2; <!!!!!!!!! important ~~~~~~>
    if(fun(mid)) hi = mid;
    else lo = mid;
}
ans = right;
```









#### Tips, learn from mistakes

1. Databricks interview experience
2. IP address in CIDR range check function implmentaition
3. Things that went wrong

1. Webcam's exposure was not good, dimly lit.
2. Did not focus on the core algorithm early 
on, taking the net mask, applying it to CIDR range, get min and max, and checking if IP is between min and max
3. did not ask early on if we could look up c++ references, string functions


3. reimplemented it after interview, without all the string manip fluff (core agorithm)
 it was a total of 20 lines function. 


Learnings
1. Don't jump staight into implementation
2. Ask early if very strict on c++ documentation lookups.
3. Mostly not, but be prepared. 







