#include <iostream>
#include <vector>
#include <string>
#include "classes/Admin.hpp"
#include "classes/Usuario.hpp"
#include "classes/Livro.hpp"
#include "classes/Chamada.hpp"
#include "classes/classFunc.hpp"

using namespace std;

int loginAdmin(vector<Admin> &Admins){
    string name;
    string password;
    cout << "Digite o nome do Administrador: ";
    getline(cin, name);
    cout << "Digite a senha do Administrador: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < Admins.size(); i++){
        if (Admins[i].nome == name && Admins[i].getSenha() == password){
            return i;
        }
    }
    int op;
    cout << "Nome ou senha invalidos." << endl;
    cout << "Tentar novamente.(1 - sim 0 - não)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (op == 1){
        return loginAdmin(Admins);
    }
    return -1;

}

Admin createAdmin(){
    string name;
    string password;
    cout << "Digite o nome do Administrador: ";
    getline(cin, name);
    cout << "Digite a senha do Administrador: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Admin newAdmin(name, password);
    return newAdmin;
}

// funções de criação
    void createUser(vector<Usuario> &Usuarios, Admin &Admin){
        Usuarios.push_back(Admin.cadastrarUsuario());
        Usuarios[Usuarios.size() - 1].setId(Usuarios);   
    }

    int loginUser(vector<Usuario> &Usuarios){
        string email;
        string password;
        cout << "Digite o email do Usuario: ";
        getline(cin, email);
        cout << "Digite a senha do Usuario: ";
        cin >> password;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < Usuarios.size(); i++){
            if (Usuarios[i].getEmail() == email && Usuarios[i].getSenha() == password){
                return i;
            }
        }
        int op;
        cout << "Email ou senha invalidos." << endl;
        cout << "Tentar novamente.(1 - sim 0 - não)" << endl;
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (op == 1){
            return loginUser(Usuarios);
        }
        return -1;
    }

    void createBook(vector<Livro> &Livros, Admin &Admin){
        Livros.push_back(Admin.novoLivro());
        Livros[Livros.size() - 1].setId(Livros);
    }

    void createChamada(vector<Chamada> &Chamadas,vector<Usuario> &Usuarios, vector<Livro> &Livros, Admin &Admin){
        string titulo;
        string nome;
        int op;
        cout << "Digite o titulo do Livro que deseja emprestar: ";
        getline(cin, titulo);
        cout << "Digite o nome do Usuario que deseja emprestar o Livro: ";
        getline(cin, nome);
        for (int i = 0; i < Livros.size(); i++)
        {
            if (Livros.at(i).titulo == titulo)
            {
                for (int j = 0; j < Usuarios.size(); j++)
                {
                    if (Usuarios.at(j).nome == nome)
                    {
                        if (Livros.at(i).checarDisponibilidade())
                        {
                            cout << "Livro disponivel!" << endl;
                            Livros.at(i).deletarExemplar();
                            Chamadas.push_back(Admin.novoEmprestimo(Livros, Usuarios, i, j));
                            Usuarios.at(j).addEmprestimo();
                            return;
                        }
                        else
                        {
                            cout << "Livro nao disponivel!" << endl;
                            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
                            cin >> op;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (op == 1)
                            {
                                createChamada(Chamadas,Usuarios,Livros,Admin);
                            }
                        }
                    }
                }
                cout << "Usuario nao encontrado!" << endl;
                cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
                cin >> op;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (op == 1)
                {
                    createChamada(Chamadas, Usuarios, Livros, Admin);
                }
                return;
            }
        }
        cout << "Livro nao encontrado!" << endl;
        cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (op == 1)
        {
            createChamada(Chamadas, Usuarios, Livros, Admin);
        }
    }
// Fim das funções de criação

// Funções de listagem
    void listarUsuarios(vector<Usuario> &Usuarios){
        for (int i = 0; i < Usuarios.size(); i++){
            cout << "ID: " << Usuarios[i].getId() << " Nome: " << Usuarios[i].nome << " Email: " << Usuarios[i].getEmail() << endl;
        }
    }

    void listarAtributosUser(Usuario user, vector<Chamada> &Chamadas){
        cout << "ID: " << user.getId() << endl;
        cout << "Nome: " << user.nome << endl;
        cout << "Email: " << user.getEmail() << endl;
        cout << "Data de nascimento: " << user.getDtaNascimento() << endl;
        cout << "Telefone: " << user.getTelefone() << endl;
        cout << "Multas: " << user.getMulta(Chamadas) << endl;
        if(user.getStatus() == 1){
            cout << "Status: Ativo" << endl;
        }else{
            cout << "Status: Bloqueado" << endl;
        }
        cout << "Livros alugados: " << user.getEmprestimos() << endl;
    }

    void listarAdmins(vector<Admin> &Admins){
        for (int i = 0; i < Admins.size(); i++){
            cout << "Nome: " << Admins[i].nome << endl;
        }
    }

    void listarLivros(vector<Livro> &Livros){
        for (int i = 0; i < Livros.size(); i++){
            cout << "ID: " << Livros[i].getId() << " Nome: " << Livros[i].titulo << " Autor: " << Livros[i].autor << " Isbn: " << Livros[i].getIsbn() << endl;
        }
    }

    void listarAtributosLivro(Livro book){
        cout << "ID: " << book.getId() << endl;
        cout << "Titulo: " << book.titulo << endl;
        cout << "Autor: " << book.autor << endl;
        cout << "Editora: " << book.editora << endl;
        cout << "Isbn: " << book.getIsbn() << endl;
        cout << "Publicação: " << book.getPublicacao() << endl;
        cout << "Exemplares disponiveis: " << book.getExemplares() << endl;
    }

    void listarChamadas(vector<Chamada> &Chamadas, vector<Usuario> &Usuarios, vector<Livro> &Livros){
        for (int i = 0; i < Chamadas.size(); i++){
            cout << "ID:" << i << " Usuario: " << Usuarios[Chamadas[i].getIdUsuario()].nome << " Livro: " << Livros[Chamadas[i].getIdLivro()].titulo << " Data de emprestimo: " << Chamadas[i].getDtaEmprestimo() << endl;
        }
    }

    void listarAtributosChamada(Chamada call, vector<Usuario> &Usuarios, vector<Livro> &Livros){
        cout << "ID: " << call.getId() << endl;
        cout << "Usuario: " << Usuarios[call.getIdUsuario()].nome << endl;
        cout << "Livro: " << Livros[call.getIdLivro()].titulo << endl;
        cout << "Data de emprestimo: " << call.getDtaEmprestimo() << endl;
        cout << "Data de vencimento: " << call.getDtaVenc() << endl;
        if (call.getStatus() == 1){
            cout << "Status: Ativo" << endl;
        }else{
            cout << "Status: Encerrado" << endl;
        }
        if (call.getAtrasado() == 1){
            cout << "Atrasado: Sim" << endl;
        }else{
            cout << "Atrasado: Não" << endl;
        }
    }
// Fim das funções de listagem

// Funções de ação

    void pagamento(Usuario &user, vector<Chamada> &Chamadas){
        float multa = user.getMulta(Chamadas);
        if (multa == 0){
            cout << "Não há multas a serem pagas." << endl;
            return;
        }
        float valor;
        cout << "O valor da multa é de: " << multa << endl;
        cout << "Digite o valor a ser pago: ";
        cin >> valor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        user.pagarMulta(valor,Chamadas);
    }

    void devolucao(Usuario &user, vector<Livro> &Livros, vector<Chamada> &Chamadas){
        int op;
        int qnt;
        cout << "Quantas devoluções deseja fazer?" << endl;
        cin >> qnt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < qnt; i++){
            user.devolverLivro(Chamadas, Livros);
        }
        cout << "Deseja pagar a multa?(1 - sim 0 - não)" << endl;
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (op == 1){
            pagamento(user, Chamadas);
        }

    }

    void mudarAtributosUser(Usuario &user){
        int op;
        int dta[3];
        string placeholder;
        cout << "O que deseja alterar?" << endl;
        cout << "1 - Nome" << endl;
        cout << "2 - Email" << endl;
        cout << "3 - Data de nascimento" << endl;
        cout << "4 - Telefone" << endl;
        cout << "5 - Senha" << endl;
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (op){
            case 1:
                cout << "Digite o novo nome: ";
                getline(cin, placeholder);
                user.nome = placeholder;
                break;
            case 2:
                cout << "Digite o novo email: ";
                getline(cin, placeholder);
                user.setEmail(placeholder);
                break;
            case 3:
                cout << "Digite o dia de nascimento: ";
                cin >> dta[0];
                cout << "Digite o mes de nascimento: ";
                cin >> dta[1];
                cout << "Digite o ano de nascimento: ";
                cin >> dta[2];
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                user.setDtaNascimento(dta);
                break;
            case 4:
                cout << "Digite o novo telefone: ";
                getline(cin, placeholder);
                user.setTelefone(placeholder);
                break;
            case 5:
                cout << "Digite a nova senha: ";
                cin >> placeholder;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                user.setSenha(placeholder);
                break;
            default:
                cout << "Opção invalida." << endl;
                cout << "Tentar novamente?(1 - sim 0 - não)" << endl;
                cin >> op;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (op == 1){
                    mudarAtributosUser(user);
                }
                break;
        }
    }

    void retirarExemplar(Livro &book){
        book.deletarExemplar();
    }

    void checarMulta(vector<Chamada> &Chamadas, Usuario &user){
        float multa = user.getMulta(Chamadas);
        if (multa == 0){
            cout << "Não há multas a serem pagas." << endl;
        }else{
            cout << "O valor da multa é de: " << multa << endl;
        }
    }

    void userActions(vector<Usuario> &Usuarios, vector<Livro> &Livros, vector<Chamada> &Chamadas){
        int op;
        int userIndex = loginUser(Usuarios);
        bool running = true;
        while(running){
            cout << "1 - Devolver Livro" << endl;
            cout << "2 - Pagar multa" << endl;
            cout << "3 - Checar multa" << endl;
            cout << "4 - Mudar atributos" << endl;
            cout << "5 - Sair" << endl;
            cin >> op;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (op){
                case 1:
                    devolucao(Usuarios[userIndex], Livros, Chamadas);
                    break;
                case 2:
                    pagamento(Usuarios[userIndex], Chamadas);
                    break;
                case 3:
                    checarMulta(Chamadas, Usuarios[userIndex]);
                    break;
                case 4:
                    mudarAtributosUser(Usuarios[userIndex]);
                    break;
                case 5:
                    running = false;
                    break;
                default:
                    cout << "Opção invalida." << endl;
                    break;
            }
        }
    }