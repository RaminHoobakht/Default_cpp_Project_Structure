/* passing array to the function */

#include <iostream>
#include "../header/utillib.hpp"

#define out std::cout
#define log std::clog
#define err std::cerr

namespace cpp {

    void display_array(const int (&int_array)[], size_t size) noexcept;


    void display_array(const int (&int_array)[], const size_t size) noexcept {
        for (size_t i{util::zero}; i < size; ++i) {
            out << SP << int_array[i] << SP;
        }
        LF;
    }

} // namespace cpp


int main() {

    int int_arr[]{10, 23, 36, 52, 41, 14, 85, 47, 96, 36};

    size_t size{sizeof(int_arr) / sizeof(*int_arr)};

    cpp::display_array(int_arr, size);

    std::cout << "\n #(17:23:30): The End ..." << std::endl;
    return (EXIT_SUCCESS);
}
