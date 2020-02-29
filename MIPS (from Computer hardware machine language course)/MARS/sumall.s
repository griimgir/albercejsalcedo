.data
	positiveString: .asciiz "\nSum of the positve numbers: "
	negativeString: .asciiz "\nSum of negative numbers: "
	answerString: .asciiz "\nEnter an integer positive or negative (0 to end program):"
	
.text

	input:
	li $v0, 4
	la $a0, answerString
	syscall
	#move v0 -> t0
	li $v0, 5
	syscall
	move $t0, $v0
	
	blt $t0, $zero, negative	#less than
	bgt $t0, $zero, positive	#greater than
	
	beq $t0, $zero, termination
	
	positive:
	add $t2, $t2, $t0
	j input

	negative:
	add $t1, $t1, $t0
	j input
		
	termination:	
	li $v0, 4
	la $a0, positiveString
	syscall
	
	li $v0, 1
	la $a0, ($t2)
	syscall
	
	li $v0, 4
	la $a0, negativeString
	syscall
	
	li $v0, 1
	la $a0, ($t1)
	syscall
	
	
