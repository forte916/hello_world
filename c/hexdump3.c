#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void displayHexRecord(char *data, int count, int record_length) {
	int	i;
	for (i=0; i < count; i++) printf("%02x ", data[i] & 0xff);
	for (; i < record_length; i++) printf("   ");
	printf(": ");
	for (i=0; i < count; i++) {
		if (isgraph(data[i])) putchar(data[i]);
		else		  putchar('.');
	}
	putchar('\n');
}

void hexDump(FILE *f, long cur_addr, long end, int bytes_per_line) {
	int	record_length, read_count;
	char	*data;
	assert(data = (char*) calloc(sizeof(data[0]), bytes_per_line));
	if (-1 == fseek(f, cur_addr, SEEK_SET)) perror("fseek");
	while (1) {
		printf("%05x  ", cur_addr);
		read_count = end - cur_addr;
		if (read_count > bytes_per_line) read_count = bytes_per_line;
		record_length = fread(data, sizeof(char), read_count, f);
		displayHexRecord(data, record_length, bytes_per_line);
		if (record_length < bytes_per_line) break;
		if (end <= (cur_addr += record_length)) break;
	}
	free(data);
}

int main(void) {
	FILE *f = fopen("a.out", "r");
	if (f == NULL) {
		perror("a.out");
		exit(1);
	}
	hexDump(f, 0, 100, 16);
	return 0;
}

