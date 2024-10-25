#include <iostream>
#include <cmath>

void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 1. Вычислить N, равное сумме выражений (a_i - b_i)^2 при i от 1 до 30, где a_i = i, b_i = i^2 при нечетных i; a_i = i / 2, b_i = i^3 при четных i\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    long double N = 0, a, b;
    int i = 1;

    while (i <= 30){
        if (i % 2 == 0){
            a = (long double) i / 2;
            b = pow(i, 3);
        }
        else {
            a = i;
            b = pow(i, 2);
        }
        N += pow(a - b, 2);
        i++;
    }

    std::cout << "N = " << N << '\n';
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