#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>

#define RESET   "\033[0m"
#define VERDE   "\033[32m"
#define VERMELHO "\033[31m"
#define AZUL    "\033[34m"
#define ROSA    "\033[95m"
#define ROXO "\033[35m"
#define AMARELO  "\033[33m"
#define LARANJA  "\033[38;5;208m"
#define CINZA "\033[90m"
#define CIANO "\033[1;36m"
#define OURO "\033[1;33m"

//Itens para o Vetor dinamico
char *hospedes = NULL;
int tamHospedes = 0;

bool morrer = 0;
int Thuman=0;//total de humanos
int Entrou=0;//Total de humanos q entraram
//ERRO=humano-entrou

void limpar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Função de escrever o texto
void type_text(const char *text, int speed) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(speed);
    }
}

void history(){
    printf(VERMELHO);
   type_text("\n+~~~~~~~~+~~~~~~~~+~~~~~~~~+~~~~~~~~+~~~~~~~~+\n",25000);
    type_text("| \tD O N T  L E T  T H E M  I N \t     |",300000);
    type_text("\n+~~~~~~~~+~~~~~~~~+~~~~~~~~+~~~~~~~~+~~~~~~~~+\n",25000);
    printf(RESET);
    sleep(1 );
    printf("\nPressione ENTER para começar ");
    getchar();
    sleep(2);
    printf("\n");
   
    // 3 de maio
    printf(AMARELO "3 de maio de 2029\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("NASA detecta um objeto espacial se aproximando da Terra.", 30000);
    printf("\n");
    printf("\n");
    sleep(1);
   
    // 7 de maio
    printf(AMARELO "7 de maio de 2029\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Especialistas afirmam que o objeto deve cair no oceano.", 30000);
    printf("\n");
    printf("\n");
    sleep(1);
   
    // 12 de maio
    printf(AMARELO "12 de maio de 2029\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Nova rota indica a possivel passagem proxima a Indonesia.", 35000);
    printf("\n");
    printf("\n");
    sleep(1);

    // 15 de maio
    printf(AMARELO "15 de maio de 2029\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Sensores registram vibracoes incomuns no vulcao Anak Krakatau.", 80000);
    printf("\n");
    printf("\n");

    // Impacto
    printf(VERMELHO "17 de maio de 2029 — 02:41\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Um meteoro entra na atmosfera e é visto em varios paises.", 80000);
    printf("\n");
    printf("\n");

    printf(VERMELHO "17 de maio de 2029 — 02:43\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Fragmento atinge a ilha do Anak Krakatau.\n", 90000);
    printf(AZUL "TV: " RESET);
    type_text("O impacto ativa o vulcao inesperadamente.  ", 90000);
    printf("\n");
    printf("\n");

    // Escuridao
    printf(CINZA "17 de maio de 2029 — 09:57\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Cinzas vulcanicas cobrem o ceu.\n", 90000);
    printf(AZUL "TV: " RESET);
    type_text("Os cientistas estipularam que toda fumaca ira se dissolver totalmente no ar em tres dias. ", 70000);
    printf("\n");
    printf("\n");

    // Inicio do fim
    printf(AMARELO "17 de maio de 2029 - 17:39\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Pessoas aparentemente normais entram em colapso sob a escuridao total. \n", 70000);

    // Revelacao
    printf(VERMELHO "\n\nALERTA MUNDIAL\n\n\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("Autoridades confirmam a existencia de seres disfarcados de humanos. \n", 60000);
    printf(AZUL "TV: " RESET);
    type_text("Esses seres nao sobrevivem a luz do Sol.\n", 60000);
    printf(AZUL "TV: " RESET);
    type_text("Durante anos, eles viveram escondidos se protegendo da luz solar. ", 60000);
    printf("\n");
    printf("\n");

    // Final
    printf(AMARELO "18 de maio de 2029 - 00:26\n" RESET);
    printf(AZUL "TV: " RESET);
    type_text("!!! ALERTA !!!\n", 150000);
    printf(AZUL "TV: " RESET);
    type_text("FIQUEM EM CASA!\n", 120000);
    printf(AZUL "TV: " RESET);
    type_text("Esses seres mostram caracteristicas suspeitas, como seus dentes perfeitos, \nolhos alterados, pele anormal, temperatura baixa  e cheiro forte... \nCuidado se encontrar alguem que tenha a maioria desses indicios \n", 60000);
    printf("\n");
    printf("\n");
}

// enter depois da historia
void enter_Dps_Hist(){
   
    printf(CINZA "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" RESET);
    type_text("    Voce nao pode desistir.            \n", 50000);
    type_text("    Seu trabalho eh selecionar os abrigados no bunker de protecao ao apocalise!!!\n", 30000);
    type_text("    Se abrir a porta, nao ha volta...        \n", 30000);
   
    printf(CINZA "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" RESET);
   
    printf(VERMELHO);
    type_text("\nPressione ENTER para comecar.\n",40000);
    getchar();

}


//vetor dinamico pra pessoas dentro da casa
void addHospedes(const char *nome) {
    int len = strlen(nome);

    // remove ": " do final, se existir
    if (len >= 2 && nome[len-2] == ':' && nome[len-1] == ' ') {
        len -= 2;
    }

    char *tmp = (char *) realloc(hospedes, (tamHospedes + len + 2) * sizeof(char));
    if (tmp == NULL) return;

    hospedes = tmp;

    memcpy(hospedes + tamHospedes, nome, len);
    tamHospedes += len;

    hospedes[tamHospedes++] = '\n';
    hospedes[tamHospedes] = '\0';
}
void mostrarHospedes() {
    if (!hospedes) {
        printf("\nVoce esta sozinho\n");
        return;
    }

    printf(VERDE "\nPessoas na casa:\n" RESET);
    printf("%s", hospedes);
    printf("\n");
}

void final_gameover() {
    sleep(2);
    limpar();
    printf(VERMELHO);
    type_text("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n", 20000);
    printf("|            FINAL: MORTE                        |\n");
    type_text("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n", 20000);
    printf(RESET);

    type_text("Voce abriu a porta.\n", 70000);
    sleep(1);
    type_text("A escuridao entrou com eles.\n\n", 80000);
    sleep(1);
    type_text("Nao houve luta.\n", 90000);
    type_text("Nao houve escolha.\n\n", 90000);
    printf(VERMELHO);
    if(Entrou==0){type_text("Voce nao sobreviveu ao apocalipse.\n", 120000);
    }else{type_text("Voce e todos que deixou entrar nao sobreviveram ao apocalipse\n", 120000); }  
    printf(RESET);

    sleep(3);
}

void final_salvador() {
    sleep(2);
    limpar();
   
    printf(OURO);
    type_text("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n", 20000);
    printf("|              FINAL: SALVADOR                   |\n");
    type_text("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n", 20000);
    printf(RESET);

   
    type_text("Voce escolheu confiar.\n", 70000);
    sleep(1);
    type_text("Mesmo quando o medo gritava mais alto.\n\n", 80000);
    type_text("Ao amanhecer, a luz voltou.\n\n", 90000);
    sleep(1);
    printf(VERDE);
    type_text("Todos os necessitados foram salvos...\n", 90000);
    type_text("porque voce decidiu nao fechar os olhos.\n", 100000);
    printf(RESET);
    sleep(3);
}

void final_egoista() {
    sleep(2);
    limpar();

    printf(CINZA);
    type_text("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n", 20000);
    printf("|             FINAL: SOLIDAO                     |\n");
    type_text("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n", 20000);
    printf(RESET);


    type_text("Voce sobreviveu.\n", 80000);
    sleep(1);
    type_text("Sozinho.\n\n", 100000);
    type_text("Do lado de fora, gritos cessaram.\n", 90000);
    sleep(1);
    type_text("Do lado de dentro, o silencio ficou.\n\n", 90000);
    printf(CINZA);
    type_text("Nao havia mais ninguem para salvar.\n", 100000);
    printf(RESET);
    sleep(3);
}

void final_desconfiado() {
    sleep(2);
    limpar();
   
    printf(ROXO);
    type_text("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n", 20000);
    printf("|          FINAL: DESCONFIANCA                   |\n");
    type_text("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n", 20000);
    printf(RESET);


    type_text("Voce tentou acertar.\n", 70000);
    sleep(1);
    type_text("Mas o medo guiou suas escolhas.\n\n", 80000);
    type_text("Alguns viveram.\n", 90000);
    type_text("Outros nao tiveram essa chance.\n\n", 90000);
    printf(ROXO);
    type_text("O apocalipse chegou ao fim.\n", 90000);
    printf(RESET);
    sleep(3);
}
void final_humano() {
    sleep(2);
    limpar();
   
    printf(CIANO);
    type_text("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n", 20000);
    printf("|                FINAL: HUMANO                   |\n");
    type_text("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n", 20000);
    printf(RESET);

    type_text("Voce estendeu a mao para muitos.\n", 70000);
    sleep(1);
    type_text("Mas o destino e cruel e nao permite herois perfeitos.\n\n", 80000);
   
    type_text("O peso das perdas ainda machuca...\n", 90000);
    sleep(1);
    type_text("Mas o som das vozes ao seu redor prova que valeu a pena.\n\n", 90000);
   
    printf(CIANO);
    type_text("Voce nao salvou o mundo inteiro.\n", 100000);
    type_text("Mas salvou o mundo de quem sobreviveu ao seu lado.\n", 110000);
    printf(RESET);
   
    sleep(3);
}

void Final() {
    if (morrer) {
        final_gameover();
    } else if (Entrou == Thuman) {
        final_salvador();
    } else if (Entrou == 0) {
        final_egoista();
    } else if (Entrou < 0.7 * Thuman) {
        final_desconfiado();
    } else {
        final_humano();
    }
}


// [1] Estrutura do nó e da fila
typedef struct Suspeito {
    bool human;//1 humano; 0 n humano
    char Inf[2][170]; //Informações adicionais
    char Name[30]; //Como sera chamado;
    char Desc[300]; //Descricao
    char Falas[3][140]; // Falas
    char Resp[5][140]; //Resposta
    bool carac[5]; //Caracteristicas
    struct Suspeito* prox;
} Suspeito;

typedef struct {
    Suspeito* inicio;
    Suspeito* fim;
    int quant;
} Fila;

// [1] Inicializa a fila
void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->quant = 0;
}

// [1] Verifica se a fila está vazia
int filaVazia(Fila* f) {
    return (f->inicio == NULL);
}

// [1] Adicionar elemento ao final da fila (Enqueue)
void inserir(Fila* f, bool human, const char Inf[2][170], const char Name[30],const char Desc[140], const char Falas[3][140], const char Resp[5][140], const bool carac[5]) {
    Suspeito* novo = (Suspeito*)malloc(sizeof(Suspeito));
    if (novo == NULL) return;
   
    novo->human=human;
    strcpy(novo->Desc,Desc);
    strcpy(novo->Name,Name);
    strcpy(novo->Inf[0],Inf[0]);
    strcpy(novo->Inf[1],Inf[1]);
    for(int i=0;i<3;i++){
        strcpy(novo->Falas[i],Falas[i]);
    }
    for(int i=0;i<5;i++){
        novo->carac[i]=carac[i];
        strcpy(novo->Resp[i],Resp[i]);
    }
   
    novo->prox = NULL;
   
    if (filaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->quant++;
}


// [1] Tamanho da fila
int tamanhoFila(Fila* f) {
    return f->quant;
}

// [1] Destruição da fila
void destruirFila(Fila* f) {
    Suspeito* atual = f->inicio;
    while (atual != NULL) {
        Suspeito* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->quant = 0;
}
void analisar(Fila* f, int num, bool verif[5]) {
    if (filaVazia(f)) return;

   
    verif[num]=0;
    printf("\n");
    //printf(AZUL "Analise:\n" RESET);
    switch(num){
        case 0: //dentes
            if (f->inicio->carac[num]) {
                printf(VERMELHO " Os dentes estao perfeitos\n" RESET);
            } else {
                printf(VERDE " Os dentes sao imperfeitos\n" RESET);
            }
            break;
        case 1: //pele
            if (f->inicio->carac[num]) {
                printf(VERMELHO " A pele esta diferente\n" RESET);
            } else {
                printf(VERDE " A pele esta normal\n" RESET);
            }
            break;
        case 2: //olhos
            if (f->inicio->carac[num]) {
                printf(VERMELHO "Os olhos estao avermelhados\n" RESET);
            } else {
                printf(VERDE "Os olhos estao normais\n" RESET);
            }
            break;
        case 3: //temperatura
            if (f->inicio->carac[num]) {
                printf(VERMELHO " A temperatura corporal esta baixa\n" RESET);
            } else {
                printf(VERDE " A temperatura corporal nao esta baixa\n" RESET);
            }
            break;
        case 4: //cheiro
            if (f->inicio->carac[num]) {
                printf(VERMELHO " Ha um cheiro muito ruim no ar\n" RESET);
            } else {
                printf(VERDE " Nao ha nenhum cheiro incomum\n" RESET);
            }
            break;

    }
    sleep(1);
    printf(LARANJA "%s" RESET,f->inicio->Name);
    type_text(f->inicio->Resp[num], 50000);
    sleep(1);
}


int submenu(bool c[5]) {
    int op;
   
    printf("\n");
    printf(ROXO "------ ANALISAR SUSPEITO ------\n" RESET);
    c[0]&&printf(" 1 - Abre a boca para eu ver os seus dentes\n");
    c[1]&&printf(" 2 - Analisar a pele\n");
    c[2]&&printf(" 3 - Me mostre seus olhos\n");
    c[3]&&printf(" 4 - Vou verificar sua temperatura\n");
    c[4]&&printf(" 5 - Sentir melhor o cheiro\n");
    printf(" 6 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);

    return op;
}


void menu(Fila* s) {
    int op;
    bool verif[5];
    for(int i=0;i<5;i++){verif[i]=1;}
    int ji=0;
    bool temp=1;
    do {
        printf("\n");
        printf(VERDE "ESCOLHA\n" RESET);
        printf(" 1 - Mandar embora\n");
        printf(" 2 - Deixar entrar\n");
        printf(" 3 - Analisar\n");
        ji < 2 && printf(" 4 - Pedir mais informação");
        ji == 1 && printf(" de novo");
        printf("\nR: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                //executar fala 1
                printf(LARANJA "%s" RESET,s->inicio->Name);
                type_text(s->inicio->Falas[1],20000);
                sleep(1);
                printf(VERMELHO "\nVoce mandou embora.\n" RESET);
                temp=0;
                break;

            case 2:
                //executar fala 2
                printf(LARANJA "%s" RESET,s->inicio->Name);
                type_text(s->inicio->Falas[2],30000);
                sleep(1);
                printf(VERDE "\nVoce deixou  entrar.\n" RESET);
                if(s->inicio->human){
                    Entrou++;
                    addHospedes(s->inicio->Name);
                }else{
                    morrer=1;
                    destruirFila(s);
                    return;//tenta fechar o jogo
                }
               
                temp=0;
                break;

            case 3: {
                int sub;
                do {
                    sub = submenu(verif);
                    if (sub >= 1 && sub <= 5 && verif[sub-1]) {
                        analisar(s, sub - 1, verif);
                    }else{
                        sub!=6&&printf(VERMELHO "Opcao invalida!\n" RESET);
                    }
                } while (sub != 6);
                break;
   }
            case 4:
                if(ji == 2){
                    printf("Opcao invalida!\n");
                    break;}
                printf(LARANJA "%s" RESET,s->inicio->Name);
                type_text(s->inicio->Inf[ji],65000);
                ji++;
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (temp);

}

void removerPrimeiro(Fila* f) {
    if (filaVazia(f)) return; // fila vazia, nada a remover

    Suspeito* temp = f->inicio; // guarda o primeiro
    f->inicio = f->inicio->prox; // move o início para o próximo

    if (f->inicio == NULL) { // se a fila ficou vazia
        f->fim = NULL;
    }

    free(temp); // libera memória
    f->quant--; // atualiza contador
}

// Acessa o primeiro elemento da fila
bool acessarPrimeiro(Fila* f) {
    if (!filaVazia(f)) {
        //Caixa de dialogos
        sleep(1);
        printf("\n");
        if(rand()%2){printf("Toc Toc\n");
        }else{printf("TOC TOC\n");}
        printf("\n");
        printf("%s",f->inicio->Desc);
        f->inicio->human&&Thuman++;
        printf("\n");
        sleep(2);
        printf(LARANJA "%s" RESET,f->inicio->Name);
        type_text(f->inicio->Falas[0],70000);
        sleep(1);
        //Menu
        menu(f);
        removerPrimeiro(f);
        return 1;
    }
    //tds suspeitos analizados
     // Ou tratamento de erro
     printf(CINZA "\n==Acho q ninguem mais vira essa noite==\n" RESET);
     return 0;
}



int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
   
    history();
    char opcao = 'S';
   
    while(opcao == 'S'){
        hospedes = NULL;
        tamHospedes = 0;
       
        morrer = 0;
        Thuman=0;//total de humanos
        Entrou=0;
   
    enter_Dps_Hist();
   
    Fila s;
    inicializarFila(&s);
   
    bool human;//1 humano; 0 n humano
    char Inf[2][170];
    char Name[30];
    char Desc[140];
    char Falas[3][140];
    char Resp[5][140]; //Resposta
    bool carac[5];
   
    //Suspeito 1D1:
        human=1;//humano
        strcpy(Inf[0],"Meu nome e Joao Carlos, eu morava perto daqui ate meu bairro ser atacado por essas coisas, so preciso de um lugar pra ficar\n");
        strcpy(Inf[1],"Ja falei tudo o que tinha pra falar, vai me deixar entrar ou nao?\n");
        strcpy(Name,"Homem Pálido: ");//Sem ( /n ) Com (: )
        strcpy(Desc,"Um homem, alto, palido e de cara fechada que esta na porta\n");
        if(rand() % 2){strcpy(Falas[0],"Eai, preciso de um lugar pra ficar, me deixa entrar?\n");
        }else{strcpy(Falas[0],"Eai, me deixa entrar?\n");}
        strcpy(Falas[1],"Vai se arrepender de nao me deixar entrar\n");
        strcpy(Falas[2],"Obrigado por me deixar ficar\n");
       
        //Dentes perfeitos
        carac[0]=0;strcpy(Resp[0],"Nao escovava muito os dentes quando era criança\n");
       
        //pele quebradiça
        carac[1]=0;strcpy(Resp[1],"Minha pele é completamente normal\n");
       
        //olhos avermelhados
        carac[2]=1;strcpy(Resp[2],"Meus olhos estao vermelhos porque dormi mal essa noite, por causa de tudo\n");
       
        //temperatura
        if(rand() % 2){carac[3]=1;strcpy(Resp[3],"Voce esta ficando paronoico, desde criança meu corpo é mais frio que o normal\n");
        }else{carac[3]=0;strcpy(Resp[3],"Como esperado, tudo normal\n");}
       
        //cheiro
        carac[4]=0;strcpy(Resp[4],"Nao tem nada de incomum com meu cheiro como pode ver\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);

    //Suspeito 2D1
        human=1;//humano
        if(rand() % 2){strcpy(Inf[0],"Oi, meu nome é Ellie, estou perdida e preciso de um abrigo\n");
        }else{strcpy(Inf[0],"Oi, meu nome é Ellie, eu me separei do meu pai nessa confusao toda e preciso de um lugar pra ficar\n");}
        strcpy(Inf[1],"Por favor, me deixa entrar. Por acaso, voce viu o meu pai?\n");
        strcpy(Name,"Menina pequena: ");
        strcpy(Desc,"Uma criança na porta, ela é tão nova, por que ela está sozinha?\n");
        strcpy(Falas[0],"Oi, voce pode me deixar entrar? Estou com medo\n");
        strcpy(Falas[1],"Voce não tem coração? Vai me deixar sozinha aqui fora? \n");
        strcpy(Falas[2],"Muito obrigada, quer brincar mais tarde?\n");
       
        //Dentes ruins
        carac[0]=0;strcpy(Resp[0],"Acho chato escovar os dentes\n");
       
        //pele com marcas
        carac[1]=1;strcpy(Resp[1],"Essa cicatriz.. foi um acidente\n");
       
        //olhos perfeitos
        if(rand() % 2){carac[2]=0;strcpy(Resp[2],"Eu tenho dois olhos, isso não é o normal?\n");
        }else{carac[2]=1;strcpy(Resp[2],"Estao vermelhos porque estou chorando, nao esta vendo?\n");}
       
        //temperatura ok
        carac[3]=0;strcpy(Resp[3],"Não entendi, eu não estou com febre dã\n");
       
        //cheiro ruim
        carac[4]=1;strcpy(Resp[4],"Não tive tempo para tomar banho..\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);

    //Suspeito3D1:
        human=0; //nao humano (Criança monstro)
        strcpy(Inf[0],"Tio... eu me perdi da mamãe e do papai...\n");
        if(rand() % 2){strcpy(Inf[1],"Deixa eu entrar... esta escuro aqui fora...\n");
        }else{strcpy(Inf[1],"Eu prometo que sou bonzinho, abre a porta...\n");}
        strcpy(Name,"Garoto com boneco: ");
        strcpy(Desc,"Um menino pequeno segurando um boneco de pano que parece ter sido rasgado\n");
        strcpy(Falas[0],"Oi... voce pode ser meu novo papai?\n");
        strcpy(Falas[1],"VOCE E MAU! TODOS VOCES SAO MAUS!\n");
        strcpy(Falas[2],"Oba... agora vamos brincar de esconde-esconde no escuro.\n");
       
        carac[0]=1;strcpy(Resp[0],"O fada do dente me deu dentes novos e fortes...\n");
       
        carac[1]=1;strcpy(Resp[1],"Eu estou com medo, por isso estou branquelo...\n");
       
        if(rand() % 2){carac[2]=1;strcpy(Resp[2],"Esta muito escuro, meus olhos ficam grandes pra te ver melhor\n");
        }else{carac[2]=0;strcpy(Resp[2],"Meus olhos doem com a luz da sua lanterna...\n");}
       
        if(rand() % 2){carac[3]=1;strcpy(Resp[3],"O frio doi... me aquece la dentro?\n");
        }else{carac[3]=1;strcpy(Resp[3],"Eu amo o frio e voce?\n");}
       
        carac[4]=1;strcpy(Resp[4],"Eu estava brincando na terra antes de tudo ficar preto...\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
       
    printf(AMARELO "\nDIA 1: 18 de maio de 2029 - 04:15\n" RESET);
    printf(AZUL "TV (Plantão de Emergência): " RESET);
    type_text("PROTOCOLO DE SEGURANÇA NACIONAL: O inimigo mimetiza traços humanos. \n", 60000);
    printf(AZUL "TV (Plantão de Emergência): " RESET);
    type_text("Mantenha vigilância absoluta sobre qualquer indivíduo próximo. \n", 60000);
    printf(AZUL "TV (Plantão de Emergência): " RESET);
    type_text("O perigo pode estar ao seu lado sob uma face familiar.\n", 60000);
   
    while(acessarPrimeiro(&s))
    sleep(1);
    mostrarHospedes();
    sleep(2);

    if(!morrer){

    //fim do dia 1
   
    //Suspeito 1D2
if(rand() % 2){
human=0;//n humano
        strcpy(Inf[0],"Meu nome é Vivian, sou dona do mercadinho da rua de cima, minha casa pegou fogo por causa daquelas coisas e preciso de um lugar...\n");
        if(rand() % 2){strcpy(Inf[1],"Ainda tenho alguns suprimentos do meu mercado, se me deixar entrar, eu te dou tudo\n");
        }else{strcpy(Inf[1],"Nao tenho nada aqui, se tivesse eu te daria tudo\n");}
        strcpy(Name,"Mulher cinzenta: ");//Sem ( /n ) Com (: )
        strcpy(Desc,"Agora quem esta na porta é uma mulher com aparencia suja e cansada, sua roupa parece estar com cinzas\n");
        strcpy(Falas[0],"Socorro... por favor, me deixe entrar...\n");
        if(rand() % 2){strcpy(Falas[1],"Não vai sobreviver por muito tempo...\n");
        }else{strcpy(Falas[1],"Nao acredito que exista alguem no mundo assim como voce\n");}
        strcpy(Falas[2],"Humanos... sempre pensando em si\n");
       
        carac[0]=1;strcpy(Resp[0],"Escovo os dentes diariamente... voce não?\n");
       
        carac[1]=1;strcpy(Resp[1],"São queimaduras, elas doem muito\n");
       
        carac[2]=1;strcpy(Resp[2],"Andei chorando... perdão, voce sabe o quanto aqueles seres são horriveis\n");
       
        carac[3]=0;strcpy(Resp[3],"Acabei de escapar de um incendio... não poderia estar fria\n");
       
        carac[4]=1;strcpy(Resp[4],"Deve ser o cheiro abafado da fumaça que ficou nas minhas roupas\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);

}else{
   human=1;//humano
        strcpy(Inf[0],"Meu nome é Vivian, sou dona do mercadinho da rua de cima, minha casa pegou fogo por causa daquelas coisas e preciso de um lugar...\n");
        if(rand() % 2){strcpy(Inf[1],"Nao tenho nada aqui, se tivesse eu te daria tudo\n");
        }else{strcpy(Inf[1],"Isso e tudo que tenho a dizer\n");}
        strcpy(Name,"Mulher cinzenta: ");//Sem ( /n ) Com (: )
        strcpy(Desc,"Agora quem esta na porta é uma mulher com aparencia suja e cansada, sua roupa parece estar com cinzas\n");
        strcpy(Falas[0],"socorro... por favor, me deixe entrar...\n");
        strcpy(Falas[1],"Nao acredito que exista alguem no mundo assim como voce\n");}
        strcpy(Falas[2],"Nem acredito que voce me deixou ficar, qualque coisa que voce precisar pode me pedir\n");
       
        if(rand() % 2){carac[0]=1;strcpy(Resp[0],"Escovo os dentes diariamente... voce não?\n");
        }else{carac[0]=0;strcpy(Resp[0],"Meus dentes sao meio tortinhos mesmo\n");
       
        carac[1]=1;strcpy(Resp[1],"São queimaduras, elas doem muito\n");
       
        carac[2]=1;strcpy(Resp[2],"Andei chorando... perdão, voce sabe o quanto aqueles seres são horriveis\n");
       
        if(rand() % 2){carac[3]=0;strcpy(Resp[3],"Acabei de escapar de um incendio... não poderia estar fria\n");
        }else{carac[3]=0;strcpy(Resp[3],"Minha temperatura esta normal, ja passou um tempo desde o incedio\n");}
       
        carac[4]=0;strcpy(Resp[4],"Devo estar com um leve cheiro de fumaca, mas nada inesperado\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
}


    //Suspeito 2D2:
    if(rand() % 2){
        human=0;//n humano
        if(rand() % 2){strcpy(Inf[0],"Meu nome e Joana, vim de Semarang, so quero entrar pra descansar essa noite\n");
        }else{strcpy(Inf[0],"Meu nome e Joana, vim de Jacarta, so quero entrar pra descansar essa noite\n");}
        if(rand() % 2){strcpy(Inf[1],"ME DEIXA ENTRAR LOGO!!\n");
        }else{strcpy(Inf[1],"Ja falei tudo q tinha pra falar!!\n");}
        strcpy(Name,"Mulher de casaco: ");//Sem ( /n ) Com (: )
        strcpy(Desc,"Agora quem esta na porta é uma mulher baixa usando casaco sujo de sangue\n");
        strcpy(Falas[0],"Ola, me deixa entrar?\n");
        strcpy(Falas[1],"Nos vamos voltar para te pegar!\n");
        strcpy(Falas[2],"Voces sao sempre assim tao... tolos?\n");
       
        //Dentes perfeitos
        carac[0]=0;strcpy(Resp[0],"Sofri alguns acidentes ultimamente que fizeram eu quebrar alguns dentes\n");
       
        //pele quebradiça
        carac[1]=1;strcpy(Resp[1],"Tenho uma doença de pele, por isso uso casaco\n");
       
        //olhos avermelhados
        carac[2]=1;strcpy(Resp[2],"Meus olhos? Nao ha nada de errado com eles\n");
       
        //temperatura
        carac[3]=1;strcpy(Resp[3],"Sinto muito frio, nao saio de casa sem casaco\n");
       
        //cheiro
        carac[4]=1;strcpy(Resp[4],"Faz um tempo que nao consigo lavar meu casaco, por isso ele fede tanto\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
    }else{
        human=1;//humano
        strcpy(Inf[0],"Meu nome e Joana, vim de Jacarta, so quero entrar pra descansar essa noite\n");
        if(rand() % 2){strcpy(Inf[1],"Vai me deixar entrar ou nao!!\n");
        }else{strcpy(Inf[1],"Ja falei tudo q tinha pra falar!!\n");}
        strcpy(Name,"Mulher de casaco: ");//Sem ( /n ) Com (: )
        strcpy(Desc,"Agora quem esta na porta é uma mulher baixa usando casaco sujo de sangue\n");
        if(rand() % 2){strcpy(Falas[0],"Eai, posso passar um tempo ai?\n");
        }else{strcpy(Falas[0],"Preciso de abrigo, me deixa entrar?\n");}
        strcpy(Falas[1],"Vou morrer sozinha mesmo!\n");
        strcpy(Falas[2],"Muito obrigada\n");
       
        //Dentes perfeitos
        if(rand() % 2){carac[0]=0;strcpy(Resp[0],"Sofri alguns acidentes na minha vida que fizeram eu quebrar alguns dentes\n");
        }else{carac[0]=1;strcpy(Resp[0],"Tirei meu aparelho recentemente, obrigada por notar\n");}
       
        //pele quebradiça
        carac[1]=0;strcpy(Resp[1],"Minha pele, eu cuido bem dela\n");
       
        //olhos avermelhados
        carac[2]=0;strcpy(Resp[2],"Olhos normais,nao ha nada de errado com eles\n");
       
        //temperatura
        carac[3]=1;strcpy(Resp[3],"Sinto muito frio, nao saio de casa sem casaco\n");
       
        //cheiro
        carac[4]=0;strcpy(Resp[4],"Meu cheiro e bem comum, eu sei\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
    }

    //Suspeito 3D2:
        human=1;//humano
        strcpy(Inf[0],"Ah, oi! Meu nome é Rich, já pode me deixar entrar!\n");
        strcpy(Inf[1],"Que parte voce não entendeu? Se me fizer esperar eu mando demolirem isso aqui! \n");
        strcpy(Name,"Um mauricinho qualquer: ");
        strcpy(Desc,"Homem com roupas caras, mas sujas e com leves arranhoes \n");
        strcpy(Falas[0],"Ola, querido! Trouxe algumas malas, tem bastante espaco ai, né? \n");
        strcpy(Falas[1],"Voce deve estar louco, eu jamais seria um deles, olha pra mim! \n");
        strcpy(Falas[2],"Ate que esse lugarzinho tem funcionarios competentes! Agora, quem vai levar minha bagagem?\n");
       
        //Dentes perfeitos
        carac[0]=1;strcpy(Resp[0],"Obvio que meus dentes sao perfeitos, minha beleza custa caro!\n");
       
        //pele otima
        if(rand() % 2){carac[1]=0;strcpy(Resp[1],"Se quiser te indico meus produtos de skin care\n");
        }else{carac[1]=0;strcpy(Resp[1],"E claro que minha pele e perfeita\n");}
       
        //olhos normais
        carac[2]=0;strcpy(Resp[2],"Eu durmo 12 horas por dia, voce sabe que faz mal trabalhar demais!\n");
       
        //temperatura fria
        if(rand() % 2){carac[3]=1;strcpy(Resp[3],"Por que estaria quente? Jamais me estressaria com algo, isso da rugas. \n");
        }else{carac[3]=0;strcpy(Resp[3],"Eu faco bronzeamento, minha pele nunca ficaria fria\n");}
       
        //cheiro bom
        carac[4]=0;strcpy(Resp[4],"Meu bem, so meu perfume compra 2 carros, proxima pergunta!\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
   
    //supeito 4 D2:
   
    if(rand()%2){
        human=1;
        strcpy(Inf[0],"Sou o Dr. Marcos. Tenho kit de primeiros socorros. Estou ferido, mas posso ser util.\n");
        strcpy(Inf[1],"Olha, eu vi coisas horriveis. Se nao me deixar entrar, isso vai acontecer comigo.\n");
       
        if(rand() % 2){strcpy(Name,"Homem com jaleco impecável: ");
        strcpy(Desc,"Um homem com um jaleco branco perfeitamente limpo, sem nenhuma mancha de sangue ou sujeira.\n");
        }else{strcpy(Name,"Homem de jaleco rasgado: ");
        strcpy(Desc,"Um homem com roupas hospitalares sujas de sangue seco, ele treme um pouco\n");}
       
        strcpy(Falas[0],"Por favor... eu so preciso descansar os olhos e limpar meus ferimentos.\n");
        strcpy(Falas[1],"Voce esta condenando seus feridos a morte sem mim...\n");
        strcpy(Falas[2],"Obrigado. Vou montar uma enfermaria improvisada no canto.\n");
       
        carac[0]=0;strcpy(Resp[0],"Levei um soco de um paciente em panico... quebrei um dente.\n");
       
        carac[1]=1;strcpy(Resp[1],"Sao arranhoes de fuga, nada infectado, eu garanto, sou medico.\n");
       
        carac[2]=1;strcpy(Resp[2],"Nao durmo ha 72 horas operando gente... meus olhos estao ardendo.\n");
       
        carac[3]=0;strcpy(Resp[3],"Estou com um pouco de febre devido a um corte na perna, mas estou vivo e quente.\n");
       
        if(rand() % 2){carac[4]=1;strcpy(Resp[4],"Cheiro de hospital e sangue... ossos do oficio.\n");
        }else{carac[4]=0;strcpy(Resp[4],"Não há cheiro. A esterilização total é fundamental para evitar contágio.\n");}
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
    }else{
        human=0; // n humano
        if(rand() % 2){strcpy(Inf[0],"Sou o Dr. Elias. Tenho suprimentos médicos avançados e a possível cura. Vim ajudar.\n");
        }else{strcpy(Inf[0],"Sou o Dr. Marcos. Tenho kit de primeiros socorros. Estou ferido, mas posso ser util.\n");}
       
        if(rand() % 2){strcpy(Inf[1],"Preciso entrar para examinar voces antes que a infecção se espalhe aí dentro.\n");
        }else{strcpy(Inf[1],"Olha, eu vi coisas horriveis. Se nao me deixar entrar, isso vai acontecer comigo.\n");}
       
        if(rand() % 2){strcpy(Name,"Homem com jaleco impecável: ");
        strcpy(Desc,"Um homem com um jaleco branco perfeitamente limpo, sem nenhuma mancha de sangue ou sujeira.\n");
        }else{strcpy(Name,"Homem de jaleco rasgado: ");
        strcpy(Desc,"Um homem com roupas hospitalares sujas de sangue seco, ele treme um pouco\n");}
       
        strcpy(Falas[0],"Olá. Por favor, agilize o processo. Tenho... pacientes esperando ai dentro.\n");
        strcpy(Falas[1],"Voces não entendem... voces estão doentes. Nós somos a melhoria.\n");
        strcpy(Falas[2],"Excelente escolha. Vamos começar a... triagem dos órgãos.\n");
       
        //Dentes (Perfeitos, dentes de "revista")
        carac[0]=1;strcpy(Resp[0],"A higiene oral é vital para um médico. Meus dentes são exemplares, como pode ver.\n");
       
        //Pele (Pálida, sem marcas, parece cera ou plástico)
        carac[1]=1;strcpy(Resp[1],"Minha pele, estou fazendo um procedimento que faz ela ficar assim\n");
       
        //Olhos (Muito claros, sem piscar, sem sinal de cansaço)
        carac[2]=1;strcpy(Resp[2],"Estou cansado, nada demais\n");
       
        //Temperatura (Fria - O oposto do médico humano que estava com febre)
        carac[3]=1;strcpy(Resp[3],"Minha temperatura está estável e fria. A sua parece elevada... medo, talvez?\n");
       
        //Cheiro (Nenhum cheiro, estéril. Muito suspeito no apocalipse)
        carac[4]=1;strcpy(Resp[4],"Não há cheiro. A esterilização total é fundamental para evitar contágio.\n");
       
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
       
    }    

   
    printf(AMARELO "\nDIA 2: 19 de maio de 2029 - 02:03\n" RESET);
    printf(AZUL "TV (Últimas Notícias): " RESET);
    type_text("BOLETIM DE QUEDA: As metrópoles de Semarang e Bandung foram declaradas Zonas Mortas. \n", 60000);
    printf(AZUL "TV (Últimas Notícias): " RESET);
    type_text("As comunicações civis foram cortadas após a invasão total das entidades. \n", 60000);

    while(acessarPrimeiro(&s))
    sleep(1);
    mostrarHospedes();
    sleep(2);
   

    }if(!morrer){


    //Supeitos do dia 3:

    //Suspeito 1D3
        human=1;// humano
        if(rand() % 2){strcpy(Inf[0],"Meu nome é Levi, me tira daqui por favor! Abre a porta!\n");
        }else{strcpy(Inf[0],"Meu nome é Caio, me tira daqui por favor! Abre a porta!\n");}
        strcpy(Inf[1],"Me deixa entrar, eles vao me pegar! Eles invadiram minha casa, nao consigo tomar banho desde o primeiro dia\n");
        strcpy(Name,"Jovem adulto pálido: ");
        strcpy(Desc,"Esse jovem parece nao dormir ha dias, esta em pessimo estado\n");
        if(rand() % 2){strcpy(Falas[0],"Oi, por favor, estou com medo, ABRE AGORA.. antes que seja tarde\n");
        }else{strcpy(Falas[0],"Por favor, estou com medo, ABRE AGORA.. eles estao vindo\n");}
        strcpy(Falas[1],"Nao acredito que vou morrer, eu... nao fiz tudo que sonhei\n");
        strcpy(Falas[2],"Obrigado, eu preciso dormir, estou sonhando com isso \n");
       
        //Dentes em pessimo estado
        if(rand() % 2){carac[0]=0;strcpy(Resp[0],"Muita coisa aconteceu la fora, nao tive tempo de me cuidar\n");
        }else{carac[0]=0;strcpy(Resp[0],"Comi muita coisa estranha, nao tive tempo de escovar os dentes\n");}
       
        //pele cortada
        carac[1]=1;strcpy(Resp[1],"Eu quase fui atacado por um, tive que correr ate aqui e cai algumas vezes..\n");
       
        //olhos avermelhados
        carac[2]=1;strcpy(Resp[2],"Voce nao entendeu.. como posso dormir? E claro que meus olhos nao estao bem\n");
       
        //temperatura ok
        carac[3]=0;strcpy(Resp[3],"Tira isso de mim e me deixa entrar logo, por favor! EU IMPLORO\n");
       
        //cheiro ruim
        carac[4]=1;strcpy(Resp[4],"Eu ja te expliquei tudo, por favor acaba logo com isso e me salva\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
   

    //Suspeito 2D3
        human=0;//monstro
        strcpy(Inf[0],"Ola,meu nome e Maria, voce precisa me deixar entrar!\n");
        strcpy(Inf[1],"Meu marido sumiu ontem a noite e me deixou sozinha e tive que vir de Bandung ate aqui andando, por favor me ajuda\n");
        strcpy(Name,"Linda mulher de vermelho: ");
        strcpy(Desc,"Uma mulher charmosa e misteriosa, mas suas botas estao sujas de sangue\n");
        strcpy(Falas[0],"Ola oficial, faço tudo o que voce desejar... basta me deixar entrar!\n");
        strcpy(Falas[1],"Isso foi so o começo, voces irao morrer em breve!\n");
        strcpy(Falas[2],"Voce me salvou, muito obrigada! Espero nao te fazer se arrepender \n");
       
        //Dentes perfeitos
        carac[0]=1;strcpy(Resp[0],"Voce sabe, meu marido exige que eu esteja perfeita para ele\n");
       
        //pele otima
        carac[1]=0;strcpy(Resp[1],"So irei deixar voce tocar no meu rosto novamente ai dentro, oficial...\n");
       
        //olhos avermelhados
        carac[2]=1;strcpy(Resp[2],"Devo ter exagerado um pouco na maquiagem e me deu alergia, nada demais..\n");
       
        //temperatura quente
        carac[3]=0;strcpy(Resp[3],"Voce me deixa nervosa... deve ser por isso\n");
       
        //cheiro ruim
        carac[4]=1;strcpy(Resp[4],"Acho que esse perfume nao e dos melhores, nao concorda?\n");
       
        inserir(&s,human,Inf, Name, Desc, Falas, Resp, carac);
   
    //Suspeito 3D3
        human = 1; // humano
        strcpy(Inf[0],
        "Meu nome e Willian Bill... eu perdi a perna fugindo deles. Amarrei como pude pra nao sangrar ate morrer\n");
        strcpy(Inf[1],
        "Nao tenho mais nada pra te provar... se me mandar embora, eu nao sobrevivo ate o amanhecer\n");
        strcpy(Name,"Homem ferido: ");
        strcpy(Desc,
        "O homem a sua frente se apoia em algo improvisado. "
        "Parte de sua perna foi amputada recentemente, envolta em panos sujos de sangue.\n");

        strcpy(Falas[0],
        "Por favor... eu nao consigo ir muito longe assim, so preciso de um lugar seguro\n");
        strcpy(Falas[1],
        "Entao e isso? Depois de tudo, vou morrer aqui fora...\n");
        strcpy(Falas[2],
        "Obrigado... eu prometo que nao vou causar problemas\n");

        // dentes normais
        carac[0] = 0;
        strcpy(Resp[0],
        "Quebrei um dente quando cai tentando escapar... nao era prioridade agora\n");

        // pele anormal
        carac[1] = 1;
        strcpy(Resp[1],
        "Isso nao e doenca... eu perdi parte da perna tentando sobreviver\n");

        // olhos alterados
        carac[2] = 1;
        strcpy(Resp[2],
        "Eu perdi muito sangue e nao durmo ha dias... como voce acha que meus olhos ficariam?\n");

        // temperatura baixa
        carac[3] = 1;
        strcpy(Resp[3],
        "Meu corpo esta frio porque estou em choque... eu quase morri la fora\n");

        // cheiro forte
        carac[4] = 1;
        strcpy(Resp[4],
        "Isso e sangue seco e remedio... eu amarrei como deu pra nao morrer\n");

        inserir(&s, human, Inf, Name, Desc, Falas, Resp, carac);

//---------------------------- personagens terminados


    printf(AMARELO "\nDIA 3: 20 de maio de 2029 - 02:54\n" RESET);
    printf(AZUL "TV (Informe Meteorológico): " RESET);
    type_text("AVANÇO NA ATMOSFERA: Sensores indicam que a densidade das cinzas começou a dissipar. \n", 60000);
    printf(AZUL "TV (Informe Meteorológico): " RESET);
    type_text("Estimativa de luz solar direta nas próximas horas. \n", 60000);
    printf(AZUL "TV (Informe Meteorológico): " RESET);
    type_text("Sobreviventes, resistam: a radiação ultravioleta é nossa única defesa final.\n", 60000);
         
    while(acessarPrimeiro(&s))
    sleep(1);
    mostrarHospedes();
    sleep(2);
    }
    Final();

    free(hospedes);
    hospedes = NULL;
    destruirFila(&s);
   
    sleep(3);
   
    do {
        printf(AMARELO "\n\n[SISTEMA]" RESET " Deseja jogar novamente? (S/N): ");
        scanf(" %c", &opcao);
       
        if (opcao == 's' || opcao == 'S') {
            printf(VERDE "Se prepare...\n" RESET);
            sleep(1);
            limpar();
            opcao = 'S';
        }
        else if (opcao == 'n' || opcao == 'N') {
            printf(VERMELHO "Obrigado por jogar...\n" RESET);
            sleep(2);
            return 0;
        }
        else {
            printf("Opcao invalida. Digite S ou N.\n");
        }
    } while (opcao != 's' && opcao != 'S');
    }
    return 0;
}
