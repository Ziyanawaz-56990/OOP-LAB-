#include <stdio.h>

int main()
{
    int n, i, key;
    int arr[100];
    int position = -1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
        printf("Element found at position %d\n", position + 1);
    else
        printf("Element not found\n");

    return 0;
}