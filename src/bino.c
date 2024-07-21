#include <stdio.h>
#include <stdlib.h>



void zerome (unsigned char *buffer, int length) {
	for (int i = 0; i < length; ++i) {
		buffer[i] = 0;
	}
}


int main (int argc, char const *argv[])
{
	int number_of_bytes_to_read = 16;
	int number_of_times_to_read = 4;

	if (argc == 1) {
		printf("Usage:\n\tbino $filepath\n");
		return 0;
	}

	const char *filepath = argv[1];

	if (argc > 2) {
		number_of_bytes_to_read = atoi(argv[2]);
		if (argc > 3) {
			number_of_times_to_read = atoi(argv[3]);
		}
	}

	FILE *ptr = fopen(filepath,"rb");
	if (ptr == NULL) {
		printf("File not found: %s\n", filepath);
		return 0;
	}

	unsigned char *buffer = NULL;
	int buffer_size = number_of_bytes_to_read;
	buffer = malloc(number_of_bytes_to_read);

	for (int i = 0; i < number_of_times_to_read; ++i) {
		printf("Line %3d [%d]:", i+1, number_of_bytes_to_read);

		int result = fread(buffer, buffer_size, 1, ptr);
		for (int j = 0; j < buffer_size; j++) {
			if (j > 0 && j % 4 == 0) {
				printf(" . ");
			} else {
				printf(" ");
			}

			printf("%2x", buffer[j]);
		}

		printf("\n");

		if (result == 0) {
			printf("End of file reached!\n");
			break;
		} else {
			zerome(buffer, buffer_size);
		}
	}

	fclose(ptr);
	free(buffer);

	return 0;
}
