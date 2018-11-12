/*********************************************************************************************************************
* DAVE APP Name : I2C_SLAVE       APP Version: 4.0.14
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-08-27:
 *     - Initial version for DAVEv4.
 *
 * 2016-07-08:
 *     - Fixed incorrect case for an included header.<br>
 *
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "i2c_slave.h"

/***********************************************************************************************************************
 * EXTERN DECLARATIONS
 ***********************************************************************************************************************/

extern void I2C_SLAVE_lProtocolHandler(const I2C_SLAVE_t * const handle);


I2C_SLAVE_STATUS_t dhI2C_SLAVE_init(void);
void dhI2C_SLAVE_dma_tx_handler(XMC_DMA_CH_EVENT_t event);
void dhI2C_SLAVE_dma_rx_handler(XMC_DMA_CH_EVENT_t event);
XMC_DMA_CH_CONFIG_t dhI2C_SLAVE_dma_ch_tx_config =
{
  .src_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_8,
  .dst_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_8,
  .src_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT,
  .dst_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_NO_CHANGE,
  .src_burst_length = XMC_DMA_CH_BURST_LENGTH_8,
  .dst_burst_length = XMC_DMA_CH_BURST_LENGTH_1,
  .transfer_flow = XMC_DMA_CH_TRANSFER_FLOW_M2P_DMA,
  .transfer_type = XMC_DMA_CH_TRANSFER_TYPE_SINGLE_BLOCK,
  .dst_handshaking = XMC_DMA_CH_DST_HANDSHAKING_HARDWARE,
  .dst_peripheral_request = DMA_PERIPHERAL_REQUEST(5U, 11U), /*DMA0_PERIPHERAL_REQUEST_USIC1_SR0_5*/
  .enable_interrupt = true
};

const I2C_SLAVE_DMA_CONFIG_t dhI2C_SLAVE_dma_tx_config =
{
  .dma_ch_config = &dhI2C_SLAVE_dma_ch_tx_config,
  .dma_channel   = 5U
};
XMC_DMA_CH_CONFIG_t dhI2C_SLAVE_dma_ch_rx_config =
{
  .src_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_8,
  .dst_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_8,
  .src_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_NO_CHANGE,
  .dst_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT,
  .src_burst_length = XMC_DMA_CH_BURST_LENGTH_1,
  .dst_burst_length = XMC_DMA_CH_BURST_LENGTH_8,
  .transfer_flow = XMC_DMA_CH_TRANSFER_FLOW_P2M_DMA,
  .transfer_type = XMC_DMA_CH_TRANSFER_TYPE_SINGLE_BLOCK,
  .src_handshaking = XMC_DMA_CH_SRC_HANDSHAKING_HARDWARE,
  .src_peripheral_request = DMA_PERIPHERAL_REQUEST(2U, 12U), /*DMA0_PERIPHERAL_REQUEST_USIC1_SR1_2*/
  .enable_interrupt = true
};
const I2C_SLAVE_DMA_CONFIG_t dhI2C_SLAVE_dma_rx_config =
{
  .dma_ch_config = &dhI2C_SLAVE_dma_ch_rx_config,
  .dma_channel   = 4U
};
const XMC_I2C_CH_CONFIG_t dhI2C_SLAVE_channel_config =
{
  .baudrate = 100000U, /*Used for setting speed mode and oversampling*/
  .address  = 10U
};

const I2C_SLAVE_CONFIG_t dhI2C_SLAVE_config =
{
  .channel_config = &dhI2C_SLAVE_channel_config,
  .global_dma = &GLOBAL_DMA_0,
  .transmit_dma_config = &dhI2C_SLAVE_dma_tx_config,
  .receive_dma_config = &dhI2C_SLAVE_dma_rx_config,
  .fptr_i2c_slave_config = dhI2C_SLAVE_init,
  .tx_cbhandler = NULL,
  .rx_cbhandler = CB_I2C_SlaveReceive,
  .read_request_cbhandler = CB_I2C_SlaveReadRequest,
  .error_cbhandler = NULL,
  .transmit_mode = I2C_SLAVE_TRANSFER_MODE_DMA,
  .receive_mode = I2C_SLAVE_TRANSFER_MODE_DMA,
  .txFIFO_size    = XMC_USIC_CH_FIFO_DISABLED, 
  .rxFIFO_size    = XMC_USIC_CH_FIFO_DISABLED,
  .tx_sr = 0U
};
I2C_SLAVE_RUNTIME_t dhI2C_SLAVE_runtime =
{
  .tx_busy = false,
  .rx_busy = false,
};

I2C_SLAVE_t dhI2C_SLAVE =
{
  .channel = XMC_I2C1_CH0,
  .config = &dhI2C_SLAVE_config,
  .runtime = &dhI2C_SLAVE_runtime
};

I2C_SLAVE_STATUS_t dhI2C_SLAVE_init(void)
{
  I2C_SLAVE_STATUS_t status = I2C_SLAVE_STATUS_SUCCESS;
 uint32_t protocol_events = ((uint32_t)XMC_I2C_CH_EVENT_SLAVE_READ_REQUEST);
  const XMC_GPIO_CONFIG_t dhI2C_SLAVE_sda_pin_config   =
  { 
    .mode = XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT2,
    .output_level   = XMC_GPIO_OUTPUT_LEVEL_HIGH,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE
  }; 
  const XMC_GPIO_CONFIG_t dhI2C_SLAVE_scl_pin_config   =
  { 
    .mode = XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN_ALT2,
    .output_level  = XMC_GPIO_OUTPUT_LEVEL_HIGH,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE
  }; 
  status = (I2C_SLAVE_STATUS_t)GLOBAL_DMA_Init(&GLOBAL_DMA_0);
  XMC_DMA_CH_Init(XMC_DMA0, 5U, &dhI2C_SLAVE_dma_ch_tx_config);
  XMC_DMA_CH_EnableEvent(XMC_DMA0,  5U, XMC_DMA_CH_EVENT_TRANSFER_COMPLETE);

  XMC_DMA_CH_Init(XMC_DMA0, 4U, &dhI2C_SLAVE_dma_ch_rx_config);
  XMC_DMA_CH_EnableEvent(XMC_DMA0,  4U, XMC_DMA_CH_EVENT_TRANSFER_COMPLETE);


  XMC_I2C_CH_Init(XMC_I2C1_CH0, &dhI2C_SLAVE_channel_config);

  XMC_I2C_CH_SetInputSource(XMC_I2C1_CH0, XMC_I2C_CH_INPUT_SDA, 1U);
  XMC_I2C_CH_SetInputSource(XMC_I2C1_CH0, XMC_I2C_CH_INPUT_SCL, 0U);
  XMC_USIC_CH_SetInterruptNodePointer(XMC_I2C1_CH0,
                    XMC_USIC_CH_INTERRUPT_NODE_POINTER_TRANSMIT_BUFFER,
                     ((uint32_t)0));
  XMC_USIC_CH_SetInterruptNodePointer(XMC_I2C1_CH0,
                    XMC_USIC_CH_INTERRUPT_NODE_POINTER_RECEIVE,
                     1U);
  XMC_USIC_CH_SetInterruptNodePointer(XMC_I2C1_CH0,
                    XMC_USIC_CH_INTERRUPT_NODE_POINTER_ALTERNATE_RECEIVE,
                     1U);
  XMC_USIC_CH_SetInterruptNodePointer(XMC_I2C1_CH0,
                    XMC_USIC_CH_INTERRUPT_NODE_POINTER_PROTOCOL,
                     5U);
  XMC_I2C_CH_Start(XMC_I2C1_CH0);

  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, (uint8_t)11, &dhI2C_SLAVE_scl_pin_config);
  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, (uint8_t)5, &dhI2C_SLAVE_sda_pin_config);
  NVIC_SetPriority((IRQn_Type)95, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),63U,0U));
  NVIC_EnableIRQ((IRQn_Type)95);
  XMC_I2C_CH_EnableEvent(XMC_I2C1_CH0, protocol_events);
  /*Register transfer complete event handler*/
  XMC_DMA_CH_SetEventHandler(XMC_DMA0, 4U, dhI2C_SLAVE_dma_rx_handler);
  /* Register transfer complete event handler */
  XMC_DMA_CH_SetEventHandler(XMC_DMA0, 5U, dhI2C_SLAVE_dma_tx_handler);
  return status;
}
void dhI2C_SLAVE_ERR_HANDLER()
{
  I2C_SLAVE_lProtocolHandler(&dhI2C_SLAVE);
}

void dhI2C_SLAVE_dma_tx_handler(XMC_DMA_CH_EVENT_t event)
{
  if(event == XMC_DMA_CH_EVENT_TRANSFER_COMPLETE)
  {
    dhI2C_SLAVE.runtime->tx_busy = false;
    XMC_I2C_CH_DisableEvent(dhI2C_SLAVE.channel, (uint32_t)XMC_I2C_CH_EVENT_TRANSMIT_BUFFER);
  }
}
void dhI2C_SLAVE_dma_rx_handler(XMC_DMA_CH_EVENT_t event)
{
  if(event == XMC_DMA_CH_EVENT_TRANSFER_COMPLETE)
  {
    dhI2C_SLAVE.runtime->rx_busy = false;
    XMC_I2C_CH_DisableEvent(dhI2C_SLAVE.channel, ((uint32_t)XMC_I2C_CH_EVENT_STANDARD_RECEIVE | (uint32_t)XMC_I2C_CH_EVENT_ALTERNATIVE_RECEIVE));
    CB_I2C_SlaveReceive();
  }
}
