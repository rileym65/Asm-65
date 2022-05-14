#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

//  Immediate    #n    0x001       +0x08
//  ZeroPage     n     0x002       +0x04
//  Absolute     nn    0x004       +0x0c
//  ZPIndexedX   n,X   0x008       +0x14
//  ZPIndexedY   n,Y   0x010       +0x14
//  AbsIndexedX  nn,X  0x020       +0x1c
//  AbsIndexedY  nn,Y  0x040       +0x18
//  IndirectX    (n,X) 0x080       +0x00
//  IndirectY    (n),Y 0x100       +0x10
//  Indirect     (n)   0x200       +0x11
//  Accumulator  A     0x400       +0x08

typedef unsigned char byte;
typedef unsigned short word;

LINK char    opcodes[256][10];
LINK byte    opcodeArgs[256];
LINK byte    opcodeBase[256];
LINK word    opcodeModes[256];
LINK byte    opcodeType[256];
LINK int     numOpcodes;
LINK word    address;
LINK char  **sourceNames;
LINK int     numSourceFiles;
LINK char    baseName[1024];
LINK char    listName[1024];
LINK char    outName[1024];
LINK FILE   *sourceFile[100];
LINK int     lineNumber[100];
LINK int     fileNumber;
LINK FILE   *listFile;
LINK FILE   *outFile;
LINK char    listLine[1024];
LINK int     pass;
LINK int     lineCount;
LINK int     codeGenerated;
LINK char    label[256];
LINK char    opcode[256];
LINK char    arg1[256];
LINK char    arg2[256];
LINK word    arg;
LINK word    amode;
LINK byte    opcodeOffset;
LINK int     numArgs;
LINK char  **labelNames;
LINK word   *labelValues;
LINK int    *labelLine;
LINK int     numLabels;
LINK int     errors;
LINK char    sourceLine[1024];
LINK int     instructionBytes;
LINK byte    a1,a2;
LINK word    i1,i2;
LINK byte    c1,c2;
LINK int     evalErrors;
LINK byte    outBytes[16];
LINK int     outCount;
LINK word    outAddress;
LINK int     showList;
LINK int     showSymbols;
LINK int     createListFile;
LINK word    startAddress;
LINK char  **defines;
LINK char  **defineValues;
LINK int     numDefines;
LINK char    nests[100];
LINK int     numNests;
LINK char  **externals;
LINK int     numExternals;
LINK int     usedExternal;
LINK int    *references;
LINK word   *referenceAddress;
LINK int     numReferences;
LINK int    *publics;
LINK int     numPublics;

#endif

