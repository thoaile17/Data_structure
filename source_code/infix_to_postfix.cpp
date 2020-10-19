#include<iostream>
#include<stack>

using namespace std;

int precedence(char c){
    // Kiểm tra thứ tự ưu tiên toán tử
    // Hoặc không phải toán tử trả về -1
    if (c == '^'){
        return 3;
    }
    if (c == '*' || c == '/'){
        return 2;
    }
    if (c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

string postfix(string s){
    stack<char> mystack;
    string res;
    for (int i = 0; i < s.size() ; i++){

        // Nếu là toán hạng, tùy theo từng bài mà điều kiện
        // sẽ khác nhau, ở đây ví dụ gồm [a..z], các toán tử và các dấu ngoặc
        if (s[i] >= 'a' && s[i] <= 'z'){
            res += s[i];
        }

        // Nếu là dấu mở ngoặc thì đẩy vào stack
        else if (s[i] == '('){
            mystack.push('(');
        }

        // Nếu là dấu đóng ngoặc thì in ra các phần tử trong stack
        // cho đến khi stack rỗng hoặc gặp dấu mở ngoặc
        else if (s[i] == ')'){
            while(!mystack.empty() && mystack.top() != '('){
                res += mystack.top();
                mystack.pop();
            }
            mystack.pop();
        }

        // Nếu là toán tử thì in ra các phần tử trong stack có thứ tự ưu tiên
        // lớn hơn hoặc bằng toán tử đang xét, sau cùng đẩy toán tử đang xét vào stack
        else{
            while (!mystack.empty() && precedence(mystack.top()) >= precedence(s[i])){
                res += mystack.top();
                mystack.pop();
            }
            mystack.push(s[i]);
        }
    }

    // Khi lặp lại các bước trên cuối cùng, in ra tất cả những gì còn lại trong stack
    while(!mystack.empty()){
        res += mystack.top();
        mystack.pop();
    }
    return res;
}

int main(){
    string s = "a+b*(c^d-e)^(f+g*h)-i";

    cout << postfix(s);
}
