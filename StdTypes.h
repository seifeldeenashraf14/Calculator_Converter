

#ifndef STDTYPES_H_
#define STDTYPES_H_


typedef enum
{
	EOK,
	ENOK,
	PARAMRETER_OUT_RANGE,
	PARAMERTE_NULL_PTR

}tenuErrrorStatus;

////////////////////****Data Types****////////////////////

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u16;
typedef signed int s16;

typedef unsigned long u32;
typedef signed long s32;

typedef unsigned long long u64;
typedef signed long long s64;

////////////////////****Pointer Types****////////////////////

typedef unsigned char* pu8;
typedef signed char* ps8;

typedef unsigned int* pu16;
typedef signed int* ps16;

typedef unsigned long* pu32;
typedef signed long* ps32;

typedef unsigned long long* pu64;
typedef signed long long* ps64;

#define Null_ptr ((void*)0)

////////////////////****Max size of Data Types****////////////////////

#define Max_U8_size ((u8)255)
#define Max_S8_size ((s8)127)
#define Min_S8_size ((s8)-128)

#define Max_U16_size ((u16)65535)
#define Max_S16_size ((s16)32767)
#define Min_S16_size ((s16)-32768)

#define Max_U32_size ((u32)4294967295)
#define Max_S32_size ((s32)2147483647)
#define Min_S32_size ((s32)-2147483648)


////////////////////****enums****////////////////////

typedef enum
{
	OK,
	NOTOK,
	NULL,
	OUT_OF_RANGE
}Error_types;
typedef enum
{
    False,
	True

}Boolean_types;


#define NULLPTR ((void*)0)

#endif /* STDTYPES_H_ */
