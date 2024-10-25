#include <iostream>

long long checkLong();
unsigned long long checkUnsignedLong();
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 8. Вычислить a_0 - 2a_1 + 4a_2 - 8a_3 +...+ 2^(n - 1) * (-1)^(n - 1) * a_n-1\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    std::cout << "Введите n: ";
    unsigned long long n;
    n = checkUnsignedLong();

    std::cout << "Введите коэффиценты: ";
    long long sum = 0, a_i = 0, k = 1, a = 0;
    bool sign;
    a_i = checkLong();
    sum = a_i;
    a = a_i;
    for (int i = 1; i < n; i++){
        sign = (a < 0);
        a_i = checkLong();
        if (sign){
            a = a_i;
        }
        else{
            a = -a_i;
        }
        sum += a << i;
    }

    std::cout << sum << '\n';
}

unsigned long long checkUnsignedLong(){
    unsigned long long input;
    char c;
    if (std::cin >> input){
        std::cin.get(c);
        if (c == '\n'){
            return input;
        }
        else {
            std::cout << "Неверный формат ввода!\n";
            std::cin.ignore(12413,'\n');
            checkUnsignedLong();
        }
    }
    else {
        std::cout << "Неверный формат ввода!\n";
        std::cin.clear();
        std::cin.ignore(12413,'\n');
        checkUnsignedLong();
    }
    
    return 1;
}

long long checkLong(){
    long double input;
    if (std::cin>>input){
        if ((input - (long long)input) != 0) {
        std::cout << "Неверный формат ввода!\n";
        std::cin.clear();
        std::cin.ignore(12413,'\n');
        checkLong();
        }
        else {
            return input;
        }
    }
    else {
        std::cout << "Неверный формат ввода!\n";
        std::cin.clear();
        std::cin.ignore(12413,'\n');
        checkLong();
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