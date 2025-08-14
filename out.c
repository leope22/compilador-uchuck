#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int value;

int main() {
    int _t1;
    int _t2;
    int _t3;

    n = 1;
    value = 1;
L1:
    _t1 = n < 10;
    if (_t1) goto L2;
    goto L3;
L2:
    _t2 = value * n;
    value = _t2;
    printf("%i\n", value);
    _t3 = n + 1;
    n = _t3;
    goto L1;
L3:
    return 0;
}
