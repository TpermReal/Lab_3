
#include<stdio.h>
#include<stdlib.h>
#include <cstring>

#define maxsize 100

int flag = 0;
char temp;

//定义顺序表结构
typedef struct {
    char s[maxsize];
    int length;
}SeqList;

//定义堆栈
typedef struct {
    int top;
    char elem[maxsize];
}Stack;

//初始化顺序表
void initList(SeqList& L) {
    L.length = 0;
}

//初始化堆栈
void initStack(Stack& S) {
    S.top = -1;
}

//输入创建顺序表
void createList(SeqList& L) {
    scanf("%s",&L.s);
    L.length = strlen(L.s);
}

//入栈
bool push(Stack &S,char ch) {
    if (S.top == maxsize - 1) {
        return false;
    }
    S.top++;
    S.elem[S.top] = ch;
    return true;
}

//出栈
bool pop(Stack &S, char &ch) {
    if (S.top == -1) {
        return false;
    }
    ch = S.elem[S.top];
    S.top--;
    return true;
}

bool isEmpty(Stack S){
    return S.top == -1;
}
//获取栈顶元素
char topElem(Stack S) {
    return S.elem[S.top];
}
//括号匹配函数
void matchBracket(Stack& S, char Lbracket) {
    while (S.elem[S.top] != Lbracket) {
        pop(S, temp);
    }
    pop(S, temp);
    flag--;
}

//检测算法
bool checkExp(SeqList L, Stack S) {
    int i = 0;
    int count = L.length;
    //char temp;int flag = 0;
    while (count--) {
        if (L.s[i] >= '0' && L.s[i] <= '9') {//当前是数字
            i++;
            continue;
        }
        else {//当前是符号，包括运算符、左括号和右括号
            if (L.s[i] == '(' || L.s[i] == '[' || L.s[i] == '{') {
                push(S, L.s[i]);
                flag++;
            }
            else if(L.s[i] =='+' || L.s[i]=='-' || L.s[i] == '*' || L.s[i] == '/'){
                char top = topElem(S);
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    pop(S, temp);
                }
                else {
                    push(S, L.s[i]);
                }
            }
            else if(L.s[i] == ')' || L.s[i] == ']' || L.s[i] == '}'){//当前是右括号
                if (flag > 0) {
                    if (L.s[i] == ')') {
                        matchBracket(S, '(');
                    }
                    else if (L.s[i] == ']') {
                        matchBracket(S, '[');
                    }
                    else {
                        matchBracket(S, '{');
                    }
                }
                else {
                    return false;
                }
            }
            else {
                printf("输入的字符有误！");
                return false;
            }
        }
        i++;
    }
    if (isEmpty(S)) {
        return true;
    }
    else {
        char top = topElem(S);
        if (top == '+' || top == '-' || top == '*' || top == '/') {
            return true;
        }
        else {//栈顶是左括号
            return false;
        }
    }
}
//flag记录栈内含有左括号的个数，当flag为0但当前扫描到的字符为右括号，则匹配错误
int main() {
    SeqList l;
    Stack s;
    initList(l);
    initStack(s);
    createList(l);

    if (checkExp(l, s)) {
        printf("yes!");
    }
    else {
        printf("no!");
    }

}
 