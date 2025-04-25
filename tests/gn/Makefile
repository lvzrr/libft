CC 			= 	gcc

CFG			= 	-Wall -Wextra -Werror -I. -pthread -I../../include/ -lft

SRC    	    = 	sq_main.c sq_get_next_line.c

all : setup exec test

exec: $(SRC)
	@$(CC) -o t0.esq $^ $(CFG) -D BUFFER_SIZE=0
	@$(CC) -o t1.esq $^ $(CFG) -D BUFFER_SIZE=1
	@$(CC) -o t2.esq $^ $(CFG) -D BUFFER_SIZE=2
	@$(CC) -o t42.esq $^ $(CFG) -D BUFFER_SIZE=42
	@$(CC) -o t42000.esq $^ $(CFG) -D BUFFER_SIZE=42000

setup :
	@cp ../../include/gnl.h ./get_next_line.h
	@cp ../../in/get_next_line.c ./sq_get_next_line.c

test :
	@./sloquet.sh

clean :
	@rm -f get_next_line.h
	@rm -f sq_get_next_line.c
	@rm -f *.esq
	@rm -f log_norminette
fco : clean
	@rm -rf out_*

.PHONY : all exec setup test clean fco
