#include <iostream>
#include <vector>
#include <string>
#include "classes/Admin.hpp"
#include "classes/Usuario.hpp"
#include "classes/Livro.hpp"
#include "classes/Chamada.hpp"
#include "classes/classFunc.hpp"
#include "interactUser.hpp"


using namespace std;


int main(){
    vector<Admin> Admins;
    vector<Usuario> Usuarios;
    vector<Livro> Livros;
    vector<Chamada> Chamadas;
    bool running = true;
    int AdminIndex = -1;

    Admins.push_back(createAdmin());

    while(running){
        if (AdminIndex == -1){
            AdminIndex = loginAdmin(Admins);
        }
        if (AdminIndex != -1){
            int op;
            int op2;
            string email;
            string nome;
            string titulo;
            string emailUser;
            string nomeUser;
            string tituloBook;
            int userIndex = -1;
            int ChamadaIndex = -1;
            int bookIndex = -1;
            cout << "1 - Cadastrar Usuario" << endl;
            cout << "2 - Cadastrar Livro" << endl;
            cout << "3 - Cadastrar Chamada" << endl;
            cout << "4 - Listar Usuarios" << endl;
            cout << "5 - Listar Livros" << endl;
            cout << "6 - Listar Chamadas" << endl;
            cout << "7 - Listar Admins" << endl;
            cout << "8 - Listar atributos de um Usuario" << endl;
            cout << "9 - Listar atributos de um Livro" << endl;
            cout << "10 - Listar atributos de uma Chamada" << endl;
            cout << "11 - Deletar exemplar de um Livro" << endl;
            cout << "12 - Deletar Usuario" << endl;
            cout << "13 - Deletar Livro" << endl;
            cout << "14 - Ações de Usuario" << endl;
            cout << "15 - Sair" << endl;
            cin >> op;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch(op){
                case 1:
                    createUser(Usuarios, Admins[AdminIndex]);
                    break;
                case 2:
                    createBook(Livros, Admins[AdminIndex]);
                    break;
                case 3:
                    createChamada(Chamadas, Usuarios, Livros, Admins[AdminIndex]);
                    break;
                case 4:
                    listarUsuarios(Usuarios);
                    break;
                case 5:
                    listarLivros(Livros);
                    break;
                case 6:
                    listarChamadas(Chamadas, Usuarios, Livros);
                    break;
                case 7:
                    listarAdmins(Admins);
                    break;
                case 8:
                    cout << "Digite o email do Usuario: ";
                    cin >> email;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Digite o nome do Usuario: ";
                    getline(cin, nome);
                    for(int i = 0; i < Usuarios.size(); i++){
                        if (Usuarios[i].getEmail() == email && Usuarios[i].nome == nome){
                            userIndex = i;
                            break;
                        }
                    }
                    if (userIndex != -1){
                        listarAtributosUser(Usuarios[userIndex], Chamadas);
                    } else {
                        cout << "Usuario não encontrado" << endl;
                    }

                    break;
                case 9:
                    cout << "Digite o titulo do Livro: ";
                    getline(cin, titulo);
                    for(int i = 0; i < Livros.size(); i++){
                        if (Livros[i].titulo == titulo){
                            bookIndex = i;
                            break;
                        }
                    }
                    if (bookIndex != -1){
                        listarAtributosLivro(Livros[bookIndex]);
                    } else {
                        cout << "Livro não encontrado" << endl;
                    }
                    
                    break;
                case 10:
                    cout << "Digite o email do Usuario: ";
                    cin >> emailUser;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Digite o nome do Usuario: ";
                    getline(cin, nomeUser);
                    cout << "Digite o titulo do Livro: ";
                    getline(cin, tituloBook);

                    for(int i = 0; i < Usuarios.size(); i++){
                        if (Usuarios[i].getEmail() == emailUser && Usuarios[i].nome == nomeUser){
                            userIndex = i;
                            break;
                        }
                    }

                    for(int i = 0; i < Livros.size(); i++){
                        if (Livros[i].titulo == tituloBook){
                            bookIndex = i;
                            break;
                        }
                    }

                    if (userIndex != -1 && bookIndex != -1){
                        for(int i = 0; i < Chamadas.size(); i++){
                            if (Chamadas[i].getIdUsuario() == Usuarios[userIndex].getId() && Chamadas[i].getIdLivro() == Livros[bookIndex].getId()){
                                ChamadaIndex = i;
                                break;
                            }
                        }
                        if (ChamadaIndex != -1){
                            listarAtributosChamada(Chamadas[ChamadaIndex], Usuarios, Livros);
                        } else {
                            cout << "Chamada não encontrada" << endl;
                        }
                    } else {
                        cout << "Usuario ou Livro não encontrado" << endl;
                    }

                    break;
                case 11:
                    cout << "Digite o titulo do Livro: ";
                    getline(cin, tituloBook);
                    for(int i = 0; i < Livros.size(); i++){
                        if (Livros[i].titulo == tituloBook){
                            bookIndex = i;
                            break;
                        }
                    }
                    if (bookIndex != -1){
                        retirarExemplar(Livros[bookIndex]);
                    } else {
                        cout << "Livro não encontrado" << endl;
                    }
                    
                    break;
                case 12:
                    Admins[AdminIndex].deletarUsuario(Usuarios);
                    break;
                case 13:
                    Admins[AdminIndex].deletarLivro(Livros);
                    break;
                case 14:
                    userActions(Usuarios, Livros, Chamadas);
                    break;
                case 15:
                    cout << "Deseja sair ou fazer outro login?(1 - sair 0 - fazer outro login)" << endl;
                    cin >> op2;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (op2 == 1){
                        running = false;
                    } else {
                        AdminIndex = -1;
                    }
                    break;
                default:
                    cout << "Opção invalida" << endl;
                    break;
            }
        }
        
    }
}