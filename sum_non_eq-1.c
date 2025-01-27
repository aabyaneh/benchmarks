/*
  The C* port of sum_non_eq-1.c from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  termination : true
  no-overflow : false
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

uint64_t sum(uint64_t n, uint64_t m) {
  if (n == 0) {
    return m;
  } else {
    return sum(n - 1, m + 1);
  }
}

uint64_t main() {
  uint64_t a;
  uint64_t b;
  uint64_t result;

  interval(&a, 0, -1, 1);
  interval(&b, 0, -1, 1);
  result = sum(a, b);

  if (result != a + b) {
    VERIFIER_error();
  }

  return 0;
}