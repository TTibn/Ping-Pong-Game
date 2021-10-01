/*
 * Ping_Pong.c
 *
 *  Created on: Apr 18, 2021
 *      Author: Theocharis Theocharidis
 */

#include "io.h"
#include "alt_types.h"
#include "system.h"
#include <stdbool.h>

int main()
{
	alt_u32 sw;  // 32bits variable statement to be used for the 2 push buttons 
  bool sign = false; // Statement and initialization of boolean variable for continuous movement of leds 
  bool flag=false;  // Declaration and initialization of boolean variable to restart a ping pong set 
  alt_u32 leds = 0x00000001; //Declaration and initialization of the variable for leds
  alt_u32 leds1=0x0000001; // Declaration and initialization of the right-hand led as the Player on the Right 
  alt_u32 leds2=0x02000000; // Declaration and initialization of the leftmost led as the Player on the Left 
  int win1,win2=0, count=0, i, itr = 90000; 


  while (1)
  {
	  IOWR(LED_OUT_BASE, 0, leds); // Writing the value of the leds variable to the 26 bits (26 leds) amplitude register PIO 

   if (sign) // Part of a program for the continuous movement of leds 
   {
	   leds = leds >> 1;
    }
   else
   {
	   leds = leds << 1;
   }

   for (i = 0; i < itr; i++); // Loop Structure for delay 

    if (leds == 0x02000000)
    {//If the player on the left presses the 2nd push button (Button 7), then the direction of movement of the leds changes (racket repulsion) 
    	sw = IORD(SW_IN_BASE, 0);  //Read the register value for the push buttons and enter the variable sw 
    	if (!(sw & 0x02)) // Apply mask 00000010 with the operator & to see if the left button is pressed (Button 7) 
    	{
    	    sign=true;
            count++;
        }
    	else
    	{/* The player on the left loses. 
    		Fast flashing (5 times) of all the LEDs on the board  */
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
       		IOWR(LED_OUT_BASE, 0, leds);
       		for (i=0; i<300000; i++);
       		leds = 0x3FFFFFF;
  	   		IOWR(LED_OUT_BASE, 0, leds);
       		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds=0x00000001;
    		IOWR(LED_OUT_BASE, 0, leds);
    		sign=false;
    		count=0;
    		itr=90000;
    		win2=win2+1;
    		if (win2>=2)
    		{// The player on the right wins the set. This is followed by a slow flashing of the right-hand led and its staying on 
    			IOWR(LED_OUT_BASE, 0, leds1 & 0x00);
    			for (i=0; i<400000; i++);
    		    IOWR(LED_OUT_BASE, 0, leds1);
    			for (i=0; i<400000; i++);
       			IOWR(LED_OUT_BASE, 0, leds1 & 0x00);
    		    for (i=0; i<400000; i++);
    		    IOWR(LED_OUT_BASE, 0, leds1);
    		    for (i=0; i<400000; i++);
    		    IOWR(LED_OUT_BASE, 0, leds1 & 0x00);
    		    for (i=0; i<400000; i++);
    		    IOWR(LED_OUT_BASE, 0, leds1);
    		    for (i=0; i<400000; i++);
    		    IOWR(LED_OUT_BASE, 0, leds1);
    		    for (i=0; i<1000000; i++);
    		    leds=0x00;
    		    IOWR(LED_OUT_BASE, 0, leds);
    		    win2=0;
    		    win1=0;
    		    flag=true;
    		}
    	}
    }

    if (leds == 0x00000001)
    {//If the player on the right presses the 1st push button (Button 6), then the direction of movement of the leds changes (racket repulsion) 
    	sw = IORD(SW_IN_BASE, 0); //Read the register value for the push buttons and enter the variable sw
    	if (!(sw & 0x01))// Apply mask 00000001 with the operator & to see if the right button is pressed (Button 6) 
    	{
    		sign=false;
            count++;
    	}
    	else
    	{/* The player on the right loses. 
    		Fast flashing (5 times) of all the LEDs on the board */
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x3FFFFFF;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds = 0x00;
    		IOWR(LED_OUT_BASE, 0, leds);
    		for (i=0; i<300000; i++);
    		leds=0x00000001;
    		IOWR(LED_OUT_BASE, 0, leds);
    		sign=false;
    		count=0;
    		itr=90000;
    		win1=win1+1;
    		if (win1>=2)
    		{// The player on the left wins the set. This is followed by a slow flashing of the left LED and it stays on 
    			IOWR(LED_OUT_BASE, 0, leds2 & 0x00);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2 & 0x00);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2 & 0x00);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2);
    			for (i=0; i<400000; i++);
    			IOWR(LED_OUT_BASE, 0, leds2);
    			for (i=0; i<1000000; i++);
    			win1=0;
    			win2=0;
    			leds=0x00;
    			IOWR(LED_OUT_BASE, 0, leds);
    			flag=true;
    		}
    	}
    }
    // Part of the program for changing the movement speeds of the ping pong ball 
    if ((count >= 8) & (count < 16))
    {
    	itr = 60000;
    }
    else if (count >= 16)
    {
    	itr = 45000;
    }
    // Part of a program to start a new set after pressing either of the two push buttons 
    if (flag)
    {
    	sw = IORD(SW_IN_BASE, 0);
    	if ((!(sw & 0x01)) || (!(sw & 0x02)))
    	{
    		leds=0x00000001;
    		IOWR(LED_OUT_BASE, 0, leds);
    		sign=false;
    		flag=false;
    	}
    }
  }
}
