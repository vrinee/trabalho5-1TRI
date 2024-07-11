
#include <iostream>
#include <vector>

using namespace std;

class Livro{
    public:
        string titulo;
        string autor;
        string editora;

        Livro(string _titulo, string _autor, string _editora, string _publicacao, string _isbn);

        string getPublicacao();

        string getIsbn();

        void novoExemplar();

        int getExemplares();


        void deletarExemplar();

        bool checarDisponibilidade();

        void setId(vector<Livro> &Livros);
        
        int getId();
    
    private:
        string publicacao;
        string isbn;
        int exemplares;
        int id;

};
