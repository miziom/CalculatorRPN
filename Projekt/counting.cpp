/**
 * \file counting.cpp
 * \brief Plik implementacji modułu \a obliczeniowego
 *
 * Moduł \a counting zawiera funkcje niezbędne,
 * aby mozna bylo obliczyc wyrazenie skonwertowane do ONP
 *
 * \see conwerterparser.h
 */


#include "counting.h"
#include <string>
#include <math.h>
#include <sstream>
#include <stdlib.h>

bool ifOperator(std::string oper)
{
    if(oper.size()== 1)
        if(oper[0] == '+' || oper[0] == '-' || oper[0] == '*' || oper[0] == '/' || oper[0] == '^')
            return true;
    else return false;
}

std::string count(RPNQueue *elem)
{
    RPNStack *stack = NULL;
    while(elem->qrpnlist->head != NULL)
    {
        std::string operator1 = queuePopRPN(elem);
        if(ifOperator(operator1) == false)
        {
            stackPushRPN(stack,operator1);
        }
        if(ifOperator(operator1) == true)
        {
            std::string stack1 = stackPopRPN(stack);
            std::string stack2 = stackPopRPN(stack);
            double stack1Double = strtod(stack1.c_str(), NULL);
            double stack2Double = strtod(stack2.c_str(), NULL);
            if(operator1[0] == '+')
            {
                double result = stack2Double + stack1Double;
                std::string res = std::to_string(result);
                stackPushRPN(stack,res);
            }
            if(operator1[0] == '-')
            {
                double result = stack2Double - stack1Double;
                std::string res = std::to_string(result);
                stackPushRPN(stack,res);
            }
            if(operator1[0] == '*')
            {
                double result = stack2Double * stack1Double;
                std::string res = std::to_string(result);
                stackPushRPN(stack,res);
            }
            if(operator1[0] == '/')
            {
                double result = stack2Double / stack1Double;
                std::string res = std::to_string(result);
                stackPushRPN(stack,res);
            }
            if(operator1[0] == '^')
            {
                double result = pow(stack2Double, stack1Double);
                std::string res = std::to_string(result);
                stackPushRPN(stack,res);
            }
        }
    }
    return stack->srpnlist->head->data;
}
