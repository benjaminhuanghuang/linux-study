```
  init/main.c
    stat_kernel()
      trap_init();
```

```
// arch/x86/kernel/traps.c

#ifdef CONFIG_X86_32
	set_system_trap_gate(SYSCALL_VECTOR, &system_call);
	set_bit(SYSCALL_VECTOR, used_vectors);
#endif

```

```
// arch/x86/kernel/entry_32.S

  ENTRY(system_call)
    syscallll_call

```

## system_call 伪代码

```
.macro INTERRUPT_RETURN  ; 中断返回
    iret
.endm
.macro SAVE_ALL          ; 保护现场
    ...
.macro RESTORE_INT_REGS
    ...
.endm

ENTRY(system_call)
    SAVE_ALL
syscall_call:
    call *sys_call_table(,%eax,4)
    movl %eax, PT_EAX(%esp)  ; store the return value
syscall exit:
    testl $_TIF_ALLWORK_MASK, %ecx # current->work
    jne syscall_exit_work
restore_all:
    RESTORE_INT_REGS
irq_return:
    INTERRUPT_RETURN      ; 到这里就算执行完了
ENDPROC(system_call)

syscall_exit_work:
    testl  $_TIF_WORK_SYSCALL_EXIT, %ecx
    jz work_pending
END(syscall_exit_work)

work_pending:
    testb $_TIF_NEED_RESCHED, %cl
    jz work_notifysig
work_resched:
    call schedule
    jz restore_all
work_notifysig:
    ...                  ; deal with pending signals
END(work_pending)
```
