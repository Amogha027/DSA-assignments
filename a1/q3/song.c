#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

sptr makeSong(char *name, char *artist, double time)
{
	sptr s = (song *)malloc(sizeof(song));
	assert(s != NULL);

	s->name = (char *)malloc(strlen(name)+ 1);
	assert(s->name != NULL);
	strcpy(s->name, name);

	s->artist = (char *)malloc(strlen(artist)+1);
	assert(s->artist != NULL);
	strcpy(s->artist, artist);

	s->time = time;
	return s;
}
