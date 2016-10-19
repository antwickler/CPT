#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50

int stack[MAX];
char postfix[MAX];
int top = -1;

void push(int tmp);
void cal(char c);

int main(){
    int i;
    printf("Enter a postfix: ");
    gets(postfix);
    for(i = 0; i < strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            push(i);
        }
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
            cal(postfix[i]);
        }
    }
    printf("Result = %d\n", stack[top]);
    return 0;
}
void push(int tmp){
    top++;
    stack[top] = (int)(postfix[tmp] - 48);
}
void cal(char c){
    int a, b, ans;
    a = stack[top];
    stack[top] = '\0';
    top--;
    b = stack[top];
    stack[top] = '\0';
    top--;
    switch(c){
        case '+': ans = b + a;
        break;
        case '-': ans = b - a;
        break;
        case '*': ans = b * a;
        break;
        case '/': ans = b / a;
        break;
        case '^': ans = b ^ a;
        break;
        default: ans = 0;
    }
    top++;
    stack[top] = ans;
}
