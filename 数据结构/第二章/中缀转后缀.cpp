#include<stack>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
int pri (char c);//判断运算符优先级
string tran(char a[]);//中缀运算符转后缀运算符
 
int main()
{
    char str[100];
    cin.getline(str, 100);//读入中缀表达式
    string a=tran(str);
    cout << a << endl;
    return 0;
}
int pri(char c)
{
    if(c == '+' || c=='-')
        return 1;
    else if(c =='*' ||c=='/')
        return 2;
    else if(c=='(')
        return 0;
}
string tran(char a[])
{
    int i;
    char c;
    stack<char> st;//建立一个运算符堆栈
    stringstream ss;//定义字符串流类
    for(i=0;a[i];i++)
    {
        c=a[i];//为方便写
        if(c == '+' || c=='-'||c =='*' ||c=='/')
        {
            if((c == '+' || c=='-') && (i==0 || a[i-1]=='('))//判断正负号  ？-9+（+5*7）
            {
                ss << (c=='-' ? "-":"");
            }
            else
            {
                ss << " ";
                while(!st.empty() && pri(st.top()) >= pri(c)) //当算数优先级小于栈顶算算数符的t优先级
                {
                    ss<< st.top()<< " ";//拼接c栈顶运算符
                    st.pop();
                }
                st.push(c);
            }
        }
        else if(c =='(')//左括号无脑压入 
            st.push(c);
        else if(c == ')') //右括号 
        {
            while(st.top() != '(') //一直pop直到左括号 
            {
                ss<< " " << st.top();
                st.pop();
            }
			st.pop();
        }
        else
            ss<< c;//数字 直接输出 
    }
    while(!st.empty())
    {
        ss << " "<< st.top();
        st.pop();
    }
    return ss.str();
}

