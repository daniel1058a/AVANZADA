#include <algorithm>
#include <iostream>
#include <array>
#include <format>
#include "Helpers.h"
using namespace std;

static void array_example_1() {
    array<int, 9> x_values {100, 200, 300, 400, 500, 600, 700, 800, 900}; //initialization
    //Look: if array doesn't have any value so all of values will be 0
    for (int i = 0; i < x_values.size(); i++) {
        //.at(i): returns the i value
        cout << x_values.at(i) << endl;
    }
    for (auto value : x_values) {
        //auto: interpret which is the data type from container
        //cout << value << " ";
        cout << format("{:4d}", value);
    }
    cout << endl;
    cout <<  "size: "  <<x_values.size() << endl;
    //iterator
    cout << "Iteradores" <<endl;
    for ( auto it = x_values.begin(); it != x_values.end(); ++it) {
        cout<< format( "{:7d}", *it); // *it: desreferenciador
    }
    cout << endl;
    //iterator reverso
    cout << "Iteradores reversos" <<endl;
    //Even tought the iterator is reverse it has to increase
    for (auto it = x_values.rbegin(); it != x_values.rend(); ++it) {
        cout<< format( "{:5d}", *it);
    }
}

static void array_example_2() {
    array<long, 10> x_values {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (auto it = x_values.begin() ; it != x_values.end() ; ++it) {
        cout << format("{:6d}", *it);
    }
    cout << endl;
    // agregar
    for (auto it = x_values.begin() ; it != x_values.end() ; ++it) {
        *it += 5;
        //Se puede acceder a los elementos del array usando *it (desrreferenciador), si se tiene el indice se usa .at(i)
    }
    for (auto it = x_values.begin() ; it != x_values.end() ; ++it) {
        cout << format("{:6d}", *it);
    }
}

static void array_example_3() {
    array<double, 8> radios{1.0, 1.4, 2.0, 2.8, 4.0, 5.6, 8.0, 11.0};
    array<double, radios.size()> areas{}; //Se inicializan en 0;
    //Calculo
    auto it_a = areas.begin();
    for (auto it_r = radios.begin(); it_r != radios.end(); ++it_r, ++it_a) {
        *it_a = numbers::pi * *it_r * *it_r;
    }
    //Print
    it_a =  areas.begin();

    cout << format("{:6s} {:12s}", "Radios" , "Areas") << endl;
    for (auto it_r = areas.begin(); it_r != areas.end(); ++it_r, ++it_a) {
        cout << format ("{:6.1f} {:12.6f}", *it_r, *it_a) << endl;
    }
}

//Recomentacion: Evitar usar el using namespace std;
static void array_example_4() {
    constexpr size_t epl_max{5};
    array<string, 15> colors_1{"Red" , "Green" , "Blue" , "Cyan" , "Magenta" , "Yellow", "Black" , "White" , "Orange" , "Pink" , "Purple" , "Ambar" , "Lake", "Gold", "Silver"};
    auto colors_2{colors_1}; //Es igual que hacer colors_2 = colors_1
    print_container("Container 1", colors_1, 5);
    print_container("Container 2", colors_2, 5);
    //sort
    sort(colors_1.begin(), colors_1.end());
    print_container("colors_1 (after sort):", colors_1, 5);
    //range::sort
    ranges::sort(colors_2.begin(), colors_2.end());
    print_container("colors_2 (after ranges::sort):", colors_2, 5);
    //comparacion
    //{:s}: Especificador de un String
    cout << format("colors_1 == colors_2 : {:s}", colors_1 == colors_2) << endl;
}

int main() {
    std::cout << "Arrays |!|" << std::endl;
    //array_example_1();
    //array_example_2();
    //array_example_3();
    array_example_4();
    return 0;
}
