#ifndef __USER_H_
#define __USER_H_
#include "musicplayer.h"

typedef struct User user;

struct User{
	char *name; // name of the user
	mptr player; // music player of the user
	ptr head; // pointer to the first song in the list of liked songs
	ptr tail; // pointer to the lst song in the list of liked songs
	int count; // Number of liked songs
};

user *createUser(char *name);
int addSongToQueueUser(user *c, sptr s);
int removeSongFromQueueUser(user *c, int k);
int playSongUser(user *c);
song *getCurrentSongUser(user *c);
int addLikedSong(user *c, sptr s);
int removeLikedSong(user *c, sptr s);
int userCompatibility(user *c1, user *c2);

#endif