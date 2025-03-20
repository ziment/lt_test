#include <cmath>
#include <iostream>

// Не принимаем изначальную сумму, она не нужна для ответа
void usage() {
    std::cout << "Usage: fincalc <interest> <multiplier>\nConstraints:\n  "
                 "interest > 0\n  multiplier >= 1"
              << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Exactly 2 arguments are required" << std::endl;
        usage();
        return 1;
    }

    double interest, mult;

    try {
        interest = std::stod(argv[1]);
        mult = std::stod(argv[2]);
    } catch (std::invalid_argument) {
        std::cerr << "Unable to parse numerical arguments" << std::endl;
        usage();
        return 2;
    }

    if (interest <= 0 || mult < 1) {
        std::cerr << "Invalid argument values." << std::endl;
        usage();
        return 3;
    }

    double years = log(mult) / log(1 + interest / 100);

    std::cout << ceil(years) << std::endl;

    return 0;
}
