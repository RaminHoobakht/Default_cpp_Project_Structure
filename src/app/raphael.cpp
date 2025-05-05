
#include <iostream>
#include <utility>

namespace cpp {

    class raphael final {

    private:
        int value_{};

    public:
        raphael() noexcept;
        explicit raphael(const int value_param) noexcept;
        raphael(const raphael &rhs) noexcept;
        raphael(raphael &&rhs) noexcept;
        ~raphael() noexcept;

        void set_value(int value_param) noexcept;
        [[nodiscard]] int get_value() const noexcept;

        raphael &operator=(const raphael &rhs) noexcept;

        /* move constructor parameter should be non-constant to modify */
        raphael &operator=(raphael &&rhs) noexcept;
    };

    /* ----------------------------------------- */

    raphael::raphael() noexcept {
        std::cout << "Hello, I am raphael ..." << '\n';
    }

    raphael::raphael(const int value_param) noexcept : value_(value_param) {
        std::cout << "Hello, I am initialized raphael class ..." << '\n';
    }

    raphael::raphael(const raphael &rhs) noexcept : value_(rhs.value_) {
        std::cout << "Hello, I am raphael copy constructor ..." << '\n';
    }

    raphael::raphael(raphael &&rhs) noexcept :
        value_(std::exchange(rhs.value_, 0)) {
        std::cout << "Hello, I am raphael move constructor ... " << '\n';
    }

    raphael::~raphael() noexcept {
        /* code */
        std::cout << "Goodbye raphael ..." << '\n';
    }

    /* const not needed for primitive value  */
    void raphael::set_value(int value_param) noexcept {
        /* code */
        value_ = value_param;
    }

    int raphael::get_value() const noexcept {
        /* code */
        return value_;
    }

    /* return command should be out of if block */
    raphael &raphael::operator=(const raphael &rhs) noexcept {
        if (this != &rhs) {
            this->value_ = rhs.value_;
        }
        return *this;
    }

    raphael &raphael::operator=(raphael &&rhs) noexcept {
        if (this != &rhs) {
            this->value_ = std::exchange(rhs.value_, 0);
        }
        return *this;
    }


} // namespace cpp


int main() {

    std::cout << '\n';

    auto raphael_one{cpp::raphael{10}};
    auto raphael_two{cpp::raphael{20}};

    std::cout << "raphael one value: " << raphael_one.get_value() << '\n';
    std::cout << "raphael two value: " << raphael_two.get_value() << '\n';
    std::cout << "-------------------------------------------------" << '\n';

    raphael_one = raphael_two;

    std::cout << "raphael one value: " << raphael_one.get_value() << '\n';
    std::cout << "raphael two value: " << raphael_two.get_value() << '\n';
    std::cout << "-------------------------------------------------" << '\n';

    cpp::raphael raphael_temp{30};
    auto raphael_three{std::move(raphael_temp)};
    std::cout << "raphael three value: " << raphael_three.get_value() << '\n';
    std::cout << "-------------------------------------------------" << '\n';

    auto raphael_four{raphael_three};
    std::cout << "raphael four value: " << raphael_four.get_value() << '\n';
    std::cout << "-------------------------------------------------" << '\n';

    std::cout << "\n The End ..." << std::endl;
    return EXIT_SUCCESS;
}
