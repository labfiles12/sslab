#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char input[16], stack[15];
void check()
{
    for (z = 0; z < c; z++)
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')')
        {
            stack[z] = 'F';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\tREDUCE by F->(E)", stack, input);
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stack[z] == 'i' && stack[z + 1] == 'd')
        {
            stack[z] = 'F';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\tREDUCE by F->id", stack, input);
            j++;
        }
    for (z = 0; z < c; z++)
    {
        if (stack[z] == 'T' && stack[z + 1] == '*' && stack[z + 2] == 'F')
        {
            stack[z] = 'T';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\tREDUCE by T->T*F", stack, input);
            i = i - 2;
        }
        else if (stack[z] == 'F')
        {
            stack[z] = 'T';
            printf("\n$%s\t%s$\tREDUCE by T->F", stack, input);
        }
    }
    for (z = 0; z < c; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'T' && stack[z + 3] == '*')
            break;
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'T')
            if (input[j + 1] == '*')
                break;
            else
            {
                stack[z] = 'E';
                stack[z + 1] = '\0';
                printf("\n$%s\t%s$\tREDUCE by E->E+T", stack, input);
                i = i - 2;
            }
        else if (stack[z] == 'T')
        {
            if (stack[z + 1] == '*' || input[j + 1] == '*')
                break;
            stack[z] = 'E';
            printf("\n$%s\t%s$\tREDUCE by E->T", stack, input);
        }
    }
}
void main()
{
    printf("Grammar: \n E->E+T|T \n T->T*F|F \n F->(E)|id\n");
    printf("Enter the input string\n");
    scanf("%s", input);
    c = strlen(input);
    printf("Stack \t Input \t\t Action\n");
    printf("$\t %s$", input); // Initial contents of the input buffer
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        if (input[j] == 'i' && input[j + 1] == 'd')
        {
            stack[i] = input[j];
            stack[i + 1] = input[j + 1];
            stack[i + 2] = '\0'; /*input till here*/
            input[j] = ' ';
            input[j + 1] = ' ';
            printf("\n$%s\t%s$\tSHIFT-> id", stack, input);
            check();
        }
        else
        {
            stack[i] = input[j];
            stack[i + 1] = '\0';
            input[j] = ' ';
            printf("\n$%s\t%s$\tSHIFT-> symbol", stack, input);
            check();
        }
    }
    printf("\n");
    getchar();
}
