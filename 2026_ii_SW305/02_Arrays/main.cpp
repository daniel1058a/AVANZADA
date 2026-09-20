#include <iostream>
#include <array>
#include <format>

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

int main() {
    std::cout << "Arrays |!|" << std::endl;
    //array_example_1();
    array_example_2();
    return 0;
}
