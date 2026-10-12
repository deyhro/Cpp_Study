// 문제 3. 짝수, 홀수 판별

#include <iostream>

void EvenOdd(int* num) {
    if (*num % 2 == 0) {
        std::cout << *num << "은 짝수" << std::endl;
    }
    else {
        std::cout << *num << "은 홀수" << std::endl;
    }
}

int main(){

    int num;

    std::cout << "정수 입력 : ";
    std::cin >> num;

    EvenOdd(&num);

    return 0;
}

// 정답 :
// 정수를 입력하세요 : "입력"
// "입력"은 "짝수/홀수"입니다.

// 한글 깨짐 문제
// chcp 65001 작성 후 코드 실행