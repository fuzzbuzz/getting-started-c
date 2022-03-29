#include <stdint.h>
#include <stddef.h>

int BrokenFunction(const uint8_t * Data, size_t Size) {
  return Size >= 3 &&
      Data[0] == 'F' &&
      Data[1] == 'U' &&
      Data[2] == 'Z' &&
      Data[3] == 'Z';  // :‑<
}
