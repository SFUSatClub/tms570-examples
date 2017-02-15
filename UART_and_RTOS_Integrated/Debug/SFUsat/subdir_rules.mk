################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
SFUsat/SFU_Serial.obj: ../SFUsat/SFU_Serial.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7R4 --code_state=32 --include_path="C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/Users/Richard Arthurs/workspace_v6_2/UART_and_RTOS_Integrated/SFUsat" --include_path="C:/Users/Richard Arthurs/workspace_v6_2/UART_and_RTOS_Integrated/include" -g --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --enum_type=packed --preproc_with_compile --preproc_dependency="SFUsat/SFU_Serial.d" --obj_directory="SFUsat" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


