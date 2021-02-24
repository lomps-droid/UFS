"""
# Iniciando projeto
# Projeto Não pertence a nenhuma lista de atividade
# Feito por: Alexandre Douglas / ******@gmail.com / *******@academico.ufs.br
"""
continuar = 1
alunos = {}
name = ''
#Funções
def alterar_aluno():
    alterar = 1
    print("Digite a matricula que deseja fazer alterações: ")
    matricula = int(input())
    for z, x in alunos.items():
        a, nota1, nota2, nota3, nota4 = x
    if matricula == z:
        while alterar == 1:
            print("1- Nota 01")
            print("2- Nota 02")
            print("3- Nota 03")
            print("4- Nota 04")
            print("0- Sair")
            opcao = int(input())
            if opcao == 1:
                print("Digite o valor da primeira unidade: ")
                nota1 = int(input())
                if (nota1 <= 10) and (nota1 >= 0):
                    print("Nota alterada com sucesso!!")
                    adicionar = {matricula: (
                        a, nota1, nota2, nota3, nota4)}
                else:
                    print("Digite um valor válido")
                    nota1 = 0
            elif opcao == 2:
                print("Digite o valor da Segunda unidade: ")
                nota2 = int(input())
                if (nota2 <= 10) and (nota2 >= 0):
                    print("Nota alterada com sucesso!!")
                    adicionar = {matricula: (a, nota1, nota2, nota3, nota4)}
                else:
                    print("Digite um valor válido")
                    nota2 = 0
            elif opcao == 3:
                print("Digite o valor da Terceira unidade: ")
                nota3 = int(input())
                if (nota3 <= 10) and (nota3 >= 0):
                    print("Nota alterada com sucesso!!")
                    adicionar = {matricula: (
                        a, nota1, nota2, nota3, nota4)}
                else:
                    print("Digite um valor válido")
                    nota3 = 0
            elif opcao == 4:
                print("Digite o valor da Quarta unidade: ")
                nota4 = int(input())
                if (nota4 <= 10) and (nota4 >= 0):
                    print("Nota alterada com sucesso!!")
                    adicionar = {matricula: (
                        a, nota1, nota2, nota3, nota4)}
                else:
                    print("Digite um valor válido")
                    nota4 = 0
            elif opcao == 0:
                alterar = 0
                # Passando valores das notas para a variavel "alunos"
            alunos.update(adicionar)


while continuar == 1:
    matexiste = 0
    alterar = 1
    print("Menu Principal: ")
    print("1- Cadastrar Aluno")
    print("2- Remover Aluno")
    print("3- Alterar Dados de Aluno")
    print("4- Exibir Lista de Alunos")
    print("5- Exibir Lista de Alunos Aprovados")
    print("6- Exibir Lista de Alunos Reprovados")
    opcao = int(input())
    if opcao == 1:
        print("Digite o numero da matricula que deseja adicionar: ")
        matricula = int(input())
        for i in alunos:  # Verificando se matricula já existe
            if matricula == i:
                print("Numero de matricula já existe!!")
                matexiste = 1
        if matexiste == 0:
            print("Digite o nome do Aluno: ")
            name = input()
            # Adicionando valores a uma variavel
            adicionar = {matricula: (name, 0, 0, 0, 0)}
            # Passando valores da variavel para a variavel "alunos"
            alunos.update(adicionar)
            print(
                f'O Aluno {name} de Matrícula: {matricula} foi adicionado com sucesso')
            print("====================================")
    elif opcao == 2:
        print("Digite a matricula que deseja remover: ")
        matricula = int(input())
        for i in alunos:  # Procurando pela matricula
            if matricula == i:
                deletar = matricula  # Salvando valor da matricula caso ela exista
        del alunos[deletar]  # Deletando
    elif opcao == 3:
        alterar_aluno()
    elif opcao == 4:
        print("====================================")
        for i, x in alunos.items():  # Rodando tudo da variavel Alunos
            a, b, c, d, e = x
            media = (b+c+d+e)/4
            print(f'Aluno: {a} || Matricula: {i} || Media: {media}')
        print("====================================")
    elif opcao == 5:
        print("====================================")
        for i, x in alunos.items():  # Rodando tudo da variavel Alunos
            a, b, c, d, e = x
            media = (b+c+d+e)/4
            if media >= 7:
                print(f'Aluno: {a} || Matricula: {i} || Media: {media}')
        print("====================================")
    elif opcao == 6:
        print("====================================")
        for i, x in alunos.items():  # Rodando tudo da variavel Alunos
            a, b, c, d, e = x
            media = (b+c+d+e)/4
            if media < 7:
                print(f'Aluno: {a} || Matricula: {i} || Media: {media}')
        print("====================================")
    elif opcao == 0:
        continuar = 0
