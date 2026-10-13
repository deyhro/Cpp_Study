#include<iostream>

int maxNumber(int* num1, int* num2, int* num3) {

    int* maxNum = num1;

    if (*num2 > *maxNum) {
        maxNum = num2;
    }
    
    if (*num3 > *maxNum){
        maxNum = num3;
    }

    return *maxNum;
}

int main() {

    int num1, num2, num3;
    
    std::cout << "정수 3개 입력 : ";
    std::cin >> num1 >> num2 >> num3;

    std::cout << "가장 큰 값은 : " << maxNumber(&num1, &num2, &num3);

    return 0;
}