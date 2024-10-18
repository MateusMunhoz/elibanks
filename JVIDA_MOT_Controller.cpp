/*
JVIDA_MOT_Controller.cpp - Projeto Jogo Da Vida - Etapa 02
06/10/2024  - Grupo: MOT
Mateus Munhoz Guimaraes
Osvaldo Kiyokazu Reffi Onishi
Thales de Souza Martins
*/

#include <iostream>
#include "JVIDA_MOT_Controller.h"
#include "JVIDA_MOT_View.cpp"

void menuJogar()
{
    menuDimensaoMatriz();
    system("cls");
    preencherMesaJogo();
    apresentarMesaJogo();
    int opcao;
    do
    {
        opcao = apresentaMenu();
        switch (opcao)
        {
        case 1:
 /*           if (ativo == 1)
            {
                acharCelulasMortas(); // Atualiza com '+' quando o ativo está ligado
            }*/
            apresentarMesaJogo();
            break;
        case 2:
            system("cls");
            limparMatriz();
            break;
        case 3:

            posicionarCelulaViva();
/*           if (ativo == 1)
            {
                system("cls");
                acharCelulasMortas(); // Atualiza após posicionar células
            }*/ 
            apresentarMesaJogo();
            break;
        case 4:
            system("cls");
            ativo = (ativo == 1) ? 0 : 1; // Alterna entre mostrar ou não os vizinhos
            if (ativo == 1)
            {
                acharCelulasMortas();
            }
            else
            {
                esconderCelulasMortas(); // Limpa os '+' e mantém apenas os 'O'
            }
            apresentarMesaJogo();
            break;
        default:
            break;
        }

    } while (opcao != 0);
}

void limparMatriz()
{
    system("cls");
    preencherMesaJogo();
    apresentarMesaJogo();
}

void preencherMesaJogo()
{
    for (int linhas = 0; linhas < dim; linhas++) // i são as linhas
    {
        for (int colunas = 0; colunas < dim; colunas++) // j são as colunas
        {
            matrizJogo[linhas][colunas] = '.'; // Preenche a matriz com '.'
        }
    }
}

void acharCelulasMortas()
{
    for (int linhas = 0; linhas < dim; linhas++)
    {
        for (int colunas = 0; colunas < dim; colunas++)
        {
            if (matrizJogo[linhas][colunas] == 'O') // Encontra célula viva
            {
                for (int i = -1; i <= 1; i++) // Verifica os vizinhos
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int novaLinha = linhas + i;
                        int novaColuna = colunas + j;
                        if (novaLinha >= 0 && novaLinha < dim && novaColuna >= 0 && novaColuna < dim)
                        {
                            if (matrizJogo[novaLinha][novaColuna] == '.')
                            {
                                matrizJogo[novaLinha][novaColuna] = '+';
                            }
                        }
                    }
                }
            }
        }
    }
}

void esconderCelulasMortas()
{
    for (int linhas = 0; linhas < dim; linhas++)
    {
        for (int colunas = 0; colunas < dim; colunas++)
        {
            if (matrizJogo[linhas][colunas] == '+') // Remove os '+'
            {
                matrizJogo[linhas][colunas] = '.'; // Retorna a células mortas ('.')
            }
        }
    }
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Limpa o buffer de entrada
}
