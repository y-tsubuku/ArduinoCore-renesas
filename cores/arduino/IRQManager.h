#ifndef ARDUINO_IRQ_MANAGER_H
#define ARDUINO_IRQ_MANAGER_H

#include "bsp_api.h"
#include "r_uart_api.h"

typedef enum {
    IRQ_RTC,
    IRQ_USB,
    IRQ_AGT,
    IRQ_UART_SCI2,
    IRQ_I2C_MASTER,
    IRQ_I2C_SLAVE
} Peripheral_t;

typedef struct usb {
    uint32_t num_of_irqs_required;
    uint32_t address_of_handler;
} USBIrqCfg_t;


class IRQManager {
    public:
    bool addPeripheral(Peripheral_t p, void *cfg);
    static IRQManager& getInstance();
    IRQManager(IRQManager const&)               = delete;
    void operator=(IRQManager const&)           = delete;
    ~IRQManager();

    private:
    int last_interrupt_index;
    IRQManager();

};





#endif