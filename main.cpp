// ******* needs library **************
#include <avr/io.h> // standard library for AVR microcontrollers
#include <util/delay.h> // for _delay_ms()
// ************************************

#define F_CPU 1000000UL // defining CPU frequency

// array to store LED pins
int led_arr[5] = {PB0, PB1, PB2, PB3, PB4};

// function to turn LEDs on and off in a chain pattern
void chain_led(int num = 1){
	for(int j = 0; j < num; j++){
		// *** turn on LEDs one by one ***
		for(int i = 0; i < sizeof(led_arr) / sizeof(led_arr[0]); ++i){
			PORTB |= (1 << led_arr[i]); // set LED pin high
			_delay_ms(200); // wait for 200 ms
		}
		// ******************************
		
		// *** turn off LEDs one by one ***
		for(int i = 0; i < sizeof(led_arr) / sizeof(led_arr[0]); ++i){
			PORTB &= ~(1 << led_arr[i]); // set LED pin low
			_delay_ms(200); // wait for 200 ms
		}
		// *******************************
	}
}

// function to blink all LEDs simultaneously
void blink_led(int num = 1){
	for(int j = 0; j < num; j++){
		// *** turn on all LEDs ***
		for(int i = 0; i < sizeof(led_arr); ++i){
			PORTB |= (1 << led_arr[i]); // set all LED pins high
		}
		// **********************
		
		_delay_ms(200); // wait for 200 ms
		
		// *** turn off all LEDs ***
		for(int i = 0; i < sizeof(led_arr); ++i){
			PORTB &= ~(1 << led_arr[i]); // set all LED pins low
		}
		// ***********************
		_delay_ms(200); // wait for 200 ms
	}
}

// function to turn on and off alternating LEDs
void current_led(int num = 1){
	for(int j = 0; j < num; j++){
		// *** turn on 1st, 3rd, 5th LEDs ***
		for(int i = 0; i < sizeof(led_arr); i += 2){
			PORTB |= (1 << led_arr[i]); // set odd-numbered LED pins high
		}
		// **********************************
		_delay_ms(200); // wait for 200 ms
		// *** turn off 1st, 3rd, 5th LEDs ***
		for(int i = 0; i < sizeof(led_arr); i += 2){
			PORTB &= ~(1 << led_arr[i]); // set odd-numbered LED pins low
		}
		// ***********************************
		_delay_ms(200); // wait for 200 ms
		
		// *** turn on 2nd, 4th LEDs ***
		for(int i = 1; i < sizeof(led_arr) / sizeof(led_arr[0]); i += 2){
			PORTB |= (1 << led_arr[i]); // set even-numbered LED pins high
		}
		// ****************************
		_delay_ms(200); // wait for 200 ms
		// *** turn off 2nd, 4th LEDs ***
		for(int i = 1; i < sizeof(led_arr) / sizeof(led_arr[0]); i += 2){
			PORTB &= ~(1 << led_arr[i]); // set even-numbered LED pins low
		}
		// *****************************
		_delay_ms(200); // wait for 200 ms
	}
}

// function to turn LEDs on and off in a reverse chain pattern
void revers_chain_led(int num = 1){
	for(int j = 0; j < num; j++){
		// *** turn on LEDs in reverse order ***
		for(int i = (sizeof(led_arr) / sizeof(led_arr[0])) - 1; i >= 0; --i){
			PORTB |= (1 << led_arr[i]); // set LED pin high
			_delay_ms(200); // wait for 200 ms
		}
		// ************************************
		
		// *** turn off LEDs in reverse order ***
		for(int i = (sizeof(led_arr) / sizeof(led_arr[0])) - 1 ; i >= 0; --i){
			PORTB &= ~(1 << led_arr[i]); // set LED pin low
			_delay_ms(200); // wait for 200 ms
		}
		// *************************************
	}
}

// ******* the main function **********
int main(void){
	
	DDRB = 0b1111111; // set PORTB as output
	
	while(1){
		chain_led(2); // call chain_led function twice
		blink_led(3); // call blink_led function three times
		revers_chain_led(2); // call revers_chain_led function twice
		current_led(2); // call current_led function twice
	}
	
	return 0;
}
// *************************************
