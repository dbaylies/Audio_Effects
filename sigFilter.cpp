#include "baseEffect.h"
#include "sigFilter.h"
#include "hpf.h"
#include "lpf.h"
#include <stdlib.h>

sigFilter::sigFilter(void) {;}
sigFilter::~sigFilter() {;}


void sigFilter::init(int mode, int num_chn, int fpb) {

    // Set sig_filter class variable to mode that was passed in
    filtmode = mode;

    if (filtmode == LPF) {

        filtlen = (int)(sizeof(lpf)/sizeof(float));
        midbuf = (float *)calloc((filtlen-1+fpb)*num_chn,sizeof(float));

    } else if (filtmode == HPF) {

        filtlen = (int)(sizeof(hpf)/sizeof(float));
        midbuf = (float *)calloc((filtlen-1+fpb)*num_chn,sizeof(float));

    }

}
void sigFilter::process(float *ibuf, float *obuf, int num_frames, int num_chn)
{
    int i, j, k;
    // int count = 0;
    // static int filtcount = 0;

    // Process depending on value of filtmode
    if (filtmode == LPF) {

        //Copy input buffer to end of midbuf
        for (j = 0; j < num_frames; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                midbuf[(j+(filtlen-1))*num_chn + i] = ibuf[j*num_chn + i];
            }
        }

        // Bring down if over length of filter
        // filtcount = filtcount % filtlen;
        // Loop over all input samples
        for (j = 0; j < num_frames; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                // Loop over all filter samples
                obuf[j*num_chn + i] = 0;
                for (k = 0; k < filtlen; k++) {
                    //k = k % filtlen;
                    // printf("%i\n",filtcount);
                    //if ((j+filtlen-k) >= 0 && (j+filtlen-k) <= num_frames+filtlen) {
                        obuf[j*num_chn + i] += lpf[k]*midbuf[((j+filtlen-k)*num_chn)+i];
                        //count++;
                    //}
                }
            }

        }
        
        // Copy end of obuf to beginning of midbuf for next run
        for (j = 0; j < filtlen-1; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                midbuf[j*num_chn + i] = ibuf[(j+num_frames-(filtlen-1))*num_chn + i];
            }
        }

    } else if (filtmode == HPF) {
        
        //Copy input buffer to end of midbuf
        for (j = 0; j < num_frames; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                midbuf[(j+(filtlen-1))*num_chn + i] = ibuf[j*num_chn + i];
            }
        }

        // Bring down if over length of filter
        // filtcount = filtcount % filtlen;
        // Loop over all input samples
        for (j = 0; j < num_frames; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                // Loop over all filter samples
                obuf[j*num_chn + i] = 0;
                for (k = 0; k < filtlen; k++) {
                    //k = k % filtlen;
                    // printf("%i\n",filtcount);
                    if ((j+filtlen-k) >= 0 && (j+filtlen-k) <= num_frames+filtlen) {
                        obuf[j*num_chn + i] += hpf[k]*midbuf[((j+filtlen-k)*num_chn)+i];
                        //count++;
                    }
                }
            }

        }
        
        // Copy end of obuf to beginning of midbuf for next run
        for (j = 0; j < filtlen-1; j++) {
            // Loop over all channels
            for (i = 0; i < num_chn; i++) {
                midbuf[j*num_chn + i] = ibuf[(j+num_frames-(filtlen-1))*num_chn + i];
            }
        }
    }

}
