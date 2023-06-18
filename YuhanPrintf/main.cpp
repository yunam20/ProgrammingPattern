#include <stdio.h>
#include <string.h>

void print_digit(int a, char* buf, int* pos) {
    if (a >= 10) {
        print_digit(a / 10, buf, pos);
    }
    buf[*pos] = '0' + a % 10;
    (*pos)++;
}

int printYuhan(const char* string, int num)
{
    int i, pos = 0;
    char output[256] = { 0 };

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == '%' && string[i + 1] == 'd') {
            print_digit(num, output, &pos);
            i++;
        }
        else {
            output[pos] = string[i];
            pos++;
        }
    }

    output[pos] = '\0';
    puts(output);
    return 0;
}

int main() {
    int num = 42;
    printYuhan("이은석은 %d배 멋진 남자!", num);
    return 0;
}