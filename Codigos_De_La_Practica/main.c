/*
 * APE 1 - Codigo 5: Microchip Studio (C puro, sin Arduino)
 * Dispositivo: ATmega328P | Toolchain: AVR/GNU C Compiler (avr-gcc)
 */

#include <avr/io.h>

int main(void)
{
    // Configura PB5 (D13) y PB0 (D8) como salidas.
    DDRB |= (1 << DDB5) | (1 << DDB0);

    // Configura PD2 (D2) como entrada para el pulsador.
    DDRD &= ~(1 << DDD2);

    // Activa la resistencia pull-up interna de PD2.
    PORTD = (1 << PORTD2);

    while (1)
    {
        // Comprueba el estado del pulsador conectado a PD2.
        if (PIND & (1 << PIND2)) {
            // Pulsador sin presionar: apaga el LED integrado de PB5.
            PORTB &= ~(1 << PORTB5);
        } else {
            // Pulsador presionado: enciende el LED integrado de PB5.
            PORTB |= (1 << PORTB5);
        }

        // Invierte el estado de PB0 en cada iteración.
        PORTB ^= (1 << PORTB0);
    }
}
