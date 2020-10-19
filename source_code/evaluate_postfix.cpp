// Link bai tap: http://upcoder.hcmue.edu.vn/'index.php/3daa5a01c074b589ba9df29c405451b7/lvypJ''yRMoOMs!jMm0M_NKz.3p'moNe5@qlR'pxRfoLqs'vviBnt'C4:'@2~-K.68b!---h7di597hj9P738.ObNi'Rk:1?x~xj:1?K~lA:10!uEA:9

// Code tham khao

#include<iostream>
#include<stack>

using namespace std;

int main(){
    string s[100];
    int n = 0;
    while(cin >> s[n]){
			n++;
    }

    stack<int> opr;
    for (int i = 0 ; i < n ; i++){
        if (s[i] != "+" && s[i] != "-" && s[i] != "*"){ // Kiểm tra nếu là toán hạng
            opr.push(stoi(s[i]));
        }else{ // Nếu là toán tử
            int tmp = 0;
            int y = opr.top();
            opr.pop();
            int x = opr.top();
            opr.pop();
            // Lưu ý thứ tự phép tính khi lấy ra phần tử đầu đỉnh stack là y,
            // phần tử kế tiếp ở đỉnh là x, thực hiện phép tính (x opt y)
            if (s[i] == "+"){
                tmp = x+y;
                opr.push(tmp);
            }else if (s[i] == "-"){
                tmp = x-y;
                opr.push(tmp);
            }else{
                tmp = x*y;
                opr.push(tmp);
            }
        }
    }
    // Giá trị opr.top() sẽ là kết quả
    cout << opr.top();
}
