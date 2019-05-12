// https://www.hackerrank.com/challenges/permutations-of-strings/problem

/*
Algorithm :
Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
Find the largest index l greater than k such that a[k] < a[l].
Swap the value of a[k] with that of a[l].
Reverse the sequence from a[k + 1] up to and including the final element a[n].

For example, given the sequence [1, 2, 3, 4] (which is in increasing order), and given that the index is zero-based, the steps are as follows:
Index k = 2, because 3 is placed at an index that satisfies condition of being the largest index that is still less than a[k + 1] which is 4.
Index l = 3, because 4 is the only value in the sequence that is greater than 3 in order to satisfy the condition a[k] < a[l].
The values of a[2] and a[3] are swapped to form the new sequence [1,2,4,3].
The sequence after k-index a[2] to the final element is reversed. Because only one value lies after this index (the 3), the sequence remains unchanged in this instance. Thus the lexicographic successor of the initial state is permuted: [1,2,4,3].

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
  /**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
  int i = n - 1;
  while (i > 0 && strcmp(s[i - 1], s[i]) >= 0)
    i--; // find key
  if (i <= 0)
    return 0;
  int j = n - 1;
  while (strcmp(s[i - 1], s[j]) >= 0)
    --j;
  char *temp = s[i - 1];
  s[i - 1] = s[j];
  s[j] = temp;

  j = n - 1;
  while (i < j)
  {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    --j;
    ++i;
  }
  return 1;
}

int main()
{
  char **s;
  int n;
  scanf("%d", &n);
  s = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++)
  {
    s[i] = calloc(11, sizeof(char));
    scanf("%s", s[i]);
  }
  do
  {
    for (int i = 0; i < n; i++)
      printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
  } while (next_permutation(n, s));
  for (int i = 0; i < n; i++)
    free(s[i]);
  free(s);
  return 0;
}
