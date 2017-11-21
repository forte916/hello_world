/**
 * How to run
 *   $ gcc -o xor3 xor3.c
 *   $ ./xor3
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  //isgraph()


/**
 * @brief XOR calculation with a one byte key.
 *
 * @param[in]  plain  A source text.
 * @param[out] cipher A destination text to be encoded.
 * @param[in]  key    A key with one byte.
 */
void xor_enc_one_byte_key(char* plain, char* cipher, char key)
{
	int p_len = strlen(plain);
	for (int i = 0; i < p_len; i++) {
		cipher[i] = plain[i] ^ key;
	}
}

/**
 * @brief XOR calculation with a key which is shorter than a source text.
 *
 * @param[in]  plain  A source text.
 * @param[out] cipher A destination text to be encoded.
 * @param[in]  key    A key which is shorter than source text.
 */
void xor_enc_short_key(char* plain, char* cipher, char* key)
{
	int p_len = strlen(plain);
	int key_len = strlen(key);
	for (int i = 0; i < p_len; i++) {
		cipher[i] = plain[i] ^ key[i % key_len];
	}
}

/**
 * @brief XOR calculation with a key which is equal or longer than a source text.
 *        Which means stream cipher.
 *
 * @param[in]  plain  A source text.
 * @param[out] cipher A destination text to be encoded.
 * @param[in]  key    A key which is equal or longer than a source text.
 */
void xor_enc_stream_cipher(char* plain, char* cipher, char* key)
{
	int p_len = strlen(plain);
	int key_len = strlen(key);
	if (key_len < p_len) {
		printf("Invalid argument: key is shorter than source text.");
		return ;
	}
	for (int i = 0; i < p_len; i++) {
		cipher[i] = plain[i] ^ key[i];
	}
}


void print_hex_char(char *str)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		printf("%c", isgraph(str[i]) ? str[i] : '.');
	}
	printf("\n");
}


int main(void)
{
	char cipher[256] = {0};
	char key1    = 'A'; // 'A' == 65
	char key2[]  = "Abcd";
	char key3[]  = "Abcdabcdabciabcdabcd";
	char plain[] = "This is plain text";
	//                  v  v   v
	//key3 ^ plain:"    A  D   \0     "
	// If 'printable letter' xor 'blank space', the result is the UPPER/LOWER case letter.
	// If same letter, the result is the NUL(\0).

	printf("Original string:  ");
	printf("%s\n", plain);

	printf("---- Test case 1 ----\n");
	// encrypt
	xor_enc_one_byte_key(plain, cipher, key1);
	printf("Encrypted string: ");
	print_hex_char(cipher);
	// decrypt
	xor_enc_one_byte_key(cipher, plain, key1);
	printf("Decrypted string: ");
	print_hex_char(plain);


	printf("---- Test case 2 ----\n");
	// encrypt
	xor_enc_short_key(plain, cipher, key2);
	printf("Encrypted string: ");
	print_hex_char(cipher);
	// decrypt
	xor_enc_short_key(cipher, plain, key2);
	printf("Decrypted string: ");
	print_hex_char(plain);


	printf("---- Test case 3 ----\n");
	// encrypt
	xor_enc_stream_cipher(plain, cipher, key3);
	printf("Encrypted string: ");
	print_hex_char(cipher);
	// decrypt
	xor_enc_stream_cipher(cipher, plain, key3);
	printf("Decrypted string: ");
	print_hex_char(plain);

	return 0;
}
