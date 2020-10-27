#include <atmel_start.h>
#include <hal_gpio.h>
#include <hal_delay.h>

int int2bits(int bits[4], int n, const int size){
	for(int i = 0; i < size; i++){
		bits[i] = n%2;
		n=n/2;
	}
}

void displaydigit(int bits[4]){
		gpio_set_pin_level(sevseg1, bits[0]);
		gpio_set_pin_level(sevseg2, bits[1]);
		gpio_set_pin_level(sevseg3, bits[2]);
		gpio_set_pin_level(sevseg4, bits[3]);
}


const int size = 4;
int h, t, o, mode = 1, number = 0;
int bits[size];
int main(void)
{
	pwm_set_parameters(&PWM_0, 1000, 5000);
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	while (1) {
		if(mode == 1){
			gpio_set_pin_level(LED1, 1);
			if (gpio_get_pin_level(button1)==1){
				delay_ms(100);
				if(number<99)
					number++; //while button one is pushed increase the displayed number
			}
			if (gpio_get_pin_level(button2)==1){
				delay_ms(100);
				if(number>0)
					number--; //while button two is pushed decrease the displayed number
			}
			o = number%10;
			t = (number/10)%10;
			int2bits(bits, t, size);
			gpio_set_pin_level(digit1_on, 1);
			gpio_set_pin_level(digit2_on, 0);
			displaydigit(bits);
			delay_ms(5);
			int2bits(bits, o, size);
			gpio_set_pin_level(digit1_on, 0);
			gpio_set_pin_level(digit2_on, 1);
			displaydigit(bits);
			delay_ms(5);
			pwm_set_parameters(&PWM_0, 10, 500);
			pwm_enable(&PWM_0);
			if (gpio_get_pin_level(mode_button)==1){
				gpio_set_pin_level(LED1, 0);
				number = 0;				
				mode = 2;
				delay_ms(100);
			}
		}
		if(mode == 2){
			gpio_set_pin_level(LED2, 1);
			int2bits(bits, number, size);
			displaydigit(bits);
			gpio_set_pin_level(digit1_on, 1);
			gpio_set_pin_level(digit2_on, 1);
			delay_ms(100);
			if (gpio_get_pin_level(mode_button)==1){
				gpio_set_pin_level(LED2, 0);
				mode = 3;
				delay_ms(100);
			}			
		}
		if(mode == 3){
			gpio_set_pin_level(LED3, 1);
			gpio_set_pin_level(digit1_on, 0);
			gpio_set_pin_level(digit2_on, 0);
			delay_ms(100);
			if (gpio_get_pin_level(mode_button)==1){
				gpio_set_pin_level(LED3, 0);
				mode = 1;
				delay_ms(100);
			}
		}
	}
}
