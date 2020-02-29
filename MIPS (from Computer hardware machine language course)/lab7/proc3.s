.data

x:		.word 5
y:		.word 10
p:		.word 0
q:		.word 0
.text

main:		la $t0, x
		lw $s0, 0($t0)	#s0 -> x
		la $t0, y	#loading address y
		lw $s1, 0($t0)	#s1 -> y
		#sum(x)
		#a0 -> x
		add $a0, $zero, $s0
		#a1 -> y
		add $a1, $zero, $s1
		jal SUM
		#add $t0, $s1, $s0
		add $s1, $a0, $a1
		add $a0, $s1, $s0
		#termination
		li $v0, 1
		syscall
		j END
		
SUM:		addi $t0, $a1, 1
		addi $t1, $a0, 1
		jal SUB
		
		la $t0, p
		#addi $sp, $sp -4
		#sw $s0, 0($sp)
		#lw $s0, 0($t0)
		#add $s0, $zero, $v0		# p = v0
		lw $s0, 0($t0)
		add $s0, $s0, $v0
		
		subi $t0, $a0 1
		subi $t1, $a1 1
		jal SUB
		
		la $t0, q
		#addi $sp, $sp -4
		#sw $s1, 0($sp)
		lw $s1, 0($t0)
		add $s1, $s1, $v0
		add $s0, $s0, $s1
		addi $ra,$zero, 4194340
		jr $ra
		
SUB:	sub $v0, $t1, $t0
		jr $ra
		
END:
		