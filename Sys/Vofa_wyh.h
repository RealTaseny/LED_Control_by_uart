#ifndef __VOFA_WYH_H__
#define __VOFA_WYH_H__

#include "HEADFILE_WYH.H"

#define CH_COUNT 1

struct Frame {
    float fdata[CH_COUNT];
    unsigned char tail[4];
};

void Uart_Sendtail_wyh(void);
void print_vofa_wyh(void);

#endif