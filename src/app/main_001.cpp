albert::albert(const albert &rhs) noexcept : value_(rhs.value_) {}

albert::albert(albert &&rhs) noexcept : value_(std::exchange(rhs.value_, 0)) {}

albert &albert::operator=(const albert &rhs) noexcept {
    if (this != &rhs) { // Add self-assignment check
        value_ = rhs.value_;
    }
    return *this;
}
