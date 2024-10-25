#include <iostream>
#include <cmath>

void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 3. Вычислить значения функции y = sin(x) - cos(x) на отрезке [A, B] в точках X_i = A + i * H, H = (B - A) / M\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    const long double M = 20, A = 0, B = M_PI / 2;
    long double H = (B - A) / M;
    std::cout << "M = 20, A = 0, B = pi / 2, H = " << H << '\n';

    long long i = 1;
    long double X = A + i * H;

    while (X <= B){
        std::cout << "y = " << sin(X) - cos(X) << "\tx = " << X << '\n';
        i++;
        X = A + i * H;
    }
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