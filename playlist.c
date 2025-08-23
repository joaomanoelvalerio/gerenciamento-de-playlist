#include <stdio.h>

#define MAX 20

typedef struct {
    int musicas[MAX];
    int total;
} Playlist;

void criarPlaylist(Playlist *p) {
    p->total = 0;
};

int estaVazia(Playlist *p) {
    return (p->total == 0);
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
