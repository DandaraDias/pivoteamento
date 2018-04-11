#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double matrizd[4][5]={M_PI, -M_E, M_SQRT2, -sqrt(3), sqrt(11), pow(M_PI, 2), M_E, -pow(M_E, 2), 3./7., 0, sqrt(5), -sqrt(6), 1., -M_SQRT2, M_PI, pow(M_PI, 3), pow(M_E, 2), -sqrt(7), 1./9., M_SQRT2};
	int i, j;
	
	FILE *letraD;
	
	letraD = fopen("letraD.dat", "w");
	
	fprintf(letraD, "4\n");
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<5; j++)
		{
			fprintf(letraD, "%.2lf\t", matrizd[i][j]);
		}
		fprintf(letraD, "\n");

	}
	
	return 0;
}
