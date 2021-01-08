/**
 * @file omapl138_eth_driver.h
 * @brief OMAP-L138 Ethernet MAC driver
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2021 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.0.2
 **/

#ifndef _OMAPL138_ETH_DRIVER_H
#define _OMAPL138_ETH_DRIVER_H

//Dependencies
#include "core/nic.h"

//Number of TX buffers
#ifndef OMAPL138_ETH_TX_BUFFER_COUNT
   #define OMAPL138_ETH_TX_BUFFER_COUNT 8
#elif (OMAPL138_ETH_TX_BUFFER_COUNT < 1)
   #error OMAPL138_ETH_TX_BUFFER_COUNT parameter is not valid
#endif

//TX buffer size
#ifndef OMAPL138_ETH_TX_BUFFER_SIZE
   #define OMAPL138_ETH_TX_BUFFER_SIZE 1536
#elif (OMAPL138_ETH_TX_BUFFER_SIZE != 1536)
   #error OMAPL138_ETH_TX_BUFFER_SIZE parameter is not valid
#endif

//Number of RX buffers
#ifndef OMAPL138_ETH_RX_BUFFER_COUNT
   #define OMAPL138_ETH_RX_BUFFER_COUNT 8
#elif (OMAPL138_ETH_RX_BUFFER_COUNT < 1)
   #error OMAPL138_ETH_RX_BUFFER_COUNT parameter is not valid
#endif

//RX buffer size
#ifndef OMAPL138_ETH_RX_BUFFER_SIZE
   #define OMAPL138_ETH_RX_BUFFER_SIZE 1536
#elif (OMAPL138_ETH_RX_BUFFER_SIZE != 1536)
   #error OMAPL138_ETH_RX_BUFFER_SIZE parameter is not valid
#endif

//Channel number for the TX interrupt
#ifndef OMAPL138_ETH_TX_IRQ_CHANNEL
   #define OMAPL138_ETH_TX_IRQ_CHANNEL 3
#elif (OMAPL138_ETH_TX_IRQ_CHANNEL < 0 || OMAPL138_ETH_TX_IRQ_CHANNEL > 31)
   #error OMAPL138_ETH_TX_IRQ_CHANNEL parameter is not valid
#endif

//Channel number for the RX interrupt
#ifndef OMAPL138_ETH_RX_IRQ_CHANNEL
   #define OMAPL138_ETH_RX_IRQ_CHANNEL 3
#elif (OMAPL138_ETH_RX_IRQ_CHANNEL < 0 || OMAPL138_ETH_RX_IRQ_CHANNEL > 31)
   #error OMAPL138_ETH_RX_IRQ_CHANNEL parameter is not valid
#endif

//Name of the section where to place DMA buffers
#ifndef OMAPL138_ETH_RAM_SECTION
   #define OMAPL138_ETH_RAM_SECTION ".ram_no_cache"
#endif

//Name of the section where to place DMA descriptors
#ifndef OMAPL138_ETH_RAM_CPPI_SECTION
   #define OMAPL138_ETH_RAM_CPPI_SECTION ".ram_cppi"
#endif

//EMAC cores
#define EMAC_CORE0 0
#define EMAC_CORE1 1
#define EMAC_CORE2 2

//EMAC channels
#define EMAC_CH0 0
#define EMAC_CH1 1
#define EMAC_CH2 2
#define EMAC_CH3 3
#define EMAC_CH4 4
#define EMAC_CH5 5
#define EMAC_CH6 6
#define EMAC_CH7 7

//SYSCFG0 registers
#define SYSCFG0_PINMUX_R(n)         HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(n))
#define SYSCFG0_CFGCHIP3_R          HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP3)

//EMAC registers
#define EMAC_TXREVID_R              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXREVID)
#define EMAC_TXCONTROL_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXCONTROL)
#define EMAC_TXTEARDOWN_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXTEARDOWN)
#define EMAC_RXREVID_R              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXREVID)
#define EMAC_RXCONTROL_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXCONTROL)
#define EMAC_RXTEARDOWN_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXTEARDOWN)
#define EMAC_TXINTSTATRAW_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXINTSTATRAW)
#define EMAC_TXINTSTATMASKED_R      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXINTSTATMASKED)
#define EMAC_TXINTMASKSET_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXINTMASKSET)
#define EMAC_TXINTMASKCLEAR_R       HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXINTMASKCLEAR)
#define EMAC_MACINVECTOR_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINVECTOR)
#define EMAC_MACEOIVECTOR_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACEOIVECTOR)
#define EMAC_RXINTSTATRAW_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXINTSTATRAW)
#define EMAC_RXINTSTATMASKED_R      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXINTSTATMASKED)
#define EMAC_RXINTMASKSET_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXINTMASKSET)
#define EMAC_RXINTMASKCLEAR_R       HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXINTMASKCLEAR)
#define EMAC_MACINTSTATRAW_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINTSTATRAW)
#define EMAC_MACINTSTATMASKED_R     HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINTSTATMASKED)
#define EMAC_MACINTMASKSET_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINTMASKSET)
#define EMAC_MACINTMASKCLEAR_R      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINTMASKCLEAR)
#define EMAC_RXMBPENABLE_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXMBPENABLE)
#define EMAC_RXUNICASTSET_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXUNICASTSET)
#define EMAC_RXUNICASTCLEAR_R       HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXUNICASTCLEAR)
#define EMAC_RXMAXLEN_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXMAXLEN)
#define EMAC_RXBUFFEROFFSET_R       HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXBUFFEROFFSET)
#define EMAC_RXFILTERLOWTHRESH_R    HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXFILTERLOWTHRESH)
#define EMAC_RXFLOWTHRESH_R(n)      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXFLOWTHRESH(n))
#define EMAC_RXFREEBUFFER_R(n)      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXFREEBUFFER(n))
#define EMAC_MACCONTROL_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACCONTROL)
#define EMAC_MACSTATUS_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACSTATUS)
#define EMAC_EMCONTROL_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_EMCONTROL)
#define EMAC_FIFOCONTROL_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FIFOCONTROL)
#define EMAC_MACCONFIG_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACCONFIG)
#define EMAC_SOFTRESET_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_SOFTRESET)
#define EMAC_MACSRCADDRLO_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACSRCADDRLO)
#define EMAC_MACSRCADDRHI_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACSRCADDRHI)
#define EMAC_MACHASH1_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACHASH1)
#define EMAC_MACHASH2_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACHASH2)
#define EMAC_BOFFTEST_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_BOFFTEST)
#define EMAC_TPACETEST_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TPACETEST)
#define EMAC_RXPAUSE_R              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXPAUSE)
#define EMAC_TXPAUSE_R              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXPAUSE)
#define EMAC_RXGOODFRAMES_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXGOODFRAMES)
#define EMAC_RXBCASTFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXBCASTFRAMES)
#define EMAC_RXMCASTFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXMCASTFRAMES)
#define EMAC_RXPAUSEFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXPAUSEFRAMES)
#define EMAC_RXCRCERRORS_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXCRCERRORS)
#define EMAC_RXALIGNCODEERRORS_R    HWREG(SOC_EMAC_DSC_CONTROL_REG + EMACEMAC_RXOVERSIZED)
#define EMAC_RXJABBER_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXJABBER)
#define EMAC_RXUNDERSIZED_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXUNDERSIZED)
#define EMAC_RXFRAGMENTS_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXFRAGMENTS)
#define EMAC_RXFILTERED_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXFILTERED)
#define EMAC_RXQOSFILTERED_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXQOSFILTERED)
#define EMAC_RXOCTETS_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXOCTETS)
#define EMAC_TXGOODFRAMES_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXGOODFRAMES)
#define EMAC_TXBCASTFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXBCASTFRAMES)
#define EMAC_TXMCASTFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXMCASTFRAMES)
#define EMAC_TXPAUSEFRAMES_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXPAUSEFRAMES)
#define EMAC_TXDEFERRED_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXDEFERRED)
#define EMAC_TXCOLLISION_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXCOLLISION)
#define EMAC_TXSINGLECOLL_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXSINGLECOLL)
#define EMAC_TXMULTICOLL_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXMULTICOLL)
#define EMAC_TXEXCESSIVECOLL_R      HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXEXCESSIVECOLL)
#define EMAC_TXLATECOLL_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXLATECOLL)
#define EMAC_TXUNDERRUN_R           HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXUNDERRUN)
#define EMAC_TXCARRIERSENSE_R       HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXCARRIERSENSE)
#define EMAC_TXOCTETS_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXOCTETS)
#define EMAC_FRAME64_R              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME64)
#define EMAC_FRAME65T127_R          HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME65T127)
#define EMAC_FRAME128T255_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME128T255)
#define EMAC_FRAME256T511_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME256T511)
#define EMAC_FRAME512T1023_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME512T1023)
#define EMAC_FRAME1024TUP_R         HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_FRAME1024TUP)
#define EMAC_NETOCTETS_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_NETOCTETS)
#define EMAC_RXSOFOVERRUNS_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXSOFOVERRUNS)
#define EMAC_RXMOFOVERRUNS_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXMOFOVERRUNS)
#define EMAC_RXDMAOVERRUNS_R        HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXDMAOVERRUNS)
#define EMAC_MACADDRLO_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACADDRLO)
#define EMAC_MACADDRHI_R            HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACADDRHI)
#define EMAC_MACINDEX_R             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_MACINDEX)
#define EMAC_TXHDP_R(n)             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXHDP(n))
#define EMAC_RXHDP_R(n)             HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXHDP(n))
#define EMAC_TXCP_R(n)              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_TXCP(n))
#define EMAC_RXCP_R(n)              HWREG(SOC_EMAC_DSC_CONTROL_REG + EMAC_RXCP(n))

//EMAC control registers
#define EMAC_CTRL_REVID_R           HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_REVID)
#define EMAC_CTRL_SOFTRESET_R       HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_SOFTRESET)
#define EMAC_CTRL_INTCONTRO_R       HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_INTCONTROL)
#define EMAC_CTRL_C0RXTHRESHEN_R    HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0RXTHRESHEN)
#define EMAC_CTRL_CnRXEN_R(n)       HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_CnRXEN(n))
#define EMAC_CTRL_CnTXEN_R(n)       HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_CnTXEN(n))
#define EMAC_CTRL_CnMISCEN_R(n)     HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_CnMISCEN(n))
#define EMAC_CTRL_CnRXTHRESHEN_R(n) HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_CnRXTHRESHEN(n))
#define EMAC_CTRL_C0RXTHRESHSTAT_R  HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0RXTHRESHSTAT)
#define EMAC_CTRL_C0RXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0RXSTAT)
#define EMAC_CTRL_C0TXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0TXSTAT)
#define EMAC_CTRL_C0MISCSTAT_R      HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0MISCSTAT)
#define EMAC_CTRL_C1RXTHRESHSTAT_R  HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1RXTHRESHSTAT)
#define EMAC_CTRL_C1RXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1RXTHRESHSTAT)
#define EMAC_CTRL_C1TXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1TXSTAT)
#define EMAC_CTRL_C1MISCSTAT_R      HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1MISCSTAT)
#define EMAC_CTRL_C2RXTHRESHSTAT_R  HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2RXTHRESHSTAT)
#define EMAC_CTRL_C2RXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2RXSTAT)
#define EMAC_CTRL_C2TXSTAT_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2TXSTAT)
#define EMAC_CTRL_C2MISCSTAT_R      HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2MISCSTAT)
#define EMAC_CTRL_C0RXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0RXIMAX)
#define EMAC_CTRL_C0TXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C0TXIMAX)
#define EMAC_CTRL_C1RXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1RXIMAX)
#define EMAC_CTRL_C1TXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C1TXIMAX)
#define EMAC_CTRL_C2RXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2RXIMAX)
#define EMAC_CTRL_C2TXIMAX_R        HWREG(SOC_EMAC_DSC_CTRL_MOD_REG + EMAC_CTRL_C2TXIMAX)

//MDIO registers
#define MDIO_REVID_R                HWREG(SOC_MDIO_0_REGS + MDIO_REVID)
#define MDIO_CONTROL_R              HWREG(SOC_MDIO_0_REGS + MDIO_CONTROL)
#define MDIO_ALIVE_R                HWREG(SOC_MDIO_0_REGS + MDIO_ALIVE)
#define MDIO_LINK_R                 HWREG(SOC_MDIO_0_REGS + MDIO_LINK)
#define MDIO_LINKINTRAW_R           HWREG(SOC_MDIO_0_REGS + MDIO_LINKINTRAW)
#define MDIO_LINKINTMASKED_R        HWREG(SOC_MDIO_0_REGS + MDIO_LINKINTMASKED)
#define MDIO_USERINTRAW_R           HWREG(SOC_MDIO_0_REGS + MDIO_USERINTRAW)
#define MDIO_USERINTMASKED_R        HWREG(SOC_MDIO_0_REGS + MDIO_USERINTMASKED)
#define MDIO_USERINTMASKSET_R       HWREG(SOC_MDIO_0_REGS + MDIO_USERINTMASKSET)
#define MDIO_USERINTMASKCLEAR_R     HWREG(SOC_MDIO_0_REGS + MDIO_USERINTMASKCLEAR)
#define MDIO_USERACCESS0_R          HWREG(SOC_MDIO_0_REGS + MDIO_USERACCESS0)
#define MDIO_USERPHYSEL0_R          HWREG(SOC_MDIO_0_REGS + MDIO_USERPHYSEL0)
#define MDIO_USERACCESS1_R          HWREG(SOC_MDIO_0_REGS + MDIO_USERACCESS1)
#define MDIO_USERPHYSEL1_R          HWREG(SOC_MDIO_0_REGS + MDIO_USERPHYSEL1)

//MACEOIVECTOR register
#define EMAC_MACEOIVECTOR_C0RXTHRESH    0x00000000
#define EMAC_MACEOIVECTOR_C0RX          0x00000001
#define EMAC_MACEOIVECTOR_C0TX          0x00000002
#define EMAC_MACEOIVECTOR_C0MISC        0x00000003
#define EMAC_MACEOIVECTOR_C1RXTHRESH    0x00000004
#define EMAC_MACEOIVECTOR_C1RX          0x00000005
#define EMAC_MACEOIVECTOR_C1TX          0x00000006
#define EMAC_MACEOIVECTOR_C1MISC        0x00000007
#define EMAC_MACEOIVECTOR_C2RXTHRESH    0x00000008
#define EMAC_MACEOIVECTOR_C2RX          0x00000009
#define EMAC_MACEOIVECTOR_C2TX          0x0000000A
#define EMAC_MACEOIVECTOR_C2MISC        0x0000000B

//TX buffer descriptor flags
#define EMAC_TX_WORD0_NEXT_DESC_POINTER 0xFFFFFFFF
#define EMAC_TX_WORD1_BUFFER_POINTER    0xFFFFFFFF
#define EMAC_TX_WORD2_BUFFER_OFFSET     0xFFFF0000
#define EMAC_TX_WORD2_BUFFER_LENGTH     0x0000FFFF
#define EMAC_TX_WORD3_SOP               0x80000000
#define EMAC_TX_WORD3_EOP               0x40000000
#define EMAC_TX_WORD3_OWNER             0x20000000
#define EMAC_TX_WORD3_EOQ               0x10000000
#define EMAC_TX_WORD3_TDOWNCMPLT        0x08000000
#define EMAC_TX_WORD3_PASSCRC           0x04000000
#define EMAC_TX_WORD3_PACKET_LENGTH     0x0000FFFF

//RX buffer descriptor flags
#define EMAC_RX_WORD0_NEXT_DESC_POINTER 0xFFFFFFFF
#define EMAC_RX_WORD1_BUFFER_POINTER    0xFFFFFFFF
#define EMAC_RX_WORD2_BUFFER_OFFSET     0x07FF0000
#define EMAC_RX_WORD2_BUFFER_LENGTH     0x000007FF
#define EMAC_RX_WORD3_SOP               0x80000000
#define EMAC_RX_WORD3_EOP               0x40000000
#define EMAC_RX_WORD3_OWNER             0x20000000
#define EMAC_RX_WORD3_EOQ               0x10000000
#define EMAC_RX_WORD3_TDOWNCMPLT        0x08000000
#define EMAC_RX_WORD3_PASSCRC           0x04000000
#define EMAC_RX_WORD3_ERROR_MASK        0x03FF0000
#define EMAC_RX_WORD3_JABBER            0x02000000
#define EMAC_RX_WORD3_OVERSIZE          0x01000000
#define EMAC_RX_WORD3_FRAGMENT          0x00800000
#define EMAC_RX_WORD3_UNDERSIZED        0x00400000
#define EMAC_RX_WORD3_CONTROL           0x00200000
#define EMAC_RX_WORD3_OVERRUN           0x00100000
#define EMAC_RX_WORD3_CODEERROR         0x00080000
#define EMAC_RX_WORD3_ALIGNERROR        0x00040000
#define EMAC_RX_WORD3_CRCERROR          0x00020000
#define EMAC_RX_WORD3_NOMATCH           0x00010000
#define EMAC_RX_WORD3_PACKET_LENGTH     0x0000FFFF

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief TX buffer descriptor
 **/

typedef struct _Omapl138TxBufferDesc
{
   uint32_t word0;
   uint32_t word1;
   uint32_t word2;
   uint32_t word3;
   struct _Omapl138TxBufferDesc *next;
   struct _Omapl138TxBufferDesc *prev;
} Omapl138TxBufferDesc;


/**
 * @brief RX buffer descriptor
 **/

typedef struct _Omapl138RxBufferDesc
{
   uint32_t word0;
   uint32_t word1;
   uint32_t word2;
   uint32_t word3;
   struct _Omapl138RxBufferDesc *next;
   struct _Omapl138RxBufferDesc *prev;
} Omapl138RxBufferDesc;


//AM335x Ethernet MAC driver
extern const NicDriver omapl138EthDriver;

//AM335x Ethernet MAC related functions
error_t omapl138EthInit(NetInterface *interface);
void omapl138EthInitGpio(NetInterface *interface);
void omapl138EthInitBufferDesc(NetInterface *interface);

void omapl138EthTick(NetInterface *interface);

void omapl138EthEnableIrq(NetInterface *interface);
void omapl138EthDisableIrq(NetInterface *interface);
void omapl138EthTxIrqHandler(void);
void omapl138EthRxIrqHandler(void);
void omapl138EthEventHandler(NetInterface *interface);

error_t omapl138EthSendPacket(NetInterface *interface,
   const NetBuffer *buffer, size_t offset, NetTxAncillary *ancillary);

error_t omapl138EthReceivePacket(NetInterface *interface);

error_t omapl138EthUpdateMacAddrFilter(NetInterface *interface);
error_t omapl138EthUpdateMacConfig(NetInterface *interface);

void omapl138EthWritePhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr, uint16_t data);

uint16_t omapl138EthReadPhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
