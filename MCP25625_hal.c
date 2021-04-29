/*******************************************************************************
* Title                 :   MCP25625 HAL
* Filename              :   MCP25625_hal.c
* Author                :   MSV
* Origin Date           :   01/02/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials       Description
*  01/02/16       1.0.0             MSV        Module Created.
*
*******************************************************************************/
/**
 * @file MCP25625_hal.c
 * @brief <h2> HAL layer </h2>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "MCP25625_hal.h"
#include <pigpio.h>
#include <stdio.h>

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

void write_spi_p(uint8_t data);
uint8_t read_spi_p();


int myspi ;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void MCP25625_hal_cs( int state )
{
	gpioWrite(8,state);

}

void MCP25625_hal_rst( int state )
{

}

void MCP25625_hal_stb( int state )
{
	gpioWrite(27,state);

}

void MCP25625_hal_tx0( int state )
{
	//CE0

}

void MCP25625_hal_tx1( int state )
{

}

int MCP25625_hal_rx0()
{
}

int MCP25625_hal_rx1()
{
}

void MCP25625_hal_init()
{
	gpioInitialise();
	myspi = spiOpen(0,100000,32);
	int retva = gpioHardwareClock(4,19200000);
	printf("clock %d",retva);
	
	gpioSetMode(8,PI_OUTPUT);
	gpioSetMode(27,PI_OUTPUT);
	
}

void MCP25625_hal_cmd( uint8_t cmd )
{
	printf("com \n");
   	write_spi_p( cmd );
}

void MCP25625_hal_write( uint8_t *buffer,
                         uint16_t count )
{
    	while( count-- )
        	write_spi_p( *buffer++ );
}

void MCP25625_hal_read( uint8_t *buffer,
                        uint16_t count )
{
	while( count-- )
        	*buffer++ = read_spi_p();
}

uint8_t read_spi_p(){
	uint8_t buf = 0x00;
	spiRead(myspi,&buf,1);
	printf("R : %02X \n" ,buf);
	return buf;
}


void write_spi_p(uint8_t data){
	printf("W : %02X \n" ,data);
	spiRead(myspi,&data,1);
}



/*************** END OF FUNCTIONS ***************************************************************************/
/*

	uint8_t a = 0x32;
	uint8_t b = 0x00;
	
	spiXfer(myspi,&a,&b,2);
	printf(" test : %02X " ,b);

*/
