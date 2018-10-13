# C-fork-System-Call

> make 
Makefile:5: warning: overriding commands for target `interface'
Makefile:3: warning: ignoring old commands for target `interface'
make: Circular interface <- interface dependency dropped.
gcc -o server server.c
gcc -o interface interface.c
> ./interface 
Pipes opened successfully. Forking.
Input command: 
element = 0: id = 987654, odometer = 201200, gallons = 4.000000
element = 1: id = red, odometer = 89114, gallons = 0.000000
element = 2: id = red, odometer = 89712, gallons = 13.500000
element = 3: id = red, odometer = 90229, gallons = 15.300000
element = 4: id = 987654, odometer = 201001, gallons = 0.000000
element = 5: id = 987654, odometer = 201111, gallons = 5.200000
element = 6: id = 987654, odometer = 201612, gallons = 25.290001
element = 7: id = red, odometer = 89300, gallons = 7.100000
element = 8: id = green, odometer = 16, gallons = 0.000000
element = 9: id = green, odometer = 216, gallons = 20.000000
element = 10: id = green, odometer = 518, gallons = 61.000000
element = 11: id = green, odometer = 879, gallons = 50.000000
mpg,red
Response: Average MPG = 31.058498
Input command: 
mpg,green
Response: Average MPG = 6.587786
Input command: 
mpg,yellow
Input id not found
Response: 
Input command: 
exit
Response: Server complete. 

Interface: child process (16497) completed.
Interface: child process exit status = 10.
Interface: complete

> ./interface 
Pipes opened successfully. Forking.
Input command: 
element = 0: id = 987654, odometer = 201200, gallons = 4.000000
element = 1: id = red, odometer = 89114, gallons = 0.000000
element = 2: id = red, odometer = 89712, gallons = 13.500000
element = 3: id = red, odometer = 90229, gallons = 15.300000
element = 4: id = 987654, odometer = 201001, gallons = 0.000000
element = 5: id = 987654, odometer = 201111, gallons = 5.200000
element = 6: id = 987654, odometer = 201612, gallons = 25.290001
element = 7: id = red, odometer = 89300, gallons = 7.100000
element = 8: id = green, odometer = 16, gallons = 0.000000
element = 9: id = green, odometer = 216, gallons = 20.000000
element = 10: id = green, odometer = 518, gallons = 61.000000
element = 11: id = green, odometer = 879, gallons = 50.000000
list,red
Response: element = 1: id = red, odometer = 89114, gallons = 0.000000
element = 2: id = red, odometer = 89300, gallons = 7.100000
element = 3: id = red, odometer = 89712, gallons = 13.500000
element = 7: id = red, odometer = 90229, gallons = 15.300000

Input command: 
list,green
Response: element = 8: id = green, odometer = 16, gallons = 0.000000
element = 9: id = green, odometer = 216, gallons = 20.000000
element = 10: id = green, odometer = 518, gallons = 61.000000
element = 11: id = green, odometer = 879, gallons = 50.000000

Input command: 
mpg,red
Response: Average MPG = 31.058495
Input command: 
mpg,green
Response: Average MPG = 6.587786
Input command: 
mpg,yellow
Input id not found
Response: 
Input command: 
exit
Response: Server complete. 

Interface: child process (16497) completed.
Interface: child process exit status = 10.
Interface: complete

> ./interface 
Pipes opened successfully. Forking.
Input command: 
element = 0: id = 987654, odometer = 201200, gallons = 4.000000
element = 1: id = red, odometer = 89114, gallons = 0.000000
element = 2: id = red, odometer = 89712, gallons = 13.500000
element = 3: id = red, odometer = 90229, gallons = 15.300000
element = 4: id = 987654, odometer = 201001, gallons = 0.000000
element = 5: id = 987654, odometer = 201111, gallons = 5.200000
element = 6: id = 987654, odometer = 201612, gallons = 25.290001
element = 7: id = red, odometer = 89300, gallons = 7.100000
element = 8: id = green, odometer = 16, gallons = 0.000000
element = 9: id = green, odometer = 216, gallons = 20.000000
element = 10: id = green, odometer = 518, gallons = 61.000000
element = 11: id = green, odometer = 879, gallons = 50.000000
exit
Response: Server complete. 

Interface: child process (16492) completed.
Interface: child process exit status = 10.
Interface: complete

> ./interface 
Pipes opened successfully. Forking.
Input command: 
element = 0: id = 987654, odometer = 201200, gallons = 4.000000
element = 1: id = red, odometer = 89114, gallons = 0.000000
element = 2: id = red, odometer = 89712, gallons = 13.500000
element = 3: id = red, odometer = 90229, gallons = 15.300000
element = 4: id = 987654, odometer = 201001, gallons = 0.000000
element = 5: id = 987654, odometer = 201111, gallons = 5.200000
element = 6: id = 987654, odometer = 201612, gallons = 25.290001
element = 7: id = red, odometer = 89300, gallons = 7.100000
element = 8: id = green, odometer = 16, gallons = 0.000000
element = 9: id = green, odometer = 216, gallons = 20.000000
element = 10: id = green, odometer = 518, gallons = 61.000000
element = 11: id = green, odometer = 879, gallons = 50.000000
mpg,red
Response: Average MPG = 31.058498
Input command: 
mpg,green
Response: Average MPG = 6.587786
Input command: 
mpg,987654
Response: Average MPG = 17.715279
Input command: 
exit
Response: Server complete. 

Interface: child process (16497) completed.
Interface: child process exit status = 10.
Interface: complete
> ^Dexit
