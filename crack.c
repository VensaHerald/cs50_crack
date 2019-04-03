#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <unistd.h>

//char *crypt(const char *key, const char *salt);

int main(int argc, char *argv[])
{
	//printf("%s\n", argv[1]);
	
	//if (argc != 2) printf("Usage: ./crack hash\n");
	
	
	
	//const char * test_salt = "51";
	//char * result = crypt(test_key, test_salt);
	//printf("%s\n", result);
	//strting to draw letters from
	const char * string_dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int dict_len = strlen(string_dict);
	char test_key[5] = {'\0'};
	
	int key_len = 1;
	printf("Checking:\n");
	while(key_len <= 5)
	{
		fflush(stdout);
		printf("\nkeylen:%i\n",key_len);
		for(int i0 = 0; i0 < dict_len; i0++) 
		{
			test_key[0] = string_dict[i0];
			for(int i1 = 0; i1 < dict_len; i1++) 
			{
				if (key_len == 1){test_key[1] = '\0'; break;}
				test_key[1] = string_dict[i1];
				printf("\r%s",test_key);
				fflush(stdout);
				for(int i2 = 0; i2 < dict_len; i2++) 
				{
					if (key_len == 2){test_key[2] = '\0'; break;}
					test_key[2] = string_dict[i2];
					printf("\r%s",test_key);
					fflush(stdout);
					for(int i3 = 0; i3 < dict_len; i3++) 
					{
						if (key_len == 3){test_key[3] = '\0'; break;}
						test_key[3] = string_dict[i3];
						printf("\r%s",test_key);
						fflush(stdout);
						for(int i4 = 0; i4 < dict_len; i4++) 
						{
							if (key_len == 4){test_key[4] = '\0'; break;}
							test_key[4] = string_dict[i4];
							printf("\r%s",test_key);
							fflush(stdout);
							
						}
					}
				}
			}
			printf("\r%s",test_key);
			fflush(stdout);
		}
			
		key_len++;
	}

}
