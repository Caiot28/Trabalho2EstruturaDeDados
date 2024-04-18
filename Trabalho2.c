#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto {
    float X;
    float Y;
};

main(){

    FILE *arquivo;
    float area;
    int vertices;

    arquivo = fopen("triangulo5.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(arquivo, "%d", &vertices);

    struct Ponto Vertices[vertices];
    
    for(int i = 0; i < vertices; i++){
    
    fscanf(arquivo, "%f %f\n", &Vertices[i].X, &Vertices[i].Y);
    printf("%f %f\n", Vertices[i].X, Vertices[i].Y);

    }
    fclose(arquivo);
}
