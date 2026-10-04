#include <stdio.h>

void print_utf8(unsigned int cp)
{
    if (cp <= 0x7F)
        putchar(cp);
    else if (cp <= 0x7FF) {
        putchar(0xC0 | (cp >> 6));
        putchar(0x80 | (cp & 0x3F));
    } else if (cp <= 0xFFFF) {
        putchar(0xE0 | (cp >> 12));
        putchar(0x80 | ((cp >> 6) & 0x3F));
        putchar(0x80 | (cp & 0x3F));
    } else {
        putchar(0xF0 | (cp >> 18));
        putchar(0x80 | ((cp >> 12) & 0x3F));
        putchar(0x80 | ((cp >> 6) & 0x3F));
        putchar(0x80 | (cp & 0x3F));
    }
}

int main(void)
{
    unsigned int max = 0x1FFFFF;

    for (unsigned int cp = 0; cp <= max; cp++) {
        print_utf8(cp);
        //putchar('\n');
    }

    return 0;
}
