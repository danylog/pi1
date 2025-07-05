################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Versuch00/Testprogramm_Eclipse_Doxygen/Complex.cpp \
../Versuch00/Testprogramm_Eclipse_Doxygen/main.cpp 

CPP_DEPS += \
./Versuch00/Testprogramm_Eclipse_Doxygen/Complex.d \
./Versuch00/Testprogramm_Eclipse_Doxygen/main.d 

OBJS += \
./Versuch00/Testprogramm_Eclipse_Doxygen/Complex.o \
./Versuch00/Testprogramm_Eclipse_Doxygen/main.o 


# Each subdirectory must supply rules for building sources it contributes
Versuch00/Testprogramm_Eclipse_Doxygen/%.o: ../Versuch00/Testprogramm_Eclipse_Doxygen/%.cpp Versuch00/Testprogramm_Eclipse_Doxygen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Versuch00-2f-Testprogramm_Eclipse_Doxygen

clean-Versuch00-2f-Testprogramm_Eclipse_Doxygen:
	-$(RM) ./Versuch00/Testprogramm_Eclipse_Doxygen/Complex.d ./Versuch00/Testprogramm_Eclipse_Doxygen/Complex.o ./Versuch00/Testprogramm_Eclipse_Doxygen/main.d ./Versuch00/Testprogramm_Eclipse_Doxygen/main.o

.PHONY: clean-Versuch00-2f-Testprogramm_Eclipse_Doxygen

