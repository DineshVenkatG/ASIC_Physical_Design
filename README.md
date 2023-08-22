
# VLSI Physical Design for ASICs 

The objective of VLSI physical design for ASIC is to transform a digital circuit logic representation into a physical layout meeting the power,performance,area and manufacturability requirements .


* If you need to know about basic instructions you can read through them here , the daywise labs are in thier respective folders , the commands needed for them along with their explanations are also in those folders. The pre-requisites for installation will be at the end of the readme file , feel free to scroll down and install them !*


## Table of contents 

### DAY1
****
Introduction to RISCV ISA and GNU Compiler Toolchain


Basic keywords you need to know before proceeding :

* ISA
 - An ISA or the Instruction Set Architecture is part of the abstract model of the computer that defines how the CPU is controlled by the software . It acts as an interface between the hardware and the software,specifying both what the processor is capable of doing as well how it gets done.
 
 
* RISC-V
 - RISC-V is a versatile and open ISA that promotes collaboration and innovation in processor design and development.
  

* Compiler
 - A compiler is a software tool  that translates high-level programming code into machine code that can be executed directly by a computer's hardware .
 
 
* Assembler
 - A program or tool that translates assembly language code into machine code that can be executed by a computer's cpu.
 
* ALP
 - Assembly language is a low level programming lnguage that is closely related to the architecture of specificcomputer's cpu .
 
 
* HDL
 -Hardware Description language used for designing and describing digital hardware circuits . 
 - Eg: Verilog , System Verilog,VHDL
 
 
* GDS
 - Graphic data system: GDSII files contain information about the geometric shapes, layers, masks, and other essential details that make up the physical layout of a chip.
 
 
 
 
 
### Basic pre-requisties to be installed in your system and installation of the tool 
*****

```
sudo apt update 
sudo apt upgrade 

git clone https://github.com/kunalg123/riscv_workshop_collaterals.git

cd riscv_workshop_collaterals

chmod +x run.sh
 
./run.sh
```

## 1. Create a simple C program that calculates sum from 1 to N
****


Compile it using C compiler 
 ```
 gcc sum1.c -o sum1.o
 ./sum.o
 ```
-o allows you to name your output file

![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/4a0f0407-68c2-467c-8b85-fcde75a21101)

_____compile using riscv compiler and view the output_____
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum.o sum.c
spike pk sum.o
```
![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/697552a7-4f2c-48c4-a2ac-c636afe53dce)

*Contents of main*

![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/1c663ae0-ad06-4a87-b12b-8c9cb6ff6349)

```-O<number>```  :  indicates the level of optimisation 

after the optimization of  ```-Ofast```

![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/aa778c08-6b4c-4fca-8a98-c13a8627522e)

The below commands opens the debugger 
``` spike -d pk sum.o ```
This allows you to debug line by line 
``` until pc 0 100b0 ``` : this lets the debugger to run upto 100b0 and after that performs line by line debugging 

the below image shows the same :

![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/cee87279-e3bf-4236-9853-32fbaaf5b22e)

# Integer Number representation :
------------
*Number system for unsigned numbers*

* 64 bit double word
* 32 bit word
* Range of unsigned number is : [0,2^(n)-1]

*Number system for signed numbers*

The signed number is represented in 2's complement form
* The MSB is sign bit 
* Range is [-2^(n-1),2^(n-1)-1]



## 2. Write a C program to check the maximum 64 bit unsigned number and max and min 64 bit unsigned number .
The code is compiled using gcc and using the riscv tool chain 

![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/735922df-ba95-4317-b0fd-2410aa3e9ac3)


*********
*********
### DAY2 

*******
### ABI: Application Binary Interface

Interface is the appearance provided to the user.
Given an application to run on hardware, there are multiple interface in between for it to run on hardware , this is done by application binary interface.
Given below is a pictorial representation of how from an application to hardware everything is interfaced 



+ The parts of ISA that are accessible to User: User ISA
+ The parts of ISA accessible to the OS: system ISA
+ The access is done using system calls
+ The ABI accesses the system via *Registers*.

### ABI Names :
+ Specific name through which you can access the internal registers of the risc-v CPU core .
+ The ABI names and their corresponding usage are given below :
  
### Base integer instructions :
*RISCV belongs to the little endian memory addressing system*
There are 47 base instructions present in RISC-V ISA 

1. R-type (Register type ):
   They operate on registers and have fixed format for their operands

2. I - types (Immediate type):
   These instructions have an immediate operand and one register operand.

3. S-type (Store-type):
   These instructions are used for storing values from registers to memory.

4. B-type (Branch-type):
   These instructions perform conditional branching based on comparisons.

5. U-type(Upper Immediate Type):
   Have a larger immediate field for encoding larger constants.

6. J-type (Jump type):
   Used for unconditional jumps and functional calls.


-------------



## Simulate C program using ABI function call and execution 


![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/1ecb0f55-8897-4ca2-96ca-306121e7eb1c)



![image](https://github.com/DineshVenkatG/ASIC_Physical_Design/assets/99543009/79099efd-f52f-4242-943a-8cd31d3abd48)

