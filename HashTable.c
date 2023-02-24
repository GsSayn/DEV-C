#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MOTS 90947


unsigned int FNVHash(char* str, unsigned int length);
int probe(int i0, int k, int S);

void initTab(int taille, char* liste[]){
    char tab[50];

    for(char* retour = fgets(tab, 50, stdin); retour != NULL; retour = fgets(tab, 50, stdin)) {
        int i0 = 0;
        int l = strlen(retour);
        retour[l - 1] = 0;
        
        i0 = FNVHash(retour, l - 1) % taille;
        
        for(int k = 0;;k++){
            int index = probe(i0, k, taille);

            if(liste[index] == NULL){
                liste[index] = strdup(retour);
                printf("tab[%d]=%s (%d)\n", index, retour, k);
                break;
            }
        }
    }
}

void afficherTab(int taille, char* liste[]){
    for(int i = 0; i < taille; i++){
        printf("%s:%d\n", liste[i], FNVHash(liste[i], strlen(liste[i])));
    }    
}

int fctRechercheBete(char* motsRecherche, int taille, char* liste[]){
    for(int i = 0; i < taille; i++) {
        if (strcmp(motsRecherche, liste[i]) == 0){
            return 1;
        }
    }
    return 0;
}


int fctRecherche(char* motsRecherche, int taille, char* liste[]){
    int i0 = FNVHash(motsRecherche, strlen(motsRecherche)) % TAILLE_MOTS; 

    for(int k = 0;;k++) {
        int index = probe(i0, k, taille);
        if(liste[index] == NULL){
            return 0;
        }
        else if(strcmp(motsRecherche, liste[index]) == 0){
            printf("Trouvé K = %d\n", k);
            return 1;
        }
    }
    return 0;
}

unsigned int FNVHash(char* str, unsigned int length) {
	const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < length; str++, i++)
	{
		hash *= fnv_prime;
		hash ^= (*str);
	}

	return hash;
}

int probe(int i0, int k, int S){
    return (i0 + k*k) % S;
}

void aideRecherche(char* motsRecherche, char* mots[]){
    printf("%s:%d\n", motsRecherche, fctRecherche(motsRecherche,TAILLE_MOTS, mots)); 
}

int main() {
    char* mots[TAILLE_MOTS];

    memset(mots, 0, TAILLE_MOTS * sizeof(char*));

    initTab(TAILLE_MOTS, mots);

    aideRecherche("chat",mots);
    aideRecherche("emballer",mots);
    aideRecherche("zebre",mots);
    aideRecherche("omettre",mots);    
}
