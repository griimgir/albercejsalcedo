        .data
n:      .word 13

        .text
main: 	
	add $t0, $s0, $zero
	addi $t1, $t0, 1
	addi $t2, $t0, 2
	addi $t3, $t0, 3
	addi $t4, $t0, 4
	addi $t5, $t0, 5
	addi $t6, $t0, 6
	addi $t7, $t0, 7
	li	$v0, 10
	syscall
