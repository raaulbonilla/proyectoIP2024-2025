################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TADCasilla.cpp \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/entorno.cpp \
../src/numberTiles.cpp \
../src/pruebaTADCasilla.cpp \
../src/pruebaTADTablero.cpp 

CPP_DEPS += \
./src/TADCasilla.d \
./src/TADJuego.d \
./src/TADTablero.d \
./src/entorno.d \
./src/numberTiles.d \
./src/pruebaTADCasilla.d \
./src/pruebaTADTablero.d 

OBJS += \
./src/TADCasilla.o \
./src/TADJuego.o \
./src/TADTablero.o \
./src/entorno.o \
./src/numberTiles.o \
./src/pruebaTADCasilla.o \
./src/pruebaTADTablero.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TADCasilla.d ./src/TADCasilla.o ./src/TADJuego.d ./src/TADJuego.o ./src/TADTablero.d ./src/TADTablero.o ./src/entorno.d ./src/entorno.o ./src/numberTiles.d ./src/numberTiles.o ./src/pruebaTADCasilla.d ./src/pruebaTADCasilla.o ./src/pruebaTADTablero.d ./src/pruebaTADTablero.o

.PHONY: clean-src

