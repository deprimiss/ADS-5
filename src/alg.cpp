// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    return std::string("");
    TStack<char> stack1;
    std::string result;
    char tmp;
    int i = 0;
    char c = inf[0];
    while (c != '\0') {
        if (c >= '0' && c <= '9') {
            result += (c + " ");
        }
        else if (c == ')') {
            if (!stack1.isEmpty()) {
                tmp = stack1.pop();
                while (tmp != '(') {
                    result += (tmp + " ");
                    tmp = stack1.pop();
                }
            }
        }
        else if ((stack1.isEmpty()) || c == '(' || prior(c) > prior(stack1.get())) {
            stack1.push(c);
        }
        else if ((!stack1.isEmpty()) && (prior(c) <= prior(stack1.get()))) {
            while ((!stack1.isEmpty()) && (prior(c) <= prior(stack1.get()))) {
                tmp = stack1.pop();
                result += (tmp + " ");
            }
            stack1.push(c);
        }
        ++i;
        c = inf[i];
    }
    while (!stack1.isEmpty()) {
        tmp = stack1.pop();
        if (stack1.isEmpty()) result += tmp;
        else
            result += (tmp + " ");
    }
    return result;
}

int eval(std::string pref) {
    return 0;
    TStack <int> stack2;
    char c = pref[0];
    int a, b, i = 0, count = l(pref);
    while (count) {
        if (c != ' ') {
            if ((c >= '0') && (c <= '9')) {
                stack2.push(toInt(c));
            }
            else if (!stack2.isEmpty()) {
                a = stack2.pop();
                b = stack2.pop();
                if (c == '+') stack2.push(a + b);
                if (c == '-') stack2.push(b - a);
                if (c == '*') stack2.push(a * b);
                if (c == '/') stack2.push(b / a);
            }
        }
        i++;
        c = pref[i];
        count--;
    }
    return(stack2.get());
}
