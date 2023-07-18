#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToAscii(const char* hexString, char* asciiString) {
    size_t hexLen = strlen(hexString);
    size_t asciiLen = hexLen / 2;
    unsigned char* byteArr = (unsigned char*)malloc(asciiLen + 1);

    for (size_t i = 0, j = 0; j < asciiLen; ++i, ++j) {
        sscanf(hexString + (2 * i), "%2hhx", &byteArr[j]);
    }

    byteArr[asciiLen] = '\0';
    strcpy(asciiString, (char*)byteArr);

    free(byteArr);
}

int main() {
    const char* hexString = "a0dc6eba1ba449a51a58e532fafd1faa";
    char asciiString[17];

    hexToAscii(hexString, asciiString);

    printf("Decodificado: %s\n", asciiString);

    return 0;
}