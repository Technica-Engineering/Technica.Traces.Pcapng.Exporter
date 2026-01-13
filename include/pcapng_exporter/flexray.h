#ifndef _FR_H
#define _FR_H

#include <stdint.h>

#define FR_CHANNEL_A 0
#define FR_CHANNEL_B 1

#define FR_TYPE_FRAME  0x01
#define FR_TYPE_SYMBOL 0x02

#define FR_ERROR_FCRCERR 	1 << 4 // Frame CRC error
#define FR_ERROR_HCRCERR	1 << 3 // Invalid ID, i.e.a frame ID of 0x3E or 0x3F has been received
#define FR_ERROR_FESERR 	1 << 2 // Frame End Sequence error
#define FR_ERROR_CODEERR 	1 << 1 // Coding error… indicates if a Frame Start Sequence Error (FSSERR) or a Byte Start Sequence error (BSSERR) occurred
#define FR_ERROR_TSSVIOL 	1 << 0 // TSS violation

#define FR_PPI	1 << 3 // payload preable indicator
#define FR_NFI	1 << 2 // null frame indicator
#define FR_SFI	1 << 1 // sync frame indicator 
#define FR_STFI 1 << 0 // startup frame indicator

// Does not match PCAP structure memory layout wise
// But close enough
struct flexray_frame
{
	uint8_t type : 6;
	uint8_t channel : 2;
	uint8_t err_flags;

	uint8_t fr_flags;
	uint16_t fid;

	uint8_t len;
	uint16_t hcrc;
	uint8_t cc;

	uint8_t data[254];
	uint8_t symbol_length;

	flexray_frame() {
		type = FR_TYPE_FRAME;
	}
};

#endif