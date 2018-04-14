#ifndef _SIG_DRC_H
#define _SIG_DRC_H

class sigDRC : public baseEffect {
public:
    sigDRC();
    ~sigDRC();
    /* virtual functions */
    virtual void init();
    virtual void process(float *ibuf, float *obuf, int num_frames, int num_chn);

    // Variables

    int sgn;
    float x, abs_x;
    int k, i, j;
};

#endif