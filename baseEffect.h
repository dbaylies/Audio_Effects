#ifndef _BASE_EFFECT_H
#define _BASE_EFFECT_H
#include <stdio.h>

class baseEffect {
public:
    baseEffect();
    ~baseEffect();
    /* virtual functions */
    virtual void init(int mode, int num_chn, int fpb) {;}
    virtual void process(float *ibuf, float *obuf, int num_frames, int num_chn) {;}
};

#endif
