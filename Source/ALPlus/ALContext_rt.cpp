#include "ALContext.h"
#include <GL/glfw.h>

// Two-channel sawtooth wave generator.
static int saw( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
                double streamTime, RtAudioStreamStatus status, void *userData )
{
	unsigned int i, j;
	double *buffer = (double *) outputBuffer;
	double *lastValues = (double *) userData;

	if ( status == RTAUDIO_INPUT_OVERFLOW )
		std::cout << "Stream overflow detected!" << std::endl;
	else if ( status == RTAUDIO_OUTPUT_UNDERFLOW )
		std::cout << "Stream underflow detected!" << std::endl;

	// Write interleaved audio data.
	for ( i=0; i<nBufferFrames; i++ ) {
		for ( j=0; j<2; j++ ) {
			*buffer++ = lastValues[j];

			lastValues[j] += 0.005 * (j+1+(j*0.1));
			if ( lastValues[j] >= 1.0 ) lastValues[j] -= 2.0;
		}
	}

	return 0;
}

float ttt = 0;
int nnn = 0;

static int play( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
                 double streamTime, RtAudioStreamStatus status, void *userData )
{
	short *buffer = (short*)outputBuffer;
	//stb_vorbis *v = (stb_vorbis*)userData;
	short *input = (short*)(userData + (int)(streamTime * 96 / 2));
	//nnn += 1;
	//printf("nnn=%d\n", nnn);

	//int n = stb_vorbis_get_frame_short_interleaved(v, 2, buffer, nBufferFrames / 2);
	//printf("b=%d n=%d\n", nBufferFrames, n);
	memcpy(buffer, input, nBufferFrames);

	return 0;
}

ALContext::ALContext()
{
	// Determine the number of devices available
	unsigned int devices = mAudio.getDeviceCount();
	// Scan through devices for various capabilities
	RtAudio::DeviceInfo info;
	for ( unsigned int i=0; i<devices; i++ ) {
		info = mAudio.getDeviceInfo( i );
		if ( info.probed == true ) {
			// Print, for example, the maximum number of output channels for each device
			std::cout << "device = " << info.name;
			std::cout << ": maximum output channels = " << info.outputChannels << "\n";
		}
	}

	if ( mAudio.getDeviceCount() == 0 ) exit( 0 );

	int channels = 2;
	printf("decoding...\n");
	int len = stb_vorbis_decode_filename("Data/game1.ogg", &channels, &mDecoded);
	printf("channels=%d size=%d\n", channels, len);
	//int error;
	//mVorbis = stb_vorbis_open_filename("Data/game.ogg", &error, NULL);
	//printf("v=%d error=%d\n", mVorbis, error);

	RtAudio::StreamParameters parameters;
	parameters.deviceId = mAudio.getDefaultOutputDevice();
	parameters.nChannels = channels;
	parameters.firstChannel = 0;
	unsigned int sampleRate = 44100;
	unsigned int bufferFrames = 256; // 256 sample frames

	RtAudio::StreamOptions options;
	options.flags = RTAUDIO_NONINTERLEAVED;

	try {
		mAudio.openStream( &parameters, NULL, RTAUDIO_SINT16,
		                   sampleRate, &bufferFrames, &play, (void*)&mDecoded );
	} catch ( RtError& e ) {
		std::cout << '\n' << e.getMessage() << '\n' << std::endl;
		exit( 0 );
	}

	ttt = glfwGetTime();
	mAudio.startStream();
}

ALContext::~ALContext()
{
	stb_vorbis_close(mVorbis);
	mAudio.stopStream();
	mAudio.closeStream();
}
