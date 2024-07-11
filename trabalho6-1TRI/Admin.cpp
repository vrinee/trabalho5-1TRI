#include <iostream>
#include <vector>
#include <string>
#include "Admin.hpp"
#include "Usuario.hpp"
#include "Livro.hpp"
#include "Chamada.hpp"
#include "classFunc.hpp"

using namespace std;

Admin::Admin(string _nome, string _senha)
{
    nome = _nome;
    senha = _senha;
}

string Admin::getSenha()
{
    return senha;
}

Usuario Admin::cadastrarUsuario()
{
    string nome;
    string senha;
    int dtaNascimento[3];
    string email;
    string telefone;
    cout << "Digite o nome do Usuario: ";
    getline(cin, nome);
    cout << "Digite a senha do Usuario: ";
    cin >> senha;
    cout << "Digite o dia de nascimento do Usuario: ";
    cin >> dtaNascimento[0];
    cout << "Digite o mes de nascimento do Usuario: ";
    cin >> dtaNascimento[1];
    cout << "Digite o ano de nascimento do Usuario: ";
    cin >> dtaNascimento[2];
    cout << "Digite o email do Usuario: ";
    cin >> email;
    cout << "Digite o telefone do Usuario: ";
    cin >> telefone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Usuario user(nome, senha, dtaNascimento, email, telefone);
    return user;
}

void Admin::deletarUsuario(vector<Usuario> &Usuarios)
{
    string nome;
    int op;
    cout << "Digite o nome do Usuario que deseja deletar: ";
    getline(cin, nome);
    for (int i = 0; i < Usuarios.size(); i++)
    {
        if (Usuarios.at(i).nome == nome)
        {
            Usuarios.erase(Usuarios.begin() + i);
            cout << "Usuario deletado com sucesso!" << endl;
            return;
        }
    }
    cout << "Usuario nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (op == 1)
    {
        deletarUsuario(Usuarios);
    }
}

Livro Admin::novoLivro()
{
    string titulo;
    string autor;
    string editora;
    string publicacao;
    string isbn;
    cout << "Digite o titulo do Livro: ";
    getline(cin, titulo);
    cout << "Digite o autor do Livro: ";
    getline(cin, autor);
    cout << "Digite a editora do Livro: ";
    getline(cin, editora);
    cout << "Digite a data de publicacao do Livro: ";
    getline(cin, publicacao);
    cout << "Digite o ISBN do Livro: ";
    cin >> isbn;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Livro book(titulo, autor, editora, publicacao, isbn);
    return book;
}

void Admin::deletarLivro(vector<Livro> &Livros)
{
    string titulo;
    int op;
    cout << "Digite o titulo do Livro que deseja deletar: ";
    getline(cin, titulo);
    for (int i = 0; i < Livros.size(); i++)
    {
        if (Livros.at(i).titulo == titulo)
        {
            Livros.erase(Livros.begin() + i);
            cout << "Livro deletado com sucesso!" << endl;
            return;
        }
    }
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (op == 1)
    {
        deletarLivro(Livros);
    }
}

Chamada Admin::novoEmprestimo(vector<Livro> &Livros, vector<Usuario> &Usuarios, int livroID, int usuarioId)
{
    int dtaEmprestimo[3];
    cout << "Digite o dia de emprestimo: " << endl;
    cin >> dtaEmprestimo[0];
    cout << "Digite o mes de emprestimo: " << endl;
    cin >> dtaEmprestimo[1];
    cout << "Digite o ano de emprestimo: " << endl;
    cin >> dtaEmprestimo[2];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Chamada call(dtaEmprestimo, livroID, usuarioId);
    return call;
}