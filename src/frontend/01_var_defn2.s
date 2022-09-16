.global main
sub sp,sp,#4
mov r1,#3
str r1,[sp,#0]
sub sp,sp,#4
mov r2,#5
str r2,[sp,#0]
main:
sub sp,sp,#4
mov r3,#5
str r3,[sp,#0]
ldr r4,[sp,#0]
ldr r5,[sp,#4]
add r6,r4,r5
sub sp,sp,#4
str r6,[sp,#0]
mov r0,r6
bx lr
