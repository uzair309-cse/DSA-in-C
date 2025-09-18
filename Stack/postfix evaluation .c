// Postfix evaluation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int e_postfix(char *postfix){
int stack[MAX];
int top = -1;
int i , op1 , op2 , result;

for(i=0;i<strlen(postfix);i++){

    //check if the character is a digit
    if(postfix[i] >= '0' && postfix[i] <= '9'){
        
        //push the digits onto the stack
        stack[++top] = postfix[i] - '0';
    }else
    {
        //pop two operands from the stack
        op2 = stack[top--];
        op1 = stack[top--];

        switch(postfix[i]){

            case '+':
            result = op1 + op2;
            break;
            case '-':
            result = op1 - op2;
            break;
            case '*':
            result = op1 * op2;
            break;
            case '/':
            result = op1 / op2;
            break;
        }

        //push the result onto the stack
        stack[++top] = result;
    }

}
return stack[top];
}

int main(){
    char postfix[MAX];

    printf("Enter the postfix expression:");
    scanf("%s",postfix);

    int result = e_postfix(postfix);

    printf("Result:%d\n",result);

    return 0;
}
