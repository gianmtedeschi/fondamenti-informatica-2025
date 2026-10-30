int uffNord; /* uffNord fa da flag*/

for (p = 0; p < 20; p++) {
    uffNord = 0; //per ogni piano assumo 0
    for (u = 0; u < 40 && !uffNord; u++)
	if(torre[p][u].esposizione == nord)
	    uffNord = 1;

    /* se qui vale ancora 0 vuol dire che non ci sono uffici a nord*/
    if (!uffNord)
	printf("il piano %d  non ha edifici esposti a nord", p);
 }

/* è corretto anche senza !uffNord nel for(), anche se non è efficiente. */
