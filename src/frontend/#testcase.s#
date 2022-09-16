.global main
.data
a:
.skip 20
.text
main:
ldr r1,=a
movw r2,#0
str r2,[r1,#0]
ldr r3,=a
movw r4,#1
str r4,[r3,#4]
ldr r5,=a
movw r6,#2
str r6,[r5,#8]
ldr r7,=a
movw r8,#3
str r8,[r7,#12]
ldr r9,=a
movw r10,#4
str r10,[r9,#16]
sub sp,#4
movw r11,#0
str r11,[sp,#0]
sub sp,#4
movw r0,#4
str r0,[sp,#0]
sub sp,#4
movw r1,#5
str r1,[sp,#0]
ldr r2,[sp,#8]
ldr r3,[sp,#0]
mul r4,r2,r3
sub sp,#4
str r4,[sp,#0]
ldr r5,[sp,#0]
ldr r6,[sp,#8]
add r7,r5,r6
sub sp,#4
str r7,[sp,#0]
ldr r8,=a
ldr r8,[r8]
sub sp,#0
str r8,[sp,#0]
mov r0,r8
bx lr
