#include<stack>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
int pri (char c);//�ж���������ȼ�
string tran(char a[]);//��׺�����ת��׺�����
 
int main()
{
    char str[100];
    cin.getline(str, 100);//������׺���ʽ
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
    stack<char> st;//����һ���������ջ
    stringstream ss;//�����ַ�������
    for(i=0;a[i];i++)
    {
        c=a[i];//Ϊ����д
        if(c == '+' || c=='-'||c =='*' ||c=='/')
        {
            if((c == '+' || c=='-') && (i==0 || a[i-1]=='('))//�ж�������  ��-9+��+5*7��
            {
                ss << (c=='-' ? "-":"");
            }
            else
            {
                ss << " ";
                while(!st.empty() && pri(st.top()) >= pri(c)) //���������ȼ�С��ջ������������t���ȼ�
                {
                    ss<< st.top()<< " ";//ƴ��cջ�������
                    st.pop();
                }
                st.push(c);
            }
        }
        else if(c =='(')//����������ѹ�� 
            st.push(c);
        else if(c == ')') //������ 
        {
            while(st.top() != '(') //һֱpopֱ�������� 
            {
                ss<< " " << st.top();
                st.pop();
            }
			st.pop();
        }
        else
            ss<< c;//���� ֱ����� 
    }
    while(!st.empty())
    {
        ss << " "<< st.top();
        st.pop();
    }
    return ss.str();
}

