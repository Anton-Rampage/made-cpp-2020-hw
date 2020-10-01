	.text
	.global	count_det
count_det:
    @calculate a11 * a22 * a33
    ldr r1, [r0]
    ldr r2, [r0, #16]
    mul r1, r2, r1
    ldr r2, [r0, #32]
    mul r1, r1, r2
    @calculate a12 * a23 * a31
    ldr r2, [r0, #4]
    ldr r3, [r0, #20]
    mul r2, r2, r3
    ldr r3, [r0, #24]
    mul r2, r2, r3
    @sum
    add r1, r1, r2
    @calculate a21 * a32 * a13
    ldr r2, [r0, #12]
    ldr r3, [r0, #28]
    mul r2, r2, r3
    ldr r3, [r0, #8]
    mul r2, r2, r3
    @sum
    add r1, r1, r2
    @calculate a13 * a22 * a31
    ldr r2, [r0, #8]
    ldr r3, [r0, #16]
    mul r2, r2, r3
    ldr r3, [r0, #24]
    mul r2, r2, r3
    @sub
    sub r1, r1, r2
    @calculate a12 * a21 * a33
    ldr r2, [r0, #4]
    ldr r3, [r0, #12]
    mul r2, r2, r3
    ldr r3, [r0, #32]
    mul r2, r2, r3
    @sub
    sub r1, r1, r2
    @calculate a11 * a23 * a32
    ldr r2, [r0]
    ldr r3, [r0, #20]
    mul r2, r2, r3
    ldr r3, [r0, #28]
    mul r2, r2, r3
    @sub
    sub r1, r1, r2
    @return
    mov r0, r1
    bx lr
