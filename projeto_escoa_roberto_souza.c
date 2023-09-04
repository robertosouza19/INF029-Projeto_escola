/******************************************************************************
projeto escola inf029
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERRO  -1
#define VALIDO 0
#define QTD_DIGITOS_DATA 8
#define MULTIPLICADOR 10
#define TAM_PROFESSOR 5
#define TAM_ALUNOS 20//quantos alunos posso cadastra
#define TAM_DISCPLINAS 10
# define QTD_MAX_ALUNOS 30

typedef struct{
    char nome[45];
    char cpf[12];
    int matricula;
    char data_nascimento[QTD_DIGITOS_DATA +1];
    char sex1o;
    int dia,mes,ano;
}aluno_professor;

typedef struct {
  char nome_disciplina[45];
  int codigo_disciplina;
  int semestre;
  int matricula_professor;
  int matriculas_alunos[30];
  int fim_vet_matriculas;//fim vetor guarda matriculas de alunos
}disciplina;

int menu();
int menu_aluno();
int menu_professor();
int menu_disciplina();
int menu_relatorio();

int adicionar_aluno(int *qtd_alunos, aluno_professor lista_alunos[],int tam_aluno,
int *matricula);
int adicionar_professor(int *qtd_professores, aluno_professor lista_professores[]
,int tam_professor,int *matricula);

int cpf_valido(char cpf_string[]);
void retira_quebra_linha_str(char string[]);
int data_correta(char string[]);
void limpa_buffer();
int digito_verificador(int vetor[],int tamanho,int multiplicador,int elemento);
int sexo_correto(char sexo);
int listagem_usuarios(int qtd_usuarios,aluno_professor lista_usuarios[],
int tam_usuario,int opcao);

int atualizar_alunos(int qtd_alunos,aluno_professor lista_alunos[],
int tam_aluno);


int busca_matricula(int matricula,aluno_professor lista_alunos[],
int tam_aluno,int fim_vetor);


int busca_cpf(char string_cpf[],aluno_professor lista_alunos[],int tam_aluno,
int fim_vetor);
int excluir_aluno(int *qtd_alunos,aluno_professor lista_alunos[],
int tam_aluno,disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas);

int excluir_profesor(int *qtd_professores,aluno_professor lista_professores[],
int tam_professor);
int atualizar_professor(int qtd_professores,aluno_professor lista_professores[],
int tam_professor);
int cadastro(aluno_professor lista_alunos[],int tam_aluno,int qtd_alunos,
             aluno_professor lista_professores[],int tam_professor,int qtd_professores,
             disciplina lista_disciplinas[],int tam_disciplina ,int *qtd_disciplinas);

int busca_vetor_matricula(int matricula,int vetor_matriculas[],int tamanho,
                          int fim_vetor);
int listar_disciplina(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas
                      ,aluno_professor lista_professores[],int tam_professor,
                      int qtd_professores);
int excluir_aluno_disciplina(disciplina lista_disciplinas[],int tam_disciplina,
int qtd_disciplinas,int codigo_disciplina,int matricula_aluno);
int busca_aluno_disciplina(int codigo_disciplina,disciplina lista_disciplinas[],
int tam_disciplina,int qtd_disciplinas,int matricula_aluno,int* indice_aluno,
int* indice_disciplina);
int teste(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas);
void copia_vet_para_struct(disciplina lista_disciplinas[],int tam_disciplina,int
qtd_disciplinas,int vetor_matriculas[],int tamanho);
int exibir_disciplina(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas,
                      aluno_professor lista_professores[],int tam_professor,int qtd_professores,
                      aluno_professor lista_alunos[],int tam_aluno,int qtd_alunos);


void copia_entre_structs(aluno_professor lista_usuarios[] ,int tam_usuario,int qtd_usuarios,
aluno_professor lista_copia_usuarios[],int tam_copia_usuarios);
void copia_entre_structs(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios,aluno_professor lista_copia_usuarios[],int tam_copia);

int valida_ordem_alfabet(char primeira_string[],char segunda_string[]);
void ordena_atraves_ano_nascimento(aluno_professor lista_usuarios[],int tam_usuarios
,int qtd_usuarios);
int avalia_ano(char string1[],char string2[]);


int  exibir_usuarios_sexo(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios,int opcao);

void usuarios_ordem_alfabet(aluno_professor lista_usuarios[],int tam_usuario,
int qtd_usuarios);

void ordena_atraves_ano_nascimento(aluno_professor lista_usuarios[],int tam_usuarios
,int qtd_usuarios);

int avalia_mais_jovem(char string1[],char string2[]);
void ordena_data_nascimento(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios);


int main()
{ 
    aluno_professor lista_alunos[TAM_ALUNOS],lista_professores[TAM_PROFESSOR];
    disciplina lista_disciplinas[TAM_DISCPLINAS];
    int qtd_alunos      =  0;
    int qtd_professores =  0;
    int qtd_disciplinas =  0;
    int opcao,opcao_aluno,opcao_professor,opcao_disciplina,opcao_relatorio;
    int matricula = -1;
    do{
        opcao = menu();
        switch(opcao){
          
          case 0://sair
            printf("progama encerrado com sucesso\n");
          break;
          case 1://ir aluno
              do{
                  opcao_aluno = menu_aluno();
                  switch(opcao_aluno){
                      case 0://sair do progama
                      opcao = 0;
                        printf("progama encerrado com sucesso\n");
                        break;
                      case 1://voltar menu principal
                        break;
                      case 2://adicionar aluno
                        adicionar_aluno(&qtd_alunos, lista_alunos,TAM_ALUNOS,
                        &matricula);
                        break;
                      case 3://listar alunos
                        listagem_usuarios(qtd_alunos,lista_alunos,TAM_ALUNOS,opcao);
                        break;
                      case 4://atualiza aluno
                        atualizar_alunos(qtd_alunos,lista_alunos,TAM_ALUNOS);
                        break;
                     case 5://excluir aluno
                        excluir_aluno(&qtd_alunos,lista_alunos,
                        TAM_ALUNOS,lista_disciplinas,TAM_DISCPLINAS,qtd_disciplinas);
                        break;
                      default:
                      printf("opcao invalida\n");
                  }
                  
              }while((opcao_aluno != 0)&&(opcao_aluno != 1));
              break;
          case 2://ir para professor
            do{
                  opcao_professor = menu_professor();
                  switch(opcao_professor){
                      case 0://sair do progama
                      opcao = 0;
                        printf("progama encerrado com sucesso\n");
                      break;
                      case 1://voltar menu principal
                      break;
                      case 2://adicionar professores
                        adicionar_professor(&qtd_professores,lista_professores,
                        TAM_PROFESSOR,&matricula);  
                        break;
                      case 3://listar professores
                        listagem_usuarios(qtd_professores,lista_professores,
                        TAM_PROFESSOR,opcao);
                        break;
                      case 4://atualiza professores
                        atualizar_professor(qtd_professores,lista_professores
                        ,TAM_PROFESSOR);
                        break;
                      case 5://excluir professsores
                      excluir_profesor(&qtd_professores,lista_professores,TAM_PROFESSOR);
                      break;
                      default:
                      printf("opcao invalida\n");
                  }
                  
              }while((opcao_professor != 0)&&(opcao_professor != 1));
          break;
          case 3://ir para disciplina
            do{
    
                opcao_disciplina = menu_disciplina();
                switch(opcao_disciplina){
                    case 0://sair encerra o progama
                        printf("progama encerrado com sucesso\n");
                        opcao = 0;
                    break;
                    case 1://voltar ao menu anterior
                    break;
                    case 2://cadastro disciplina    
                        cadastro(lista_alunos,TAM_ALUNOS,qtd_alunos,
                                 lista_professores,TAM_PROFESSOR,qtd_professores,
                                 lista_disciplinas,TAM_DISCPLINAS,&qtd_disciplinas);
                                 printf("cadastro da disciplina feito com sucesso\n");
                               
                    break;
                    case 3://listar disciplinas
                       listar_disciplina(lista_disciplinas,TAM_DISCPLINAS,qtd_disciplinas,
                                         lista_professores,TAM_PROFESSOR,qtd_professores);
                        break;
                    case 4://excluir um aluno
                       int codigo_disciplina,matricula_aluno,retorno;
                       printf("informe o codigo da disciplina:\n");
                       scanf("%d",&codigo_disciplina);
                       printf("informe a matricula do aluno:\n");
                       scanf("%d",&matricula_aluno);
                       retorno = excluir_aluno_disciplina(lista_disciplinas,
                       TAM_DISCPLINAS,qtd_disciplinas,codigo_disciplina,
                       matricula_aluno);
                             if(retorno == -1){
                                 printf("nao e possivel excluir dados invalidos\n");
                             }
                             else{
                                 printf("exclusao realizada com sucesso\n");
                             }
                       
                       
                        break;
                    case 5:
                        teste(lista_disciplinas,TAM_DISCPLINAS,qtd_disciplinas);
                        break;
                    case 6://exibir uma disciplina
                       exibir_disciplina(lista_disciplinas,TAM_DISCPLINAS,qtd_disciplinas,
                       lista_professores,TAM_PROFESSOR,qtd_professores,
                       lista_alunos,TAM_ALUNOS,qtd_alunos);
                        break;
                    default:
                        printf("opcao invalida\n");
                    
                    
                }
            }while( (opcao_disciplina != 0)&&(opcao_disciplina != 1) );
          break;
          case 4:
            //relatorios
            do{
                opcao_relatorio = menu_relatorio();
                switch(opcao_relatorio){
                    case 0://sair do relatorio
                        printf("progama encerrado com sucesso\n");
                        opcao = 0;
                    break;
                    case 1://voltar menu inicial
                    break;
                    case 2://exibir alunos por sexo
                        exibir_usuarios_sexo(lista_alunos,TAM_ALUNOS,
                        qtd_alunos,opcao_relatorio);
                    break;
                    case 3://exibir professores por sexo
                        exibir_usuarios_sexo(lista_professores,TAM_PROFESSOR,
                        qtd_professores,opcao_relatorio);
                    break;
                    case 4://exibir alunos por odem alfabetica
                        usuarios_ordem_alfabet(lista_alunos,TAM_ALUNOS,
                        qtd_alunos);
                        break;
                    case 5://exibir professores por ordem alfabetica
                        usuarios_ordem_alfabet(lista_professores,TAM_PROFESSOR,
                        qtd_professores);
                    break;
                    case 6://exibir alunos aparti do ano nascemnto mais novo ao mais velho
                        ordena_atraves_ano_nascimento(lista_alunos,TAM_ALUNOS,
                        qtd_alunos);
                    break;
                    case 7://exibir prof aparti do ano nascimnto mais novo ao mais velho
                        ordena_atraves_ano_nascimento(lista_professores,TAM_PROFESSOR,
                        qtd_professores);
                    break;
                    case 8://exibir pela data nascimento alunos
                        ordena_data_nascimento(lista_alunos,TAM_ALUNOS,qtd_alunos);
                    break;
                    case 9://exibir pela data nascimento professores
                         ordena_data_nascimento(lista_professores,TAM_PROFESSOR,
                         qtd_professores);
                    break;
                    
                    default:
                        printf("opcao invalida tente novamente!!!\n");
                    
                    
                    
                }
                
            }while((opcao_relatorio != 0)&&(opcao_relatorio != 1));
            break;
          default:
                  printf("opcao invalida\n");
      }  
    }while(opcao != 0);//encerra op progama
    

    return 0;
}
int menu(){
    int opcao;
    printf("============= secao inicial ====================================\n");
    printf("0 sair do progama\n");
    printf("1 secao aluno\n");
    printf("2 secao professor\n");
    printf("3 secao disciplina\n");
    printf("4 secao relatorio\n");
    printf("escolha aopcao desejada\n");
    printf("=================================================================\n");
    scanf("%d",&opcao);
    return opcao;
}

int menu_aluno(){
    int opcao_aluno;
    printf("============= secao aluno ======================================\n");
    printf("0 sair do progama\n");
    printf("1 voltar menu principal\n");
    printf("2 adicionar alunos\n");
    printf("3 listar alunos\n");
    printf("4 atualizar dados alunos\n");
    printf("5 excluir alunos\n");
    printf("================================================================\n");
    printf("escolha aopcao desejada\n");
    scanf("%d",&opcao_aluno);
    setbuf(stdin,NULL);
    system("clear");
    return opcao_aluno;
}

int menu_professor(){
    int opcao_professor;
    printf("============= secao professor ==================================\n");
    printf("0 sair do progama\n");
    printf("1 voltar menu principal\n");
    printf("2 adicionar professores\n");
    printf("3 listar professores\n");
    printf("4 atualizar dados professores\n");
    printf("5 excluir professores\n");
    printf("================================================================\n");
    printf("escolha a opcao desejada:\n");
    scanf("%d",&opcao_professor);
    setbuf(stdin,NULL);
    system("clear");
    return opcao_professor;
}
int menu_disciplina(){
    int opcao_disciplina;
    printf("============= secao disciplina ======================================\n");
    printf("0 sair do progama\n");
    printf("1 voltar menu principal\n");
    printf("2 adicionar disciplinas\n");
    printf("3 listar dados das disciplinas\n");
    printf("4 excluir aluno(a)\n");
    printf("5 teste aluno(a)\n");
    printf("6 exibir dados da disciplina\n");
    printf("================================================================\n");
    printf("escolha aopcao desejada\n");
    scanf("%d",&opcao_disciplina);
    setbuf(stdin,NULL);
    system("clear");
    return opcao_disciplina;
}
int menu_relatorio(){
    int opcao_relatorio;
    printf("============= secao relatorios ==================================\n");
    printf("0 sair do progama\n");
    printf("1 voltar menu principal\n");
    printf("2 exibir alunos por sexo\n");
    printf("3 exibir professores por sexo\n");
    printf("4 exibir alunos por ordem alfabetica\n");
    printf("5 exibir professores por ordem alfabetica\n");
    printf("6 exibir alunos por ano de nascimento\n");
    printf("7 exibir professores por ano de nascimento\n");
    printf("8 exibir alunos por data  de nascimento\n");
    printf("9 exibir profesores por data de nascimento\n");
    printf("10 exibir os anivensariantes do mes\n");
    printf("================================================================\n");
    printf("escolha a opcao desejada:\n");
    scanf("%d",&opcao_relatorio);
    setbuf(stdin,NULL);
    system("clear");
    return opcao_relatorio;
}
int adicionar_aluno(int *qtd_alunos, aluno_professor lista_alunos[],int tam_aluno,
int *matricula)
{
    
    
    char nome_aluno[45];
    char data_nascimento[QTD_DIGITOS_DATA + 1];
    char sexo_aluno;
    char cpf_aluno[12];
    
    if(*qtd_alunos == tam_aluno){
        printf("nao e possivel adicionar mais alunos \n");
        return -1;
    }
    
    printf("informe o nome do aluno(a)que deseja cadastra:\n");
    fgets(nome_aluno,45,stdin);
    retira_quebra_linha_str(nome_aluno);
    
    while(1){
        
        printf("informe a data de nascimento do aluno (a):(dd-mm-aaaa)\n");
        scanf("%s",data_nascimento);
        setbuf(stdin,NULL);
        retira_quebra_linha_str(data_nascimento);
        if(data_correta(data_nascimento) == -1){
            printf("data de nascimento invalida.\n");
        }
        else{
            
            break;
        }
         
    }
    
   while(1){
        printf("informe o cpf do aluno(a):\n");
        scanf("%s",cpf_aluno);
        
        if( (cpf_valido(cpf_aluno)  == -1)||(busca_cpf(cpf_aluno,lista_alunos,
        tam_aluno,*qtd_alunos) == 0)){
            printf("cpf invalido ou cpf ja cadstrado\n");
        }
       
        else{
            break;
        }
   }
    limpa_buffer();
    while(1){
        printf("informe o sexo do aluno(a) :[m/f]\n");
        scanf("%c",&sexo_aluno);
        limpa_buffer();
        if(sexo_correto(sexo_aluno)==-1){
            printf("entrada para sexo invalida.\n");
        }
        else{
            break;
        }
    }
    *matricula = *matricula +1;
    sscanf(data_nascimento,"%2d %2d %4d",&lista_alunos[*qtd_alunos].dia,
    &lista_alunos[*qtd_alunos].mes,&lista_alunos[*qtd_alunos].ano);
    lista_alunos[*qtd_alunos].matricula = *matricula;
    strcpy(lista_alunos[*qtd_alunos].nome,nome_aluno);
    strcpy(lista_alunos[*qtd_alunos].data_nascimento,data_nascimento);
    strcpy(lista_alunos[*qtd_alunos].cpf,cpf_aluno);
    lista_alunos[*qtd_alunos].sexo = sexo_aluno;
    *qtd_alunos = *qtd_alunos + 1;
    //salvado dados do qtd_alunos
    printf("cadastro do aluno(a) feito com sucesso\n");
}
int adicionar_professor(int *qtd_professores, aluno_professor lista_professores[]
,int tam_professor,int *matricula)
{
    
    
    char nome_professor[45];
    char data_nascimento[QTD_DIGITOS_DATA + 1];
    char sexo_professor;
    char cpf_professor[12];
    
    if(*qtd_professores == tam_professor){
        printf("nao e possivel adicionar mais professores \n");
        return -1;
    }
    
    printf("informe o nome do  professor (a)que deseja cadastra:\n");
    fgets(nome_professor,45,stdin);
    retira_quebra_linha_str(nome_professor);
    
    while(1){
        
        printf("informe a data de nascimento do professor(a):(dd-mm-aaaa)\n");
        scanf("%s",data_nascimento);
        setbuf(stdin,NULL);
        retira_quebra_linha_str(data_nascimento);
        if(data_correta(data_nascimento) == -1){
            printf("data de nascimento invalida.\n");
        }
        else{
            
            break;
        }
         
    }
    
   while(1){
        printf("informe o cpf do professor(a):\n");
        scanf("%s",cpf_professor);
        
        if( (cpf_valido(cpf_professor)  == -1)||(busca_cpf(cpf_professor,lista_professores,
        tam_professor,*qtd_professores) == 0)){
            printf("cpf invalido ou cpf ja cadastrado\n");
        }
       
        else{
            break;
        }
   }
     limpa_buffer();
    while(1){
        printf("informe o sexo do professor(a) :[m/f]\n");
        scanf("%c",&sexo_professor);
        limpa_buffer();
        if(sexo_correto(sexo_professor)==-1){
            printf("entrada para sexo invalida.\n");
        }
        else{
            break;
        }
    }
   * matricula = *matricula + 1;
    lista_professores[*qtd_professores].matricula =* matricula;
    strcpy(lista_professores[*qtd_professores].nome,nome_professor);
    strcpy(lista_professores[*qtd_professores].data_nascimento,data_nascimento);
    strcpy(lista_professores[*qtd_professores].cpf,cpf_professor);
    lista_professores[*qtd_professores].sexo = sexo_professor;
    *qtd_professores = *qtd_professores + 1;
    printf("cadastro do professor(a) feito com sucesso\n");
}
void retira_quebra_linha_str(char string[]){
    int icont = 0;
    while(string[icont]!='\0'){
        if(string[icont] == '\n'){
            string[icont] = '\0'; 
        }
        icont++;
    }
}
int data_correta(char string[]){
    int dia ,mes, ano ;
    int bissexto = -1;
    int data_certa = -1;
    int vet_qtd_dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(strlen(string)!= QTD_DIGITOS_DATA){
        return -1;
    }
    sscanf(string,"%2d %2d %4d",&dia,&mes,&ano);//armazena nas tres variaveis
    if((ano % 4 == 0)&&(ano % 100 != 0)||(ano % 400 == 0)){
        bissexto = 0;
    }
    for(int icont = 0;icont < sizeof(vet_qtd_dias);icont++ ){
        if ((icont == mes-1)&&(dia>=1)&&(dia <=vet_qtd_dias[icont])){
            data_certa = 0;
            return data_certa;
        }
        else if ((mes == 2)&&(dia>=1)&&(dia<=29)&&(bissexto == 0)){
            data_certa = 0;
            return data_certa;
        }
    }
    
    return data_certa;
}
void limpa_buffer(){
  int c;
while ((c = getchar()) != '\n' && c != EOF) {}  
}

int sexo_correto(char sexo){
   if((sexo == 'm')||(sexo == 'M')||(sexo == 'F')||(sexo =='f')){
     return 0;  
   } 
   else{
       return -1;
   }
}

int cpf_valido(char cpf_string[]){
   int icont = 0;
   int iguais = 0;
   int ultimo_digito,penultimo_digito;
   int digitos_cpf[11];
    if(strlen(cpf_string)!= 11){//quantidade digitos diferente 11 invalido
        
        return -1;
    }
    while(cpf_string[icont] != '\0'){//{aramazenamento e conversao para int
        digitos_cpf[icont] = (int)cpf_string[icont] - 48 ;
        
        icont++;
    }
    for(icont = 1;icont < 11;icont++){
        if(digitos_cpf[0] == digitos_cpf[icont]){
            iguais++;
        }
    }
    
    if(iguais == 10){//todos digitos do cpf igual cpf invalido
        return -1;
    }
    
   penultimo_digito = digito_verificador(digitos_cpf,sizeof(digitos_cpf),
   MULTIPLICADOR,digitos_cpf[9]);
    
   ultimo_digito =  digito_verificador(digitos_cpf,sizeof(digitos_cpf),
   MULTIPLICADOR + 1,digitos_cpf[10]);
   if ( (penultimo_digito == 0)&&(ultimo_digito == 0)){
       return 0;//valido
   }
   else{
       return -1;//invalido
   }
    
}

int digito_verificador(int vetor[],int tamanho,int multiplicador,int elemento){
    int icont = 0;
    int soma = 0;
    int resto;
    while(multiplicador >= 2){
        soma+=vetor[icont] * multiplicador;
        multiplicador--;
        icont++;
    }
    resto = soma % 11;
    if( (resto < 2) && (elemento == 0)){
        
        return 0;
    }
    else if( (resto <= 10)&&(elemento == 11- resto) ){
        
        return 0;
    }
    else{
        return -1;
    }
    
    return 0;
}

int listagem_usuarios(int qtd_usuarios,aluno_professor lista_usuarios[],
int tam_usuario,int opcao){
    int icont,jcont,cont ;
    char opcoes[3][20] = {" ","aluno(a)s","professor(a)s"};
    if(qtd_usuarios == 0){
        printf("nao e possivel exibir,  0 %s cadastrados\n",opcoes[opcao]);
        return -1;
    }
    printf("============= %s cadastrados por matricula ==============\n",opcoes[opcao]);
   for(int icont = 0;icont < qtd_usuarios;icont++){
        
      printf("nome:.....................%s\n",lista_usuarios[icont].nome);
      printf("matricula:................%d\n",lista_usuarios[icont].matricula);
      printf("data nascimento:..........%.2s-%.2s-%s\n",lista_usuarios[icont].data_nascimento,
      lista_usuarios[icont].data_nascimento+2,lista_usuarios[icont].data_nascimento+4);
      printf("cpf:......................%.3s.%.3s.%.3s-%s\n",lista_usuarios[icont].cpf,
      lista_usuarios[icont].cpf+3,lista_usuarios[icont].cpf+6,lista_usuarios[icont].cpf+9);
      printf("sexo:.....................%c\n",lista_usuarios[icont].sexo);
      puts(" ");
        
    }
    
}



int atualizar_alunos(int qtd_alunos,aluno_professor lista_alunos[],
int tam_aluno){
    int matricula;
    char sexo;
    char cpf_aluno[12];
    char data_nascimento[QTD_DIGITOS_DATA +1];
    char nome_aluno[45];
    int posicao;
    if(qtd_alunos == 0){
        printf("nao e possivel atualizar nao existem alunos cadastrados\n");
        return -1;
    }
    printf("informe a matricula que deseja editar os dados\n");
    scanf("%d",&matricula);
    setbuf(stdin,NULL);
    posicao = busca_matricula(matricula,lista_alunos,tam_aluno,qtd_alunos);
    if( posicao == -1){
        printf("matricula do aluno inexistente\n"); 
        return -1;//volta opcoes
    }
    
    printf("informe o nome do aluno(a) que deseja cadastra:\n");
    fgets(nome_aluno,45,stdin);
    retira_quebra_linha_str(nome_aluno);
    
    while(1){
        
        printf("informe a data de nascimento:(dd-mm-aaaa)\n");
        scanf("%s",data_nascimento);
        setbuf(stdin,NULL);
        retira_quebra_linha_str(data_nascimento);
        if(data_correta(data_nascimento) == -1){
            printf("data de nascimento invalida.\n");
        }
        else{
            break;
        }
         
    }
    
   while(1){
        printf("informe o cpf do aluno(a):\n");
        scanf("%s",cpf_aluno );
        
        if( (cpf_valido(cpf_aluno)  == -1)||(busca_cpf(cpf_aluno,lista_alunos,
        tam_aluno,qtd_alunos) == 0)){
            printf("cpf invalido ou cpf ja cadastrado\n");
        }
    
        else{
            
            break;
        }
   }
     limpa_buffer();
    while(1){
        printf("informe o sexo do aluno:[m/f]\n");
        scanf("%c",&sexo);
        limpa_buffer();
        if(sexo_correto(sexo)==-1){
            printf("entrada para sexo invalida.\n");
        }
        else{
            break;
        }
    }
    
    strcpy(lista_alunos[posicao].nome,nome_aluno);
    strcpy(lista_alunos[posicao].data_nascimento,data_nascimento);
    strcpy(lista_alunos[posicao].cpf,cpf_aluno);
    lista_alunos[posicao].sexo = sexo;
    printf("alteracoes salvas com sucesso\n");
    //salvando as alteracoes
    
    return 0;
}


int excluir_aluno(int *qtd_alunos,aluno_professor lista_alunos[],
int tam_aluno,disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas){
    
    int matricula,cont;
    int posicao_matricula;
    if(*qtd_alunos== 0){
        printf("nao existem alunos cadastrados\n");
        return -1;
    }
    printf("informe a matricula do aluno(a) que deseja a excluir:\n");
    scanf("%d",&matricula);
    posicao_matricula = busca_matricula(matricula,lista_alunos,tam_aluno,*qtd_alunos);
    if( posicao_matricula == -1){
        printf("matricula inexistente\n");
        return -1;
    }
    for(cont = posicao_matricula;cont < *qtd_alunos-1;cont++){
        lista_alunos[cont].matricula = lista_alunos[cont+ 1].matricula;
        strcpy(lista_alunos[cont].nome,lista_alunos[cont +1 ].nome);
        strcpy(lista_alunos[cont].data_nascimento,lista_alunos[cont +1 ]
        .data_nascimento);
        strcpy(lista_alunos[cont].cpf,lista_alunos[cont +1 ].cpf);
        lista_alunos[cont +1 ].sexo = lista_alunos[cont].sexo;
    }
    *qtd_alunos= * qtd_alunos -1;
    for(int codigo_disciplina = 0;codigo_disciplina < qtd_disciplinas;codigo_disciplina++){
        excluir_aluno_disciplina(lista_disciplinas,tam_disciplina,
        qtd_disciplinas,codigo_disciplina,matricula);
    }
    printf("exclusao realizada com sucesso\n");
    return 0;
}
int busca_cpf(char string_cpf[],aluno_professor lista_alunos[],int tam_aluno,
int fim_vetor){
    int cont;
    for(cont = 0;cont < fim_vetor;cont++){
        if(strcmp(string_cpf,lista_alunos[cont].cpf) == 0){
            
            return 0;
        }
    }
    return -1;
}

int busca_matricula(int matricula,aluno_professor lista_alunos[],
int tam_aluno,int fim_vetor){
   int cont;
   for(cont = 0;cont < fim_vetor;cont++){
       if(matricula == lista_alunos[cont].matricula){
           return cont;
       }
   }
   return -1;
}
int excluir_profesor(int *qtd_professores,aluno_professor lista_professores[],
int tam_professor){
    
    int matricula,cont;
    int posicao_matricula;
    if(*qtd_professores== 0){
        printf("0 professores(a) cadastrados nao e possivel excluir\n");
        return -1;
    }
    printf("informe a matricula do professor(a) que deseja a exclusao:\n");
    scanf("%d",&matricula);
    posicao_matricula = busca_matricula(matricula,lista_professores,tam_professor
    ,*qtd_professores);
    if( posicao_matricula == -1){
        printf("matricula inexistente,nao e possivel realizar a  exclusao\n");
        return -1;
    }
    for(cont = posicao_matricula;cont < *qtd_professores-1;cont++){
        lista_professores[cont].matricula = lista_professores[cont+ 1].matricula;
        strcpy(lista_professores[cont].nome,lista_professores[cont +1 ].nome);
        strcpy(lista_professores[cont].data_nascimento,lista_professores[cont +1 ]
        .data_nascimento);
        strcpy(lista_professores[cont].cpf,lista_professores[cont +1 ].cpf);
        lista_professores[cont +1 ].sexo = lista_professores[cont].sexo;
    }
    *qtd_professores= * qtd_professores -1;
    printf("exclusao realizada com sucesso\n");
    return 0;
}

int atualizar_professor(int qtd_professores,aluno_professor lista_professores[],
int tam_professor){
    int matricula;
    char sexo;
    char cpf_professor[12];
    char data_nascimento[QTD_DIGITOS_DATA +1];
    char nome_professor[45];
    int posicao;
    if(qtd_professores== 0){
        printf("nao e possivel atualizar nao existem professores cadastrados\n");
        return -1;
    }
    printf("informe a matricula que deseja editar os dados\n");
    scanf("%d",&matricula);
    setbuf(stdin,NULL);
    posicao = busca_matricula(matricula,lista_professores,tam_professor,qtd_professores);
    if( posicao == -1){
        printf("matricula do aluno inexistente\n"); 
        return -1;//volta opcoes
    }
    
    printf("informe o nome do professor(a) que deseja cadastra:\n");
    fgets(nome_professor,45,stdin);
    retira_quebra_linha_str(nome_professor);
    
    while(1){
        
        printf("informe a data de nascimento:(dd-mm-aaaa)\n");
        scanf("%s",data_nascimento);
        setbuf(stdin,NULL);
        retira_quebra_linha_str(data_nascimento);
        if(data_correta(data_nascimento) == -1){
            printf("data de nascimento invalida.\n");
        }
        else{
            break;
        }
         
    }
    
   while(1){
        printf("informe o cpf do professor(a):\n");
        scanf("%s",cpf_professor );
        
        if( (cpf_valido(cpf_professor)  == -1)||(busca_cpf(cpf_professor,lista_professores,
        tam_professor,qtd_professores) == 0)){
            printf("cpf invalido ou cpf ja cadastrado\n");
        }
    
        else{
            
            break;
        }
   }
     limpa_buffer();
    while(1){
        printf("informe o sexo do professor:[m/f]\n");
        scanf("%c",&sexo);
        limpa_buffer();
        if(sexo_correto(sexo)==-1){
            printf("entrada para sexo invalida.\n");
        }
        else{
            break;
        }
    }
    
    strcpy(lista_professores[posicao].nome,nome_professor);
    strcpy(lista_professores[posicao].data_nascimento,data_nascimento);
    strcpy(lista_professores[posicao].cpf,cpf_professor);
    lista_professores[posicao].sexo = sexo;
    printf("alteracoes salvas com sucesso\n");
    //salvando as alteracoes
    
    return 0;
}

int cadastro(aluno_professor lista_alunos[],int tam_aluno,int qtd_alunos,
             aluno_professor lista_professores[],int tam_professor,int qtd_professores,
             disciplina lista_disciplinas[],int tam_disciplina ,int *qtd_disciplinas){
    

    char nome_disciplina[45];
    int matricula_professor;
    int matricula_aluno;
    int semestre;
    int termina;
    int codigo_disciplina;
    
    int qtd_alunos_disciplina = 0;//contador
    int icont;
    int matriculas_alunos[QTD_MAX_ALUNOS];
    int tamanho = qtd_alunos;
    
    if((qtd_alunos == 0)||(qtd_professores == 0)){
        printf("nao existe alunos ou professorem cadastrados\n");
        return -1;
    }
    
    printf("informe o nome da disciplina:\n");
    fgets(nome_disciplina,45,stdin);
    retira_quebra_linha_str(nome_disciplina);
    printf("informe o semestre da disciplina:\n");
    scanf("%d",&semestre);
    while(1){//valida professor
        printf("informe matricula do professor:\n");
        scanf("%d",&matricula_professor );
        if(busca_matricula(matricula_professor,lista_professores,tam_professor,
        qtd_professores) != -1 ){
           break;//professor localizado adicionado disciplina
        }
        else{
             printf("professor nao esta cadastrado na escola tente de novo\n");
            //ate inserir matricula valida ciclo continua
        }
    }
    
    
//qtd_alunos representa quantidade de alunos na escola
    while (qtd_alunos_disciplina < qtd_alunos ) {
        //limite aluno quantidade alunos matriculados na escola
        
        
        while(1){//valida entrada aluno
            printf("informe a matricula do aluno que deseja adicionar disciplina:\n");
            scanf("%d",&matricula_aluno);
            if(busca_matricula(matricula_aluno, lista_alunos,
            tam_aluno,qtd_alunos) == -1 ){
                printf("aluno nao esta matriculado na instituicao\n");
            }
            else if(busca_vetor_matricula(matricula_aluno,matriculas_alunos,tamanho,
            qtd_alunos_disciplina) == 0){//impede cadastra mesmo aluno varias vezes
                printf("o aluno ja foi cadastrado na disciplina\n");
            }
            else{
                //aluno e valido pois esta matriculado na escola 
                // o aluno nao consta na disciplina
                break;
            }
               
        }
        matriculas_alunos[qtd_alunos_disciplina] = matricula_aluno;//guarda aluno
        if(qtd_alunos_disciplina < qtd_alunos -1){
            //pergunta ate penultima posicao vetor_matriculas
            printf("deseja termina o cadastro de alunos digite -1:\n");
            scanf("%d",&termina);
            if(termina == -1){
                lista_disciplinas[*qtd_disciplinas].fim_vet_matriculas = 
                qtd_alunos_disciplina;
                printf("cadastro de alunos encerrado\n");
                break;
            }
            
        }
        if(qtd_alunos_disciplina == qtd_alunos  -1){
            //informa atigiu limite alunos matriculados na escola
            printf("nao existe mais alunos na escola para ser adicionados a disciplina\n"); 
        }
        lista_disciplinas[*qtd_disciplinas].fim_vet_matriculas = 
        qtd_alunos_disciplina;
        
        
        qtd_alunos_disciplina++;
        
    }
    codigo_disciplina = *qtd_disciplinas;//gerando codigo disciplina
    lista_disciplinas[*qtd_disciplinas].codigo_disciplina = codigo_disciplina;//guarda codigo da disciplina
    strcpy(lista_disciplinas[*qtd_disciplinas].nome_disciplina,nome_disciplina);//nome da disciplina
    lista_disciplinas[*qtd_disciplinas].semestre = semestre;//semestre
    lista_disciplinas[*qtd_disciplinas].matricula_professor = matricula_professor;//matricula professor
    copia_vet_para_struct(lista_disciplinas,tam_disciplina,*qtd_disciplinas,
    matriculas_alunos,QTD_MAX_ALUNOS);

    *qtd_disciplinas = *qtd_disciplinas +1;//cadastro disciplina foi concluido com exito

    return 0;
}

int busca_vetor_matricula(int matricula,int vetor_matriculas[],int tamanho,
                          int fim_vetor){
    int contador;
    for(contador = 0;contador < fim_vetor;contador++){
        if(matricula == vetor_matriculas[contador]){
            return 0;//achei
        }
    }
    return -1;//nao achei
}
int listar_disciplina(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas,
                      aluno_professor lista_professores[],int tam_professor,
                      int qtd_professores){
    int contador,indice;
    if(qtd_disciplinas == 0){
        printf("nao e possivel lista 0 disciplinas cadastrads\n");
        return -1;
    }printf("====================== disciplinas cadastradas ===============\n");
    for(contador = 0;contador < qtd_disciplinas;contador++){
        printf("nome da disciplina:.....................................%s\n",
        lista_disciplinas[contador].nome_disciplina);
        
        printf("semestre da disciplina:.................................%d\n",
        lista_disciplinas[contador].semestre);
        
        printf("codigo da disciplina:...................................%d\n",
        lista_disciplinas[contador].codigo_disciplina);
        
        indice =  busca_matricula(lista_disciplinas[contador].matricula_professor
        ,lista_professores,tam_professor,qtd_professores);
        if(indice < 0){
           printf("professor:............................................ nao definido\n");
           printf(" \n");
           
           continue;
        }
        printf("professor:...............................................%s\n",
        lista_professores[indice].nome);
        printf(" \n"); 
    }
}
int excluir_aluno_disciplina(disciplina lista_disciplinas[],int tam_disciplina,
int qtd_disciplinas,int  codigo_disciplina,int matricula_aluno){
 
  int indice_disciplina = -1,indice_aluno = -1;//marcadores
  

 int icont,jcont,final;
                                 
 busca_aluno_disciplina(codigo_disciplina,lista_disciplinas,tam_disciplina,
 qtd_disciplinas,matricula_aluno,&indice_aluno,&indice_disciplina);
 if( (indice_aluno == -1) ||(indice_disciplina == -1) ){
    
     return -1; 
 }
 final = lista_disciplinas[indice_disciplina].fim_vet_matriculas;
 for(icont = indice_aluno;icont <final ;icont++){
     lista_disciplinas[indice_disciplina].matriculas_alunos[icont] = 
     lista_disciplinas[indice_disciplina].matriculas_alunos[icont + 1];
     
 }
 lista_disciplinas[indice_disciplina].fim_vet_matriculas--;
 return 0; 
}
int busca_aluno_disciplina(int codigo_disciplina,disciplina lista_disciplinas[],
int tam_disciplina,int qtd_disciplinas,int matricula_aluno,int* indice_aluno,
int* indice_disciplina){
    int icont,jcont,fim_vetor;
    for(icont = 0;icont < qtd_disciplinas;icont++){
        if(codigo_disciplina == lista_disciplinas[icont].codigo_disciplina){
            *indice_disciplina = icont;
            fim_vetor = lista_disciplinas[icont].fim_vet_matriculas;
            for(jcont = 0;jcont <=fim_vetor;jcont++){
                if(matricula_aluno == lista_disciplinas[icont].matriculas_alunos[jcont]){
                    *indice_aluno = jcont;
                    return 0;//achei
                }
            }
        }
    }

}
int teste(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas){
    int jcont,icont,final;
    if (qtd_disciplinas == 0){
        printf("impossivel listar\n");
        return -1;
    }
    printf("alunos que pertecem as discipinas\n");
    for(icont = 0;icont < qtd_disciplinas ;icont++){
        printf("========== %s ==========\n",lista_disciplinas[icont].
        nome_disciplina);
        final = lista_disciplinas[icont].fim_vet_matriculas;
        for(jcont = 0;jcont <= final;jcont++){
           printf("aluno............................:%d\n",lista_disciplinas[icont]
           .matriculas_alunos[jcont]); 
        }
        printf(" \n");
        
    }
}
void copia_vet_para_struct(disciplina lista_disciplinas[],int tam_disciplina,int
qtd_disciplinas,int vetor_matriculas[],int tamanho){
    int fim = lista_disciplinas[qtd_disciplinas].fim_vet_matriculas;
    for(int icont = 0; icont <= fim ;icont++){
        lista_disciplinas[qtd_disciplinas].matriculas_alunos[icont] = 
        vetor_matriculas[icont];
    }
    
}

int exibir_disciplina(disciplina lista_disciplinas[],int tam_disciplina,int qtd_disciplinas,
                      aluno_professor lista_professores[],int tam_professor,int qtd_professores,
                      aluno_professor lista_alunos[],int tam_aluno,int qtd_alunos){
    int codigo_disciplina,posicao_disciplina = -1;
    int matricula_professor,posicao_professor;
    printf("informe o codigo da disciplina que desjainformacoes:\n");
    scanf("%d",&codigo_disciplina);
    //busca 
    for(int icont = 0;icont < qtd_disciplinas;icont++){
        if(codigo_disciplina == lista_disciplinas[icont].codigo_disciplina){
            posicao_disciplina = icont;
            break;//localizado 
        }
    }
    if(posicao_disciplina == -1){
        printf("disciplina nao localizada\n"); 
        return -1;
    }
    else{
        printf("====================== dados da disciplinas ======================\n");
        printf("nome da disciplina:.............................................%s\n",
        lista_disciplinas[posicao_disciplina].nome_disciplina);
        printf("codigo_disciplina:..............................................%d\n",
        lista_disciplinas[posicao_disciplina].codigo_disciplina);
        printf("semestre:.......................................................%d\n",
        lista_disciplinas[posicao_disciplina].semestre);
        matricula_professor = lista_disciplinas[posicao_disciplina].matricula_professor;
        posicao_professor = busca_matricula(matricula_professor,lista_professores,tam_aluno,
        qtd_professores);
        if(posicao_professor == -1){
           printf("professor:.............................................nao definido\n"); 
        }
        else{
            printf("professor:..................................................%s\n",
        lista_professores[posicao_professor].nome);
        }
        
    }
}


void copia_entre_structs(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios,aluno_professor lista_copia_usuarios[],int tam_copia){
   for(int icont = 0;icont < qtd_usuarios;icont++){
       //matricula
       lista_copia_usuarios[icont].matricula = lista_usuarios[icont].matricula;
       //nome
       strcpy(lista_copia_usuarios[icont].nome,lista_usuarios[icont].nome);
       strcpy(lista_copia_usuarios[icont].data_nascimento,lista_usuarios[icont].
       data_nascimento);
       strcpy(lista_copia_usuarios[icont].cpf,lista_usuarios[icont].cpf);
       lista_copia_usuarios[icont].sexo = lista_usuarios[icont].sexo;
       
   } 
}

int valida_ordem_alfabet(char primeira_string[],char segunda_string[]){
    int icont = 0;
    while( (primeira_string[icont] !='\0')&&(segunda_string[icont]!='\0')){
        if(primeira_string[icont] > segunda_string[icont]){
            
            return 0;//fazer troca
        }
        else if(primeira_string[icont] < segunda_string[icont]){
            return -1;//nao faz troca
        }
        icont++;
    }
    return -2;//nao faz troca
}   
void usuarios_ordem_alfabet(aluno_professor lista_usuarios[],int tam_usuario,
int qtd_usuarios){
    int icont,jcont,tam_copia_usuarios = qtd_usuarios,aux_matricula;
    aluno_professor lista_copia_usuarios[qtd_usuarios];//aramzena copia vetor usuarios
    char aux_nome[45],aux_data[11],aux_cpf[12],aux_sexo;
    copia_entre_structs(lista_usuarios,tam_usuario,qtd_usuarios,
    lista_copia_usuarios,tam_copia_usuarios);
     for(icont = 0;icont < qtd_usuarios -1;icont++){
         
        for(jcont = icont + 1;jcont < qtd_usuarios;jcont++){
            if(valida_ordem_alfabet(lista_copia_usuarios[icont].nome,
            lista_copia_usuarios[jcont].nome) == 0){
                strcpy(aux_nome,lista_copia_usuarios[icont].nome);
                strcpy(lista_copia_usuarios[icont].nome,lista_copia_usuarios[jcont].nome);
                strcpy(lista_copia_usuarios[jcont].nome,aux_nome);
                //matricula
                aux_matricula = lista_copia_usuarios[icont].matricula;
                lista_copia_usuarios[icont].matricula = lista_copia_usuarios[jcont].matricula;
                lista_copia_usuarios[jcont].matricula = aux_matricula;
                //data_nascimento
                strcpy(aux_data,lista_copia_usuarios[icont].data_nascimento);
                strcpy(lista_copia_usuarios[icont].data_nascimento,lista_copia_usuarios[jcont].data_nascimento);
                strcpy(lista_copia_usuarios[jcont].data_nascimento,aux_data);
                //cpf
                strcpy(aux_cpf,lista_copia_usuarios[icont].cpf);
                strcpy(lista_copia_usuarios[icont].cpf,lista_copia_usuarios[jcont].cpf);
                strcpy(lista_copia_usuarios[jcont].cpf,aux_cpf);
                //genero
                aux_sexo = lista_copia_usuarios[icont].sexo;
                lista_copia_usuarios[icont].sexo = lista_copia_usuarios[jcont].sexo;
                lista_copia_usuarios[jcont].sexo = aux_sexo;
            }   
        }
    }
     //impressao alunos
    for(icont = 0; icont < qtd_usuarios;icont++){
        printf("nome:..............%s\n",lista_copia_usuarios[icont].nome);
        printf("matricula:.........%d\n",lista_copia_usuarios[icont].matricula);
        printf("data de nascimento:%.2s-%.2s-%2s\n",lista_copia_usuarios[icont].data_nascimento,
        lista_copia_usuarios[icont].data_nascimento+2,lista_copia_usuarios[icont].data_nascimento+4
        );
        printf("cpf................%s.%.3s.%.3s-%s\n",lista_copia_usuarios[icont].cpf,
        lista_copia_usuarios[icont].cpf+3,lista_copia_usuarios[icont].cpf+6,
        lista_copia_usuarios[icont].cpf+8);
        printf("sexo:..............%c\n",lista_copia_usuarios[icont].sexo);
        printf(" \n");
        
    }
    
    
}
//usuarios =  aluno ou professor
void ordena_atraves_ano_nascimento(aluno_professor lista_usuarios[],int tam_usuarios
,int qtd_usuarios){
    
    int tam_copia = qtd_usuarios;
    int aux_matricula,icont,jcont;
    char aux_nome[45],aux_data[11],aux_cpf[12],aux_sexo;
    aluno_professor lista_copia_usuarios[qtd_usuarios];
    copia_entre_structs(lista_usuarios,tam_usuarios,
    qtd_usuarios,lista_copia_usuarios,tam_copia);
    for(icont = 0;icont < qtd_usuarios -1;icont++){
        
        for(jcont = icont +1;jcont < qtd_usuarios;jcont++){
            if(avalia_ano(lista_copia_usuarios[icont].data_nascimento,
            lista_copia_usuarios[jcont].data_nascimento) == 0){
                strcpy(aux_nome,lista_copia_usuarios[icont].nome);
                strcpy(lista_copia_usuarios[icont].nome,lista_copia_usuarios[jcont].nome);
                strcpy(lista_copia_usuarios[jcont].nome,aux_nome);
                //matricula
                aux_matricula = lista_copia_usuarios[icont].matricula;
                lista_copia_usuarios[icont].matricula = lista_copia_usuarios[jcont].matricula;
                lista_copia_usuarios[jcont].matricula = aux_matricula;
                //data_nascimento
                strcpy(aux_data,lista_copia_usuarios[icont].data_nascimento);
                strcpy(lista_copia_usuarios[icont].data_nascimento,lista_copia_usuarios[jcont].data_nascimento);
                strcpy(lista_copia_usuarios[jcont].data_nascimento,aux_data);
                //cpf
                strcpy(aux_cpf,lista_copia_usuarios[icont].cpf);
                strcpy(lista_copia_usuarios[icont].cpf,lista_copia_usuarios[jcont].cpf);
                strcpy(lista_copia_usuarios[jcont].cpf,aux_cpf);
                //genero
                aux_sexo = lista_copia_usuarios[icont].sexo;
                lista_copia_usuarios[icont].sexo = lista_copia_usuarios[jcont].sexo;
                lista_copia_usuarios[jcont].sexo = aux_sexo;  
            }
        }
    }
    //impressao usuarios por ano nascimento do mais novo aos mais velhos.
    for(icont = 0;icont < qtd_usuarios;icont++){
        printf("matricula:..............%d\n",lista_copia_usuarios[icont].matricula);
        printf("nome:...................%s\n",lista_copia_usuarios[icont].nome);
        printf("data:...................%.2s-%.2s-%s\n",
        lista_copia_usuarios[icont].data_nascimento,
        lista_copia_usuarios[icont].data_nascimento+2,lista_copia_usuarios[icont].data_nascimento + 4); 
        printf("cpf:....................%.3s.%.3s.%.3s-%s\n",
        lista_copia_usuarios[icont].cpf,lista_copia_usuarios[icont].cpf+3,
        lista_copia_usuarios[icont].cpf + 6,lista_copia_usuarios[icont].cpf + 9);
        printf("sexo:..................%c\n",lista_copia_usuarios[icont].sexo);
        puts(" ");
    }   
    
    
    
   
    
    
}
int avalia_ano(char string1[],char string2[]){
    int ano1,ano2;
    ano1 = atoi(string1);
    ano2 = atoi(string2);
    ano1 = ano1 % 10000;
    ano2 = ano2 % 10000;
    if(ano1 > ano2){
        
        return 0;
    }
    else if (ano1 < ano2){
        
        return -1;
    }
    else{
        
        return -1;
    }
}


int exibir_usuarios_sexo(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios,int opcao){
    char opcoes[4][20] = {" "," ","aluno(a)","professor(a)"};
    if(qtd_usuarios == 0){
        printf("nao e possivel exibir,  0 %s cadastrados\n",opcoes[opcao]);
        return -1;
    }
    printf("==========\tsexo masculino\t==========\n");
    
    for(int icont = 0;icont < qtd_usuarios;icont++){
        if((lista_usuarios[icont].sexo == 'm')||(lista_usuarios[icont].sexo == 'M')){
          printf("nome:.....................%s\n",lista_usuarios[icont].nome);
          printf("matricula:................%d\n",lista_usuarios[icont].matricula);
          printf("data nascimento:..........%.2s-%.2s-%s\n",lista_usuarios[icont].data_nascimento,
          lista_usuarios[icont].data_nascimento+2,lista_usuarios[icont].data_nascimento+4);
          printf("cpf:......................%.3s.%.3s.%.3s-%s\n",lista_usuarios[icont].cpf,
          lista_usuarios[icont].cpf+3,lista_usuarios[icont].cpf+6,lista_usuarios[icont].cpf+9);
          printf("sexo:.....................%c\n",lista_usuarios[icont].sexo);
          puts(" ");
        }
    }
    printf("==========\tsexo feminino\t==========\n");
    for(int icont = 0;icont < qtd_usuarios;icont++){
        if((lista_usuarios[icont].sexo == 'f')||(lista_usuarios[icont].sexo == 'F')){
          printf("nome:.....................%s\n",lista_usuarios[icont].nome);
          printf("matricula:................%d\n",lista_usuarios[icont].matricula);
          printf("data nascimento:..........%.2s-%.2s-%s\n",lista_usuarios[icont].data_nascimento,
          lista_usuarios[icont].data_nascimento+2,lista_usuarios[icont].data_nascimento+4);
          printf("cpf:......................%.3s.%.3s.%.3s-%s\n",lista_usuarios[icont].cpf,
          lista_usuarios[icont].cpf+3,lista_usuarios[icont].cpf+6,lista_usuarios[icont].cpf+9);
          printf("sexo:.....................%c\n",lista_usuarios[icont].sexo);
          puts(" ");
        }
    }
}
void ordena_data_nascimento(aluno_professor lista_usuarios[],int tam_usuarios,
int qtd_usuarios){
   aluno_professor lista_copia_usuarios[qtd_usuarios];
   int tam_copia = qtd_usuarios;
   int aux_matricula,icont,jcont;
   char aux_nome[45],aux_data[11],aux_cpf[12],aux_sexo;
   copia_entre_structs(lista_usuarios,tam_usuarios,qtd_usuarios,
   lista_copia_usuarios,tam_copia);//copia para lista_copia_usuarios
   for(icont = 0;icont < qtd_usuarios -1;icont++){
        
        for(jcont = icont +1;jcont < qtd_usuarios;jcont++){
            if(avalia_mais_jovem(lista_copia_usuarios[icont].data_nascimento,
            lista_copia_usuarios[jcont].data_nascimento) == 0){
                strcpy(aux_nome,lista_copia_usuarios[icont].nome);
                strcpy(lista_copia_usuarios[icont].nome,lista_copia_usuarios[jcont].nome);
                strcpy(lista_copia_usuarios[jcont].nome,aux_nome);
                //matricula
                aux_matricula = lista_copia_usuarios[icont].matricula;
                lista_copia_usuarios[icont].matricula = lista_copia_usuarios[jcont].matricula;
                lista_copia_usuarios[jcont].matricula = aux_matricula;
                //data_nascimento
                strcpy(aux_data,lista_copia_usuarios[icont].data_nascimento);
                strcpy(lista_copia_usuarios[icont].data_nascimento,lista_copia_usuarios[jcont].data_nascimento);
                strcpy(lista_copia_usuarios[jcont].data_nascimento,aux_data);
                //cpf
                strcpy(aux_cpf,lista_copia_usuarios[icont].cpf);
                strcpy(lista_copia_usuarios[icont].cpf,lista_copia_usuarios[jcont].cpf);
                strcpy(lista_copia_usuarios[jcont].cpf,aux_cpf);
                //genero
                aux_sexo = lista_copia_usuarios[icont].sexo;
                lista_copia_usuarios[icont].sexo = lista_copia_usuarios[jcont].sexo;
                lista_copia_usuarios[jcont].sexo = aux_sexo;  
            }
        }
    }
   for(icont = 0;icont < qtd_usuarios;icont++){
        printf("matricula:..............%d\n",lista_copia_usuarios[icont].matricula);
        printf("nome:...................%s\n",lista_copia_usuarios[icont].nome);
        printf("data:...................%.2s-%.2s-%s\n",
        lista_copia_usuarios[icont].data_nascimento,
        lista_copia_usuarios[icont].data_nascimento+2,lista_copia_usuarios[icont].data_nascimento + 4); 
        printf("cpf:....................%.3s.%.3s.%.3s-%s\n",
        lista_copia_usuarios[icont].cpf,lista_copia_usuarios[icont].cpf+3,
        lista_copia_usuarios[icont].cpf + 6,lista_copia_usuarios[icont].cpf + 9);
        printf("sexo:..................%c\n",lista_copia_usuarios[icont].sexo);
        puts(" ");
    }   
    
}
int avalia_mais_jovem(char string1[],char string2[]){
    int dia1,dia2,mes1,mes2,ano1,ano2;
    sscanf(string1,"%2d %2d %4d",&dia1,&mes1,&ano1);
    sscanf(string2,"%2d %2d %4d",&dia2,&mes2,&ano2);
    if(ano1 >  ano2){//nao troca
        return ERRO;
    }
    else if(ano1 < ano2){// troca
        return VALIDO;
    }
    else if (mes1 > mes2){//nao troca
        return ERRO;
    }
    else if (mes1 < mes2){//troca
        return VALIDO;
    }
    else if (dia1 > dia2){//nao troca
        return ERRO;
    }
    else if (dia1 < dia2){//troca
        return 0;
    }
    return ERRO;
}















