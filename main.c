#define MAIN

#include "header.h"

#define OP_STOP     0xff
#define OP_DIV      0x71
#define OP_MUL      0x70
#define OP_SUB      0x61
#define OP_ADD      0x60
#define OP_SHR      0x51
#define OP_SHL      0x50
#define OP_LT       0x45
#define OP_LE       0x44
#define OP_GT       0x43
#define OP_GE       0x42
#define OP_NE       0x41
#define OP_EQ       0x40
#define OP_XOR      0x32
#define OP_OR       0x31
#define OP_AND      0x30
#define OP_LAND     0x20
#define OP_LOR      0x10
#define OP_OP       0x09
#define OP_CP       0x08
#define OP_END      0x01

typedef union {
  float f;
  unsigned int i;
  } FTOI;

void addOpcode(char* op, byte args, word modes, byte base, byte t) {
  strcpy(opcodes[numOpcodes], op);
  opcodeArgs[numOpcodes] = args;
  opcodeModes[numOpcodes] = modes;
  opcodeBase[numOpcodes] = base;
  opcodeType[numOpcodes] = t;
  numOpcodes++;
  }

void initOpcodes() {
  numOpcodes = 0;
  addOpcode("ADC",    1,   0x3ef, 0x61, 1);
  addOpcode("AND",    1,   0x3ef, 0x21, 1);
  addOpcode("ASL",    1,   0x42e, 0x02, 1);
  addOpcode("BCC",    1,   0x006, 0x90, 2);
  addOpcode("BCS",    1,   0x006, 0xb0, 2);
  addOpcode("BEQ",    1,   0x006, 0xf0, 2);
  addOpcode("BNE",    1,   0x006, 0xd0, 2);
  addOpcode("BMI",    1,   0x006, 0x30, 2);
  addOpcode("BPL",    1,   0x006, 0x10, 2);
  addOpcode("BVC",    1,   0x006, 0x50, 2);
  addOpcode("BVS",    1,   0x006, 0x70, 2);
  addOpcode("BRA",    1,   0x006, 0x80, 2);
  addOpcode("BIT",    1,   0x02f, 0x20, 1);
  addOpcode("BRK",    0,       0, 0x00, 1);
  addOpcode("CLC",    0,       0, 0x18, 1);
  addOpcode("CLD",    0,       0, 0xd8, 1);
  addOpcode("CLI",    0,       0, 0x58, 1);
  addOpcode("CLV",    0,       0, 0xb8, 1);
  addOpcode("CMP",    1,   0x3ef, 0xc1, 1);
  addOpcode("CPX",    1,   0x007, 0xe0, 1);
  addOpcode("CPY",    1,   0x007, 0xc0, 1);
  addOpcode("DEA",    0,       0, 0x3a, 1);
  addOpcode("DEC",    1,   0x02e, 0xc2, 1);
  addOpcode("DEX",    0,       0, 0xca, 1);
  addOpcode("DEY",    0,       0, 0x88, 1);
  addOpcode("EOR",    1,   0x3ef, 0x41, 1);
  addOpcode("INA",    0,       0, 0x1a, 1);
  addOpcode("INC",    1,   0x02e, 0xe2, 1);
  addOpcode("INX",    0,       0, 0xe8, 1);
  addOpcode("INY",    0,       0, 0xc8, 1);
  addOpcode("JMP",    1,   0x284, 0x40, 1);
  addOpcode("JSR",    1,   0x004, 0x20, 1);
  addOpcode("LDA",    1,   0x3ef, 0xa1, 1);
  addOpcode("LDX",    1,   0x057, 0xa2, 1);
  addOpcode("LDY",    1,   0x057, 0xa0, 1);
  addOpcode("LSR",    1,   0x42e, 0x42, 1);
  addOpcode("NOP",    0,       0, 0xea, 1);
  addOpcode("ORA",    1,   0x3ef, 0x01, 1);
  addOpcode("PHA",    0,       0, 0x48, 1);
  addOpcode("PHP",    0,       0, 0x08, 1);
  addOpcode("PHX",    0,       0, 0xda, 1);
  addOpcode("PHY",    0,       0, 0x5a, 1);
  addOpcode("PLA",    0,       0, 0x68, 1);
  addOpcode("PLP",    0,       0, 0x28, 1);
  addOpcode("PLX",    0,       0, 0xfa, 1);
  addOpcode("PLY",    0,       0, 0x7a, 1);
  addOpcode("ROL",    1,   0x42e, 0x22, 1);
  addOpcode("ROR",    1,   0x42e, 0x62, 1);
  addOpcode("RTI",    0,       0, 0x40, 1);
  addOpcode("RTS",    0,       0, 0x60, 1);
  addOpcode("SBC",    1,   0x3ef, 0xe1, 1);
  addOpcode("SEC",    0,       0, 0x38, 1);
  addOpcode("SED",    0,       0, 0xf8, 1);
  addOpcode("SEI",    0,       0, 0x78, 1);
  addOpcode("STA",    0,   0x3ee, 0x81, 1);
  addOpcode("STX",    0,   0x056, 0x82, 1);
  addOpcode("STY",    0,   0x02e, 0x80, 1);
  addOpcode("STZ",    0,   0x02e, 0x64, 1);
  addOpcode("TAX",    0,       0, 0xaa, 1);
  addOpcode("TAY",    0,       0, 0xa8, 1);
  addOpcode("TRB",    1,   0x006, 0x10, 1);
  addOpcode("TSB",    1,   0x006, 0x00, 1);
  addOpcode("TSX",    0,       0, 0xba, 1);
  addOpcode("TXA",    0,       0, 0x8a, 1);
  addOpcode("TXS",    0,       0, 0x9a, 1);
  addOpcode("TYA",    0,       0, 0x98, 1);
  printf("%d opcodes loaded\n",numOpcodes);
  }

void writeOutput() {
  int  i;
  char buffer[256];
  char tmp[4];
  sprintf(buffer,":%04x",outAddress);
  for (i=0; i<outCount; i++) {
    sprintf(tmp," %02x",outBytes[i]);
    strcat(buffer,tmp);
    }
  fprintf(outFile,"%s\n",buffer);
  outCount = 0;
  outAddress = address;
  }

void output(byte value) {
  int  i;
  char tmp[4];
  codeGenerated++;
  address++;
  instructionBytes++;
  sprintf(tmp," %02x",value);
  strcat(listLine,tmp);
  if (instructionBytes == 4) {
    strcat(listLine,"  ");
    strcat(listLine, sourceLine);
    }
  if ((instructionBytes % 4) == 0) {
    if (pass == 2) {
      if (showList != 0) printf("%s\n",listLine);
      if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
      }
    strcpy(listLine,"             ");
    }
  if (pass == 2) {
    outBytes[outCount++] = value;
    if (outCount == 16) {
      writeOutput();
      }
    }
  }

int findLabelNumber(char* name) {
  int i;
  int j;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0)
      return i;
  return -1;
  }

word findLabel(char* name, char* err) {
  int i;
  int j;
  *err = 0;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0) {
      for (j=0; j<numExternals; j++)
        if (strcasecmp(externals[j], name) == 0)
          usedExternal = j;
      return labelValues[i];
      }
  if (pass == 1) return 0xffff;
  *err = 0xff;
  printf("Error: Label not found: %s\n",name);
  errors++;
  return 0;
  }

int addLabel(char* name, word value) {
  int i;
  if (pass == 2) return 0;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0) {
      printf("Error: Duplicate label: %s\n",name);
      errors++;
      return -1;
      }
  numLabels++;
  if (numLabels == 1) {
    labelNames = (char**)malloc(sizeof(char*));
    labelValues = (word*)malloc(sizeof(word));
    labelLine = (int*)malloc(sizeof(int));
    }
  else {
    labelNames = (char**)realloc(labelNames,sizeof(char*)*numLabels);
    labelValues = (word*)realloc(labelValues,sizeof(word)*numLabels);
    labelLine = (int*)realloc(labelLine,sizeof(int)*numLabels);
    }
  labelNames[numLabels-1] = (char*)malloc(strlen(name)+1);
  strcpy(labelNames[numLabels-1], name);
  labelValues[numLabels-1] = value;
  labelLine[numLabels-1] = lineCount;
  return 0;
  }

void setLabel(char* name, word value) {
  int i;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0) {
      labelValues[i] = value;
      return;
      }
  numLabels++;
  if (numLabels == 1) {
    labelNames = (char**)malloc(sizeof(char*));
    labelValues = (word*)malloc(sizeof(word));
    labelLine = (int*)malloc(sizeof(int));
    }
  else {
    labelNames = (char**)realloc(labelNames,sizeof(char*)*numLabels);
    labelValues = (word*)realloc(labelValues,sizeof(word)*numLabels);
    labelLine = (int*)realloc(labelLine,sizeof(int)*numLabels);
    }
  labelNames[numLabels-1] = (char*)malloc(strlen(name)+1);
  strcpy(labelNames[numLabels-1], name);
  labelValues[numLabels-1] = value;
  labelLine[numLabels-1] = lineCount;
  }

void addExternal(char* name) {
  int i;
  if (pass == 2) return;
  for (i=0; i<numExternals; i++)
    if (strcasecmp(externals[i], name) == 0) {
      printf("Error: Duplicate external: %s\n",name);
      errors++;
      return;
      }
  addLabel(name, 0);
  numExternals++;
  if (numExternals == 1)
    externals = (char**)malloc(sizeof(char*));
  else
    externals = (char**)realloc(externals,sizeof(char*)*numExternals);
  externals[numExternals-1] = (char*)malloc(strlen(name)+1);
  strcpy(externals[numExternals-1], name);
  }

void addDefine(char *def, char* value) {
  int i;
  for (i=0; i<numDefines; i++)
    if (strcmp(defines[i], def) == 0) {
      printf("Error: %s is defined more than once\n");
      errors++;
      return;
      }
  numDefines++;
  if (numDefines == 1) {
    defines = (char**)malloc(sizeof(char*));
    defineValues = (char**)malloc(sizeof(char*));
    }
  else {
    defines = (char**)realloc(defines,sizeof(char*)*numDefines);
    defineValues = (char**)realloc(defineValues,sizeof(char*)*numDefines);
    }
  defines[numDefines-1] = (char*)malloc(strlen(def) + 1);
  defineValues[numDefines-1] = (char*)malloc(strlen(value) + 1);
  strcpy(defines[numDefines-1], def);
  strcpy(defineValues[numDefines-1], value);
  }

char* findDefine(char*def) {
  int i;
  for (i=0; i<numDefines; i++)
    if (strcmp(defines[i], def) == 0) {
      return defineValues[i];
      }
  return NULL;
  }

char* evaluate(char* expr, word* ret) {
  int  i;
  word nstack[256];
  int  nsp;
  byte ostack[256];
  int  osp;
  int  flag;
  char err;
  char token[128];
  int  pos;
  char isHex;
  char hexChar;
  word dec;
  word hex;
  word value;
  byte op;
  char ntype;
  *ret = 0;
  evalErrors = 0;
  usedExternal = -1;
  osp = 0;
  nsp = 0;
  flag = 0;
  if (*expr == '-') {
    nstack[nsp++] = 0;
    ostack[osp++] = OP_SUB;
    expr++;
    }
  while (flag == 0) {
    hexChar = 'N';
    isHex = 'N';
    ntype = 'W';
    dec = 0;
    hex = 0;
    while (*expr == ' ') expr++;
    while (*expr == '(') {
      ostack[osp++] = OP_OP;
      expr++;
      }
    while (*expr == ' ') expr++;
    if (*expr == '<') {
      ntype = 'H';
      expr++;
      }
    if (*expr == '>') {
      ntype = 'L';
      expr++;
      }
    if (*expr == '$' && 
        ((*(expr+1) >= '0' && *(expr+1) <= '9') ||
         (*(expr+1) >= 'a' && *(expr+1) <= 'f') ||
         (*(expr+1) >= 'A' && *(expr+1) <= 'F')
        )) {
      isHex = 'Y';
      expr++;
      }
    if (*expr == '$') {
      value = address;
      expr++;
      }
    else if (*expr == '%') {
      expr++;
      isHex = 'N';
      value = 0;
      while (*expr == '0' || *expr == '1' || *expr == '_') {
        if (*expr == '0') value <<= 1;
        if (*expr == '1') value = (value << 1) | 1;
        expr++;
        }
      }
    else if ((*expr >= '0' && *expr <= '9') || isHex == 'Y') {
      while ((*expr >= '0' && *expr <= '9') ||
             (*expr >= 'a' && *expr <= 'f') ||
             (*expr >= 'A' && *expr <= 'F')) {
        if (*expr >= '0' && *expr <= '9') {
          dec = (dec * 10) + (*expr - '0');
          hex = (hex * 16) + (*expr - '0');
          }
        if (*expr >= 'a' && *expr <= 'f') {
          hexChar = 'Y';
          hex = (hex * 16) + (*expr - 87);
          }
        if (*expr >= 'A' && *expr <= 'F') {
          hexChar = 'Y';
          hex = (hex * 16) + (*expr - 55);
          }
        expr++;
        }
      if (*expr == 'h' || *expr == 'H') {
        isHex = 'Y';
        expr++;
        }
      if (isHex == 'Y') {
        value = hex;
        }
      else if (hexChar == 'N') {
        value = dec;
        }
      else {
        printf("Error: Expression error\n");
        *ret = 0;
        evalErrors = 1;
        return expr;
        }
      }
    else if ((*expr >= 'a' && *expr <= 'z') ||
             (*expr >= 'A' && *expr <= 'Z') ||
             *expr == '_') {
      pos = 0;
      while ((*expr >= 'a' && *expr <= 'z') ||
             (*expr >= 'A' && *expr <= 'Z') ||
             (*expr >= '0' && *expr <= '9') ||
             *expr == '_') token[pos++] = *expr++;
      token[pos] = 0;
      value = findLabel(token, &err);
      if (err != 0) evalErrors = 1;
      }
    else if (*expr == '\'') {
      expr++;
      value = *expr++;
      while (*expr != 0 && *expr != '\'') expr++;
      if (*expr == '\'') expr++;
      }
    else {
      evalErrors = 1;
      return expr;
      }
    if (ntype == 'W') nstack[nsp++] = value;
    if (ntype == 'H') nstack[nsp++] = (value >> 8) & 0xff;
    if (ntype == 'L') nstack[nsp++] = value & 0xff;
    while (*expr == ' ' || *expr == '\t') expr++;
    op = OP_CP;
    while (op == OP_CP) {
      if (*expr == 0) op = OP_END;
      else if (*expr == '+') op = OP_ADD;
      else if (*expr == '-') op = OP_SUB;
      else if (*expr == '*') op = OP_MUL;
      else if (*expr == '/') op = OP_DIV;
      else if (*expr == ')') op = OP_CP;
      else if (*expr == '<' && *(expr+1) == '<') { op = OP_SHL; expr++; }
      else if (*expr == '>' && *(expr+1) == '>') { op = OP_SHR; expr++; }
      else if (*expr == '<' && *(expr+1) == '>') { op = OP_NE; expr++; }
      else if (*expr == '<' && *(expr+1) == '=') { op = OP_LE; expr++; }
      else if (*expr == '>' && *(expr+1) == '=') { op = OP_GE; expr++; }
      else if (*expr == '&' && *(expr+1) == '&') { op = OP_LAND; expr++; }
      else if (*expr == '|' && *(expr+1) == '|') { op = OP_LOR; expr++; }
      else if (*expr == '>') op = OP_GT;
      else if (*expr == '<') op = OP_LT;
      else if (*expr == '=') op = OP_EQ;
      else if (*expr == '&') op = OP_AND;
      else if (*expr == '|') op = OP_OR;
      else if (*expr == '^') op = OP_XOR;
      else {
        op = OP_END;
        flag = 0xff;
        }
      if (*expr != 0) expr++;
      while (osp > 0 && (ostack[osp-1] & 0xf0) >= (op & 0xf0)) {
        if (ostack[osp-1] == OP_ADD) { nstack[nsp-2] += nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SUB) { nstack[nsp-2] -= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_MUL) { nstack[nsp-2] *= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_DIV) { nstack[nsp-2] /= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SHL) { nstack[nsp-2] <<= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SHR) { nstack[nsp-2] >>= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_AND) { nstack[nsp-2] &= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_OR) { nstack[nsp-2] |= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_XOR) { nstack[nsp-2] ^= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_NE) { nstack[nsp-2] = nstack[nsp-2] != nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_EQ) { nstack[nsp-2] = nstack[nsp-2] == nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_GE) { nstack[nsp-2] = nstack[nsp-2] >= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LE) { nstack[nsp-2] = nstack[nsp-2] <= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_GT) { nstack[nsp-2] = nstack[nsp-2] > nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LT) { nstack[nsp-2] = nstack[nsp-2] < nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LAND) { nstack[nsp-2] = nstack[nsp-2] && nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LOR) { nstack[nsp-2] = nstack[nsp-2] || nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_OP) {
          osp--;
          op = OP_STOP;
          }
        }
      if (op == OP_STOP) op = OP_CP;
      while (*expr == ' ' || *expr == '\t') expr++;
      }
    ostack[osp++] = op;
    if (*expr == 0) flag = 0xff;
    }
  if (nsp != 1) {
    printf("Error: Expression error\n");
    evalErrors = 1;
    }
  *ret = nstack[0];
  return expr;
  }

void parse(char* line) {
  int pos;
  strcpy(label, "");
  strcpy(opcode, "");
  strcpy(arg1, "");
  strcpy(arg2, "");
  numArgs = 0;
  if (*line != ' ' && *line != '\t') {
    pos = 0;
    while (*line != 0 && *line != ' ' && *line != '\t' && *line != ':')
      label[pos++] = *line++;
    label[pos] = 0;
    if (*line == ':') line++;
    }
  while (*line == ' ' || *line == '\t') line++;
  if (*line == 0 || *line == ';') return;
  pos = 0;
  while (*line != 0 && *line != ' ' && *line != '\t')
    opcode[pos++] = *line++;
  opcode[pos] = 0;
  while (*line == ' ' || *line == '\t') line++;
  if (*line == 0 || *line == ';') return;
  pos = 0;
  while (*line != 0 && *line != ',' && *line != ';')
    arg1[pos++] = *line++;
  arg1[pos] = 0;
  if (*line == ',') line++;
  while (*line == ' ' || *line == '\t') line++;
  if (*line == 0 || *line == ';') return;
  pos = 0;
  while (*line != 0 && *line != ';')
    arg2[pos++] = *line++;
  arg2[pos] = 0;
  return;
  }

void parse2() {
  if (strcasecmp(opcode,"db") == 0) return;
  if (strcasecmp(opcode,"byte") == 0) return;
  if (strcasecmp(opcode,".byte") == 0) return;
  if (strcasecmp(opcode,"dw") == 0) return;
  if (strcasecmp(opcode,"word") == 0) return;
  if (strcasecmp(opcode,".word") == 0) return;
  while (strlen(arg1) > 0 && arg1[strlen(arg1)-1] <= 32) arg1[strlen(arg1)-1] = 0;
  while (strlen(arg2) > 0 && arg2[strlen(arg2)-1] <= 32) arg2[strlen(arg2)-1] = 0;
  if (strlen(arg2) > 0) numArgs = 2;
  else if (strlen(arg1) > 0) numArgs = 1;
  else numArgs = 0;
  if (numArgs == 0) {
    amode = 0;
    arg = 0;
    opcodeOffset = 0;
    }
  if (numArgs == 1) {
    if (strcasecmp(arg1,"a") == 0) {
      amode = 0x400;
      opcodeOffset = 0x08;
      }
    else if (arg1[0] == '#') {
      amode = 0x001;
      opcodeOffset = 0x08;
      evaluate(&(arg1[1]), &arg);
      }
    else if (arg1[0] == '(') {
      amode = 0x200;
      opcodeOffset = 0x11;
      evaluate(&(arg1[1]), &arg);
      }
    else {
      evaluate(arg1, &arg);
      if (evalErrors != 0) {
        printf("Error: Invalid argument format\n");
        printf("       %s\n",sourceLine);
        errors++;
        }
      else {
        if (arg < 256) {
          amode = 0x002;
          opcodeOffset = 0x04;
          }
        else {
          amode = 0x004;
          opcodeOffset = 0x0c;
          }
        }
      }
    }
  if (numArgs == 2) {
    if (arg1[0] == '(') {
      evaluate(&(arg1[1]), &arg);
      if (evalErrors != 0) {
        printf("Error: Invalid argument format\n");
        printf("       %s\n",sourceLine);
        errors++;
        }
      else {
        if (strcasecmp(arg2,"y") == 0) {
          amode = 0x100;
          opcodeOffset = 0x10;
          }
        else if (strcasecmp(arg2,"x)") == 0) {
          amode = 0x080;
          opcodeOffset = 0x00;
          }
        else {
          printf("Error: Invalid argument format\n");
          printf("       %s\n",sourceLine);
          errors++;
          }
        }
      }
    else {
      evaluate(arg1, &arg);
      if (evalErrors != 0) {
        printf("Error: Invalid argument format\n");
        printf("       %s\n",sourceLine);
        errors++;
        }
      else {
        if (strcasecmp(arg2,"y") == 0) {
          amode = 0x040;
          opcodeOffset = 0x18;
          }
        else if (strcasecmp(arg2,"x") == 0) {
          if (arg < 256) {
            amode = 0x008;
            opcodeOffset = 0x14;
            }
          else {
            amode = 0x020;
            opcodeOffset = 0x1c;
            }
          }
        else {
          printf("Error: Invalid argument format\n");
          printf("       %s\n",sourceLine);
          errors++;
          }
        }
      }
    }
// printf("amode = %03x\n",amode);
// printf("offset = %02x\n",opcodeOffset);
// printf("arg = %04x\n",arg);
  return;
  }

int lookupInstruction() {
  int i;
  char flag;
  word value;
  char temp[1024];
  char err;
  int  pos;
  usedExternal = -1;
  for (i=0; i<numOpcodes; i++) {
    if (strcasecmp(opcode,opcodes[i]) == 0) {
      if (amode == opcodeModes[i]) return i;
      if ((amode & opcodeModes[i]) != 0) return i;
      }
    }
  return -1;
  }

void translateInstruction(int o) {
  word addr;
  if (opcodeType[o] == 1) {
// printf("op=%02x amode=%03x\n",opcodeBase[o],amode);
    if (opcodeBase[o] == 0x20 && amode == 0x001) output(0x89);
    else if (opcodeBase[o] == 0xe0 && amode == 0x001) output(0xe0);
    else if (opcodeBase[o] == 0xc0 && amode == 0x001) output(0xc0);
    else if (opcodeBase[o] == 0x40 && amode == 0x200) output(0x6c);
    else if (opcodeBase[o] == 0x40 && amode == 0x080) output(0x7c);
    else if (strcasecmp(opcode,"jsr") == 0) output(0x20);
    else if (opcodeBase[o] == 0x20 && amode == 0x004) output(0x34);
    else if (opcodeBase[o] == 0xa2 && amode == 0x001) output(0xa2);
    else if (opcodeBase[o] == 0xa0 && amode == 0x001) output(0xa0);
    else if (opcodeBase[o] == 0xa2 && amode == 0x010) output(0xb6);
    else if (opcodeBase[o] == 0xa2 && amode == 0x040) {
      if (arg < 256) {
        output(0xb6);
        amode = 0x002;
        }
      else {
        output(0xbe);
        amode = 0x004;
        }
      }
    else if (opcodeBase[o] == 0xa0 && amode == 0x040) {
      if (arg < 256) {
        output(0xb4);
        amode = 0x002;
        }
      else {
        output(0xbc);
        amode = 0x004;
        }
      }
    else if (opcodeBase[o] == 0x82 && amode == 0x040) {
      output(0x96);
      amode = 0x002;
      }
    else if (opcodeBase[o] == 0x64 && amode == 0x002) output(0x64);
    else if (opcodeBase[o] == 0x64 && amode == 0x004) output(0x9c);
    else if (opcodeBase[o] == 0x64 && amode == 0x008) output(0x74);
    else if (opcodeBase[o] == 0x64 && amode == 0x020) output(0x9e);
    else output(opcodeBase[o] + opcodeOffset);
    if (opcodeBase[o] == 0x40 && amode == 0x200) amode = 0x004;
    if (opcodeBase[o] == 0x40 && amode == 0x080) amode = 0x004;
    switch (amode) {
      case 0x001: output(arg & 0xff); break;
      case 0x002: output(arg & 0xff); break;
      case 0x004: output(arg & 0xff); output((arg >> 8) & 0xff); break;
      case 0x008: output(arg & 0xff); break;
      case 0x010: output(arg & 0xff); break;
      case 0x020: output(arg & 0xff); output((arg >> 8) & 0xff); break;
      case 0x040: output(arg & 0xff); output((arg >> 8) & 0xff); break;
      case 0x080: output(arg & 0xff); break;
      case 0x100: output(arg & 0xff); break;
      case 0x200: output(arg & 0xff); break;
      }
    }
  if (opcodeType[o] == 2) {
    output(opcodeBase[o]);
    addr = (arg - (address+1));
    output(addr & 0xff);
    if (pass == 2 && ((addr & 0xff00) != 0) && ((addr & 0xff00) != 0xff00)) {
      printf("Error: Branch out of range\n");
      errors++;
      }
    }
  }

void defReplace(char* line) {
  char  buffer[1024];
  char *pchar;
  int i;
  for (i=0; i<numDefines; i++) {
    while ((pchar = strstr(line, defines[i])) != NULL) {
      strncpy(buffer,line,pchar-line);
      buffer[pchar-line] = 0;
      strcat(buffer,defineValues[i]);
      strcat(buffer,pchar+strlen(defines[i]));
      strcpy(line,buffer);
      }
    }
  }

char* nextLine(char* line) {
  int   i;
  char* ret;
  int   flag;
  char  buffer[1024];
  int   pos;
  char *pchar;
  word  value;
  flag = -1;
  while (flag) {
    ret = fgets(line, 1024, sourceFile[fileNumber]);
    lineCount++;
    lineNumber[fileNumber]++;
    if (ret != NULL) {
      while (strlen(ret) > 0 && line[strlen(ret)-1] <= ' ')
        line[strlen(ret)-1] = 0;
      flag = 0;
      if (*ret == '#') {
        if (fileNumber == 0)
          sprintf(listLine,"[%05d] ",lineNumber[fileNumber]);
        else
          sprintf(listLine,"<%05d> ",lineNumber[fileNumber]);
        while (strlen(listLine) < 25) strcat(listLine," ");
        strcat(listLine,"  ");
        strcat(listLine,ret);
        if (pass == 2) {
          if (showList != 0) printf("%s\n",listLine);
          if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
          }
        flag = -1;
        if (strncmp(ret,"#include ",9) == 0) {
          ret += 9;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          fileNumber++;
          lineNumber[fileNumber] = 0;
          sourceFile[fileNumber] = fopen(buffer,"r");
          if (sourceFile[fileNumber] == NULL) {
            }
          }
        if (strncmp(ret,"#define ",8) == 0) {
          ret += 8;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          while (*ret == ' ' || *ret == '\t') ret++;
          if (*ret == 0) addDefine(buffer,"1");
            else addDefine(buffer, ret);
          }
        if (strncmp(ret,"#ifdef ",7) == 0) {
          ret += 7;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          pchar = findDefine(buffer);
          if (pchar != NULL) {
            numNests++;
            nests[numNests] = 'Y';
            }
          else {
            numNests++;
            nests[numNests] = 'N';
            }
          }
        if (strncmp(ret,"#ifndef ",8) == 0) {
          ret += 8;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          pchar = findDefine(buffer);
          if (pchar != NULL) {
            numNests++;
            nests[numNests] = 'N';
            }
          else {
            numNests++;
            nests[numNests] = 'Y';
            }
          }
        if (strncmp(ret,"#if ",4) == 0) {
          ret += 4;
          while (*ret == ' ' || *ret == '\t') ret++;
          defReplace(ret);
          evaluate(ret, &value);
          if (value != 0) {
            numNests++;
            nests[numNests] = 'Y';
            }
          else {
            numNests++;
            nests[numNests] = 'N';
            }
          }
        if (strncmp(ret,"#endif",6) == 0) {
          if (numNests > 0) numNests--;
          else {
            printf("Error: Unmatched #endif\n");
            errors++;
            }
          }
        if (strncmp(ret,"#else",5) == 0) {
          if (numNests > 0)
            nests[numNests] = (nests[numNests] == 'Y') ? 'N' : 'Y';
          else {
            printf("Error: Unmatched #else\n");
            errors++;
            }
          }
        }
      else if (nests[numNests] != 'Y') {
        flag = -1;
        }
      else {
        defReplace(ret);
        }
      }
    else {
      if (fileNumber == 0) flag = 0;
      else {
        fclose(sourceFile[fileNumber]);
        fileNumber--;
        flag = -1;
        }
      }
    }
  return ret;
  }

int assemblyPass(char* sourceName) {
  int  o;
  int  i;
  word value;
  char *pchar;
  char  err;
  FTOI ftoi;
  char line[1024];
  sourceFile[0] = fopen(sourceName, "r");
  if (sourceFile[0] == NULL) {
    printf("Error: Could not open: %s\n",sourceName);
    return -1;
    }
  lineNumber[0] = 0;
  fileNumber = 0;
  lineCount = 0;
  address = 0;
  outCount = 0;
  outAddress = 0;
  codeGenerated = 0;
  numDefines = 0;
  nests[0] = 'Y';
  numNests = 0;
  while (nextLine(line)) {
    strcpy(sourceLine, line);
    if (strncmp(line,".list",5) == 0) showList = -1;
    if (strncmp(line,".sym",4) == 0) showSymbols = -1;
    if (line[0] == '.') strcpy(line,"");
    pchar = strchr(line, ';');
    if (pchar != NULL) {
      *pchar = 0;
      while (strlen(line) > 0 && line[strlen(line)-1] <= ' ')
        line[strlen(line)-1] = 0;
      }
    parse(line);
    parse2();
    if (strlen(label) > 0 || strlen(opcode) > 0) {
      if (fileNumber == 0)
        sprintf(listLine,"[%05d] %04x:",lineNumber[fileNumber],address);
      else
        sprintf(listLine,"<%05d> %04x:",lineNumber[fileNumber],address);
      if (strlen(label) > 0) addLabel(label, address);
      instructionBytes = 0;
      if (strlen(opcode) > 0) {
        if (strcasecmp(opcode,"org") == 0) {
          if (outCount != 0) writeOutput();
          evaluate(arg1, &address);
          outAddress = address;
          }
        else if (strcasecmp(opcode,"extrn") == 0) {
          addExternal(arg1);
          }
        else if (strcasecmp(opcode,"public") == 0) {
          if (pass == 2) {
            i = findLabelNumber(arg1);
            if (i < 0) {
              printf("Error: Symbol not found: %s\n",arg1);
              errors++;
              }
            else {
              numPublics++;
              if (numPublics == 1)
                publics = (int*)malloc(sizeof(int));
              else
                publics = (int*)realloc(publics,sizeof(int)*numPublics);
              publics[numPublics-1] = i;
              }
            }
          }
        else if (strcasecmp(opcode,"ds") == 0) {
          if (outCount != 0) writeOutput();
          evaluate(arg1, &value);
          address += value;
          outAddress = address;
          }
        else if (strcasecmp(opcode,"db") == 0 ||
                 strcasecmp(opcode,".byte") == 0 ||
                 strcasecmp(opcode,"byte") == 0) {
          if (strlen(arg2) > 0) {
            strcat(arg1,",");
            strcat(arg1,arg2);
            }
          pchar = arg1;
          while (*pchar != 0) {
            if (*pchar == '"') {
              pchar++;
              while (*pchar != 0 && *pchar != '"') {
                output(*pchar);
                pchar++;
                }
              if (*pchar == '"') pchar++;
              }
            else {
              pchar = evaluate(pchar, &value);
              output(value & 0xff);
              }
            while (*pchar == ' ') pchar++;
            if (*pchar == ',') pchar++;
            while (*pchar == ' ') pchar++;
            }
          }
        else if (strcasecmp(opcode,"dw") == 0 ||
                 strcasecmp(opcode,"word") == 0 ||
                 strcasecmp(opcode,".word") == 0) {
          if (strlen(arg2) > 0) {
            strcat(arg1,",");
            strcat(arg1,arg2);
            }
          pchar = arg1;
          while (*pchar != 0) {
            pchar = evaluate(pchar, &value);
            output(value & 0xff);
            output((value >> 8) & 0xff);
            while (*pchar == ' ') pchar++;
            if (*pchar == ',') pchar++;
            while (*pchar == ' ') pchar++;
            }
          }
        else if (strcasecmp(opcode,"df") == 0) {
          ftoi.f = atof(arg1);
          output(ftoi.i & 0xff);
          output((ftoi.i >> 8) & 0xff);
          output((ftoi.i >> 16) & 0xff);
          output((ftoi.i >> 24) & 0xff);
          }
        else if (strcasecmp(opcode,"end") == 0) {
          if (outCount != 0) writeOutput();
          evaluate(arg1, &startAddress);
          }
        else if (strcasecmp(opcode,"equ") == 0 ||
                 strcasecmp(opcode,".equ") == 0) {
          evaluate(arg1, &value);
          if (strlen(label) > 0) setLabel(label, value);
          }
        else {
          o = lookupInstruction();
          if (o >= 0) {
            translateInstruction(o);
            }
          else {
            printf("Error: Invalid instruction\n");
            printf("   [%05d] %s\n",lineCount,sourceLine);
            errors++;
            }
          }
        }
      if (instructionBytes < 4) {
        while (strlen(listLine) < 25) strcat(listLine," ");
        strcat(listLine,"  ");
        strcat(listLine,sourceLine);
        }
      if (instructionBytes < 4 || ((instructionBytes % 4) != 0) && instructionBytes != 4)
        if (pass == 2) {
          if (showList != 0) printf("%s\n",listLine);
          if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
          }
      }
    }
  while (fileNumber > 0) {
    fclose(sourceFile[fileNumber--]);
    }
  fclose(sourceFile[0]);
  for (i=0; i<numDefines; i++) {
    free(defines[i]);
    free(defineValues[i]);
    }
  if (numDefines > 0) {
    free(defines);
    free(defineValues);
    }
  return errors;
  }

void assembleFile(char* sourceName) {
  int   i;
  char *pchar;
  char buffer[1024];
  strcpy(baseName, sourceName);
  pchar = strchr(baseName,'.');
  if (pchar != NULL) *pchar = 0;
  strcpy(listName, baseName);
  strcat(listName, ".lst");
  strcpy(outName, baseName);
  strcat(outName, ".prg");

  printf("Source file: %s\n",sourceName);
  errors = 0;
  numLabels = 0;
  numExternals = 0;
  numReferences = 0;
  numPublics = 0;
  startAddress = 0xffff;
  pass = 1;
  if (assemblyPass(sourceName) != 0) {
    printf("Errors encountered. Assembly aborted\n");
    }
  else {
    pass = 2;
    outFile = fopen(outName, "w");
    if (createListFile != 0) listFile = fopen(listName, "w");
    assemblyPass(sourceName);
    if (outBytes > 0) writeOutput();
    if (startAddress != 0xffff)
      fprintf(outFile,"@%04x\n",startAddress);
    if (numReferences > 0) {
      for (i=0; i<numReferences; i++) {
        fprintf(outFile,"?%s %04x\n",externals[references[i]],referenceAddress[i]);
        }
      }
    if (numPublics > 0) {
      for (i=0; i<numPublics; i++) {
        fprintf(outFile,"=%s %04x\n",labelNames[publics[i]],labelValues[publics[i]]);
        }
      }
    fclose(outFile);
    if (showSymbols != 0) {
      printf("\n");
      if (createListFile) fprintf(listFile,"\n");
      for (i=0; i<numLabels; i++) {
        sprintf(buffer,"%-16s %04x <%05d> \n",labelNames[i],labelValues[i],labelLine[i]);
        printf("%s",buffer);
        if (createListFile) fprintf(listFile,"%s",buffer);
        }
      printf("\n");
      if (createListFile) fprintf(listFile,"\n");
      }
    }
  printf("Lines assembled: %d\n",lineCount);
  printf("Errors         : %d\n",errors);
  printf("Code generated : %d\n",codeGenerated);
  if (createListFile != 0 && pass == 2) {
    fprintf(listFile,"Lines assembled: %d\n",lineCount);
    fprintf(listFile,"Errors         : %d\n",errors);
    fprintf(listFile,"Code generated : %d\n",codeGenerated);
    }
  if (createListFile != 0 && pass == 2) fclose(listFile);
  printf("\n");
  for (i=0; i<numLabels; i++) {
    free(labelNames[i]);
    }
  for (i=0; i<numExternals; i++)
    free(externals[i]);
  if (numExternals > 0) free(externals);
  if (numPublics > 0) free(publics);
  if (numReferences > 0) {
    free(references);
    free(referenceAddress);
    }
  if (numLabels > 0) {
    free(labelNames);
    free(labelValues);
    free(labelLine);
    }
  }

int main(int argc, char **argv) {
  int i;
  printf("Asm/65 1.0 by Michael H. Riley\n\n");
  initOpcodes();
  showList = 0;
  showSymbols = 0;
  createListFile = 0;
  numSourceFiles = 0;
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-l") == 0) showList = -1;
    else if (strcmp(argv[i],"-L") == 0) createListFile = -1;
    else if (strcmp(argv[i],"-s") == 0) showSymbols = -1;
    else {
      numSourceFiles++;
      if (numSourceFiles == 1)
        sourceNames = (char**)malloc(sizeof(char*));
      else
        sourceNames = (char**)realloc(sourceNames,sizeof(char*) * numSourceFiles);
      sourceNames[numSourceFiles-1] = (char*)malloc(strlen(argv[i])+1);
      strcpy(sourceNames[numSourceFiles-1], argv[i]);
      }
    }
  if (numSourceFiles == 0) {
    printf("No source file specified\n");
    exit(1);
    }
  for (i=0; i<numSourceFiles; i++)
    assembleFile(sourceNames[i]);
  return 0;
  }

