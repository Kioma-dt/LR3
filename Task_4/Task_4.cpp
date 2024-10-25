#include <iostream>
#include <cmath>

unsigned long long n = 0;

long double checkDouble();
long long checkLong();
long double my_sin(long double arg);
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\nВариант 1\n";
    std::cout << "Задание 4. Разложить функцию sin(x) в ряд Тейлора, затем с помощью полученного ряда найти значение функции и сравнить его со значением, вычисленным с помощью стандартных функций\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    std::cout << "Введите количество членов ряда Тейлора для разложения функции: ";
    n = checkLong();

    std::cout << "Введите количество чисел, от которых необходимо посчитать значение функции: ";
    long long l;
    l = checkLong();

    std::cout << "Введите эти числа (числа должны принадлежать отрезку [0.1, 1]): ";
    long double x;
    for (int i = 0; i < l; i++){
        x = checkDouble();
        if (x < 0.1 || x > 1){
            std::cout << "Числа должны принадлежать отрезку [0.1, 1]!\n";
            return;
        }
        std::cout << "sin(x) = " << sin(x) << "\tmy_sin(x) = " << my_sin(x) << '\n';
    }
}

long double my_sin(long double arg){
    if (arg < 0){
        return -sin(-arg);
    }

    long double n = 2 * M_PI;
    while(n <= arg){
        n *= 2;
    }
    while (arg > 2 * M_PI){
        while (arg >= n){
            arg -= n;
        }
        n /= 2;
    }

    long double res = 0;
    long double arg_n = arg;
    long long i = 0;


    while (i <= 5000){
        res += arg_n;
        i++;
        arg_n *= (-1) * arg * arg / ((2 * i) * (2 * i + 1));
    }

    return res;
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

long long checkLong(){
    long long input;
    char c;
    if (std::cin >> input){
        std::cin.get(c);
        if (c == '\n'){
            return input;
        }
        else {
            std::cout << "Неверный формат ввода!\n";
            std::cin.ignore(12413,'\n');
            checkLong();
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