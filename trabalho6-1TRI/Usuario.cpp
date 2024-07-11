#include <iostream>
#include <vector>
#include <string>
#include "Chamada.hpp"
#include "Livro.hpp"
#include "Usuario.hpp"
#include "classFunc.hpp"

using namespace std;

Usuario::Usuario(string _nome, string _senha, int _dtaNascimento[3], string _email, string _telefone)
{
    nome = _nome;
    senha = _senha;
    dtaNascimento[0] = _dtaNascimento[0];
    dtaNascimento[1] = _dtaNascimento[1];
    dtaNascimento[2] = _dtaNascimento[2];
    email = _email;
    telefone = _telefone;
    multa = 0;
    status = true;
}

void Usuario::setNome(string _nome)
{
    nome = _nome;
}

string Usuario::getSenha()
{
    return senha;
}

void Usuario::setSenha(string _senha)
{
    senha = _senha;
}

int* Usuario::getDtaNascimento()
{
    return dtaNascimento;
}

void Usuario::setDtaNascimento(int _dtaNascimento[3])
{
    dtaNascimento[0] = _dtaNascimento[0];
    dtaNascimento[1] = _dtaNascimento[1];
    dtaNascimento[2] = _dtaNascimento[2];
}

string Usuario::getEmail()
{
    return email;
}

void Usuario::setEmail(string _email)
{
    email = _email;
}

string Usuario::getTelefone()
{
    return telefone;
}

void Usuario::setTelefone(string _telefone)
{
    telefone = _telefone;
}

float Usuario::getMulta(vector<Chamada> &Chamadas)
{
    checarMulta(Chamadas);
    return multa;
}

bool Usuario::getStatus()
{
    Usuario::checarStatus();
    return status;
}

void Usuario::checarStatus()
{
    if (multa > 50)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}

void Usuario::setId(vector<Usuario> &Usuarios)
{
    for (int i = 0; i < Usuarios.size(); i++)
    {
        if (Usuarios.at(i).getEmail() == email)
        {
            id = i;
        }
    }
}

int Usuario::getId()
{
    return id;
}

int Usuario::getEmprestimos()
{
    return emprestimos;
}

void Usuario::addEmprestimo()
{
    emprestimos++;
}

void Usuario::checarMulta(vector<Chamada> &Chamadas)
{
    int dtaAtual[3];
    int timesRan = 0;
    cout << "Digite o dia atual: ";
    cin >> dtaAtual[0];
    cout << "Digite o mes atual: ";
    cin >> dtaAtual[1];
    cout << "Digite o ano atual: ";
    cin >> dtaAtual[2];
    while (timesRan < emprestimos)
    {
        for (int i = 0; i < Chamadas.size(); i++)
        {
            if (Chamadas.at(i).getIdUsuario() == id)
            {
                if (Chamadas.at(i).getAtrasado())
                {
                    int dias = diasAte(Chamadas.at(i).getDtaVenc(), dtaAtual);

                    if (dias > 0)
                    {
                        multa += dias * 2;
                        Chamadas.at(i).setAtrasado();
                    }
                }
                timesRan++;
            }
        }
    }
}

void Usuario::pagarMulta(float valor, vector<Chamada> &Chamadas)
{
    checarMulta(Chamadas);
    multa -= valor;
}

void Usuario::devolverLivro(vector<Chamada> &Chamadas, vector<Livro> &Livros)
{
    string titulo;
    int diaAtual[3];
    int idLivro;
    int op;
    cout << "Digite o dia atual: ";
    cin >> diaAtual[0];
    cout << "Digite o mes atual: ";
    cin >> diaAtual[1];
    cout << "Digite o ano atual: ";
    cin >> diaAtual[2];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o titulo do Livro que deseja devolver: ";
    getline(cin, titulo);
    for (int i = 0; i < Livros.size(); i++)
    {
        if (Livros.at(i).titulo == titulo)
        {
            idLivro = i;
            break;
        }
    }
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (op == 1)
    {
        devolverLivro(Chamadas, Livros);
        return;
    }

    for (int i = 0; i < Chamadas.size(); i++)
    {
        if (Chamadas.at(i).getIdUsuario() == id and Chamadas.at(i).getIdLivro() == idLivro)
        {
            Chamadas.at(i).setStatus();
            int dias = diasAte(Chamadas.at(i).getDtaVenc(), diaAtual);
            if (dias > 0 and Chamadas.at(i).getAtrasado() == false)
            {
                multa += dias * 2;
                Chamadas.at(i).setAtrasado();
            }
            Livros.at(idLivro).novoExemplar();
            cout << "Livro devolvido com sucesso!" << endl;
            return;
        }
    }
}