#include <string>
#include <iostream>

using std::string;
using std::cout;

class Pessoa{
    protected:
        string nome;
    public:
        Pessoa(string nome){
            this->nome = nome;
        }    
};

class Professor:public virtual Pessoa{
    protected:
        int cpf;
    public:
        Professor(string nome, int cpf):Pessoa (nome){
            this->cpf = cpf;
        }

        string getNomeProf(){return nome_prof;}
        int getCpf(){return cpf;}
};

class Aluno:public virtual Pessoa{
    protected:
        int ra;
    public:
        Aluno(string nome, int ra):Pessoa (nome){
            this->ra = ra;
        }
        int getRa(){return ra;}
};

class ProfessorAluno: public Professor, public Aluno{
    private:
        int status; //1 = professor, 2 = aluno, 0 = nao ativo
    public:
        ProfessorAluno(string nome, int cpf, int ra) :Pessoa(nome),Professor(nome, cpf),Aluno(nome, ra){
            status = 0;
        }
        int getStatus(){return status;}
        void setStatus(int s){status = s;}
        void print(){     
            cout<<"\nNome: "<<Aluno::nome_aluno; //protected chama direto
            cout<<"\nCPF: "<<Professor::cpf;
            cout<<"\nRA: "<<ra<<"\n";
        }
};

int main(){
    ProfessorAluno p1("Joao", 111, 222);
    p1.setStatus(1);
    p1.print();
    return 0;
}