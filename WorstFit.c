#include<stdio.h>
#define max 35
void main()
{
    int nb, nf, i, j, b[max], f[max], temp, highest =0, frag[max];
    static bf[max], ff[max];
    printf("Enter the number of block: ");
    scanf("%d", &nb);
    printf("Enter the number of file: ");
    scanf("%d", &nf);
    printf("Enter the size of blocks: \n");
    for(i=1; i<=nb; i++)
    {
        printf("Block no %d: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of files: \n");
    for(i=1; i<=nf; i++)
    {
        printf("File no %d: ", i);
        scanf("%d", &f[i]);
    }
    for(i=1; i<=nf; i++)
    {
        for(j=1; j<=nb; j++)
        {
            if(bf[j] != 1)
            {
                temp = b[j] - f[i];
                if(temp >= 0)
                    if(highest< temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment");
    for(i=1; i<=nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
