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
LFB4667:
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
LFE4667:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB4670:
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
LFE4670:
	.section	.text$_ZNK10CollectionIjE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIjE4sizeEv
	.def	__ZNK10CollectionIjE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIjE4sizeEv:
LFB4974:
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
LFE4974:
	.section	.text$_ZNK10CollectionIjEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIjEixEj
	.def	__ZNK10CollectionIjEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIjEixEj:
LFB4975:
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
LFE4975:
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
LFB4979:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4979
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
	call	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14normalAccuracyERKS5_INS3_IfEEESA_
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
LFE4979:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA4979:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4979-LLSDACSB4979
LLSDACSB4979:
	.uleb128 LEHB0-LFB4979
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB4979
	.uleb128 LEHE1-LEHB1
	.uleb128 L69-LFB4979
	.uleb128 0
	.uleb128 LEHB2-LFB4979
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB4979
	.uleb128 LEHE3-LEHB3
	.uleb128 L70-LFB4979
	.uleb128 0
	.uleb128 LEHB4-LFB4979
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
LLSDACSE4979:
	.section	.text$_Z5test9IfEvv,"x"
	.linkonce discard
	.section	.text$_ZNKSt16initializer_listIjE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIjE4sizeEv
	.def	__ZNKSt16initializer_listIjE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIjE4sizeEv:
LFB5116:
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
LFE5116:
	.section	.text$_ZNKSt16initializer_listIjE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIjE5beginEv
	.def	__ZNKSt16initializer_listIjE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIjE5beginEv:
LFB5120:
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
LFE5120:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEEC1ERKSt16initializer_listIjE:
LFB5122:
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
LFE5122:
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
LFB5123:
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
LFE5123:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21initializeInnerStructEPFfvE:
LFB5124:
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
LFE5124:
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
LFB5128:
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
LFE5128:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB5129:
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
LFE5129:
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
LFB5125:
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
LFE5125:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE21setActivationFunctionERKNS_8function10ActivationIS3_fJEEE:
LFB5130:
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
LFE5130:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE24setNormalizationFunctionERKNS_8function10ActivationIS3_fJEEE:
LFB5131:
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
LFE5131:
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
LFB5135:
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
LFE5135:
	.text
	.def	___tcf_1;	.scl	3;	.type	32;	.endef
___tcf_1:
LFB5136:
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
LFE5136:
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
LFB5132:
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
LFE5132:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15setLossFunctionERKNS_8function4LossIS3_fJEEE:
LFB5137:
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
LFE5137:
	.section	.text$_ZNKSt16initializer_listIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE4sizeEv
	.def	__ZNKSt16initializer_listIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE4sizeEv:
LFB5139:
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
LFE5139:
	.section	.text$_ZNKSt16initializer_listIfE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE5beginEv
	.def	__ZNKSt16initializer_listIfE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE5beginEv:
LFB5140:
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
LFE5140:
	.section	.text$_ZNKSt16initializer_listIfE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIfE3endEv
	.def	__ZNKSt16initializer_listIfE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIfE3endEv:
LFB5141:
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
LFE5141:
	.section	.text$_ZN5lique6VectorIfEC1ERKSt16initializer_listIfE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE
	.def	__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1ERKSt16initializer_listIfE:
LFB5143:
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
LFE5143:
	.section	.text$_ZN5lique6VectorIfED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfED1Ev
	.def	__ZN5lique6VectorIfED1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfED1Ev:
LFB5146:
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
LFE5146:
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE4sizeEv:
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
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE5beginEv:
LFB5149:
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
LFE5149:
	.section	.text$_ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv
	.def	__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt16initializer_listIN5lique6VectorIfEEE3endEv:
LFB5150:
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
LFE5150:
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E
	.def	__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEC1ERKSt16initializer_listIS2_E:
LFB5152:
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
LFE5152:
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
LFB5153:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5153
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
LFE5153:
	.section	.gcc_except_table,"w"
LLSDA5153:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5153-LLSDACSB5153
LLSDACSB5153:
	.uleb128 LEHB5-LFB5153
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB6-LFB5153
	.uleb128 LEHE6-LEHB6
	.uleb128 L139-LFB5153
	.uleb128 0
	.uleb128 LEHB7-LFB5153
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE5153:
	.section	.text$_Z9testNeuroIN5trixy5NeuroIN5lique6MatrixENS2_6VectorENS2_6LinearE10CollectionfJEEEfEvRKT_RKS6_INS4_IT0_EEESF_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj:
LFB5154:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5154
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
LFE5154:
	.section	.gcc_except_table,"w"
LLSDA5154:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5154-LLSDACSB5154
LLSDACSB5154:
	.uleb128 LEHB8-LFB5154
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB5154
	.uleb128 LEHE9-LEHB9
	.uleb128 L152-LFB5154
	.uleb128 0
	.uleb128 LEHB10-LFB5154
	.uleb128 LEHE10-LEHB10
	.uleb128 L153-LFB5154
	.uleb128 0
	.uleb128 LEHB11-LFB5154
	.uleb128 LEHE11-LEHB11
	.uleb128 L152-LFB5154
	.uleb128 0
	.uleb128 LEHB12-LFB5154
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
LLSDACSE5154:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE15trainStochasticERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj:
LFB5155:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5155
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
LFE5155:
	.section	.gcc_except_table,"w"
LLSDA5155:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5155-LLSDACSB5155
LLSDACSB5155:
	.uleb128 LEHB13-LFB5155
	.uleb128 LEHE13-LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB14-LFB5155
	.uleb128 LEHE14-LEHB14
	.uleb128 L174-LFB5155
	.uleb128 0
	.uleb128 LEHB15-LFB5155
	.uleb128 LEHE15-LEHB15
	.uleb128 L175-LFB5155
	.uleb128 0
	.uleb128 LEHB16-LFB5155
	.uleb128 LEHE16-LEHB16
	.uleb128 L174-LFB5155
	.uleb128 0
	.uleb128 LEHB17-LFB5155
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
LLSDACSE5155:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE10trainBatchERKS5_INS3_IfEEESA_fj,"x"
	.linkonce discard
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj
	.def	__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj;	.scl	2;	.type	32;	.endef
__ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj:
LFB5156:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5156
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
LFE5156:
	.section	.gcc_except_table,"w"
LLSDA5156:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5156-LLSDACSB5156
LLSDACSB5156:
	.uleb128 LEHB18-LFB5156
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB19-LFB5156
	.uleb128 LEHE19-LEHB19
	.uleb128 L195-LFB5156
	.uleb128 0
	.uleb128 LEHB20-LFB5156
	.uleb128 LEHE20-LEHB20
	.uleb128 L196-LFB5156
	.uleb128 0
	.uleb128 LEHB21-LFB5156
	.uleb128 LEHE21-LEHB21
	.uleb128 L195-LFB5156
	.uleb128 0
	.uleb128 LEHB22-LFB5156
	.uleb128 LEHE22-LEHB22
	.uleb128 0
	.uleb128 0
LLSDACSE5156:
	.section	.text$_ZN5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14trainMiniBatchERKS5_INS3_IfEEESA_fjj,"x"
	.linkonce discard
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14normalAccuracyERKS5_INS3_IfEEESA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14normalAccuracyERKS5_INS3_IfEEESA_
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14normalAccuracyERKS5_INS3_IfEEESA_;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14normalAccuracyERKS5_INS3_IfEEESA_:
LFB5159:
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
LFE5159:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE14globalAccuracyERKS5_INS3_IfEEESA_f:
LFB5160:
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
LFE5160:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE12fullAccuracyERKS5_INS3_IfEEESA_f:
LFB5161:
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
LFE5161:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE4lossERKS5_INS3_IfEEESA_:
LFB5162:
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
LFE5162:
	.section	.text$_ZN10CollectionIN5lique6MatrixIfEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej
	.def	__ZN10CollectionIN5lique6MatrixIfEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6MatrixIfEEEC1Ej:
LFB5212:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5212
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
LEHB23:
	call	__Znaj
LEHE23:
	movl	%eax, %edi
	movl	%ebx, (%edi)
	leal	4(%edi), %esi
	leal	-1(%ebx), %eax
	movl	%eax, -32(%ebp)
	movl	%esi, -36(%ebp)
L232:
	cmpl	$0, -32(%ebp)
	js	L231
	movl	-36(%ebp), %ecx
LEHB24:
	call	__ZN5lique6MatrixIfEC1Ev
LEHE24:
	addl	$12, -36(%ebp)
	subl	$1, -32(%ebp)
	jmp	L232
L231:
	leal	4(%edi), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	jmp	L239
L238:
	movl	%eax, -36(%ebp)
	testl	%esi, %esi
	je	L234
	movl	-32(%ebp), %eax
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	subl	$12, %eax
	addl	%esi, %eax
	movl	%eax, -32(%ebp)
L235:
	cmpl	%esi, -32(%ebp)
	je	L234
	subl	$12, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	jmp	L235
L234:
	movl	-36(%ebp), %esi
	cmpl	$178956970, %ebx
	ja	L236
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$2, %eax
	addl	$4, %eax
	jmp	L237
L236:
	movl	$-1, %eax
L237:
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	__ZdaPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
LEHB25:
	call	__Unwind_Resume
LEHE25:
L239:
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
LFE5212:
	.section	.gcc_except_table,"w"
LLSDA5212:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5212-LLSDACSB5212
LLSDACSB5212:
	.uleb128 LEHB23-LFB5212
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB24-LFB5212
	.uleb128 LEHE24-LEHB24
	.uleb128 L238-LFB5212
	.uleb128 0
	.uleb128 LEHB25-LFB5212
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
LLSDACSE5212:
	.section	.text$_ZN10CollectionIN5lique6MatrixIfEEEC1Ej,"x"
	.linkonce discard
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEC1Ej
	.def	__ZN10CollectionIN5lique6VectorIfEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEC1Ej:
LFB5215:
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
	ja	L241
	leal	0(,%ebx,8), %eax
	addl	$4, %eax
	jmp	L242
L241:
	movl	$-1, %eax
L242:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %esi
	movl	%ebx, (%esi)
	leal	4(%esi), %eax
	leal	-1(%ebx), %edx
	movl	%edx, %ebx
	movl	%eax, %edi
L244:
	testl	%ebx, %ebx
	js	L243
	movl	%edi, %ecx
	call	__ZN5lique6VectorIfEC1Ev
	addl	$8, %edi
	subl	$1, %ebx
	jmp	L244
L243:
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
LFE5215:
	.section	.text$_ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej
	.def	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEC1Ej:
LFB5218:
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
	ja	L246
	leal	0(,%ebx,8), %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edi
	movl	%edi, %edx
	leal	-1(%ebx), %eax
	movl	%eax, %ebx
	movl	%edx, %esi
	jmp	L249
L246:
	call	___cxa_throw_bad_array_new_length
L249:
	testl	%ebx, %ebx
	js	L248
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	movl	%esi, %ecx
	call	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	subl	$8, %esp
	addl	$8, %esi
	subl	$1, %ebx
	jmp	L249
L248:
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
LFE5218:
	.section	.text$_ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E
	.def	__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E;	.scl	2;	.type	32;	.endef
__ZN5trixy8function4LossIN5lique6VectorEfJEEC1EPFfRKNS3_IfEES7_EPFS5_S7_S7_E:
LFB5221:
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
LFE5221:
	.section	.text$_ZN10CollectionIN5lique6MatrixIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6MatrixIfEEEixEj
	.def	__ZN10CollectionIN5lique6MatrixIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6MatrixIfEEEixEj:
LFB5222:
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
LFE5222:
	.section	.text$_ZN5lique6MatrixIfEC1Ejj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1Ejj
	.def	__ZN5lique6MatrixIfEC1Ejj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1Ejj:
LFB5225:
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
	ja	L254
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
	jmp	L259
L254:
	call	___cxa_throw_bad_array_new_length
L259:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L261
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L257
	sall	$2, %eax
	jmp	L260
L257:
	call	___cxa_throw_bad_array_new_length
L260:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L259
L261:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5225:
	.section	.text$_ZN5lique6MatrixIfED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfED1Ev
	.def	__ZN5lique6MatrixIfED1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfED1Ev:
LFB5228:
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
	je	L268
	movl	$0, -12(%ebp)
L266:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L264
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L265
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L265:
	addl	$1, -12(%ebp)
	jmp	L266
L264:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L268
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L268:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5228:
	.section	.text$_ZN5lique6MatrixIfEaSEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEaSEOS1_
	.def	__ZN5lique6MatrixIfEaSEOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEaSEOS1_:
LFB5229:
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
	jne	L270
	movl	-28(%ebp), %eax
	jmp	L271
L270:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L272
	movl	$0, -12(%ebp)
L275:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L273
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L274
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L274:
	addl	$1, -12(%ebp)
	jmp	L275
L273:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L272
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L272:
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
L271:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5229:
	.section	.text$_ZN10CollectionIN5lique6VectorIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5lique6VectorIfEEEixEj
	.def	__ZN10CollectionIN5lique6VectorIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5lique6VectorIfEEEixEj:
LFB5230:
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
LFE5230:
	.section	.text$_ZN5lique6VectorIfEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1Ej
	.def	__ZN5lique6VectorIfEC1Ej;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1Ej:
LFB5233:
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
	ja	L280
	sall	$2, %eax
	jmp	L282
L280:
	call	___cxa_throw_bad_array_new_length
L282:
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
LFE5233:
	.section	.text$_ZN5lique6VectorIfEaSEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEaSEOS1_
	.def	__ZN5lique6VectorIfEaSEOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEaSEOS1_:
LFB5234:
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
	jne	L284
	movl	-12(%ebp), %eax
	jmp	L285
L284:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L286
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L286:
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
L285:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5234:
	.section	.text$_ZN5lique6MatrixIfE4fillEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE4fillEPFfvE
	.def	__ZN5lique6MatrixIfE4fillEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE4fillEPFfvE:
LFB5235:
	.cfi_startproc
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
L291:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L288
	movl	$0, -16(%ebp)
L290:
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L289
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
	jmp	L290
L289:
	addl	$1, -12(%ebp)
	jmp	L291
L288:
	movl	-28(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5235:
	.section	.text$_ZN5lique6VectorIfE4fillEPFfvE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE4fillEPFfvE
	.def	__ZN5lique6VectorIfE4fillEPFfvE;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE4fillEPFfvE:
LFB5236:
	.cfi_startproc
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
L295:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L294
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
	jmp	L295
L294:
	movl	-28(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5236:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev:
LFB5239:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5239
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
LFE5239:
	.section	.gcc_except_table,"w"
LLSDA5239:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5239-LLSDACSB5239
LLSDACSB5239:
LLSDACSE5239:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev:
LFB5243:
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
LFE5243:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev:
LFB5245:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5245
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
LFE5245:
	.section	.gcc_except_table,"w"
LLSDA5245:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5245-LLSDACSB5245
LLSDACSB5245:
LLSDACSE5245:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNKSt4lessIPKcEclERKS1_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4lessIPKcEclERKS1_S4_
	.def	__ZNKSt4lessIPKcEclERKS1_S4_;	.scl	2;	.type	32;	.endef
__ZNKSt4lessIPKcEclERKS1_S4_:
LFB5247:
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
LFE5247:
	.section	.text$_ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPKcEONSt16remove_referenceIT_E4typeEOS4_:
LFB5248:
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
LFE5248:
	.section	.text$_ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIPKcEOT_RNSt16remove_referenceIS2_E4typeE:
LFB5250:
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
LFE5250:
	.section	.text$_ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_
	.def	__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EOPKcLb0EEC2IS1_EEOT_:
LFB5257:
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
LFE5257:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEEC2IS1_EEOT_:
LFB5259:
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
LFE5259:
	.section	.text$_ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_
	.def	__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIJOPKcEEC1IJS1_ELb1EEEDpOT_:
LFB5262:
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
LFE5262:
	.section	.text$_ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_,"x"
	.linkonce discard
	.globl	__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_
	.def	__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_;	.scl	2;	.type	32;	.endef
__ZNSt10_Head_baseILj0EOPKcLb0EE7_M_headERS3_:
LFB5275:
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
LFE5275:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_,"x"
	.linkonce discard
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEE7_M_headERS3_:
LFB5274:
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
LFE5274:
	.section	.text$_ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIOPKcEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5276:
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
LFE5276:
	.section	.text$_ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_
	.def	__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_;	.scl	2;	.type	32;	.endef
__ZNSt11_Tuple_implILj0EJOPKcEEC2EOS3_:
LFB5277:
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
LFE5277:
	.section	.text$_ZNSt5tupleIJOPKcEEC1EOS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5tupleIJOPKcEEC1EOS3_
	.def	__ZNSt5tupleIJOPKcEEC1EOS3_;	.scl	2;	.type	32;	.endef
__ZNSt5tupleIJOPKcEEC1EOS3_:
LFB5280:
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
LFE5280:
	.section	.text$_ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_,"x"
	.linkonce discard
	.globl	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_
	.def	__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_;	.scl	2;	.type	32;	.endef
__ZSt16forward_as_tupleIJPKcEESt5tupleIJDpOT_EES5_:
LFB5249:
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
LFE5249:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_:
LFB5246:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5246
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
	call	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
LEHE26:
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
	jne	L320
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
LEHB27:
	call	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
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
	je	L321
L320:
	movl	$1, %eax
	jmp	L322
L321:
	movl	$0, %eax
L322:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	testb	%al, %al
	je	L325
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
LEHB28:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	subl	$16, %esp
	movl	%eax, -28(%ebp)
L325:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	addl	$4, %eax
	jmp	L331
L330:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	nop
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE28:
L331:
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
LFE5246:
	.section	.gcc_except_table,"w"
LLSDA5246:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5246-LLSDACSB5246
LLSDACSB5246:
	.uleb128 LEHB26-LFB5246
	.uleb128 LEHE26-LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB27-LFB5246
	.uleb128 LEHE27-LEHB27
	.uleb128 L330-LFB5246
	.uleb128 0
	.uleb128 LEHB28-LFB5246
	.uleb128 LEHE28-LEHB28
	.uleb128 0
	.uleb128 0
LLSDACSE5246:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation7sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5281:
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
LFE5281:
	.section	.text$_ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation15sigmoid_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5282:
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
LFE5282:
	.section	.text$_ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation15tensor_of_unitsIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5283:
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
LFE5283:
	.section	.text$_ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4tanhIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5284:
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
LFE5284:
	.section	.text$_ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12tanh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5285:
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
LFE5285:
	.section	.text$_ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4reluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5286:
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
LFE5286:
	.section	.text$_ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12relu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5287:
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
LFE5287:
	.section	.text$_ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation3eluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5288:
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
LFE5288:
	.section	.text$_ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation11elu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5289:
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
LFE5289:
	.section	.text$_ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation5lreluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5290:
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
LFE5290:
	.section	.text$_ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation13lrelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5291:
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
LFE5291:
	.section	.text$_ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4seluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5292:
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
LFE5292:
	.section	.text$_ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12selu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5293:
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
LFE5293:
	.section	.text$_ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation4geluIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5294:
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
LFE5294:
	.section	.text$_ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation12gelu_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5295:
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
LFE5295:
	.section	.text$_ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation8softsignIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5296:
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
LFE5296:
	.section	.text$_ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16softsign_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5297:
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
LFE5297:
	.section	.text$_ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation8softplusIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5298:
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
LFE5298:
	.section	.text$_ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16softplus_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5299:
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
LFE5299:
	.section	.text$_ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation5swishIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5300:
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
LFE5300:
	.section	.text$_ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation13swish_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5301:
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
LFE5301:
	.section	.text$_ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_
	.def	__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation16unstable_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_:
LFB5302:
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
L376:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L375
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
	jmp	L376
L375:
	fldz
	fstps	-16(%ebp)
	movl	$0, -20(%ebp)
L378:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L377
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
	jmp	L378
L377:
	movl	$0, -24(%ebp)
L380:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L382
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fdivs	-16(%ebp)
	fstps	(%eax)
	addl	$1, -24(%ebp)
	jmp	L380
L382:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5302:
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
LFB5303:
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
L386:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L384
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
	je	L385
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfEclEj
	subl	$4, %esp
	flds	(%eax)
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E3max
L385:
	addl	$1, -12(%ebp)
	jmp	L386
L384:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN5lique6VectorIfEC1Ej
	subl	$4, %esp
	movl	$0, -16(%ebp)
L388:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L387
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
	jmp	L388
L387:
	fldz
	fstps	__ZZN5trixy3set10activation7softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_E11denominator
	movl	$0, -20(%ebp)
L390:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L389
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
	jmp	L390
L389:
	movl	$0, -24(%ebp)
L392:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L394
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
	jmp	L392
L394:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5303:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_:
LFB5304:
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
LFE5304:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv:
LFB5305:
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
LFE5305:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEneERKSC_:
LFB5306:
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
LFE5306:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEptEv:
LFB5307:
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
LFE5307:
	.section	.text$_ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_
	.def	__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_;	.scl	2;	.type	32;	.endef
__ZN5trixy8function10ActivationIN5lique6VectorEfJEEC1EPFNS3_IfEERKS5_ES9_:
LFB5310:
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
LFE5310:
	.section	.text$_ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	.def	__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj;	.scl	2;	.type	32;	.endef
__ZN10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj:
LFB5311:
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
LFE5311:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev:
LFB5314:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5314
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
LFE5314:
	.section	.gcc_except_table,"w"
LLSDA5314:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5314-LLSDACSB5314
LLSDACSB5314:
LLSDACSE5314:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EED1Ev:
LFB5318:
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
LFE5318:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev:
LFB5320:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5320
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
LFE5320:
	.section	.gcc_except_table,"w"
LLSDA5320:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5320-LLSDACSB5320
LLSDACSB5320:
LLSDACSE5320:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEEixEOS1_:
LFB5321:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5321
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
LEHB29:
	call	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
LEHE29:
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
	jne	L410
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
LEHB30:
	call	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
LEHE30:
	movl	$1, %ebx
	leal	-18(%ebp), %eax
	movl	%esi, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L411
L410:
	movl	$1, %eax
	jmp	L412
L411:
	movl	$0, %eax
L412:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	testb	%al, %al
	je	L415
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
LEHB31:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	subl	$16, %esp
	movl	%eax, -28(%ebp)
L415:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	addl	$4, %eax
	jmp	L421
L420:
	testb	%bl, %bl
	cmpb	$0, -45(%ebp)
	nop
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE31:
L421:
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
LFE5321:
	.section	.gcc_except_table,"w"
LLSDA5321:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5321-LLSDACSB5321
LLSDACSB5321:
	.uleb128 LEHB29-LFB5321
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB30-LFB5321
	.uleb128 LEHE30-LEHB30
	.uleb128 L420-LFB5321
	.uleb128 0
	.uleb128 LEHB31-LFB5321
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE5321:
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
LFB5323:
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
LFE5323:
	.section	.text$_ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5322:
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
L426:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L425
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
	jmp	L426
L425:
	flds	__ZZN5trixy3set4loss18mean_squared_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	flds	LC42
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5322:
	.section	.text$_ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss26mean_squared_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5324:
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
L430:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L432
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
	jmp	L430
L432:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5324:
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
LFB5325:
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
L435:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L434
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
	jmp	L435
L434:
	flds	__ZZN5trixy3set4loss19mean_absolute_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5325:
	.section	.text$_ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss27mean_absolute_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5326:
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
L442:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L446
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
	jbe	L445
	fld1
	fchs
	jmp	L441
L445:
	fld1
L441:
	fstps	(%ebx)
	addl	$1, -12(%ebp)
	jmp	L442
L446:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5326:
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
LFB5328:
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
LFE5328:
	.section	.text$_ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_
	.def	__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_:
LFB5327:
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
L451:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L450
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
	jmp	L451
L450:
	flds	__ZZN5trixy3set4loss30mean_squared_logarithmic_errorIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	flds	LC42
	fdivrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5327:
	.section	.text$_ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss38mean_squared_logarithmic_error_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5329:
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
L455:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L457
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
	jmp	L455
L457:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5329:
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
LFB5330:
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
L460:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L459
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
	jmp	L460
L459:
	flds	__ZZN5trixy3set4loss25categorical_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5330:
	.section	.text$_ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss33categorical_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5331:
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
L464:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L466
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
	jmp	L464
L466:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5331:
	.section	.text$_ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss41categorical_cross_entropy_derived_softmaxIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5332:
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
L469:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L471
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
	jmp	L469
L471:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5332:
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
LFB5333:
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
L474:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L473
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
	jmp	L474
L473:
	flds	__ZZN5trixy3set4loss20binary_cross_entropyIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5333:
	.section	.text$_ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss28binary_cross_entropy_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
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
L478:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L480
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
	jmp	L478
L480:
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
	.section	.text$_ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss36binary_cross_entropy_derived_sigmoidIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5335:
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
L483:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L485
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
	jmp	L483
L485:
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
LFB5336:
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
L488:
	movl	8(%ebp), %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L487
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
	jmp	L488
L487:
	flds	__ZZN5trixy3set4loss7logcoshIN5lique6VectorEfJEEET0_RKT_IS5_JDpT1_EESB_E6result
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5336:
	.section	.text$_ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_
	.def	__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set4loss15logcosh_derivedIN5lique6VectorEfJEEET_IT0_JDpT1_EERKS9_SB_:
LFB5337:
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
L492:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L494
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
	jmp	L492
L494:
	nop
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5337:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE4findERSC_:
LFB5338:
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
LFE5338:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE3endEv:
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
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5339:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEneERKSC_:
LFB5340:
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
LFE5340:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEptEv:
LFB5341:
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
LFE5341:
	.section	.text$_ZN5lique6VectorIfEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1Ev
	.def	__ZN5lique6VectorIfEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1Ev:
LFB5344:
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
LFE5344:
	.section	.text$_ZN5lique6VectorIfEaSERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEaSERKS1_
	.def	__ZN5lique6VectorIfEaSERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEaSERKS1_:
LFB5345:
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
	jne	L505
	movl	-28(%ebp), %eax
	jmp	L506
L505:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L507
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L507:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L508
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	$0, -12(%ebp)
	jmp	L511
L508:
	call	___cxa_throw_bad_array_new_length
L511:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L510
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
	jmp	L511
L510:
	movl	-28(%ebp), %eax
L506:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5345:
	.section	.text$_ZNK10CollectionIN5lique6VectorIfEEE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	.def	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv:
LFB5346:
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
LFE5346:
	.section	.text$_ZNK10CollectionIN5lique6VectorIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6VectorIfEEEixEj
	.def	__ZNK10CollectionIN5lique6VectorIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6VectorIfEEEixEj:
LFB5347:
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
LFE5347:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKNS3_IfEE:
LFB5348:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5348
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
LEHB32:
	call	__ZN5lique6VectorIfEC1ERKS1_
LEHE32:
	subl	$4, %esp
	movl	$0, -12(%ebp)
L518:
	movl	8(%ebp), %eax
	movl	32(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L526
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
LEHB33:
	call	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
LEHE33:
	subl	$16, %esp
	leal	-28(%ebp), %eax
	movl	%esi, 4(%esp)
	leal	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB34:
	call	__ZNK5lique6VectorIfEplERKS1_
LEHE34:
	subl	$8, %esp
	leal	-36(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB35:
	call	*%ebx
LEHE35:
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
	jmp	L518
L525:
	movl	%eax, %ebx
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L521
L524:
	movl	%eax, %ebx
L521:
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L522
L523:
	movl	%eax, %ebx
L522:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB36:
	call	__Unwind_Resume
LEHE36:
L526:
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
LFE5348:
	.section	.gcc_except_table,"w"
LLSDA5348:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5348-LLSDACSB5348
LLSDACSB5348:
	.uleb128 LEHB32-LFB5348
	.uleb128 LEHE32-LEHB32
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB33-LFB5348
	.uleb128 LEHE33-LEHB33
	.uleb128 L523-LFB5348
	.uleb128 0
	.uleb128 LEHB34-LFB5348
	.uleb128 LEHE34-LEHB34
	.uleb128 L524-LFB5348
	.uleb128 0
	.uleb128 LEHB35-LFB5348
	.uleb128 LEHE35-LEHB35
	.uleb128 L525-LFB5348
	.uleb128 0
	.uleb128 LEHB36-LFB5348
	.uleb128 LEHE36-LEHB36
	.uleb128 0
	.uleb128 0
LLSDACSE5348:
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
LFB5349:
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
L529:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L528
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
	jmp	L529
L528:
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
LFE5349:
	.section	.text$_ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b
	.def	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b;	.scl	2;	.type	32;	.endef
__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE3dotERKS4_RKS2_b:
LFB5350:
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
	je	L532
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
L536:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3rowEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L533
	movl	$0, -24(%ebp)
L535:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3colEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L534
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
	jmp	L535
L534:
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
	jmp	L536
L533:
	movl	-60(%ebp), %eax
	leal	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1EOS1_
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	jmp	L531
L532:
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
L541:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3colEv
	cmpl	-28(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L538
	movl	$0, -32(%ebp)
L540:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE4sizeEv
	movl	%eax, %ecx
	call	__ZNK5lique6MatrixIfE5Shape3rowEv
	cmpl	-32(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L539
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
	jmp	L540
L539:
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
	jmp	L541
L538:
	movl	-60(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfEC1EOS1_
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
L531:
	movl	-60(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5350:
	.section	.text$_ZNK5lique6VectorIfEplERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfEplERKS1_
	.def	__ZNK5lique6VectorIfEplERKS1_;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfEplERKS1_:
LFB5351:
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
L544:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L546
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
	jmp	L544
L546:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5351:
	.section	.text$_ZNK5lique6VectorIfE8multiplyERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE8multiplyERKS1_
	.def	__ZNK5lique6VectorIfE8multiplyERKS1_;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE8multiplyERKS1_:
LFB5352:
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
L549:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L551
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
	jmp	L549
L551:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5352:
	.section	.text$_ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b
	.def	__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b;	.scl	2;	.type	32;	.endef
__ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b:
LFB5353:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5353
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
	je	L553
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
LEHB37:
	call	__ZN5lique6MatrixIfEC1Ejj
LEHE37:
	subl	$8, %esp
	movl	$0, -12(%ebp)
L557:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L554
	movl	$0, -16(%ebp)
L556:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-16(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L555
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
	jmp	L556
L555:
	addl	$1, -12(%ebp)
	jmp	L557
L554:
	movl	-60(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB38:
	call	__ZN5lique6MatrixIfEC1EOS1_
LEHE38:
	subl	$4, %esp
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	jmp	L552
L553:
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
LEHB39:
	call	__ZN5lique6MatrixIfEC1Ejj
LEHE39:
	subl	$8, %esp
	movl	$0, -20(%ebp)
L562:
	movl	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-20(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L559
	movl	$0, -24(%ebp)
L561:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5lique6VectorIfE4sizeEv
	cmpl	-24(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L560
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
	jmp	L561
L560:
	addl	$1, -20(%ebp)
	jmp	L562
L559:
	movl	-60(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB40:
	call	__ZN5lique6MatrixIfEC1EOS1_
LEHE40:
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	jmp	L552
L565:
	movl	%eax, %ebx
	leal	-36(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
L566:
	movl	%eax, %ebx
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6MatrixIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE41:
L552:
	movl	-60(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE5353:
	.section	.gcc_except_table,"w"
LLSDA5353:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5353-LLSDACSB5353
LLSDACSB5353:
	.uleb128 LEHB37-LFB5353
	.uleb128 LEHE37-LEHB37
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB38-LFB5353
	.uleb128 LEHE38-LEHB38
	.uleb128 L565-LFB5353
	.uleb128 0
	.uleb128 LEHB39-LFB5353
	.uleb128 LEHE39-LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB40-LFB5353
	.uleb128 LEHE40-LEHB40
	.uleb128 L566-LFB5353
	.uleb128 0
	.uleb128 LEHB41-LFB5353
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
LLSDACSE5353:
	.section	.text$_ZNK5lique6LinearINS_6MatrixIfEENS_6VectorIfEEE9tensordotERKS4_S7_b,"x"
	.linkonce discard
	.section	.text$_ZNK5lique6MatrixIfE4joinEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE4joinEf
	.def	__ZNK5lique6MatrixIfE4joinEf;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE4joinEf:
LFB5354:
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
L571:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L573
	movl	$0, -16(%ebp)
L570:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L569
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
	jmp	L570
L569:
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
LFE5354:
	.section	.text$_ZN5lique6MatrixIfEmIERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEmIERKS1_
	.def	__ZN5lique6MatrixIfEmIERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEmIERKS1_:
LFB5355:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L578:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L575
	movl	$0, -8(%ebp)
L577:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L576
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
	jmp	L577
L576:
	addl	$1, -4(%ebp)
	jmp	L578
L575:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5355:
	.section	.text$_ZNK5lique6VectorIfE4joinEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE4joinEf
	.def	__ZNK5lique6VectorIfE4joinEf;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE4joinEf:
LFB5356:
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
L582:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L584
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
	jmp	L582
L584:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5356:
	.section	.text$_ZN5lique6VectorIfEmIERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEmIERKS1_
	.def	__ZN5lique6VectorIfEmIERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEmIERKS1_:
LFB5357:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L587:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L586
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
	jmp	L587
L586:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5357:
	.section	.text$_ZNK5lique6MatrixIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE4sizeEv
	.def	__ZNK5lique6MatrixIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE4sizeEv:
LFB5358:
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
LFE5358:
	.section	.text$_ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE
	.def	__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE6resizeERKNS1_5ShapeE:
LFB5359:
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
LFE5359:
	.section	.text$_ZNK5lique6VectorIfE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE4sizeEv
	.def	__ZNK5lique6VectorIfE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE4sizeEv:
LFB5360:
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
LFE5360:
	.section	.text$_ZN5lique6VectorIfE6resizeEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE6resizeEj
	.def	__ZN5lique6VectorIfE6resizeEj;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE6resizeEj:
LFB5361:
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
	je	L596
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L596:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L597
	sall	$2, %eax
	jmp	L600
L597:
	call	___cxa_throw_bad_array_new_length
L600:
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
LFE5361:
	.section	.text$_ZN5lique6MatrixIfE4fillEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE4fillEf
	.def	__ZN5lique6MatrixIfE4fillEf;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE4fillEf:
LFB5362:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L605:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L602
	movl	$0, -8(%ebp)
L604:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L603
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
	jmp	L604
L603:
	addl	$1, -4(%ebp)
	jmp	L605
L602:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5362:
	.section	.text$_ZN5lique6VectorIfE4fillEf,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfE4fillEf
	.def	__ZN5lique6VectorIfE4fillEf;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfE4fillEf:
LFB5363:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L609:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L608
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	flds	8(%ebp)
	fstps	(%eax)
	addl	$1, -4(%ebp)
	jmp	L609
L608:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5363:
	.section	.text$_ZN5lique6MatrixIfEpLERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEpLERKS1_
	.def	__ZN5lique6MatrixIfEpLERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEpLERKS1_:
LFB5364:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L615:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L612
	movl	$0, -8(%ebp)
L614:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	-8(%ebp), %eax
	jbe	L613
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
	jmp	L614
L613:
	addl	$1, -4(%ebp)
	jmp	L615
L612:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5364:
	.section	.text$_ZN5lique6VectorIfEpLERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEpLERKS1_
	.def	__ZN5lique6VectorIfEpLERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEpLERKS1_:
LFB5365:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	$0, -4(%ebp)
L619:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-4(%ebp), %eax
	jbe	L618
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
	jmp	L619
L618:
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5365:
	.section	.text$_ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE
	.def	__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE;	.scl	2;	.type	32;	.endef
__ZNK5trixy5NeuroIN5lique6MatrixENS1_6VectorENS1_6LinearE10CollectionfJEE11feedforwardERKS5_INS3_IfEEE:
LFB5366:
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
L623:
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK10CollectionIN5lique6VectorIfEEE4sizeEv
	cmpl	-12(%ebp), %eax
	seta	%al
	testb	%al, %al
	je	L625
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
	jmp	L623
L625:
	nop
	movl	-28(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5366:
	.section	.text$_ZNK5lique6VectorIfEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfEclEj
	.def	__ZNK5lique6VectorIfEclEj;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfEclEj:
LFB5370:
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
LFE5370:
	.section	.text$_ZN5lique6MatrixIfEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1Ev
	.def	__ZN5lique6MatrixIfEC1Ev;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1Ev:
LFB5414:
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
LFE5414:
	.section	.text$_ZN5lique6MatrixIfE5ShapeC1Ejj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE5ShapeC1Ejj
	.def	__ZN5lique6MatrixIfE5ShapeC1Ejj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE5ShapeC1Ejj:
LFB5417:
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
LFE5417:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev:
LFB5420:
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
LFE5420:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5422:
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
LFE5422:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E:
LFB5424:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L634:
	cmpl	$0, 8(%ebp)
	je	L635
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
	jmp	L634
L635:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5424:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv:
LFB5425:
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
LFE5425:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_:
LFB5426:
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
LFE5426:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEeqERKSC_:
LFB5427:
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
LFE5427:
	.section	.text$_ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
	.def	__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt3mapIPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv:
LFB5428:
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
LFE5428:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEdeEv:
LFB5429:
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
LFE5429:
	.section	.text$_ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	.def	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E;	.scl	2;	.type	32;	.endef
__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E:
LFB5432:
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
LFE5432:
	.section	.text$_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5434:
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
LFE5434:
	.section	.text$_ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE
	.def	__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt5tupleIJOPKcEEEOT_RNSt16remove_referenceIS5_E4typeE:
LFB5435:
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
LFE5435:
	.section	.text$_ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE:
LFB5436:
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
LFE5436:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_:
LFB5433:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5433
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
LEHB42:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
LEHE42:
	subl	$12, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB43:
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
	je	L654
	movl	-20(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
LEHE43:
	subl	$12, %esp
	jmp	L661
L654:
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
	jmp	L661
L659:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB44:
	call	___cxa_rethrow
LEHE44:
L660:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L661:
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
LFE5433:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5433:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5433-LLSDATTD5433
LLSDATTD5433:
	.byte	0x1
	.uleb128 LLSDACSE5433-LLSDACSB5433
LLSDACSB5433:
	.uleb128 LEHB42-LFB5433
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB43-LFB5433
	.uleb128 LEHE43-LEHB43
	.uleb128 L659-LFB5433
	.uleb128 0x1
	.uleb128 LEHB44-LFB5433
	.uleb128 LEHE44-LEHB44
	.uleb128 L660-LFB5433
	.uleb128 0
	.uleb128 LEHB45-LFB5433
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE5433:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5433:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZN5trixy3set10activation6detail7sigmoidIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_
	.def	__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail7sigmoidIfEET_S4_:
LFB5441:
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
LFE5441:
	.section	.text$_ZNK5lique6VectorIfE5applyEPFffE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6VectorIfE5applyEPFffE
	.def	__ZNK5lique6VectorIfE5applyEPFffE;	.scl	2;	.type	32;	.endef
__ZNK5lique6VectorIfE5applyEPFffE:
LFB5442:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5442
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
LEHB46:
	call	__ZN5lique6VectorIfEC1Ej
LEHE46:
	subl	$4, %esp
	movl	$0, -12(%ebp)
L666:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L670
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
LEHB47:
	call	*%eax
LEHE47:
	fstps	-32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L666
L669:
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5lique6VectorIfED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB48:
	call	__Unwind_Resume
LEHE48:
L670:
	nop
	movl	-28(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5442:
	.section	.gcc_except_table,"w"
LLSDA5442:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5442-LLSDACSB5442
LLSDACSB5442:
	.uleb128 LEHB46-LFB5442
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB47-LFB5442
	.uleb128 LEHE47-LEHB47
	.uleb128 L669-LFB5442
	.uleb128 0
	.uleb128 LEHB48-LFB5442
	.uleb128 LEHE48-LEHB48
	.uleb128 0
	.uleb128 0
LLSDACSE5442:
	.section	.text$_ZNK5lique6VectorIfE5applyEPFffE,"x"
	.linkonce discard
	.section	.text$_ZN5lique6VectorIfEC1EOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1EOS1_
	.def	__ZN5lique6VectorIfEC1EOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1EOS1_:
LFB5445:
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
LFE5445:
	.section	.text$_ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail15sigmoid_derivedIfEET_S4_:
LFB5446:
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
LFE5446:
	.section	.text$_ZN5trixy3set10activation6detail4tanhIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4tanhIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4tanhIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4tanhIfEET_S4_:
LFB5447:
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
LFE5447:
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
LFB5448:
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
LFE5448:
	.section	.text$_ZN5trixy3set10activation6detail4reluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4reluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4reluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4reluIfEET_S4_:
LFB5449:
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
	jbe	L684
	flds	8(%ebp)
	jmp	L682
L684:
	fldz
L682:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5449:
	.section	.text$_ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12relu_derivedIfEET_S4_:
LFB5450:
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
	jbe	L691
	fld1
	jmp	L689
L691:
	fldz
L689:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5450:
	.section	.text$_ZN5trixy3set10activation6detail3eluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail3eluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail3eluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail3eluIfEET_S4_:
LFB5451:
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
	jbe	L698
	flds	8(%ebp)
	jmp	L696
L698:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	fsubrp	%st, %st(1)
	fldl	LC47
	fmulp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
L696:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5451:
	.section	.text$_ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail11elu_derivedIfEET_S4_:
LFB5452:
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
	jbe	L705
	fld1
	jmp	L703
L705:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	flds	LC48
	fmulp	%st, %st(1)
L703:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5452:
	.section	.text$_ZN5trixy3set10activation6detail5lreluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail5lreluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail5lreluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail5lreluIfEET_S4_:
LFB5453:
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
	jbe	L712
	flds	8(%ebp)
	jmp	L710
L712:
	flds	8(%ebp)
	flds	LC49
	fmulp	%st, %st(1)
L710:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5453:
	.section	.text$_ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail13lrelu_derivedIfEET_S4_:
LFB5454:
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
	jbe	L719
	fld1
	jmp	L717
L719:
	flds	LC49
L717:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5454:
	.section	.text$_ZN5trixy3set10activation6detail4seluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4seluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4seluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4seluIfEET_S4_:
LFB5455:
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
	jbe	L726
	flds	8(%ebp)
	flds	LC50
	fmulp	%st, %st(1)
	jmp	L724
L726:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	fld1
	fsubrp	%st, %st(1)
	fldl	LC51
	fmulp	%st, %st(1)
	fstps	-12(%ebp)
	flds	-12(%ebp)
L724:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5455:
	.section	.text$_ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail12selu_derivedIfEET_S4_:
LFB5456:
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
	jbe	L733
	flds	LC50
	jmp	L731
L733:
	flds	8(%ebp)
	fstps	(%esp)
	call	__ZSt3expf
	flds	LC52
	fmulp	%st, %st(1)
L731:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5456:
	.section	.text$_ZN5trixy3set10activation6detail4geluIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail4geluIfEET_S4_
	.def	__ZN5trixy3set10activation6detail4geluIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail4geluIfEET_S4_:
LFB5457:
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
LFE5457:
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
LFB5458:
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
LFE5458:
	.section	.text$_ZN5trixy3set10activation6detail8softsignIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail8softsignIfEET_S4_
	.def	__ZN5trixy3set10activation6detail8softsignIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail8softsignIfEET_S4_:
LFB5459:
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
LFE5459:
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
LFB5460:
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
LFE5460:
	.section	.text$_ZN5trixy3set10activation6detail8softplusIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail8softplusIfEET_S4_
	.def	__ZN5trixy3set10activation6detail8softplusIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail8softplusIfEET_S4_:
LFB5461:
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
LFE5461:
	.section	.text$_ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_
	.def	__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail16softplus_derivedIfEET_S4_:
LFB5462:
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
LFE5462:
	.section	.text$_ZN5trixy3set10activation6detail5swishIfEET_S4_,"x"
	.linkonce discard
	.globl	__ZN5trixy3set10activation6detail5swishIfEET_S4_
	.def	__ZN5trixy3set10activation6detail5swishIfEET_S4_;	.scl	2;	.type	32;	.endef
__ZN5trixy3set10activation6detail5swishIfEET_S4_:
LFB5463:
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
LFE5463:
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
LFB5464:
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
LFE5464:
	.section	.text$_ZN5lique6VectorIfEclEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEclEj
	.def	__ZN5lique6VectorIfEclEj;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEclEj:
LFB5465:
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
LFE5465:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_:
LFB5466:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5466
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
LEHB49:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
LEHE49:
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
	jne	L753
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB50:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
LEHE50:
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L754
L753:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	jmp	L761
L754:
	movl	-16(%ebp), %eax
L761:
	testb	%bl, %bl
	jmp	L762
L760:
	testb	%bl, %bl
	nop
	movl	%eax, (%esp)
LEHB51:
	call	__Unwind_Resume
LEHE51:
L762:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5466:
	.section	.gcc_except_table,"w"
LLSDA5466:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5466-LLSDACSB5466
LLSDACSB5466:
	.uleb128 LEHB49-LFB5466
	.uleb128 LEHE49-LEHB49
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB50-LFB5466
	.uleb128 LEHE50-LEHB50
	.uleb128 L760-LFB5466
	.uleb128 0
	.uleb128 LEHB51-LFB5466
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
LLSDACSE5466:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv:
LFB5467:
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
LFE5467:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5468:
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
LFE5468:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EEC1Ev:
LFB5471:
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
LFE5471:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5473:
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
LFE5473:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_eraseEPSt13_Rb_tree_nodeISB_E:
LFB5475:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L771:
	cmpl	$0, 8(%ebp)
	je	L772
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
	jmp	L771
L772:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5475:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_M_beginEv:
LFB5476:
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
LFE5476:
	.section	.text$_ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_
	.def	__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_;	.scl	2;	.type	32;	.endef
__ZNSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE11lower_boundERSC_:
LFB5477:
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
LFE5477:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEeqERKSC_:
LFB5478:
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
LFE5478:
	.section	.text$_ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv
	.def	__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt3mapIPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEESt4lessIS1_ESaISt4pairIKS1_S8_EEE8key_compEv:
LFB5479:
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
LFE5479:
	.section	.text$_ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv
	.def	__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEdeEv:
LFB5480:
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
LFE5480:
	.section	.text$_ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E
	.def	__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E;	.scl	2;	.type	32;	.endef
__ZNSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1ERKSt17_Rb_tree_iteratorISB_E:
LFB5483:
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
LFE5483:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_:
LFB5484:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5484
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
LEHB52:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
LEHE52:
	subl	$12, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
LEHB53:
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
	je	L785
	movl	-20(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
LEHE53:
	subl	$12, %esp
	jmp	L792
L785:
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
	jmp	L792
L790:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB54:
	call	___cxa_rethrow
LEHE54:
L791:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB55:
	call	__Unwind_Resume
LEHE55:
L792:
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
LFE5484:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5484:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5484-LLSDATTD5484
LLSDATTD5484:
	.byte	0x1
	.uleb128 LLSDACSE5484-LLSDACSB5484
LLSDACSB5484:
	.uleb128 LEHB52-LFB5484
	.uleb128 LEHE52-LEHB52
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB53-LFB5484
	.uleb128 LEHE53-LEHB53
	.uleb128 L790-LFB5484
	.uleb128 0x1
	.uleb128 LEHB54-LFB5484
	.uleb128 LEHE54-LEHB54
	.uleb128 L791-LFB5484
	.uleb128 0
	.uleb128 LEHB55-LFB5484
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
LLSDACSE5484:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5484:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEESt17_Rb_tree_iteratorISB_ESt23_Rb_tree_const_iteratorISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_:
LFB5485:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5485
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
LEHB56:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
LEHE56:
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
	jne	L794
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
LEHB57:
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
LEHE57:
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt4lessIPKcEclERKS1_S4_
	subl	$8, %esp
	testb	%al, %al
	je	L795
L794:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	jmp	L802
L795:
	movl	-16(%ebp), %eax
L802:
	testb	%bl, %bl
	jmp	L803
L801:
	testb	%bl, %bl
	nop
	movl	%eax, (%esp)
LEHB58:
	call	__Unwind_Resume
LEHE58:
L803:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5485:
	.section	.gcc_except_table,"w"
LLSDA5485:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5485-LLSDACSB5485
LLSDACSB5485:
	.uleb128 LEHB56-LFB5485
	.uleb128 LEHE56-LEHB56
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB57-LFB5485
	.uleb128 LEHE57-LEHB57
	.uleb128 L801-LFB5485
	.uleb128 0
	.uleb128 LEHB58-LFB5485
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
LLSDACSE5485:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4findERS3_,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE3endEv:
LFB5486:
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
LFE5486:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5487:
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
LFE5487:
	.section	.text$_ZN5lique6VectorIfEC1ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6VectorIfEC1ERKS1_
	.def	__ZN5lique6VectorIfEC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6VectorIfEC1ERKS1_:
LFB5490:
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
	ja	L809
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
	jmp	L812
L809:
	call	___cxa_throw_bad_array_new_length
L812:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L813
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
	jmp	L812
L813:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5490:
	.section	.text$_ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj
	.def	__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5trixy8function10ActivationIN5lique6VectorEfJEEEEixEj:
LFB5491:
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
LFE5491:
	.section	.text$_ZNK10CollectionIN5lique6MatrixIfEEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK10CollectionIN5lique6MatrixIfEEEixEj
	.def	__ZNK10CollectionIN5lique6MatrixIfEEEixEj;	.scl	2;	.type	32;	.endef
__ZNK10CollectionIN5lique6MatrixIfEEEixEj:
LFB5492:
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
LFE5492:
	.section	.text$_ZNK5lique6MatrixIfE5Shape3rowEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE5Shape3rowEv
	.def	__ZNK5lique6MatrixIfE5Shape3rowEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE5Shape3rowEv:
LFB5494:
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
LFE5494:
	.section	.text$_ZNK5lique6MatrixIfE5Shape3colEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfE5Shape3colEv
	.def	__ZNK5lique6MatrixIfE5Shape3colEv;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfE5Shape3colEv:
LFB5495:
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
LFE5495:
	.section	.text$_ZNK5lique6MatrixIfEclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5lique6MatrixIfEclEjj
	.def	__ZNK5lique6MatrixIfEclEjj;	.scl	2;	.type	32;	.endef
__ZNK5lique6MatrixIfEclEjj:
LFB5496:
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
LFE5496:
	.section	.text$_ZN5lique6MatrixIfEclEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEclEjj
	.def	__ZN5lique6MatrixIfEclEjj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEclEjj:
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
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5497:
	.section	.text$_ZN5lique6MatrixIfEC1EOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1EOS1_
	.def	__ZN5lique6MatrixIfEC1EOS1_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1EOS1_:
LFB5500:
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
LFE5500:
	.section	.text$_ZN5lique6MatrixIfEC1ERKNS1_5ShapeE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE
	.def	__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfEC1ERKNS1_5ShapeE:
LFB5503:
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
	ja	L828
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
	jmp	L833
L828:
	call	___cxa_throw_bad_array_new_length
L833:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L835
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L831
	sall	$2, %eax
	jmp	L834
L831:
	call	___cxa_throw_bad_array_new_length
L834:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
	jmp	L833
L835:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5503:
	.section	.text$_ZN5lique6MatrixIfE6resizeEjj,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE6resizeEjj
	.def	__ZN5lique6MatrixIfE6resizeEjj;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE6resizeEjj:
LFB5504:
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
	je	L837
	movl	$0, -12(%ebp)
L840:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L838
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L839
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L839:
	addl	$1, -12(%ebp)
	jmp	L840
L838:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L837
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L837:
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L842
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	movl	$0, -16(%ebp)
	jmp	L847
L842:
	call	___cxa_throw_bad_array_new_length
L847:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-16(%ebp), %eax
	jbe	L844
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %edx
	sall	$2, %edx
	leal	(%eax,%edx), %ebx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	$536870911, %eax
	ja	L845
	sall	$2, %eax
	jmp	L849
L845:
	call	___cxa_throw_bad_array_new_length
L849:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, (%ebx)
	addl	$1, -16(%ebp)
	jmp	L847
L844:
	movl	-28(%ebp), %eax
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5504:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev:
LFB5539:
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
LFE5539:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5541:
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
LFE5541:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base:
LFB5543:
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
LFE5543:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base:
LFB5544:
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
LFE5544:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5545:
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
LFE5545:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_:
LFB5546:
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
LFE5546:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv:
LFB5547:
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
LFE5547:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5548:
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
LFE5548:
	.section	.text$_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.def	__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE:
LFB5559:
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
LFE5559:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEERKS1_OT_:
LFB5561:
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
LFE5561:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_Lb1EEEOT_OT0_:
LFB5568:
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
LFE5568:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_:
LFB5575:
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
LFE5575:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_:
LFB5549:
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
	je	L869
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	testl	%eax, %eax
	je	L870
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
	je	L870
	movl	$1, %eax
	jmp	L871
L870:
	movl	$0, %eax
L871:
	testb	%al, %al
	je	L872
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
	jmp	L884
L872:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L884
L869:
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
	je	L874
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
	je	L875
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
	jmp	L884
L875:
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
	je	L877
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L878
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
	jmp	L884
L878:
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
	jmp	L884
L877:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L884
L874:
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
	je	L879
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
	je	L880
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
	jmp	L884
L880:
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
	je	L882
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L883
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
	jmp	L884
L883:
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
	jmp	L884
L882:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L884
L879:
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
L884:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5549:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E:
LFB5576:
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
LFE5576:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E:
LFB5577:
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
	jne	L888
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	12(%ebp), %eax
	je	L888
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
	je	L889
L888:
	movl	$1, %eax
	jmp	L890
L889:
	movl	$0, %eax
L890:
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
LFE5577:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base:
LFB5580:
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
LFE5580:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv:
LFB5581:
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
LFE5581:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_:
LFB5582:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L899:
	cmpl	$0, 8(%ebp)
	je	L896
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
	je	L897
	movl	8(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L899
L897:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L899
L896:
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
LFE5582:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base:
LFB5583:
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
LFE5583:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5584:
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
LFE5584:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EEC1Ev:
LFB5587:
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
LFE5587:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEED2Ev:
LFB5589:
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
LFE5589:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base:
LFB5591:
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
LFE5591:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base:
LFB5592:
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
LFE5592:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_drop_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5593:
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
LFE5593:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11lower_boundERS3_:
LFB5594:
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
LFE5594:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8key_compEv:
LFB5595:
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
LFE5595:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5596:
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
LFE5596:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorISB_ERS3_:
LFB5597:
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
	je	L919
	movl	-108(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	testl	%eax, %eax
	je	L920
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
	je	L920
	movl	$1, %eax
	jmp	L921
L920:
	movl	$0, %eax
L921:
	testb	%al, %al
	je	L922
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
	jmp	L934
L922:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L934
L919:
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
	je	L924
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
	je	L925
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
	jmp	L934
L925:
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
	je	L927
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L928
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
	jmp	L934
L928:
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
	jmp	L934
L927:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L934
L924:
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
	je	L929
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
	je	L930
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
	jmp	L934
L930:
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
	je	L932
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	L933
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
	jmp	L934
L933:
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
	jmp	L934
L932:
	movl	-108(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	subl	$4, %esp
	jmp	L934
L929:
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
L934:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5597:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt13_Rb_tree_nodeISB_E:
LFB5598:
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
LFE5598:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSJ_PSt13_Rb_tree_nodeISB_E:
LFB5599:
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
	jne	L938
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	cmpl	12(%ebp), %eax
	je	L938
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
	je	L939
L938:
	movl	$1, %eax
	jmp	L940
L939:
	movl	$0, %eax
L940:
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
LFE5599:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base:
LFB5602:
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
LFE5602:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_M_endEv:
LFB5603:
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
LFE5603:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE14_M_lower_boundEPSt13_Rb_tree_nodeISB_EPSt18_Rb_tree_node_baseRS3_:
LFB5604:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
L949:
	cmpl	$0, 8(%ebp)
	je	L946
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
	je	L947
	movl	8(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L949
L947:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
	movl	%eax, 8(%ebp)
	jmp	L949
L946:
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
LFE5604:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE6_S_keyEPKSt18_Rb_tree_node_base:
LFB5605:
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
LFE5605:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5606:
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
LFE5606:
	.section	.text$_ZN5lique6MatrixIfE5ShapeC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5lique6MatrixIfE5ShapeC1ERKS2_
	.def	__ZN5lique6MatrixIfE5ShapeC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN5lique6MatrixIfE5ShapeC1ERKS2_:
LFB5609:
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
LFE5609:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5635:
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
LFE5635:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv:
LFB5637:
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
LFE5637:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5638:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5638
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
LFE5638:
	.section	.gcc_except_table,"w"
LLSDA5638:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5638-LLSDACSB5638
LLSDACSB5638:
LLSDACSE5638:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5639:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5639
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
LFE5639:
	.section	.gcc_except_table,"w"
LLSDA5639:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5639-LLSDACSB5639
LLSDACSB5639:
LLSDACSE5639:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv:
LFB5640:
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
LFE5640:
	.section	.text$_ZNSt18_Rb_tree_node_baseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt18_Rb_tree_node_baseC2Ev
	.def	__ZNSt18_Rb_tree_node_baseC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt18_Rb_tree_node_baseC2Ev:
LFB5644:
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
LFE5644:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5648:
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
LFE5648:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5650:
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
LFE5650:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5641:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5641
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
	je	L967
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1Ev
L967:
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
LEHB59:
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
LEHE59:
	jmp	L972
L970:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB60:
	call	___cxa_rethrow
LEHE60:
L971:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB61:
	call	__Unwind_Resume
LEHE61:
L972:
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
LFE5641:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5641:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5641-LLSDATTD5641
LLSDATTD5641:
	.byte	0x1
	.uleb128 LLSDACSE5641-LLSDACSB5641
LLSDACSB5641:
	.uleb128 LEHB59-LFB5641
	.uleb128 LEHE59-LEHB59
	.uleb128 L970-LFB5641
	.uleb128 0x1
	.uleb128 LEHB60-LFB5641
	.uleb128 LEHE60-LEHB60
	.uleb128 L971-LFB5641
	.uleb128 0
	.uleb128 LEHB61-LFB5641
	.uleb128 LEHE61-LEHB61
	.uleb128 0
	.uleb128 0
LLSDACSE5641:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5641:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	.def	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv;	.scl	2;	.type	32;	.endef
__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE13_M_const_castEv:
LFB5651:
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
LFE5651:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv:
LFB5652:
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
LFE5652:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv:
LFB5653:
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
LFE5653:
	.section	.text$_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	.def	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE:
LFB5660:
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
LFE5660:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_:
LFB5662:
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
LFE5662:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_:
LFB5654:
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
L986:
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	je	L983
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
	je	L984
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	jmp	L985
L984:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
L985:
	movl	%eax, -48(%ebp)
	jmp	L986
L983:
	movl	-52(%ebp), %edx
	leal	-56(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	cmpb	$0, -9(%ebp)
	je	L987
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
	je	L988
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
	jmp	L991
L988:
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv
L987:
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
	je	L990
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
	jmp	L991
L990:
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
L991:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5654:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv:
LFB5663:
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
LFE5663:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEmmEv:
LFB5664:
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
LFE5664:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEppEv:
LFB5665:
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
LFE5665:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E:
LFB5666:
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
LFE5666:
	.section	.text$_ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_
	.def	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_;	.scl	2;	.type	32;	.endef
__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEclERKSB_:
LFB5667:
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
LFE5667:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base:
LFB5668:
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
LFE5668:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv:
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
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5669:
	.section	.text$_ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5671:
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
LFE5671:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE13_Rb_tree_implISF_Lb1EE13_M_initializeEv:
LFB5673:
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
LFE5673:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5674:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5674
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
LFE5674:
	.section	.gcc_except_table,"w"
LLSDA5674:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5674-LLSDACSB5674
LLSDACSB5674:
LLSDACSE5674:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E:
LFB5675:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5675
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
LFE5675:
	.section	.gcc_except_table,"w"
LLSDA5675:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5675-LLSDACSB5675
LLSDACSB5675:
LLSDACSE5675:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_get_nodeEv:
LFB5676:
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
LFE5676:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5681:
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
LFE5681:
	.section	.text$_ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
	.def	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev:
LFB5683:
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
LFE5683:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_:
LFB5677:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5677
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
	je	L1016
	movl	%eax, %ecx
	call	__ZNSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1Ev
L1016:
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
LEHB62:
	call	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
LEHE62:
	jmp	L1021
L1019:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_put_nodeEPSt13_Rb_tree_nodeISB_E
	subl	$4, %esp
LEHB63:
	call	___cxa_rethrow
LEHE63:
L1020:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB64:
	call	__Unwind_Resume
LEHE64:
L1021:
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
LFE5677:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA5677:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT5677-LLSDATTD5677
LLSDATTD5677:
	.byte	0x1
	.uleb128 LLSDACSE5677-LLSDACSB5677
LLSDACSB5677:
	.uleb128 LEHB62-LFB5677
	.uleb128 LEHE62-LEHB62
	.uleb128 L1019-LFB5677
	.uleb128 0x1
	.uleb128 LEHB63-LFB5677
	.uleb128 LEHE63-LEHB63
	.uleb128 L1020-LFB5677
	.uleb128 0
	.uleb128 LEHB64-LFB5677
	.uleb128 LEHE64-LEHB64
	.uleb128 0
	.uleb128 0
LLSDACSE5677:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT5677:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE17_M_construct_nodeIJRKSt21piecewise_construct_tSt5tupleIJOS1_EESM_IJEEEEEvPSt13_Rb_tree_nodeISB_EDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv
	.def	__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv;	.scl	2;	.type	32;	.endef
__ZNKSt23_Rb_tree_const_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE13_M_const_castEv:
LFB5684:
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
LFE5684:
	.section	.text$_ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv
	.def	__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE4sizeEv:
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
	movl	20(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5685:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE12_M_rightmostEv:
LFB5686:
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
LFE5686:
	.section	.text$_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE
	.def	__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEOT_RNSt16remove_referenceISG_E4typeE:
LFB5693:
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
LFE5693:
	.section	.text$_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_
	.def	__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
__ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEERS1_Lb1EEEOT_OT0_:
LFB5695:
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
LFE5695:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE24_M_get_insert_unique_posERS3_:
LFB5687:
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
L1035:
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	je	L1032
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
	je	L1033
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE7_S_leftEPSt18_Rb_tree_node_base
	jmp	L1034
L1033:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_rightEPSt18_Rb_tree_node_base
L1034:
	movl	%eax, -48(%ebp)
	jmp	L1035
L1032:
	movl	-52(%ebp), %edx
	leal	-56(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEC1EPSt18_Rb_tree_node_base
	subl	$4, %esp
	cmpb	$0, -9(%ebp)
	je	L1036
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
	je	L1037
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
	jmp	L1040
L1037:
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv
L1036:
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
	je	L1039
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
	jmp	L1040
L1039:
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
L1040:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE5687:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE11_M_leftmostEv:
LFB5696:
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
LFE5696:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEmmEv:
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
LFE5697:
	.section	.text$_ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv
	.def	__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv;	.scl	2;	.type	32;	.endef
__ZNSt17_Rb_tree_iteratorISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEppEv:
LFB5698:
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
LFE5698:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt13_Rb_tree_nodeISB_E:
LFB5699:
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
LFE5699:
	.section	.text$_ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_
	.def	__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_;	.scl	2;	.type	32;	.endef
__ZNKSt10_Select1stISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEclERKSB_:
LFB5700:
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
LFE5700:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base,"x"
	.linkonce discard
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE8_S_valueEPKSt18_Rb_tree_node_base:
LFB5701:
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
LFE5701:
	.section	.text$_ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5702:
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
LFE5702:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5712:
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
LFE5712:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv:
LFB5714:
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
LFE5714:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_:
LFB5715:
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
LFE5715:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j:
LFB5716:
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
LFE5716:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j:
LFB5717:
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
LFE5717:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_:
LFB5718:
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
LFE5718:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv:
LFB5719:
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
LFE5719:
	.section	.text$_ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5720:
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
LFE5720:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEC2Ev:
LFB5722:
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
LFE5722:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE21_M_get_Node_allocatorEv:
LFB5724:
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
LFE5724:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE7destroyISC_EEvRSE_PT_:
LFB5725:
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
LFE5725:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE10deallocateERSE_PSD_j:
LFB5726:
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
LFE5726:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE8allocateERSE_j:
LFB5727:
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
LFE5727:
	.section	.text$_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEEE9constructISC_JRKSt21piecewise_construct_tSt5tupleIJOS3_EESK_IJEEEEEvRSE_PT_DpOT0_:
LFB5728:
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
LFE5728:
	.section	.text$_ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv
	.def	__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt8_Rb_treeIPKcSt4pairIKS1_N5trixy3set4data8LossDataIN5lique6VectorEfJEEEESt10_Select1stISB_ESt4lessIS1_ESaISB_EE5beginEv:
LFB5729:
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
LFE5729:
	.section	.text$_ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv
	.def	__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv;	.scl	2;	.type	32;	.endef
__ZNKSt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE9_M_valptrEv:
LFB5730:
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
LFE5730:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_:
LFB5733:
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
LFE5733:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j:
LFB5734:
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
LFE5734:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8allocateEjPKv:
LFB5735:
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
	je	L1082
	call	__ZSt17__throw_bad_allocv
L1082:
	movl	8(%ebp), %eax
	imull	$28, %eax, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5735:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_:
LFB5736:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5736
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
	je	L1089
	movzbl	-25(%ebp), %eax
	movb	%al, 8(%esp)
	movl	%edi, 4(%esp)
	movzbl	-33(%ebp), %eax
	movb	%al, (%esp)
	movl	%ebx, %ecx
LEHB65:
	call	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
LEHE65:
	subl	$12, %esp
	jmp	L1089
L1088:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB66:
	call	__Unwind_Resume
LEHE66:
L1089:
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
LFE5736:
	.section	.gcc_except_table,"w"
LLSDA5736:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5736-LLSDACSB5736
LLSDACSB5736:
	.uleb128 LEHB65-LFB5736
	.uleb128 LEHE65-LEHB65
	.uleb128 L1088-LFB5736
	.uleb128 0
	.uleb128 LEHB66-LFB5736
	.uleb128 LEHE66-LEHB66
	.uleb128 0
	.uleb128 0
LLSDACSE5736:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5737:
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
LFE5737:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE7destroyISD_EEvPT_:
LFB5738:
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
LFE5738:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE10deallocateEPSE_j:
LFB5739:
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
LFE5739:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8allocateEjPKv:
LFB5740:
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
	je	L1095
	call	__ZSt17__throw_bad_allocv
L1095:
	movl	8(%ebp), %eax
	imull	$28, %eax, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE5740:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_:
LFB5741:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA5741
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
	je	L1102
	movzbl	-25(%ebp), %eax
	movb	%al, 8(%esp)
	movl	%edi, 4(%esp)
	movzbl	-33(%ebp), %eax
	movb	%al, (%esp)
	movl	%ebx, %ecx
LEHB67:
	call	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
LEHE67:
	subl	$12, %esp
	jmp	L1102
L1101:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB68:
	call	__Unwind_Resume
LEHE68:
L1102:
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
LFE5741:
	.section	.gcc_except_table,"w"
LLSDA5741:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE5741-LLSDACSB5741
LLSDACSB5741:
	.uleb128 LEHB67-LFB5741
	.uleb128 LEHE67-LEHB67
	.uleb128 L1101-LFB5741
	.uleb128 0
	.uleb128 LEHB68-LFB5741
	.uleb128 LEHE68-LEHB68
	.uleb128 0
	.uleb128 0
LLSDACSE5741:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE9constructISD_JRKSt21piecewise_construct_tSt5tupleIJOS4_EESK_IJEEEEEvPT_DpOT0_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE6_M_ptrEv:
LFB5742:
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
LFE5742:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEEE8max_sizeEv:
LFB5743:
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
LFE5743:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
	.def	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE:
LFB5746:
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
LFE5746:
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5747:
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
LFE5747:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEEE8max_sizeEv:
LFB5748:
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
LFE5748:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE
	.def	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EESE_IJDpT0_EE:
LFB5751:
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
LFE5751:
	.section	.text$_ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv
	.def	__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx16__aligned_membufISt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEE7_M_addrEv:
LFB5752:
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
LFE5752:
	.section	.text$_ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE,"x"
	.linkonce discard
	.globl	__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	.def	__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE;	.scl	2;	.type	32;	.endef
__ZSt12__get_helperILj0EOPKcJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE:
LFB5755:
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
LFE5755:
	.section	.text$_ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_,"x"
	.linkonce discard
	.globl	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_
	.def	__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_;	.scl	2;	.type	32;	.endef
__ZSt3getILj0EJOPKcEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS7_:
LFB5754:
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
LFE5754:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	.def	__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data14ActivationDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE:
LFB5757:
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
LFE5757:
	.section	.text$_ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE
	.def	__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE;	.scl	2;	.type	32;	.endef
__ZNSt4pairIKPKcN5trixy3set4data8LossDataIN5lique6VectorEfJEEEEC1IJOS1_EJLj0EEJEJEEERSt5tupleIJDpT_EERSD_IJDpT1_EESt12_Index_tupleIJXspT0_EEESM_IJXspT2_EEE:
LFB5760:
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
LFE5760:
	.text
	.def	___tcf_2;	.scl	3;	.type	32;	.endef
___tcf_2:
LFB5770:
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
LFE5770:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB5769:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L1124
	cmpl	$65535, 12(%ebp)
	jne	L1124
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_2, (%esp)
	call	_atexit
L1124:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE5769:
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
LFB5771:
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
LFE5771:
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
	.def	__ZdaPvj;	.scl	2;	.type	32;	.endef
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
