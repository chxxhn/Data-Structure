#include "Calculator.h"

char NUMBER[] =  {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber(char Cipher)
{
    int i = 0;

    for(i = 0; i < sizeof(NUMBER); i++) 
    {
        if(Cipher == NUMBER[i]) return 1;
    }

    return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
    unsigned int i = 0;

    for(i = 0; 0 != Expression[i]; i++)
    {
        Token[i] = Expression[i];
        if(IsNumber(Expression[i]) == 1) 
        {
            *TYPE = OPERAND;
            if(IsNumber(Expression[i+1]) != 1) break;
        }
        else
        {
            *TYPE = Expression[i];
            break;
        }
    }

    Token[++i] = '\0';
    return i;
}

int GetPriority(char Operator, int InStack)
{
    int priority = -1;

    switch(Operator)
    {
        case LEFT_PARENTHESIS:
            if(InStack) priority = 3;
            else priority = 0;
            break;
        case MULTIPLY:
        case DIVIDE:
            priority = 1;
            break;
        case PLUS:
        case MINUS:
            priority = 2;
            break;
    }
    return priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
    return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
    LinkedListStack* stack;
    char Token[32];
    int type = -1;
    unsigned int position = 0;
    unsigned int length = strlen(InfixExpression);

    LLS_CreateStack(&stack);

    while(position < length)
    {
        position += GetNextToken(&InfixExpression[position], Token, &type);

        if(type == OPERAND)
        {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if(type == RIGHT_PARENTHESIS) 
        {  
            while(!LLS_IsEmpty(stack))
            {
                Node* popped = LLS_Pop(stack);
                if(popped->Data[0] == LEFT_PARENTHESIS)
                {
                    LLS_DestroyNode(popped);
                    break;
                }
                else
                {
                    strcat(PostfixExpression, popped->Data);
                    LLS_DestroyNode(popped);
                }
            }
        }
        else
        {
            while(!LLS_IsEmpty(stack) && )
        }
    }
}