#include <format>
#include <iostream>
#include <vector>

#include "../01_buildingblocks/Helpers.h"
//NOTA: Cuando el color de un archivo es diferente significa que no esta subido a un repo en git previo
static void vector_example_1() {
    std::vector<int> v1{10, 20, 30, 40, 50};
    std::vector<int> v2(v1.size());
    std::vector<int> v3(v1.size(), 7);
    print_container("v1: ", v1);
    print_container("v2: ", v2);
    print_container("v3: ", v3);
    // operadot [] o .at()
    for (size_t i = 0; i < v1.size(); ++i) {
        v2[i] = v1[i] * v3.at(i);
    }
    print_container("v2 (after opertation): ", v2);
    //mas vectores
    std::vector<unsigned long long> v4{100, 200, 300, 400, 500, 600, 700, 800};
    std::vector<unsigned long long> v5(v4.size(), 100); //constructor
    std::vector<unsigned long long> v6{v4.size()}; //inicializacion
    std::vector<unsigned long long> v7{};
    print_container("v4: ", v4);
    print_container("v5: ", v5);
    print_container("v6: ", v6);
    print_container("v7: ", v7);
    //iteradores
    auto it4 = v4.begin();
    auto it5 = v5.begin();
    auto it6 = v6.begin();

    for (; it4 != v4.end(); ++it4, ++it5, ++it6) {
        *it5 = *it4 / 2;
    }
    print_container("v5 (after operation): ", v5);
    //front(); back()
    std::cout << std:: format("v4.front(): {:6d}", v4.front()) << endl;
    std::cout << std:: format("v4.back(): {:6d}", v4.back()) << endl;
    //Clear
    v5.clear();
    print_container("v5 (after clear): ", v5);
}

int main() {
    std::cout << "Vectors |!|" << std::endl;
    vector_example_1();
    return 0;
}
