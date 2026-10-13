/*
 * New Orleans -- On Real Hardware -- MSP430G2553
 *
 * Target architecture: TI MSP430G2553 on the MSP-EXP430G2/G2ET LaunchPad.
 * Built with msp430-elf-gcc 9.3.1.11 using -mmcu=msp430g2553,
 * -mcpu=msp430, -Os, -g, and C99.
 *
 * This program mimics the New Orleans level from Matasano's
 * Microcorruption CTF and can be considered a spiritual successor.
 *
 * UART input is used to read the password from the user.
 * LEDs:
 *   P1.0 — Red   — Locked
 *   P1.6 — Green — Unlocked
 *
 * UART: 9600 baud, 8N1; P1.1 RX / P1.2 TX.
 */
#include <msp430.h>
#include <stdint.h>

#if !defined(__MSP430G2553__)
#error "This port requires MSP430G2553"
#endif

static char expected_password[8];

__attribute__((noinline))
static void board_init(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    /* The UART baud calculation requires the factory 1 MHz calibration. */
    if (CALBC1_1MHZ == 0xff || CALDCO_1MHZ == 0xff)
        for (;;) { }  /* Calibration must be restored or supplied explicitly. */
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    BCSCTL2 = 0;

    /* P1.0 = red LED
     * P1.6 = green LED
     *
     * Default/locked state:
     *   red   = ON
     *   green = OFF
     */
    P1SEL  &= ~(BIT0 | BIT6);
    P1SEL2 &= ~(BIT0 | BIT6);

    /* Preload output state before enabling output direction. */
    P1OUT &= ~(BIT0 | BIT6);
    P1OUT |= BIT0;

    P1DIR |= BIT0 | BIT6;

    P1SEL |= BIT1 | BIT2;
    P1SEL2 |= BIT1 | BIT2;
    UCA0CTL1 = UCSWRST | UCSSEL_2;
    UCA0CTL0 = 0;  /* asynchronous UART, 8 bits, no parity, 1 stop bit */
    UCA0BR0 = 104;
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;
    UCA0CTL1 &= (uint8_t)~UCSWRST;
}

static void uart_putchar(char c)
{
    while (!(IFG2 & UCA0TXIFG)) { }
    UCA0TXBUF = (uint8_t)c;
}

static void uart_puts(const char *s)
{
    while (*s) uart_putchar(*s++);
    uart_putchar('\r');
    uart_putchar('\n');
}

__attribute__((noipa))
static void getsn(char *destination, unsigned int capacity)
{
    unsigned int used = 0;
    if (!capacity) return;
    for (;;) {
        while (!(IFG2 & UCA0RXIFG)) { }
        char c = (char)UCA0RXBUF;
        if (c == '\r' || c == '\n') break;
        if (used + 1 < capacity) destination[used++] = c;
        /* Drain an overlong line while keeping space for the NUL. */
    }
    destination[used] = '\0';
}

/* Preserve the original New Orleans get_password() function boundary. */
__attribute__((noinline))
static void get_password(char *destination)
{
    getsn(destination, 100);
}

__attribute__((noinline))
static void create_password(void)
{
    expected_password[0] = 'h'; expected_password[1] = 'u';
    expected_password[2] = 'n'; expected_password[3] = 't';
    expected_password[4] = 'e'; expected_password[5] = 'r';
    expected_password[6] = '2'; expected_password[7] = '\0';
}

__attribute__((noinline))
static unsigned int check_password(const char *password)
{
    for (unsigned int i = 0; i != 8; ++i)
        if (password[i] != expected_password[i]) return 0;
    return 1;
}

__attribute__((noinline))
static void unlock_door(void)
{
    P1OUT &= ~BIT0;  /* Red Off */
    P1OUT |=  BIT6;  /* Green On */
}

int main(void)
{
    char password[100];
    board_init();
    create_password();
    uart_puts("Enter the password to continue");
    get_password(password);
    if (check_password(password)) {
        uart_puts("Access Granted!");
        unlock_door();
    } else {
        uart_puts("Invalid password; try again.");
    }
    while (UCA0STAT & UCBUSY) { }  /* Finish UART output before stopping clocks. */
    for (;;) __bis_SR_register(LPM4_bits);  /* Remain in LPM4 until hardware reset. */
}
