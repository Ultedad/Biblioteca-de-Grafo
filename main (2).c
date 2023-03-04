#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct GRAFO{
   char nome[20];
   struct GRAFO *aresta;
   struct GRAFO *vertice;
} Grafo;

void PrintVertice(Grafo *grafo){
  printf("\n\n-=-=-=-Vertice-=-=-=-");
  if(grafo->vertice == NULL){
    printf("\n%s", grafo->nome);
  } else{
  Grafo *Aux = grafo;
  do{
    printf("↓\n");
    printf("%s\n", Aux->nome);
    Aux = Aux->vertice;
    }while(Aux != NULL);
  }
}

void PrintAresta(Grafo *grafo){
  printf("\n\n-=-=-=-Vertices e Arestas-=-=-=-");
  if(grafo->vertice == NULL){
    printf("\nNao tem aresta\n");
    return;
  }else{
  Grafo *Aux = grafo;
  do{
    
    printf("↓\n");
    printf("%s", Aux->nome);

    Grafo *AuxAresta = Aux;
    if(AuxAresta->aresta == NULL){
      printf("->");
    } else{
      AuxAresta = AuxAresta->aresta;
      do{
      printf("->%s", AuxAresta->nome);
      AuxAresta = AuxAresta->aresta;
        }while(AuxAresta != NULL);
    }

    printf("\n");

    Aux = Aux->vertice;
    }while(Aux != NULL);
  }
}
void RemoverAuxiliar(Grafo *grafo,char vertice[20], char verticeRemovido[20]){
  }
 
Grafo *CriarGrafo(){
  Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
  strcpy(grafo->nome, "v1");
  grafo->aresta = NULL;
  grafo->vertice = NULL;
  
  return grafo;
}

void CriarVertice(Grafo *grafo){
  char nome[20];
  if(grafo->vertice == NULL){
    Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
    printf("Qual o nome do vertice?");
    scanf("%s", nome);
    strcpy(Novo->nome, nome);
    Novo->aresta = NULL;
    Novo->vertice = NULL;
    grafo->vertice = Novo;
  } else{
    Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
    printf("Qual o nome do vertice?");
    scanf("%s", nome);
    strcpy(Novo->nome, nome);
    Novo->aresta = NULL;
    Novo->vertice = NULL;
    Grafo *Aux = grafo->vertice;
      while(Aux->vertice){
        Aux = Aux->vertice;
      }
   Aux->vertice = Novo;
  }
}

void CriarAresta(Grafo *grafo){
  char origem[20], destino[20];
  int cont1=0, cont2=0;
  printf("Quais vertices terão a aresta?");
  PrintVertice(grafo);
  printf("de:");
  scanf("%s", origem);
  printf("para:");
  scanf("%s", destino);
  Grafo *Aux = grafo;
  do{
    if(strcmp(Aux->nome, origem)==0){
      if(Aux->aresta == NULL){
        Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
        strcpy(Novo->nome, destino);
        Novo->aresta = NULL;
        Novo->vertice = NULL;
        Aux->aresta = Novo;
      } else{
        Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
        strcpy(Novo->nome, destino);
        Novo->aresta = NULL;
        Novo->vertice = NULL;
        Grafo *Fa = Aux->aresta;
        while(Fa->aresta){
        Fa = Fa->aresta;}
        Fa->aresta = Novo;
      }
    cont1 = 1;}
    Aux = Aux->vertice;
    }while(Aux != NULL && cont1 == 0);
  Grafo *Aux2 = grafo;
  do{
    if(strcmp(Aux2->nome, destino)==0){
      if(Aux2->aresta == NULL){
        Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
        strcpy(Novo->nome, origem);
        Novo->aresta = NULL;
        Novo->vertice = NULL;
        Aux2->aresta = Novo;
      } else{
        Grafo *Novo = (Grafo *) malloc(sizeof(Grafo));
        strcpy(Novo->nome, origem);
        Novo->aresta = NULL;
        Novo->vertice = NULL;
        Grafo *Fa1 = Aux2->aresta;
        while(Fa1->aresta){
        Fa1 = Fa1->aresta;}
        Fa1->aresta = Novo;
      }
    cont2 = 1;}
    Aux2 = Aux2->vertice;
    }while(Aux2 != NULL && cont2 == 0);
}

void RemoverVertice(Grafo *grafo){
  Grafo *Aux = grafo, *Aux2 = grafo, *Ant = NULL, *Pos;
  char vertice[20];
  printf("Qual vertice quer remover?:");
  scanf("%s", vertice);
  if(strcmp(Aux->nome, vertice)==0){
    grafo = grafo->vertice;
    free(Aux);
    Aux = NULL;
  } else{
  Ant = grafo;
  while( Aux != NULL){
    Aux = Aux->vertice;
    if(strcmp(Aux->nome, vertice)==0){
      Pos = Aux->vertice;
      Ant->vertice = Pos;
      free(Aux);
      Aux= NULL;
      break;
    }
    Ant = Ant->vertice;
   }
  }
}

void RemoverAresta(Grafo *grafo){
  Grafo *Aux = grafo, *AuxV, *Ant = NULL, *Pos;
  Grafo *Aux2 = grafo, *AuxV2, *Ant2 = NULL, *Pos2;
  char origem[20], destino[20];
  printf("Quais vertices para remover a aresta?");
  PrintVertice(grafo);
  printf("de:");
  scanf("%s", origem);
  printf("para:");
  scanf("%s", destino);

  // -=-=-=-=-=- Removendo origem para destino -=-=-=-=-=-
  //Caso 1: o Vertice é o primeiro, Procurar a aresta...
  if(strcmp(Aux->nome, origem)==0){
    Aux = Aux->aresta;
    Ant = grafo;
    if(strcmp(Aux->nome, destino)==0){
      Pos = Aux->aresta;
      Ant->aresta = Pos;
      free(Aux);
      Aux = NULL;
    }else{
      while( Aux != NULL){
      Ant = Aux;
      Aux = Aux->aresta;
      if(strcmp(Aux->nome, destino)==0){
      Pos = Aux->aresta;
      Ant->aresta = Pos;
      free(Aux);
      Aux= NULL;
      break;}
      }}
    }else{
      AuxV = grafo->vertice;
      while (AuxV != NULL){
        Aux = AuxV;

        
        if(strcmp(Aux->nome, origem)==0){
        Aux = Aux->aresta;
        Ant = AuxV;
        if(strcmp(Aux->nome, destino)==0){
          Pos = Aux->aresta;
          Ant->aresta = Pos;
          free(Aux);
          Aux = NULL;
        }else{
          while( Aux != NULL){
          Ant = Aux;
          Aux = Aux->aresta;
          if(strcmp(Aux->nome, destino)==0){
          Pos = Aux->aresta;
          Ant->aresta = Pos;
          free(Aux);
          Aux = NULL;
          break;}}}
        } 
        
        AuxV = AuxV->vertice;
        }
      }

  // -=-=-=-=-=- Removendo destino para origem -=-=-=-=-=-
  // Faz a msm coisa que o outro em vice-versa
  if(strcmp(Aux2->nome, destino)==0){
      Aux2 = Aux2->aresta;
      Ant2 = grafo;
      if(strcmp(Aux2->nome, origem)==0){
        Pos2 = Aux2->aresta;
        Ant2->aresta = Pos2;
        free(Aux2);
        Aux2 = NULL;
      }else{
        while( Aux2 != NULL){
        Ant2 = Aux2;
        Aux2 = Aux2->aresta;
        if(strcmp(Aux2->nome, origem)==0){
        Pos2 = Aux2->aresta;
        Ant2->aresta = Pos2;
        free(Aux2);
        Aux2= NULL;
        break;}
        }}
      }else{
        AuxV2 = grafo->vertice;
        while (AuxV2 != NULL){
          Aux2 = AuxV2;
  
          
          if(strcmp(Aux2->nome, destino)==0){
          Aux2 = Aux2->aresta;
          Ant2 = AuxV2;
          if(strcmp(Aux2->nome, origem)==0){
            Pos2 = Aux2->aresta;
            Ant2->aresta = Pos2;
            free(Aux2);
            Aux2 = NULL;
          }else{
            while( Aux2 != NULL){
            Ant2 = Aux2;
            Aux2 = Aux2->aresta;
            if(strcmp(Aux2->nome, origem)==0){
            Pos2 = Aux2->aresta;
            Ant2->aresta = Pos2;
            free(Aux2);
            Aux2 = NULL;
            break;}}}
          } 
          
          AuxV2 = AuxV2->vertice;
          }
        }
}

void GrauVertice(Grafo *grafo){
  Grafo *Aux = grafo, *AuxAresta;
  int Grau = 0;
  char vertice[20];
  PrintVertice(grafo);
  printf("Qual vertice quer o grau?:");
  scanf("%s", vertice);
  while( Aux != NULL){
    if(strcmp(Aux->nome, vertice)==0){
      AuxAresta = Aux->aresta;
      while(AuxAresta != NULL){
        Grau++;
        AuxAresta = AuxAresta->aresta;}
      break;}
    Aux = Aux->vertice;
  }
  printf("\nO Grau do vertice [%s] é %i\n", vertice, Grau);
  
}

void VizinhoOuNao(Grafo *grafo){
  Grafo *Aux = grafo, *AuxAresta;
  int cont = 0;
  char vertice[20], verticeVizinho[20];
  PrintVertice(grafo);
  printf("Qual é o vertice?:");
  scanf("%s", vertice);
  printf("Quem é o vizinho?;");
  scanf("%s", verticeVizinho);
  while( Aux != NULL){
    if(strcmp(Aux->nome, vertice)==0){
      AuxAresta = Aux->aresta;
      while(AuxAresta != NULL){
        if(strcmp(AuxAresta->nome, verticeVizinho)==0){
          cont = 1;
        }
        AuxAresta = AuxAresta->aresta;}
      break;}
    Aux = Aux->vertice;
  }
  if(cont == 0){
    printf("\n%s nao e vizinho de %s\n", vertice, verticeVizinho);
  } else{
    printf("\n%s e vizinho de %s\n", vertice, verticeVizinho);
  }
}




int main(void) {
  int opcao, parada=0;
  Grafo *grafo = CriarGrafo();
  do{
    PrintVertice(grafo);
    PrintAresta(grafo);
    printf("\n1 - Criar Vertices\n");
    printf("2 - Criar Arestas\n");
    printf("3 - Remover Vertice\n");
    printf("4 - Remover Aresta\n");
    printf("5 - Determinar Grau do Vertice\n");
    printf("6 - Vertice Vizinho de Verice\n");
    printf("7 - Ciclo euleriano\n");
    printf("8 - Sair\n");
    printf("Digite o numero:");
    scanf("%i", &opcao);
    switch(opcao){
      case 1: CriarVertice(grafo); break;
      case 2: CriarAresta(grafo); break;
      case 3: RemoverVertice(grafo); break;
      case 4: RemoverAresta(grafo); break;
      case 5: GrauVertice(grafo); break;
      case 6: VizinhoOuNao(grafo); break;
      case 8: parada = 1; break;
    }
  } while(parada == 0);
  return 0;
}