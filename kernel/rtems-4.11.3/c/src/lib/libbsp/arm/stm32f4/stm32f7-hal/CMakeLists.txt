INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../include/arm)
INCLUDE_DIRECTORIES(../../include/cmsis)
INCLUDE_DIRECTORIES(../../include/cortexm)
INCLUDE_DIRECTORIES(../../include/diag)
INCLUDE_DIRECTORIES(../../include/stm32f7-hal)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

set(_SRC 
	stm32f7xx_hal.c 
	stm32f7xx_hal_cortex.c 
	#stm32f7xx_hal_crc_ex.c 
	stm32f7xx_hal_gpio.c 
	#stm32f7xx_hal_iwdg.c 
	stm32f7xx_hal_mdios.c 
	#stm32f7xx_hal_pwr.c 
	stm32f7xx_hal_pwr_ex.c 
	stm32f7xx_hal_rcc.c 
	stm32f7xx_hal_rcc_ex.c 
	stm32f7xx_hal_sdram.c 
	stm32f7xx_ll_fmc.c 
	stm32f7xx_hal_dma.c 
)

add_library(hal STATIC ${_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

