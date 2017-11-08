#include <stdio.h>
#include <string.h>

void Enc(char* plain, char* cipher, char key){
    int p_len = strlen(plain);
    for(int i = 0; i < p_len; i+=1){
        cipher[i] = plain[i] ^ key;
    }
}

void Dec(char* cipher, char* plain, char key){
    return Enc(cipher, plain, key);
}

int main(){
    char plain[5] = "abcd";
    char cipher[5] = "";
    char key = 0x80;
    Enc(plain, cipher, key);
    Dec(cipher, plain, key);
    printf("%s", plain);  // => "abcd"
}

