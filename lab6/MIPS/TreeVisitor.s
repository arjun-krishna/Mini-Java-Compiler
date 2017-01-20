	.text
	.globl	main
main:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 8
	sw $ra, -4($fp)
	li $a0, 4
	jal _halloc
	move $t0, $v0
	li $a0, 4
	jal _halloc
	move $t1, $v0
	la $t2, TV_Start
	sw $t2, 0($t0)
	sw $t0, 0($t1)
	move $t0, $t1
	lw $t1, 0($t0)
	lw $t2, 0($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $t1
	jal _print
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 8
	jr $ra

	.text
	.globl	TV_Start
TV_Start:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	li $a0, 84
	jal _halloc
	move $t0, $v0
	li $a0, 28
	jal _halloc
	move $t1, $v0
	la $t2, Tree_accept
	sw $t2, 80($t0)
	la $t2, Tree_RecPrint
	sw $t2, 76($t0)
	la $t2, Tree_Print
	sw $t2, 72($t0)
	la $t2, Tree_Search
	sw $t2, 68($t0)
	la $t2, Tree_RemoveLeft
	sw $t2, 64($t0)
	la $t2, Tree_RemoveRight
	sw $t2, 60($t0)
	la $t2, Tree_Remove
	sw $t2, 56($t0)
	la $t2, Tree_Delete
	sw $t2, 52($t0)
	la $t2, Tree_Insert
	sw $t2, 48($t0)
	la $t2, Tree_Compare
	sw $t2, 44($t0)
	la $t2, Tree_SetHas_Right
	sw $t2, 40($t0)
	la $t2, Tree_SetHas_Left
	sw $t2, 36($t0)
	la $t2, Tree_GetHas_Left
	sw $t2, 32($t0)
	la $t2, Tree_GetHas_Right
	sw $t2, 28($t0)
	la $t2, Tree_SetKey
	sw $t2, 24($t0)
	la $t2, Tree_GetKey
	sw $t2, 20($t0)
	la $t2, Tree_GetLeft
	sw $t2, 16($t0)
	la $t2, Tree_GetRight
	sw $t2, 12($t0)
	la $t2, Tree_SetLeft
	sw $t2, 8($t0)
	la $t2, Tree_SetRight
	sw $t2, 4($t0)
	la $t2, Tree_Init
	sw $t2, 0($t0)
	li $t2, 4
L2:	nop
	li $t3, 28
	slt $t4, $t2, $t3
	bne $t4, 1, L3
	add $t3, $t1, $t2
	li $t4, 0
	sw $t4, 0($t3)
	add $t2, $t2, 4
	j L2
L3:	nop
	sw $t0, 0($t1)
	move $s1, $t1
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 0($t1)
	li $t1, 16
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 72($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	li $t0, 100000000
	move $a0, $t0
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 8
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 24
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 4
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 12
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 20
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 28
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 48($t1)
	li $t1, 14
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 72($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	li $t0, 100000000
	move $a0, $t0
	jal _print
	li $a0, 4
	jal _halloc
	move $t0, $v0
	li $a0, 12
	jal _halloc
	move $t1, $v0
	la $t2, MyVisitor_visit
	sw $t2, 0($t0)
	li $t2, 4
L4:	nop
	li $t3, 12
	slt $t4, $t2, $t3
	bne $t4, 1, L5
	add $t3, $t1, $t2
	li $t4, 0
	sw $t4, 0($t3)
	add $t2, $t2, 4
	j L4
L5:	nop
	sw $t0, 0($t1)
	move $t0, $t1
	li $t1, 50000000
	move $a0, $t1
	jal _print
	move $t1, $s1
	lw $t2, 0($t1)
	lw $t3, 80($t2)
	move $a0, $t1
	move $a1, $t0
	jalr $t3
	move $t2, $v0
	li $t0, 100000000
	move $a0, $t0
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 24
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 12
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 16
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 50
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 12
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 52($t1)
	li $t1, 12
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 72($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 68($t1)
	li $t1, 12
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $a0, $t3
	jal _print
	li $t0, 0
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_Init
Tree_Init:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 12($s0)
	li $t0, 0
	sw $t0, 16($s0)
	li $t0, 0
	sw $t0, 20($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_SetRight
Tree_SetRight:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 8($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_SetLeft
Tree_SetLeft:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 4($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_GetRight
Tree_GetRight:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	lw $t0, 8($s0)
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_GetLeft
Tree_GetLeft:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	lw $t0, 4($s0)
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_GetKey
Tree_GetKey:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	lw $t0, 12($s0)
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_SetKey
Tree_SetKey:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 12($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_GetHas_Right
Tree_GetHas_Right:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	lw $t0, 20($s0)
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_GetHas_Left
Tree_GetHas_Left:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	lw $t0, 16($s0)
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_SetHas_Left
Tree_SetHas_Left:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 16($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_SetHas_Right
Tree_SetHas_Right:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	sw $s1, 20($s0)
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Tree_Compare
Tree_Compare:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 20
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2
	li $t1, 0
	add $t0, $s2, 1
	slt $t1, $s1, $s2
	bne $t1, 1, L6
	li $t1, 0
	j L7
L6:	nop
	li $t2, 1
	slt $t3, $s1, $t0
	sub $t0, $t2, $t3
	bne $t0, 1, L8
	li $t1, 0
	j L9
L8:	nop
	li $t1, 1
L9:	nop
L7:	nop
	move $v0, $t1
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 20
	jr $ra

	.text
	.globl	Tree_Insert
Tree_Insert:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 28
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	move $s0, $a0
	move $s1, $a1
	li $a0, 84
	jal _halloc
	move $t0, $v0
	li $a0, 28
	jal _halloc
	move $t1, $v0
	la $t2, Tree_accept
	sw $t2, 80($t0)
	la $t2, Tree_RecPrint
	sw $t2, 76($t0)
	la $t2, Tree_Print
	sw $t2, 72($t0)
	la $t2, Tree_Search
	sw $t2, 68($t0)
	la $t2, Tree_RemoveLeft
	sw $t2, 64($t0)
	la $t2, Tree_RemoveRight
	sw $t2, 60($t0)
	la $t2, Tree_Remove
	sw $t2, 56($t0)
	la $t2, Tree_Delete
	sw $t2, 52($t0)
	la $t2, Tree_Insert
	sw $t2, 48($t0)
	la $t2, Tree_Compare
	sw $t2, 44($t0)
	la $t2, Tree_SetHas_Right
	sw $t2, 40($t0)
	la $t2, Tree_SetHas_Left
	sw $t2, 36($t0)
	la $t2, Tree_GetHas_Left
	sw $t2, 32($t0)
	la $t2, Tree_GetHas_Right
	sw $t2, 28($t0)
	la $t2, Tree_SetKey
	sw $t2, 24($t0)
	la $t2, Tree_GetKey
	sw $t2, 20($t0)
	la $t2, Tree_GetLeft
	sw $t2, 16($t0)
	la $t2, Tree_GetRight
	sw $t2, 12($t0)
	la $t2, Tree_SetLeft
	sw $t2, 8($t0)
	la $t2, Tree_SetRight
	sw $t2, 4($t0)
	la $t2, Tree_Init
	sw $t2, 0($t0)
	li $t2, 4
L10:	nop
	li $t3, 28
	slt $t4, $t2, $t3
	bne $t4, 1, L11
	add $t3, $t1, $t2
	li $t4, 0
	sw $t4, 0($t3)
	add $t2, $t2, 4
	j L10
L11:	nop
	sw $t0, 0($t1)
	move $s2, $t1
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 0($t1)
	move $a0, $t0
	move $a1, $s1
	jalr $t2
	move $t1, $v0
	move $s3, $s0
	li $s4, 1
L12:	nop
	bne $s4, 1, L13
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $t1
	slt $t1, $s1, $t0
	bne $t1, 1, L14
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L16
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s3, $t1
	j L17
L16:	nop
	li $s4, 0
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 36($t1)
	li $t1, 1
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 8($t1)
	move $a0, $t0
	move $a1, $s2
	jalr $t2
	move $t1, $v0
L17:	nop
	j L15
L14:	nop
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L18
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s3, $t1
	j L19
L18:	nop
	li $s4, 0
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 40($t1)
	li $t1, 1
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s3
	lw $t1, 0($t0)
	lw $t2, 4($t1)
	move $a0, $t0
	move $a1, $s2
	jalr $t2
	move $t1, $v0
L19:	nop
L15:	nop
	j L12
L13:	nop
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 28
	jr $ra

	.text
	.globl	Tree_Delete
Tree_Delete:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 48
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	sw $s6, 24($sp)
	sw $s7, 28($sp)
	sw $s5, 32($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $s0
	move $s3, $s0
	li $s4, 1
	li $v1, 0
	sw $v1, 20($sp)
	li $s6, 1
L20:	nop
	bne $s4, 1, L21
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s7, $t1
	slt $t0, $s1, $s7
	bne $t0, 1, L22
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L24
	move $s3, $s2
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L25
L24:	nop
	li $s4, 0
L25:	nop
	j L23
L22:	nop
	slt $t0, $s7, $s1
	bne $t0, 1, L26
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L28
	move $s3, $s2
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L29
L28:	nop
	li $s4, 0
L29:	nop
	j L27
L26:	nop
	bne $s6, 1, L30
	li $s7, 0
	li $s5, 1
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sub $t0, $s5, $t1
	bne $t0, 1, L34
	li $s5, 1
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sub $t0, $s5, $t1
	bne $t0, 1, L34
	li $s7, 1
L34:	nop
	bne $s7, 1, L32
	j L33
L32:	nop
	move $t0, $s0
	lw $t1, 0($t0)
	lw $t2, 56($t1)
	move $a0, $t0
	move $a1, $s3
	move $a2, $s2
	jalr $t2
	move $t1, $v0
L33:	nop
	j L31
L30:	nop
	move $t0, $s0
	lw $t1, 0($t0)
	lw $t2, 56($t1)
	move $a0, $t0
	move $a1, $s3
	move $a2, $s2
	jalr $t2
	move $t1, $v0
L31:	nop
	lw $v1, 20($sp)
	li $v1, 1
	sw $v1, 36($sp)
	li $s4, 0
L27:	nop
L23:	nop
	li $s6, 0
	j L20
L21:	nop
	lw $v1, 36($sp)
	move $v0, $v1
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 32($sp)
	lw $s6, 24($sp)
	lw $s7, 28($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 48
	jr $ra

	.text
	.globl	Tree_Remove
Tree_Remove:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 24
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L35
	move $t0, $s0
	lw $t1, 0($t0)
	lw $t2, 64($t1)
	move $a0, $t0
	move $a1, $s1
	move $a2, $s2
	jalr $t2
	move $t1, $v0
	j L36
L35:	nop
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L37
	move $t0, $s0
	lw $t1, 0($t0)
	lw $t2, 60($t1)
	move $a0, $t0
	move $a1, $s1
	move $a2, $s2
	jalr $t2
	move $t1, $v0
	j L38
L37:	nop
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s3, $t1
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $t1
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $t1
	move $t1, $s0
	lw $t2, 0($t1)
	lw $t3, 44($t2)
	move $a0, $t1
	move $a1, $s3
	move $a2, $t0
	jalr $t3
	move $t2, $v0
	bne $t2, 1, L39
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 8($t1)
	lw $t1, 24($s0)
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 36($t1)
	li $t1, 0
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	j L40
L39:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 4($t1)
	lw $t1, 24($s0)
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 40($t1)
	li $t1, 0
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
L40:	nop
L38:	nop
L36:	nop
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 24
	jr $ra

	.text
	.globl	Tree_RemoveRight
Tree_RemoveRight:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 28
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2
L41:	nop
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L42
	move $s3, $s2
	lw $t0, 0($s3)
	lw $s4, 24($t0)
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $t1
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $s3
	move $a1, $t1
	jalr $s4
	move $t0, $v0
	move $s1, $s2
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L41
L42:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 4($t1)
	lw $t1, 24($s0)
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 40($t1)
	li $t1, 0
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 28
	jr $ra

	.text
	.globl	Tree_RemoveLeft
Tree_RemoveLeft:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 28
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2
L43:	nop
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L44
	move $s3, $s2
	lw $t0, 0($s3)
	lw $s4, 24($t0)
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $t0, $t1
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $s3
	move $a1, $t1
	jalr $s4
	move $t0, $v0
	move $s1, $s2
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L43
L44:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 8($t1)
	lw $t1, 24($s0)
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 36($t1)
	li $t1, 0
	move $a0, $t0
	move $a1, $t1
	jalr $t2
	move $t3, $v0
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 28
	jr $ra

	.text
	.globl	Tree_Search
Tree_Search:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 32
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	sw $s5, 20($sp)
	move $s0, $a0
	move $s1, $a1
	move $s2, $s0
	li $s3, 1
	li $s4, 0
L45:	nop
	bne $s3, 1, L46
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s5, $t1
	slt $t0, $s1, $s5
	bne $t0, 1, L47
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L49
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L50
L49:	nop
	li $s3, 0
L50:	nop
	j L48
L47:	nop
	slt $t0, $s5, $s1
	bne $t0, 1, L51
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L53
	move $t0, $s2
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $s2, $t1
	j L54
L53:	nop
	li $s3, 0
L54:	nop
	j L52
L51:	nop
	li $s4, 1
	li $s3, 0
L52:	nop
L48:	nop
	j L45
L46:	nop
	move $v0, $s4
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 20($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 32
	jr $ra

	.text
	.globl	Tree_Print
Tree_Print:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 12
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	move $s0, $a0
	move $t0, $s0
	move $t1, $s0
	lw $t2, 0($t1)
	lw $t3, 76($t2)
	move $a0, $t1
	move $a1, $t0
	jalr $t3
	move $t2, $v0
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 12
	jr $ra

	.text
	.globl	Tree_RecPrint
Tree_RecPrint:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 24
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	move $s0, $a0
	move $s1, $a1
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L55
	move $s2, $s0
	lw $t0, 0($s2)
	lw $s3, 76($t0)
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $s2
	move $a1, $t1
	jalr $s3
	move $t0, $v0
	j L56
L55:	nop
L56:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $t1
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L57
	move $s2, $s0
	lw $t0, 0($s2)
	lw $s3, 76($t0)
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $s2
	move $a1, $t1
	jalr $s3
	move $t0, $v0
	j L58
L57:	nop
L58:	nop
	li $t0, 1
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 24
	jr $ra

	.text
	.globl	Tree_accept
Tree_accept:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	li $t0, 333
	move $a0, $t0
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 0($t1)
	move $a0, $t0
	move $a1, $s0
	jalr $t2
	move $t1, $v0
	li $t0, 0
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	Visitor_visit
Visitor_visit:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L59
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sw $t1, 8($s0)
	lw $t0, 8($s0)
	move $t1, $t0
	lw $t0, 0($t1)
	lw $t2, 80($t0)
	move $a0, $t1
	move $a1, $s0
	jalr $t2
	move $t0, $v0
	j L60
L59:	nop
L60:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L61
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sw $t1, 4($s0)
	lw $t0, 4($s0)
	move $t1, $t0
	lw $t0, 0($t1)
	lw $t2, 80($t0)
	move $a0, $t1
	move $a1, $s0
	jalr $t2
	move $t0, $v0
	j L62
L61:	nop
L62:	nop
	li $t0, 0
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl	MyVisitor_visit
MyVisitor_visit:
	sw $fp, -8($sp)
	move $fp, $sp
	subu $sp, $sp, 16
	sw $ra, -4($fp)
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	move $s0, $a0
	move $s1, $a1
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 28($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L63
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 12($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sw $t1, 8($s0)
	lw $t0, 8($s0)
	move $t1, $t0
	lw $t0, 0($t1)
	lw $t2, 80($t0)
	move $a0, $t1
	move $a1, $s0
	jalr $t2
	move $t0, $v0
	j L64
L63:	nop
L64:	nop
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 20($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	move $a0, $t1
	jal _print
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 32($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	bne $t1, 1, L65
	move $t0, $s1
	lw $t1, 0($t0)
	lw $t2, 16($t1)
	move $a0, $t0
	jalr $t2
	move $t1, $v0
	sw $t1, 4($s0)
	lw $t0, 4($s0)
	move $t1, $t0
	lw $t0, 0($t1)
	lw $t2, 80($t0)
	move $a0, $t1
	move $a1, $s0
	jalr $t2
	move $t0, $v0
	j L66
L65:	nop
L66:	nop
	li $t0, 0
	move $v0, $t0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $ra, -4($fp)
	lw $fp, -8($fp)
	addu $sp, $sp, 16
	jr $ra

	.text
	.globl _halloc
_halloc:
	li $v0, 9
	syscall
	jr $ra

	.text
	.globl _print
_print:
	li $v0, 1
	syscall
	la $a0, newl
	li $v0, 4
	syscall
	jr $ra

	.text
	.globl _error
_error:
	la $a0, err_msg
	li $v0, 4
	syscall
	li $v0, 10
	syscall

	.data
	.align   0
newl:   .asciiz "\n"
	.data
	.align   0
str_er: .asciiz " ERROR: abnormal termination\n"
	.data
	.align   0
err_msg:.asciiz "ERROR\n"


