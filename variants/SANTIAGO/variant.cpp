#include "Arduino.h"

const AnalogPinDescription g_AAnalogPinDescription[] = {
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_7 },    // A0    ADC0_AN9
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_0 },    // A1    ADC0_AN0
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_1 },    // A2    ADC0_AN1
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_2 },    // A3    ADC3_AN2
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_12},    // A4    ADC1_AN21
  {&g_adc0_ctrl, &g_adc0_cfg, ADC_CHANNEL_13}     // A5    ADC2_AN22
};

const AnalogOutPinDescription g_AAnalogOutPinDescription[] = {
  {&g_dac0_ctrl, &g_dac0_cfg }                    // A0
};

pwmTable_t pwmTable[] = {
  {&g_timer0_ctrl, &g_timer0_cfg, GPT_IO_PIN_GTIOCA, NULL}, // D9
  {&g_timer0_ctrl, &g_timer0_cfg, GPT_IO_PIN_GTIOCB, NULL}, // D10
  {&g_timer1_ctrl, &g_timer1_cfg, GPT_IO_PIN_GTIOCA, NULL}, // D11
  {&g_timer1_ctrl, &g_timer1_cfg, GPT_IO_PIN_GTIOCB, NULL}, // D3
  {&g_timer2_ctrl, &g_timer2_cfg, GPT_IO_PIN_GTIOCA, NULL}, // D5
  {nullptr,        nullptr,       GPT_IO_PIN_GTIOCB, NULL},
  {nullptr,        nullptr,       GPT_IO_PIN_GTIOCA, NULL},
  {&g_timer3_ctrl, &g_timer3_cfg, GPT_IO_PIN_GTIOCB, NULL}, // D6
};

const irqTable_t irqTable[] = {
    {&g_external_irq0_ctrl, &g_external_irq0_cfg},    // ext_int0
    {&g_external_irq1_ctrl, &g_external_irq1_cfg},    // ext_int1
};

uart_instance_t UartTable[] = {
  {&g_uart1_ctrl      , &g_uart1_cfg      , &g_uart_on_sci},          //SCI0
  {&g_uart2_ctrl      , &g_uart2_cfg      , &g_uart_on_sci},          //SCI1
  {&g_uart0_ctrl      , &g_uart0_cfg      , &g_uart_on_sci},          //SCI2
  {nullptr            , nullptr           , nullptr       },          //SCI3
  {nullptr            , nullptr           , nullptr       },          //SCI4
  {nullptr            , nullptr           , nullptr       },          //SCI5
  {nullptr            , nullptr           , nullptr       },          //SCI6
  {nullptr            , nullptr           , nullptr       },          //SCI7
  {nullptr            , nullptr           , nullptr       },          //SCI8
  {nullptr            , nullptr           , nullptr       },          //SCI9
};

void __attribute__((weak)) i2c_callback (i2c_master_callback_args_t * p_args) {}
void __attribute__((weak)) sci_i2c_callback (i2c_master_callback_args_t * p_args) {}

i2c_master_instance_t I2CMasterTable[] = {
  {nullptr            , nullptr           , nullptr             },    //IIC0
  {&g_i2c_master0_ctrl, &g_i2c_master0_cfg, &g_i2c_master_on_iic},    //IIC1
  {&g_i2c1_ctrl       , &g_i2c1_cfg       , &g_i2c_master_on_sci},    //SCI0
  {&g_i2c2_ctrl       , &g_i2c2_cfg       , &g_i2c_master_on_sci},    //SCI1
  {&g_i2c3_ctrl       , &g_i2c3_cfg       , &g_i2c_master_on_sci},    //SCI2
  {nullptr            , nullptr           , nullptr             },    //SCI3
  {nullptr            , nullptr           , nullptr             },    //SCI4
  {nullptr            , nullptr           , nullptr             },    //SCI5
  {nullptr            , nullptr           , nullptr             },    //SCI6
  {nullptr            , nullptr           , nullptr             },    //SCI7
  {nullptr            , nullptr           , nullptr             },    //SCI8
  {nullptr            , nullptr           , nullptr             },    //SCI9
};

void __attribute__((weak)) spi_callback(spi_callback_args_t *p_args) {}
void __attribute__((weak)) sci_spi_callback(spi_callback_args_t *p_args) {}

spi_instance_t SpiTable[] = {
  {nullptr            , nullptr           , nullptr             },    //SPI0
  {&g_spi0_ctrl       , &g_spi0_cfg       , &g_spi_on_spi       },    //SPI1
  {&g_spi1_ctrl       , &g_spi1_cfg       , &g_spi_on_sci       },    //SCI0
  {&g_spi2_ctrl       , &g_spi2_cfg       , &g_spi_on_sci       },    //SCI1
  {&g_spi3_ctrl       , &g_spi3_cfg       , &g_spi_on_sci       },    //SCI2
  {nullptr            , nullptr           , nullptr             },    //SCI3
  {nullptr            , nullptr           , nullptr             },    //SCI4
  {nullptr            , nullptr           , nullptr             },    //SCI5
  {nullptr            , nullptr           , nullptr             },    //SCI6
  {nullptr            , nullptr           , nullptr             },    //SCI7
  {nullptr            , nullptr           , nullptr             },    //SCI8
  {nullptr            , nullptr           , nullptr             },    //SCI9
};

sciTable_t SciTable[] {
/*
    +-----------------+------------------- +-------------------+
    |      UART       |        I2C         |        SPI        |
    +-----------------+------------------- +-------------------+
 */
  { &UartTable[0]     , &I2CMasterTable[2] , &SpiTable[2]      },
  { &UartTable[1]     , &I2CMasterTable[3] , &SpiTable[3]      },
  { &UartTable[2]     , &I2CMasterTable[4] , &SpiTable[4]      },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
  { nullptr           , nullptr            , nullptr           },
};

const PinDescription g_APinDescription[] = {
/*
    +------------------------+---------------+---------------------+--------------------------+
    |       PIN Name         |      PWM      |    EXT INTERRUPT    |          Notes           |
    |                        |               |                     |  Board Pin | Peripheral  |
    +------------------------+---------------+---------------------+--------------------------+
 */
    // Digital
    { BSP_IO_PORT_03_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D0     |   UART RX   */
    { BSP_IO_PORT_01_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D1     |   UART TX   */
    { BSP_IO_PORT_02_PIN_06,    NOT_ON_PWM,     EXTERNAL_INT_0   }, /*   D2     |             */
    { BSP_IO_PORT_01_PIN_04,    PWM_TIM1_CHB,   EXTERNAL_INT_1   }, /*   D3     |             */
    { BSP_IO_PORT_04_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D4     |             */
    { BSP_IO_PORT_01_PIN_03,    PWM_TIM2_CHA,   NOT_AN_INTERRUPT }, /*   D5     |             */
    { BSP_IO_PORT_01_PIN_12,    PWM_TIM3_CHB,   NOT_AN_INTERRUPT }, /*   D6     |             */
    { BSP_IO_PORT_04_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D7     |             */
    { BSP_IO_PORT_03_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D8     |             */
    { BSP_IO_PORT_03_PIN_00,    PWM_TIM0_CHA,   NOT_AN_INTERRUPT }, /*   D9     |             */
    { BSP_IO_PORT_01_PIN_08,    PWM_TIM0_CHB,   NOT_AN_INTERRUPT }, /*   D10    |     CS      */
    { BSP_IO_PORT_01_PIN_09,    PWM_TIM1_CHA,   NOT_AN_INTERRUPT }, /*   D11    |     MOSI    */
    { BSP_IO_PORT_01_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D12    |     MISO    */
    { BSP_IO_PORT_01_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D13    |     SCK     */
    { BSP_IO_PORT_01_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D14    |     SDA     */
    { BSP_IO_PORT_01_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D15    |     SCL     */

    // Analog
    { BSP_IO_PORT_00_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A0     |   AIN/AOUT  */
    { BSP_IO_PORT_00_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A1     |     AIN     */
    { BSP_IO_PORT_00_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A2     |     AIN     */
    { BSP_IO_PORT_00_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A3     |     AIN     */
    { BSP_IO_PORT_01_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A4     |     AIN     */
    { BSP_IO_PORT_01_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   A5     |     AIN     */

    // RGB LED
    { BSP_IO_PORT_00_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D22    |     LEDR    */
    { BSP_IO_PORT_00_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT }, /*   D23    |     LEDB    */

    { BSP_IO_PORT_01_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_01_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_01_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_01_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_02_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_02_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_03_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_03_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_04_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_04_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_05_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_05_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_06_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_06_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_07_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_07_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_08_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_08_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },

    { BSP_IO_PORT_09_PIN_00,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_01,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_02,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_03,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_04,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_05,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_06,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_07,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_08,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_09,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_10,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_11,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_12,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_13,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_14,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
    { BSP_IO_PORT_09_PIN_15,    NOT_ON_PWM,     NOT_AN_INTERRUPT },
};

extern "C" {
  unsigned int PINCOUNT_fn() {
    return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
  }
  unsigned int I2C_COUNT_fn() {
    return (sizeof(I2CMasterTable) / sizeof(I2CMasterTable[1]));
  }
  unsigned int SPI_COUNT_fn() {
    return (sizeof(SpiTable) / sizeof(SpiTable[1]));
  }
  unsigned int UART_COUNT_fn() {
    return (sizeof(UartTable) / sizeof(UartTable[0]));
  }
  unsigned int SCI_COUNT_fn() {
    return (sizeof(SciTable) / sizeof(SciTable[0]));
  }
}

void initVariant() {

}