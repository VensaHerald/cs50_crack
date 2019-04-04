#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <unistd.h>

//char *crypt(const char *key, const char *salt);
// define the length of the alphabet to generate test passwords
#define DICT_LEN 52


int main(int argc, char *argv[])
{

	// If more or less than one argument provided then return usage
	if (argc != 2) {printf("Usage: ./crack hash\n"); return 0;};
	
	// if correct args provided, get test_hash from argv
	char * test_hash = *(argv+1);
	
	// reject any invald length input.  Could cause overflow later when checking correct pass
	if (strlen(test_hash) != 13){printf("Usage: ./crack hash[13]\n"); return 0;};
	
	// string with relevant chars to create test password from
	const char * string_dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	// copy salt from input hash, initialise with null and copy with strncpy to prevent overflow
	char salt[3] = {'\0'};
	strncpy(salt,test_hash,2);
	
	
	// string with null chars to hold test keys
	char test_key[6] = {'\0'};
	
	// Start with len 1 key and loop from there.  
	int key_len = 1;
	printf("Checking:\n");
	while(key_len <= 5)
	{
		fflush(stdout);
		//printf("\nkeylen:%i\n",key_len);
		
		for(int i0 = 0; i0 < DICT_LEN; i0++) 
		{
			test_key[0] = string_dict[i0];
			
			for(int i1 = 0; i1 < DICT_LEN; i1++) 
			{
				if (key_len == 1)break;
				test_key[1] = string_dict[i1];
				printf("\r%s",test_key);
				fflush(stdout);
				if (strcmp(crypt(test_key,salt), test_hash)==0) {printf("\nFound ^^^^\n");return 0;}
				
				for(int i2 = 0; i2 < DICT_LEN; i2++) 
				{
					if (key_len == 2)break;
					test_key[2] = string_dict[i2];
					printf("\r%s",test_key);
					fflush(stdout);
					if (strcmp(crypt(test_key,salt), test_hash)==0) {printf("\nFound ^^^^\n");return 0;}
					
					for(int i3 = 0; i3 < DICT_LEN; i3++) 
					{
						if (key_len == 3)break;
						test_key[3] = string_dict[i3];
						printf("\r%s",test_key);
						fflush(stdout);
						if (strcmp(crypt(test_key,salt), test_hash)==0) {printf("\nFound ^^^^\n");return 0;}
						
						for(int i4 = 0; i4 < DICT_LEN; i4++) 
						{
							if (key_len == 4)break;
							test_key[4] = string_dict[i4];
							printf("\r%s",test_key);
							fflush(stdout);
							if (strcmp(crypt(test_key,salt), test_hash)==0) {printf("\nFound ^^^^\n");return 0;}
							
						}
					}
				}
			}
			printf("\r%s",test_key);
			fflush(stdout);
			if (strcmp(crypt(test_key,salt), test_hash)==0) {printf("\nFound ^^^^\n");return 0;}
		}
			
		key_len++;
	}

}
