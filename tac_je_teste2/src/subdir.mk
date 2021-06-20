################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Component.cpp \
../src/Face.cpp \
../src/Game.cpp \
../src/GameObject.cpp \
../src/Main.cpp \
../src/Music.cpp \
../src/Rect.cpp \
../src/Sound.cpp \
../src/Sprite.cpp \
../src/State.cpp \
../src/Vec2.cpp 

OBJS += \
./src/Component.o \
./src/Face.o \
./src/Game.o \
./src/GameObject.o \
./src/Main.o \
./src/Music.o \
./src/Rect.o \
./src/Sound.o \
./src/Sprite.o \
./src/State.o \
./src/Vec2.o 

CPP_DEPS += \
./src/Component.d \
./src/Face.d \
./src/Game.d \
./src/GameObject.d \
./src/Main.d \
./src/Music.d \
./src/Rect.d \
./src/Sound.d \
./src/Sprite.d \
./src/State.d \
./src/Vec2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


