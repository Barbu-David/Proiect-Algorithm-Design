#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include"lobster.h"

int main(int argc, char* argv[])
{	

	//Variable declaration

	unsigned long long bag_size, lobster_number=0;
	clock_t start, end;

	start=clock();

	FILE *input, *output;  // I/O files

	lobster* lobster_collection=malloc(sizeof(lobster)); // vector to keep track of all avalible lobsters

	// I/O intitialization

	input=fopen(argv[1], "r");
	output=fopen("output","w");

	// Error handling

	if(argc!=2){
	       
		fprintf(stderr, "The progam needs exactly one file as a command line argument");
		return 1;
	}

	if(input == NULL || output == NULL)
	{
		fprintf(stderr, "Failed to open files");
		return 2;
	}

	
	//Input

	fscanf(input,"%llu",&bag_size);
	
	//Reading each lobsters attributes in the lobster collection. It is assumed the input is correctly formatted
	while(fscanf(input,"%s %llu %llu",
				lobster_collection[lobster_number].name,
				&lobster_collection[lobster_number].size,
				&lobster_collection[lobster_number].value)
			!=EOF)
		if(lobster_collection[lobster_number].size<=bag_size) //Only  consider the lobsters if they can fit in the bag
		{
			lobster_number++;
			lobster_collection=realloc(lobster_collection, sizeof(lobster)*(lobster_number+2));
		}



	//Function call
	

	dynamic_programming_lobster(lobster_collection, lobster_number, bag_size, output);


	end=clock();

	fprintf(output, "\n Time: %lf seconds ", (double)((end-start))/CLOCKS_PER_SEC);
		
	//Cleaning up

	free(lobster_collection);

	fclose(input);
	fclose(output);

	return 0;
}
