#include <iostream>
#include <cmath>

void solve();
void repeat();

int main (){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 2. Вычислить сумму ряда d_n = 1 / 2^n + 1 / 3^n с точнстью 10^-3\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    long double d, sum = 0, accuracy = 1e-3;
    long long n = 1;

    do {
        d = 1 / pow(2, n) + 1 / pow(3, n);
        sum += d;
        n++;
    } while (d >= accuracy);

    std::cout << "Сумма ряда: " << sum << '\n';
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