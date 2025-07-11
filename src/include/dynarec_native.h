#ifndef __DYNAREC_ARM_H_
#define __DYNAREC_ARM_H_

typedef struct dynablock_s dynablock_t;
typedef struct x64emu_s x64emu_t;
typedef struct instsize_s instsize_t;


//#define USE_CUSTOM_MEM
#ifdef USE_CUSTOM_MEM
#define dynaMalloc customMalloc
#define dynaCalloc customCalloc
#define dynaRealloc customRealloc
#define dynaFree customFree
#else
#define dynaMalloc box_malloc
#define dynaCalloc box_calloc
#define dynaRealloc box_realloc
#define dynaFree box_free
#endif

#define MAX_INSTS   32760

void addInst(instsize_t* insts, size_t* size, int x64_size, int native_size);

void CancelBlock64(int need_lock);
dynablock_t* FillBlock64(uintptr_t addr, int alternate, int is32bits, int inst_max, int is_new);

#endif //__DYNAREC_ARM_H_
