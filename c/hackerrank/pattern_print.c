// https://www.hackerrank.com/challenges/printing-pattern-2/problem

/*
Print Pattern : 4

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

My Solution :
Find minimun of i, j index. Subract from max index to get sum.
Adjustment : For lower right half of grid, find min instead of max.

Alternate Solution:
Value to be subtracted from n, is least distance from borders of grid.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int sum = 0;
    int x = n*2 -1;
    int max = 0;
    int min = 0;
    for(int i = n*2 -1; i > 0; --i) {
        for(int j = n*2 -1; j > 0; --j) {
            sum = 0;
            max = i > j ? i : j;

            sum = sum + x-max;
            if (i + j < x+1) {
              min = i > j ? j : i;
              sum = min - 1;
            }

              printf("%d", n - sum);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}

