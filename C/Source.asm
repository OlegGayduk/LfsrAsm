Title Вычисление регистра сдвига; Заголовок программы
.686; Тип микропроцессора
.MODEL FLAT, C ; Модель памяти -Win32 (начиная с i386) и язык программирования
.STACK 256; Сегмент стека и его размер
.DATA; Сегментданных
.CODE; Сегмент кода программы
;-----------External usage-------------------------
; Возвращаемое значение процедуры во внешнее приложение
EXTRN num : byte
EXTRN sizen : byte
EXTRN lengthn : byte
;-----------Function definitions-------------------
; Описание экспортируемой функции
PUBLIC C lfsr ;
lfsr PROC far; Заголовок экспортируемой функции
;far -возможность обращения к процедуре из другого участка кода проекта

;основная часть
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
; Оператор Return from procedure обеспечивает возврат управления вызывающей программе
retn 
lfsr ENDP
END