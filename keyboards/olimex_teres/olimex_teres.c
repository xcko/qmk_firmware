/* Copyright 2019 xcko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <avr/power.h>
#include <avr/wdt.h>
#include "LUFA/Drivers/Peripheral/TWI.h"
#include "LUFA/Drivers/Peripheral/ADC.h"

#include "olimex_teres.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  /* Disable clock division */
  clock_prescale_set(clock_div_1);

  //Keyboard init
  DDRB = 0xff;
  PORTB = 0xff;

  DDRD = 0;
  PORTD = 0xfc;

  DDRC = 0;
  PORTC = 0xc0;

  DDRE = 0;
  PORTE = 0x44;

  DDRF = 0;
  PORTF = 0xf2;

  TWI_Init(TWI_BIT_PRESCALE_4 , TWI_BITLENGTH_FROM_FREQ(TWI_BIT_PRESCALE_4 , 100000));
  ADC_Init(ADC_FREE_RUNNING  | ADC_PRESCALE_128);
  ADCSRA |= 1 << ADIE;
  MCUCR = 0;
  EIMSK |= 1 << INT2;

  ADC_SetupChannel(0);
  ADC_StartReading(ADC_REFERENCE_AVCC | ADC_LEFT_ADJUSTED | ADC_CHANNEL0);

  // set timer0 counter initial value to 0
  TCNT0=0x00;
  // start timer0 with /1024 prescaler
  TCCR0B = (1<<CS02) | (1<<CS00);
  TIMSK0=1<<TOIE0;

  //button = 0xff;
  matrix_init_user();
}

/*
void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  // led_set_user(usb_led);
}

*/
