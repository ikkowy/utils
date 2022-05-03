#include <assert.h>
#include <stdlib.h>

#include "../bitswap.h"

int main() {
    assert(bswap16(0xaabb) == 0xbbaa);
    assert(bswap32(0xaabbccdd) == 0xddccbbaa);
    assert(bswap64(0x1122334455667788ull) == 0x8877665544332211ull);
    return EXIT_SUCCESS;
}
