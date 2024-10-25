#include <iostream>
#include <cmath>

long double checkDouble();
bool Armstrong(long long x);
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 7. Вывести все числа Армстронга(числа, равные сумме своих цифр, возведенных в степень, равную количеству цифр) меньше n\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    std::cout << "Введите n: ";
    long double n;
    n = checkDouble();

    std::cout << "Числа Армстронга меньше " << n << ": \n";
    for (int i = 1; i <= n; i++)
    {
        if (Armstrong(i)){
            std::cout << i << '\n';
        }
    }
}

bool Armstrong(long long x){
    long long x_i = x;
    bool isArmstrong = false;
    long long n = log10(x) + 1, sum = 0, i = n;

    while (i){
        long long power = pow(10, i - 1), digit = x_i / power;
        sum += pow(digit, n);
        x_i %= power;
        i--;
        if (sum > x){
            break;
        }
    }
    if (sum == x){
        isArmstrong = true;
    }

    return isArmstrong;
}

long double checkDouble(){
    long double input;
    char c;
    if (std::cin >> input){
        std::cin.get(c);
        if (c == '\n'){
            return input;
        }
        else {
            std::cout << "Неверный формат ввода!\n";
            std::cin.ignore(12413,'\n');
            checkDouble();
        }
    }
    else {
        std::cout << "Неверный формат ввода!\n";
        std::cin.clear();
        std::cin.ignore(12413,'\n');
        checkDouble();
    }
    
    return 1;
}
void repeat(){
    std::cout << "Повторить решение?(y/n) ";
    char c;
    std::cin >> c;
    if (c == 'y'){
        std::cout << "----------------------\n";
        std::cin.ignore(12413,'\n');
        main();
    }
    else if (c == 'n'){
        return;
    }
    else {
        std::cout << "Неверный символ!\n";
        std::cin.ignore(12413,'\n');
        repeat();
    }
}