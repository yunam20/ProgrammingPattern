#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void my_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char* c = format; *c; ++c) {
        if (*c == '%') {
            ++c; // 서식 문자 다음 문자로 이동

            // 지원하는 서식 문자 처리
            switch (*c) {
            case '%':
                putchar('%');
                break;

            case 'c':
                putchar(va_arg(args, int));
                break;

            case 'd': {
                int val = va_arg(args, int);
                int div = 1;
                if (val < 0) {
                    putchar('-');
                    val = -val;
                }
                while (val / div >= 10) {
                    div *= 10;
                }
                while (div > 0) {
                    putchar('0' + val / div);
                    val %= div;
                    div /= 10;
                }
                break;
            }

            case 's': {
                const char* str = va_arg(args, const char*);
                while (*str) {
                    putchar(*str++);
                }
                break;
            }

            default:
                break;
            }
        }
        else {
            putchar(*c);
        }
    }

    va_end(args);
}

int my_scanf(const char* format, ...) {
	int count = 0;
	va_list arglist;
	va_start(arglist, format);
	count = vscanf(format, arglist);
	va_end(arglist);
	return count;
}

/*
int my_printf(const char* string, char a)
{
	int i;
	for (i = 0; strlen(string) > i; i++) {
		if (string[i] == '%') {
			switch (string[i + 1])
			{
			case 'c':
				putchar(a);
				i++;
				break;
			default:
				break;
			}
			continue;
		}
		putchar(string[i]);
	}

	return 0;
}*/

int main()
{
	char a = 'i';
	int fuck;
	my_printf("씨발 %c", a);
	my_scanf("%d", &fuck);
	printf("%d", fuck);

	return 0;
}