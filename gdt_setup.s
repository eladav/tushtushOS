gdtr DW 0 ; For limit storage
     DD 0 ; For base storage
 global setGdt
setGdt:
    ; cli

   MOV   eax, [esp + 4]
   MOV   [gdtr + 2], eax
   MOV   ax, [esp + 8]
   MOV   [gdtr], ax
   LGDT  [gdtr]
   RET

global reloadSegments
   reloadSegments:
   ; Reload CS register containing code selector:

   ; Reload data segment registers:
   MOV   AX, 0x10 ; 0x10 points at the new data selector
   MOV   DS, AX
   MOV   ES, AX
   MOV   FS, AX
   MOV   GS, AX
   MOV   SS, AX

    ; code here uses the previous cs
    jmp 0x08:flush_cs   ; specify cs when jumping to flush_cs
    flush_cs:
        RET