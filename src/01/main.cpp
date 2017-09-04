#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

char szFormat[] = "%s %s\n";
char szHello[] = "Hello";
char szWorld[] = " world";

int main(int argc, char** argv)
{
    __asm {
        MOV     EAX, OFFSET szWorld
        PUSH    EAX
        MOV     EAX, OFFSET szHello
        PUSH    EAX
        MOV     EAX, OFFSET szFormat
        PUSH    EAX
        CALL    printf
        // 压入了 3 个参数在堆栈中，调用函数之后要调整堆栈
        ADD     ESP, 12
    }
    system("pause");
    return 0;
}