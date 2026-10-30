# define MAX_SQUADRE 20
# define MAX_COGNOME 20
# define MAX_NOME 30
# define MAX_CALCIATORI 23

typedef struct{
    char cognome[MAX_COGNOME + 1];
    int eta;
    int maglia;
    int presenze;
    int gol;
}Calciatore;

typedef struct{
    char nome[MAX_NOME + 1];
    int punti;
    Calciatore calciatore[MAX_CALCIATORI];
}Squadra;

typedef Squadra Campionato[MAX_SQUADRE];
