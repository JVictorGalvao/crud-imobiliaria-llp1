#include <stdio.h>
#include <string.h>

#define TAMANHO 100

enum {ALUGUEL, VENDA};
enum {CASA, APTO, TERRENO};

typedef struct{
    char logradouro[100];
    int numero;
    char bairro[50];
    char cidade[100];
    int cep;
} endereco_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    double area;
    int numQuartos;
    char posicao[50];
    int andar;
    double precoCondominio;
    int vagasGaragem;
} apto_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    double area;
} terreno_t;

typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} tipoImovel_t;

typedef struct{
    tipoImovel_t imovel;
    int tipo;
} imovel_t;

void salvaImoveis(imovel_t *imoveis){
    FILE *fp;
    fp = fopen("imoveis.bin", "wb");

    fwrite(imoveis, sizeof(imovel_t), TAMANHO, fp);

    fclose(fp);
}

void leImoveis(imovel_t *imoveis){
    FILE *fp;
    fp = fopen("imoveis.bin", "rb");

    fread(imoveis, sizeof(imovel_t), TAMANHO, fp);

    fclose(fp);
}

void ExibeMenu(){
    puts("Menuzinho");
}

void exibeTerreno(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->imovel.terreno.titulo);
    printf("Valor: %lf \n", exibido->imovel.terreno.preco);
    printf("Area: %lf \n", exibido->imovel.terreno.area);
    printf("Disponibilidade: ");
    switch(exibido->imovel.terreno.disponibilidade){
        case ALUGUEL:
            printf("Aluguel.\n");
            break;
        case VENDA:
            printf("Venda.\n");
            break;
    }
    //exibeEndereco();
    printf("\n\n");
}
void buscaPorTitulo(char *titulo,  imovel_t lista[])
{
    int i;
    for ( i = 0; i < TAMANHO; i++)
    {
        if(!(strcmp(titulo, lista[i].imovel.terreno.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.apto.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.casa.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
    }
    puts("Título não encontrado.");
}

int main(void){
    int i;
    imovel_t listaImoveis[TAMANHO];

    char title[]="Terreno pra vender";

    leImoveis(listaImoveis);
    /*
    listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].imovel.terreno.titulo, "Terreno pra vender");
    listaImoveis[0].imovel.terreno.preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    listaImoveis[0].imovel.terreno.disponibilidade = VENDA;

    salvaImoveis(listaImoveis);
    */
    exibeTerreno(&listaImoveis[0]);
    
    buscaPorTitulo(title,listaImoveis);

    return 0;
}
