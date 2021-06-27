/*
Aluno: Alexandre Douglas
Matrícula: *********
Programação Imperativa ~ Turma 01 ~ 2020.1
PROJETO 01
*/

#include <stdio.h>
#include <string.h>
FILE *dados;
typedef struct
{
    char nome[50];
    int matricula, faltas; //frequencia;
    float notas[4];
    float media;
} alunos_dados;
alunos_dados info[60];
int i, q, z; //Usado em loops
int dados_insert()
{
    dados = fopen("alunos.txt", "w");
    if (dados == NULL)
    {
        printf("Erro ao abrir arquivo, tente novamente");
        return 0;
    }
    for (q = 0; q < 60; q++)
    {
        fprintf(dados, "%d %.2f %.2f %.2f %.2f %d %s\n", info[q].matricula, info[q].notas[0], info[q].notas[1], info[q].notas[2], info[q].notas[3], info[q].faltas, info[q].nome);
    }
    fclose(dados);
}
int dados_leitura()
{
    dados = fopen("alunos.txt", "r");
    if (dados == NULL)
    {
        printf("Erro ao abrir arquivo, tente novamente");
        return 0;
    }
    for (q = 0; q < 60; q++)
    {
        fscanf(dados, "%d %f %f %f %f %d %s", &info[q].matricula, &info[q].notas[0], &info[q].notas[1], &info[q].notas[2], &info[q].notas[3], &info[q].faltas, info[q].nome);
    }
    fclose(dados);
}
int u;
//Funções
//Funções de ordem
void troca(alunos_dados a[], int pos_max, int pos2)
{
    alunos_dados tmp;
    tmp.matricula = a[pos_max].matricula;
    tmp.media = a[pos_max].media;
    tmp.faltas = a[pos_max].faltas;
    tmp.notas[0] = a[pos_max].notas[0];
    tmp.notas[1] = a[pos_max].notas[1];
    tmp.notas[2] = a[pos_max].notas[2];
    tmp.notas[3] = a[pos_max].notas[3];
    strcpy(tmp.nome, a[pos_max].nome);

    a[pos_max].matricula = a[pos2].matricula;
    a[pos_max].media = a[pos2].media;
    a[pos_max].faltas = a[pos2].faltas;
    a[pos_max].notas[0] = a[pos2].notas[0];
    a[pos_max].notas[1] = a[pos2].notas[0];
    a[pos_max].notas[2] = a[pos2].notas[0];
    a[pos_max].notas[3] = a[pos2].notas[0];
    strcpy(a[pos_max].nome, a[pos2].nome);

    a[pos2].matricula = tmp.matricula;
    a[pos2].media = tmp.media;
    a[pos2].faltas = tmp.faltas;
    a[pos2].notas[0] = tmp.notas[0];
    a[pos2].notas[1] = tmp.notas[1];
    a[pos2].notas[2] = tmp.notas[2];
    a[pos2].notas[3] = tmp.notas[3];
    strcpy(a[pos2].nome, tmp.nome);
}

void matricula_ordem(alunos_dados a[], int n)
{
    int i, j;
    int pos_max;
    for (i = 0; i < n - 1; i++)
    {
        pos_max = 0;
        for (j = 1; j < n - i; j++)
        {
            if (a[j].matricula > a[pos_max].matricula)
            {
                pos_max = j;
            }
        }
        troca(a, pos_max, n - 1 - i);
    }
}
void falta(alunos_dados a[], int n)
{
    int i, j;
    int pos_max;
    for (i = 0; i < n - 1; i++)
    {
        pos_max = 0;
        for (j = 1; j < n - i; j++)
        {
            if (a[j].faltas > a[pos_max].faltas)
            {
                pos_max = j;
            }
        }
        troca(a, pos_max, n - 1 - i);
    }
}
void nomes(alunos_dados a[], int n)
{
    int i, j;
    int pos_max;
    for (i = 0; i < n - 1; i++)
    {
        pos_max = 0;
        for (j = 1; j < n - i; j++)
        {
            if (strcmp(a[j].nome, a[pos_max].nome) > 0)
            {
                pos_max = j;
            }
        }
        troca(a, pos_max, n - 1 - i);
    }
}
void media(alunos_dados a[], int n)
{
    int i, j;
    int pos_max;
    for (i = 0; i < n - 1; i++)
    {
        pos_max = 0;
        for (j = 1; j < n - i; j++)
        {
            if (a[j].media < a[pos_max].media)
            {
                pos_max = j;
            }
        }
        troca(a, pos_max, n - 1 - i);
    }
}


int main()
{
    int alterar_option = 1;
    int option_notas;
    int buscar[1]; //Vetor com função de receber dados e comparar com outros vetores
    int zerar = 1;
    int limite = 0; // Estabelence um limite para o numero de matriculas de acordo com o vetor matricula[x]
    int option;
    int return_option = 1;

    do
    {
        //Retornando as variaveis de "loop" aos valores iniciais
        int adicionar = 1;
        int modificar = 0;
        int remover = 0;
        dados_leitura();
        /////////////////////////////////////////////////
        printf("\n===========================\n");
        printf("1- Cadastrar Aluno\n");
        printf("2- Remover aluno\n");
        printf("3- Atualizar dados de um Aluno\n");
        printf("4- Listar alunos cadastrados\n");
        printf("5- Listar alunos aprovados\n");
        printf("6- Listar alunos reprovados por media\n");
        printf("7- Listar alunos reprovados por falta\n");
        printf("0- sair\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            if (limite < 60)
            {
                //Recebendo matricula
                printf("\nDigite o numero da matricula: ");
                scanf("%d", &buscar[0]);
                //Verificar se a matrícula existe
                for (i = 0; i < 60; i++)
                {
                    if (buscar[0] == info[i].matricula)
                    {
                        system("cls || clear");
                        printf("\nNumero da matricula ja existe!");
                        adicionar = 0;
                        break;
                    }
                }
                //Adicionando aluno caso a matrícula não exista
                for (i = 0; i < 60; i++)
                {
                    //Verificando se matricula foi removida ou não existe para realizar a substituição dentro do vetor por uma matricula nova
                    if (info[i].matricula == 0)
                    {
                        if (adicionar == 1)
                        {
                            info[i].matricula = buscar[0];
                            fflush(stdin);
                            printf("Nome do Aluno: ");
                            gets(info[i].nome);
                            system("cls || clear");
                            printf("\n==================================");
                            printf("\nMatricula adicionada com sucesso!\n");
                            adicionar = 0;
                            dados_insert();
                        }
                    }
                }
            }
            else
            {
                system("cls || clear");
                printf("\n=====================================\n");
                printf("Numero de matricula atingiu o limite!");
                printf("\n=====================================\n");
            }

            break;
        case 2:
            printf("\n=========================================");
            printf("\nDigite o numero de matricula do aluno: ");
            scanf("%d", &buscar[0]);
            //Verificando se o aluno existe
            for (i = 0; i < 60; i++)
            {
                if (buscar[0] == info[i].matricula)
                {
                    //Removendo matricula
                    info[i].matricula = 0;
                    for (u = 0; u < 4; u++)
                    {
                        info[i].notas[u] = 0;
                    }
                    info[i].faltas = 0;
                    strcpy(info[i].nome, "Nonome");
                    dados_insert();
                    system("cls || clear");
                    printf("\n=================================\n");
                    printf("Matricula removida com sucesso!");
                    printf("\n=================================\n");
                    remover = 1;
                    //Editando arquivo
                    break;
                }
            }
            if (remover == 0)
            {
                system("cls || clear");
                printf("\n=====================================\n");
                printf("Numero de matricula invalido!");
                printf("\n=====================================\n");
            }
            break;

        case 3:
            printf("\nDigite o numero da matricula do Aluno: ");
            scanf("%d", &buscar[0]);
            //Verificando se o numero de matricula existe
            for (i = 0; i < 60; i++)
            {
                //Verificando se a matricula PODE existir
                if (info[i].matricula == buscar[0])
                {
                    system("cls || clear");
                    //Esse "do" faz retornar ao menu de alteração das notas e faltas
                    do
                    {
                        printf("\n1- Alterar nota 01\n");
                        printf("\n2- Alterar nota 02\n");
                        printf("\n3- Alterar nota 03\n");
                        printf("\n4- Alterar nota 04\n");
                        printf("\n5- Alterar numero de faltas\n");
                        printf("\n0- Voltar ao menu principal\n");
                        printf("Op%c%co: ", 135, 198);
                        scanf("%d", &option_notas);
                        switch (option_notas)
                        {
                        case 1:
                            printf("\nDigite a nova nota do aluno: ");
                            scanf("%f", &info[i].notas[0]);
                            if (info[i].notas[0] <= 10 && info[i].notas[0] >= 0)
                            {
                                system("cls || clear");
                                printf("\n=========================\n");
                                printf("Nota alterada com sucesso.");
                                printf("\nAluno de matricula N%c%d possui agora na Nota 01: %.2f Pontos\n", 248, info[i].matricula, info[i].notas[0]);
                                dados_insert();
                                break;
                            }
                            else
                            {
                                info[i].notas[0] = 0;
                                dados_insert();
                                system("cls || clear");
                                printf("Valor invalido");
                            }

                            break;
                        case 2:
                            printf("\nDigite a nova nota do aluno: ");
                            scanf("%f", &info[i].notas[1]);
                            if (info[i].notas[1] <= 10 && info[i].notas[1] >= 0)
                            {
                                system("cls || clear");
                                printf("\n=========================\n");
                                printf("Nota alterada com sucesso.");
                                printf("\nAluno de matricula N%c%d possui agora na Nota 02: %.2f Pontos\n", 248, info[i].matricula, info[i].notas[1]);
                                dados_insert();
                                break;
                            }
                            else
                            {
                                info[i].notas[1] = 0;
                                dados_insert();
                                system("cls || clear");
                                printf("Valor invalido");
                            }
                            break;
                        case 3:
                            printf("\nDigite a nova nota do aluno: ");
                            scanf("%f", &info[i].notas[2]);
                            if (info[i].notas[2] <= 10 && info[i].notas[2] >= 0)
                            {
                                system("cls || clear");
                                printf("\n=========================\n");
                                printf("Nota alterada com sucesso.");
                                printf("\nAluno de matricula N%c%d possui agora na Nota 03: %.2f Pontos\n", 248, info[i].matricula, info[i].notas[2]);
                                dados_insert();
                                break;
                            }
                            else
                            {
                                info[i].notas[2] = 0;
                                dados_insert();
                                system("cls || clear");
                                printf("Valor invalido");
                            }
                            break;
                        case 4:
                            printf("\nDigite a nova nota do aluno: ");
                            scanf("%f", &info[i].notas[3]);
                            if (info[i].notas[3] <= 10 && info[i].notas[3] >= 0)
                            {
                                system("cls || clear");
                                printf("\n=========================\n");
                                printf("Nota alterada com sucesso.");
                                printf("\nAluno de matricula N%c%d possui agora na Nota 04: %.2f Pontos\n", 248, info[i].matricula, info[i].notas[3]);
                                dados_insert();
                                break;
                            }
                            else
                            {
                                info[i].notas[3] = 0;
                                dados_insert();
                                system("cls || clear");
                                printf("Valor invalido");
                            }
                            break;
                        case 5:
                            printf("\nDigite o numero de faltas do Aluno\n");
                            scanf("%d", &info[i].faltas);
                            if (info[i].faltas <= 36 && info[i].faltas >= 0)
                            {
                                system("cls || clear");
                                printf("\n===========================\n");
                                printf("Numero de faltas alterado com sucesso.");
                                printf("\nAluno de matricula N%c%d possui: %d Faltas\n", 248, info[i].matricula, info[i].faltas);
                                dados_insert();
                                break;
                            }
                            else
                            {
                                dados_insert();
                                system("cls || clear");
                                printf("Valor invalido");
                                info[i].faltas = 0;
                                break;
                            }
                            break;
                        case 0:
                            alterar_option = 0;
                            break;
                        default:
                            system("cls || clear");
                            printf("\nSeleciona uma opcao valida!\n");
                            break;
                        }
                    } while (alterar_option == 1);
                }
            }
            break;
        case 4:
            for (u = 0; u < 60; u++)
            {
                info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
            }
            system("cls || clear");
            printf("\n============O R D E N A R===============\n");
            printf("\n1- Matricula");
            printf("\n2- Nome");
            printf("\n3- Media");
            printf("\n4- Faltas");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                matricula_ordem(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 2:
                nomes(info, 60);
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 3:
                media(info, 60);
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 4:
                falta(info, 60);
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            default:
                break;
            }
            break;
        case 5:
            system("cls || clear");
            printf("\n============O R D E N A R===============\n");
            printf("\n1- Matricula");
            printf("\n2- Nome");
            printf("\n3- Media");
            printf("\n4- Faltas");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                matricula_ordem(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media >= 7 && info[q].faltas < 15)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 2:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                nomes(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media >= 7 && info[q].faltas < 15)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 3:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                media(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media >= 7 && info[q].faltas < 15)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                };
                break;
            case 4:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                falta(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media >= 7 && info[q].faltas < 15)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            default:
                break;
            }
            break;
        case 6:
            system("cls || clear");
            printf("\n============O R D E N A R===============\n");
            printf("\n1- Matricula");
            printf("\n2- Nome");
            printf("\n3- Media");
            printf("\n4- Faltas");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                matricula_ordem(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media < 7)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 2:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                nomes(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media < 7)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 3:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                media(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media < 7)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 4:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                falta(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].media < 7)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            }
            break;
        case 7:
            system("cls || clear");
            printf("\n============O R D E N A R===============\n");
            printf("\n1- Matricula");
            printf("\n2- Media");
            printf("\n3- Nomes");
            printf("\n4- Faltas");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                matricula_ordem(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].faltas > 14)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 2:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                nomes(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].faltas > 14)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 3:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                media(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].faltas > 14)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            case 4:
                for (u = 0; u < 60; u++)
                {
                    info[u].media = (info[u].notas[0] + info[u].notas[1] + info[u].notas[2] + info[u].notas[3]) / 4;
                }
                falta(info, 60);
                system("cls || clear");
                printf("\n====================\n");
                for (q = 0; q < 60; q++)
                {
                    //Ignorando matriculas removidas ou que não existe
                    if (info[q].matricula > 0 && info[q].faltas > 14)
                    {
                        printf("\n- N da matricula: %d - Aluno: - %s - Media: %.2f - Faltas: %d  |", info[q].matricula, info[q].nome, info[q].media, info[q].faltas);
                    }
                }
                break;
            default:
                break;
            }
            break;
        case 0:
            return 0;
            break;
        default:
            system("cls || clear");
            printf("Seleciona uma opcao valida!");
            break;
        }

    } while (return_option != 0);
}
