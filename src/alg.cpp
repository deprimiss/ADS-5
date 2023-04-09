// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char n) {
    if (n == '(') return 0;
    if (n == ')') return 1;
    if (n == '+' || n == '-') return 2;
    if (n == '*' || n == '/') return 3;
    return -1;
}

int toInt(char c) {
    char nums[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++) {
        if (c == nums[i])
            return i;
    }
    return -1;
}

int l(std::string s) {
    int l = 0;
    char c = s[0];
    while (c != '\0')
        c = s[++l];
    return l;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string res;
    char temp;
    int i = 0;
    char c = inf[0];
    while (c != '\0') {
        if (c >= '0' && c <= '9') {
            res = res + c + " ";
        } else if (c == ')') {
            if (!stack1.isEmpty()) {
                temp = stack1.pop();
                while (temp != '(') {
                    res = res + temp + " ";
                    temp = stack1.pop();
                }
            }
        } else if ((stack1.isEmpty()) || c == '(' || prior(c) >\
                   prior(stack1.get())) {
            stack1.push(c);
        } else if ((!stack1.isEmpty()) && (prior(c) <= prior(stack1.get()))) {
            while ((!stack1.isEmpty()) && (prior(c) <= prior(stack1.get()))) {
                temp = stack1.pop();
                res = res + temp + " ";
            }
            stack1.push(c);
        }
        ++i;
        c = inf[i];
    }
    while (!stack1.isEmpty()) {
        temp = stack1.pop();
        if (stack1.isEmpty()) res = res + temp;
        else
            res = res + temp + " ";
    }
    return res;
}

int eval(std::string pref) {
    TStack <int, 100> stack2;
    char c = pref[0];
    int a, b, i = 0, count = l(pref);
    while (count) {
        if (c != ' ') {
            if ((c >= '0') && (c <= '9')) {
                stack2.push(toInt(c));
            } else if (!stack2.isEmpty()) {
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
