/*
 * microphone.h
 *
 * Created: 4/5/2017 20:53:18
 *  Author: Nathan
 */ 


#ifndef MICROPHONE_H_
#define MICROPHONE_H_
#include <asf.h>
#include "conf_board.h"
#include "conf_clock.h"
#include "wifi.h"
#include "math.h"

#define NUMBER_OF_SAMPLES 1000
// uint8_t input_buffer[BUFFER_SIZE];

uint16_t *generate_spoof(uint32_t tone_frequency);
void send_data_ws(uint16_t *samples_data);
void do_it();
void configure_i2s();

/** The SSC interrupt IRQ priority. */
#define SSC_IRQ_PRIO           4

#define OVER_SAMPLE_RATE			64
#define SAMPLE_RATE					32000
#define SSC_BIT_RATE				(OVER_SAMPLE_RATE * SAMPLE_RATE)

#endif /* MICROPHONE_H_ */