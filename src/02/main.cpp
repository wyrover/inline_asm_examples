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
        ȫ�ֱ����� OFFSET
        LEA     EAX, tszHello               ;
        �ֲ������� LEA
        PUSH    EAX
        PUSH    0
        CALL    DWORD PTR [MessageBox]      ;
        ע�����ﲻ�� CALL MessageBox�����ǵ����ض�λ���ĺ�����ַ
    }
    system("pause");
    return 0;
}