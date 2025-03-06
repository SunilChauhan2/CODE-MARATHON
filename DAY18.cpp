/*Queation 1: Given a prefix expression, evaluate it using stack and print the final output.
Complete the evalPrefix() function and return the final output.
Input Format
The first line of input contains an integer T denoting the number of test cases. The next T lines contain a prefix expression.
An expression in prefix form will consist of all digits and following five operators: +, -, *, /, ^
Output Format
Print the final output of prefix expression evaluation in new line for each test case.
Sample Input
1
+-*235/^234
Sample Output
3 */
int evalPrefix(char* exp)
{
    stack<int> st;
    int len = strlen(exp);
    
    
    for (int i = len - 1; i >= 0; i--) {
        
        if (isdigit(exp[i])) {
            st.push(exp[i] - '0'); 
        } 
       
        else {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            
            switch (exp[i]) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }
    return st.top(); 
}
