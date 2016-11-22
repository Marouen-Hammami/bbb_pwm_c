/********************************************************************/
/* This program let's you access the PWM devices on beagle bone and */
/* activate, change periods and duty cycle of PWM pins              */
/*------------------------------------------------------------------*/
/* Author:   Marouen HAMMAMI                                        */
/* Date:     20/11/2016                                             */
/* Email :   hammami.marwen1994@gmail.com                           */
/*------------------------------------------------------------------*/
/* DATE       |	 UPDATES                         | Author           */
/* 22/11/2016 | Added duty and period settings   | Marouen HAMMAMI  */
/********************************************************************/

//////////////////////////////////////////////////////////////////////
void _init_pwm_pin(int header ,int pin);                            // pwm intialization function  
void free_pwm();                                                    // all pwm release 
void pwm_duty_set(int header ,int pin ,int duty);                   // duty set function
void pwm_period_set(int header , int pin , int period);             // period set function
//////////////////////////////////////////////////////////////////////
/* Make sure to call pwm_period_set function before pwm_duty_set    */
/* Make sure that duty is always less than period                   */
/********************************************************************/

