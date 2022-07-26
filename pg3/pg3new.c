#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char input[10], stack[25];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
void pop()
{
    top = top - 1;
}

void main()
{
    int i = 0;
    printf("first(A)={a}\t");
    printf("follow(A)={$}\n");
    printf("first(B)={b,@}\t");
    printf("follow(B)={a}\n\n");
    printf("\t a \t b \t $ \n");
    printf("A\tA->aBa\n");
    printf("B\tB->@\tB->bB\n");
    printf("Enter the Input String terminated with $ to parse\n");
    scanf("%s", input); // Invalid String (not a,b or $) (Skipped) & End of string $ (Skipped)
    push('$');
    push('A');
    printf("Stack\tInput\tAction");
    while (i != strlen(input) && stack[top] != '$')
    {
        printf("\n");
        for (int l = top; l >= 0; l--)
            printf("%c", stack[l]);
        printf("\t");
        for (int l = i; l < strlen(input); l++)
            printf("%c", input[l]);
        printf("\t");
        if (stack[top] == 'A')
        {
            printf("A->aBa");
            pop();
            push('a');
            push('B');
            push('a');
        }
        else if (stack[top] == 'B')
        {
            if (input[i] != 'b')
            {
                printf("B->@");
                pop();
            }
            else
            {
                printf("B->bB");
                pop();
                push('B');
                push('b');
            }
        }
        else
        {
            if (stack[top] == input[i])
            {
                printf("Matched %c", input[i]);
                pop();
                i++;
            }
            else
                break;
        }
    }
    if (stack[top] == '$' && input[i] == '$')
    {
        printf("\n$\t$");
        printf("\nValid String Accepted\n");
    }
    else
        printf("\nInvalid String Rejected\n");
}
