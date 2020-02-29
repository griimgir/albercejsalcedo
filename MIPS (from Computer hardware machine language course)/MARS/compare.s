        .data
n:      .word 25
prompt:	.asciiz "Enter an input: "
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"
buffer: .space 4

        .text
main:		#load address
		la $t1, n
		#loadword
		lw $t1, 0($t1)
		#print prompt
		li $v0, 4
   		la $a0, prompt
    		syscall
		
		
		#reads an interger an saves it to t0
		li $v0, 5
		syscall
		move $t0, $v0	#saves v0 -> t0
    		
    		greater: 	
    		slt $s0, $t0, $t1	#set less than
		beq $s0, $zero, greater2	#branch if equal to
		bne $s0, $zero, less	#branch if not equal to
		# terminate/end
    		li $v0, 10
    		syscall
		
	
		greater2:	li $v0, 4
		la $a0, str3
		syscall
	
		less:
		beq $t0, $t1, less2
		bne $t0, $t1, less2
	
		less2:	slt $s0, $t0, $t1
		bne $s0, $zero, less3	#branch if not equal to
		li $v0, 10
		syscall
	
		less3:
		li $v0, 4
		la $a0, str2	#load address
		syscall
    		
exit:    	# terminate/end
    		li $v0, 10
    		syscall
		
