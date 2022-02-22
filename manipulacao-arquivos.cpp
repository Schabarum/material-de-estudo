#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// Funcoes
// Controles de menu
void Menu();
void DoPrincipal(int opcao);
void ReturnMenu();
// Inserção
void EscritaWrite();
void EscritaDiferente();
// Leitura
void LeituraRead();
void LeituraDiferente();
// Deletar
void LimparDados();
// Editar
void UsingTellandSeekforEdit();

int main(){
    Menu();
    // in     = input(leitura)
    // out    = output (escrita)
    // binary = modo binario
    // ate    = abre para escrita e posiciona o cursor no final
    // app    = append, abre para escrita sem deletar o conteúdo atual, posiciona no final
    // trunc  = truncate, abre para escrita e remove o conteúdo atual antes de abrir

    // write  = escrita no arquivo
    // read   = le o conteudo de determinada linha no arquivo
    
    // tellp  = Retorna a posição do ponteiro dentro do stream
    // seekp  = Define a posição do ponteiro dentro do stream
    
    // beg    = Constante para definir posição beg = Begin (Inicio)
    // cur    = Constante para definir posição cur = current (posição corrente)
    // end    = Constante para definir posição end (Final)
    return 0;
}

void EscritaWrite(){
    fstream arquivo;
    arquivo.open("Teste.txt",ios::out); // Irá abrir o arquivo, e cria-lo caso necessário
    if(arquivo.is_open()){ // Vai verificar se o arquivo está aberto
        arquivo.write("Digitar informacoes em um txt pode ser facil", 45);
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
    arquivo.close(); // Irá fechar o arquivo, liberando a memória após seu uso
    ReturnMenu();
}

void EscritaDiferente(){
    ofstream arquivo; 
    string palavra, dica;
    char opc = ' ';
    arquivo.open("Palavras.txt",ios::out|ios::app); // Cria o arquivo em modo escrita output, e 
    if (arquivo.is_open()){                         // vai posicionar o cursor no final da linha
        cout << "Digite uma palavra: ";
        cin >> palavra;
        cout << "Digite uma dica: ";
        cin >> dica;
        arquivo << palavra << ";" << dica << ";" << endl; // Vai inserir os valores das variaveis 
        cout << "Deseja continuar inserindo?[s/n]" << endl; // palavra e dica no arquivo txt
        cin >> opc;
        if (opc == 'n' or opc == 'N'){
            ReturnMenu();
        };
    }else{
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }arquivo.close();
    ReturnMenu();
}

void LeituraRead(){
    fstream arquivo;
    char linha[255];
    arquivo.open("Teste.txt",ios::in); // criação do arquivo em modo leitura
    if(arquivo.is_open()){
            arquivo.read(linha, 255); // passa tamanho e aonde vai armazenar
            cout << linha << endl; // vai imprimir a linha que foi armazenada na variavel 
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
    arquivo.close();
    ReturnMenu();
}

void LeituraDiferente(){
    ifstream arquivo;
    string linha;
    arquivo.open("Palavras.txt",ios::in);
    if (arquivo.is_open()){      
        while (getline(arquivo, linha)){
                cout << linha << endl;
        }
    }else{
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }arquivo.close();
    ReturnMenu();
}

void LimparDados(){
    fstream arquivo;
    arquivo.open("Palavras.txt",ios::out|ios::trunc);
    if (arquivo.is_open()){
        cout << "O arquivo Palavras.txt, foi limpo" << endl;
    }else{
        cout << "Não foi possivel abrir o arquivo!" << endl;
    }
    arquivo.close();
    ReturnMenu();
}

void UsingTellandSeekforEdit(){// edit
    long posicao;
    fstream arquivo;
    arquivo.open("Teste.txt",ios::out);
    if (arquivo.is_open()){
        arquivo.write("Estrutura de dados pode ser dificil", 35);
        posicao = arquivo.tellp(); // atribui a posição atual, a variavel posicao
        cout << "A posicao atual do cursor eh: "<< posicao << endl; 
        arquivo.seekp(posicao-7); // vai definir a posição do cursor
        posicao = arquivo.tellp(); // pega a posição denovo
        cout << "A posicao atual do cursor eh: "<< posicao << endl; 
        arquivo.write("foda",4); // irá alterar o conteudo do arquivo, a 
                                 // partir da posição atual e sobescrever seu conteudo
        arquivo.seekp(arquivo.end+3); // fim
        posicao=arquivo.tellp();
        cout << "A posicao atual do cursor eh: "<< posicao << endl; 
        
        arquivo.seekp(arquivo.beg+15); // inicial
        posicao=arquivo.tellp();
        cout << "A posicao atual do cursor eh: "<< posicao << endl; 
        
        arquivo.seekp(arquivo.cur+3); // corente
        posicao=arquivo.tellp();
        cout << "A posicao atual do cursor eh: "<< posicao << endl; 
       
        arquivo.close();
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
    ReturnMenu();
}

void Menu(){ // Menu 
    int opc;
    cout << "|--------------------------------------------------|" << endl;
    cout << "|                  Seja bem vindo                  |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    cout << "|1 - Escrita utilizando Write                      |" << endl;
    cout << "|2 - Escrita utilizando outro metodo               |" << endl;
    cout << "|3 - Listar utilizadno Read                        |" << endl;
    cout << "|4 - Listar utilizando outro metodo                |" << endl;
    cout << "|5 - Limpar dados do arquivo                       |" << endl;
    cout << "|6 - Editar dados utilizando o seekp e tellp       |" << endl;
    cout << "|7 - Sair/Fechar                                   |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    cout << "|             Informe a opcao desejada             |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    cin >> opc;
    DoPrincipal(opc);
}

void DoPrincipal(int opcao){ // Laço principal
    do{
        switch (opcao){
        case 1:     
            EscritaWrite();             
        break;
        case 2:     
            EscritaDiferente();         
        break;
        case 3:     
            LeituraRead();              
        break;  
        case 4:     
            LeituraDiferente();
        break;
        case 5:     
            LimparDados();              
        break;
        case 6:     
            UsingTellandSeekforEdit();  
        break;
        case 7:     
            cout << "Isso eh um adeus? '-_- " << endl;   
            exit(0);
        break;
        default:
            cout << "Opcao digitada invalida verifica se esta entre os digitos 1 e 7" << endl;
        break;
        }
    } while (opcao < 7);
}

void ReturnMenu(){ // Retorna para o menu
    char opc = ' ';
    system("pause");
    system("cls");
    cout << "Deseja retornar ao menu?[s/n]" << endl;
    cin >> opc;
    if (opc == 's' or opc == 'S'){
        system("cls");
        Menu();
    }else if (opc == 'n' or opc == 'N'){
        cout << "Isso eh um adeus? '-_- " << endl;
        exit(0);
    }
}