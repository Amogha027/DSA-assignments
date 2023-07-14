#ifndef __SONG_H_
#define __SONG_H_

typedef struct Song song;
typedef struct Song* sptr;

struct Song
{
	char *name;	  // name of the song
	char *artist; // name of the artist of the song
	double time;  // duration of song in seconds
};

sptr makeSong(char *name, char *artist, double time);

#endif