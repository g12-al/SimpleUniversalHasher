#include <stdio.h>
#include <string.h>


#define PRIMENUM 75604541 //251
#define PRIMENUM2 67867979
#define KEYLENGTH 37

char *generateHash(char *key, char *inputstring, int prime);
int generateModifier(char *inputstring, int smallprime);
char *convertToString(int *hash, int length);

int main(int argc, char **argv)
{
	if(argc == 1){
		printf("Please enter a string for an argument.\n");
		return 0;		
	}


	char key[] = "M2ws1nKloSm493az8I6th2^gsnAxQCo9";
	//char inputstring[] = "this is a test string";
	char *inputstring = argv[1];	
	
	int prime = PRIMENUM;
	int length = strlen(inputstring);

	char *outputstring = generateHash(key, inputstring, prime);

	printf("%s\n", outputstring);	

	return 0;
}

char *generateHash(char *key, char *inputstring, int prime)
{
	int i;
	int modifier = generateModifier(inputstring, PRIMENUM2);

	int *outputstring = malloc( sizeof(int) * strlen(key) );

	for(i = 0; i < strlen(key); i++)
	{
		outputstring[i] = inputstring[(i-20) % strlen(inputstring)] + modifier;
		outputstring[i] *= key[i]; 
		outputstring[i] %= prime;
		//printf("%d ", outputstring[i]);
	}
	//printf("\n");

	return convertToString(outputstring, strlen(key));
}


int generateModifier(char *inputstring, int smallprime)
{
	int i, mod = inputstring[0];

	for(i = 1; i < strlen(inputstring); i++)
	{
		mod *= inputstring[i];
		mod %= smallprime;
	}

	return mod;
}

char *convertToString(int *hash, int length)
{
	char *result = malloc( sizeof(int) * length);

	sprintf(result, "%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x",
			hash[0], hash[1], hash[2], hash[3],
			hash[4], hash[5], hash[6], hash[7],
			hash[8], hash[9], hash[10], hash[11],
			hash[12], hash[13], hash[14], hash[15]);
	return result;
}
	

