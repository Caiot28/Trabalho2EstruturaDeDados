#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo (Ponto p1, Ponto p2, Ponto p3);

main(){

    FILE *arquivo;
    int vertices;
    float AreaPoligono;

    arquivo = fopen("triangulo5.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(arquivo, "%d", &vertices); // guarda o nmr de vertices

    Ponto Vertices[vertices]; //cria um vetor de vertices
    
    for(int i = 0; i < vertices; i++){
    fscanf(arquivo, "%f %f\n", &Vertices[i].X, &Vertices[i].Y);
    } // guarda os vertices

    if(vertices > 2){ 
        
        for(int i = 0; i < vertices - 2; i++){ //cria os triangulos e calcula a area de cada um
        float determinante;
        Ponto p1 = Vertices[0];
        Ponto p2 = Vertices[1 + i];
        Ponto p3 = Vertices[2 + i];
        determinante = AreaTriangulo(p1, p2, p3);

        AreaPoligono += determinante;
        }
    } else {
        printf("Numero de vertices incompativel");
        exit(0);
    }

    printf("\nA area do poligono e %.2f\n", AreaPoligono);

    fclose(arquivo);
}

float AreaTriangulo (Ponto p1, Ponto p2, Ponto p3){
    float AreaPoligono;
    AreaPoligono = (p1.X * p2.Y * 1) + (p1.Y * 1 * p3.X) + (1 * p2.X * p3.Y) - (p3.X * p2.Y * 1) - (p3.Y * 1 * p1.X) - (1 * p2.X * p1.Y);

    if(AreaPoligono < 0){
        AreaPoligono *= -1;
    }

    AreaPoligono = AreaPoligono / 2;
    
    return AreaPoligono;
}
