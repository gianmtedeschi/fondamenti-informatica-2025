Campionato serie_a;
Calciatore capocannoniere;
Squadra squadra_capocannoniere;
int i, j;

// inizializzazione capocannoniere
capocannoniere = serie_a[0].calciatore[0];
squadra_capocannoniere = serie_a[0];

// ricerca capocannoniere
for(i = 0; i < MAX_SQUADRE; i++)
    for(j = 0; j < MAX_CALCIATORI; j++)
        if(serie_a[i].calciatore[j].gol > capocannoniere.gol){
            capocannoniere = serie_a[i].calciatore[j];
            squadra_capocannoniere = serie_a[i];
        }

// stampa capocannoniere
printf("\ncapocannoniere: %s\n", capocannoniere.cognome);
printf("squadra: %s\n", squadra_capocannoniere.nome);
printf("numero di gol: %d\n\n", capocannoniere.gol);
