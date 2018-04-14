#ifndef _SIG_FILTER_H
#define _SIG_FILTER_H

// Define HPF and LPF
#define HPF                 0
#define LPF                 1

class sigFilter : public baseEffect {
public:
    sigFilter();
    ~sigFilter();
    /* virtual functions */
    // Is it necessary to have virtual keywords here?
    void init(int mode, int num_chn, int fpb);
    void process(float *ibuf, float *obuf, int num_frames, int num_chn);
    int filtmode, filtlen;
    float *midbuf;

    //int filtcount = 0;
};

#endif
