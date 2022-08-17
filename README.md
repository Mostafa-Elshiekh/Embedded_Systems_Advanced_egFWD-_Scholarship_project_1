# Embedded_Systems_Advanced_egFWD-_Scholarship_project_1
Control blinking of an LED for a user-defined ON and OFF periods  Create a function in the App layer that takes as an input from the user a specific ON time and OFF time in seconds, lights a LED for the given ON time, and dim it for the given OFF time. It’s prohibited to use predefined delay functions, only timer driver functions can be used. This function implements implicitly the PWM module using Timer Overflow.


## Prepare project folders

Create a COTS folder for the whole course including a folder for each layer in the layered architectureto include MCAL,HAL,SERVICE,APPLICATION and LIBRARIES

Provide a screenshot of your COTS folder with the stated arrangement

## Implement the GPIO driver

> 1-Create the GPIO driver from scratch using the sufficient interface,configure,private and program files
2-Create functions in GPIO driver that are needed to perform the required project functionality
Provide a screen recording of GPIO driver, explaining its functions and Macros, and how each function will help to achieve the functionality of the project (Maximum 3 minutes)

## Implement Timer driver

1-Create the Timer driver from scratch using the sufficient interface,configure,private and program files
2-Create functions in Timer driver that are needed to perform the required project functionality
3-Creating a Timer Overflow ISR that performs the required functionality
Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer
Provide a screen recording of TIMER driver, explaining its functions and Macros, and how each function will help to achieve the functionality of the project (Maximum 4 minutes)

## Implement interrupt driver

1-Creating the Interrupt driver from scratch using the sufficient interface,configure,private and program files
2-Create functions in Interrupt driver that are needed to perform the required project functionality
Provide a screen recording of Interrupt driver, explaining its functions and Macros, and how each function will help to achieve the functionality of the project (Maximum 2 minutes)

## Test your application

1-Deliver a screen recording of your code (main.c), and run it while showing the Tiva C board simulator showing how the LED status would vary by changing the ON/OFF time in runtime. (Maximum 3 minutes)
