#include <iostream>
const long double pi = 3.14159265358979323846264;
const long double e = 2.718281828459045235;

long double checkDouble();
long double fabs(long double arg);
long double pow(long double arg, unsigned long power);
long double sin(long double arg);
long double cos(long double arg);
long double ln(long double arg);
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Задание 6. Из величин a = sin(x), b = cos(x), c = ln(fabs(x)) найти минимальное при заданном x\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    long double a, b, c, x;
    std::cout << "Введите x: ";
    x = checkDouble();
    if (x == 0){
        std::cout << "x должен быть ненулевым!\n";
        return;
    }

    a = sin(x);
    b = cos(x);
    c = ln(fabs(x));

    std::cout << "a = " << a << "\tb = " << b << "\tc = " << c << '\n';
    std::cout << "Минимальное значение: " << ((a < b) && (a < c) ? a : b < c ? b : c) << '\n';
}

long double fabs(long double arg){
    if (arg < 0) return -arg;
    return arg;
}

long double sin(long double arg){
    if (arg < 0){
        return -sin(-arg);
    }

    long double n = 2 * pi;
    while(n <= arg){
        n *= 2;
    }
    while (arg > 2 * pi){
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

long double cos(long double arg){
    if (arg < 0){
        return cos(-arg);
    }

    long double n = 2 * pi;
    while(n <= arg){
        n *= 2;
    }
    while (arg > 2 * pi){
        while (arg >= n){
            arg -= n;
        }
        n /= 2;
    }

    long double res = 0;
    long double arg_n = 1;
    long long i = 0;

    while (i <= 5000){
        res += arg_n;
        i++;
        arg_n *= (-1) * arg * arg / ((2 * i) * (2 * i - 1));
    }

    return res;
}

long double ln(long double arg){
    long double s = 0;
    while (arg > 2) {
        arg /= e;
        s++;
    }
    if (arg < 0.1){
        return -ln(1 / arg) + s;
    }

    arg--;
    long double res = 0;
    long double arg_n = arg;
    long long i = 1;

    while (i <= 5000){
        res += arg_n;
        i++;
        arg_n *= (-arg) * (i - 1) / i;
    }

    return res + s;
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