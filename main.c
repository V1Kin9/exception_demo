// See LICENSE for license details.
#include <stdio.h>
#include <stdlib.h>

#define	LOAD_EXCEPTION_DEMO
#define	STORE_EXCEPTION_DEMO
#define	INST_EXCEPTION_DEMO
#define ECALL_EXCEPTION_DEMO

#ifdef LOAD_EXCEPTION_DEMO
__attribute__((optimize("O0"))) void load_excep(void)
{
	uint32_t *ptr = (uint32_t *)0xdeadbee;
	uint32_t a = *ptr;
}
#endif


#ifdef STORE_EXCEPTION_DEMO
__attribute__((optimize("O0"))) void store_excep(void)
{
	uint32_t *ptr = NULL;
	*ptr = 0xdeadbee;
}
#endif

#ifdef INST_EXCEPTION_DEMO
__attribute__((optimize("O0"))) void inst_excep(void)
{
	asm volatile (".word 0x0");
}
#endif


int main(void)
{
#ifdef LOAD_EXCEPTION_DEMO
	load_excep();
#endif
#ifdef STORE_EXCEPTION_DEMO
	store_excep();
#endif
#ifdef INST_EXCEPTION_DEMO
	inst_excep();
#endif
#ifdef ECALL_EXCEPTION_DEMO
	asm volatile ("ecall");
#endif
    return 0;
}

