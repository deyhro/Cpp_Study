#include <iostream>

void Attack(int* hp, int damage) {
    *hp -= damage;
}

int main() {

    int hp = 100;
    int num;

    std::cout << "숫자를 입력하세요 : ";
    std::cin >> num;

    Attack(&hp, num);

    std::cout << "입힌 데미지 : " << num << std::endl;
    std::cout << "hp : " << hp << std::endl;

    return 0;
}