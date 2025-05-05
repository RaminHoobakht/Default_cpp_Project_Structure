/* character comparison */

#include "main.hpp"

uint add_asci_code(const std::string word) noexcept;

int main() {

    std::string one{"ZBCDB"}; // total asci code is 295
    std::string two{"ZBCDABCD"}; // total asci code is 298

    // std::string one{"wild"}; // total asci code is 432
    // std::string two{"animal"}; // total asci code is 626

    if (one > two) {
        out << "one is greater than two ..." << NL;
    } else if (two > one) {
        out << "two is greater than one ..." << NL;
    } else {
        out << "both are equals ..." << NL;
    }

    SEP;

    out << "one : " << one << NL;
    out << "two : " << two << NL;
    SEP;

    out << "one : " << add_asci_code(one) << NL;
    out << "two : " << add_asci_code(two) << NL;
    SEP;

    out << "compare one and two : " << one.compare(two) << NL;
    //  0: equals
    // -1: rhs is greater
    //  1: lhs is greater

    out << "\n #(00:00:00): The End ..." << eln;
    return EXIT_SUCCESS;
}

uint add_asci_code(const std::string word) noexcept {
    size_t size{word.size()};
    uint sum{};
    for (size_t i{util::zero}; i < size; ++i) {
        sum += uint(word.at(i));
    }
    return sum;
}
