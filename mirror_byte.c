//
// Created by maor on 09/11/2020.
//
#include <stdio.h>
#include <stdint.h>

uint8_t reverse2(uint8_t n);

unsigned char reverse(unsigned char b);

int main() {
    unsigned char c = 0b11000000;
    printf("%d", reverse(c));

    return 0;
}

static unsigned char lookup[16] = {
        0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
        0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf,};

unsigned char reverse(unsigned char b) {
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

uint8_t reverse2(uint8_t n) {
    // Reverse the top and bottom nibble then swap them.
    return (lookup[n & 0b1111] << 4) | lookup[n >> 4];
}