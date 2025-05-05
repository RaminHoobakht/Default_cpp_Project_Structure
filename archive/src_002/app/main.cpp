/* passing array to function */

#include <cstddef>
#include <iostream>
#include "../header/utillib.hpp"

#define out std::cout
#define log std::clog
#define err std::cerr

namespace cpp {

    void display_array(const int(&int_arr), size_t size) noexcept;
    void display_array(const int (&int_arr)[], size_t size) noexcept;


    void display_array(const int(&int_arr), const size_t size) noexcept {
        out << "version one ..." << NL;
        for (size_t i{util::zero}; i < size; ++i) {
            out << SP << (int_arr + static_cast<int>(i)) << SP;
        }
        LF;
    }

    void display_array(const int (&int_arr)[], const size_t size) noexcept {
        out << "version two ..." << NL;
        for (size_t i{util::zero}; i < size; ++i) {
            out << SP << *(int_arr + static_cast<int>(i)) << SP;
        }
        LF;
    }


} // namespace cpp


int main() {

    const int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const size_t size{sizeof(arr) / sizeof(*arr)};

	LF;
    cpp::display_array(*arr, size);
    SEP;

	LF;
    cpp::display_array(arr, size);
    SEP;

    std::cout << "\n #(01:05:40): The End ..." << std::endl;
    return (EXIT_SUCCESS);
}
