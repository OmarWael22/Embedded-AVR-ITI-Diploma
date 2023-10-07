#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int bitwiseAnd(int a, int b);
int bitwiseOr(int a, int b);
int bitwiseNot(int a);
int bitwiseXor(int a, int b);
int remaind(int a, int b);
int increment(int a);
int decrement(int a);

void main(void) {
    int id, op1, op2, result;

   

    printf("Enter the operation ID : ");
    scanf("%d", &id);

    if ((id >= 1 && id <= 9) && (id != 7)) {
        printf("Enter operand 1: ");
        scanf("%d", &op1);
        
        printf("Enter operand 2: ");
        scanf("%d", &op2);
    } else if (id == 7 || id == 10 || id == 11) {
        printf("Enter one operand: ");
        scanf("%d", &op1);
    } else {
        printf("Invalid operation ID. Please enter a valid number from 1 to 11.\n");
      
    }

    switch (id) {
    case 1:
        result = add(op1, op2);
        break;
    case 2:
        result = subtract(op1, op2);
        break;
    case 3:
        result = multiply(op1, op2);
        break;
    case 4:
        result = divide(op1, op2);
        break;
    case 5:
        result = bitwiseAnd(op1, op2);
        break;
    case 6:
        result = bitwiseOr(op1, op2);
        break;
    case 7:
        result = bitwiseNot(op1);
        break;
    case 8:
        result = bitwiseXor(op1, op2);
        break;
    case 9:
        result = remaind(op1, op2);
        break;
    case 10:
        result = increment(op1);
        break;
    case 11:
        result = decrement(op1);
        break;
    
    }

    printf("Result: %d\n", result);

}
// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseNot(int a) {
    return ~a;
}

int bitwiseXor(int a, int b) {
    return a ^ b;
}

int remaind(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int increment(int a) {
    return a + 1;
}

int decrement(int a) {
    return a - 1;
}



