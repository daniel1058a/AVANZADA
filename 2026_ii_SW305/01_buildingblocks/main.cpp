#include <iostream>

using namespace std;
//Plantilla
template<typename T>
static void Swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}
//El const: leer pero no modificar
//size_t: enteros positivos exclusivo para tamaños
static void Print(const int A[], size_t size) {
    for (size_t i=0 ; i<size ; i++) {
        cout << A[i] <<endl;
    }
}
template<typename T>
static void Print2(const T& array) {
    for (auto element : array) {
        cout << element << " ";
    }
    cout << " " <<endl;
}

int main() {
    std::cout << "Building Blocks |!|" << std::endl;
    int A[] = {3, 6};
    //Print(A, 2);
    Print2(A);
    Swap(A[0], A[1]);
    //Print(A, 2);
    Print2(A);

    return 0;
}
