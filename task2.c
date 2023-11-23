#include <stdio.h>

#define NMAX 100
int main() {
  float k[NMAX];
  char o[NMAX];
  int num_elemente = 0;
  scanf("%d", &num_elemente);

  for (int i = 0; i < num_elemente; i++)
    scanf("%f", &k[i]);

  for (int i = 0; i < num_elemente; i++)
    scanf("%c", &o[i]);

  for (int i = 0; i < num_elemente - 1; i++) {
    o[i] = o[i + 1];
    o[i + 1] = 0;
  }

  for (int i = 0; i < num_elemente - 1; i++) {
    if (o[i] == '*' || o[i] == '/') {
      k[i] = (o[i] == '*' ? k[i] * k[i + 1] : k[i] / k[i + 1]);
      for (int j = i + 1; j < num_elemente - 1; j++) {
        k[j] = k[j + 1];
        k[j + 1] = 0;
      }
      for (int j = i; j < num_elemente - 1; j++) {
        o[j] = o[j + 1];
        o[j + 1] = 0;
      }
      i--;
    }
  }

  for (int i = 0; i < num_elemente - 1; i++) {
    if (o[i] == '+' || o[i] == '-') {
      k[i] = (o[i] == '+' ? k[i] + k[i + 1] : k[i] - k[i + 1]);
      for (int j = i + 1; j < num_elemente - 1; j++) {
        k[j] = k[j + 1];
        k[j + 1] = 0;
      }
      for (int j = i; j < num_elemente - 1; j++) {
        o[j] = o[j + 1];
        o[j + 1] = 0;
      }
      i--;
    }
  }

  printf("%f\n", k[0]);
  return 0;
}
