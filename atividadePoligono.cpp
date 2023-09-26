/*O modelo de arquivo verticie deve serguir o exemplo abaixo:
3        # Número de vértices (neste caso, um polígono com 4 vértices)
1.0 2.0  # Coordenadas do primeiro vértice (x, y)
3.0 8.0  # Coordenadas do segundo vértice (x, y)
5.0 1.0  # Coordenadas do terceiro vértice (x, y)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double calcularArea(Point vertices[], int numVertices) {
    double area = 0.0;

    for (int i = 0; i < numVertices - 1; i++) {
        area += (vertices[i].x * vertices[i + 1].y - vertices[i + 1].x * vertices[i].y);
    }

    area += (vertices[numVertices - 1].x * vertices[0].y - vertices[0].x * vertices[numVertices - 1].y);

    return fabs(area) / 2.0;
}

int main() {
    FILE *arquivo;
    int numVertices;
    
    arquivo = fopen("C:\\Users\\ryann\\Desktop\\Lari Atividades\\vertices2.txt", "r"); // caminho do arquivo verticies
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    fscanf(arquivo, "%d", &numVertices);
    
    if (numVertices < 3) {
        printf("O polígono deve ter pelo menos 3 vértices.\n");
        fclose(arquivo);
        return 1;
    }
    
    Point *vertices = (Point *)malloc(numVertices * sizeof(Point));
    
    if (vertices == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }
    
    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%lf %lf", &vertices[i].x, &vertices[i].y);
    }
    
    fclose(arquivo);
    
    double area = calcularArea(vertices, numVertices);
    
    printf("A area do poligono eh: %.2lf\n", area);
    
    free(vertices);
    
    return 0;
}
