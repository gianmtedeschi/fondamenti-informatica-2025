#include <stdio.h>
#include <stdlib.h>

#define NUMEROPERSONE 20
#define DIMCOGNOME 20
#define DIMNOME 20

typedef struct {
    int giorno, mese, anno;
} Data;

typedef struct {
    char cognome[DIMCOGNOME], nome[DIMNOME], sesso;
    Data nascita;
} Persona;


int readField(char buffer[], char sep, FILE *f) {
    int i = 0;
    char ch = fgetc(f);
    
    while (ch != sep && ch != 10 && ch != EOF ) {
        buffer[i] = ch;
        i++;
        ch = fgetc(f);
    }
    
    buffer[i] = '\0';
    return ch;
}

void lettura(char nomefile[], Persona v[], int* pindice) {
    Persona x;
    int more = 1;
    FILE *f = fopen(nomefile, "r");
    *pindice = 0;
    if (f == NULL){
        printf("Impossibile aprire file di ingresso");
        exit(1);
    }

    do {
        more = readField(x.cognome, ';', f);
        more = more && readField(x.nome, ';', f);
        more = more && fscanf(f, "%d/%d/%d %c\n",
        &x.nascita.giorno,
        &x.nascita.mese,
        &x.nascita.anno,
        &x.sesso);
        if(more) {
            v[*pindice] = x;
            (*pindice)++;
        }
    } while(more);

    fclose(f);
}

int compatibili(Persona p1, Persona p2) {
    int compSesso, compAnno;
    compSesso = (p1.sesso != p2.sesso);
    compAnno = abs(p1.nascita.anno - p2.nascita.anno) <= 5;
    
    return compSesso && compAnno;
}

int main(){
    Persona elenco[NUMEROPERSONE], utente;
    int indiceElenco = 0, i;
    FILE *fbin;
    
    lettura("people.txt", elenco, &indiceElenco);
    
    printf("\n\nNome e cognome: ");
    gets(utente.nome);
    gets(utente.cognome);
    
    printf("data di nascita (gg/mm/aaaa): ");
    scanf("%d/%d/%d",
        &utente.nascita.giorno,
        &utente.nascita.mese,
        &utente.nascita.anno);
        
    /* sopprime il fine linea rimasto sull'input */
    scanf("%*c");
    printf("Inserire il sesso (M/F): ");
    scanf("%c%*c",&utente.sesso);
    
    fbin = fopen("partners.dat", "wb");
    if (fbin==NULL) {
        printf("Impossibile aprire file di uscita\n");
        exit(2);
    }
    
    printf("Compatibili con %s %s:\n",utente.nome,utente.cognome);
    for (i=0; i<indiceElenco; i++){
        if (compatibili(utente,elenco[i])) {
            fwrite(&elenco[i], sizeof(Persona), 1, fbin);
            printf("%s %s nato(a) il %d/%d/%d\n",
            elenco[i].nome,
            elenco[i].cognome,
            elenco[i].nascita.giorno,
            elenco[i].nascita.mese,
            elenco[i].nascita.anno);
        }
    }

    fclose(fbin);
}