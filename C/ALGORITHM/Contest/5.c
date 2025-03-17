#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, x, y, d;
        scanf("%lld %lld %lld %lld", &n, &x, &y, &d);


        if (abs(y - x) % d == 0) {
            printf("%lld\n", abs(y - x) / d);
        } else {

            printf("-1\n");
        }
    }

    return 0;
}
