#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int min(int a, int b) { return a < b ? a : b; }

int main(int argc, char *argv[]) {
	FILE *fp;
	int i, start, end, width, left, count;
	unsigned char *buf;
	if(argc != 5) {
		fprintf(stderr, "Usage: %s <source> <start> <end> <width>\n", argv[0]);
		exit(2);
	}
	if((fp = fopen(argv[1], "r")) == NULL) { perror("fopen"); exit(2); }
	start = atoi(argv[2]);
	end	= atoi(argv[3]);
	width = atoi(argv[4]);
	left = end - start;
	if((buf = malloc(width)) == NULL) {
		fprintf(stderr, "No memory?!?\n");
		exit(2);
	}
	if(fseek(fp, start, SEEK_SET)) { perror("fseek"); exit(2); }
	while(left > 0 && (count = fread(buf, 1, min(left, width), fp))) {
		for(i = 0; i < count; i++)	 printf("%02X ", buf[i]);
		for(i = 0; i < width - count; i++) printf("   ");
		printf(": ");
		for(i = 0; i < count; i++) printf("%c", isgraph(buf[i]) ? buf[i] : '.');
		printf("\n");
		left -= count;
	}
	free(buf);
	return 0;
}

