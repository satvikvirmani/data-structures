#include <stdio.h>
#include <math.h>

#define MAX 100
#define ERROR -9999
#define INVALID_OPERATOR_ERROR -9998
#define INVALID_OPERATION_ERROR -9997

float evalPostfix(char[]);
float calc(float, float, char);

float push(float);
float pop();
float peek();

float stack[MAX];
int top = -1;

int main() {
    
    char e[] = "15. 11. 20. 4. /*+";
    
    printf("\n%0.2f", evalPostfix(e));
}

float push(float val){
    if(top < MAX-1){
        stack[++top] = val;
        return 1; //Operation Successfull
    }
    
    return 0; //Operation Unsuccessfull
}

float pop(){
    if(top > -1){
        return stack[top--]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}

float peek(){
    if(top > -1){
        return stack[top]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}

float calc(float a, float b, char op){
    // Returns the result of expression
    // Returns INVALID_OPERATOR_ERROR if invalid operator is encountered
    
    if(op == '+'){
        return a + b;
    }
    else if(op == '-'){
        return a - b;
    }
    else if(op == '*'){
        return a * b;
    }
    else if(op == '/'){
        return a / b;
    }
    else if(op == '^'){
        return 0;
    }
    else{
        return INVALID_OPERATOR_ERROR;
    }
}

float evalPostfix(char postfix[]){
    // Returns the result of the evaluation
    // Returns INVALID_OPERATOR_ERROR if invalid operator is encountered
    // Returns INVALID_OPERATION_ERROR if only one operand is there for evaluation
    
    int i = 0, j;
    float op_a, op_b, res, tempNum = 0.0, digit, multiplier = 0.1;
    
    while(postfix[i] != '\0'){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            j = i;
            while(postfix[j] >= '0' && postfix[j] <= '9'){
                digit = postfix[j] - '0';
                tempNum = tempNum * 10.0 + digit;
                j++;
            }
            if(postfix[j] == '.'){
                j++;
                
                while(postfix[j] >= '0' && postfix[j] <= '9'){
                    digit = postfix[j] - '0';
                    tempNum = tempNum + digit*multiplier;
                    multiplier = multiplier*0.1;
                    j++;
                }
                
                multiplier = 0.1;
            }
            push(tempNum);
            tempNum = 0;
            i = j;
        }
        else if(postfix[i] == ' '){
            i++;
        }
        else{
            op_b = pop();
            op_a = pop();
            if(op_a == ERROR || op_b == ERROR){
                return INVALID_OPERATION_ERROR;
            }
            res = calc(op_a, op_b, postfix[i]);
            if(res == INVALID_OPERATOR_ERROR){
                return INVALID_OPERATOR_ERROR;
            }
            push(res);
            i++;
        }
    }
    
    return pop();
}