#include "Lista.h"
#include "No.h"
#include <iostream>

Lista::Lista()
{
    fim = NULL;		//aponta para o ultimo
    lista = NULL;	//aponta para o primeiro
    numnos = 0;		//numero de nos
}

Lista::~Lista()
{
    if (lista == fim)
    {
        this->Remove();
    }
    else
    {
        this->Remove(1);
    }
}

TipoDado Lista::Remove()
{
    if (!Vazia())
    {
        No * rem = lista;
        TipoDado elem;
        elem = rem->info;
        std::cout << "Elemento Removido: " << elem << std::endl;
        lista = rem->prox;
        delete rem;
        --numnos;
        return elem;
    }
    else
    {
        std::cout << "Lista Vazia!" << std::endl;
    }
}

void Lista::Insere(TipoDado x)
{
    No * novono;
    novono = new No;
    novono->info = x;
    if (Vazia())
    {
        lista = novono;
        lista->prox = lista;
        ++numnos;
        fim = lista;
    }
    else
    {
        novono->prox = lista;
        fim->prox = novono;
        fim = novono;
        ++numnos;
    }
}

TipoDado Lista::Remove(TipoDado m)
{
    if (Vazia())
    {
        std::cout << "Lista Vazia! " << std::endl;
        return 0;
    }
    else
    {
        No * rem;
        while (numnos>1)
        {
            for (int i = 1; i<m; i++)
            {
                if (i == m - 1)
                {
                    fim = lista;
                }
                lista = lista->prox;
            }
            rem = lista;
            lista = lista->prox;
            fim->prox = lista;
            std::cout << "O valor a ser deletado eh: " << rem->info << std::endl;
            rem->prox = NULL;
            delete rem;
            --numnos;
        }
        std::cout << "O valor sorteado eh: " << lista->info << std::endl;
        lista->prox = NULL;
        return lista->info;
    }
}

void Lista::Imprime()
{
    No *tnp = lista;
    do
    {
        std::cout << tnp->info << std::endl;
        tnp = tnp->prox;
    } while (tnp != lista);
}

unsigned int Lista::Tam()
{
    std::cout << "Tamanho da Lista: " << numnos << std::endl;
    return numnos;
}

bool Lista::Vazia()
{
    return lista == NULL;
}
