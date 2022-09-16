.global: main
main:
sub sp,sp 4
mov r1,#100
str r1,[sp,#0]
ldr r1,[sp,#0]
str r1,[sp,#1]
mov r0 r1
bx lr
