#include <Library/MemoryMapLib.h>

STATIC
EFI_MEMORY_REGION_DESCRIPTOR
gMemoryDescriptor[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  {"UEFI Stack",         0x40000000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI FD",            0x40080000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"DXE Heap",           0x40280000, 0x03C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},

  // Reserved Regions (SM-T220, 3 GB). Source: /proc/device-tree/reserved-memory
  // and /proc/iomem from the stock firmware. Adjacent regions are merged.
  {"Samsung Sec Log",         0x46C00000, 0x00A00000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"DTB Addr MRDump",         0x47880000, 0x00080000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"Ramoops And ATF",         0x47C80000, 0x00150000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"PL Bootarg",              0x47DD0000, 0x00200000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"LK Addr MRDump",          0x48000000, 0x00400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"SPM Reserved",            0x77FF0000, 0x00010000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"Display Reserved",        0x79DA0000, 0x00E60000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"TEE SecMem",              0x7AC00000, 0x00400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"TEE Reserved And GZ Log", 0x7BA00000, 0x04041000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"SSPM Log Store And GZ",   0x7FB00000, 0x00500000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"SCP Or WiFi Share 0",     0x8F000000, 0x00300000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"SSPM Share And SCP",      0x9F3F0000, 0x00B10000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"CCCI Tag Mem",            0x9FFF0000, 0x00010000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"Consys Reserved",         0xBE000000, 0x00440000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"SCP Or WiFi Share 1",     0xBF000000, 0x00300000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"ATF Log And Ramdump",     0xBFF30000, 0x000C0000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"DRAMC RK0",               0xBFFFF000, 0x00001000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"ION Carveout",            0xCFFFB000, 0x00005000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"DRAMC RK1",               0xFFFFF000, 0x00001000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK},

  // Register Regions
  {"GIC Distributor",    0x0C000000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"GIC Redistributors", 0x0C100000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Top Ck Gen",         0x10000000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Infra Cfg AO",       0x10001000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Pinctrl",            0x10005000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"WatchDog Timer",     0x10007000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"AP Mixed",           0x1000C000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PMIC Wrapper",       0x1000D000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"EMI",                0x10219000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MSDC-0",             0x11230000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MSDC-1",             0x11240000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MSDC Top-0",         0x11C90000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"MSDC Top-1",         0x11CD0000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Display OVL",        0x1400B000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE}
};

VOID
GetMemoryMap (
  OUT EFI_MEMORY_REGION_DESCRIPTOR **MemoryDescriptor,
  OUT UINT8                         *MemoryDescriptorCount)
{
  // Pass Data
  *MemoryDescriptor      = gMemoryDescriptor;
  *MemoryDescriptorCount = ARRAY_SIZE (gMemoryDescriptor);
}
