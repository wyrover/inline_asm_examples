#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>



typedef int (WINAPI
             *MessageBox_type)(
                 __in_opt HWND hWnd,
                 __in_opt LPCSTR lpText,
                 __in_opt LPCSTR lpCaption,
                 __in UINT uType) ;

MessageBox_type RealMessageBox = MessageBoxA;

//�����Լ���MessageBox��ÿ����MessageBox��Ҫ����myMessageBox������
_declspec(naked)  void WINAPI
myMessageBox(
    __in_opt HWND hWnd,
    __in_opt LPCSTR lpText,
    __in_opt LPCSTR lpCaption,
    __in UINT uType)
{
    __asm {
        PUSH ebp
        mov ebp, esp

        /*
        vs2010 debug �����Ĵ�������Ҫcmp esi esp���Ƚ϶�ջ��
        ���������ڵ��÷�__asm����ǰpushһ��esi
        */
        push esi
    }
    //�����ӡMessageBox����
    printf("hwnd:%8X lpText:%s lpCaption:%s,uType:%8X", hWnd, lpText, lpCaption, uType);
    __asm {
        /*
        vs2010 debug �����Ĵ�������Ҫcmp esi esp���Ƚ϶�ջ��
        ���������ڵ��÷�__asm����ǰpushһ��esi
        */
        pop esi

        mov ebx, RealMessageBox
        add ebx, 5
        jmp ebx
    }
}


#pragma pack(1)
typedef struct _JMPCODE {
    BYTE jmp;
    DWORD addr;
} JMPCODE, *PJMPCODE;

VOID HookMessageBoxA()
{
    JMPCODE jcode;
    jcode.jmp = 0xe9;//jmp
    jcode.addr = (DWORD)myMessageBox - (DWORD)RealMessageBox - 5;
    RealMessageBox = MessageBoxA;
    ::WriteProcessMemory(GetCurrentProcess(), MessageBoxA, &jcode, sizeof(JMPCODE), NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
    HookMessageBoxA();  //hook����
    ::MessageBoxA(NULL, "hook test", "tip", MB_OK); //ִ��api MessageBox
    return 0;
}