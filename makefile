test:
	gcc MCP25625_hal.h MCP25625_hal.c -o test.o -pthread -lpigpio -lrt
