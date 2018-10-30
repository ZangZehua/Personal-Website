#include "stdio.h"

#define MaxSize 20
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack * S)
{
    S->top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack * S, int x)
{
    if (S->top == MaxSize - 1)
    {
        return false;
    }
    else
    {
        S->top++;
        S->data[S->top] = x;
        return true;
    }
}

bool Pop(SqStack * S, int * x)
{
    if (S->top == -1)
    {
        return false;
    }
    else
    {
        *x = S->data[S->top];
        S->top--;
        return true;
    }

}

bool GetTop(SqStack * S, int * x)
{
    if (S->top == -1)
    {
        return false;
    }
    else
    {
        *x = S->data[S->top];
        return true;
    }
}

int main()
{
    char inputString[MaxSize];
    printf("please input the expression: \n");
    scanf("%s", inputString);
    printf("the input expression is: %s\n", inputString);
    SqStack * sqStack;
    InitStack(sqStack);
    int operator_1, operator_2, operator_result;
    int temp;
    for (int inputPointer = 0; inputPointer < MaxSize || inputString[inputPointer] != '\0'; inputPointer++) {
        printf("char: %c\n", inputString[inputPointer]);
        if (inputString[inputPointer] >= '0' && inputString[inputPointer] <= '9')
        {
            temp = inputString[inputPointer] - '0';
            Push(sqStack, temp);
            printf("pushed\n");
        } else if (inputString[inputPointer] == '+') {
            Pop(sqStack, &operator_2);
            Pop(sqStack, &operator_1);
            operator_result = operator_1 + operator_2;
            printf("+: %d + %d = %d\n", operator_1, operator_2, operator_result);
            Push(sqStack, operator_result);
        }else if (inputString[inputPointer] == '-') {
            Pop(sqStack, &operator_2);
            Pop(sqStack, &operator_1);
            operator_result = operator_1 - operator_2;
            printf("-: %d - %d = %d\n", operator_1, operator_2, operator_result);
            Push(sqStack, operator_result);
        }else if (inputString[inputPointer] == '*') {
            Pop(sqStack, &operator_2);
            Pop(sqStack, &operator_1);
            operator_2 -= '0';
            operator_1 -= '0';
            operator_result = operator_1 * operator_2;
            printf("*: %d * %d = %d\n", operator_1, operator_2, operator_result);
            Push(sqStack, operator_result);
        }else if (inputString[inputPointer] == '/') {
            Pop(sqStack, &operator_2);
            Pop(sqStack, &operator_1);
            operator_2 -= '0';
            operator_1 -= '0';
            if (operator_2 == 0)
            {
                printf("0 error\n");
                return 0;
            }
            operator_result = operator_1 + operator_2;
            printf("/: %d / %d = %d\n", operator_1, operator_2, operator_result);
            Push(sqStack, operator_result);
        }
    }
    GetTop(sqStack, &operator_result);
    printf("the result is: %d\n", operator_result);
}