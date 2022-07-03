#include <stdio.h>
#define MAX_SIZE 20

struct Matrix {
 float array[MAX_SIZE][MAX_SIZE];
 int m,n;
};

struct Matrix readMatrix(){

	struct Matrix matrice;
	scanf("%d%d",&matrice.m,&matrice.n);
	//printf("\n\n");

	for(int i=0;i<matrice.m;i++){
		for (int j=0;j<matrice.n;j++)
			scanf("%f",&matrice.array[i][j]);
	}

	return matrice;
}

void printMatrix(struct Matrix matrice){

	printf("\n\n");
	for(int i=0;i<matrice.m;i++){
		for (int j=0;j<matrice.n;j++){
			printf("%f ",matrice.array[i][j]);
		}
		printf("\n");
	}
}

int addMatrix(struct Matrix *matrice_a,struct Matrix *matrice_b,struct Matrix *matrice_add){


	if((*matrice_a).m == (*matrice_b).m && (*matrice_a).n == (*matrice_b).n){
			
		for(int i=0;i< (*matrice_a).m;i++){
			for (int j=0;j< (*matrice_a).n;j++)
				(*matrice_add).array[i][j] = (*matrice_a).array[i][j] + (*matrice_b).array[i][j];
		}

		for(int i=0;i<(*matrice_a).m;i++){
			for (int j=0;j<(*matrice_a).n;j++)
				printf("%f ",(*matrice_add).array[i][j]);
		
			printf("\n");

		}

		return 1;
	}

	else
		return 0;
}

int subMatrix(struct Matrix *matrice_a,struct Matrix *matrice_b,struct Matrix *matrice_sub){

	if((*matrice_a).m == (*matrice_b).m && (*matrice_a).n == (*matrice_b).n){
			
		for(int i=0;i<(*matrice_a).m;i++){
			for (int j=0;j<(*matrice_a).n;j++)
				(*matrice_sub).array[i][j] = (*matrice_a).array[i][j] - (*matrice_b).array[i][j];
		}

		for(int i=0;i<(*matrice_a).m;i++){
			for (int j=0;j<(*matrice_a).n;j++)
				printf("%f ",(*matrice_sub).array[i][j]);
		
			printf("\n");
		}

		return 1;
	}

	else
		return 0;

}

int mulMatrix(struct Matrix *matrice_a,struct Matrix *matrice_b,struct Matrix *matrice_mul){


	if((*matrice_a).n == (*matrice_b).m){
		for(int i=0;i<(*matrice_a).m;i++)
			for (int j=0;j<(*matrice_b).n;j++)
				(*matrice_mul).array[i][j] = 0;

		for(int i=0;i<(*matrice_a).m;i++)
			for (int j=0;j<(*matrice_b).n;j++)
				for (int k = 0; k < (*matrice_a).n; ++k)
					(*matrice_mul).array[i][j] += (*matrice_a).array[i][k] * (*matrice_b).array[k][j]; 

		
		for(int i=0;i<(*matrice_a).n;i++){
			for (int j=0;j<(*matrice_b).n;j++)
				printf("%f ",(*matrice_mul).array[i][j]);
		
			printf("\n");

		}

		return 1;
	}

	else
		return 0;
}

int main(){

	struct Matrix matrice_A;
	matrice_A = readMatrix();
	printMatrix(matrice_A);

	printf("\n\n");

	struct Matrix matrice_B;
	matrice_B = readMatrix();
	printMatrix(matrice_B);

	struct Matrix *matrice_sub,*matrice_add,*matrice_mul, *matriceA= &matrice_A , *matriceB = &matrice_B;

	printf("\n\n");

	printf("Enter an operator (+, -, *) ");
	
	char operator;
	fflush(stdin);
	scanf("%c",&operator);
	
	switch (operator){

		case '+':
			printf("addition of A & B is:\n");
			addMatrix(matriceA,matriceB,matrice_add);
			break;


		case '-':
			printf("substraction of A & B is:\n");
            subMatrix(matriceA,matriceB,matrice_sub);
            break;

        case '*':
        	printf("multiplication of A & B is:\n");
            mulMatrix(matriceA,matriceB,matrice_mul);
            break;

        default:
            printf("AKH(OUCH)!U MADE A MISTAKE.");
	}

	return 0;	
}



