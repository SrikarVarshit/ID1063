#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void uniform(char *str, int leN)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}


void binaryVector(int n)
{
    double x;

    // Generate n random numbers using uniform() function
    uniform("binary.dat", n);

    FILE *fp = fopen("binary.dat", "r");

    // Convert the random numbers into 0 or 1
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%lf", &x);

        if (x < 0.5)
            printf("0");
        else
        printf("1");
    }
    printf("\n");

    
    fclose(fp);
}

int main(){
	srand(time(NULL));
	printf("Enter n ");
	int n;
	scanf("%d",&n);
	binaryVector(n);
}
