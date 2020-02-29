.data
prompt:	.asciiz "Eneter an integer: "

        .text
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# display the promt
		li $v0, 4
		la $a0, prompt
		syscall
			
		#read user input
		li $v0, 5
		syscall
		#storing input
		move $a0, $v0
		addi $v0, $zero, 0
		
		jal recursion	# Call recursion(x)
		
		#storing input to be printed
		sw $v0, 0($sp)
		lw $a0, 0($sp)
		
		li $v0, 1
		syscall
		
		j end		# Jump to end of program


recursion:	addi $sp, $sp, -12	# Push stack frame for local storage
 
 		#return address to main function
		sw $ra, 8($sp)
		
		#go to not_ten if true
		addi $t0, $zero, 10
		bne $a0, $t0, notTen
		
		#update value $v0 which returns to main
		addi $v0, $v0, 2
		
		j end_recur
			
notTen:	addi $t0, $zero, 11
		bne $a0, $t0, notEleven

		#update value $v0 which returns to main
		addi $v0, $v0, 1
		j end_recur		

notEleven:	sw $a0, 4($sp) 	
		# creating a new input argument
		addi $a0, $a0, 2
		
		# recursion(m + 2)
		jal recursion		
		
		lw $a0, 4($sp)
		
		# create new input argument
		addi $a0, $a0 1
		
		#recursion(m + 1)
		jal recursion
		
		lw $a0, 4($sp)
		add $v0, $v0, $a0

		#terminate recursion
		j end_recur
		
	
end_recur:	lw $ra, 8($sp)
		#Pop stack 
		addi $sp, $sp, 12
		jr $ra

		# stack pointer back to original position
end:		addi $sp, $sp 4			
		li $v0, 10 
		syscall