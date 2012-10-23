#include "ALContext.h"

ALContext::ALContext(bool enabled) : mSounds(10)
{
	mEnabled = false;
#ifdef ALPLUS_FMOD
	FMOD_RESULT result;
	mEnabled = false;
	if (enabled)
	{
		result = FMOD_System_Create(&mSoundSystem);
		if (result != FMOD_OK)
		{
			return;
		}
		result = FMOD_System_Init(mSoundSystem, 32, FMOD_INIT_NORMAL, 0);
		if (result != FMOD_OK)
		{
			return;
		}
		mEnabled = true;
	}
#endif
}

ALContext::~ALContext()
{
#ifdef ALPLUS_FMOD
	if (mEnabled)
		FMOD_System_Release(mSoundSystem);
#endif
}

void ALContext::createSound(const char* file_name, int id)
{
	if (!mEnabled) return;
#ifdef ALPLUS_FMOD
	FMOD_System_CreateSound(mSoundSystem, file_name, FMOD_DEFAULT, 0, &mSounds[id]);
#endif
}

void ALContext::update()
{
	if (!mEnabled) return;
#ifdef ALPLUS_FMOD
	FMOD_System_Update(mSoundSystem);
#endif
}

void ALContext::play(int id)
{
	if (!mEnabled) return;
#ifdef ALPLUS_FMOD
	FMOD_System_PlaySound(mSoundSystem, FMOD_CHANNEL_FREE, mSounds[id], false, 0);
#endif
}
