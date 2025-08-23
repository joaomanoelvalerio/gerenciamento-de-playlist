#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Definição da estrutura Playlist
typedef struct {
    int musicas[MAX];
    int total;
} Playlist;

// --- Implementação das Funções ---

void criarPlaylist(Playlist *p) {
    p->total = 0;
}

int estaCheia(Playlist *p) {
    return (p->total == MAX);
}

int adicionarMusica(Playlist *p, int idMusica) {
    if (estaCheia(p)) {
        return 0; 
    }
    
    p->musicas[p->total] = idMusica;
    p->total++;
    
    return 1;
}

int removerMusica(Playlist *p, int posicao) {
    if (p->total == 0 || posicao < 0 || posicao >= p->total) {
        return 0;
    }

    int i;
    for (i = posicao; i < p->total - 1; i++) {
        p->musicas[i] = p->musicas[i+1];
    }
    
    p->total--;
    
    return 1;
}

int buscarMusica(Playlist *p, int idMusica) {
    int i;
    for (i = 0; i < p->total; i++) {
        if (p->musicas[i] == idMusica) {
            return i;
        }
    }
    return -1;
}

void mostrarPlaylist(Playlist *p) {
    int i;
    printf("Sua playlist tem %d musicas:\n", p->total);
    printf("[ ");
    for (i = 0; i < p->total; i++) {
        printf("%d", p->musicas[i]);
        if (i < p->total - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

// --- Função Principal (main) ---

int main() {
    Playlist minhaPlaylist;
    criarPlaylist(&minhaPlaylist);
    
    int option;
    int idMusica, posicao;
    
    printf("=== MINHA PLAYLIST ===\n");
    printf("1. Adicionar musica\n");
    printf("2. Remover musica\n");
    printf("3. Buscar musica\n");
    printf("4. Mostrar playlist\n");
    printf("5. Sair\n\n");
    
    do {
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Digite o ID da música: ");
                scanf("%d", &idMusica);
                if (adicionarMusica(&minhaPlaylist, idMusica)) {
                    printf("Musica adicionada!\n");
                } else {
                    printf("Erro: Playlist cheia.\n");
                }
                break;
            case 2:
                printf("Digite a posição para remover: ");
                scanf("%d", &posicao);
                if (removerMusica(&minhaPlaylist, posicao)) {
                    printf("Musica da posição %d removida!\n", posicao);
                } else {
                    printf("Erro: Posicao invalida.\n");
                }
                break;
            case 3:
                printf("Digite o ID da musica para buscar: ");
                scanf("%d", &idMusica);
                posicao = buscarMusica(&minhaPlaylist, idMusica);
                if (posicao != -1) {
                    printf("Musica %d encontrada na posicao: %d\n", idMusica, posicao);
                } else {
                    printf("Musica não encontrada.\n");
                }
                break;
            case 4:
                mostrarPlaylist(&minhaPlaylist);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        printf("\n");
        
    } while (option != 5);
    
    return 0;
}