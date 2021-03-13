/*
 * cpuid.c
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: File containing functions for fetching cpu info using assembly cpuid
 */ 

#include <cpuid.h>
#include "cpuid.h"
#include "interface/print.h"
#include "interface/extra_print.h"
#include "convert.h"

/// Order of vendor strings in assembly registries = ebx edx ecx

/* Vendor-strings. */
#define CPUID_VENDOR_OLDAMD       "AMDisbetter!"
#define CPUID_VENDOR_AMD          "AuthenticAMD"
#define CPUID_VENDOR_INTEL        "GenuineIntel"
#define CPUID_VENDOR_OLDTRANSMETA "TransmetaCPU"
#define CPUID_VENDOR_TRANSMETA    "GenuineTMx86"
#define CPUID_VENDOR_CYRIX        "CyrixInstead"
#define CPUID_VENDOR_CENTAUR      "CentaurHauls"
#define CPUID_VENDOR_NEXGEN       "NexGenDriven"
#define CPUID_VENDOR_UMC          "UMC UMC UMC "
#define CPUID_VENDOR_SIS          "SiS SiS SiS "
#define CPUID_VENDOR_NSC          "Geode by NSC"
#define CPUID_VENDOR_RISE         "RiseRiseRise"
#define CPUID_VENDOR_VORTEX       "Vortex86 SoC"
#define CPUID_VENDOR_VIA          "VIA VIA VIA "
#define CPUID_VENDOR_MCST_ELBRUS  "E2K MACHINE"
#define CPUID_VENDOR_HYGON        "HygonGenuine"
#define CPUID_VENDOR_ZHAOXIN      "  Shanghai  "
 
/*Vendor-strings from Virtual Machines.*/
#define CPUID_VENDOR_VIRTUAL_VMWARE         "VMwareVMware"
#define CPUID_VENDOR_VIRTUAL_QEMU           "TCGTCGTCGTCG"
#define CPUID_VENDOR_VIRTUAL_XENHVM         "XenVMMXenVMM"
#define CPUID_VENDOR_VIRTUAL_MICROSOFT_HV   "Microsoft Hv"
#define CPUID_VENDOR_VIRTUAL_APPLE          "VirtualApple"
#define CPUID_VENDOR_VIRTUAL_PARALLELS      " lrpepyh vr"
#define CPUID_VENDOR_VIRTUAL_PROJECT_ACRN   "ACRNACRNACRN"
#define CPUID_VENDOR_VIRTUAL_QNX_HYPERVISOR " QNXQVMBSQG "
#define CPUID_VENDOR_VIRTUAL_KVM            " KVMKVMKVM "
#define CPUID_VENDOR_VIRTUAL_BHYVE          "bhyve bhyve "

/// Fetches the vendor id using assembly cpuid
char* get_vendor_id() 
{
    int asm_eax, asm_ebx, asm_ecx, asm_edx;

    __cpuid(0, asm_eax, asm_ebx, asm_ecx, asm_edx);

    char int_as_hex[10]; 
    char int_as_string[10];

    int_to_string(int_as_string, asm_eax);
    newline();
    print(int_as_string);

    int_to_string(int_as_string, asm_ebx);
    newline();
    print(int_as_string);
    print_num(asm_ebx, 16, int_as_hex);
    newline();
    print(int_as_hex);

    int_to_string(int_as_string, asm_edx);
    newline();
    print(int_as_string);
    print_num(asm_edx, 16, int_as_hex);
    newline();
    print(int_as_hex);
 
    int_to_string(int_as_string, asm_ecx);
    newline();
    print(int_as_string);
    print_num(asm_ecx, 16, int_as_hex);
    newline();
    print(int_as_hex);

    return "";
}