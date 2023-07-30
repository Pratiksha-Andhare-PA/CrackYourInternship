class Solution {
public:

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }
    int applyOp(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow(a, b);
            default: return 0;
        }
    }

    int calculate(string s) {
        stack<int> values;
        stack<char> ops;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '(') {
                ops.push(s[i]);
            } else if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Move back one position to adjust for the loop increment
                values.push(num);
            } else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                if (!ops.empty())
                    ops.pop(); // Remove the opening parenthesis '('
            } else {
                while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(s[i]);
            }
        }

        while (!ops.empty()) {
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(val1, val2, op));
        }

        return values.top();   
    }
};
