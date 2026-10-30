for(i = 0; i < 20; i++) { //scorre i piani
    noUfficiNord = 1; //versione con flag inversa

    for(j = 0; j < 40; j++) //senza flag arriva fino a 39
	if(torre[i][j].esposizione == nord)
	    noUfficiNord = 0;

    if(noUfficiNord) {
	printf("il piano %d non ha uffici a nord", i);
	stipendioMedio = 0;
	cnt = 0;
	for(j = 0; j < 40; j++)
	    if(strcmp(torre[i][j].occupante.nome, "Giacomo") == 0){
		stipendioMedio += torre[i][j].occupante.stipendio;
		cnt++;
	    }
	printf("Lo stipendio medio dei Giacomo nel "
	       "piano è %f ", stipendioMedio / cnt);
    }
 }
