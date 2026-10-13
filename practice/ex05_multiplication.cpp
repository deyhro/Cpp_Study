#include <iostream>

void multi()
{
    int num;

    while (true)
    {
        std::cout << "2부터 9 사이의 정수 입력 : ";
        std::cin >> num;

        if (num >= 2 && num <= 9)
        {
            for (int i = 1; i < 10; i++)
            {
                std::cout << num << " x " << i << " = " << num * i << std::endl;
            }
            break;
        }
        else
        {
            std::cout << "잘못된 입력입니다. (2~9 사이의 값을 입력해주세요.)" << std::endl;
            continue;
        }
    }
}

int main()
{
    multi();

    return 0;
}