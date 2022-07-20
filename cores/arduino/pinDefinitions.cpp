#include "Arduino.h"
#include "bsp_api.h"
#include "hal_data.h"

#define IOPORT_PRV_PERIPHERAL_FUNCTION    (1U << 16)
#define IOPORT_PRV_PORT_OFFSET            (8U)
#define BSP_IO_PRV_8BIT_MASK              (0xFF)

void pinPeripheral(bsp_io_port_pin_t bspPin, uint32_t bspPeripheral) {
    R_IOPORT_PinCfg(&g_ioport_ctrl, bspPin, bspPeripheral);
}


void pinPeripheral(uint32_t pinNumber, uint32_t bspPeripheral) {
  pinPeripheral(digitalPinToBspPin(pinNumber), bspPeripheral);
}