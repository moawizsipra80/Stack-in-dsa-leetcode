#include "stack.h"
#include <iostream>
#include<vector>
using namespace std;

int size;

void checkplaindrome(string plaindrome, stack<char> &h)
{
    size = plaindrome.length();
    string fix = "";

    for (int i = size-1; i >= 0; i--)
    {
        char ch = plaindrome[i];
        if (isalpha(ch)||isdigit(ch))
        {
            h.push(ch);
        }
    }

    while (!h.isEmpty() )
    {
        fix += h.stacktop();
    }

    string read = std::string(1, h.stacktop());
    if (fix == read)
    {
        cout << "yes it is  a plaindrom" << endl;
    }
    else{
        cout << "no it is a not aplaindrome" << endl;
    }
        }


int count = 0;
int count2 = 0;
void checkformofstring(string form)
{
    int size2 = form.length();

    int mid = size / 2;

    stack<char> p(size);
    stack<char> p2(size);
for(int i=0;i<size2;i++)
{

    p.push(form[i]);
}
    for (int i = 0; i < mid; i++)
    {
        if(form[i]=='a')
        {
        p2.push(form[i]);
       
   }
   else{
    cout<<"not from anbn"<<endl;
   }
}
for(int i=mid;i>size;i--)
{
   if(form[i]=='b')
   {
    if(!p2.isEmpty()){
        cout<<"not from formula"<<endl;
        return;
    }
    p.pop();
   }
   else{
    cout<<"not from anbn"<<endl;
return;
}
     if (p2.isEmpty())
        cout << "Yes, it is of the form anbn" << endl;
    else
        cout << "Not of form anbn" << endl;

 }
}
char top,c;
void isValid(string exp)
{
    int size3=exp.length();
        stack<char>p3(size3);
 for(int i=0;i<size3;i++){
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
    {
          c=exp[i];
        p3.push(c);
    }
    else if(exp[i]==')' || exp[i]=='}'|| exp[i]==']')
    {
        if(p3.isEmpty()){
            cout<<"BAD"<<endl;
            return;
        }
        top=p3.stacktop();
        p3.pop();
    }
    if((exp[i]=='('&& top!=')' )||
        (exp[i]=='{' && top!='}')||
        (exp[i]=='[' && top!=']'))
        {
cout<<"BAD"<<endl;
        }
        
 }
if(p3.isEmpty()){
    cout<<"GOOD"<<endl;
}
else{
    cout<<"BAD"<<endl;
}
}
int carry=0;
void  addingtwoverylargenumbers(string numbers,string n2)
{
    int size4=numbers.length();
    int  size5=n2.length();
    stack<int>s1(size4);
    stack<int>s2(size5);
   stack<int> cal(size4+size5);
   int carry=0; 
   for (int i = 0; i < size4; i++)
    {
        s1.push(numbers[i]-'0');
       
    }
     for(int j=0;j<size5;j++)
        {
        s2.push(n2[j]-'0');
        }

while(!s1.isEmpty()|| !s2.isEmpty())
{
    int d1=0;
    int d2=0;
    if(!s1.isEmpty()){
        d1=s1.stacktop();
        s1.pop();
    }
    if(!s2.isEmpty()){
        d2=s2.stacktop();
        s2.pop();
    }
    int sum=d1+d2;
    cal.push(sum);
    carry=sum/10;

}
if(carry>0)
cal.push(carry);

cout << "SUM = ";
while(!cal.isEmpty()){
  cout << cal.stacktop();
  cal.pop();
}
}
int main()
{
    string plaindrom;
    int size = plaindrom.length();
    stack<char> h(size);
    cout << "enter the string that you want to check" << endl;
    // cin >> plaindrom;
    getline(cin, plaindrom);
    checkplaindrome(plaindrom, h);

    // for functin 2
    string a;
    cout << "enter the string aaabbb" << endl;
    cin >> a;
    checkformofstring(a);
    //
    string expression;
    cout<<"enter the expression"<<endl;
    cin>>expression;
    isValid(expression);
    //
    string n1,n2;
    cout<<"enter the first numbers and secon large numbers"<<endl;
    cin>>n1>>n2;
    addingtwoverylargenumbers(n1,n2);
    return 0;
}