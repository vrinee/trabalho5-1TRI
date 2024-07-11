#include <iostream>
#include <vector>

class Admin;
class Usuario;
class Livro;
class Chamada;

using namespace std;

int loginAdmin(vector<Admin> &Admins);

Admin createAdmin();

// funções de criação
    void createUser(vector<Usuario> &Usuarios, Admin &Admin);

    int loginUser(vector<Usuario> &Usuarios);

    void createBook(vector<Livro> &Livros, Admin &Admin);

    void createChamada(vector<Chamada> &Chamadas,vector<Usuario> &Usuarios, vector<Livro> &Livros, Admin &Admin);
// Fim das funções de criação

// Funções de listagem
    void listarUsuarios(vector<Usuario> &Usuarios);

    void listarAtributosUser(Usuario user, vector<Chamada> &Chamadas);

    void listarAdmins(vector<Admin> &Admins);

    void listarLivros(vector<Livro> &Livros);

    void listarAtributosLivro(Livro book);

    void listarChamadas(vector<Chamada> &Chamadas, vector<Usuario> &Usuarios, vector<Livro> &Livros);

    void listarAtributosChamada(Chamada call, vector<Usuario> &Usuarios, vector<Livro> &Livros);
// Fim das funções de listagem

// Funções de ação

    void pagamento(Usuario &user, vector<Chamada> &Chamadas);

    void devolucao(Usuario &user, vector<Livro> &Livros, vector<Chamada> &Chamadas);

    void mudarAtributosUser(Usuario &user);

    void retirarExemplar(Livro &book);

    void checarMulta(vector<Chamada> &Chamadas, Usuario &user);

    void userActions(vector<Usuario> &Usuarios, vector<Livro> &Livros, vector<Chamada> &Chamadas);