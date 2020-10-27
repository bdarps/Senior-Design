/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_adc_base.h>

struct adc_sync_descriptor ADC_0;

struct pwm_descriptor PWM_0;

struct ac_sync_descriptor AC_0;

void ADC_0_PORT_init(void)
{
}

void ADC_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	adc_sync_init(&ADC_0, ADC, (void *)NULL);
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void PWM_0_PORT_init(void)
{

	gpio_set_pin_function(PWMpos, PINMUX_PA10E_TC1_WO0);

	gpio_set_pin_function(PWMneg, PINMUX_PA11E_TC1_WO1);
}

void PWM_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC1);
	_gclk_enable_channel(TC1_GCLK_ID, CONF_GCLK_TC2_SRC);
}

void PWM_0_init(void)
{
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, TC1, _tc_get_pwm());
}

void AC_0_PORT_init(void)
{
}

void AC_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBC, AC);
	_gclk_enable_channel(AC_GCLK_ID_DIG, CONF_GCLK_DIG_AC_SRC);
	_gclk_enable_channel(AC_GCLK_ID_ANA, CONF_GCLK_ANA_AC_SRC);
}

void AC_0_init(void)
{
	AC_0_CLOCK_init();
	ac_sync_init(&AC_0, AC);
	AC_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA19

	gpio_set_pin_level(decimal_pt,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(decimal_pt, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(decimal_pt, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA16

	gpio_set_pin_level(sevseg1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   0);

	// Set pin direction to output
	gpio_set_pin_direction(sevseg1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(sevseg1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA10

	gpio_set_pin_level(sevseg2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   0);

	// Set pin direction to output
	gpio_set_pin_direction(sevseg2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(sevseg2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	gpio_set_pin_level(sevseg3,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   0);

	// Set pin direction to output
	gpio_set_pin_direction(sevseg3, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(sevseg3, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA22

	gpio_set_pin_level(sevseg4,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   0);

	// Set pin direction to output
	gpio_set_pin_direction(sevseg4, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(sevseg4, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA23

	gpio_set_pin_level(digit1_on,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(digit1_on, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(digit1_on, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA24

	gpio_set_pin_level(digit2_on,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(digit2_on, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(digit2_on, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA25

	gpio_set_pin_level(digit3_on,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(digit3_on, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(digit3_on, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PB22

	gpio_set_pin_level(button1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   GPIO_PULL_UP);

	// Set pin direction to input
	gpio_set_pin_direction(button1, GPIO_DIRECTION_IN);

	gpio_set_pin_function(button1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB31

	gpio_set_pin_level(button2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   GPIO_PULL_UP);

	// Set pin direction to output
	gpio_set_pin_direction(button2, GPIO_DIRECTION_IN);

	gpio_set_pin_function(button2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA13

	gpio_set_pin_level(mode_button,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   GPIO_PULL_UP);

	// Set pin direction to output
	gpio_set_pin_direction(mode_button, GPIO_DIRECTION_IN);

	gpio_set_pin_function(mode_button, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA8

	gpio_set_pin_level(sensor,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   GPIO_PULL_UP);

	// Set pin direction to output
	gpio_set_pin_direction(sensor, GPIO_DIRECTION_IN);

	gpio_set_pin_function(sensor, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA16

	gpio_set_pin_level(LED1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED1, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA17

	gpio_set_pin_level(LED2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED2, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA18

	gpio_set_pin_level(LED3,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED3, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED3, GPIO_PIN_FUNCTION_OFF);
	
	// GPIO on PA14

	gpio_set_pin_level(LED0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA15

	// Set pin direction to input
	gpio_set_pin_direction(SW0, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(SW0,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(SW0, GPIO_PIN_FUNCTION_OFF);

	ADC_0_init();

	delay_driver_init();

	PWM_0_init();

	AC_0_init();
}
