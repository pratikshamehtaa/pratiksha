#include <stdio.h>
#include <string.h>

#define MAX 10

int top=-1;
int stk[MAX];
void push(char);
char pop();

int main()
{
    char exp[MAX],temp;
    int i, flag=1;

    printf("Enter expression:\n");
    fgets(exp,MAX,stdin);

    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' ||exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
        }

        if(exp[i]==')' ||exp[i]==']' || exp[i]=='}')
            if (top==-1)
                flag=0;
            
            else
            {   
                temp= pop();
                if(temp=='(' && (exp[i]=='}' ||exp[i]==']' ))
                    flag=0;

                if(temp=='{' && (exp[i]==')' ||exp[i]==']' ))
                    flag=0;

                if(temp=='[' && (exp[i]=='}' ||exp[i]==')' ))
                    flag=0;
            }
    }

    if(top>=0)
        flag=0;
    
    if(flag==0)
        printf("\nInvalid expression ");

    if(flag==1)
        printf("\nValid expression ");

    return 0;
}


void push(char c)
{
    if(top==MAX-1)
    {
        printf("Stack overflow");
    }

    else{
        top++;
        stk[top]=c;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }

    else{
        top--;
        return stk[top];

    }
}
