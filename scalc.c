/*
Program to implement a scientific calculator
 ***************************************************************
* Author Dept . Date . Notes
* ***************************************************************
* Micaela Graiver Comp. Science . Oct 1 2020 Error handling.
* Micaela Graiver Comp. Science . Nov 2 2020 Initial version complete .
* Micaela Graiver Comp. Science . Oct 3 2020 Debugging- fixing command line arguments .
* Micaela Graiver Comp. Science . Nov 4 2020 Debugging- fixing conversion of char array to integers .
* Micaela Graiver Comp. Science . Nov 5 2020 Debugging- finalize solution .
*/

#include<stdio.h>
int main(int argc, char* argv[]) {
    
if (argc != 4){
    printf("Error: invalid number of arguments!\n");
    printf("scalc <operand1> <operator> <operand2>");
    return 1;
    }

    if (*argv[2] != '+'){
    printf("Error: operator can only be + !\n");

    return 1;
    }


int num1[1000], num2[1000], sum[1000];
int l1, l2;

/* convert character to integer*/

for (l1 = 0; argv[1][l1] != '\0'; l1++){
    num1[l1] = argv[1][l1] - '0';
    if ((argv[1][l1] < '0') || (argv[1][l1]  > '9')){
           printf("Error!! operand can only be positive integers");
        return 1;
    }
    
}
    

for (l2 = 0; argv[3][l2] != '\0'; l2++){
    num2[l2] = argv[3][l2] - '0';
    if ((argv[3][l2] < '0') || (argv[3][l2]  > '9')){
           printf("Error!! operand can only be positive integers");
        return 1;
    }
    
}
    int carry = 0;
    int k = 0;
    int i = l1 - 1;
    int j = l2 - 1;
for (; i >= 0 && j >= 0; i--, j--, k++) {
    sum[k] = (num1[i] + num2[j] + carry) % 10;
    carry = (num1[i] + num2[j] + carry) / 10;
}
if (l1 > l2) {

while (i >= 0) {
    sum[k++] = (num1[i] + carry) % 10;
    carry = (num1[i--] + carry) / 10;
}

} else if (l1 < l2) {
    while (j >= 0) {
        sum[k++] = (num2[j] + carry) % 10;
        carry = (num2[j--] + carry) / 10;
}
    } 
    else 
    { if (carry > 0)
         sum[k++] = carry;
}



    for (k--; k >= 0; k--)
    printf("%d", sum[k]);
    printf("\n");

return 0;
}

