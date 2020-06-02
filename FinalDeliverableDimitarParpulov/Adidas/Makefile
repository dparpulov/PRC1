CFLAGS=-Wall -Werror -Isrc

ENCODE= encodeMain
CHANNEL= channelMain
DECODE= decodeMain

SHARED=src/adidas.c

all:
	gcc $(CFLAGS) src/$(ENCODE).c $(SHARED) -o bin/$(ENCODE)
	gcc $(CFLAGS) src/$(CHANNEL).c $(SHARED) -o bin/$(CHANNEL)
	gcc $(CFLAGS) src/$(DECODE).c $(SHARED) -o bin/$(DECODE)

encode:
	gcc $(CFLAGS) src/$(ENCODE).c $(SHARED) -o bin/$(ENCODE)

channel:
	gcc $(CFLAGS) src/$(CHANNEL).c $(SHARED) -o bin/$(CHANNEL)

decode:
	gcc $(CFLAGS) src/$(DECODE).c $(SHARED) -o bin/$(DECODE)

clean:
	@rm -rf bin/*
