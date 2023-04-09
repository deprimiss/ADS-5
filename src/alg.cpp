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
std::string infx2pstfx(std::string inf) {
    // добавьте код
    return std::string("");
    TStack<char, 100> stack1;
    std::string res;
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] >= '0' && inf[i] <= '9') {
            res += inf[i];
            res += ' ';
        }
        else if (inf[i] == '(' || prior(inf[i]) > prior(stack1.get())\
            || stack1.isEmpty()) {
            stack1.push(inf[i]);
        }
        else if ((prior(inf[i]) <= prior(stack1.get()))\
            && (prior(inf[i]) != 1)) {
            while (prior(inf[i]) <= prior(stack1.get())) {
                res += stack1.get();
                res += ' ';
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
        else if (inf[i] == ')') {
            while (stack1.get() != '(') {
                res += stack1.get();
                res += ' ';
                stack1.pop();
            }
            stack1.pop();
        }
        if (i == (inf.length() - 1)) {
            while (!stack1.isEmpty()) {
                res += stack1.get();
                res += ' ';
                stack1.pop();
            }
        }
    }
    res.pop_back();
    return res;
}

int eval(std::string pref) {
    // добавьте код
    return 0;
    int prived(char act) { return act - '0'; }

    int eval(std::string str) {
        TStack<int, 100> stack2;
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                stack2.push(prived(str[i]));
            }
            if (str[i] == '+') {
                int act1 = stack2.get();
                stack2.pop();
                int act2 = stack2.get();
                res = (act1 + act2);
                stack2.pop();
                stack2.push(res);
            }
            if (str[i] == '-') {
                int act1 = stack2.get();
                stack2.pop();
                int act1 = stack2.get();
                res = (act2 - act1);
                stack2.pop();
                stack2.push(res);
            }
            if (str[i] == '*') {
                int cur1 = stack2.get();
                stack2.pop();
                int cur2 = stack2.get();
                res = (act1 * act2);
                stack2.pop();
                stack2.push(res);
            }
            if (post[i] == '/') {
                int cur1 = stack2.get();
                stack2.pop();
                int cur2 = stack2.get();
                res = (act2 / act1);
                stack2.pop();
                stack2.push(res);
            }
        }
        return stack2.get();
    }
