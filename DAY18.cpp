#include <iostream>
// #include <stack>
// #include <cmath>
// #include <cstring> 
// int evalPrefix(char* exp)
// {
//     stack<int> st;
//     int len = strlen(exp);
    
    
//     for (int i = len - 1; i >= 0; i--) {
        
//         if (isdigit(exp[i])) {
//             st.push(exp[i] - '0'); 
//         } 
       
//         else {
//             int op1 = st.top(); st.pop();
//             int op2 = st.top(); st.pop();
            
//             switch (exp[i]) {
//                 case '+': st.push(op1 + op2); break;
//                 case '-': st.push(op1 - op2); break;
//                 case '*': st.push(op1 * op2); break;
//                 case '/': st.push(op1 / op2); break;
//                 case '^': st.push(pow(op1, op2)); break;
//             }
//         }
//     }
//     return st.top(); 
// }
