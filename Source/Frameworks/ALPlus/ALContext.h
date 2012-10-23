#ifndef ALCONTEXT_H
#define ALCONTEXT_H

#ifdef ALPLUS_RTAUDIO
#include "RtAudio.h"
#include "stb_vorbis.h"
#endif

#ifdef ALPLUS_FMOD
#include <fmod.h>
#include <vector>
#endif

class ALContext
{
public:
	ALContext(bool enabled);
	~ALContext();
	void createSound(const char* file_name, int id);
	void update();
	void play(int id);
private:
	bool mEnabled;
#ifdef ALPLUS_RTAUDIO
	RtAudio mAudio;
	double mData[2];
	short *mDecoded;
	stb_vorbis *mVorbis;
#endif
#ifdef ALPLUS_FMOD
	FMOD_SYSTEM* mSoundSystem;
	std::vector<FMOD_SOUND*> mSounds;
#else
	int mSounds; // Fix for linux build!
#endif
};

#endif // ALCONTEXT_H
