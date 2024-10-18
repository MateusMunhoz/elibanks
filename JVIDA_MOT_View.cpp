/*
JVIDA_MOT_View.cpp - Projeto Jogo Da Vida - Etapa 02
10/10/2024  - Grupo: MOT
Mateus Munhoz Guimaraes
Osvaldo Kiyokazu Reffi Onishi
Thales de Souza Martins
*/

#include "JVIDA_MOT_View.h"

int apresentaMenu()
{
    int op;
    printf("\n");
    printf("1 - Apresentar o Mapa \n");
    printf("2 - Limpar o Mapa\n");
    printf("3 - Incluir/excluir celulas vivas\n");
    printf("4 - Mostrar/Esconder os mortos-vizinhos\n\n");
    //    printf("5 - Iniciar o processo\n");
    //    printf("6 - Apresentar as listas\n\n");
    //    printf("7 - Gravar uma geracao inicial cadastrada\n");
    //    printf("8 - Recuperar uma geracao inicial cadastrada\n");
    //    printf("9 - Limpar o cadastro de geracoes iniciais cadastradas (n geraçoes)\n\n");
    //    printf("10 - Regras de evolucao das celulas\n");
    printf("0 - Sair do jogo \n");

    printf("Opcao escolhida: ");
    scanf("%d", &op);

    return op;
}

void apresentaMensagem(char msg[200])
{
    printf("%s \n", msg);
}

int menuDimensaoMatriz()
{
    do
    {
        printf("Escolha o tamanho da matriz do jogo: (de 10 a 60) \n");
        scanf("%d", &dim);

        if (dim < 10 || dim > 60)
        {
            system("cls");
            printf("A matriz deve ter tamanho entre 10 e 60, sendo invalido o tamanho %d \n", dim);
        }
    } while (dim < 10 || dim > 60); // Continua pedindo até obter um valor válido

    printf("O tamanho informado e valido, inciando a matriz \n\n");
    return dim;
}

void apresentarMesaJogo()
{
    //system("cls");
    printf("   ");
    for (int j = 0; j < dim; j++)
    {
        printf("%2d ", j);
    }

    for (int i = 0; i < dim; i++)
    {
        printf("\n");
        printf("%2d ", i);

        for (int k = 0; k < dim; k++)
        {
            printf("%2c ", matrizJogo[i][k]);
        }
    }
    printf("\n");
}

void posicionarCelulaViva() // Funcao utilizada para posicionar uma celula viva em uma coordenada especificada pelo jogador, aonde e feito tambem o tratamento de casos como se ja houver uma celula naquela coordenada, dando ao usuario a opcao de remove-la ou mudar a coordenada aonde colocar a celula
{
    int coordenadaL;
    int coordenadaC;
    int remover;
    int continuar = 1; // Variável para controlar o loop

    while (continuar == 1) // Enquanto o usuário quiser continuar, o loop roda
    {
        printf("Digite as coordenadas em que deseja posicionar a celula viva: \n");

        printf("Coluna:");
        scanf("%d", &coordenadaC); // Pede ao usuario onde quer colocar sua célula
        printf("\n");

        printf("Linha:");
        scanf("%d", &coordenadaL);
        printf("\n");
        system("cls");

        if (coordenadaC < dim && coordenadaC >= 0 && coordenadaL >= 0 && coordenadaL < dim) // Verifica se as coordenadas estão dentro do limite da matriz
        {
            if (matrizJogo[coordenadaL][coordenadaC] == 'O') // Verifica se já existe uma célula viva nessa coordenada
            {

                printf("Ja ha uma celula viva nessa coordenada, deseja remove-la (1 para sim, 2 para nao)?  \n");
                scanf("%d", &remover);

                if (remover == 1)
                {
                    //    system("cls");
                    matrizJogo[coordenadaL][coordenadaC] = '.';

                    for (int i = -1; i <= 1; i++) // Verifica os vizinhos
                    {
                        for (int j = -1; j <= 1; j++)
                        {
                            int novaLinha = coordenadaL + i;
                            int novaColuna = coordenadaC + j;
                            if (novaLinha >= 0 && novaLinha < dim && novaColuna >= 0 && novaColuna < dim)
                            {
                                if (ativo == 1)
                                {
                                    if (matrizJogo[novaLinha][novaColuna] == '+')
                                    {
                                        matrizJogo[novaLinha][novaColuna] = '.';
                                        acharCelulasMortas();
                                    }
                                }
                            }
                        }
                    }
                    printf("Removida a celula da coordenada (%d,%d) \n", coordenadaL, coordenadaC);
                }
                else
                {
                    printf("Entao escolha outra coordenada para posicionar a celula viva \n");
                }
            }
            else // Se não houver célula viva, insere a nova célula
            {
                matrizJogo[coordenadaL][coordenadaC] = 'O';
                system("cls");
            }
            
        }
        else // Caso a coordenada seja inválida
        {
            printf("Coordenadas invalidas \n");
            printf("Escolha outra coordenada \n");
        }

        if (ativo == 1)
        {
            acharCelulasMortas();
        }

        apresentarMesaJogo();

        printf("Deseja posicionar mais uma celula viva (1 para sim, 0 para nao)? ");
        scanf("%d", &continuar);

        limparBuffer();
    }
}
