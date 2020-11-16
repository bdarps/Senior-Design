#include <atmel_start.h>
#include <hal_gpio.h>
#include <hal_delay.h>

const int size = 4;
int h, t, o, mode = 1, number = 0, motorCount = 100, sensorCount = 0, prevSensorCount = 0;
int bits[size];

void int2bits(int bits[4], int n, const int size){
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

void displayOn(void){ //shows number on the displays
			o = number%10; //get ones digit
			t = (number/10)%10; //get tens digit
			int2bits(bits, t, size);
			gpio_set_pin_level(digit1_on, 1);
			gpio_set_pin_level(digit2_on, 0);
			displaydigit(bits); //display tens digit on display 1
			delay_ms(5);
			int2bits(bits, o, size);
			gpio_set_pin_level(digit1_on, 0);
			gpio_set_pin_level(digit2_on, 1);
			displaydigit(bits); // display ones digit on display 2
			delay_ms(5);
}

void delay4display(int time){ //a delay that avoids interfering with the displays' functionality
	for(int i = 0; i < time/10; i++){
			displayOn();
	}
}

int main(void)
{
	//pwm_set_parameters(&PWM_0, 5000, 5000);
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	while (1) {
		
		//Mode 1: user set torque
		if(mode == 1){ //sets output according to user input
			gpio_set_pin_level(LED1, 1);
			//number = 0;
			if (gpio_get_pin_level(button1)==1){
				delay_ms(100);
				if(number<99){
					number++; //while button one is pushed increase the displayed number
					motorCount++; //add time for motor to be on clockwise
				}
			}
			if (gpio_get_pin_level(button2)==1){
				delay_ms(100);
				if(number>0){
					number--; //while button two is pushed decrease the displayed number
					motorCount--; //add time for motor to be on counterclockwise
				}
			}
			
			displayOn();
			
			while((motorCount!=100)&&(gpio_get_pin_level(button1)!=1)&&(gpio_get_pin_level(button2)!=1)){
				if(motorCount < 100){
					gpio_set_pin_level(Dirneg, 1);
					gpio_set_pin_level(Dirpos, 0); //set motor direction counter clockwise
					delay4display(500);
					motorCount++;
				}
				if(motorCount > 100){
					gpio_set_pin_level(Dirneg, 0);
					gpio_set_pin_level(Dirpos, 1); //set motor direction clockwise
					delay4display(500);
					motorCount--;
				}
				gpio_set_pin_level(Dirneg, 0);
				gpio_set_pin_level(Dirpos, 0); 
			}
			
			//pwm no longer used for motor control
			//pwm_enable(&PWM_0);
			//pwm_set_parameters(&PWM_0, 100, number);
			//delay_ms(2000);
			//pwm_set_parameters(&PWM_0, 500, 100);
			
			if (gpio_get_pin_level(mode_button)==1){ //mode change
				gpio_set_pin_level(LED1, 0);		
				number = 0;
				mode = 2;
				delay_ms(100);
			}
		}
		
		
		//Mode 2: vary with sensor input
		if(mode == 2){ //varies output according to sensor input 
			gpio_set_pin_level(LED2, 1);
			/*
			while(!gpio_get_pin_level(sensor)){
				sensorCount++;
			}
			if(sensorCount > prevSensorCount){
				gpio_set_pin_level(Dirneg, 1);
				gpio_set_pin_level(Dirpos, 0); //set motor direction counter clockwise
				delay4display(500);
			}
			if(sensorCount < prevSensorCount){
				gpio_set_pin_level(Dirneg, 0);
				gpio_set_pin_level(Dirpos, 1); //set motor direction counter clockwise
				delay4display(500);
			}
			gpio_set_pin_level(Dirneg, 0);
			gpio_set_pin_level(Dirpos, 0); 
			prevSensorCount = sensorCount;
			*/
			int2bits(bits, number, size);
			displaydigit(bits);
			gpio_set_pin_level(digit1_on, 1);
			gpio_set_pin_level(digit2_on, 1);
			delay_ms(100);
			
			if (gpio_get_pin_level(mode_button)==1){ //mode change
				gpio_set_pin_level(LED2, 0);
				sensorCount = 0;
				prevSensorCount = 0;
				mode = 3;
				delay_ms(100);
			}			
		}
		
		
		//Mode 3: standby
		if(mode == 3){ //standby mode, only mode LED should be on
			gpio_set_pin_level(LED3, 1);
			gpio_set_pin_level(digit1_on, 0);
			gpio_set_pin_level(digit2_on, 0); //turn of displays
			delay_ms(100);
			if (gpio_get_pin_level(mode_button)==1){ //mode change
				gpio_set_pin_level(LED3, 0);
				mode = 1;
				delay_ms(100);
			}
		}
	}
}
