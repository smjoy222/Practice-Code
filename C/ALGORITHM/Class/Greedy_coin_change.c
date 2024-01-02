#include <stdio.h>
void des(int a[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
int coin(int a[], int size, int s)
{
    int count = 0;
    int i,num_c;
    if (s > 0)
    {
        for (i = 0; i < size; i++)
        {
            if (a[i] <= s)
            {
                 num_c = s / a[i];
                s = s - (num_c * a[i]);
            }
        }
    }
    if (s != 0)
    {
        return -1;
    }
    else
    {
        return num_c;
    }
}
int main()
{
    int size;
    int s;
    printf("Enter the total ammount:");
    scanf("%d", &s);
    printf("Enter the number of coins:");
    scanf("%d", &size);
    int a[size];
    printf("Enter the avilable coins:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    des(a, size);
    int c = coin(a, size, s);
    printf("Minimum Coin:%d\n",c);
    return 0;
}