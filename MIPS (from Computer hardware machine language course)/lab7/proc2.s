		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:		la $t0, x #//5
		lw $s0, 0($t0)	# s0 = x = 5
		la $t0, y	#//t0 = y = 10
		lw $s1, 0($t0) 	# s1 = y = 10
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# Set a0 as input argument for SUM	s0 = 5 so add 5 to $zero
		jal SUM
		add $t0, $s1, $s0
		add $s1, $t0, $v0
		addi $a0, $s1, 0 
		li $v0, 1		 
		syscall	
		j END

		
SUM: 		la $t0, m
		addi $sp, $sp -4
		sw $s0, 0($sp)
		lw $s0, 0($t0)		# s0 = m
		add $a0, $s0, $a0	# Update a0 as new argument for SUB
		jal SUB
		
		lw $s0, 0($sp)
		addi $sp, $sp 4
		add $a0, $zero, $s0
		add $v0, $a0, $v0
		addi $ra,$zero, 0x00400020
		jr $ra		
		
SUB:		la $t0, b
		addi $sp, $sp -4
		sw $s0, 0($sp)		# Backup s0 from SUM
		lw $s0, 0($t0)		# s0 = b
		sub $v0, $a0, $s0
		lw $s0, 0($sp)		# Restore s0 from SUM
		addi $sp, $sp 4
		jr $ra

		
END:
