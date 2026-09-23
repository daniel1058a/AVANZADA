//
// Created by USUARIO on 21/09/2026.
//

#ifndef INC_2026_II_SW305_HELPERS_H
#define INC_2026_II_SW305_HELPERS_H

#include <iostream>
using namespace std;
template <typename T>
static void print_container(const char *msg, const T& container, size_t epl_max = 0) { //epl: elementos/linea
    if (msg != nullptr) {
        cout << msg << endl;
    }
    size_t epl{}; //numero de elementos por linea
    size_t num_elem{}; //numero de elementos por contenedor
    for (const auto& elemen : container) {
        ++ num_elem;
        cout << elemen << " ";
        if (epl_max !=  0) {
            if (++epl % epl_max == 0) {
                cout << endl;
            }
        }
    }
    if (num_elem == 0) {
        cout << "<empty>" << endl;
    }
    cout << endl;
}

#endif //INC_2026_II_SW305_HELPERS_H
