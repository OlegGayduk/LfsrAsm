Title ���������� �������� ������; ��������� ���������
.686; ��� ���������������
.MODEL FLAT, C ; ������ ������ -Win32 (������� � i386) � ���� ����������������
.STACK 256; ������� ����� � ��� ������
.DATA; �������������
.CODE; ������� ���� ���������
;-----------External usage-------------------------
; ������������ �������� ��������� �� ������� ����������
EXTRN num : byte
EXTRN sizen : byte
EXTRN lengthn : byte
;-----------Function definitions-------------------
; �������� �������������� �������
PUBLIC C lfsr ;
lfsr PROC far; ��������� �������������� �������
;far -����������� ��������� � ��������� �� ������� ������� ���� �������

;�������� �����
xor eax,eax
xor ecx,ecx
xor edx,edx
xor ebx,ebx 

mov cl,sizen
mov dl,num

cycle:
shl eax,1
push edx 
and edx,1
or eax,edx
pop edx

push edx
shr edx,1
pop ebx
xor edx,ebx
and edx,1
push ecx
mov cl,lengthn
shl edx, cl
pop ecx
shr ebx,1
or edx,ebx

dec cl
cmp cl,0
jnz cycle
; �������� Return from procedure ������������ ������� ���������� ���������� ���������
retn 
lfsr ENDP
END