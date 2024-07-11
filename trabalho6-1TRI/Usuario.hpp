
#include <iostream>
#include <vector>


using namespace std;

class Chamada;
class Livro;

class Usuario{
    public:
        string nome;
        
        Usuario(string _nome, string _senha, int _dtaNascimento[3], string _email, string _telefone);

        void setNome(string _nome);

        string getSenha();

        void setSenha(string _senha);

        int *getDtaNascimento();

        void setDtaNascimento(int _dtaNascimento[3]);

        string getEmail();

        void setEmail(string _email);

        string getTelefone();

        void setTelefone(string _telefone);

        float getMulta(vector<Chamada> &Chamadas);

        bool getStatus();

        void checarStatus();

        void setId(vector<Usuario> &Usuarios);

        int getId();

        int getEmprestimos();

        void addEmprestimo();

        void checarMulta(vector<Chamada> &Chamadas);

        void pagarMulta(float valor, vector<Chamada> &Chamadas);
        void devolverLivro(vector<Chamada> &Chamadas, vector<Livro> &Livros);

    private:
        string senha;
        int dtaNascimento[3];
        string email;
        string telefone;
        float multa;
        bool status;
        int id;
        int emprestimos = 0;

};

