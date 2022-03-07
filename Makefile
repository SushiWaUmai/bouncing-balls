CFLAGS=-Wall -Wextra -std=gnu99

ball: ./src/main.c 
	$(CC) $(CFLAGS) -o ball.out ./src/main.c -lm
