# include<iostream>

using namespace std;
# define OK 1;//定义宏观变量
# define ERROR 0;
# define OVERFLOW -2
# define MASIZE 100//定义栈的最大容量
typedef struct {
    char *base;
    char *top;
    int stacksize;
} SqStack;

int InitStack(SqStack &S)//初始化栈
{
    S.base = new char[MASIZE];
    if (!S.base)exit(OVERFLOW);//查看栈是否初始化成功
    S.top = S.base;
    S.stacksize = MASIZE;
    return OK;
}

int Push(SqStack &S, char e)//元素入栈
{
    if (S.top - S.base == S.stacksize)return ERROR;
    *S.top++ = e;
    return OK;
}

int Pop(SqStack &S, char &e)//栈顶元素按顺序出栈
{

    e = *--S.top;
    cout << "字符元素为： " << e << endl;
    return e;
}

int main() {
    SqStack S1;
    if (InitStack(S1))

        cout << "栈初始化成功" << endl;
    cout << "请输入入栈元素的个数" << endl;
    int n;
    cin >> n;
    char c[100];//定义一个存放字符的数组
    cout << "请输入第一个字符" << endl;
    for (int i = 0; i < n; i++) {
        char e1;
        cin >> e1;
        c[i] = e1;
        if ((Push(S1, e1)) && c[i] != '\0')//去除字符串中的空格

        {
            //cout << "第" << i + 1 << "个元素入栈成功" << endl;

        } else {
            cout << "入栈失败" << endl;
        }
    }

    int b = 1;
    for (int i = 0; i < n; i++) {
        char e;
        if (Pop(S1, e) != c[i])//判断字符串是否为回文

            b = -1;

    }
    if (b == -1)
        cout << "不是回文串" << endl;
    else cout << "是回文串" << endl;

}