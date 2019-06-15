#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


void swap(int *pa, int *pb){
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
  int s;
  int area[n];
  for (int i = 0; i < n;++i)  {
    s = (tr[i].a + tr[i].b + tr[i].c) / 2;
    area[i] = pow(s * (s - tr[i].a) * (s - tr[i].b) * (s - tr[i].c), 0.5);
  }
  for (int i = 0; i < n;++i)  {
    for (int j = 0; j < n - i;++j) {
      if (area[j] > area[j+1])
      {
        swap(&area[j], &area[j + 1]);
        swap(&tr[j], &tr[j + 1]);
      }
    }
  }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
