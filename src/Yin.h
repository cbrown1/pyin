#ifndef Yin_h
#define Yin_h

#include <stdint.h>

/* #define YIN_SAMPLING_RATE 44100 */
#define YIN_DEFAULT_THRESHOLD 0.15

/**
 * @struct  Yin
 * @breif	Object to encapsulate the parameters for the Yin pitch detection algorithm 
 */
typedef struct _Yin {
	int bufferSize;			/**< Size of the audio buffer to be analysed */
	int halfBufferSize;		/**< Half the buffer length */
	double* yinBuffer;		/**< Buffer that stores the results of the intermediate processing steps of the algorithm */
	double probability;		/**< Probability that the pitch found is correct as a decimal (i.e 0.85 is 85%) */
	double threshold;		/**< Allowed uncertainty in the result as a decimal (i.e 0.15 is 15%) */
    double sampleRate; /***< Customizable sampleRate */
} Yin;

/**
 * Initialise the Yin pitch detection object
 * @param yin        Yin pitch detection object to initialise
 * @param bufferSize Length of the audio buffer to analyse
 * @param threshold  Allowed uncertainty (e.g 0.05 will return a pitch with ~95% probability)
 */
void Yin_init(Yin *yin, double sampleRate, int bufferSize, double threshold);

/**
 * Runs the Yin pitch detection algortihm
 * @param  yin    Initialised Yin object
 * @param  buffer Buffer of samples to analyse
 * @return        Fundamental frequency of the signal in Hz. Returns -1 if pitch can't be found
 */
double Yin_getPitch(Yin *yin, double *buffer);

/**
 * Certainty of the pitch found 
 * @param  yin Yin object that has been run over a buffer
 * @return     Returns the certainty of the note found as a decimal (i.e 0.3 is 30%)
 */
double Yin_getProbability(Yin *yin);

void Yin_quit(Yin *yin);


#endif
