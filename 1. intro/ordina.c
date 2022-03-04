#include <stdio.h>
#define MAX 40
int input_array(int a[])
{
    int val, i;
    printf("inserisci gli elementi (-1 per terminare):\n");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        a[i] = val;
    }
    return i;
}
int minimo(int a[], int pmin, int n)
{
    int min = a[pmin];
    for (int j = pmin+1; j < n; j++)
    {
        if (a[j] < min)
        {
            min = a[j];
            pmin = j;
        }
    }
    return pmin;
}
void scambia(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ordina_array(int a[], int n)
{
    int i, p;
    for (i = 0; i < n-1; i++)
    {
        p = minimo(a, i, n);
        scambia(&a[i], &a[p]);
    }
}
void output_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(void)
{
    int a[MAX], n;
    n = input_array(a);
    ordina_array(a, n);
    output_array(a, n);
    return 0;
}