time-asm.exe: time-asm.c
	gcc -o time-asm.exe time-asm.c

time.exe: time.c
	gcc -o time.exe time.c
	
time32.exe: time.c
	# 64位机器上编出32位代码需加-m32
	gcc -o time32.exe time.c -m32
