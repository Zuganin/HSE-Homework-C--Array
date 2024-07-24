#include <iostream>
#define CATCH_CONFIG_MAIN


#include <array>
#include <utility>

#include "array.h"
#include "array.h"  // check include guards

template <class T, class U, size_t N>
void Equals(const Array<T, N>& actual, const std::array<U, N>& required) {
    for (size_t i = 0; i < N; ++i) {
        if(!(actual[i] == required[i])) {
            std::cout << "Wrong answer" << "\n";
        }
    }
}

void REQUIRE(bool b) {
    if (!b) {
        std::cout << "Wrong answer" << "\n";
    }
}

void REQUIRE_FALSE(bool b) { return REQUIRE(!b); }

int main()
{
    Array<int, 3> a{};
    a[0] = 1;
    a[1] = 2;
    a[2] = -1;

    REQUIRE(std::as_const(a).Data() == &(a[0]));
    REQUIRE(*(std::as_const(a).Data() + 1) == 2);
    static_assert((std::is_same_v<decltype(a.Data()), int*>));
    static_assert((std::is_same_v<decltype(std::as_const(a).Data()), const int*>));
}
