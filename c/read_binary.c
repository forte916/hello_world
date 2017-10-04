/**
 * @brief    Show a GIF header info.
 *
 * Input:
 *     Pass the path of GIF file to this script.
 *
 *     A pseudocode of GIF header format.
 *         struct {
 *             char  signature[3];
 *             char  version[3];
 *             u16   logicalScreenWidth;
 *             u16   logicalScreenHeight;
 *             u8    flags; //GCTF 1bit, CR 3bit, SF 1bit, SGCT 3bit
 *             u8    backgroundColorIndex;
 *             u8    pixelAspectRatio;
 *             struct {
 *                 u8 R;
 *                 u8 G;
 *                 u8 B;
 *             } globalColorTable[n]; // 0 <= n <= 255
 *         } GIF_header;
 * 
 * Output:
 *     A GIF header info.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void usage(const char* prog)
{
    printf("Usage:  %s example.gif\r\n", prog);
    exit(1);
}

typedef struct _PALETTE {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} PALETTE, *PPALETTE;

typedef struct _gif_header {
	char sig[3+1];
	char ver[3+1];
	unsigned short width;
	unsigned short height;
	unsigned char flags;
	unsigned char bgidx;
	unsigned char ratio;
	int gcgf;
	int cr;
	int sf;
	int sgct;
	int table_size;

	PPALETTE pgct;
} gif_header;

void show_GIF_header_info(const gif_header* h)
{
	printf("Sig   : %s\r\n", h->sig);
	printf("Ver   : %s\r\n", h->ver);
	printf("Width : %d\r\n", h->width);
	printf("Height: %d\r\n", h->height);
	//printf("Flags : %s\r\n", format(h->flags, "b")); //TODO:implement format()
	printf("Flags : %X\r\n", h->flags); //TODO:implement format()
	printf("    GCGF: %d\r\n", h->gcgf);
	printf("    CR  : %d\r\n", h->cr);
	printf("    SF  : %d\r\n", h->sf);
	printf("    SGCT: %d\r\n", h->sgct);
	printf("    Size: %d\r\n", h->table_size);
	printf("BgIdx : %d\r\n", h->bgidx);
	printf("Ratio : %x\r\n", h->ratio);

    printf("Palette: [");
	int palette_size = (int) h->table_size / 3;
	for (int i = 0; i < palette_size; i++) {
		PPALETTE pgct = (h->pgct)+i;
		printf("(%X,%X,%X), ", pgct->R, pgct->G, pgct->B);
	}
    printf("]\r\n");
}

void read_GIF_header(const char* infile)
{
	FILE* fin = fopen(infile, "rb");
	if (fin == NULL) {
		printf("fopen: ERROR: Could not open a file.\r\n");
		return;
	}

	gif_header h;
    memset(&h, 0, sizeof(h));

	fread(&h.sig, sizeof(h.sig) - 1, 1, fin);
	if (strncmp(h.sig, "GIF", 3) != 0) {
		printf("Invalid GIF signature: %s\r\n", h.sig);
        goto error;
	}

	fread(&h.ver, sizeof(h.ver) - 1, 1, fin);
	if (strncmp(h.ver, "87a", 3) != 0
			&& strncmp(h.ver, "89a", 3) != 0) {
		printf("Invalid GIF version: %s\r\n", h.ver);
        goto error;
	}

	fread(&h.width, sizeof(h.width), 1, fin);
	fread(&h.height, sizeof(h.height), 1, fin);

	fread(&h.flags, sizeof(h.flags), 1, fin);
	fread(&h.bgidx, sizeof(h.bgidx), 1, fin);
	fread(&h.ratio, sizeof(h.ratio), 1, fin);

	h.gcgf = (h.flags >> 7) & 1;
	h.cr   = (h.flags >> 4) & 7;
	h.sf   = (h.flags >> 3) & 1;
	h.sgct = h.flags & 7;
	h.table_size = (2 << h.sgct) * 3;

	if (h.gcgf == 1) {
		PPALETTE pgct =  malloc(h.table_size);
		fread(pgct, h.table_size, 1, fin);
		h.pgct = pgct;
	}

	fclose(fin);
	show_GIF_header_info(&h);
	return;

error:
	fclose(fin);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		usage(argv[0]);
	}

	read_GIF_header(argv[1]);
	return 0;
}


/**
 * How to run

gcc -o a.exe read_binary.c
./a.exe example.gif

 */
