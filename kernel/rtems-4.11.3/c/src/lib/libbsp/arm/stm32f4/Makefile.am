ACLOCAL_AMFLAGS = -I ../../../../aclocal

include $(top_srcdir)/../../../../automake/compile.am

include_bspdir = $(includedir)/bsp

###############################################################################
#                  Data                                                       #
###############################################################################

dist_project_lib_DATA = bsp_specs

noinst_LIBRARIES = libbspstart.a

libbspstart_a_SOURCES = ../shared/start/start.S

project_lib_DATA =
project_lib_DATA += start.$(OBJEXT)
project_lib_DATA += startup/linkcmds

EXTRA_DIST = startup/linkcmds.stm32f4
EXTRA_DIST += startup/linkcmds.stm32f105rc

###############################################################################
#                  Header                                                     #
###############################################################################

include_HEADERS =
include_HEADERS += ../../shared/include/tm27.h
include_HEADERS += include/bsp.h

nodist_include_HEADERS =
nodist_include_HEADERS += ../../shared/include/coverhd.h
nodist_include_HEADERS += include/bspopts.h

nodist_include_bsp_HEADERS =
nodist_include_bsp_HEADERS += ../../shared/include/bootcard.h

include_bsp_HEADERS =
include_bsp_HEADERS += ../../shared/include/utility.h
include_bsp_HEADERS += ../../shared/include/irq-generic.h
include_bsp_HEADERS += ../../shared/include/irq-info.h
include_bsp_HEADERS += ../../shared/include/stackalloc.h
include_bsp_HEADERS += ../shared/include/start.h
include_bsp_HEADERS += ../shared/armv7m/include/armv7m-irq.h
include_bsp_HEADERS += include/irq.h
include_bsp_HEADERS += include/usart.h
include_bsp_HEADERS += include/stm32f4.h
include_bsp_HEADERS += include/stm32f10xxx_gpio.h
include_bsp_HEADERS += include/stm32f10xxx_rcc.h
include_bsp_HEADERS += include/stm32f10xxx_exti.h
include_bsp_HEADERS += include/stm32f4xxxx_adc.h
include_bsp_HEADERS += include/stm32f4xxxx_exti.h
include_bsp_HEADERS += include/stm32f4xxxx_gpio.h
include_bsp_HEADERS += include/stm32f4xxxx_rcc.h
include_bsp_HEADERS += include/stm32f4xxxx_pwr.h
include_bsp_HEADERS += include/stm32f4xxxx_syscfg.h
include_bsp_HEADERS += include/stm32f4xxxx_tim.h
include_bsp_HEADERS += include/stm32f4xxxx_flash.h
include_bsp_HEADERS += include/stm32f4xxxx_otgfs.h
include_bsp_HEADERS += include/stm32_i2c.h
include_bsp_HEADERS += include/i2c.h
include_bsp_HEADERS += include/stm32_usart.h
include_bsp_HEADERS += include/io.h
include_bsp_HEADERS += include/rcc.h
include_bsp_HEADERS += include/stm32f7-hal/stm32f7xx_hal.h
include_bsp_HEADERS += include/stm32f7-hal/stm32f7xx_hal_gpio.h
include_bsp_HEADERS += include/stm32f7-hal/stm32f7xx_hal_gpio_ex.h
include_bsp_HEADERS += include/stm32f7-hal/stm32f7xx_hal_def.h
include_bsp_HEADERS += include/stm32f7-hal/stm32f7xx_hal_conf.h
include_bsp_HEADERS += include/cmsis/core_cm7.h
include_bsp_HEADERS += include/cmsis/core_cmFunc.h
include_bsp_HEADERS += include/cmsis/core_cmInstr.h
include_bsp_HEADERS += include/cmsis/core_cmSimd.h
include_bsp_HEADERS += include/cmsis/stm32f767xx.h
include_bsp_HEADERS += include/cmsis/stm32f7xx.h
include_bsp_HEADERS += include/cmsis/system_stm32f7xx.h

###############################################################################
#                  LibBSP                                                     #
###############################################################################

noinst_LIBRARIES += libbsp.a

libbsp_a_SOURCES =
libbsp_a_CPPFLAGS =
libbsp_a_LIBADD =

# Shared
libbsp_a_SOURCES += ../../shared/bootcard.c
libbsp_a_SOURCES += ../../shared/bspclean.c
libbsp_a_SOURCES += ../../shared/bspgetworkarea.c
libbsp_a_SOURCES += ../../shared/bsplibc.c
libbsp_a_SOURCES += ../../shared/bsppost.c
libbsp_a_SOURCES += ../../shared/bsppredriverhook.c
libbsp_a_SOURCES += ../../shared/bsppretaskinghook.c
libbsp_a_SOURCES += ../../shared/cpucounterread.c
libbsp_a_SOURCES += ../../shared/cpucounterdiff.c
libbsp_a_SOURCES += ../../shared/gnatinstallhandler.c
libbsp_a_SOURCES += ../../shared/sbrk.c
libbsp_a_SOURCES += ../../shared/src/stackalloc.c

# Startup
libbsp_a_SOURCES += ../shared/startup/bsp-start-memcpy.S
libbsp_a_SOURCES += startup/bspstart.c
libbsp_a_SOURCES += startup/bspstarthook.c
libbsp_a_SOURCES += startup/bspreset.c

# IRQ
libbsp_a_SOURCES += ../../shared/src/irq-default-handler.c
libbsp_a_SOURCES += ../../shared/src/irq-generic.c
libbsp_a_SOURCES += ../../shared/src/irq-info.c
libbsp_a_SOURCES += ../../shared/src/irq-legacy.c
libbsp_a_SOURCES += ../../shared/src/irq-server.c
libbsp_a_SOURCES += ../../shared/src/irq-shell.c
libbsp_a_SOURCES += ../shared/armv7m/irq/armv7m-irq.c
libbsp_a_SOURCES += ../shared/armv7m/irq/armv7m-irq-dispatch.c

# Console
libbsp_a_SOURCES += ../../shared/console.c
libbsp_a_SOURCES += ../../shared/console_control.c
libbsp_a_SOURCES += ../../shared/console_read.c
libbsp_a_SOURCES += ../../shared/console_select.c
libbsp_a_SOURCES += ../../shared/console_write.c
libbsp_a_SOURCES += console/console-config.c
libbsp_a_SOURCES += console/usart.c

# Clock
libbsp_a_SOURCES += ../../shared/clockdrv_shell.h
libbsp_a_SOURCES += ../shared/armv7m/clock/armv7m-clock-config.c

# Timer
libbsp_a_SOURCES += ../../shared/timerstub.c

# Cache
libbsp_a_SOURCES += ../../../libcpu/shared/src/cache_manager.c
libbsp_a_SOURCES += ../../../libcpu/arm/shared/cache/cache_.h
libbsp_a_CPPFLAGS += -I$(srcdir)/../../../libcpu/arm/shared/include

# Hal
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_cortex.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_gpio.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_pwr_ex.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_rcc.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_rcc_ex.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_dma.c
libbsp_a_SOURCES += stm32f7-hal/stm32f7xx_hal_usart.c
libbsp_a_CPPFLAGS += -I$(srcdir)/../../../libbsp/arm/stm32f4/include/stm32f7-hal
libbsp_a_CPPFLAGS += -I$(srcdir)/../../../libbsp/arm/stm32f4/include/stm32f7-hal/Legacy
libbsp_a_CPPFLAGS += -I$(srcdir)/../../../libbsp/arm/stm32f4/include/cmsis

###############################################################################
#                  Special Rules                                              #
###############################################################################

DISTCLEANFILES = include/bspopts.h

include $(srcdir)/preinstall.am
include $(top_srcdir)/../../../../automake/local.am
