/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Bryan Newbold.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file fsmc.c
 * @brief Flexible static memory controller support.
 */

#include "fsmc.h"
#include <gpio.h>

#ifdef STM32_HIGH_DENSITY

/**
 * Configure FSMC GPIOs for use with SRAM.
 */
void fsmc_sram_init_gpios(void) {
    /* Data lines... */
    gpio_set_modef(GPIOD,  0, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD,  1, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD,  8, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD,  9, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD, 10, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD, 14, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD, 15, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE,  7, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE,  8, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE,  9, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 10, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 11, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 12, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 13, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 14, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOE, 15, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);

    /* Address lines... */
    gpio_set_modef(GPIOD, 11, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD, 12, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOD, 13, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  0, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  1, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  2, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  3, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  4, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF,  5, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF, 12, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF, 13, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF, 14, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOF, 15, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  0, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  1, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  2, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  3, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  4, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);
    gpio_set_modef(GPIOG,  5, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);

    /* And control lines... */
    gpio_set_modef(GPIOD,  4, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NOE
    gpio_set_modef(GPIOD,  5, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NWE

    gpio_set_modef(GPIOD,  7, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NE1
    gpio_set_modef(GPIOG,  9, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NE2
    gpio_set_modef(GPIOG, 10, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NE3
    gpio_set_modef(GPIOG, 12, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NE4

    gpio_set_modef(GPIOE,  0, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NBL0
    gpio_set_modef(GPIOE,  1, GPIO_MODE_AF , GPIO_OTYPE_PP | GPIO_OSPEED_50MHZ);   // NBL1
}

#endif  /* STM32_HIGH_DENSITY */
