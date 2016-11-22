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


#include <unistd.h>
#include <stdio.h>
#include "pwm_fun.h"
//-------------------------Constants--------------------------------//
#define STR_LEN 100
//---------------------Global Variables-----------------------------//
char comd[STR_LEN];
//-------------------------Functions--------------------------------//
/********************************************************************/
/*                  PWM init Function                               */
/********************************************************************/

void _init_pwm_pin(int header ,int pin)
{
    printf("pwm intiation on  pin P%d,%d \n",header,pin);
    sprintf(comd,"echo bone_pwm_P%d_%d >> /sys/devices/bone_capemgr.9/slots",header,pin);
    system(comd);

    
}
/********************************************************************/
/*              PWM Release function                                */
/********************************************************************/
void free_pwm()
{
    FILE *fp;
	char tst[255];
	char X[4];
	char Id[STR_LEN];
	
	
	system("cat /sys/devices/bone_capemgr.9/slots > ~/HAMMAMI/data/slot.txt ");
	fp = fopen("/root/HAMMAMI/data/slot.txt","r");
	while (fgets(tst,255,fp)!= NULL)
		{
			if (tst[53]=='b')
			{
				X[1] = tst[0];
				X[2]=tst[1];
				if (X[1]==' ')
				{
					X[1]=X[2];
					X[2]=' ';
					
				}
			
				sprintf(Id,"echo -%c%c > /sys/devices/bone_capemgr.9/slots",X[1],X[2]);
				
				
			};
		};	
	
	printf("shutting down pwm\n");
	fclose(fp);
	system(Id);

    
}
/**************************************************************************/
/*					duty setting function								  */
/**************************************************************************/
void pwm_duty_set(int header ,int pin ,int duty)
{
	FILE *fx;
	char tst[255];
	char X[4];
	char pin_str[3];
	char header_str[3];
	
	sprintf(pin_str,"%d",pin);
	sprintf(header_str,"%d",header);
	
	system("ls /sys/devices/ocp.3/ > ~/HAMMAMI/data/ocp.txt ");
	fx = fopen("/root/HAMMAMI/data/ocp.txt","r");
	while (fgets(tst,255,fx)!= NULL)
		{
			if ((tst[0]=='p')&&(tst[1]=='w')&&(tst[10]==header_str[0])&&(tst[12]==pin_str[0])&&(tst[13]==pin_str[1]))
			{
				X[1] = tst[15];
				X[2]=tst[16];
			};
		};	
	
	fclose(fx);

	sprintf(comd,"sudo echo %d > /sys/devices/ocp.3/pwm_test_P%d_%d.%c%c/duty",duty,header,pin,X[1],X[2]);
	printf(comd);
	printf("\n");
	system(comd);
	sprintf(comd,"cat /sys/devices/ocp.3/pwm_test_P%d_%d.%c%c/duty",header,pin,X[1],X[2]);
	system(comd);
	
	
}
/**************************************************************************/
/*					period setting function								  */
/**************************************************************************/
void pwm_period_set(int header , int pin , int period)
{

	FILE *fx;
	char tst[255];
	char X[4];
	char pin_str[3];
	char header_str[3];
	
	sprintf(pin_str,"%d",pin);
	sprintf(header_str,"%d",header);
	
	system("ls /sys/devices/ocp.3/ > ~/HAMMAMI/data/ocp.txt ");
	fx = fopen("/root/HAMMAMI/data/ocp.txt","r");
	while (fgets(tst,255,fx)!= NULL)
		{
			if ((tst[0]=='p')&&(tst[1]=='w')&&(tst[10]==header_str[0])&&(tst[12]==pin_str[0])&&(tst[13]==pin_str[1]))
			{
				X[1] = tst[15];
				X[2]=tst[16];
			};
		};	
	
	fclose(fx);
	
	sprintf(comd,"sudo echo %d > /sys/devices/ocp.3/pwm_test_P%d_%d.%c%c/period",period,header,pin,X[1],X[2]);
	printf(comd);
	printf("\n");
	system(comd);
	sprintf(comd,"cat /sys/devices/ocp.3/pwm_test_P%d_%d.%c%c/period",header,pin,X[1],X[2]);
	system(comd);

	
}
/**************************************************************************/


