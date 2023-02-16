#include "Files.hpp"

#include <stdio.h>
#include <stdlib.h>

std::pair<void*, long> read_file(const char *filename, const char *mode) {
	FILE *f = fopen(filename, mode);

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	rewind(f);

	void *buf = calloc(1, size+1);
	fread(buf, size, 1, f);
	fclose(f);
	return {buf, size};
}
