#include <stdio.h>
#include <string.h>
#define LEN 1000
int main()
{
    char sin[LEN] = {'\0'};
    char sout[LEN] = {'\0'};
    char *p;
    char swap[LEN];
    char a[LEN / 10][LEN];
    int k = -1, i, l, r;
    printf("Vvedite vhodnuu stroku: ");
    gets(sin);
    p = strtok(sin, "_");
    while(p != NULL)
    {
        k++;
        strcpy(a[k], p);
        p = strtok(NULL, "_");
    }
    printf("\n\nVvedite nomera slov dlya obmena(l <= r): ");
    scanf("%d %d", &l, &r);
    if(l > r)
    {
        printf("\n\nInput ERROR! Program close!");
        getch();
        return 1;
    }
    strcpy(swap, a[l - 1]);
    strcpy(a[l - 1], a[r - 1]);
    strcpy(a[r - 1], swap);
    for(i = 0; i < k; i++)
    {
        strcat(sout, a[i]);
        strcat(sout, "_");
    }
    strcat(sout, a[k]);
    printf("\n\nVihodnaya stroka: %s", sout);
    return 0;
}

