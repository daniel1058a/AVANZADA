#include <algorithm>
#include <array>
#include <deque>
#include <format>
#include <iostream>
#include "../01_buildingblocks/Helpers.h"
static void deque_example1() {
    std::deque<int> d1{10, 20, 30, 40, 50};
    std::deque<int> d2(d1.size());
    print_container("d2", d2);
    for (size_t i = 0; i < d1.size(); ++i) {
        d2[i] = d1.at(i) * 5;
    }
    print_container("d2 (after initialization): ", d2);
    //create deque
    std::deque<long> d3{100, 200, 300, 400, 500};
    std::deque<long> d4(d3.size());
    print_container("d4 (after initialization): ", d4);
    //iterators
    auto it3 = d3.begin();
    auto it4 = d4.begin();
    for (; it3 != d3.end(); ++it3, ++it4) {
        *it4 = *it3 / 2;
    }
    print_container("d4 (after iterators): ", d4);
}

static void deque_example2() {
    std::deque<double> d1{};
    //push_back
    d1.push_back(50);
    d1.push_back(60);
    d1.push_back(70);
    d1.push_back(80);
    print_container("d1:", d1);
    //push_front
    d1.push_front(40.0);
    d1.push_front(30.0);
    d1.push_front(20.0);
    d1.push_front(10.0);
    print_container("d1:", d1);
    //add elements
    std::array<double, 5> array1{1000, 2000, 3000, 4000, 5000};
    d1.insert(d1.begin() + 2,array1.begin(), array1.end());
    print_container("d1 (after insert):", d1);
}
static void deque_example3() {
    std::deque<std::string> d1{"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
    print_container("d1 (initial values):", d1);
    std::array<std::string, 6> array1{"Jul", "Ago", "Sep", "Oct", "Nov", "Dec"};
    std::deque<std::string> d2{d1};
    //macros: Ayuda al programa a diferenciar entre entornos NO compatibles
#ifdef __cpp_lib_containers_ranges
    std::cout << "C++23" <<std::endl;
    d1.append_range(array1);
#else
    std::cout << "C++20" << std::endl;
    d1.insert(d1.end(), array1.begin(), array1.end());
#endif
    print_container("d1 (after insert):", d1);
    //sort
    std:ranges::sort(d1);
    print_container("d1 (after sort):", d1);
    std::ranges::sort(d1, std::greater<>());
    print_container("d1 (after sort greater):", d1);
    std::cout << std::format("d1 == d2 {:s}", d1 == d2) << std::endl;
    std::cout << std::format("d1 <= d2 {:s}", d1 <= d2) << std::endl;
    std::cout << std::format("d1 >= d2 {:s}", d1 >= d2) << std::endl;
}


int main() {
    std::cout << "Deque |!|" << std::endl;
    //deque_example1();
    //deque_example2();
    deque_example3();
    return 0;
}
