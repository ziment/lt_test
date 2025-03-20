#include <cmath>
#include <iostream>

// Не принимаем изначальную сумму, она не нужна для ответа
void usage() {
    std::cout << "Usage: fincalc <interest> <multiplier>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Must provide exactly 2 parameters" << std::endl;
        usage();
        return 1;
    }

    double interest, mult;

    try {
        interest = std::stod(argv[1]);
        mult = std::stod(argv[2]);
    } catch (std::invalid_argument) {
        std::cerr << "Cannot parse numerical arguments" << std::endl;
        usage();
        return 2;
    }

    if (interest <= 0 || mult < 1) {
        std::cerr << "Invalid arguments" << std::endl;
        usage();
        return 2;
    }

    double years = log(mult) / log(1 + interest / 100);

    std::cout << ceil(years) << std::endl;

    return 0;
}
