#include "baseEffect.h"
#include "sigDRC.h"

sigDRC::sigDRC(void) {;}
sigDRC::~sigDRC() {;}
void sigDRC::init(void) {;}
void sigDRC::process(float *ibuf, float *obuf, int num_frames, int num_chn)
{
    
    /* Process */
    for (i=0; i<num_frames; i++) {
        for (j=0; j<num_chn; j++) {

            obuf[i*num_chn + j] = 0;

            x = ibuf[i*num_chn + j];
            sgn = (x < 0) ? -1 : 1;
            abs_x = sgn*x;

            // Process based on segment
            if (abs_x >= 0 && abs_x <= 0.25) {
                //printf("Ya");
                //k = 0;
                obuf[i*num_chn + j] = sgn*(3*abs_x);
            } else if (abs_x > 0.25 && abs_x <= 1.0) {
                //printf("Na\n");
                //k = 1;
                obuf[i*num_chn + j] = sgn*(0.332*(abs_x-0.25) + 0.75);
            } else {
                printf("Something went wrong...\n");
            }

        }
    }
}