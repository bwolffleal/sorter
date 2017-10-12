#include "No.h"

class Lista
{
protected:
    No * lista;
    unsigned int numnos;
    No * fim;
public:
    Lista();
    ~Lista();
    void Insere(TipoDado x);
    TipoDado Remove(TipoDado m);
    TipoDado Remove();
    bool Vazia();
    unsigned int Tam();
    void Imprime();
};

