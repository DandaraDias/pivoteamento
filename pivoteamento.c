#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

double** ler(const char *nome, int *k)
{
	double **L;
	double a;
	int i, j, dim;
	
	FILE *ler;
	
	ler = fopen(nome, "r");
	i = fscanf(ler, "%d", &dim);
	
	L = malloc(dim*sizeof(double *));
	
	for(i=0; i<dim; i++)
	{
		L[i] = (double *)malloc((dim+1)*sizeof(double));
	}
	
	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim+1; j++)
		{
			fscanf(ler, "%lf", &a);
			L[i][j] = a;
		}
	}
	
	*k = dim;

	return L;
}

void imprime(double **M, int dim)
{
	int i, j;
	
	puts(" ");
	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim+1; j++)
		{
			printf("%.2lf\t", M[i][j]);
		}
		
		puts(" ");
	}
}

double** triangsup(double **M, int dim)
{
	int i, j, l;
	double lambda;

	for(j=0; j<dim+1; j++)
	{
		for(i=0; i<dim; i++)
		{
			if(i>j)
			{
				lambda = M[i][j]/M[j][j];
				
				for(l=0; l<dim+1; l++)
				{
					M[i][l] = M[i][l] - lambda*M[j][l];
				}
			}
		}
	}
	
	return M;
}

void subsreversa(double **M, double *raizes, int dim)
{
	int i, j;
	double soma;
	
	for(i=dim-1; i>=0; i--)
	{
		soma=0;
				
		for(j=i+1; j<dim; j++)
		{
			soma += M[i][j]*(raizes[j]);	
		}
			
		raizes[i] = (M[i][dim] - soma)/M[i][i];
	}
}

int pivoteamento(double **M, int dim)
{
        double l, pivot, maior, aux;
        int i, j, k, m, n;
        
        int cont=0;
        
        for(j=0; j<dim; j++)
        {	
			pivot = M[j][j];
			maior = pivot;

			for(k=j+1; k<dim; k++)
			{	
				if(fabs(maior) < fabs(M[k][j]))
				{	
					maior = M[k][j];
					m = k;
				}
			}

			if(maior != pivot)
			{	
				for(n=0; n<dim+1; n++)
				{
					aux = M[m][n];
					M[m][n] = M[j][n];
					M[j][n] = aux;
				}
				cont++;
			}

			for(i=j+1; i<dim; i++)
			{
				l = M[i][j]/M[j][j];       
                
                for(k=0; k<dim+1; k++)
                {
					M[i][k] -= l*M[j][k]; 
				}
			}   
		}
			
        imprime(M, dim);
        
        return cont;
}

void determinante(double **M, int dim, int cont)
{
	int i, j;
	double prod=1;
	
	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim; j++)
		{
			if(i==j)
			{
				prod = prod*M[i][i];
			}
		}
	}
	
	if(cont%2 == 0)
	{
		printf("Determinante = %g", prod);
	}
	else
	{
		prod = prod*-1.;
		printf("Determinante = %g", prod);
	}
	
}

int main(int argc, char **argv)
{
	double **M;
	double *raizes;
	int i, j, dim;
	
	int troca;
	
	printf("\nMatriz\n");
	M = ler(argv[1], &dim);
	imprime(M, dim);

	raizes = malloc(dim*sizeof(double));
	
	printf("\nPivoteando e triangularizando\n");
	troca = pivoteamento(M, dim);

	subsreversa(M, raizes, dim);
	printf("\nRaizes\n");
	for(i=0; i<dim; i++)
	{
		printf("\nx%1d = %5.2lf", i, raizes[i]);
	}
	puts("");
	
/*	printf("\nNúmero de troca de linhas: %d\n", troca);
	
	determinante(M, dim, troca);*/
	
	return 0;
}
