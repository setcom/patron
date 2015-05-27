#include <iostream>
using namespace std;

class Interface_algoritmo
{
    public:
        virtual void ejecutar() const = 0;
};

class Estrategia_sumar: public Interface_algoritmo
{
    public:
        virtual void ejecutar() const
        {
            cout << "Ya se SUMAR" << endl;
        }
};

class Estrategia_restar: public Interface_algoritmo
{
    public:
        virtual void ejecutar() const
        {
            cout << "Ya se RESTAR" << endl;
        }
};

class Estrategia_mult: public Interface_algoritmo
{
    public:
        virtual void ejecutar() const
        {
            cout << "Ya se MULTIPLICAR" << endl;
        }
};




class Contexto_estudiante
{
    private:
        Interface_algoritmo * estrategia_;

    public:
        explicit Contexto_estudiante(Interface_algoritmo *estrategia):estrategia_(estrategia)
        {
        }

        void set_estrategia_algoritmo(Interface_algoritmo *estrategia)
        {
            estrategia_ = estrategia;
        }

        void ejecutar() const
        {
            estrategia_->ejecutar();
        }
};

int main(int argc, char *argv[])
{
    Estrategia_sumar estrategia_sumar;
    Estrategia_restar estrategia_restar;
    Estrategia_mult estrategia_mult;

    Contexto_estudiante contextoSumar(&estrategia_sumar);
    Contexto_estudiante contextoRestar(&estrategia_restar);
    Contexto_estudiante contextoMult(&estrategia_mult);

    contextoSumar.ejecutar();
    contextoRestar.ejecutar();
    contextoMult.ejecutar();

    contextoSumar.set_estrategia_algoritmo(&estrategia_restar);
    contextoSumar.ejecutar();
    contextoSumar.set_estrategia_algoritmo(&estrategia_mult);
    contextoSumar.ejecutar();

    return 0;
}

