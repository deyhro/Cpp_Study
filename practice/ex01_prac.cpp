#include <iostream>

int main()
{
    int num = 10;
    int* ptr = &num;
    int** pptr = &ptr;
    // 표기 방법의 차이 : int* ptr , int * ptr , int *ptr
    // * : 포인터
    // & : 메모리 주소 호출

    std::cout << "num : " << num << std::endl;
    std::cout << "&num : " << &num << std::endl;

    std::cout << "ptr : " << ptr << std::endl;
    std::cout << "*ptr : " << *ptr << std::endl;
    
    std::cout << "pptr : " << pptr << std::endl;
    std::cout << "*pptr :" << *pptr << std::endl;
    std::cout << "**pptr : " << **pptr << std::endl;
    // std : C++ 표준 라이브러리 에서 사용하는 namespace
    // << : 출력 스트림에 값을 전달
    // cout : 콘솔 출력
    // endl : 줄바꿈 + 출력 버퍼 flush

    return 0;
}
