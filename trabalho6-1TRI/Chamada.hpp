
#include <iostream>
#include <vector>

using namespace std;

class Chamada{
    public:
        
        Chamada(int _dtaEmprestimo[3], int _idLivro, int _idUsuario);

        int* getDtaVenc();

        void setDtaVenc(int &_dtaVenc);

        int* getDtaEmprestimo();

        int getIdLivro();

        int getIdUsuario();

        bool getStatus();

        void setStatus();

        bool getAtrasado();

        void setAtrasado();

        int getId();

        void setId(vector<Chamada> &Chamadas);

    private:
        int dtaVenc[3];
        int dtaEmprestimo[3];
        int idLivro;
        int idUsuario;
        bool status;
        bool atrasado;
        int id;


};