#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>



int main(int argc, char** argv)
{
    int a = 1;
    int b = 2;
    int c;
    __asm {
        MOV EAX, a
        MOV EBX, b
        ADD EAX, EBX
        MOV c, EAX
    }
    printf("a + b = %x + %x = %x\n", a, b, c);
    system("pause");
    return 0;
}