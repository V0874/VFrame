/*
--------------------------------------------------------------------------------------------------------------------------------------------
                                                        USART base peripheral block addresses
*/

#define USART0_BASE             (0xC0UL)
#define USART1_BASE             (0xC8UL)
#define USART2_BASE             (0xD0UL)
#define USART3_BASE             (0x130UL)

/*
--------------------------------------------------------------------------------------------------------------------------------------------
                                                        USART flag and configuration settings
*/

#define F_CPU 16000000UL                                 // system clock speed

// USART Control Register A

#define USART_RX_SUCCESS        (1 << 7)                // receive complete flag 
#define USART_TX_SUCCESS        (1 << 6)                // transmit complete flag
#define USART_BUFF_EMPTY        (1 << 5)                // transmit buffer empty flag
#define USART_FRAME_ERROR       (1 << 4)                // frame error flag
#define USART_DATA_OVERRUN      (1 << 3)                // data overrun flag
#define USART_PARITY_ERROR      (1 << 2)                // parity error flag
#define USART_DBL_SPEED_CONFIG  (1 << 1)                // double transmission speed setting
#define USART_MULTI_PROC_MODE   (1 << 0)                // multi processor communication mode setting

// USART Control Register B

#define USART_RX_ISR_SET        (1 << 7)                // RX complete interrupt bit
#define USART_TX_ISR_SET        (1 << 6)                // TX complete interrupt bit
#define USART_BUFF_ISR_SET      (1 << 5)                // enable data register empty interrupt
#define USART_RX_SET            (1 << 4)                // enable receiver
#define USART_TX_SET            (1 << 3)                // enable transmitter
#define USART_DATA_BITS         (1 << 2)                // used in conjunction to set the data bits mode
#define USART_RECEIVE_8BITN     (1 << 1)                // receive data bit 8n; 9th bit to be received with serial frames
#define USART_TRANSMIT_8BITN    (1 << 0)                // transmit data bit 8n; 9th bit to be transmitted with serial frames


// USART Control Register C

#define USART_SYNC_CONFIG         (1 << 6)                // set synchronous mode; asynchronous mode is set by default without config
#define USART_MASTER_SPI_CONFIG   ((1 << 6) | (1 << 7))   // set master spi mode
#define USART_EVEN_PARITY         (1 << 5)                // even parity mode enabled; parity is disabled by default without config
#define USART_ODD_PARITY          ((1 << 4) | (1 << 5))   // odd parity mode enabled
#define USART_2_STOP_BITS         (1 << 3)                // enabling sets 2 stop bits; 1 stop bit is configured by default without config
#define USART_DATA_BITS_MASK      ((1 << 1) | (1 << 2))     /* clears the data bits and sets them to 5 data bits selection
                                                          8 data bits are set by default without any configuration*/
#define USART_DATA_BITS_6BITS     (1 << 1)                // sets data bits to 6 bits assuming the mode has been cleared
#define USART_DATA_BITS_7BITS     (1 << 2)                // sets data bits to 7 bits assuming the mode has been cleared
#define USART_DATA_BITS_9BITS     ((1 << 1) | (1 << 2))   // sets data bits size to 9 bits and char_size in control register B must be set to 1

#define USART_CLOCK_POLARITY      (1 << 0)                /* transmitted data rising edge; received data falling edge by default;
                                                          if this  bit is set to 1 the configuration is reversed
                                                          this bit is only used for synchronous mode */

/*
--------------------------------------------------------------------------------------------------------------------------------------------
                                                        SPI mode flag and configuration settings 
*/

/*

These are the options available to the user when in SPI mode:

CTRL REGISTER A:

-USART Receive complete flag
-USART Transmit complete flag
-USART Data register empty flag

CTRL REGISTER B:

-USART RX complete interrupt enable
-USART TX complete interrupt enable
-USART Data register empty interrupt enable
-USART RX enable
-USART TX enable

CTRL REGISTSER C:

-USART Mode selection (you must enable master SPI mode with set_mode)
-USART Data order setting 
-USART Clock phase setting
-USART Clock polarity setting

There are 4 different SPI modes available depending on what bits are set or cleared
The modes selected change the leading edge and trailing edge
for the data setup and data sample to rising or falling depending on configuration

*/

#define USART_CLOCK_PHASE       (1 << 1)        // This bit determines data sampling on the leading edge or trailing edge of the clock pin
#define USART_DATA_ORDER        (1 << 2)        /* When the data order bit is set,
                                                the least significant bit of the data is transmitted first
                                                if the bit is cleared, the most significant bit of the data is transmitted first*/

/*

SPI Mode 0: This mode sets Leading edge: sample (rising) Trailing edge: setup (falling)
SPI Mode 1: This is the default SPI mode without any config; Leading edge: setup (rising) Trailing edge: sample (falling)
SPI Mode 2: This mode sets Leading edge: sample (falling) Trailing edge: setup (rising)
SPI Mode 3: This mode sets Leading edge: setup (falling) Trailing edge: sample (rising)
--------------------------------------------------------------------------------------------------------------------------------------------                                                            
*/