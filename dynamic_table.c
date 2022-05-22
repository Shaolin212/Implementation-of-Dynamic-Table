#include <stdio.h>
int *table,len;
void insert()
{
    int n;
    printf("Enter value: ");
    scanf("%d",&n);
    len++;
    if((table=(int*)realloc(table,len*sizeof(int)))==0){
        printf("Error");
    }
    table[len-1]=n;
}

void display()
{
    int x;
    for(x=0;x<len;x++)
    {
        printf(" %d\n",table[x]);
    }
}

int sum()
{
    int i,sum=0;
    for(i=0;i<len;i++)
    {
        sum += table[i];
    }
    return(sum);
}

int find(int n)
{
    int i;
    for(i=0;i<len;i++){
        if(table[i]==n)
        {
            return(i);
        }
    }
    return(-1);
}

int maximum()
{
    int i,max;
    max=table[0];
    for(i=1;i<len;i++)
    {
        if (table[i]>max)
        {
            max=table[i];
        }
    }
    return(max);
}

int minimum()
{
    int i,min;
    min=table[0];
    for(i=1;i<len;i++){
        if (table[i]<min)
        {
            min=table[i];
        }
    }
    return(min);
}

int reverse()
{
    int x,i,temp;
    printf("Elements in table: \n");
    for(x=0;x<len;x++){
        printf(" %d\n",table[x]);
    }
    for(i=0;i<x/2;i++){
        temp = table[i];
        table[i] = table[x-i-1];
        table[x-i-1] = temp;
    }
    printf("Reversing the order of the table: \n");
    for(i=0;i<x;i++){
        printf(" %d\n",table[i]);
    }
}

void sorting()
{
    int *ptr[len],*tmp,i,j;
    for(i=0;i<len;i++)
    {
        ptr[i]=&table[i];
    }
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(*ptr[j]<*ptr[i])
            {
                tmp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=tmp;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        printf("%d: %d\n",i+1,*ptr[i]);
    }
}

int remove_value(int n)
{
    int x;
    x=find(n);
    if(x==-1){
        return(-1);
    }
    else{
        table[x]=table[len-1];
        len--;
        table=(int*)realloc(table,len*sizeof(int));
        return(1);
    }
}

void destroy(int *d)
{
    if(d!=NULL)
    {
        free(d);
    }
}

int main()
{
    int out,choice,n;
    table=NULL;
    len=0;
    do
    {
        putchar('\n');
        printf("    Dynamic Table\n");
        printf("------------------------\n");
        printf(" 1: Insert a number\n");
        printf(" 2: Sum of the elements\n");
        printf(" 3: Find any number\n");
        printf(" 4: Print maximum number\n");
        printf(" 5: Print minimum number\n");
        printf(" 6: Sort the table\n");
        printf(" 7: Delete any number\n");
        printf(" 8: Reversing the order of the table\n");
        printf(" 9: Print the table\n");
        printf(" 0: Exit\n");
        printf("\n");

        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nInsert numbers to table:\n");
                printf("\n");
                insert();
                break;
            }
            case 2:
            {
                out=sum();
                printf("\nSum of all numbers is: %d\n",out);
                break;
            }
            case 3:
            {
                printf("\nEnter searching number: ");
                scanf("%d",&n);
                printf("The number is: %d",n);
                printf("\n");
                out=find(n);
                if(out==-1)
                {
                    printf("Not found the number in table\n");
                }
                else
                {
                    printf("Number is at position: %d\n",out+1);
                }
                break;
            }
            case 4:
            {
                out=maximum();
                printf("Maximum number is: %d\n",out);
                break;
            }
            case 5:
            {
                out=minimum(0,table);
                printf("Minimum number is: %d\n",out);
                break;
            }
            case 6:
            {
                printf("\nSorted table: \n");
                sorting();
                break;
            }
            case 7:
            {
                printf("\nGive number to delete: ");
                scanf("%d",&n);
                out=remove_value(n);
                if(out==1)
                {
                    printf("\nNumber %d has been deleted.\n",n);
                }
                else
                {
                    if(out==-1)
                    {
                        printf("\nNumber %d don't exist.\n",n);
                    }
                    else
                    {
                        printf("\nNumber did not deleted %d.\n",n);
                    }
                }
                break;
            }
            case 8:
            {
                reverse();
                break;

            }
            case 9:
            {
                printf("\nPrint Table:\n");
                display();
                break;
            }
        }
    }

    while(choice!=0);
    destroy(table);
    exit(0);
}

