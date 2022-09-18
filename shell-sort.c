/* shell-sort.c - Сортировка Шелла */

#include <stdio.h>
#include <stdlib.h>

static void shell_sort(int a[], int size) {
  int i, j;
  int h = 1;

  do {
    h = h * 3 + 1;
  } while (h <= size);

  do {
    h /= 3;
    for (i = h; i < size; i++) {
      int v = a[i];
      for (j = i; j >= h && a[j - h] > v; j -= h) {
        a[j] = a[j - h];
      }
      if (i != j) {
        a[j] = v;
      }
    }
  } while (h != 1);
}

int main(int argc, char *argv[]) {
  int i;

  int size = argc - 1;
  int a[size];
  for (i = 0; i < size; i++) {
    a[i] = atoi(argv[i + 1]);
  }
  shell_sort(a, size);
  printf("Output: ");
  for (i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("N\n");
  return 0;
}
