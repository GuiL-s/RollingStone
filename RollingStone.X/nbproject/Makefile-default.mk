#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c RS_motors.c RS_accelerometer.c RS_acc_mean.s library/uart/e_init_uart1.s library/uart/e_uart1_rx_char.s library/uart/e_uart1_tx_char.s library/motor_led/e_init_port.c library/motor_led/e_motors.c library/a_d/e_accelerometer.c library/a_d/e_ad_conv.c library/matlab/matlab.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/RS_motors.o ${OBJECTDIR}/RS_accelerometer.o ${OBJECTDIR}/RS_acc_mean.o ${OBJECTDIR}/library/uart/e_init_uart1.o ${OBJECTDIR}/library/uart/e_uart1_rx_char.o ${OBJECTDIR}/library/uart/e_uart1_tx_char.o ${OBJECTDIR}/library/motor_led/e_init_port.o ${OBJECTDIR}/library/motor_led/e_motors.o ${OBJECTDIR}/library/a_d/e_accelerometer.o ${OBJECTDIR}/library/a_d/e_ad_conv.o ${OBJECTDIR}/library/matlab/matlab.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/RS_motors.o.d ${OBJECTDIR}/RS_accelerometer.o.d ${OBJECTDIR}/RS_acc_mean.o.d ${OBJECTDIR}/library/uart/e_init_uart1.o.d ${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d ${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d ${OBJECTDIR}/library/motor_led/e_init_port.o.d ${OBJECTDIR}/library/motor_led/e_motors.o.d ${OBJECTDIR}/library/a_d/e_accelerometer.o.d ${OBJECTDIR}/library/a_d/e_ad_conv.o.d ${OBJECTDIR}/library/matlab/matlab.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/RS_motors.o ${OBJECTDIR}/RS_accelerometer.o ${OBJECTDIR}/RS_acc_mean.o ${OBJECTDIR}/library/uart/e_init_uart1.o ${OBJECTDIR}/library/uart/e_uart1_rx_char.o ${OBJECTDIR}/library/uart/e_uart1_tx_char.o ${OBJECTDIR}/library/motor_led/e_init_port.o ${OBJECTDIR}/library/motor_led/e_motors.o ${OBJECTDIR}/library/a_d/e_accelerometer.o ${OBJECTDIR}/library/a_d/e_ad_conv.o ${OBJECTDIR}/library/matlab/matlab.o

# Source Files
SOURCEFILES=main.c RS_motors.c RS_accelerometer.c RS_acc_mean.s library/uart/e_init_uart1.s library/uart/e_uart1_rx_char.s library/uart/e_uart1_tx_char.s library/motor_led/e_init_port.c library/motor_led/e_motors.c library/a_d/e_accelerometer.c library/a_d/e_ad_conv.c library/matlab/matlab.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F6014A
MP_LINKER_FILE_OPTION=,--script=p30F6014A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/RS_motors.o: RS_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_motors.o.d 
	@${RM} ${OBJECTDIR}/RS_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RS_motors.c  -o ${OBJECTDIR}/RS_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/RS_motors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/RS_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/RS_accelerometer.o: RS_accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_accelerometer.o.d 
	@${RM} ${OBJECTDIR}/RS_accelerometer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RS_accelerometer.c  -o ${OBJECTDIR}/RS_accelerometer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/RS_accelerometer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/RS_accelerometer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/motor_led/e_init_port.o: library/motor_led/e_init_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/motor_led" 
	@${RM} ${OBJECTDIR}/library/motor_led/e_init_port.o.d 
	@${RM} ${OBJECTDIR}/library/motor_led/e_init_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/motor_led/e_init_port.c  -o ${OBJECTDIR}/library/motor_led/e_init_port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/motor_led/e_init_port.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/motor_led/e_init_port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/motor_led/e_motors.o: library/motor_led/e_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/motor_led" 
	@${RM} ${OBJECTDIR}/library/motor_led/e_motors.o.d 
	@${RM} ${OBJECTDIR}/library/motor_led/e_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/motor_led/e_motors.c  -o ${OBJECTDIR}/library/motor_led/e_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/motor_led/e_motors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/motor_led/e_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/a_d/e_accelerometer.o: library/a_d/e_accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/a_d" 
	@${RM} ${OBJECTDIR}/library/a_d/e_accelerometer.o.d 
	@${RM} ${OBJECTDIR}/library/a_d/e_accelerometer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/a_d/e_accelerometer.c  -o ${OBJECTDIR}/library/a_d/e_accelerometer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/a_d/e_accelerometer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/a_d/e_accelerometer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/a_d/e_ad_conv.o: library/a_d/e_ad_conv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/a_d" 
	@${RM} ${OBJECTDIR}/library/a_d/e_ad_conv.o.d 
	@${RM} ${OBJECTDIR}/library/a_d/e_ad_conv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/a_d/e_ad_conv.c  -o ${OBJECTDIR}/library/a_d/e_ad_conv.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/a_d/e_ad_conv.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/a_d/e_ad_conv.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/matlab/matlab.o: library/matlab/matlab.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/matlab" 
	@${RM} ${OBJECTDIR}/library/matlab/matlab.o.d 
	@${RM} ${OBJECTDIR}/library/matlab/matlab.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/matlab/matlab.c  -o ${OBJECTDIR}/library/matlab/matlab.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/matlab/matlab.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/matlab/matlab.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/RS_motors.o: RS_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_motors.o.d 
	@${RM} ${OBJECTDIR}/RS_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RS_motors.c  -o ${OBJECTDIR}/RS_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/RS_motors.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/RS_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/RS_accelerometer.o: RS_accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_accelerometer.o.d 
	@${RM} ${OBJECTDIR}/RS_accelerometer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  RS_accelerometer.c  -o ${OBJECTDIR}/RS_accelerometer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/RS_accelerometer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/RS_accelerometer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/motor_led/e_init_port.o: library/motor_led/e_init_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/motor_led" 
	@${RM} ${OBJECTDIR}/library/motor_led/e_init_port.o.d 
	@${RM} ${OBJECTDIR}/library/motor_led/e_init_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/motor_led/e_init_port.c  -o ${OBJECTDIR}/library/motor_led/e_init_port.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/motor_led/e_init_port.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/motor_led/e_init_port.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/motor_led/e_motors.o: library/motor_led/e_motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/motor_led" 
	@${RM} ${OBJECTDIR}/library/motor_led/e_motors.o.d 
	@${RM} ${OBJECTDIR}/library/motor_led/e_motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/motor_led/e_motors.c  -o ${OBJECTDIR}/library/motor_led/e_motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/motor_led/e_motors.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/motor_led/e_motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/a_d/e_accelerometer.o: library/a_d/e_accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/a_d" 
	@${RM} ${OBJECTDIR}/library/a_d/e_accelerometer.o.d 
	@${RM} ${OBJECTDIR}/library/a_d/e_accelerometer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/a_d/e_accelerometer.c  -o ${OBJECTDIR}/library/a_d/e_accelerometer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/a_d/e_accelerometer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/a_d/e_accelerometer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/a_d/e_ad_conv.o: library/a_d/e_ad_conv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/a_d" 
	@${RM} ${OBJECTDIR}/library/a_d/e_ad_conv.o.d 
	@${RM} ${OBJECTDIR}/library/a_d/e_ad_conv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/a_d/e_ad_conv.c  -o ${OBJECTDIR}/library/a_d/e_ad_conv.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/a_d/e_ad_conv.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/a_d/e_ad_conv.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/library/matlab/matlab.o: library/matlab/matlab.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/matlab" 
	@${RM} ${OBJECTDIR}/library/matlab/matlab.o.d 
	@${RM} ${OBJECTDIR}/library/matlab/matlab.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  library/matlab/matlab.c  -o ${OBJECTDIR}/library/matlab/matlab.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/library/matlab/matlab.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"library" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/library/matlab/matlab.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/RS_acc_mean.o: RS_acc_mean.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_acc_mean.o.d 
	@${RM} ${OBJECTDIR}/RS_acc_mean.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  RS_acc_mean.s  -o ${OBJECTDIR}/RS_acc_mean.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/RS_acc_mean.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/RS_acc_mean.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_init_uart1.o: library/uart/e_init_uart1.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_init_uart1.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_init_uart1.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_init_uart1.s  -o ${OBJECTDIR}/library/uart/e_init_uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_init_uart1.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_init_uart1.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_uart1_rx_char.o: library/uart/e_uart1_rx_char.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_rx_char.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_uart1_rx_char.s  -o ${OBJECTDIR}/library/uart/e_uart1_rx_char.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_uart1_tx_char.o: library/uart/e_uart1_tx_char.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_tx_char.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_uart1_tx_char.s  -o ${OBJECTDIR}/library/uart/e_uart1_tx_char.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/RS_acc_mean.o: RS_acc_mean.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RS_acc_mean.o.d 
	@${RM} ${OBJECTDIR}/RS_acc_mean.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  RS_acc_mean.s  -o ${OBJECTDIR}/RS_acc_mean.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/RS_acc_mean.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/RS_acc_mean.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_init_uart1.o: library/uart/e_init_uart1.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_init_uart1.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_init_uart1.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_init_uart1.s  -o ${OBJECTDIR}/library/uart/e_init_uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_init_uart1.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_init_uart1.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_uart1_rx_char.o: library/uart/e_uart1_rx_char.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_rx_char.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_uart1_rx_char.s  -o ${OBJECTDIR}/library/uart/e_uart1_rx_char.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_uart1_rx_char.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/library/uart/e_uart1_tx_char.o: library/uart/e_uart1_tx_char.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/library/uart" 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d 
	@${RM} ${OBJECTDIR}/library/uart/e_uart1_tx_char.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  library/uart/e_uart1_tx_char.s  -o ${OBJECTDIR}/library/uart/e_uart1_tx_char.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I"library" -Wa,-MD,"${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/library/uart/e_uart1_tx_char.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/RollingStone.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
