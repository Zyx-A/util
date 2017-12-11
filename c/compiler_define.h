//
// Created by hujianzhe
//

#ifndef UTIL_C_COMPILER_DEFINE_H
#define	UTIL_C_COMPILER_DEFINE_H

#define	COMPILE_CHECK(exp)	typedef char __compile_check__[(exp) ? 1 : -1]

#define	field_sizeof(type, field)				sizeof(((type*)0)->field)
#define	field_offset(type, field)				((char*)(&((type *)0)->field) - (char*)(0))
#define field_container(address, type, field)	((type *)((char*)(address) - (char*)(&((type *)0)->field)))

#if defined(_WIN32) || defined(_WIN64)
	#ifdef _MSC_VER
		#ifdef	_WIN64
			/* long long*/
			typedef	__int64		ssize_t;
		#else
			/* long */
			typedef	int			ssize_t;
		#endif
		#pragma warning(disable:4200)
		#pragma warning(disable:4018)
		#pragma warning(disable:4244)
		#pragma warning(disable:4267)
		#pragma warning(disable:4800)
		#pragma warning(disable:4819)
		#ifndef _CRT_SECURE_NO_WARNINGS
			#define	_CRT_SECURE_NO_WARNINGS
		#endif
		#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
			#define	_WINSOCK_DEPRECATED_NO_WARNINGS
		#endif
	#endif
#else
	#ifndef	_XOPEN_SOURCE
		#define	_XOPEN_SOURCE
	#endif
	#ifdef	__linux__
		#ifndef	_GNU_SOURCE
			#define _GNU_SOURCE
		#endif
	#endif
#endif

#endif