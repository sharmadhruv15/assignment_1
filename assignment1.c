#include <stdio.h>
#include <string.h>

struct Pair {
  int first;
  int second;
};

struct Pair find_pair(int books[], int n, int m) {
  int seen[n];
  memset(seen, 0, sizeof(seen));

  struct Pair result = {-1, -1};  

  for (int i = 0; i < n; i++) {
    int diff = m - books[i];
    if (diff >= 0 && seen[diff] == 1) {
      result.first = books[i];
      result.second = diff;
      return result;
    }
    seen[books[i]] = 1;
  }

  return result;
}

int main() {
  int n;

  printf("Enter the number of books: ");
  scanf("%d", &n);

  int books[n];

  printf("Enter the prices of the books:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &books[i]);
  }

  int m;
  printf("Enter the target sum: ");
  scanf("%d", &m);
  
  struct Pair pair = find_pair(books, n, m);
  
  if (pair.first == -1) {
    printf("No pair found\n");
  } else {
    printf("Pair found: %d, %d\n", pair.first, pair.second);
  }

  return 0;
}
