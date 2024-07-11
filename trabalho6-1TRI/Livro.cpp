#include <iostream>
#include <vector>
#include "Livro.hpp"

using namespace std;

Livro::Livro(string _titulo, string _autor, string _editora, string _publicacao, string _isbn){
    titulo = _titulo;
    autor = _autor;
    editora = _editora;
    publicacao = _publicacao;
    isbn = _isbn;
    exemplares = 1;
    id = -1;
}

string Livro::getPublicacao(){
    return publicacao;
}

string Livro::getIsbn(){
    return isbn;
}

void Livro::novoExemplar(){
    exemplares++;
}

int Livro::getExemplares(){
    return exemplares;
}

void Livro::deletarExemplar(){
    exemplares--;
}

bool Livro::checarDisponibilidade(){
    if(exemplares > 0){
        return true;
    }else{
        return false;
    }
}

void Livro::setId(vector<Livro> &Livros){
    for (int i = 0; i < Livros.size(); i++){
        if(Livros.at(i).getIsbn() == isbn){
            id = i;
        }
    }
}
        
int Livro::getId(){
    return id;
}