#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRES 1000000

#define NTAB 30000
#define NKEY 50

int result[MAXRES][2];

void initResult() {
	memset(result, -1, MAXRES*2 * sizeof(int));
}

void afficheKeys(int i, short nKeys[NTAB], short tKeys[NTAB][NKEY]) {
	for (int j = 0 ; j < nKeys[i] ; j++) {
		printf("%d ", tKeys[i][j]);
	}
	printf("\n");
}

int score(int nLot, int i1, int i2, short nKeys[2][NTAB], short tKeys[2][NTAB][NKEY]) {
	int n1 = nKeys[nLot][i1];
	int n2 = nKeys[nLot][i2];
	int c = 0;

	//afficheKeys(i1, nKeys, tKeys);
	//afficheKeys(i2, nKeys, tKeys);

	//printf("soore i1=%d i2=%d\n", i1, i2);
	//printf("soore n1=%d n2=%d\n", n1, n2);

	for (int i = 0 ; i < n1 ; i++) {
		for (int j = 0; j < n2 ; j++) {
			if (tKeys[nLot][i1][i] == tKeys[nLot][i2][j]) {
				c++;
				break;
			}
		}
	}
	
	n1 -= c;
	n2 -= c;

	if (n1 < c) {
		c = n1;
	}

	if (n2 < c) {
		c = n2;
	}

	return c;
}

int lireLigne(int nKey, int nCount[2], int nIndex[2][NTAB], short nKeys[2][NTAB], short tKeys[2][NTAB][NKEY]) {
	char cTyp;
	int index;

	scanf(" %c", &cTyp);

	if (cTyp == 'L') {
		cTyp = 0;
	} else if (cTyp == 'P') {
		cTyp = 1;
	} else {
		exit(1);
	}

	index = nCount[cTyp];

	nIndex[cTyp][index] = nKey;

	scanf(" %hd", &nKeys[cTyp][index]);
	
	//printf("nKey=%d cTyp=%d index=%d keys=%d nCount=%d\n", nKey, cTyp, index, nKeys[cTyp][index], nCount[cTyp]);

	for (int i = 0 ; i < nKeys[cTyp][index] ; i++) {
		scanf(" %hd", &tKeys[cTyp][index][i]);
	}

	nCount[cTyp]++;

	return nKeys[cTyp][index];
}


int optimeLot(int nTot, int nKeyMax) {
	int produit = nTot * nKeyMax * nKeyMax;
	int nPak;

	if (produit >= 60000000) {
		nPak = 3200;
	}
	else if (produit >= 40000000){
		nPak = 5800;
	}
	else if (produit >= 30000000){
		nPak = 6400;
	}
	else if (produit >= 5000000) {
		nPak = 30000;
	}	
	else if (produit >= 5000000) {
		nPak = 30000;
	}
	else if (produit >= 1000000) {
		nPak = 30000;
	}
	else if (produit >= 5000000) {
		nPak = 30000;
	} else {
		nPak = 30000;
	}

	return nPak;
}

void outputLot(int nLot, int nCount[2], int nIndex[2][NTAB], short nKeys[2][NTAB], short tKeys[2][NTAB][NKEY], int nKeyMax,int* pnRes, int resultat[MAXRES][2]) {
	int total = nCount[nLot];
	int pos = 0;

	for (int i = 0 ; i < total ; i++) {
		int imax = -1;
		int smax = -1;

		if (nLot == 0) {
			result[*pnRes][0] = nIndex[nLot][pos];
			*pnRes = *pnRes + 1;
		} else if (nLot == 1) {
			result[*pnRes][i%2] = nIndex[nLot][pos];
			*pnRes = *pnRes + ( i % 2) ;
		}

		for (int j = 0; j < total ; j++) {
			if (pos == j) {
				continue;
			}
			if (nKeys[nLot][j] == -1) {
				continue;
			}
			
			int s = score(nLot, pos, j, nKeys, tKeys);	

			if (s > smax) {
				imax = j;
				smax = s;
				if (3 * smax >= nKeyMax) break;
			}
		}
		
		nKeys[nLot][pos] = -1;
		pos = imax;
	}

	nCount[nLot] = 0;
}

int main() {
	int nCount[2];
	int nIndex[2][NTAB];
	short nKeys[2][NTAB];
	short tKeys[2][NTAB][NKEY];
	
	int nKeyMax = 0;
	int nRes = 0;
	int nTot = 0;
	int nLot = NTAB;

	nCount[0] = 0;
	nCount[1] = 0;

	initResult();

	scanf(" %d", &nTot);

	nLot = 650; 

	for (int nKey=0 ; nKey < nTot ; nKey ++) {
		int k = lireLigne(nKey, nCount, nIndex, nKeys, tKeys);
		if (nKeyMax == 0) {
			nKeyMax = k;
			nLot = optimeLot(nTot, nKeyMax);
		}

		if (nCount[0] == nLot) {
			outputLot(0, nCount,  nIndex, nKeys, tKeys, nKeyMax, &nRes, result);
		}

		if (nCount[1] == nLot) {
			outputLot(1, nCount, nIndex, nKeys, tKeys, nKeyMax, &nRes, result);
		}
	}
	//printf("nCount[0]=%d\n", nCount[0]);
	//printf("nCount[1]=%d\n", nCount[1]);
	outputLot(0, nCount,  nIndex, nKeys, tKeys, nKeyMax, &nRes, result);
	outputLot(1, nCount, nIndex, nKeys, tKeys, nKeyMax, &nRes, result);

	printf("%d\n", nRes);
	for (int i = 0 ; i < nRes ; i++) {
		if (result[i][1] == -1) {
			printf("%d\n", result[i][0]);
		} else {
			printf("%d %d\n", result[i][0], result[i][1]);
		}
	}
}
