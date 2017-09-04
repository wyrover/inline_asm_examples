#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

TCHAR g_tszAppName[] = TEXT("API Test");

int main(int argc, char** argv)
{
    TCHAR tszHello[] = TEXT("Hello, world!");
    __asm {
        PUSH    MB_OK OR MB_ICONINFORMATION
        PUSH    OFFSET g_tszAppName         ;
        全局变量用 OFFSET
        LEA     EAX, tszHello               ;
        局部变量用 LEA
        PUSH    EAX
        PUSH    0
        CALL    DWORD PTR [MessageBox]      ;
        注意这里不是 CALL MessageBox，而是调用重定位过的函数地址
    }
    system("pause");
    return 0;
}