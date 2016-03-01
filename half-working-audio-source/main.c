/*
My 3DS Demo of Marie Squid
By Alan Treecko

Thanks to whoever made the 3DS homebrew scene happen!
Thanks to whoever developed DevkitPRO and it's alts or something.
Thanks to whoever just made homebrew happen in the first place.
Thanks to everybody in the homebrew scene helping me get into 
working on homebrew <3
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <3ds.h>
u8* buffer;
u32 size;
#define SAMPLERATE 32000

static void audio_load(const char *audio);
static void audio_stop(void);
int main(int argc, char **argv)

{
	
	//Initialize some sounds for high quality sounding moans and SCREAMS from the ACTION!
	srvInit();
	aptInit();
	hidInit();
	csndInit();
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);



	printf("\x1b[1;5HGuess who is the freshest squid around?");
	wait(10000);
	printf("           ");
	printf("\x1b[5;19H\x1b[32m\ Marie Squid\x1b[0m\n");
	printf("\x1b[16;3HPress Start to know that such fresh exists.");
	printf("\x1b[17;3HPress A to get INTO IT!");

	

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame mostly for the shoots
		hidScanInput();
		

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START){   //PRESS START TO RETURN TO HBL
		}
		if (kDown & KEY_A){   // PRESS A TO PLAY
			audio_load("squit.bin");
		}
		
		
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	// Exit services... I know you want to come back...

	audio_stop();
	audio_stop();
	csndExit();
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}

void audio_stop(void){

	csndExecCmds(true);
	CSND_SetPlayState(0x8, 0);
	memset(buffer, 0, size);

	linearFree(buffer);
}
void audio_load(const char *audio){

	FILE *file = fopen(audio, "rb");


	// seek to end of file
	fseek(file, 0, SEEK_END);

	// file pointer tells us the size
	off_t size = ftell(file);

	// seek back to start
	fseek(file, 0, SEEK_SET);

	//allocate a buffer
	buffer = linearAlloc(size);

	//read contents !
	

	//close the file because we like being nice and tidy
	fclose(file);

	//memcpy(b, sfx_data, sfx_size);




}
