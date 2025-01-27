/*
  The C* port of invert_string-3.c from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  termination : true
  unreach-call: false
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

void VERIFIER_assert(uint64_t cond) {
  if (cond == 0) {
    VERIFIER_error();
  }
  return;
}

uint64_t SIZEOFUINT64 = 8;

uint64_t main() {
  uint64_t  MAX;
  uint64_t  i;
  uint64_t  j;
  uint64_t* str1;
  uint64_t* str2;

  MAX = 1000;

  str1 = malloc(MAX * SIZEOFUINT64);
  str2 = malloc(MAX * SIZEOFUINT64);

  i = 0;
  while (i < MAX) {
    interval(str1 + i, 0, MAX-i, 1);
    i = i + 1;
  }
  *(str1 + (MAX-1)) = 0;

  j = 0;
  i = MAX;
  while (i > 0) {
    *(str2 + j) = *(str1 + (i-1));

    i = i - 1;
    j = j + 1;
  }

  j = 0;
  while (j < MAX) {
    VERIFIER_assert(*(str2 + j) != MAX);
    j = j + 1;
  }

  return 0;
}