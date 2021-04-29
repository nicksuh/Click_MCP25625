test:
	gcc MCP25625_hal.h MCP25625_hal.c MCP25625_hw.h MCP25625_hw.c MCP25625.h MCP25625.c -o test.o -pthread -lpigpio -lrt -fpack-struct=1 -O0

