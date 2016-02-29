//My 3DS Demo of Marie Squid
//By Alan Treecko
//yay its my first homebrew program
//im actually doing something for once in my life
//this was a devkitpro example thanks whoever
//did the graphic example for making me do something
//in my weekend.



#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <mp3player.h>

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	printf("\x1b[1;5HGuess who is the freshest squid around?");
	wait(10000);
	printf("           ");
	printf("\x1b[14;19HMarie Squid!");
	printf("\x1b[16;3HPress Start to know that such fresh exists.");

	

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu
		
		// Initialise the audio subsystem
		MP3Player_Init();
		
		// Understand. MP3
		MP3Player_PlayBuffer(sample_mp3, sample_mp3_size, NULL);
	}

	// Exit services
	gfxExit();
	return 0;
}