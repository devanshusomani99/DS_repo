#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a;
    char c = '5';
    a=((int) (c-'0'))*12;
    printf("%d\n", a);
    return 0;
}
