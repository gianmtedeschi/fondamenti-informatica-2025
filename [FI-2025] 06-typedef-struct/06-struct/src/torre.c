int p, u; /* indice di piano nell’edificio e di ufficio nel piano */

for (p = 0; p < 20; p++)
    for (u = 0; u < 40; u++)
	if ((torre[p][u].esp == sudEst || torre[p][u].esp == sud) &&
	    (torre[p][u].superficie >=20 && torre[p][u].superficie<=30)) {
	    printf("\n il Signor %s è impiegato di categoria %d",
		   torre[p][u].occupante.cognome,
		   torre[p][u].occupante.cat);
	    printf("e ha uno stipendio pari a %d euro \n",
              torre[p][u].occupante.stipendio);
	}
