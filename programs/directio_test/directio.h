/* -*- mode: c; c-basic-offset: 8; -*-
 * vim: noexpandtab sw=8 ts=8 sts=0:
 *
 * directio.h
 *
 * Copyright (C) 2010 Oracle.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */
#ifndef DIRECTIO_H
#define DIRECTIO_H

#define _GNU_SOURCE
#define _XOPEN_SOURCE 500
#define _LARGEFILE64_SOURCE
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <linux/types.h>
#include <sys/time.h>
#include <sys/sem.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <ocfs2/byteorder.h>
#include "crc32table.h"

#define FILE_RW_FLAGS		(O_CREAT|O_RDWR)
#define FILE_RO_FLAGS		(O_RDONLY)
#define FILE_MODE               (S_IRUSR|S_IWUSR|S_IXUSR|S_IROTH|\
				 S_IWOTH|S_IXOTH|S_IRGRP|S_IWGRP|S_IXGRP)

#define CHUNK_SIZE		(1024*8)
#define DIRECTIO_SLICE		(512)

#define BASC_TEST		0x00000001
#define APPD_TEST		0x00000002
#define FIHL_TEST		0x00000004
#define DSCV_TEST		0x00000008
#define VERI_TEST		0x00000010

#define HOSTNAME_LEN	256

struct write_unit {
	unsigned long wu_chunk_no;
	unsigned long long wu_timestamp;
	uint32_t wu_checksum;
	char wu_char;
};

union log_handler {
	FILE *stream_log;
	int socket_log;
};

union semun {
	int val;                    /* value for SETVAL */
	struct semid_ds *buf;       /* buffer for IPC_STAT, IPC_SET */
	unsigned short int *array;  /* array for GETALL, SETALL */
	struct seminfo *__buf;      /* buffer for IPC_INFO */
};

#endif