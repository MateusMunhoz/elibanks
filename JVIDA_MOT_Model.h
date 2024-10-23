/*
JVIDA_MOT_Model.h - Projeto Jogo Da Vida - Etapa 02
10/10/2024  - Grupo: MOT
Mateus Munhoz Guimaraes
Osvaldo Kiyokazu Reffi Onishi
Thales de Souza Martins
*/

char matrizJogo[60][60], matrizJogoAux[60][60];         //Criacao da matriz que apresenta as celulas e sua matriz auxiliar que sera usada no futuro
int dim;            //Criacao da variavel que define o tamanho da matriz
bool desativaCelMortas = true;
bool ativarReproducao = true;
