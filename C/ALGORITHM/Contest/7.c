#include <stdio.h>

int main()
{
    int T;

    scanf("%d", &T);
    int caseNum;
    for (caseNum = 1; caseNum <= T; caseNum++)
    {
        int N;
        scanf("%d", &N);

        int min_speed = 0;
        int i;
        for (i = 0; i < N; i++)
        {
            int speed;
            scanf("%d", &speed);

            if (speed > min_speed)
            {
                min_speed = speed;
            }
        }

        printf("Case %d: %d\n", caseNum, min_speed);
    }

    return 0;
}
