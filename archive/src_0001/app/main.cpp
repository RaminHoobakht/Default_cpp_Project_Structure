/* using std::optional */

#include <cstddef>
#include <iostream>
#include <iterator>
#include <optional>
#include "../header/utillib.hpp"

#define out std::cout
#define in std::cin
#define log std::clog

namespace cpp {

    std::optional<size_t> find_character(str &msg, char ch) noexcept;

    std::optional<size_t> find_character(str &msg, const char ch) noexcept {

        std::string::iterator iter{std::ranges::find(msg, ch)};
		// std::ranges::find
		
        if (iter != msg.end()) {
            return std::distance(msg.begin(), iter);
        } else {
            return std::nullopt;
        }
    }

} // namespace cpp


int main() {

	LF;
	
    std::string message{"I am a Junior C/C++ Developer ..."};
    char ch{'D'};

    if (std::optional<size_t> result{cpp::find_character(message, ch)};
        result.has_value()) {
        out << " Character for search is: " << ch << NL;
        out << " Found it at " << result.value() << " position." << NL;
    } else {
        out << " Sorry to say that specified character not found ..." << NL;
    }


    std::cout << "\n #(00:00:00): The End ..." << std::endl;
    return (EXIT_SUCCESS);
}
