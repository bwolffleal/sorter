#include <iostream>
#include "Lista.h"

int main() {
    Lista A;
    int n, m;
    int num = 1;
    std::cout << "Digite o numero de variaveis: ";
    std::cin >> n;
    std::cout << "Digite o fator sorteador: ";
    std::cin >> m;
    while (num != n + 1)
    {
        A.Insere(num);
        ++num;
    }
    A.Imprime();
    A.Tam();
    A.Remove(m);
    return 0;
}