# Audio_Effects
Uses block-processing to apply a lowpass, highpass, or compressor, depending on user input.


This code was created as part of an assignment in NYU's C Programming for Music Technology course, taught by Schuyler Quackenbush of the MPEG group.

"audioEffects", "baseEffect", "Passthrough" "hpf", "lpf", and "build.sh" were all written and provided by Professor Quackenbush, although I modified them a bit. The effects code "sigDRC" and "sigFilter" were written from scratch by me.

Usage for the audioEffects executable is "./audioEffects inputfile.wav [outputfile.wav]". For inputfile.wav, you can start by using signals/sig1.wav, for example. If an output file is specified, the audio read out by portaudio will be recorded into a .wav file in the working directory.

Turn your volume down for the dynamic range compression - it can be quite loud!
