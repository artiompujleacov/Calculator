#include <stdio.h>

#define NMAX 100
int main() {
  float k[NMAX], rezultat = 0;
  char o[NMAX];
  const int limita_elem = 0,rang_sing = 1;
  const float zero = 0;
  int num_elemente = 0, i = 0;
  scanf("%d", &num_elemente);
  if (num_elemente <= limita_elem) {
    printf("%f\n", zero);
  } else if (num_elemente == rang_sing) {
    for (i = 1; i <= num_elemente; ++i) {
      scanf("%f", &k[i]);
    }
    for (i = 1; i <= num_elemente; ++i) {
      printf("%f\n", k[i]);
    }
  } else {
    for (i = 1; i <= num_elemente; ++i) {
      scanf("%f", &k[i]);
    }
    scanf("%s", o);
    for (i = 1; i <= num_elemente; i++) {
      if (i == 1) {
        switch (o[i - 1]) {
        case '+':
          rezultat = k[i] + k[i + 1];
          break;
        case '-':
          rezultat = k[i] - k[i + 1];
          break;
        case '*':
          rezultat = k[i] * k[i + 1];
          break;
        case '/':
          rezultat = k[i] / k[i + 1];
          break;
        }
      } else {
        switch (o[i - 1]) {
        case '+':
          rezultat = rezultat + k[i + 1];
          break;
        case '-':
          rezultat = rezultat - k[i + 1];
          break;
        case '*':
          rezultat = rezultat * k[i + 1];
          break;
        case '/':
          rezultat = rezultat / k[i + 1];
          break;
        }
      }
    }
    printf("%f\n", rezultat);
  }
  return 0;
}
