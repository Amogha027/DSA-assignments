#ifndef __MUSICPLY_H_
#define __MUSICPLY_H_
#include "song.h"

typedef struct MusicPlayer musicplayer;
typedef struct MusicPlayer* mptr;
typedef struct _queue Queue;
typedef struct _queue* ptr;

struct MusicPlayer{
	sptr curr_song; // current song
	int num; // number of songs in the queue
	ptr head; // pointer to the first song of queue
	ptr tail; // pointer to the last song of queue
};

struct _queue{
	sptr sing; // name of the song in the queue
	ptr next; // pointer to the next song in the queue
	ptr prev; // pointer to the previous song in the queue
};

mptr createMusicPlayer();
int addSongToQueue(mptr m, sptr song);
int removeSongFromQueue(mptr m, int k);
int playSong(mptr m);
song *getCurrentSong(mptr m);

#endif