#include <cmath>
#include <iostream>

// Не принимаем изначальную сумму, она не нужна для ответа
void usage() {
    std::cout << "Usage: fincalc <interest> <multiplier>\nConstraints:\n  "
                 "interest > 0\n  multiplier >= 1"
              << std::endl;
}

void unable_to_parse() {
    std::cerr << "Unable to parse numerical arguments" << std::endl;
    usage();
    std::exit(2);
}

void constraints_not_satisfied() {
    std::cerr << "Arguments do not satisfy the constraints" << std::endl;
    usage();
    std::exit(3);
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if (std::string(argv[1]) == "help") {
            usage();
            return 0;
        }
    }


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
        unable_to_parse();
    } catch (std::out_of_range) {
        unable_to_parse();
    }

    if (interest <= 0 || mult < 1) {
        constraints_not_satisfied();
    }

    double years = std::log(mult) / std::log(1 + interest / 100);

    std::cout << ceil(years) << std::endl;

    return 0;
}
