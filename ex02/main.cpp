#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

Base* generate() {
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Genere: A" << std::endl;
        return new A();
    } else if (r == 1) {
        std::cout << "Genere: B" << std::endl;
        return new B();
    } else {
        std::cout << "Genere: C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Inconnu" << std::endl;
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Inconnu" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialisation aléatoire

    std::cout << "=== TEST DE TYPE PAR IDENTIFICATION ===" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n[TEST " << i + 1 << "]" << std::endl;

        Base* ptr = generate();// genere un objet A, B ou C

        std::cout << "Identification par pointeur : ";
        identify(ptr); // affiche A, B ou C avec Base*

        std::cout << "Identification par reference : ";
        identify(*ptr); // affiche A, B ou C avec Base&

        delete ptr;
    }

    return 0;
}
