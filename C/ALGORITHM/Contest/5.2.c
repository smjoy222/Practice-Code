#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, x, y, d;
        scanf("%lld %lld %lld %lld", &n, &x, &y, &d);

        long long steps = 0;

        if (abs(y - x) % d == 0) {
            steps = abs(y - x) / d;
        } else {

            long long forward_steps = -1;
            if ((y - 1) % d == 0) {
                forward_steps = (x - 1) / d;
                if ((x - 1) % d != 0) forward_steps++;
                forward_steps += (y - 1) / d;
            }


            long long backward_steps = -1;
            if ((n - y) % d == 0) {
                backward_steps = (n - x) / d;
                if ((n - x) % d != 0) backward_steps++;
                backward_steps += (n - y) / d;
            }

            if (forward_steps == -1 && backward_steps == -1) {
                printf("-1\n");
            } else if (forward_steps == -1) {
                steps = backward_steps;
            } else if (backward_steps == -1) {
                steps = forward_steps;
            } else {
                steps = forward_steps < backward_steps ? forward_steps : backward_steps;
            }
        }

        printf("%lld\n", steps);
    }

    return 0;
}
