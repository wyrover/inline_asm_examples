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
        // ѹ���� 3 �������ڶ�ջ�У����ú���֮��Ҫ������ջ
        ADD     ESP, 12
    }
    system("pause");
    return 0;
}