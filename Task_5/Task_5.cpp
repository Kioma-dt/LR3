#include <iostream>
#include <cmath>

unsigned long long checkUnsignedLong();
long double f(long double x);
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\nВариант 1\n";
    std::cout << "Задание 5. Приближенно найти корень уравнения sin(x) + cos(x) - 2arctan(x) = 0 на отрезке [0,1] по следующему алгоритму: перебираем значения от начала до конца интервала с некоторым шагом и ищем значение функции, минимальное по модулю\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    std::cout << "Введите то, насколько частей нужно разбить отрезок: ";
    unsigned long n;
    n = checkUnsignedLong();
    const long double start = 0, end = 1;
    long double step = (end-start) / n;

    long double x_min = start, f_min = f(start);
    for (long double i = step; i <= end; i+=step){
        if (fabs(f(i)) < fabs(f_min)){
            f_min = f(i);
            x_min = i;
        }
    }
    std::cout << "Приближенный корень уравнения: x = " << x_min << '\n';
}

long double f(long double x){
    return sin(x) + cos(x) - 2 * atan(x);
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