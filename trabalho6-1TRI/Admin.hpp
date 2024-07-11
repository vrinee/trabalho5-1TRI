#include <iostream>
#include <vector>

using namespace std;

class Usuario;
class Livro;
class Chamada;

class Admin{
    public:
        string nome;

        Admin(string _nome, string _senha);

        string getSenha();

        Usuario cadastrarUsuario();

        void deletarUsuario(vector<Usuario> &Usuarios);

        Livro novoLivro();

        void deletarLivro(vector<Livro> &Livros);

        Chamada novoEmprestimo(vector<Livro> &Livros, vector<Usuario> &Usuarios, int livroId, int usuarioId);

    private:
        string senha;
};

