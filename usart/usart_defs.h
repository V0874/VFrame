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

// USART Control Register A

#define USART_RX_SUCCESS        (1 << 7)                // receive complete flag 
#define USART_TX_SUCCESS        (1 << 6)                // transmit complete flag
#define USART_BUFF_EMPTY        (1 << 5)                // transmit buffer empty flag
#define USART_FRAME_ERROR       (1 << 4)                // frame error flag
#define USART_DATA_OVERRUN      (1 << 3)                // data overrun flag
#define USART_PARITY_ERROR      (1 << 2)                // parity error flag
#define USART_DBL_SPEED_MODE    (1 << 1)                // double transmission speed setting
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

#define USART_MODE_RESET        ((1 << 6) | (1 << 7))   /* reset usart mode prior to configuring mode selection;
                                                        if reset and a mode is not set subsequently, expect asynchronous mode by default */

#define USART_SYNC_MODE         (1 << 6)                // set synchronous mode
#define USART_MASTER_SPI_MODE   ((1 << 6) | (1 << 7))   // set master spi mode
#define USART_PARITY_RESET      ((1 << 4) | (1 << 5))   // must reset the mode prior to parity configuration; parity is disabled by default.
#define USART_EVEN_PARITY       (1 << 5)                // even parity mode enabled
#define USART_ODD_PARITY        ((1 << 4) | (1 << 5))   // odd parity mode enabled
#define USART_STOP_BIT_MODE     (1 << 3)                // clearing stop bit mode to 0 sets 1 stop bit; setting the mode to 1 sets 2 stop bits

#define USART_DATA_BITS_MODE    ((1 << 1) | (1 << 2))   /* must clear the mode prior to char size config other than default;
                                                        8 bit is set by default without any config;
                                                        if mode is cleared, and usart_data_bits bit is cleared with no subsequent config 
                                                        expect 5-bit data bits */

#define USART_DATA_BITS_6BITS   (1 << 1)                // sets char size to 6 bits assuming the mode has been cleared
#define USART_DATA_BITS_7BITS   (1 << 2)                // sets char size to 7 bits assuming the mode has been cleared
#define USART_DATA_BITS_9BITS   ((1 << 1) | (1 << 2))   // sets char size to 9 bits and char_size in control register B must be set to 1

#define USART_CLOCK_POLARITY    (1 << 0)                /* transmitted data rising edge; received data falling edge by default;
                                                        if this  bit is set the configuration is reversed */

/*
--------------------------------------------------------------------------------------------------------------------------------------------
*/
