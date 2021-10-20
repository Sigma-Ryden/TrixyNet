	.file	"main.cpp"
	.section	.text$_ZSt4coshf,"x"
	.linkonce discard
	.globl	__ZSt4coshf
	.def	__ZSt4coshf;	.scl	2;	.type	32;	.endef
__ZSt4coshf:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	_coshf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section	.text$_ZSt3expf,"x"
	.linkonce discard
	.globl	__ZSt3expf
	.def	__ZSt3expf;	.scl	2;	.type	32;	.endef
__ZSt3expf:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	_expf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.section	.text$_ZSt4fabsf,"x"
	.linkonce discard
	.globl	__ZSt4fabsf
	.def	__ZSt4fabsf;	.scl	2;	.type	32;	.endef
__ZSt4fabsf:
LFB32:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fabs
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE32:
	.section	.text$_ZSt3logf,"x"
	.linkonce discard
	.globl	__ZSt3logf
	.def	__ZSt3logf;	.scl	2;	.type	32;	.endef
__ZSt3logf:
LFB47:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	_logf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE47:
	.section	.text$_ZSt4tanhf,"x"
	.linkonce discard
	.globl	__ZSt4tanhf
	.def	__ZSt4tanhf;	.scl	2;	.type	32;	.endef
__ZSt4tanhf:
LFB70:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	_tanhf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE70:
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
LFB647:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE647:
	.section	.text$_ZdlPvS_,"x"
	.linkonce discard
	.globl	__ZdlPvS_
	.def	__ZdlPvS_;	.scl	2;	.type	32;	.endef
__ZdlPvS_:
LFB649:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE649:
	.section	.text$_ZStanSt13_Ios_FmtflagsS_,"x"
	.linkonce discard
	.globl	__ZStanSt13_Ios_FmtflagsS_
	.def	__ZStanSt13_Ios_FmtflagsS_;	.scl	2;	.type	32;	.endef
__ZStanSt13_Ios_FmtflagsS_:
LFB2368:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	andl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2368:
	.section	.text$_ZStorSt13_Ios_FmtflagsS_,"x"
	.linkonce discard
	.globl	__ZStorSt13_Ios_FmtflagsS_
	.def	__ZStorSt13_Ios_FmtflagsS_;	.scl	2;	.type	32;	.endef
__ZStorSt13_Ios_FmtflagsS_:
LFB2369:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	orl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2369:
	.section	.text$_ZStcoSt13_Ios_Fmtflags,"x"
	.linkonce discard
	.globl	__ZStcoSt13_Ios_Fmtflags
	.def	__ZStcoSt13_Ios_Fmtflags;	.scl	2;	.type	32;	.endef
__ZStcoSt13_Ios_Fmtflags:
LFB2371:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	notl	%eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2371:
	.section	.text$_ZStoRRSt13_Ios_FmtflagsS_,"x"
	.linkonce discard
	.globl	__ZStoRRSt13_Ios_FmtflagsS_
	.def	__ZStoRRSt13_Ios_FmtflagsS_;	.scl	2;	.type	32;	.endef
__ZStoRRSt13_Ios_FmtflagsS_:
LFB2372:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStorSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2372:
	.section	.text$_ZStaNRSt13_Ios_FmtflagsS_,"x"
	.linkonce discard
	.globl	__ZStaNRSt13_Ios_FmtflagsS_
	.def	__ZStaNRSt13_Ios_FmtflagsS_;	.scl	2;	.type	32;	.endef
__ZStaNRSt13_Ios_FmtflagsS_:
LFB2373:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2373:
	.section	.text$_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.def	__ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_;	.scl	2;	.type	32;	.endef
__ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_:
LFB2402:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStcoSt13_Ios_Fmtflags
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	addl	$12, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStaNRSt13_Ios_FmtflagsS_
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	addl	$12, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStoRRSt13_Ios_FmtflagsS_
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2402:
	.section	.text$_ZSt5fixedRSt8ios_base,"x"
	.linkonce discard
	.globl	__ZSt5fixedRSt8ios_base
	.def	__ZSt5fixedRSt8ios_base;	.scl	2;	.type	32;	.endef
__ZSt5fixedRSt8ios_base:
LFB2432:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$260, 4(%esp)
	movl	$4, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2432:
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
	.section	.text$_ZSt12setprecisioni,"x"
	.linkonce discard
	.globl	__ZSt12setprecisioni
	.def	__ZSt12setprecisioni;	.scl	2;	.type	32;	.endef
__ZSt12setprecisioni:
LFB3320:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3320:
	.section .rdata,"dr"
	.align 4
__ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.section	.text$_ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	.def	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_:
LFB4588:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4588:
	.section	.text$_ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	.def	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv:
LFB4592:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4592:
	.section	.text$_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	.def	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv:
LFB4594:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4594:
	.section	.text$_ZN5TimerC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5TimerC1Ev
	.def	__ZN5TimerC1Ev;	.scl	2;	.type	32;	.endef
__ZN5TimerC1Ev:
LFB4648:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, (%ebx)
	movl	%edx, 4(%ebx)
	nop
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4648:
	.section	.text$_ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	.def	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_:
LFB4652:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	subl	%eax, %ebx
	sbbl	%edx, %esi
	movl	%ebx, %eax
	movl	%esi, %edx
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	leal	-40(%ebp), %eax
	leal	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEC1IxvEERKT_
	subl	$4, %esp
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4652:
	.section	.text$_ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.def	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE:
LFB4651:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEEE16time_since_epochEv
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiIxSt5ratioILx1ELx1000000000EExS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4651:
	.section	.text$_ZNSt6chrono8durationIdSt5ratioILx1ELx1EEEC1IdvEERKT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6chrono8durationIdSt5ratioILx1ELx1EEEC1IdvEERKT_
	.def	__ZNSt6chrono8durationIdSt5ratioILx1ELx1EEEC1IdvEERKT_;	.scl	2;	.type	32;	.endef
__ZNSt6chrono8durationIdSt5ratioILx1ELx1EEEC1IdvEERKT_:
LFB4657:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	fldl	(%eax)
	movl	-4(%ebp), %eax
	fstpl	(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE4657:
	.section	.text$_ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILx1ELx1EEEES2_ILx1ELx1000000000EEdLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILx1ELx1EEEES2_ILx1ELx1000000000EEdLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE
	.def	__ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILx1ELx1EEEES2_ILx1ELx1000000000EEdLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILx1ELx1EEEES2_ILx1ELx1000000000EEdLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE:
LFB4654:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt6chrono8durationIxSt5ratioILx1ELx1000000000EEE5countEv
	movl	%eax, -40(%ebp)
	movl	%edx, -36(%ebp)
	fildq	-40(%ebp)
	fstpl	-32(%ebp)
	fldl	-32(%ebp)
	fldl	LC1
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	leal	-24(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6chrono8durationIdSt5ratioILx1ELx1EEEC1IdvEERKT_
	subl	$4, %esp
	fldl	-24(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4654:
	.section	.text$_ZNSt6chrono13duration_castINS_8durationIdSt5ratioILx1ELx1EEEExS2_ILx1ELx1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE,"x"
	.linkonce discard
	.globl	__ZNSt6chrono13duration_castINS_8durationIdSt5ratioILx1ELx1EEEExS2_ILx1ELx1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	.def	__ZNSt6chrono13duration_castINS_8durationIdSt5ratioILx1ELx1EEEExS2_ILx1ELx1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE;	.scl	2;	.type	32;	.endef
__ZNSt6chrono13duration_castINS_8durationIdSt5ratioILx1ELx1EEEExS2_ILx1ELx1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:
LFB4653:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILx1ELx1EEEES2_ILx1ELx1000000000EEdLb1ELb0EE6__castIxS5_EES4_RKNS1_IT_T0_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4653:
	.section	.text$_ZNKSt6chrono8durationIdSt5ratioILx1ELx1EEE5countEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6chrono8durationIdSt5ratioILx1ELx1EEE5countEv
	.def	__ZNKSt6chrono8durationIdSt5ratioILx1ELx1EEE5countEv;	.scl	2;	.type	32;	.endef
__ZNKSt6chrono8durationIdSt5ratioILx1ELx1EEE5countEv:
LFB4658:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	fldl	(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4658:
	.section	.text$_ZNK5Timer7elapsedEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5Timer7elapsedEv
	.def	__ZNK5Timer7elapsedEv;	.scl	2;	.type	32;	.endef
__ZNK5Timer7elapsedEv:
LFB4650:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %ebx
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	movl	%ebx, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chronomiINS_3_V212system_clockENS_8durationIxSt5ratioILx1ELx1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6chrono13duration_castINS_8durationIdSt5ratioILx1ELx1EEEExS2_ILx1ELx1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE
	fstpl	-32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6chrono8durationIdSt5ratioILx1ELx1EEE5countEv
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4650:
	.section .rdata,"dr"
LC2:
	.ascii " MByte(s) \0"
LC3:
	.ascii " KByte(s) \0"
LC4:
	.ascii " Byte(s)\12\0"
	.text
	.globl	__Z12network_sizeRK10CollectionIjE
	.def	__Z12network_sizeRK10CollectionIjE;	.scl	2;	.type	32;	.endef
__Z12network_sizeRK10CollectionIjE:
LFB4700:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$0, -12(%ebp)
	movl	$1, -16(%ebp)
L51:
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIjE4sizeEv
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L50
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIjEixEj
	subl	$4, %esp
	movl	(%eax), %eax
	leal	1(%eax), %ebx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIjEixEj
	subl	$4, %esp
	movl	(%eax), %eax
	imull	%ebx, %eax
	addl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
	jmp	L51
L50:
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIjE4sizeEv
	addl	%eax, -12(%ebp)
	sall	$3, -12(%ebp)
	movl	-12(%ebp), %eax
	andl	$1023, %eax
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	shrl	$10, %eax
	andl	$1023, %eax
	movl	%eax, %esi
	movl	-12(%ebp), %eax
	shrl	$20, %eax
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEj
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%esi, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEj
	subl	$4, %esp
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEj
	subl	$4, %esp
	movl	$LC4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4700:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB4702:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$16, %esp
	call	___main
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$6, (%esp)
	call	__ZSt12setprecisioni
	movl	%eax, %ebx
	movl	$__ZSt5fixedRSt8ios_base, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEPFRSt8ios_baseS0_E
	subl	$4, %esp
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision
	call	__Z5test9IfEvv
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE4702:
	.section	.text$_ZNK10CollectionIjE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIjE4sizeEv
	.def	__ZNK10CollectionIjE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIjE4sizeEv:
LFB5006:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5006:
	.section	.text$_ZNK10CollectionIjEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIjEixEj
	.def	__ZNK10CollectionIjEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIjEixEj:
LFB5007:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5007:
	.section .rdata,"dr"
LC5:
	.ascii "relu\0"
LC6:
	.ascii "softmax\0"
LC7:
	.ascii "CCE\0"
LC8:
	.ascii "Before train\12\0"
LC11:
	.ascii "After train\12\0"
LC12:
	.ascii "Normal accuracy: \0"
LC14:
	.ascii "Global accuracy: \0"
LC15:
	.ascii "Full accuracy: \0"
LC16:
	.ascii "Loss: \0"
	.section	.text$_Z5test9IfEvv,"x"
	.linkonce discard
	.globl	__Z5test9IfEvv
	.def	__Z5test9IfEvv;	.scl	2;	.type	32;	.endef
__Z5test9IfEvv:
LFB5011:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5011
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$352, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$_._58, -248(%ebp)
	movl	$5, -244(%ebp)
	leal	-288(%ebp), %eax
	leal	-248(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB0:
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE
	subl	$4, %esp
	leal	-288(%ebp), %eax
	movl	$__Z11random_realIfET_v, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE
	subl	$4, %esp
	movl	$LC5, (%esp)
	call	__ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc
	movl	%eax, -240(%ebp)
	movl	%edx, -236(%ebp)
	leal	-288(%ebp), %eax
	leal	-240(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE
	subl	$4, %esp
	movl	$LC6, (%esp)
	call	__ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc
	movl	%eax, -232(%ebp)
	movl	%edx, -228(%ebp)
	leal	-288(%ebp), %eax
	leal	-232(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE
	subl	$4, %esp
	movl	$LC7, (%esp)
	call	__ZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc
	movl	%eax, -224(%ebp)
	movl	%edx, -220(%ebp)
	leal	-288(%ebp), %eax
	leal	-224(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE
	subl	$4, %esp
	movl	$_._59, -160(%ebp)
	movl	$4, -156(%ebp)
	leal	-208(%ebp), %eax
	leal	-160(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._60, -152(%ebp)
	movl	$4, -148(%ebp)
	leal	-208(%ebp), %eax
	leal	8(%eax), %edx
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._61, -144(%ebp)
	movl	$4, -140(%ebp)
	leal	-208(%ebp), %eax
	leal	16(%eax), %edx
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._62, -136(%ebp)
	movl	$4, -132(%ebp)
	leal	-208(%ebp), %eax
	leal	24(%eax), %edx
	leal	-136(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._63, -128(%ebp)
	movl	$4, -124(%ebp)
	leal	-208(%ebp), %eax
	leal	32(%eax), %edx
	leal	-128(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._64, -120(%ebp)
	movl	$4, -116(%ebp)
	leal	-208(%ebp), %eax
	leal	40(%eax), %edx
	leal	-120(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
LEHE0:
	subl	$4, %esp
	leal	-208(%ebp), %eax
	movl	%eax, -216(%ebp)
	movl	$6, -212(%ebp)
	leal	-296(%ebp), %eax
	leal	-216(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB1:
	call	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E
LEHE1:
	subl	$4, %esp
	leal	-208(%ebp), %ebx
	addl	$48, %ebx
L60:
	leal	-208(%ebp), %eax
	cmpl	%eax, %ebx
	je	L59
	subl	$8, %ebx
	movl	%ebx, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L60
L59:
	movl	$_._65, -56(%ebp)
	movl	$3, -52(%ebp)
	leal	-104(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB2:
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._66, -48(%ebp)
	movl	$3, -44(%ebp)
	leal	-104(%ebp), %eax
	leal	8(%eax), %edx
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._67, -40(%ebp)
	movl	$3, -36(%ebp)
	leal	-104(%ebp), %eax
	leal	16(%eax), %edx
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._68, -32(%ebp)
	movl	$3, -28(%ebp)
	leal	-104(%ebp), %eax
	leal	24(%eax), %edx
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._69, -24(%ebp)
	movl	$3, -20(%ebp)
	leal	-104(%ebp), %eax
	leal	32(%eax), %edx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	subl	$4, %esp
	movl	$_._70, -16(%ebp)
	movl	$3, -12(%ebp)
	leal	-104(%ebp), %eax
	leal	40(%eax), %edx
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
LEHE2:
	subl	$4, %esp
	leal	-104(%ebp), %eax
	movl	%eax, -112(%ebp)
	movl	$6, -108(%ebp)
	leal	-304(%ebp), %eax
	leal	-112(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB3:
	call	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E
LEHE3:
	subl	$4, %esp
	leal	-104(%ebp), %ebx
	addl	$48, %ebx
L62:
	leal	-104(%ebp), %eax
	cmpl	%eax, %ebx
	je	L61
	subl	$8, %ebx
	movl	%ebx, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L62
L61:
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB4:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-304(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-296(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_
	leal	-312(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5TimerC1Ev
	leal	-288(%ebp), %eax
	movl	$100000, 12(%esp)
	flds	LC9
	fstps	8(%esp)
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj
	subl	$16, %esp
	leal	-288(%ebp), %eax
	movl	$100000, 12(%esp)
	flds	LC10
	fstps	8(%esp)
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj
	subl	$16, %esp
	leal	-288(%ebp), %eax
	movl	$2, 16(%esp)
	movl	$100000, 12(%esp)
	flds	LC10
	fstps	8(%esp)
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj
	subl	$20, %esp
	leal	-312(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5Timer7elapsedEv
	fstpl	(%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	$LC11, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-304(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-296(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_
	leal	-288(%ebp), %eax
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE8accuracyERKS5_INS3_IfEEESA_
	subl	$8, %esp
	fstpl	-320(%ebp)
	movl	$LC12, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-320(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	leal	-288(%ebp), %eax
	flds	LC13
	fstps	8(%esp)
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f
	subl	$12, %esp
	fstpl	-320(%ebp)
	movl	$LC14, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-320(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	leal	-288(%ebp), %eax
	flds	LC13
	fstps	8(%esp)
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f
	subl	$12, %esp
	fstpl	-320(%ebp)
	movl	$LC15, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-320(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	leal	-288(%ebp), %eax
	leal	-304(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-296(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_
	subl	$8, %esp
	fstpl	-320(%ebp)
	movl	$LC16, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-320(%ebp)
	fstpl	(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	jmp	L71
L69:
	movl	%eax, %esi
	leal	-208(%ebp), %ebx
	addl	$48, %ebx
L65:
	leal	-208(%ebp), %eax
	cmpl	%eax, %ebx
	je	L64
	subl	$8, %ebx
	movl	%ebx, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L65
L64:
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L70:
	movl	%eax, %esi
	leal	-104(%ebp), %ebx
	addl	$48, %ebx
L68:
	leal	-104(%ebp), %eax
	cmpl	%eax, %ebx
	je	L67
	subl	$8, %ebx
	movl	%ebx, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L68
L67:
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE4:
L71:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5011:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA5011:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5011-LLSDACSB5011
LLSDACSB5011:
	.uleb128 LEHB0-LFB5011
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB5011
	.uleb128 LEHE1-LEHB1
	.uleb128 L69-LFB5011
	.uleb128 0
	.uleb128 LEHB2-LFB5011
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB5011
	.uleb128 LEHE3-LEHB3
	.uleb128 L70-LFB5011
	.uleb128 0
	.uleb128 LEHB4-LFB5011
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
LLSDACSE5011:
	.section	.text$_Z5test9IfEvv,"x"
	.linkonce discard
	.section	.text$_ZNKSt16initializer_listIjE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIjE4sizeEv
	.def	__ZNKSt16initializer_listIjE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIjE4sizeEv:
LFB5148:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5148:
	.section	.text$_ZNKSt16initializer_listIjE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIjE5beginEv
	.def	__ZNKSt16initializer_listIjE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIjE5beginEv:
LFB5152:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5152:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE:
LFB5154:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	%ecx, -44(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIjE4sizeEv
	leal	-1(%eax), %edx
	movl	-44(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIjE4sizeEv
	leal	-1(%eax), %edx
	movl	-44(%ebp), %eax
	addl	$8, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIjE4sizeEv
	leal	-1(%eax), %edx
	movl	-44(%ebp), %eax
	addl	$16, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej
	subl	$4, %esp
	movl	-44(%ebp), %eax
	addl	$24, %eax
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIjE4sizeEv
	leal	-1(%eax), %edx
	movl	-44(%ebp), %eax
	movl	%edx, 32(%eax)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIjE5beginEv
	addl	$4, %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
L78:
	movl	-44(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L79
	movl	-12(%ebp), %eax
	movl	(%eax), %ecx
	movl	-12(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %edx
	leal	-36(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1Ejj
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	leal	-24(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	-44(%ebp), %eax
	leal	8(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$4, -12(%ebp)
	addl	$1, -16(%ebp)
	jmp	L78
L79:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5154:
	.globl	__ZZ11random_realIfET_vE6within
	.section	.data$_ZZ11random_realIfET_vE6within,"w"
	.linkonce same_size
	.align 4
__ZZ11random_realIfET_vE6within:
	.long	1000
	.section	.text$_Z11random_realIfET_v,"x"
	.linkonce discard
	.globl	__Z11random_realIfET_v
	.def	__Z11random_realIfET_v;	.scl	2;	.type	32;	.endef
__Z11random_realIfET_v:
LFB5155:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	_rand
	movl	%eax, %edx
	movl	__ZZ11random_realIfET_vE6within, %eax
	addl	%eax, %eax
	leal	1(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	__ZZ11random_realIfET_vE6within, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	fildl	-12(%ebp)
	movl	__ZZ11random_realIfET_vE6within, %eax
	movl	%eax, -12(%ebp)
	fildl	-12(%ebp)
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5155:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE:
LFB5156:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L84:
	movl	-28(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L85
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfE4fillEPFfvE
	subl	$4, %esp
	movl	-28(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfE4fillEPFfvE
	subl	$4, %esp
	addl	$1, -12(%ebp)
	jmp	L84
L85:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5156:
	.globl	__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data
	.section	.data$_ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data:
	.space 24
	.globl	__ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data
	.section	.data$_ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data,"w"
	.linkonce same_size
	.align 8
__ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data:
	.space 8
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev:
LFB5160:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5160:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB5161:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5161:
	.section .rdata,"dr"
LC17:
	.ascii "sigmoid\0"
LC18:
	.ascii "sigmoid_bce\0"
LC19:
	.ascii "tanh\0"
LC20:
	.ascii "elu\0"
LC21:
	.ascii "leaky_relu\0"
LC22:
	.ascii "selu\0"
LC23:
	.ascii "gelu\0"
LC24:
	.ascii "softsign\0"
LC25:
	.ascii "softplus\0"
LC26:
	.ascii "swish\0"
LC27:
	.ascii "unstable_softmax\0"
	.section	.text$_ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc,"x"
	.linkonce discard
	.globl	__ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc
	.def	__ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc;	.scl	2;	.type	32;	.endef
__ZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc:
LFB5157:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$100, %esp
	.cfi_offset 3, -12
	movzbl	__ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %eax
	testb	%al, %al
	sete	%al
	testb	%al, %al
	je	L89
	movl	$__ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L89
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	movl	$__ZGVZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, (%esp)
	call	___cxa_guard_release
	movl	$___tcf_0, (%esp)
	call	_atexit
L89:
	movl	$LC17, -80(%ebp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC18, -76(%ebp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC19, -72(%ebp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC5, -68(%ebp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC20, -64(%ebp)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC21, -60(%ebp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC22, -56(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC23, -52(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC24, -48(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC25, -44(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC26, -40(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC27, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	movl	$LC6, -32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, (%eax)
	movl	$__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_, 4(%eax)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	subl	$4, %esp
	movl	%eax, -84(%ebp)
	movl	$__ZZN5trixy3getINS_8function10ActivationEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE15activation_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	movl	%eax, -28(%ebp)
	leal	-84(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_
	subl	$4, %esp
	testb	%al, %al
	je	L90
	leal	-84(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv
	movl	8(%eax), %ebx
	leal	-84(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv
	movl	4(%eax), %edx
	leal	-24(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	subl	$8, %esp
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	jmp	L92
L90:
	leal	-16(%ebp), %eax
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	subl	$8, %esp
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
L92:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5157:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE:
LFB5162:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L95:
	movl	-28(%ebp), %eax
	movl	32(%eax), %eax
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	jbe	L96
	movl	-28(%ebp), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	addl	$1, -12(%ebp)
	jmp	L95
L96:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5162:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE:
LFB5163:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	32(%eax), %eax
	leal	-1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5163:
	.globl	__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data
	.section	.data$_ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data:
	.space 24
	.globl	__ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data
	.section	.data$_ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data,"w"
	.linkonce same_size
	.align 8
__ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data:
	.space 8
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev:
LFB5167:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5167:
	.text
	.def	___tcf_1;	.scl	3;	.type	32;	.endef
___tcf_1:
LFB5168:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEED1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5168:
	.section .rdata,"dr"
LC28:
	.ascii "MSE\0"
LC29:
	.ascii "MAE\0"
LC30:
	.ascii "MSLE\0"
LC31:
	.ascii "*CCE\0"
LC32:
	.ascii "*BCE\0"
LC33:
	.ascii "BCE\0"
LC34:
	.ascii "LC\0"
	.section	.text$_ZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc,"x"
	.linkonce discard
	.globl	__ZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc
	.def	__ZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc;	.scl	2;	.type	32;	.endef
__ZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKc:
LFB5164:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	movzbl	__ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %eax
	testb	%al, %al
	sete	%al
	testb	%al, %al
	je	L101
	movl	$__ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L101
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	movl	$__ZGVZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, (%esp)
	call	___cxa_guard_release
	movl	$___tcf_1, (%esp)
	call	_atexit
L101:
	movl	$LC28, -60(%ebp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC29, -56(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC30, -52(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC31, -48(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC7, -44(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC32, -40(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC33, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	movl	$LC34, -32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	subl	$4, %esp
	movl	$__ZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_, (%eax)
	movl	$__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_, 4(%eax)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	subl	$4, %esp
	movl	%eax, -64(%ebp)
	movl	$__ZZN5trixy3getINS_8function4LossEN5lique6VectorEfJELi0EEET_IT0_T1_JDpT2_EEPKcE9loss_data, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	movl	%eax, -28(%ebp)
	leal	-64(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_
	subl	$4, %esp
	testb	%al, %al
	je	L102
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv
	movl	8(%eax), %ebx
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv
	movl	4(%eax), %edx
	leal	-24(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E
	subl	$8, %esp
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	jmp	L104
L102:
	leal	-16(%ebp), %eax
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E
	subl	$8, %esp
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
L104:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5164:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE:
LFB5169:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, 24(%ecx)
	movl	%edx, 28(%ecx)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5169:
	.section	.text$_ZNKSt16initializer_listIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE4sizeEv
	.def	__ZNKSt16initializer_listIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE4sizeEv:
LFB5171:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5171:
	.section	.text$_ZNKSt16initializer_listIfE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE5beginEv
	.def	__ZNKSt16initializer_listIfE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE5beginEv:
LFB5172:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5172:
	.section	.text$_ZNKSt16initializer_listIfE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE3endEv
	.def	__ZNKSt16initializer_listIfE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE3endEv:
LFB5173:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIfE5beginEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIfE4sizeEv
	sall	$2, %eax
	addl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5173:
	.section	.text$_ZN5lique6VectorIfEC1ERKSt16initializer_listIfE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	.def	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE:
LFB5175:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	%ecx, -44(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIfE4sizeEv
	cmpl	$536870911, %eax
	ja	L113
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIfE4sizeEv
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIfE5beginEv
	movl	%eax, -16(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIfE3endEv
	movl	%eax, -24(%ebp)
	jmp	L116
L113:
	call	___cxa_throw_bad_array_new_length
L116:
	movl	-16(%ebp), %eax
	cmpl	-24(%ebp), %eax
	je	L117
	movl	-16(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-28(%ebp), %eax
	flds	(%eax)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	addl	$4, -16(%ebp)
	jmp	L116
L117:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5175:
	.section	.text$_ZN5lique6VectorIfED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfED1Ev
	.def	__ZN5lique6VectorIfED1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfED1Ev:
LFB5178:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L120
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L120:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5178:
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv:
LFB5180:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5180:
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv:
LFB5181:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5181:
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv:
LFB5182:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv
	sall	$3, %eax
	addl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5182:
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E
	.def	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E:
LFB5184:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -60(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv
	movl	%eax, %ebx
	cmpl	$268435455, %ebx
	ja	L128
	leal	0(,%ebx,8), %eax
	addl	$4, %eax
	jmp	L129
L128:
	movl	$-1, %eax
L129:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %esi
	movl	%ebx, (%esi)
	leal	4(%esi), %eax
	leal	-1(%ebx), %edx
	movl	%edx, %ebx
	movl	%eax, %edi
L131:
	testl	%ebx, %ebx
	js	L130
	movl	%edi, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	addl	$8, %edi
	subl	$1, %ebx
	jmp	L131
L130:
	leal	4(%esi), %edx
	movl	-60(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	$0, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv
	movl	%eax, -32(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv
	movl	%eax, -40(%ebp)
L133:
	movl	-32(%ebp), %eax
	cmpl	-40(%ebp), %eax
	je	L134
	movl	-32(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSERKS1_
	subl	$4, %esp
	addl	$1, -28(%ebp)
	addl	$8, -32(%ebp)
	jmp	L133
L134:
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5184:
	.section .rdata,"dr"
LC35:
	.ascii "<\0"
LC36:
	.ascii "> \0"
LC37:
	.ascii " : \0"
	.section	.text$_Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_,"x"
	.linkonce discard
	.globl	__Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_
	.def	__Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_;	.scl	2;	.type	32;	.endef
__Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_:
LFB5185:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5185
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$0, -12(%ebp)
L137:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L140
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB5:
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE
LEHE5:
	subl	$8, %esp
	movl	$LC35, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB6:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEj
	subl	$4, %esp
	movl	$LC36, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE
	movl	$LC37, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE
	movl	$10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
LEHE6:
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -12(%ebp)
	jmp	L137
L139:
	movl	%eax, %ebx
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB7:
	call	__Unwind_Resume
LEHE7:
L140:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5185:
	.section	.gcc_except_table,"w"
LLSDA5185:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5185-LLSDACSB5185
LLSDACSB5185:
	.uleb128 LEHB5-LFB5185
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB5185
	.uleb128 LEHE6-LEHB6
	.uleb128 L139-LFB5185
	.uleb128 0
	.uleb128 LEHB7-LFB5185
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE5185:
	.section	.text$_Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj:
LFB5186:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5186
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$224, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -204(%ebp)
	movl	-204(%ebp), %eax
	movl	32(%eax), %edx
	leal	-148(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB8:
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-204(%ebp), %eax
	movl	32(%eax), %eax
	leal	1(%eax), %edx
	leal	-156(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-204(%ebp), %eax
	movl	32(%eax), %edx
	leal	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-204(%ebp), %eax
	movl	32(%eax), %edx
	leal	-172(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	-204(%ebp), %eax
	movl	32(%eax), %edx
	leal	-180(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
LEHE8:
	subl	$4, %esp
	leal	-188(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -28(%ebp)
	movl	$0, -12(%ebp)
L149:
	movl	-12(%ebp), %eax
	cmpl	20(%ebp), %eax
	jnb	L142
	call	_rand
	movl	$0, %edx
	divl	-28(%ebp)
	movl	%edx, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-156(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
LEHB9:
	call	__ZN5lique6VectorIfEaSERKS1_
	subl	$4, %esp
	movl	$0, -16(%ebp)
L144:
	movl	-204(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L143
	movl	-204(%ebp), %eax
	leal	8(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	-204(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	leal	-156(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-204(%ebp), %eax
	leal	36(%eax), %edx
	leal	-132(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
LEHE9:
	subl	$16, %esp
	leal	-140(%ebp), %eax
	movl	%ebx, 4(%esp)
	leal	-132(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB10:
	call	__ZNK5lique6VectorIfEplERKS1_
LEHE10:
	subl	$8, %esp
	leal	-148(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-140(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-132(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-204(%ebp), %eax
	leal	16(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	(%eax), %ebx
	leal	-148(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-124(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB11:
	call	*%ebx
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	leal	-156(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-124(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-204(%ebp), %eax
	leal	16(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	4(%eax), %ebx
	leal	-148(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-116(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-164(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-116(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -16(%ebp)
	jmp	L144
L143:
	movl	-204(%ebp), %eax
	movl	28(%eax), %ebx
	movl	-204(%ebp), %eax
	movl	32(%eax), %edx
	leal	-156(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-108(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-188(%ebp), %eax
	leal	-108(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-204(%ebp), %eax
	movl	32(%eax), %eax
	subl	$1, %eax
	movl	%eax, -20(%ebp)
L146:
	cmpl	$0, -20(%ebp)
	je	L145
	leal	-164(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-100(%ebp), %eax
	leal	-188(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-180(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-100(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-156(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-180(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-204(%ebp), %eax
	leal	36(%eax), %edx
	leal	-92(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-172(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-92(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	-204(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-180(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-204(%ebp), %eax
	leal	36(%eax), %edx
	leal	-80(%ebp), %eax
	movl	$1, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
	subl	$16, %esp
	leal	-188(%ebp), %eax
	leal	-80(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-80(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	subl	$1, -20(%ebp)
	jmp	L146
L145:
	leal	-164(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-72(%ebp), %eax
	leal	-188(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-180(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-72(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-156(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-180(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-204(%ebp), %eax
	leal	36(%eax), %edx
	leal	-64(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-172(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	$0, -24(%ebp)
L148:
	movl	-204(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-24(%ebp), %eax
	jbe	L147
	leal	-172(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-52(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4joinEf
	subl	$8, %esp
	movl	-204(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEmIERKS1_
	subl	$4, %esp
	leal	-52(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	leal	-180(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-40(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4joinEf
LEHE11:
	subl	$8, %esp
	movl	-204(%ebp), %eax
	leal	8(%eax), %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEmIERKS1_
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -24(%ebp)
	jmp	L148
L147:
	addl	$1, -12(%ebp)
	jmp	L149
L142:
	leal	-188(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L154
L153:
	movl	%eax, %ebx
	leal	-132(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L151
L152:
	movl	%eax, %ebx
L151:
	leal	-188(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB12:
	call	__Unwind_Resume
LEHE12:
L154:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5186:
	.section	.gcc_except_table,"w"
LLSDA5186:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5186-LLSDACSB5186
LLSDACSB5186:
	.uleb128 LEHB8-LFB5186
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB5186
	.uleb128 LEHE9-LEHB9
	.uleb128 L152-LFB5186
	.uleb128 0
	.uleb128 LEHB10-LFB5186
	.uleb128 LEHE10-LEHB10
	.uleb128 L153-LFB5186
	.uleb128 0
	.uleb128 LEHB11-LFB5186
	.uleb128 LEHE11-LEHB11
	.uleb128 L152-LFB5186
	.uleb128 0
	.uleb128 LEHB12-LFB5186
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE5186:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj:
LFB5187:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5187
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$240, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -220(%ebp)
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-156(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB13:
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	leal	1(%eax), %edx
	leal	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-172(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-180(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-188(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-196(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-204(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L157:
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L156
	movl	-220(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE
	subl	$4, %esp
	movl	-220(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %ebx
	leal	-204(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfE6resizeEj
LEHE13:
	subl	$4, %esp
	addl	$1, -12(%ebp)
	jmp	L157
L156:
	leal	-212(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -232(%ebp)
	movl	$0, -228(%ebp)
	fildq	-232(%ebp)
	fstps	-224(%ebp)
	flds	-224(%ebp)
	flds	16(%ebp)
	fdivp	%st, %st(1)
	fstps	16(%ebp)
	movl	$0, -16(%ebp)
L171:
	movl	-16(%ebp), %eax
	cmpl	20(%ebp), %eax
	jnb	L158
	movl	$0, -20(%ebp)
L160:
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-20(%ebp), %eax
	jbe	L159
	leal	-196(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	fldz
	fstps	(%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE4fillEf
	subl	$4, %esp
	leal	-204(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	fldz
	fstps	(%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfE4fillEf
	subl	$4, %esp
	addl	$1, -20(%ebp)
	jmp	L160
L159:
	movl	$0, -24(%ebp)
L168:
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L161
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-164(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
LEHB14:
	call	__ZN5lique6VectorIfEaSERKS1_
	subl	$4, %esp
	movl	$0, -28(%ebp)
L163:
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-28(%ebp), %eax
	jbe	L162
	movl	-220(%ebp), %eax
	leal	8(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	-220(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	leal	-164(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-220(%ebp), %eax
	leal	36(%eax), %edx
	leal	-140(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
LEHE14:
	subl	$16, %esp
	leal	-148(%ebp), %eax
	movl	%ebx, 4(%esp)
	leal	-140(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB15:
	call	__ZNK5lique6VectorIfEplERKS1_
LEHE15:
	subl	$8, %esp
	leal	-156(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-148(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-148(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-140(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-220(%ebp), %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	(%eax), %ebx
	leal	-156(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-132(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB16:
	call	*%ebx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	leal	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-132(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-220(%ebp), %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	4(%eax), %ebx
	leal	-156(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-124(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-172(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-124(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -28(%ebp)
	jmp	L163
L162:
	movl	-220(%ebp), %eax
	movl	28(%eax), %ebx
	movl	-220(%ebp), %eax
	movl	32(%eax), %edx
	leal	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-116(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-212(%ebp), %eax
	leal	-116(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-116(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	subl	$1, %eax
	movl	%eax, -32(%ebp)
L165:
	cmpl	$0, -32(%ebp)
	je	L164
	leal	-172(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-108(%ebp), %eax
	leal	-212(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-188(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-164(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-188(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-220(%ebp), %eax
	leal	36(%eax), %edx
	leal	-100(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-180(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-100(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	-220(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-188(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-220(%ebp), %eax
	leal	36(%eax), %edx
	leal	-88(%ebp), %eax
	movl	$1, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
	subl	$16, %esp
	leal	-212(%ebp), %eax
	leal	-88(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-88(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	subl	$1, -32(%ebp)
	jmp	L165
L164:
	leal	-172(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-80(%ebp), %eax
	leal	-212(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-188(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-80(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-164(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-188(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-220(%ebp), %eax
	leal	36(%eax), %edx
	leal	-72(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-180(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-72(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	$0, -36(%ebp)
L167:
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-36(%ebp), %eax
	jbe	L166
	leal	-180(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEpLERKS1_
	subl	$4, %esp
	leal	-188(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-204(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEpLERKS1_
	subl	$4, %esp
	addl	$1, -36(%ebp)
	jmp	L167
L166:
	addl	$1, -24(%ebp)
	jmp	L168
L161:
	movl	$0, -40(%ebp)
L170:
	movl	-220(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-40(%ebp), %eax
	jbe	L169
	leal	-196(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-60(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4joinEf
	subl	$8, %esp
	movl	-220(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEmIERKS1_
	subl	$4, %esp
	leal	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	leal	-204(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-48(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4joinEf
LEHE16:
	subl	$8, %esp
	movl	-220(%ebp), %eax
	leal	8(%eax), %edx
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEmIERKS1_
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -40(%ebp)
	jmp	L170
L169:
	addl	$1, -16(%ebp)
	jmp	L171
L158:
	leal	-212(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L176
L175:
	movl	%eax, %ebx
	leal	-140(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L173
L174:
	movl	%eax, %ebx
L173:
	leal	-212(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB17:
	call	__Unwind_Resume
LEHE17:
L176:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5187:
	.section	.gcc_except_table,"w"
LLSDA5187:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5187-LLSDACSB5187
LLSDACSB5187:
	.uleb128 LEHB13-LFB5187
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB5187
	.uleb128 LEHE14-LEHB14
	.uleb128 L174-LFB5187
	.uleb128 0
	.uleb128 LEHB15-LFB5187
	.uleb128 LEHE15-LEHB15
	.uleb128 L175-LFB5187
	.uleb128 0
	.uleb128 LEHB16-LFB5187
	.uleb128 LEHE16-LEHB16
	.uleb128 L174-LFB5187
	.uleb128 0
	.uleb128 LEHB17-LFB5187
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE5187:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj:
LFB5188:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5188
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$256, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -236(%ebp)
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB18:
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	leal	1(%eax), %edx
	leal	-172(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-180(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-188(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-196(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-204(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	subl	$4, %esp
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-212(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L179:
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L178
	movl	-236(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ebx
	leal	-204(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE
	subl	$4, %esp
	movl	-236(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %ebx
	leal	-212(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfE6resizeEj
LEHE18:
	subl	$4, %esp
	addl	$1, -12(%ebp)
	jmp	L179
L178:
	leal	-220(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	movl	24(%ebp), %eax
	movl	$0, %edx
	movl	%eax, -248(%ebp)
	movl	%edx, -244(%ebp)
	fildq	-248(%ebp)
	fstps	-240(%ebp)
	flds	-240(%ebp)
	flds	16(%ebp)
	fdivp	%st, %st(1)
	fstps	16(%ebp)
	movl	$0, -20(%ebp)
L192:
	movl	-20(%ebp), %eax
	cmpl	20(%ebp), %eax
	jnb	L180
	call	_rand
	movl	%eax, %ebx
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	$0, %edx
	divl	24(%ebp)
	movl	%eax, %ecx
	movl	%ebx, %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, -44(%ebp)
	movl	-44(%ebp), %eax
	imull	24(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -48(%ebp)
	movl	$0, -24(%ebp)
L182:
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-24(%ebp), %eax
	jbe	L181
	leal	-204(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	fldz
	fstps	(%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE4fillEf
	subl	$4, %esp
	leal	-212(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	fldz
	fstps	(%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfE4fillEf
	subl	$4, %esp
	addl	$1, -24(%ebp)
	jmp	L182
L181:
	movl	-16(%ebp), %eax
	cmpl	-48(%ebp), %eax
	jnb	L183
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-172(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
LEHB19:
	call	__ZN5lique6VectorIfEaSERKS1_
	subl	$4, %esp
	movl	$0, -28(%ebp)
L185:
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-28(%ebp), %eax
	jbe	L184
	movl	-236(%ebp), %eax
	leal	8(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	-236(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	leal	-172(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-236(%ebp), %eax
	leal	36(%eax), %edx
	leal	-148(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
LEHE19:
	subl	$16, %esp
	leal	-156(%ebp), %eax
	movl	%ebx, 4(%esp)
	leal	-148(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB20:
	call	__ZNK5lique6VectorIfEplERKS1_
LEHE20:
	subl	$8, %esp
	leal	-164(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-156(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-148(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-236(%ebp), %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	(%eax), %ebx
	leal	-164(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-140(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB21:
	call	*%ebx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	leal	-172(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-140(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-236(%ebp), %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	4(%eax), %ebx
	leal	-164(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-132(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-180(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-132(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-132(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -28(%ebp)
	jmp	L185
L184:
	movl	-236(%ebp), %eax
	movl	28(%eax), %ebx
	movl	-236(%ebp), %eax
	movl	32(%eax), %edx
	leal	-172(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-124(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	leal	-220(%ebp), %eax
	leal	-124(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-124(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	subl	$1, %eax
	movl	%eax, -32(%ebp)
L187:
	cmpl	$0, -32(%ebp)
	je	L186
	leal	-180(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-116(%ebp), %eax
	leal	-220(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-196(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-116(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-172(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-236(%ebp), %eax
	leal	36(%eax), %edx
	leal	-108(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-188(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	-236(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-236(%ebp), %eax
	leal	36(%eax), %edx
	leal	-96(%ebp), %eax
	movl	$1, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
	subl	$16, %esp
	leal	-220(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-96(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	subl	$1, -32(%ebp)
	jmp	L187
L186:
	leal	-180(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	leal	-88(%ebp), %eax
	leal	-220(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE8multiplyERKS1_
	subl	$8, %esp
	leal	-196(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-88(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-172(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-196(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	movl	-236(%ebp), %eax
	leal	36(%eax), %edx
	leal	-80(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	subl	$16, %esp
	leal	-188(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEaSEOS1_
	subl	$4, %esp
	leal	-80(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	$0, -36(%ebp)
L189:
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-36(%ebp), %eax
	jbe	L188
	leal	-188(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-204(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEpLERKS1_
	subl	$4, %esp
	leal	-196(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ebx
	leal	-212(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEpLERKS1_
	subl	$4, %esp
	addl	$1, -36(%ebp)
	jmp	L189
L188:
	addl	$1, -16(%ebp)
	jmp	L181
L183:
	movl	$0, -40(%ebp)
L191:
	movl	-236(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-40(%ebp), %eax
	jbe	L190
	leal	-204(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-68(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4joinEf
	subl	$8, %esp
	movl	-236(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfEmIERKS1_
	subl	$4, %esp
	leal	-68(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	leal	-212(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-56(%ebp), %eax
	flds	16(%ebp)
	fstps	4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4joinEf
LEHE21:
	subl	$8, %esp
	movl	-236(%ebp), %eax
	leal	8(%eax), %edx
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEmIERKS1_
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -40(%ebp)
	jmp	L191
L190:
	addl	$1, -20(%ebp)
	jmp	L192
L180:
	leal	-220(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L197
L196:
	movl	%eax, %ebx
	leal	-148(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L194
L195:
	movl	%eax, %ebx
L194:
	leal	-220(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB22:
	call	__Unwind_Resume
LEHE22:
L197:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$20
	.cfi_endproc
LFE5188:
	.section	.gcc_except_table,"w"
LLSDA5188:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5188-LLSDACSB5188
LLSDACSB5188:
	.uleb128 LEHB18-LFB5188
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB19-LFB5188
	.uleb128 LEHE19-LEHB19
	.uleb128 L195-LFB5188
	.uleb128 0
	.uleb128 LEHB20-LFB5188
	.uleb128 LEHE20-LEHB20
	.uleb128 L196-LFB5188
	.uleb128 0
	.uleb128 LEHB21-LFB5188
	.uleb128 LEHE21-LEHB21
	.uleb128 L195-LFB5188
	.uleb128 0
	.uleb128 LEHB22-LFB5188
	.uleb128 LEHE22-LEHB22
	.uleb128 0
	.uleb128 0
LLSDACSE5188:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj,"x"
	.linkonce discard
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE8accuracyERKS5_INS3_IfEEESA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE8accuracyERKS5_INS3_IfEEESA_
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE8accuracyERKS5_INS3_IfEEESA_;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE8accuracyERKS5_INS3_IfEEESA_:
LFB5191:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$104, %esp
	movl	%ecx, -60(%ebp)
	leal	-52(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -40(%ebp)
	movl	12(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, -44(%ebp)
	fldz
	fstpl	-16(%ebp)
	movl	$0, -28(%ebp)
L207:
	movl	-28(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jnb	L199
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -32(%ebp)
L202:
	movl	-32(%ebp), %eax
	cmpl	-44(%ebp), %eax
	jnb	L200
	leal	-52(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-80(%ebp)
	leal	-52(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	-80(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	L201
	movl	-32(%ebp), %eax
	movl	%eax, -20(%ebp)
L201:
	addl	$1, -32(%ebp)
	jmp	L202
L200:
	movl	$0, -36(%ebp)
L205:
	movl	-36(%ebp), %eax
	cmpl	-44(%ebp), %eax
	jnb	L203
	movl	12(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-80(%ebp)
	movl	12(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	-80(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	L204
	movl	-36(%ebp), %eax
	movl	%eax, -24(%ebp)
L204:
	addl	$1, -36(%ebp)
	jmp	L205
L203:
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jne	L206
	fldl	-16(%ebp)
	fld1
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
L206:
	addl	$1, -28(%ebp)
	jmp	L207
L199:
	movl	-40(%ebp), %eax
	movl	$0, %edx
	movl	%eax, -80(%ebp)
	movl	%edx, -76(%ebp)
	fildq	-80(%ebp)
	fstpl	-72(%ebp)
	fldl	-72(%ebp)
	fldl	-16(%ebp)
	fdivp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5191:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f:
LFB5192:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	%ecx, -44(%ebp)
	leal	-40(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -28(%ebp)
	movl	12(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, -32(%ebp)
	fldz
	fstpl	-16(%ebp)
	movl	$0, -20(%ebp)
L214:
	movl	-20(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jnb	L210
	movl	$0, -24(%ebp)
L213:
	movl	-24(%ebp), %eax
	cmpl	-32(%ebp), %eax
	jnb	L211
	leal	-40(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-64(%ebp)
	movl	12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-64(%ebp)
	fstps	(%esp)
	call	__ZSt4fabsf
	flds	16(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	L212
	fldl	-16(%ebp)
	fld1
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
L212:
	addl	$1, -24(%ebp)
	jmp	L213
L211:
	addl	$1, -20(%ebp)
	jmp	L214
L210:
	movl	-28(%ebp), %eax
	imull	-32(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	$0, -60(%ebp)
	fildq	-64(%ebp)
	fstpl	-56(%ebp)
	fldl	-56(%ebp)
	fldl	-16(%ebp)
	fdivp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5192:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f:
LFB5193:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$104, %esp
	movl	%ecx, -60(%ebp)
	leal	-48(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	subl	$8, %esp
	leal	-48(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -36(%ebp)
	movl	12(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, -40(%ebp)
	fldz
	fstpl	-16(%ebp)
	movl	$0, -24(%ebp)
L222:
	movl	-24(%ebp), %eax
	cmpl	-36(%ebp), %eax
	jnb	L217
	movb	$1, -17(%ebp)
	movl	$0, -28(%ebp)
L220:
	movl	-28(%ebp), %eax
	cmpl	-40(%ebp), %eax
	jnb	L218
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-80(%ebp)
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-80(%ebp)
	fstps	(%esp)
	call	__ZSt4fabsf
	flds	16(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	L219
	movb	$0, -17(%ebp)
	jmp	L218
L219:
	addl	$1, -28(%ebp)
	jmp	L220
L218:
	cmpb	$0, -17(%ebp)
	je	L221
	fldl	-16(%ebp)
	fld1
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
L221:
	addl	$1, -24(%ebp)
	jmp	L222
L217:
	movl	-36(%ebp), %eax
	movl	$0, %edx
	movl	%eax, -80(%ebp)
	movl	%edx, -76(%ebp)
	fildq	-80(%ebp)
	fstpl	-72(%ebp)
	fldl	-72(%ebp)
	fldl	-16(%ebp)
	fdivp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5193:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_:
LFB5194:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -44(%ebp)
	leal	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	subl	$8, %esp
	fldz
	fstpl	-16(%ebp)
	movl	$0, -20(%ebp)
L226:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L225
	movl	-44(%ebp), %eax
	movl	24(%eax), %ebx
	leal	-28(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	*%ebx
	fldl	-16(%ebp)
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	addl	$1, -20(%ebp)
	jmp	L226
L225:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, -64(%ebp)
	movl	$0, -60(%ebp)
	fildq	-64(%ebp)
	fstpl	-56(%ebp)
	fldl	-56(%ebp)
	fldl	-16(%ebp)
	fdivp	%st, %st(1)
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5194:
	.section	.text$_ZN10CollectionIN5lique6MatrixIfEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	.def	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6MatrixIfEEEC1Ej:
LFB5244:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %ebx
	cmpl	$178956970, %ebx
	ja	L229
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$2, %eax
	addl	$4, %eax
	jmp	L230
L229:
	movl	$-1, %eax
L230:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %esi
	movl	%ebx, (%esi)
	leal	4(%esi), %eax
	leal	-1(%ebx), %edx
	movl	%edx, %ebx
	movl	%eax, %edi
L232:
	testl	%ebx, %ebx
	js	L231
	movl	%edi, %ecx
	call	__ZN5lique6MatrixIfEC1Ev
	addl	$12, %edi
	subl	$1, %ebx
	jmp	L232
L231:
	leal	4(%esi), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	addl	$44, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5244:
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	.def	__ZN10CollectionIN5lique6VectorIfEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEC1Ej:
LFB5247:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %ebx
	cmpl	$268435455, %ebx
	ja	L234
	leal	0(,%ebx,8), %eax
	addl	$4, %eax
	jmp	L235
L234:
	movl	$-1, %eax
L235:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %esi
	movl	%ebx, (%esi)
	leal	4(%esi), %eax
	leal	-1(%ebx), %edx
	movl	%edx, %ebx
	movl	%eax, %edi
L237:
	testl	%ebx, %ebx
	js	L236
	movl	%edi, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	addl	$8, %edi
	subl	$1, %ebx
	jmp	L237
L236:
	leal	4(%esi), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	addl	$44, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5247:
	.section	.text$_ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej
	.def	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej:
LFB5250:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %ebx
	cmpl	$268435455, %ebx
	ja	L239
	leal	0(,%ebx,8), %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edi
	movl	%edi, %edx
	leal	-1(%ebx), %eax
	movl	%eax, %ebx
	movl	%edx, %esi
	jmp	L242
L239:
	call	___cxa_throw_bad_array_new_length
L242:
	testl	%ebx, %ebx
	js	L241
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%esi, %ecx
	call	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	subl	$8, %esp
	addl	$8, %esi
	subl	$1, %ebx
	jmp	L242
L241:
	movl	-28(%ebp), %eax
	movl	%edi, (%eax)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5250:
	.section	.text$_ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E
	.def	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E;	.scl	2;	.type	32;	.endef
__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E:
LFB5253:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5253:
	.section	.text$_ZN10CollectionIN5lique6MatrixIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	.def	__ZN10CollectionIN5lique6MatrixIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6MatrixIfEEEixEj:
LFB5254:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5254:
	.section	.text$_ZN5lique6MatrixIfEC1Ejj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1Ejj
	.def	__ZN5lique6MatrixIfEC1Ejj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1Ejj:
LFB5257:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	cmpl	$536870911, %eax
	ja	L247
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfE5ShapeC1Ejj
	subl	$8, %esp
	movl	$0, -12(%ebp)
	jmp	L252
L247:
	call	___cxa_throw_bad_array_new_length
L252:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L254
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L250
	sall	$2, %eax
	jmp	L253
L250:
	call	___cxa_throw_bad_array_new_length
L253:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L252
L254:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5257:
	.section	.text$_ZN5lique6MatrixIfED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfED1Ev
	.def	__ZN5lique6MatrixIfED1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfED1Ev:
LFB5260:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L261
	movl	$0, -12(%ebp)
L259:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L257
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L258
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L258:
	addl	$1, -12(%ebp)
	jmp	L259
L257:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L261
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L261:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5260:
	.section	.text$_ZN5lique6MatrixIfEaSEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEaSEOS1_
	.def	__ZN5lique6MatrixIfEaSEOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEaSEOS1_:
LFB5261:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	cmpl	8(%ebp), %eax
	jne	L263
	movl	-28(%ebp), %eax
	jmp	L264
L263:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L265
	movl	$0, -12(%ebp)
L268:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L266
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L267
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L267:
	addl	$1, -12(%ebp)
	jmp	L268
L266:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L265
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L265:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	-28(%ebp), %eax
L264:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5261:
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEixEj
	.def	__ZN10CollectionIN5lique6VectorIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEixEj:
LFB5262:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5262:
	.section	.text$_ZN5lique6VectorIfEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1Ej
	.def	__ZN5lique6VectorIfEC1Ej;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1Ej:
LFB5265:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	cmpl	$536870911, %eax
	ja	L273
	sall	$2, %eax
	jmp	L275
L273:
	call	___cxa_throw_bad_array_new_length
L275:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5265:
	.section	.text$_ZN5lique6VectorIfEaSEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEaSEOS1_
	.def	__ZN5lique6VectorIfEaSEOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEaSEOS1_:
LFB5266:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jne	L277
	movl	-12(%ebp), %eax
	jmp	L278
L277:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L279
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L279:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
L278:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5266:
	.section	.text$_ZN5lique6MatrixIfE4fillEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE4fillEPFfvE
	.def	__ZN5lique6MatrixIfE4fillEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE4fillEPFfvE:
LFB5267:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5267
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L284:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L281
	movl	$0, -16(%ebp)
L283:
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L282
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	call	*%eax
	fstps	-32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -16(%ebp)
	jmp	L283
L282:
	addl	$1, -12(%ebp)
	jmp	L284
L281:
	movl	-28(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5267:
	.section	.gcc_except_table,"w"
LLSDA5267:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5267-LLSDACSB5267
LLSDACSB5267:
LLSDACSE5267:
	.section	.text$_ZN5lique6MatrixIfE4fillEPFfvE,"x"
	.linkonce discard
	.section	.text$_ZN5lique6VectorIfE4fillEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE4fillEPFfvE
	.def	__ZN5lique6VectorIfE4fillEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE4fillEPFfvE:
LFB5268:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5268
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L288:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L287
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	call	*%eax
	fstps	-32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L288
L287:
	movl	-28(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5268:
	.section	.gcc_except_table,"w"
LLSDA5268:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5268-LLSDACSB5268
LLSDACSB5268:
LLSDACSE5268:
	.section	.text$_ZN5lique6VectorIfE4fillEPFfvE,"x"
	.linkonce discard
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev:
LFB5271:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5271
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5271:
	.section	.gcc_except_table,"w"
LLSDA5271:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5271-LLSDACSB5271
LLSDACSB5271:
LLSDACSE5271:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev:
LFB5275:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5275:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev:
LFB5277:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5277
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5277:
	.section	.gcc_except_table,"w"
LLSDA5277:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5277-LLSDACSB5277
LLSDACSB5277:
LLSDACSE5277:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNKSt4lessIPKcEclERKS1_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4lessIPKcEclERKS1_S4_
	.def	__ZNKSt4lessIPKcEclERKS1_S4_;	.scl	2;	.type	32;	.endef
__ZNKSt4lessIPKcEclERKS1_S4_:
LFB5279:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	setb	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5279:
	.section	.text$_ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_:
LFB5280:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5280:
	.section	.text$_ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE:
LFB5282:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5282:
	.section	.text$_ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_
	.def	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_:
LFB5289:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5289:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_:
LFB5291:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5291:
	.section	.text$_ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_
	.def	__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_:
LFB5294:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5294:
	.section	.text$_ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_,"x"
	.linkonce discard
	.globl	__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_
	.def	__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_:
LFB5307:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5307:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_:
LFB5306:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5306:
	.section	.text$_ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5308:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5308:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_:
LFB5309:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_
	movl	%eax, (%esp)
	call	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5309:
	.section	.text$_ZNSt5tupleIJOPKcEEC1EOS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIJOPKcEEC1EOS3_
	.def	__ZNSt5tupleIJOPKcEEC1EOS3_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIJOPKcEEC1EOS3_:
LFB5312:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5312:
	.section	.text$_ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_,"x"
	.linkonce discard
	.globl	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_
	.def	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_;	.scl	2;	.type	32;	.endef
__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_:
LFB5281:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5281:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_:
LFB5278:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5278
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB23:
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
LEHE23:
	subl	$4, %esp
	movl	%eax, -28(%ebp)
	movl	$0, %ebx
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	movl	%eax, -24(%ebp)
	movb	$1, -45(%ebp)
	leal	-28(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	jne	L313
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
LEHB24:
	call	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
LEHE24:
	movl	$1, %ebx
	leal	-18(%ebp), %eax
	movl	%esi, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L314
L313:
	movl	$1, %eax
	jmp	L315
L314:
	movl	$0, %eax
L315:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	testb	%al, %al
	je	L318
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %edx
	leal	-16(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_
	leal	-12(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	subl	$4, %esp
	movl	-44(%ebp), %eax
	leal	-17(%ebp), %edx
	movl	%edx, 12(%esp)
	leal	-16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$__ZStL19piecewise_construct, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB25:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	subl	$16, %esp
	movl	%eax, -28(%ebp)
L318:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	addl	$4, %eax
	jmp	L324
L323:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	nop
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE25:
L324:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5278:
	.section	.gcc_except_table,"w"
LLSDA5278:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5278-LLSDACSB5278
LLSDACSB5278:
	.uleb128 LEHB23-LFB5278
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB24-LFB5278
	.uleb128 LEHE24-LEHB24
	.uleb128 L323-LFB5278
	.uleb128 0
	.uleb128 LEHB25-LFB5278
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE5278:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5313:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5313:
	.section	.text$_ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5314:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5314:
	.section	.text$_ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5315:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	fld1
	fstps	(%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfE4fillEf
	subl	$4, %esp
	nop
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5315:
	.section	.text$_ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5316:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail4tanhIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5316:
	.section	.text$_ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5317:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5317:
	.section	.text$_ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5318:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail4reluIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5318:
	.section	.text$_ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5319:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5319:
	.section	.text$_ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5320:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail3eluIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5320:
	.section	.text$_ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5321:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5321:
	.section	.text$_ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5322:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail5lreluIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5322:
	.section	.text$_ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5323:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5323:
	.section	.text$_ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5324:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail4seluIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5324:
	.section	.text$_ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5325:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5325:
	.section	.text$_ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5326:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail4geluIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5326:
	.section	.text$_ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5327:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5327:
	.section	.text$_ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5328:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail8softsignIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5328:
	.section	.text$_ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5329:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5329:
	.section	.text$_ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5330:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail8softplusIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5330:
	.section	.text$_ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5331:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5331:
	.section	.text$_ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5332:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail5swishIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5332:
	.section	.text$_ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5333:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$__ZN5trixy3set10activation6detail13swish_derivedIfEET_S4_, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE5applyEPFffE
	subl	$8, %esp
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5333:
	.section	.text$_ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5334:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L369:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L368
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	(%esp)
	call	__ZSt3expf
	fstps	-28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L369
L368:
	fldz
	fstps	-16(%ebp)
	movl	$0, -20(%ebp)
L371:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L370
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	-16(%ebp)
	faddp	%st, %st(1)
	fstps	-16(%ebp)
	addl	$1, -20(%ebp)
	jmp	L371
L370:
	movl	$0, -24(%ebp)
L373:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L375
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fdivs	-16(%ebp)
	fstps	(%eax)
	addl	$1, -24(%ebp)
	jmp	L373
L375:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5334:
	.globl	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
	.section	.data$_ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max:
	.space 4
	.globl	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	.section	.data$_ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator:
	.space 4
	.section	.text$_ZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5335:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
	movl	$1, -12(%ebp)
L379:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L377
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	L378
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
L378:
	addl	$1, -12(%ebp)
	jmp	L379
L377:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -16(%ebp)
L381:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L380
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
	fsubrp	%st, %st(1)
	fstps	(%esp)
	call	__ZSt3expf
	fstps	-28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -16(%ebp)
	jmp	L381
L380:
	fldz
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	movl	$0, -20(%ebp)
L383:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L382
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	faddp	%st, %st(1)
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	addl	$1, -20(%ebp)
	jmp	L383
L382:
	movl	$0, -24(%ebp)
L385:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L387
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	fdivrp	%st, %st(1)
	fstps	(%eax)
	addl	$1, -24(%ebp)
	jmp	L385
L387:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5335:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_:
LFB5336:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5336:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv:
LFB5337:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5337:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_:
LFB5338:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	setne	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5338:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv:
LFB5339:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5339:
	.section	.text$_ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	.def	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_;	.scl	2;	.type	32;	.endef
__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_:
LFB5342:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5342:
	.section	.text$_ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	.def	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj:
LFB5343:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5343:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev:
LFB5346:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5346
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5346:
	.section	.gcc_except_table,"w"
LLSDA5346:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5346-LLSDACSB5346
LLSDACSB5346:
LLSDACSE5346:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev:
LFB5350:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5350:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev:
LFB5352:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5352
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5352:
	.section	.gcc_except_table,"w"
LLSDA5352:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5352-LLSDACSB5352
LLSDACSB5352:
LLSDACSE5352:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_:
LFB5353:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5353
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB26:
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
LEHE26:
	subl	$4, %esp
	movl	%eax, -28(%ebp)
	movl	$0, %ebx
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	movl	%eax, -24(%ebp)
	movb	$1, -45(%ebp)
	leal	-28(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	jne	L403
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
LEHB27:
	call	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
LEHE27:
	movl	$1, %ebx
	leal	-18(%ebp), %eax
	movl	%esi, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L404
L403:
	movl	$1, %eax
	jmp	L405
L404:
	movl	$0, %eax
L405:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	testb	%al, %al
	je	L408
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %edx
	leal	-16(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_
	leal	-12(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	subl	$4, %esp
	movl	-44(%ebp), %eax
	leal	-17(%ebp), %edx
	movl	%edx, 12(%esp)
	leal	-16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$__ZStL19piecewise_construct, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB28:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	subl	$16, %esp
	movl	%eax, -28(%ebp)
L408:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	addl	$4, %eax
	jmp	L414
L413:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	nop
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE28:
L414:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5353:
	.section	.gcc_except_table,"w"
LLSDA5353:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5353-LLSDACSB5353
LLSDACSB5353:
	.uleb128 LEHB26-LFB5353
	.uleb128 LEHE26-LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB27-LFB5353
	.uleb128 LEHE27-LEHB27
	.uleb128 L413-LFB5353
	.uleb128 0
	.uleb128 LEHB28-LFB5353
	.uleb128 LEHE28-LEHB28
	.uleb128 0
	.uleb128 0
LLSDACSE5353:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.globl	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"x"
	.linkonce discard
	.globl	__ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.def	__ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_;	.scl	2;	.type	32;	.endef
__ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
LFB5355:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	fildl	12(%ebp)
	flds	8(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_pow
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5355:
	.section	.text$_ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5354:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	fldz
	fstps	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L419:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L418
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-32(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-32(%ebp)
	movl	$2, 4(%esp)
	fstps	(%esp)
	call	__ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	flds	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L419
L418:
	flds	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	flds	LC42
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5354:
	.section	.text$_ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5356:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L423:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L425
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-28(%ebp)
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L423
L425:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5356:
	.globl	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5357:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	fldz
	fstps	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L428:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L427
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-28(%ebp)
	fstps	(%esp)
	call	__ZSt4fabsf
	flds	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	faddp	%st, %st(1)
	fstps	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L428
L427:
	flds	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5357:
	.section	.text$_ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5358:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L435:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L439
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	-28(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L438
	fld1
	fchs
	jmp	L434
L438:
	fld1
L434:
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L435
L439:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5358:
	.globl	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"x"
	.linkonce discard
	.globl	__ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.def	__ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_;	.scl	2;	.type	32;	.endef
__ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
LFB5360:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	fildl	16(%ebp)
	fstpl	8(%esp)
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	_pow
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5360:
	.section	.text$_ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5359:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	fldz
	fstps	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L444:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L443
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	faddp	%st, %st(1)
	fstpl	-40(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	faddp	%st, %st(1)
	fdivrl	-40(%ebp)
	fstpl	(%esp)
	call	_log
	movl	$2, 8(%esp)
	fstpl	(%esp)
	call	__ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	flds	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L444
L443:
	flds	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	flds	LC42
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5359:
	.section	.text$_ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5361:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L448:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L450
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	faddp	%st, %st(1)
	fstps	(%ebx)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstpl	-40(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	faddp	%st, %st(1)
	fdivrl	-40(%ebp)
	fstpl	(%esp)
	call	_log
	fstpl	-40(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fdivl	-40(%ebp)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	(%eax)
	addl	$1, -12(%ebp)
	jmp	L448
L450:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5361:
	.globl	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5362:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	fldz
	fstps	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L453:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L452
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	LC44
	faddp	%st, %st(1)
	fstps	(%esp)
	call	__ZSt3logf
	fmuls	-28(%ebp)
	flds	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	fsubp	%st, %st(1)
	fstps	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L453
L452:
	flds	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5362:
	.section	.text$_ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5363:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L457:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L459
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fchs
	fstps	-28(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	LC44
	faddp	%st, %st(1)
	fdivrs	-28(%ebp)
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L457
L459:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5363:
	.section	.text$_ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5364:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L462:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L464
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-28(%ebp)
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L462
L464:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5364:
	.globl	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5365:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	fldz
	fstps	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L467:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L466
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-40(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	LC44
	faddp	%st, %st(1)
	fstps	(%esp)
	call	__ZSt3logf
	fmuls	-40(%ebp)
	fstpl	-40(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubp	%st, %st(1)
	fstpl	-48(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubp	%st, %st(1)
	fstps	(%esp)
	call	__ZSt3logf
	fmull	-48(%ebp)
	faddl	-40(%ebp)
	flds	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	fsubp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L467
L466:
	flds	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5365:
	.section	.text$_ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5366:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L471:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L473
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubrp	%st, %st(1)
	fstpl	-40(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubrp	%st, %st(1)
	fdivrl	-40(%ebp)
	fstpl	-40(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-32(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	flds	LC44
	faddp	%st, %st(1)
	fdivrs	-32(%ebp)
	fsubrl	-40(%ebp)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L471
L473:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5366:
	.section	.text$_ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5367:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L476:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L478
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstpl	-40(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubrp	%st, %st(1)
	fmull	-40(%ebp)
	fstpl	-40(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fld1
	fsubp	%st, %st(1)
	fstpl	-48(%ebp)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fmull	-48(%ebp)
	faddl	-40(%ebp)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L476
L478:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5367:
	.globl	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	.section	.data$_ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result:
	.space 4
	.section	.text$_ZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5368:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	fldz
	fstps	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	movl	$0, -12(%ebp)
L481:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L480
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-28(%ebp)
	fstps	(%esp)
	call	__ZSt4coshf
	fstps	-28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3logf
	flds	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	faddp	%st, %st(1)
	fstps	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	addl	$1, -12(%ebp)
	jmp	L481
L480:
	flds	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5368:
	.section	.text$_ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5369:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L485:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L487
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-28(%ebp)
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fsubrs	-28(%ebp)
	fstps	(%esp)
	call	__ZSt4tanhf
	fstps	-28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L485
L487:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5369:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_:
LFB5370:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5370:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv:
LFB5371:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5371:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_:
LFB5372:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	setne	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5372:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv:
LFB5373:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5373:
	.section	.text$_ZN5lique6VectorIfEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1Ev
	.def	__ZN5lique6VectorIfEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1Ev:
LFB5376:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, (%eax)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5376:
	.section	.text$_ZN5lique6VectorIfEaSERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEaSERKS1_
	.def	__ZN5lique6VectorIfEaSERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEaSERKS1_:
LFB5377:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	cmpl	8(%ebp), %eax
	jne	L498
	movl	-28(%ebp), %eax
	jmp	L499
L498:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L500
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L500:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L501
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	$0, -12(%ebp)
	jmp	L504
L501:
	call	___cxa_throw_bad_array_new_length
L504:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L503
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	jmp	L504
L503:
	movl	-28(%ebp), %eax
L499:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5377:
	.section	.text$_ZNK10CollectionIN5lique6VectorIfEEE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	.def	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv:
LFB5378:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5378:
	.section	.text$_ZNK10CollectionIN5lique6VectorIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	.def	__ZNK10CollectionIN5lique6VectorIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6VectorIfEEEixEj:
LFB5379:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5379:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE:
LFB5380:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5380
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB29:
	call	__ZN5lique6VectorIfEC1ERKS1_
LEHE29:
	subl	$4, %esp
	movl	$0, -12(%ebp)
L511:
	movl	8(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L519
	movl	8(%ebp), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	subl	$4, %esp
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6MatrixIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	8(%ebp), %eax
	leal	36(%eax), %ecx
	leal	-20(%ebp), %eax
	movl	$0, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
LEHB30:
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
LEHE30:
	subl	$16, %esp
	leal	-28(%ebp), %eax
	movl	%esi, 4(%esp)
	leal	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB31:
	call	__ZNK5lique6VectorIfEplERKS1_
LEHE31:
	subl	$8, %esp
	leal	-36(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB32:
	call	*%ebx
LEHE32:
	movl	-44(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -12(%ebp)
	jmp	L511
L518:
	movl	%eax, %ebx
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L514
L517:
	movl	%eax, %ebx
L514:
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L515
L516:
	movl	%eax, %ebx
L515:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB33:
	call	__Unwind_Resume
LEHE33:
L519:
	nop
	movl	-44(%ebp), %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5380:
	.section	.gcc_except_table,"w"
LLSDA5380:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5380-LLSDACSB5380
LLSDACSB5380:
	.uleb128 LEHB29-LFB5380
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB30-LFB5380
	.uleb128 LEHE30-LEHB30
	.uleb128 L516-LFB5380
	.uleb128 0
	.uleb128 LEHB31-LFB5380
	.uleb128 LEHE31-LEHB31
	.uleb128 L517-LFB5380
	.uleb128 0
	.uleb128 LEHB32-LFB5380
	.uleb128 LEHE32-LEHB32
	.uleb128 L518-LFB5380
	.uleb128 0
	.uleb128 LEHB33-LFB5380
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
LLSDACSE5380:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE,"x"
	.linkonce discard
	.section .rdata,"dr"
LC45:
	.ascii ", \0"
	.section	.text$_ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE,"x"
	.linkonce discard
	.globl	__ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE
	.def	__ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE;	.scl	2;	.type	32;	.endef
__ZlsIJfEERSoS0_RKN5lique6VectorIDpT_EE:
LFB5381:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$91, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	$0, -12(%ebp)
L522:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L521
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	(%esp)
	movl	8(%ebp), %ecx
	call	__ZNSolsEf
	subl	$4, %esp
	movl	$LC45, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -12(%ebp)
	jmp	L522
L521:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	(%esp)
	movl	8(%ebp), %ecx
	call	__ZNSolsEf
	subl	$4, %esp
	movl	$93, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5381:
	.section	.text$_ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
	.def	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b;	.scl	2;	.type	32;	.endef
__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b:
LFB5382:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	%ecx, -60(%ebp)
	movl	20(%ebp), %eax
	movb	%al, -64(%ebp)
	fldz
	fstpl	-16(%ebp)
	cmpb	$0, -64(%ebp)
	je	L525
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3rowEv
	movl	%eax, %edx
	leal	-40(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -20(%ebp)
L529:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3rowEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L526
	movl	$0, -24(%ebp)
L528:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3colEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L527
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-72(%ebp)
	movl	16(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfEclEjj
	subl	$8, %esp
	flds	(%eax)
	fmuls	-72(%ebp)
	fldl	-16(%ebp)
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	addl	$1, -24(%ebp)
	jmp	L528
L527:
	leal	-40(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	fldl	-16(%ebp)
	fstps	-68(%ebp)
	flds	-68(%ebp)
	fstps	(%eax)
	fldz
	fstpl	-16(%ebp)
	addl	$1, -20(%ebp)
	jmp	L529
L526:
	movl	-60(%ebp), %eax
	leal	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1EOS1_
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L524
L525:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3colEv
	movl	%eax, %edx
	leal	-48(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -28(%ebp)
L534:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3colEv
	cmpl	-28(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L531
	movl	$0, -32(%ebp)
L533:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3rowEv
	cmpl	-32(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L532
	movl	12(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-72(%ebp)
	movl	16(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfEclEjj
	subl	$8, %esp
	flds	(%eax)
	fmuls	-72(%ebp)
	fldl	-16(%ebp)
	faddp	%st, %st(1)
	fstpl	-16(%ebp)
	addl	$1, -32(%ebp)
	jmp	L533
L532:
	leal	-48(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	fldl	-16(%ebp)
	fstps	-68(%ebp)
	flds	-68(%ebp)
	fstps	(%eax)
	fldz
	fstpl	-16(%ebp)
	addl	$1, -28(%ebp)
	jmp	L534
L531:
	movl	-60(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1EOS1_
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
L524:
	movl	-60(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5382:
	.section	.text$_ZNK5lique6VectorIfEplERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfEplERKS1_
	.def	__ZNK5lique6VectorIfEplERKS1_;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfEplERKS1_:
LFB5383:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L537:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L539
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	jmp	L537
L539:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5383:
	.section	.text$_ZNK5lique6VectorIfE8multiplyERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE8multiplyERKS1_
	.def	__ZNK5lique6VectorIfE8multiplyERKS1_;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE8multiplyERKS1_:
LFB5384:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L542:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L544
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fmulp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	jmp	L542
L544:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5384:
	.section	.text$_ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	.def	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b;	.scl	2;	.type	32;	.endef
__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b:
LFB5385:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	movl	%ecx, -60(%ebp)
	movl	20(%ebp), %eax
	movb	%al, -64(%ebp)
	cmpb	$0, -64(%ebp)
	je	L546
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %edx
	leal	-36(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1Ejj
	subl	$8, %esp
	movl	$0, -12(%ebp)
L550:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L547
	movl	$0, -16(%ebp)
L549:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L548
	leal	-36(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEclEjj
	subl	$8, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-68(%ebp)
	movl	16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fmuls	-68(%ebp)
	fstps	(%ebx)
	addl	$1, -16(%ebp)
	jmp	L549
L548:
	addl	$1, -12(%ebp)
	jmp	L550
L547:
	movl	-60(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1EOS1_
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	jmp	L545
L546:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, %edx
	leal	-48(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1Ejj
	subl	$8, %esp
	movl	$0, -20(%ebp)
L555:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L552
	movl	$0, -24(%ebp)
L554:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L553
	leal	-48(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEclEjj
	subl	$8, %esp
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	-68(%ebp)
	movl	16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fmuls	-68(%ebp)
	fstps	(%ebx)
	addl	$1, -24(%ebp)
	jmp	L554
L553:
	addl	$1, -20(%ebp)
	jmp	L555
L552:
	movl	-60(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1EOS1_
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
L545:
	movl	-60(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5385:
	.section	.text$_ZNK5lique6MatrixIfE4joinEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE4joinEf
	.def	__ZNK5lique6MatrixIfE4joinEf;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE4joinEf:
LFB5386:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE
	subl	$4, %esp
	movl	$0, -12(%ebp)
L560:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L562
	movl	$0, -16(%ebp)
L559:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L558
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fmuls	12(%ebp)
	fstps	(%edx)
	addl	$1, -16(%ebp)
	jmp	L559
L558:
	addl	$1, -12(%ebp)
	jmp	L560
L562:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5386:
	.section	.text$_ZN5lique6MatrixIfEmIERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEmIERKS1_
	.def	__ZN5lique6MatrixIfEmIERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEmIERKS1_:
LFB5387:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L567:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L564
	movl	$0, -8(%ebp)
L566:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L565
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -8(%ebp)
	jmp	L566
L565:
	addl	$1, -4(%ebp)
	jmp	L567
L564:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5387:
	.section	.text$_ZNK5lique6VectorIfE4joinEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE4joinEf
	.def	__ZNK5lique6VectorIfE4joinEf;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE4joinEf:
LFB5388:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L571:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L573
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fmuls	12(%ebp)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	jmp	L571
L573:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5388:
	.section	.text$_ZN5lique6VectorIfEmIERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEmIERKS1_
	.def	__ZN5lique6VectorIfEmIERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEmIERKS1_:
LFB5389:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L576:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L575
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -4(%ebp)
	jmp	L576
L575:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5389:
	.section	.text$_ZNK5lique6MatrixIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE4sizeEv
	.def	__ZNK5lique6MatrixIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE4sizeEv:
LFB5390:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$4, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5390:
	.section	.text$_ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE
	.def	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE:
LFB5391:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE6resizeEjj
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5391:
	.section	.text$_ZNK5lique6VectorIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE4sizeEv
	.def	__ZNK5lique6VectorIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE4sizeEv:
LFB5392:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5392:
	.section	.text$_ZN5lique6VectorIfE6resizeEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE6resizeEj
	.def	__ZN5lique6VectorIfE6resizeEj;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE6resizeEj:
LFB5393:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L585
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L585:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L586
	sall	$2, %eax
	jmp	L589
L586:
	call	___cxa_throw_bad_array_new_length
L589:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5393:
	.section	.text$_ZN5lique6MatrixIfE4fillEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE4fillEf
	.def	__ZN5lique6MatrixIfE4fillEf;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE4fillEf:
LFB5394:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L594:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L591
	movl	$0, -8(%ebp)
L593:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L592
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	flds	8(%ebp)
	fstps	(%eax)
	addl	$1, -8(%ebp)
	jmp	L593
L592:
	addl	$1, -4(%ebp)
	jmp	L594
L591:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5394:
	.section	.text$_ZN5lique6VectorIfE4fillEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE4fillEf
	.def	__ZN5lique6VectorIfE4fillEf;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE4fillEf:
LFB5395:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L598:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L597
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	flds	8(%ebp)
	fstps	(%eax)
	addl	$1, -4(%ebp)
	jmp	L598
L597:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5395:
	.section	.text$_ZN5lique6MatrixIfEpLERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEpLERKS1_
	.def	__ZN5lique6MatrixIfEpLERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEpLERKS1_:
LFB5396:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L604:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L601
	movl	$0, -8(%ebp)
L603:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L602
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -8(%ebp)
	jmp	L603
L602:
	addl	$1, -4(%ebp)
	jmp	L604
L601:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5396:
	.section	.text$_ZN5lique6VectorIfEpLERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEpLERKS1_
	.def	__ZN5lique6VectorIfEpLERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEpLERKS1_:
LFB5397:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L608:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L607
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	fstps	(%edx)
	addl	$1, -4(%ebp)
	jmp	L608
L607:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5397:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE:
LFB5398:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	subl	$4, %esp
	movl	$0, -12(%ebp)
L612:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L614
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN10CollectionIN5lique6VectorIfEEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6VectorIfEaSEOS1_
	subl	$4, %esp
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	addl	$1, -12(%ebp)
	jmp	L612
L614:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5398:
	.section	.text$_ZNK5lique6VectorIfEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfEclEj
	.def	__ZNK5lique6VectorIfEclEj;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfEclEj:
LFB5402:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5402:
	.section	.text$_ZN5lique6MatrixIfEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1Ev
	.def	__ZN5lique6MatrixIfEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1Ev:
LFB5446:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE5ShapeC1Ejj
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5446:
	.section	.text$_ZN5lique6MatrixIfE5ShapeC1Ejj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE5ShapeC1Ejj
	.def	__ZN5lique6MatrixIfE5ShapeC1Ejj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE5ShapeC1Ejj:
LFB5449:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5449:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev:
LFB5452:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5452:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5454:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5454:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E:
LFB5456:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L623:
	cmpl	$0, 8(%ebp)
	je	L624
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, 8(%ebp)
	jmp	L623
L624:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5456:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv:
LFB5457:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5457:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_:
LFB5458:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5458:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_:
LFB5459:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5459:
	.section	.text$_ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
	.def	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv:
LFB5460:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5460:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv:
LFB5461:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5461:
	.section	.text$_ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	.def	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E;	.scl	2;	.type	32;	.endef
__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E:
LFB5464:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5464:
	.section	.text$_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5466:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5466:
	.section	.text$_ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	.def	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE:
LFB5467:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5467:
	.section	.text$_ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE:
LFB5468:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5468:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_:
LFB5465:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5465
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -28(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB34:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
LEHE34:
	subl	$12, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB35:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	subl	$8, %esp
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	-20(%ebp), %eax
	testl	%eax, %eax
	je	L643
	movl	-20(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
LEHE35:
	subl	$12, %esp
	jmp	L650
L643:
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-24(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-16(%ebp), %eax
	jmp	L650
L648:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB36:
	call	___cxa_rethrow
LEHE36:
L649:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB37:
	call	__Unwind_Resume
LEHE37:
L650:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5465:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5465:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5465-LLSDATTD5465
LLSDATTD5465:
	.byte	0x1
	.uleb128 LLSDACSE5465-LLSDACSB5465
LLSDACSB5465:
	.uleb128 LEHB34-LFB5465
	.uleb128 LEHE34-LEHB34
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB35-LFB5465
	.uleb128 LEHE35-LEHB35
	.uleb128 L648-LFB5465
	.uleb128 0x1
	.uleb128 LEHB36-LFB5465
	.uleb128 LEHE36-LEHB36
	.uleb128 L649-LFB5465
	.uleb128 0
	.uleb128 LEHB37-LFB5465
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
LLSDACSE5465:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5465:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy3set10activation6detail7sigmoidIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_
	.def	__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_:
LFB5473:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fchs
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5473:
	.section	.text$_ZNK5lique6VectorIfE5applyEPFffE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE5applyEPFffE
	.def	__ZNK5lique6VectorIfE5applyEPFffE;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE5applyEPFffE:
LFB5474:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5474
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB38:
	call	__ZN5lique6VectorIfEC1Ej
LEHE38:
	subl	$4, %esp
	movl	$0, -12(%ebp)
L655:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L659
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	flds	(%eax)
	fstps	(%esp)
	movl	12(%ebp), %eax
LEHB39:
	call	*%eax
LEHE39:
	fstps	-32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L655
L658:
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB40:
	call	__Unwind_Resume
LEHE40:
L659:
	nop
	movl	-28(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5474:
	.section	.gcc_except_table,"w"
LLSDA5474:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5474-LLSDACSB5474
LLSDACSB5474:
	.uleb128 LEHB38-LFB5474
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB39-LFB5474
	.uleb128 LEHE39-LEHB39
	.uleb128 L658-LFB5474
	.uleb128 0
	.uleb128 LEHB40-LFB5474
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
LLSDACSE5474:
	.section	.text$_ZNK5lique6VectorIfE5applyEPFffE,"x"
	.linkonce discard
	.section	.text$_ZN5lique6VectorIfEC1EOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1EOS1_
	.def	__ZN5lique6VectorIfEC1EOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1EOS1_:
LFB5477:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5477:
	.section	.text$_ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_:
LFB5478:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt4coshf
	fld1
	faddp	%st, %st(1)
	fldl	LC46
	fdivp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5478:
	.section	.text$_ZN5trixy3set10activation6detail4tanhIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4tanhIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4tanhIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4tanhIfEET_S4_:
LFB5479:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt4tanhf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5479:
	.globl	__ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech
	.section	.data$_ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech:
	.space 4
	.section	.text$_ZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_:
LFB5480:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt4coshf
	fld1
	fdivp	%st, %st(1)
	fstps	__ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech
	flds	__ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech
	flds	__ZZN5trixy3set10activation6detail12tanh_derivedIfEET_S4_E4sech
	fmulp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5480:
	.section	.text$_ZN5trixy3set10activation6detail4reluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4reluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4reluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4reluIfEET_S4_:
LFB5481:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L673
	flds	8(%ebp)
	jmp	L671
L673:
	fldz
L671:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5481:
	.section	.text$_ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_:
LFB5482:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L680
	fld1
	jmp	L678
L680:
	fldz
L678:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5482:
	.section	.text$_ZN5trixy3set10activation6detail3eluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail3eluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail3eluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail3eluIfEET_S4_:
LFB5483:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L687
	flds	8(%ebp)
	jmp	L685
L687:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	fsubrp	%st, %st(1)
	fldl	LC47
	fmulp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
L685:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5483:
	.section	.text$_ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_:
LFB5484:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L694
	fld1
	jmp	L692
L694:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	flds	LC48
	fmulp	%st, %st(1)
L692:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5484:
	.section	.text$_ZN5trixy3set10activation6detail5lreluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail5lreluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail5lreluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail5lreluIfEET_S4_:
LFB5485:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L701
	flds	8(%ebp)
	jmp	L699
L701:
	flds	8(%ebp)
	flds	LC49
	fmulp	%st, %st(1)
L699:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5485:
	.section	.text$_ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_:
LFB5486:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L708
	fld1
	jmp	L706
L708:
	flds	LC49
L706:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5486:
	.section	.text$_ZN5trixy3set10activation6detail4seluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4seluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4seluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4seluIfEET_S4_:
LFB5487:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L715
	flds	8(%ebp)
	flds	LC50
	fmulp	%st, %st(1)
	jmp	L713
L715:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	fsubrp	%st, %st(1)
	fldl	LC51
	fmulp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
L713:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5487:
	.section	.text$_ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_:
LFB5488:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	flds	8(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L722
	flds	LC50
	jmp	L720
L722:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	flds	LC52
	fmulp	%st, %st(1)
L720:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5488:
	.section	.text$_ZN5trixy3set10activation6detail4geluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4geluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4geluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4geluIfEET_S4_:
LFB5489:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fldl	LC46
	fmulp	%st, %st(1)
	fstpl	-24(%ebp)
	flds	8(%ebp)
	flds	LC53
	fmulp	%st, %st(1)
	flds	8(%ebp)
	fmuls	8(%ebp)
	fmuls	8(%ebp)
	flds	LC54
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	(%esp)
	call	__ZSt4tanhf
	fld1
	faddp	%st, %st(1)
	fmull	-24(%ebp)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5489:
	.globl	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3
	.section	.data$_ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3:
	.space 4
	.globl	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y
	.section	.data$_ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y:
	.space 4
	.globl	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch
	.section	.data$_ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch:
	.space 4
	.section	.text$_ZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_:
LFB5490:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fmuls	8(%ebp)
	fmuls	8(%ebp)
	fstps	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3
	flds	LC53
	fmulp	%st, %st(1)
	flds	8(%ebp)
	flds	LC54
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y
	fstps	(%esp)
	call	__ZSt4coshf
	fld1
	fdivp	%st, %st(1)
	fstps	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E1y
	fstps	(%esp)
	call	__ZSt4tanhf
	fldl	LC46
	fmulp	%st, %st(1)
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E2x3
	flds	LC55
	fmulp	%st, %st(1)
	flds	8(%ebp)
	flds	LC56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch
	fmulp	%st, %st(1)
	flds	__ZZN5trixy3set10activation6detail12gelu_derivedIfEET_S4_E3sch
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	LC46
	faddp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5490:
	.section	.text$_ZN5trixy3set10activation6detail8softsignIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail8softsignIfEET_S4_
	.def	__ZN5trixy3set10activation6detail8softsignIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail8softsignIfEET_S4_:
LFB5491:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstpl	-24(%ebp)
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt4fabsf
	fld1
	faddp	%st, %st(1)
	fdivrl	-24(%ebp)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5491:
	.globl	__ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f
	.section	.data$_ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f:
	.space 4
	.section	.text$_ZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_:
LFB5492:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt4fabsf
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	fstps	__ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f
	flds	__ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f
	flds	__ZZN5trixy3set10activation6detail16softsign_derivedIfEET_S4_E1f
	fmulp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5492:
	.section	.text$_ZN5trixy3set10activation6detail8softplusIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail8softplusIfEET_S4_
	.def	__ZN5trixy3set10activation6detail8softplusIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail8softplusIfEET_S4_:
LFB5493:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	_log
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5493:
	.section	.text$_ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_:
LFB5494:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fchs
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	faddp	%st, %st(1)
	fld1
	fdivp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5494:
	.section	.text$_ZN5trixy3set10activation6detail5swishIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail5swishIfEET_S4_
	.def	__ZN5trixy3set10activation6detail5swishIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail5swishIfEET_S4_:
LFB5495:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fstpl	-24(%ebp)
	flds	8(%ebp)
	fchs
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	faddp	%st, %st(1)
	fdivrl	-24(%ebp)
	fstps	-12(%ebp)
	flds	-12(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5495:
	.globl	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a
	.section	.data$_ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a:
	.space 4
	.globl	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b
	.section	.data$_ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b,"w"
	.linkonce same_size
	.align 4
__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b:
	.space 4
	.section	.text$_ZN5trixy3set10activation6detail13swish_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail13swish_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail13swish_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail13swish_derivedIfEET_S4_:
LFB5496:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fchs
	fstps	(%esp)
	call	__ZSt3expf
	fstps	-12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, __ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a
	flds	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a
	fld1
	faddp	%st, %st(1)
	fstps	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b
	flds	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1a
	fmuls	8(%ebp)
	flds	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b
	faddp	%st, %st(1)
	flds	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b
	flds	__ZZN5trixy3set10activation6detail13swish_derivedIfEET_S4_E1b
	fmulp	%st, %st(1)
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5496:
	.section	.text$_ZN5lique6VectorIfEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEclEj
	.def	__ZN5lique6VectorIfEclEj;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEclEj:
LFB5497:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5497:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_:
LFB5498:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5498
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
LEHB41:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
LEHE41:
	subl	$12, %esp
	movl	%eax, -16(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	movl	%eax, -12(%ebp)
	movl	$1, %ebx
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	jne	L742
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB42:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
LEHE42:
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L743
L742:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	jmp	L750
L743:
	movl	-16(%ebp), %eax
L750:
	testb	%bl, %bl
	jmp	L751
L749:
	testb	%bl, %bl
	nop
	movl	%eax, (%esp)
LEHB43:
	call	__Unwind_Resume
LEHE43:
L751:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5498:
	.section	.gcc_except_table,"w"
LLSDA5498:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5498-LLSDACSB5498
LLSDACSB5498:
	.uleb128 LEHB41-LFB5498
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB42-LFB5498
	.uleb128 LEHE42-LEHB42
	.uleb128 L749-LFB5498
	.uleb128 0
	.uleb128 LEHB43-LFB5498
	.uleb128 LEHE43-LEHB43
	.uleb128 0
	.uleb128 0
LLSDACSE5498:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv:
LFB5499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5499:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5500:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev:
LFB5503:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5503:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5505:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5505:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E:
LFB5507:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L760:
	cmpl	$0, 8(%ebp)
	je	L761
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, 8(%ebp)
	jmp	L760
L761:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5507:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv:
LFB5508:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5508:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_:
LFB5509:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5509:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_:
LFB5510:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5510:
	.section	.text$_ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
	.def	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv:
LFB5511:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5511:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv:
LFB5512:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5512:
	.section	.text$_ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	.def	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E;	.scl	2;	.type	32;	.endef
__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E:
LFB5515:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5515:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_:
LFB5516:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5516
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -28(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB44:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
LEHE44:
	subl	$12, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB45:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	subl	$8, %esp
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	-20(%ebp), %eax
	testl	%eax, %eax
	je	L774
	movl	-20(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
LEHE45:
	subl	$12, %esp
	jmp	L781
L774:
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-24(%ebp), %edx
	leal	-16(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-16(%ebp), %eax
	jmp	L781
L779:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB46:
	call	___cxa_rethrow
LEHE46:
L780:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB47:
	call	__Unwind_Resume
LEHE47:
L781:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5516:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5516:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5516-LLSDATTD5516
LLSDATTD5516:
	.byte	0x1
	.uleb128 LLSDACSE5516-LLSDACSB5516
LLSDACSB5516:
	.uleb128 LEHB44-LFB5516
	.uleb128 LEHE44-LEHB44
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB45-LFB5516
	.uleb128 LEHE45-LEHB45
	.uleb128 L779-LFB5516
	.uleb128 0x1
	.uleb128 LEHB46-LFB5516
	.uleb128 LEHE46-LEHB46
	.uleb128 L780-LFB5516
	.uleb128 0
	.uleb128 LEHB47-LFB5516
	.uleb128 LEHE47-LEHB47
	.uleb128 0
	.uleb128 0
LLSDACSE5516:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5516:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_:
LFB5517:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5517
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
LEHB48:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
LEHE48:
	subl	$12, %esp
	movl	%eax, -16(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	movl	%eax, -12(%ebp)
	movl	$1, %ebx
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	jne	L783
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB49:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
LEHE49:
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L784
L783:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	jmp	L791
L784:
	movl	-16(%ebp), %eax
L791:
	testb	%bl, %bl
	jmp	L792
L790:
	testb	%bl, %bl
	nop
	movl	%eax, (%esp)
LEHB50:
	call	__Unwind_Resume
LEHE50:
L792:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5517:
	.section	.gcc_except_table,"w"
LLSDA5517:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5517-LLSDACSB5517
LLSDACSB5517:
	.uleb128 LEHB48-LFB5517
	.uleb128 LEHE48-LEHB48
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB49-LFB5517
	.uleb128 LEHE49-LEHB49
	.uleb128 L790-LFB5517
	.uleb128 0
	.uleb128 LEHB50-LFB5517
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
LLSDACSE5517:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv:
LFB5518:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5518:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5519:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5519:
	.section	.text$_ZN5lique6VectorIfEC1ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1ERKS1_
	.def	__ZN5lique6VectorIfEC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1ERKS1_:
LFB5522:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L798
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	$0, -12(%ebp)
	jmp	L801
L798:
	call	___cxa_throw_bad_array_new_length
L801:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L802
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	flds	(%eax)
	fstps	(%edx)
	addl	$1, -12(%ebp)
	jmp	L801
L802:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5522:
	.section	.text$_ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	.def	__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj:
LFB5523:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5523:
	.section	.text$_ZNK10CollectionIN5lique6MatrixIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6MatrixIfEEEixEj
	.def	__ZNK10CollectionIN5lique6MatrixIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6MatrixIfEEEixEj:
LFB5524:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5524:
	.section	.text$_ZNK5lique6MatrixIfE5Shape3rowEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE5Shape3rowEv
	.def	__ZNK5lique6MatrixIfE5Shape3rowEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE5Shape3rowEv:
LFB5526:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5526:
	.section	.text$_ZNK5lique6MatrixIfE5Shape3colEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE5Shape3colEv
	.def	__ZNK5lique6MatrixIfE5Shape3colEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE5Shape3colEv:
LFB5527:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5527:
	.section	.text$_ZNK5lique6MatrixIfEclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfEclEjj
	.def	__ZNK5lique6MatrixIfEclEjj;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfEclEjj:
LFB5528:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5528:
	.section	.text$_ZN5lique6MatrixIfEclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEclEjj
	.def	__ZN5lique6MatrixIfEclEjj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEclEjj:
LFB5529:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5529:
	.section	.text$_ZN5lique6MatrixIfEC1EOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1EOS1_
	.def	__ZN5lique6MatrixIfEC1EOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1EOS1_:
LFB5532:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfE5ShapeC1ERKS2_
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5532:
	.section	.text$_ZN5lique6MatrixIfEC1ERKNS1_5ShapeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE
	.def	__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE:
LFB5535:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$536870911, %eax
	ja	L817
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN5lique6MatrixIfE5ShapeC1ERKS2_
	subl	$4, %esp
	movl	$0, -12(%ebp)
	jmp	L822
L817:
	call	___cxa_throw_bad_array_new_length
L822:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L824
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L820
	sall	$2, %eax
	jmp	L823
L820:
	call	___cxa_throw_bad_array_new_length
L823:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L822
L824:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5535:
	.section	.text$_ZN5lique6MatrixIfE6resizeEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE6resizeEjj
	.def	__ZN5lique6MatrixIfE6resizeEjj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE6resizeEjj:
LFB5536:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L826
	movl	$0, -12(%ebp)
L829:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L827
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L828
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L828:
	addl	$1, -12(%ebp)
	jmp	L829
L827:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L826
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L826:
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L831
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	$0, -16(%ebp)
	jmp	L836
L831:
	call	___cxa_throw_bad_array_new_length
L836:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L833
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L834
	sall	$2, %eax
	jmp	L838
L834:
	call	___cxa_throw_bad_array_new_length
L838:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -16(%ebp)
	jmp	L836
L833:
	movl	-28(%ebp), %eax
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5536:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev:
LFB5571:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 12(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 16(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 20(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5571:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5573:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5573:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base:
LFB5575:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5575:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base:
LFB5576:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5576:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5577:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5577:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_:
LFB5578:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	subl	$12, %esp
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5578:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv:
LFB5579:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5579:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5580:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	subl	$16, %esp
	movl	-12(%ebp), %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5580:
	.section	.text$_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5591:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5591:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_:
LFB5593:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5593:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_:
LFB5600:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5600:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_:
LFB5607:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5607:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_:
LFB5581:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$132, %esp
	.cfi_offset 3, -12
	movl	%ecx, -108(%ebp)
	leal	8(%ebp), %ecx
	call	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	movl	%eax, -96(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L858
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	testl	%eax, %eax
	je	L859
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L859
	movl	$1, %eax
	jmp	L860
L859:
	movl	$0, %eax
L860:
	testb	%al, %al
	je	L861
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	%eax, %edx
	movl	$0, -84(%ebp)
	leal	-92(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-84(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-92(%ebp), %eax
	movl	-88(%ebp), %edx
	jmp	L873
L861:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L873
L858:
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-108(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L863
	movl	-96(%ebp), %eax
	movl	%eax, -100(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L864
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	%eax, %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-80(%ebp), %eax
	movl	-76(%ebp), %edx
	jmp	L873
L864:
	leal	-100(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L866
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L867
	movl	$0, -64(%ebp)
	leal	-72(%ebp), %eax
	leal	-100(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-64(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	jmp	L873
L867:
	leal	-60(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-96(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-60(%ebp), %eax
	movl	-56(%ebp), %edx
	jmp	L873
L866:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L873
L863:
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L868
	movl	-96(%ebp), %eax
	movl	%eax, -104(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L869
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	%eax, %edx
	movl	$0, -44(%ebp)
	leal	-52(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-52(%ebp), %eax
	movl	-48(%ebp), %edx
	jmp	L873
L869:
	leal	-104(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-108(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L871
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L872
	movl	$0, -32(%ebp)
	leal	-40(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	jmp	L873
L872:
	leal	-28(%ebp), %eax
	leal	-104(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-104(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	-24(%ebp), %edx
	jmp	L873
L871:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L873
L868:
	movl	$0, -12(%ebp)
	leal	-20(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-96(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	subl	$8, %esp
	movl	-20(%ebp), %eax
	movl	-16(%ebp), %edx
L873:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5581:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E:
LFB5608:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	leal	-9(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5608:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E:
LFB5609:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	cmpl	$0, 8(%ebp)
	jne	L877
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	12(%ebp), %eax
	je	L877
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L878
L877:
	movl	$1, %eax
	jmp	L879
L878:
	movl	$0, %eax
L879:
	movb	%al, -9(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movzbl	-9(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	movl	-28(%ebp), %eax
	movl	20(%eax), %eax
	leal	1(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 20(%eax)
	leal	-16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-16(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5609:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base:
LFB5612:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5612:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv:
LFB5613:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$4, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5613:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_:
LFB5614:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L888:
	cmpl	$0, 8(%ebp)
	je	L885
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	xorl	$1, %eax
	testb	%al, %al
	je	L886
	movl	8(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L888
L886:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L888
L885:
	leal	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5614:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base:
LFB5615:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	leal	-9(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5615:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5616:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5616:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev:
LFB5619:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 12(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 16(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 20(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5619:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5621:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5621:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base:
LFB5623:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5623:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base:
LFB5624:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5624:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5625:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5625:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_:
LFB5626:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	subl	$12, %esp
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5626:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv:
LFB5627:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5627:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5628:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	subl	$16, %esp
	movl	-12(%ebp), %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5628:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_:
LFB5629:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$132, %esp
	.cfi_offset 3, -12
	movl	%ecx, -108(%ebp)
	leal	8(%ebp), %ecx
	call	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	movl	%eax, -96(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L908
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	testl	%eax, %eax
	je	L909
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L909
	movl	$1, %eax
	jmp	L910
L909:
	movl	$0, %eax
L910:
	testb	%al, %al
	je	L911
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	%eax, %edx
	movl	$0, -84(%ebp)
	leal	-92(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-84(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-92(%ebp), %eax
	movl	-88(%ebp), %edx
	jmp	L923
L911:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L923
L908:
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-108(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L913
	movl	-96(%ebp), %eax
	movl	%eax, -100(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L914
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	%eax, %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	movl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-80(%ebp), %eax
	movl	-76(%ebp), %edx
	jmp	L923
L914:
	leal	-100(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L916
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L917
	movl	$0, -64(%ebp)
	leal	-72(%ebp), %eax
	leal	-100(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-64(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	jmp	L923
L917:
	leal	-60(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-96(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-60(%ebp), %eax
	movl	-56(%ebp), %edx
	jmp	L923
L916:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L923
L913:
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L918
	movl	-96(%ebp), %eax
	movl	%eax, -104(%ebp)
	movl	-96(%ebp), %ebx
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	sete	%al
	testb	%al, %al
	je	L919
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	movl	%eax, %edx
	movl	$0, -44(%ebp)
	leal	-52(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-52(%ebp), %eax
	movl	-48(%ebp), %edx
	jmp	L923
L919:
	leal	-104(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-108(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L921
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L922
	movl	$0, -32(%ebp)
	leal	-40(%ebp), %eax
	leal	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	subl	$8, %esp
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	jmp	L923
L922:
	leal	-28(%ebp), %eax
	leal	-104(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-104(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	-24(%ebp), %edx
	jmp	L923
L921:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L923
L918:
	movl	$0, -12(%ebp)
	leal	-20(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-96(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	subl	$8, %esp
	movl	-20(%ebp), %eax
	movl	-16(%ebp), %edx
L923:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5629:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E:
LFB5630:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	leal	-9(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5630:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E:
LFB5631:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	cmpl	$0, 8(%ebp)
	jne	L927
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	12(%ebp), %eax
	je	L927
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L928
L927:
	movl	$1, %eax
	jmp	L929
L928:
	movl	$0, %eax
L929:
	movb	%al, -9(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movzbl	-9(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	movl	-28(%ebp), %eax
	movl	20(%eax), %eax
	leal	1(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 20(%eax)
	leal	-16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-16(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5631:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base:
LFB5634:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5634:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv:
LFB5635:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$4, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5635:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_:
LFB5636:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L938:
	cmpl	$0, 8(%ebp)
	je	L935
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	xorl	$1, %eax
	testb	%al, %al
	je	L936
	movl	8(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L938
L936:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L938
L935:
	leal	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5636:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base:
LFB5637:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	movl	%eax, %edx
	leal	-9(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5637:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5638:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5638:
	.section	.text$_ZN5lique6MatrixIfE5ShapeC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE5ShapeC1ERKS2_
	.def	__ZN5lique6MatrixIfE5ShapeC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE5ShapeC1ERKS2_:
LFB5641:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5641:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5667:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5667:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv:
LFB5669:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-4(%ebp), %eax
	leal	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	-4(%ebp), %eax
	leal	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 16(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5669:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5670:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5670
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5670:
	.section	.gcc_except_table,"w"
LLSDA5670:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5670-LLSDACSB5670
LLSDACSB5670:
LLSDACSE5670:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5671:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5671
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	%eax, %edx
	movl	$1, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5671:
	.section	.gcc_except_table,"w"
LLSDA5671:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5671-LLSDACSB5671
LLSDACSB5671:
LLSDACSE5671:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv:
LFB5672:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5672:
	.section	.text$_ZNSt18_Rb_tree_node_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt18_Rb_tree_node_baseC2Ev
	.def	__ZNSt18_Rb_tree_node_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt18_Rb_tree_node_baseC2Ev:
LFB5676:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5676:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5680:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5680:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5682:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt18_Rb_tree_node_baseC2Ev
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5682:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5673:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5673
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L956
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
L956:
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %esi
	movl	8(%ebp), %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	-32(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
LEHB51:
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
LEHE51:
	jmp	L961
L959:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB52:
	call	___cxa_rethrow
LEHE52:
L960:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB53:
	call	__Unwind_Resume
LEHE53:
L961:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5673:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5673:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5673-LLSDATTD5673
LLSDATTD5673:
	.byte	0x1
	.uleb128 LLSDACSE5673-LLSDACSB5673
LLSDACSB5673:
	.uleb128 LEHB51-LFB5673
	.uleb128 LEHE51-LEHB51
	.uleb128 L959-LFB5673
	.uleb128 0x1
	.uleb128 LEHB52-LFB5673
	.uleb128 LEHE52-LEHB52
	.uleb128 L960-LFB5673
	.uleb128 0
	.uleb128 LEHB53-LFB5673
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
LLSDACSE5673:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5673:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	.def	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv;	.scl	2;	.type	32;	.endef
__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv:
LFB5683:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5683:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv:
LFB5684:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	20(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5684:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv:
LFB5685:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$16, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5685:
	.section	.text$_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	.def	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE:
LFB5692:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5692:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_:
LFB5694:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5694:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_:
LFB5686:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	%ecx, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, -48(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, -52(%ebp)
	movb	$1, -9(%ebp)
L975:
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	je	L972
	movl	-48(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	movb	%al, -9(%ebp)
	cmpb	$0, -9(%ebp)
	je	L973
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	jmp	L974
L973:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
L974:
	movl	%eax, -48(%ebp)
	jmp	L975
L972:
	movl	-52(%ebp), %edx
	leal	-56(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	cmpb	$0, -9(%ebp)
	je	L976
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	movl	%eax, -44(%ebp)
	leal	-56(%ebp), %eax
	leal	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	je	L977
	leal	-40(%ebp), %eax
	leal	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	jmp	L980
L977:
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv
L976:
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-60(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L979
	leal	-32(%ebp), %eax
	leal	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	jmp	L980
L979:
	movl	$0, -16(%ebp)
	leal	-24(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	subl	$8, %esp
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
L980:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5686:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv:
LFB5695:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$12, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5695:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv:
LFB5696:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5696:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv:
LFB5697:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5697:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E:
LFB5698:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5698:
	.section	.text$_ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_
	.def	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_;	.scl	2;	.type	32;	.endef
__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_:
LFB5699:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5699:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base:
LFB5700:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5700:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5701:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5701:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5703:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5703:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv:
LFB5705:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-4(%ebp), %eax
	leal	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	-4(%ebp), %eax
	leal	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 16(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5705:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5706:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5706
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5706:
	.section	.gcc_except_table,"w"
LLSDA5706:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5706-LLSDACSB5706
LLSDACSB5706:
LLSDACSE5706:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5707:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5707
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	%eax, %edx
	movl	$1, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5707:
	.section	.gcc_except_table,"w"
LLSDA5707:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5707-LLSDACSB5707
LLSDACSB5707:
LLSDACSE5707:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv:
LFB5708:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5708:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5713:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5713:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5715:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt18_Rb_tree_node_baseC2Ev
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5715:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5709:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5709
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L1005
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
L1005:
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %edi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%eax, %esi
	movl	8(%ebp), %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	movl	-32(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
LEHB54:
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
LEHE54:
	jmp	L1010
L1008:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB55:
	call	___cxa_rethrow
LEHE55:
L1009:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB56:
	call	__Unwind_Resume
LEHE56:
L1010:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5709:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5709:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5709-LLSDATTD5709
LLSDATTD5709:
	.byte	0x1
	.uleb128 LLSDACSE5709-LLSDACSB5709
LLSDACSB5709:
	.uleb128 LEHB54-LFB5709
	.uleb128 LEHE54-LEHB54
	.uleb128 L1008-LFB5709
	.uleb128 0x1
	.uleb128 LEHB55-LFB5709
	.uleb128 LEHE55-LEHB55
	.uleb128 L1009-LFB5709
	.uleb128 0
	.uleb128 LEHB56-LFB5709
	.uleb128 LEHE56-LEHB56
	.uleb128 0
	.uleb128 0
LLSDACSE5709:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5709:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	.def	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv;	.scl	2;	.type	32;	.endef
__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv:
LFB5716:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5716:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv:
LFB5717:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	20(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5717:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv:
LFB5718:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$16, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5718:
	.section	.text$_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	.def	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE:
LFB5725:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5725:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_:
LFB5727:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5727:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_:
LFB5719:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	%ecx, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	movl	%eax, -48(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	movl	%eax, -52(%ebp)
	movb	$1, -9(%ebp)
L1024:
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	je	L1021
	movl	-48(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	movb	%al, -9(%ebp)
	cmpb	$0, -9(%ebp)
	je	L1022
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	jmp	L1023
L1022:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
L1023:
	movl	%eax, -48(%ebp)
	jmp	L1024
L1021:
	movl	-52(%ebp), %edx
	leal	-56(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	cmpb	$0, -9(%ebp)
	je	L1025
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	movl	%eax, -44(%ebp)
	leal	-56(%ebp), %eax
	leal	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_
	subl	$4, %esp
	testb	%al, %al
	je	L1026
	leal	-40(%ebp), %eax
	leal	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	jmp	L1029
L1026:
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv
L1025:
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	movl	%eax, %ecx
	movl	-60(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L1028
	leal	-32(%ebp), %eax
	leal	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	subl	$8, %esp
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	jmp	L1029
L1028:
	movl	$0, -16(%ebp)
	leal	-24(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	subl	$8, %esp
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
L1029:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5719:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv:
LFB5728:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$12, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5728:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv:
LFB5729:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5729:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv:
LFB5730:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5730:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E:
LFB5731:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5731:
	.section	.text$_ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_
	.def	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_;	.scl	2;	.type	32;	.endef
__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_:
LFB5732:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5732:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base:
LFB5733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5733:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5734:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5734:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5744:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5744:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv:
LFB5746:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5746:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_:
LFB5747:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5747:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j:
LFB5748:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5748:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j:
LFB5749:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5749:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_:
LFB5750:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	subl	$16, %esp
	nop
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5750:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv:
LFB5751:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	12(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5751:
	.section	.text$_ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5752:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5752:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5754:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5754:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv:
LFB5756:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5756:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_:
LFB5757:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5757:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j:
LFB5758:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5758:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j:
LFB5759:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5759:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_:
LFB5760:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %esi
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	subl	$16, %esp
	nop
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5760:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv:
LFB5761:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	12(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5761:
	.section	.text$_ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5762:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5762:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_:
LFB5765:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5765:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j:
LFB5766:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5766:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv:
LFB5767:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L1071
	call	__ZSt17__throw_bad_allocv
L1071:
	movl	8(%ebp), %eax
	imull	$28, %eax, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5767:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_:
LFB5768:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5768
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -44(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movzbl	-45(%ebp), %eax
	movb	%al, -33(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5tupleIJOPKcEEC1EOS3_
	subl	$4, %esp
	leal	-32(%ebp), %edi
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movb	%bl, -25(%ebp)
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1078
	movzbl	-25(%ebp), %eax
	movb	%al, 8(%esp)
	movl	%edi, 4(%esp)
	movzbl	-33(%ebp), %eax
	movb	%al, (%esp)
	movl	%ebx, %ecx
LEHB57:
	call	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
LEHE57:
	subl	$12, %esp
	jmp	L1078
L1077:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB58:
	call	__Unwind_Resume
LEHE58:
L1078:
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5768:
	.section	.gcc_except_table,"w"
LLSDA5768:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5768-LLSDACSB5768
LLSDACSB5768:
	.uleb128 LEHB57-LFB5768
	.uleb128 LEHE57-LEHB57
	.uleb128 L1077-LFB5768
	.uleb128 0
	.uleb128 LEHB58-LFB5768
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
LLSDACSE5768:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5769:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5769:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_:
LFB5770:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5770:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j:
LFB5771:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5771:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv:
LFB5772:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L1084
	call	__ZSt17__throw_bad_allocv
L1084:
	movl	8(%ebp), %eax
	imull	$28, %eax, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5772:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_:
LFB5773:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5773
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -44(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movzbl	-45(%ebp), %eax
	movb	%al, -33(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	movl	%eax, %edx
	leal	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5tupleIJOPKcEEC1EOS3_
	subl	$4, %esp
	leal	-32(%ebp), %edi
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	movb	%bl, -25(%ebp)
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L1091
	movzbl	-25(%ebp), %eax
	movb	%al, 8(%esp)
	movl	%edi, 4(%esp)
	movzbl	-33(%ebp), %eax
	movb	%al, (%esp)
	movl	%ebx, %ecx
LEHB59:
	call	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
LEHE59:
	subl	$12, %esp
	jmp	L1091
L1090:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB60:
	call	__Unwind_Resume
LEHE60:
L1091:
	nop
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5773:
	.section	.gcc_except_table,"w"
LLSDA5773:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5773-LLSDACSB5773
LLSDACSB5773:
	.uleb128 LEHB59-LFB5773
	.uleb128 LEHE59-LEHB59
	.uleb128 L1090-LFB5773
	.uleb128 0
	.uleb128 LEHB60-LFB5773
	.uleb128 LEHE60-LEHB60
	.uleb128 0
	.uleb128 0
LLSDACSE5773:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5774:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5774:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv:
LFB5775:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$153391689, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5775:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
	.def	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE:
LFB5778:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movb	%bl, 12(%esp)
	movb	%dl, 8(%esp)
	leal	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	subl	$16, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5778:
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5779:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5779:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv:
LFB5780:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$153391689, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5780:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
	.def	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE:
LFB5783:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movb	%bl, 12(%esp)
	movb	%dl, 8(%esp)
	leal	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	subl	$16, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE5783:
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5784:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5784:
	.section	.text$_ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE,"x"
	.linkonce discard
	.globl	__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	.def	__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE;	.scl	2;	.type	32;	.endef
__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE:
LFB5787:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5787:
	.section	.text$_ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_
	.def	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_:
LFB5786:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5786:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	.def	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE:
LFB5789:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_
	movl	%eax, (%esp)
	call	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5789:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	.def	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE:
LFB5792:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_
	movl	%eax, (%esp)
	call	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5792:
	.text
	.def	___tcf_2;	.scl	3;	.type	32;	.endef
___tcf_2:
LFB5802:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5802:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB5801:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L1113
	cmpl	$65535, 12(%ebp)
	jne	L1113
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_2, (%esp)
	call	_atexit
L1113:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5801:
	.section .rdata,"dr"
	.align 4
_._58:
	.long	4
	.long	4
	.long	5
	.long	4
	.long	3
	.align 4
_._59:
	.long	1065353216
	.long	0
	.long	1065353216
	.long	1065353216
	.align 4
_._60:
	.long	1065353216
	.long	1065353216
	.long	1065353216
	.long	0
	.align 4
_._61:
	.long	1065353216
	.long	1065353216
	.long	0
	.long	1065353216
	.align 4
_._62:
	.long	0
	.long	1065353216
	.long	1065353216
	.long	0
	.align 4
_._63:
	.long	1065353216
	.long	0
	.long	1065353216
	.long	0
	.align 4
_._64:
	.long	0
	.long	0
	.long	1065353216
	.long	1065353216
	.align 4
_._65:
	.long	1065353216
	.long	0
	.long	0
	.align 4
_._66:
	.long	0
	.long	1065353216
	.long	0
	.align 4
_._67:
	.long	1065353216
	.long	0
	.long	0
	.align 4
_._68:
	.long	0
	.long	0
	.long	1065353216
	.align 4
_._69:
	.long	0
	.long	1065353216
	.long	0
	.align 4
_._70:
	.long	1065353216
	.long	0
	.long	0
	.text
	.def	__GLOBAL__sub_I__Z12network_sizeRK10CollectionIjE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z12network_sizeRK10CollectionIjE:
LFB5803:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5803:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z12network_sizeRK10CollectionIjE
	.section .rdata,"dr"
	.align 8
LC1:
	.long	0
	.long	1104006501
	.align 4
LC9:
	.long	1036831949
	.align 4
LC10:
	.long	1041865114
	.align 4
LC13:
	.long	1028443341
	.align 4
LC42:
	.long	1073741824
	.align 4
LC44:
	.long	814313567
	.align 8
LC46:
	.long	0
	.long	1071644672
	.align 8
LC47:
	.long	-1610612736
	.long	1070176665
	.align 4
LC48:
	.long	1045220557
	.align 4
LC49:
	.long	1008981770
	.align 4
LC50:
	.long	1065778527
	.align 8
LC51:
	.long	1610612736
	.long	1073488172
	.align 4
LC52:
	.long	1071712611
	.align 4
LC53:
	.long	1061962289
	.align 4
LC54:
	.long	1024598647
	.align 4
LC55:
	.long	1029387187
	.align 4
LC56:
	.long	1053573664
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_coshf;	.scl	2;	.type	32;	.endef
	.def	_expf;	.scl	2;	.type	32;	.endef
	.def	_logf;	.scl	2;	.type	32;	.endef
	.def	_tanhf;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEj;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSt8ios_baseS0_E;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	___cxa_guard_acquire;	.scl	2;	.type	32;	.endef
	.def	___cxa_guard_release;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	___cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
	.def	_pow;	.scl	2;	.type	32;	.endef
	.def	_log;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEf;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
