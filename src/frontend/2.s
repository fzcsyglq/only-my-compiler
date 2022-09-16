.data

.balign 4
myvar1:
    .word 0

.balign 4
myvar2:
    .word 0

.text

.balign 4
.global main
main:
    ldr r1, =myvar1
    mov r3, #3             /* r3 ← 3 */
    str r3, [r1]           /* *r1 ← r3 */
    ldr r0, [r1]
    bx lr


    .data
    
.balign 4
a:
    .word 0

.balign 4
b:
    .word 0
    
.text
.balign 4
.global main
main:
    ldr r1,=b
    mov r3,#9999
	str r3,[r1]
	ldr r0,[r1]
    bx lr

