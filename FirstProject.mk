##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FirstProject
ConfigurationName      :=Debug
WorkspacePath          :=/home/bekeband/CLWorkSpace/STM32Workspace
ProjectPath            :=/home/bekeband/CLWorkSpace/STM32Workspace/FirstProject
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Beke András
Date                   :=02/05/17
CodeLitePath           :=/home/bekeband/.codelite
LinkerName             :=/usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-g++
SharedObjectLinkerName :=/usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).elf
Preprocessors          :=$(PreprocessorSwitch)STM32F103xB 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="FirstProject.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -T $(ProjectPath)/STM32F103XB_FLASH.ld -Xlinker --gc-sections -Xlinker -Map=$(IntermediateDirectory)/$(ProjectName).map -mthumb -mcpu=cortex-m3 -march=armv7-m
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(WorkspacePath)/../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include $(IncludeSwitch)$(WorkspacePath)/../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Include $(IncludeSwitch)$(WorkspacePath)/../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Inc 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-ar rcu
CXX      := /usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-g++
CC       := /usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-gcc
CXXFLAGS :=  $(Preprocessors)
CFLAGS   := -g -mcpu=cortex-m3 -mthumb $(Preprocessors)
ASFLAGS  := 
AS       := /usr/local/gcc-arm-none-eabi-5_2-2015q4/bin/arm-none-eabi-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(ObjectSuffix) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/interrupts.c$(ObjectSuffix) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(ObjectSuffix) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(ObjectSuffix) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(ObjectSuffix) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	/usr/local/gcc_arm/arm-none-eabi-objcopy -O ihex ./Debug/FirstProject.elf ./Debug/FirstProject.hex
	/usr/local/gcc_arm/arm-none-eabi-size ./Debug/FirstProject.elf
	/usr/local/gcc_arm/arm-none-eabi-objdump -d -f ./Debug/FirstProject.elf > ./Debug/FirstProject.lst
	@echo Done

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_system_stm32f1xx.c$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/system_stm32f1xx.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(DependSuffix)
	$(AS) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s" $(ASFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(ObjectSuffix) -I$(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_CMSIS_Device_ST_STM32F1xx_Source_Templates_gcc_startup_stm32f103xb.s$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Workspace/FirstProject/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/interrupts.c$(ObjectSuffix): interrupts.c $(IntermediateDirectory)/interrupts.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Workspace/FirstProject/interrupts.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interrupts.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interrupts.c$(DependSuffix): interrupts.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interrupts.c$(ObjectSuffix) -MF$(IntermediateDirectory)/interrupts.c$(DependSuffix) -MM interrupts.c

$(IntermediateDirectory)/interrupts.c$(PreprocessSuffix): interrupts.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interrupts.c$(PreprocessSuffix) interrupts.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_gpio.c$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal.c$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_rcc.c$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(ObjectSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bekeband/CLWorkSpace/STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(DependSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(DependSuffix) -MM ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c

$(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(PreprocessSuffix): ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_STM32Cube_FW_F1_V1.4.0_Drivers_STM32F1xx_HAL_Driver_Src_stm32f1xx_hal_cortex.c$(PreprocessSuffix) ../../STM32Cube_FW_F1_V1.4.0/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


