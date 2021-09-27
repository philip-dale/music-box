#ifndef FAST_PIN_H
#define FAST_PIN_H

// Each port has 3 registers, readValue (PINX) input/output mode (DDRX) and write value (PORTX)
// if we get the pointer to the PINX register we can access the DDRX register by incremetning pointer by 1 and PORTX register by incrementing by 2
// see ATMega2560 datasheet page 96

#define FAST_SET_PIN_INFO(pinInfo, pinNum)   (pinInfo.mask = digitalPinToBitMask(pinNum), pinInfo.pin = portInputRegister(digitalPinToPort(pinNum)), pinInfo.ddr = pinInfo.pin+1, pinInfo.port = pinInfo.pin+2)
#define FAST_READ(pinInfo)            (((*(pinInfo.pin)) & (pinInfo.mask)) ? 1 : 0)
#define FAST_MODE_INPUT(pinInfo)      ((*(pinInfo.ddr)) &= ~(pinInfo.mask), FAST_WRITE_LOW(pinInfo))
#define FAST_MODE_OUTPUT(pinInfo)     ((*(pinInfo.ddr)) |= (pinInfo.mask))
#define FAST_WRITE_LOW(pinInfo)       ((*(pinInfo.port)) &= ~(pinInfo.mask))
#define FAST_WRITE_HIGH(pinInfo)      ((*(pinInfo.port)) |= (pinInfo.mask))

typedef struct {
    volatile uint8_t * pin;
    volatile uint8_t * ddr;
    volatile uint8_t * port;
    uint8_t mask;
} PinInfo;

#endif