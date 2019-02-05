/*
Lab 7
Main Memory - Address Translation
by Mathew Walker
*/

#define PAGE_NUMBER_MASK;
#define OFFSET_MASK
#define PAGES
#define OFFSET_BITS
#define PAGE_SIZE
#define BUFFER_SIZE 10


int main(int argo, const char *argv[])
{	
	FILE *fptr = fopen(argv[1],"r");
	char buff[BUFFER_SIZE];
	
	while(fgets(buff,BUFFER_SIZE,fptr) != NULL)
	{
		
	}

} 